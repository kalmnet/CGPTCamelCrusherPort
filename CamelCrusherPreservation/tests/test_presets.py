import sys,pathlib,unittest,struct,plistlib
sys.path.insert(0,str(pathlib.Path(__file__).resolve().parents[1]/'tools'))
import presets
class Presets(unittest.TestCase):
 def setUp(self):self.raw=(pathlib.Path(__file__).parent/'fixtures/factory-bank.fxb').read_bytes();self.programs=presets.parse(self.raw)
 def test_original_bank(self):
  self.assertEqual(len(self.programs),20);self.assertEqual(self.programs[0]['name'],'Annihilate');self.assertEqual(struct.unpack_from('>I',self.raw,4)[0],len(self.raw))
 def test_roundtrip(self):self.assertEqual(presets.encode(self.programs),self.raw[160:])
 def test_new_preset(self):
  data=presets.vstpreset(self.programs,13);self.assertEqual(data[:4],b'VST3');list_offset=struct.unpack_from('<Q',data,40)[0];self.assertEqual(data[list_offset:list_offset+4],b'List');self.assertEqual(struct.unpack_from('<I',data,52)[0],13)
 def test_au_chunk_and_array(self):
  p=self.programs[13];blob=plistlib.dumps(dict(subtype=0x43614372,name=p['name'],data=presets.encode([p])));self.assertEqual(presets.parse(blob)[0]['parameters'],p['parameters']);blob=plistlib.dumps(dict(subtype=0x43614372,name=p['name'],data=struct.pack('>17f',*p['parameters'])));self.assertEqual(presets.parse(blob)[0]['parameters'],p['parameters'])
 def test_invalid_size(self):
  with self.assertRaises(ValueError):presets.parse(self.raw[:-1])
if __name__=='__main__':unittest.main()
