/* Analysis evidence only. Decompiler errors require verification against instructions. */
// ADDRESS 00001d10 NAME CamelCrusher::CamelCrusher

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Removing unreachable block (ram,0x00001d30) */
/* CamelCrusher::CamelCrusher(char const*, char const*) */

void __thiscall CamelCrusher::CamelCrusher(CamelCrusher *this,char *param_1,char *param_2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ADDRESS 00002660 NAME CamelCrusher::CamelCrusher

/* CamelCrusher::CamelCrusher(char const*, char const*) */

void __thiscall CamelCrusher::CamelCrusher(CamelCrusher *this,char *param_1,char *param_2)

{
  CamelCrusher(this,param_1,param_2);
  return;
}


// ADDRESS 00002a10 NAME PParam::PParam

/* PParam::PParam(PParamType, bool, char*, char*, char*, float, float) */

void __thiscall
PParam::PParam(PParam *this,PParamType param_1,bool param_2,char *param_3,char *param_4,
              char *param_5,float param_6,float param_7)

{
  _strcpy((char *)(this + 0x18),param_3);
  if (param_5 == (char *)0x0) {
    this[0x118] = (PParam)0x0;
  }
  else {
    _strcpy((char *)(this + 0x118),param_5);
  }
  if (param_4 == (char *)0x0) {
    this[0x98] = (PParam)0x0;
  }
  else {
    _strcpy((char *)(this + 0x98),param_4);
  }
  *(float *)(this + 0x198) = param_6;
  *(float *)(this + 0x19c) = param_7;
  *this = SUB41(param_1,0);
  *(float *)(this + 0x1a0) = param_6;
  *(float *)(this + 0x1a4) = param_6;
  *(undefined8 *)(this + 0x1a8) = 0;
  *(undefined4 *)(this + 0x1b4) = 0x3c23d70a;
  this[1] = (PParam)0x0;
  *(undefined8 *)(this + 8) = 0;
  *(undefined8 *)(this + 0x10) = 0;
  *(undefined4 *)(this + 0x1bc) = 0;
  *(undefined4 *)(this + 0x1b8) = 0;
  *(undefined4 *)(this + 0x1b0) = 0;
  *(undefined4 *)(this + 0x1c0) = 0;
  this[0x1c4] = (PParam)param_2;
  this[0x1c5] = (PParam)0x0;
  *(undefined4 *)(this + 0x1c8) = 0;
  *(undefined4 *)(this + 0x22cc) = 0;
  *(undefined4 *)(this + 0x22d0) = 0;
  this[0x22d4] = (PParam)0x0;
  this[0x22d5] = (PParam)0x0;
  return;
}


// ADDRESS 0000d980 NAME CamelCrusher::resume

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* CamelCrusher::resume() */

void CamelCrusher::resume(void)

{
  long *in_RDI;
  
  if (0 < *(int *)(in_RDI + 2)) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  (**(code **)(*in_RDI + 0x48))();
  *(undefined4 *)(in_RDI + 0x30008c3) = 0xec2;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ADDRESS 0000da00 NAME CamelCrusher::process

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x0000da2c) overlaps instruction at (ram,0x0000da2b)
    */
/* CamelCrusher::process(float*, float*, float*, float*, int, bool) */

void CamelCrusher::process
               (float *param_1,float *param_2,float *param_3,float *param_4,int param_5,bool param_6
               )

{
  byte in_AF;
  byte in_TF;
  byte in_IF;
  byte in_NT;
  byte in_AC;
  byte in_VIF;
  byte in_VIP;
  byte in_ID;
  long local_b8 [17];
  
  *(ulong *)(local_b8[0] + -8) =
       (ulong)(in_NT & 1) * 0x4000 | (ulong)SBORROW8((long)&stack0xffffffffffffffd0,0x88) * 0x800 |
       (ulong)(in_IF & 1) * 0x200 | (ulong)(in_TF & 1) * 0x100 | (ulong)((long)local_b8 < 0) * 0x80
       | (ulong)((section *)&stack0x00000000 == &section_000000b8) * 0x40 |
       (ulong)(in_AF & 1) * 0x10 | (ulong)((POPCOUNT((ulong)local_b8 & 0xff) & 1U) == 0) * 4 |
       (ulong)(&stack0xffffffffffffffd0 < &section_00000068.addr) | (ulong)(in_ID & 1) * 0x200000 |
       (ulong)(in_VIP & 1) * 0x100000 | (ulong)(in_VIF & 1) * 0x80000 | (ulong)(in_AC & 1) * 0x40000
  ;
  if ((section *)&stack0x00000000 != &section_000000b8) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ADDRESS 0000e1d0 NAME CamelCrusher::setParamCustom

/* CamelCrusher::setParamCustom(int, float) */

void __thiscall CamelCrusher::setParamCustom(CamelCrusher *this,int param_1,float param_2)

{
  if (param_1 == 8) {
    *(uint *)(this + 0x45dc) = ~-(uint)(DAT_0006fbd4 <= param_2) & DAT_0006fc08;
    return;
  }
  if (param_1 != 9) {
    return;
  }
  this[0x2ca1] = (CamelCrusher)(param_2 < DAT_0006fbd4);
  return;
}


// ADDRESS 0000e3a0 NAME CamelCrusher::processAllEvents

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* CamelCrusher::processAllEvents() */

void CamelCrusher::processAllEvents(void)

{
  int *piVar1;
  CAPlugin CVar2;
  CAPlugin CVar3;
  CAPlugin CVar4;
  long lVar5;
  uint uVar6;
  int iVar7;
  CAPlugin *in_RDI;
  
  iVar7 = *(int *)(in_RDI + 0x1c24);
  if ((iVar7 < *(int *)(in_RDI + 0x1c20)) &&
     (lVar5 = (long)iVar7, *(int *)(in_RDI + lVar5 * 4 + 0x20) < 0x40000001)) {
    CVar2 = in_RDI[(long)(&UNK_00001020 + lVar5)];
    CVar3 = in_RDI[lVar5 + 0x1420];
    CVar4 = in_RDI[lVar5 + 0x1820];
    *(int *)(in_RDI + 0x1c24) = iVar7 + 1;
    if ((CVar2 == (CAPlugin)0xb0) && (0 < *(int *)(in_RDI + 0x14))) {
      lVar5 = *(long *)(in_RDI + 0x18);
      piVar1 = (int *)(&DAT_00008800 + lVar5);
      iVar7 = 0;
      do {
        uVar6 = 0;
        if (iVar7 <= *piVar1) {
          uVar6 = *(uint *)(lVar5 + 0x8000);
        }
        if (uVar6 == (byte)CVar3) {
          CAPlugin::setParam(in_RDI,iVar7,(float)(uint)(byte)CVar4 / _DAT_0006fbe8);
          break;
        }
        iVar7 = iVar7 + 1;
        lVar5 = lVar5 + 4;
      } while (iVar7 != *(int *)(in_RDI + 0x14));
    }
  }
  *(undefined4 *)(in_RDI + 0x1c20) = 0;
  *(undefined4 *)(in_RDI + 0x1c24) = 0;
  return;
}


// ADDRESS 0000f1c0 NAME CamelCrusherProgram::clearCustom

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* CamelCrusherProgram::clearCustom() */

void CamelCrusherProgram::clearCustom(void)

{
  long in_RDI;
  
  *(undefined4 *)(*(long *)(in_RDI + 8) + 0x10) = 0x3f000000;
  *(undefined4 *)(*(long *)(in_RDI + 8) + 0x24) = 0x3f800000;
  *(undefined4 *)(*(long *)(in_RDI + 8) + 0x2c) = 0x3f800000;
  *(undefined4 *)(*(long *)(in_RDI + 8) + 0x28) = 0x3f800000;
  return;
}


// ADDRESS 0000f8b0 NAME PParam::PParam

/* PParam::PParam(PParamType, bool, char*, char*, char*, float, float) */

void __thiscall
PParam::PParam(PParam *this,PParamType param_1,bool param_2,char *param_3,char *param_4,
              char *param_5,float param_6,float param_7)

{
  _strcpy((char *)(this + 0x18),param_3);
  if (param_5 == (char *)0x0) {
    this[0x118] = (PParam)0x0;
  }
  else {
    _strcpy((char *)(this + 0x118),param_5);
  }
  if (param_4 == (char *)0x0) {
    this[0x98] = (PParam)0x0;
  }
  else {
    _strcpy((char *)(this + 0x98),param_4);
  }
  *(float *)(this + 0x198) = param_6;
  *(float *)(this + 0x19c) = param_7;
  *this = SUB41(param_1,0);
  *(float *)(this + 0x1a0) = param_6;
  *(float *)(this + 0x1a4) = param_6;
  *(undefined8 *)(this + 0x1a8) = 0;
  *(undefined4 *)(this + 0x1b4) = 0x3c23d70a;
  this[1] = (PParam)0x0;
  *(undefined8 *)(this + 8) = 0;
  *(undefined8 *)(this + 0x10) = 0;
  *(undefined4 *)(this + 0x1bc) = 0;
  *(undefined4 *)(this + 0x1b8) = 0;
  *(undefined4 *)(this + 0x1b0) = 0;
  *(undefined4 *)(this + 0x1c0) = 0;
  this[0x1c4] = (PParam)param_2;
  this[0x1c5] = (PParam)0x0;
  *(undefined4 *)(this + 0x1c8) = 0;
  *(undefined4 *)(this + 0x22cc) = 0;
  *(undefined4 *)(this + 0x22d0) = 0;
  this[0x22d4] = (PParam)0x0;
  this[0x22d5] = (PParam)0x0;
  return;
}


// ADDRESS 00010760 NAME PParam::advanceTimeGetParam

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* PParam::advanceTimeGetParam(int) */

ulong __thiscall PParam::advanceTimeGetParam(PParam *this,int param_1)

{
  int iVar1;
  float fVar2;
  ulong uVar3;
  float fVar4;
  
  fVar4 = *(float *)(this + 0x1a0);
  if (fVar4 != *(float *)(this + 0x1a4)) {
    iVar1 = *(int *)(this + 0x1c0);
    *(int *)(this + 0x1c0) = param_1 + iVar1;
    fVar4 = (float)(param_1 + iVar1) / (float)*(int *)(this + 0x1b8);
    if (fVar4 <= DAT_0006fb38) {
      fVar2 = DAT_0006fb38 - fVar4;
    }
    else {
      fVar2 = 0.0;
      fVar4 = DAT_0006fb38;
    }
    fVar4 = fVar2 * *(float *)(this + 0x1b0) + fVar4 * *(float *)(this + 0x1a4);
    *(float *)(this + 0x1a0) = fVar4;
  }
  uVar3 = (ulong)(uint)fVar4;
  if (*(long *)(this + 8) != 0) {
    uVar3 = getSmoothedParam();
  }
  if (*(long *)(this + 0x10) != 0) {
    fVar4 = (float)CALfo::getValue();
    fVar4 = (float)uVar3 + fVar4;
    if ((_DAT_0006fb30 <= fVar4) || (NAN(fVar4) || NAN(_DAT_0006fb30))) {
      fVar2 = DAT_0006fb38;
      if (fVar4 <= DAT_0006fb38) {
        fVar2 = fVar4;
      }
      uVar3 = (ulong)(uint)fVar2;
    }
    else {
      uVar3 = 0;
    }
  }
  return uVar3;
}


// ADDRESS 00032210 NAME CAProgram::load

/* CAProgram::load(FileIO*, int) */

undefined8 __thiscall CAProgram::load(CAProgram *this,FileIO *param_1,int param_2)

{
  long lVar1;
  int iVar2;
  long lVar3;
  int iVar4;
  float fVar5;
  undefined4 uVar6;
  
  if (0 < *(int *)(this + 0x50)) {
    iVar2 = 0;
    lVar3 = 0;
    do {
      *(undefined4 *)(*(long *)(this + 8) + lVar3) = 0;
      iVar2 = iVar2 + 1;
      lVar3 = lVar3 + 4;
    } while (iVar2 < *(int *)(this + 0x50));
  }
  fVar5 = (float)FileIO::readFloat();
  if (fVar5 < 0.0) {
    return 0;
  }
  FileIO::readString(param_1,(char *)(this + 0x10));
  if (*(int *)(this + 0x58) == param_2) {
    iVar2 = FileIO::readInt();
    if (*(int *)(this + 0x50) < iVar2) {
      return 0;
    }
    if (0 < iVar2) {
      iVar4 = 0;
      lVar3 = 0;
      do {
        lVar1 = *(long *)(this + 8);
        uVar6 = FileIO::readFloat();
        *(undefined4 *)(lVar3 + lVar1) = uVar6;
        iVar4 = iVar4 + 1;
        lVar3 = lVar3 + 4;
      } while (iVar4 != iVar2);
    }
    lVar3 = *(long *)this;
    param_2 = *(int *)(this + 0x58);
  }
  else {
    lVar3 = *(long *)this;
  }
  (**(code **)(lVar3 + 0x20))(fVar5,this,param_1,param_2);
  return 1;
}


// ADDRESS 00032350 NAME CAProgram::save

/* CAProgram::save(FileIO*) */

undefined8 __thiscall CAProgram::save(CAProgram *this,FileIO *param_1)

{
  long lVar1;
  int iVar2;
  
  FileIO::writeFloat(param_1,*(float *)(this + 0x54));
  FileIO::writeString(param_1,(char *)(this + 0x10));
  FileIO::writeInt(param_1,*(int *)(this + 0x50));
  if (0 < *(int *)(this + 0x50)) {
    iVar2 = 0;
    lVar1 = 0;
    do {
      FileIO::writeFloat(param_1,*(float *)(*(long *)(this + 8) + lVar1));
      iVar2 = iVar2 + 1;
      lVar1 = lVar1 + 4;
    } while (iVar2 < *(int *)(this + 0x50));
  }
  (**(code **)(*(long *)this + 0x28))(*(undefined4 *)(this + 0x54),this,param_1);
  return 1;
}


// ADDRESS 00032480 NAME CAProgram::loadCustom

/* CAProgram::loadCustom(FileIO*, float, int) */

void CAProgram::loadCustom(FileIO *param_1,float param_2,int param_3)

{
  return;
}


// ADDRESS 00032490 NAME CAProgram::saveCustom

/* CAProgram::saveCustom(FileIO*, float) */

void CAProgram::saveCustom(FileIO *param_1,float param_2)

{
  return;
}


// ADDRESS 00033280 NAME EnvelopeFollower::process

/* EnvelopeFollower::process(float) */

float __thiscall EnvelopeFollower::process(EnvelopeFollower *this,float param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  
  fVar2 = *(float *)(this + 0xc) - *(float *)(this + 0x14);
  if (param_1 <= fVar2) {
    if ((float)((uint)fVar2 ^ DAT_0006fc30) <= param_1) {
      fVar3 = 0.0;
      goto LAB_000332b3;
    }
    param_1 = (float)((uint)param_1 ^ DAT_0006fc30);
  }
  fVar3 = param_1 - fVar2;
LAB_000332b3:
  fVar1 = *(float *)(this + 0x10);
  if (fVar3 <= *(float *)(this + 0x10)) {
    fVar1 = fVar3;
  }
  fVar3 = 0.0;
  if (0.0 <= fVar1 + fVar2) {
    fVar3 = fVar1 + fVar2;
  }
  *(float *)(this + 0xc) = fVar3;
  return fVar3;
}


// ADDRESS 000423a0 NAME CACompressor::process

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* CACompressor::process(float*, float*, int, float, float) */

void __thiscall
CACompressor::process
          (CACompressor *this,float *param_1,float *param_2,int param_3,float param_4,float param_5)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  long lVar5;
  int iVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  
  fVar4 = DAT_0006fb38;
  fVar1 = *(float *)this;
  fVar12 = DAT_0006fb38 / (DAT_0006fb38 - fVar1);
  fVar2 = *(float *)(this + 8);
  fVar3 = *(float *)(this + 0xc);
  *(float *)(this + 8) = param_5;
  if (0 < param_3) {
    iVar6 = 0;
    lVar5 = 0;
    fVar7 = fVar12 - _DAT_00070828;
    do {
      fVar11 = param_1[lVar5];
      fVar10 = param_2[lVar5];
      fVar9 = (float)((uint)fVar11 & DAT_00070610);
      fVar8 = (float)((uint)fVar10 & DAT_00070610);
      if (fVar9 <= fVar8) {
        fVar9 = fVar8;
      }
      if ((*(float *)(this + 4) != 0.0) || (NAN(*(float *)(this + 4)))) {
        fVar9 = (float)EnvelopeFollower::process((EnvelopeFollower *)(this + 0x18),fVar9);
      }
      else {
        fVar9 = (float)((uint)fVar9 & DAT_00070610);
      }
      fVar11 = fVar11 * fVar12;
      fVar10 = fVar10 * fVar12;
      fVar9 = fVar9 * fVar12;
      if (fVar9 <= _DAT_00070828) {
        fVar8 = *(float *)(this + 0x10);
      }
      else {
        fVar8 = (fVar4 - (fVar9 - _DAT_00070828) / fVar7) * DAT_0007082c;
        fVar9 = ((DAT_0006fbd4 - fVar8 * fVar8) * _DAT_00070830 + _DAT_00070828) / fVar9;
        fVar8 = *(float *)(this + 0x10);
        if (fVar9 < fVar8) {
          *(float *)(this + 0x10) = fVar9;
          *(float *)(this + 0x14) = (fVar4 - fVar9) / (fVar2 * fVar3);
          fVar8 = fVar9;
        }
      }
      if (fVar8 < fVar4) {
        fVar11 = fVar11 * fVar8;
        fVar10 = fVar10 * fVar8;
        *(float *)(this + 0x10) = fVar8 + *(float *)(this + 0x14);
      }
      param_1[lVar5] = fVar11;
      param_2[lVar5] = fVar10;
      *(float *)this = (param_4 - fVar1) / (float)param_3 + *(float *)this;
      iVar6 = iVar6 + 1;
      lVar5 = lVar5 + 1;
    } while (iVar6 != param_3);
  }
  *(float *)this = param_4;
  return;
}


// ADDRESS 00043b30 NAME Distortion::processMech

/* Distortion::processMech(float*, int) */

void __thiscall Distortion::processMech(Distortion *this,float *param_1,int param_2)

{
  uint uVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  
  fVar3 = DAT_00070854;
  fVar2 = DAT_00070768;
  uVar1 = DAT_0006fc30;
  fVar6 = DAT_000700b4 * *(float *)(this + 4) + DAT_0006fb38;
  fVar7 = DAT_0006fbe0 / (fVar6 - DAT_00070768);
  if (0 < param_2) {
    iVar4 = 0;
    do {
      while (fVar5 = *param_1 * fVar6, fVar5 <= DAT_00070768) {
        if (fVar3 <= fVar5) goto LAB_00043b8c;
        *param_1 = (float)((uint)((fVar3 - fVar5) * fVar7 + fVar2) ^ uVar1);
        iVar4 = iVar4 + 1;
        param_1 = param_1 + 1;
        if (iVar4 == param_2) {
          return;
        }
      }
      fVar5 = (fVar5 - fVar2) * fVar7 + fVar2;
LAB_00043b8c:
      *param_1 = fVar5;
      iVar4 = iVar4 + 1;
      param_1 = param_1 + 1;
    } while (iVar4 != param_2);
  }
  return;
}


// ADDRESS 00043be0 NAME Distortion::processTube

/* Distortion::processTube(float*, int) */

void __thiscall Distortion::processTube(Distortion *this,float *param_1,int param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  uint uVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  int iVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  
  fVar7 = DAT_0007085c;
  fVar6 = DAT_00070858;
  fVar5 = DAT_0007082c;
  uVar4 = DAT_0006fc30;
  fVar3 = DAT_0006fc0c;
  fVar2 = DAT_0006fbd4;
  fVar1 = DAT_0006fb38;
  fVar10 = DAT_00070554 * *(float *)(this + 8) + DAT_0006fb38;
  if (0 < param_2) {
    iVar8 = 0;
    fVar11 = fVar10 - DAT_0006fc0c;
    do {
      while (fVar9 = *param_1 * fVar10, fVar9 <= DAT_0006fc0c) {
        if (fVar7 <= fVar9) goto LAB_00043c94;
        fVar9 = (fVar1 - (fVar7 - fVar9) / fVar11) * fVar5;
        *param_1 = (float)((uint)((fVar2 - fVar9 * fVar9) * fVar6 + fVar3) ^ uVar4);
        iVar8 = iVar8 + 1;
        param_1 = param_1 + 1;
        if (iVar8 == param_2) {
          return;
        }
      }
      fVar9 = (fVar1 - (fVar9 - fVar3) / fVar11) * fVar5;
      fVar9 = (fVar2 - fVar9 * fVar9) * fVar6 + fVar3;
LAB_00043c94:
      *param_1 = fVar9;
      iVar8 = iVar8 + 1;
      param_1 = param_1 + 1;
    } while (iVar8 != param_2);
  }
  return;
}


// ADDRESS 00043de0 NAME Distortion::processMech

/* Distortion::processMech(float*, float*, int, float) */

void __thiscall
Distortion::processMech(Distortion *this,float *param_1,float *param_2,int param_3,float param_4)

{
  uint uVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  
  *(float *)(this + 4) = param_4;
  fVar3 = DAT_00070854;
  fVar2 = DAT_00070768;
  fVar6 = DAT_000700b4;
  uVar1 = DAT_0006fc30;
  fVar10 = DAT_0006fbe0;
  fVar8 = DAT_0006fb38;
  fVar7 = param_4 * DAT_000700b4 + DAT_0006fb38;
  fVar9 = DAT_0006fbe0 / (fVar7 - DAT_00070768);
  if (0 < param_3) {
    iVar4 = 0;
    do {
      while (fVar5 = *param_1 * fVar7, DAT_00070768 < fVar5) {
        fVar5 = (fVar5 - fVar2) * fVar9 + fVar2;
LAB_00043e4c:
        *param_1 = fVar5;
        iVar4 = iVar4 + 1;
        param_1 = param_1 + 1;
        if (iVar4 == param_3) goto LAB_00043e96;
      }
      if (fVar3 <= fVar5) goto LAB_00043e4c;
      *param_1 = (float)((uint)((fVar3 - fVar5) * fVar9 + fVar2) ^ uVar1);
      iVar4 = iVar4 + 1;
      param_1 = param_1 + 1;
    } while (iVar4 != param_3);
LAB_00043e96:
    fVar3 = DAT_00070854;
    uVar1 = DAT_0006fc30;
    fVar8 = fVar6 * *(float *)(this + 4) + fVar8;
    fVar10 = fVar10 / (fVar8 - fVar2);
    iVar4 = 0;
    do {
      while (fVar6 = *param_2 * fVar8, fVar6 <= DAT_00070768) {
        if (fVar3 <= fVar6) goto LAB_00043edc;
        *param_2 = (float)((uint)((fVar3 - fVar6) * fVar10 + fVar2) ^ uVar1);
        iVar4 = iVar4 + 1;
        param_2 = param_2 + 1;
        if (iVar4 == param_3) {
          return;
        }
      }
      fVar6 = (fVar6 - fVar2) * fVar10 + fVar2;
LAB_00043edc:
      *param_2 = fVar6;
      iVar4 = iVar4 + 1;
      param_2 = param_2 + 1;
    } while (iVar4 != param_3);
  }
  return;
}


// ADDRESS 00043f30 NAME Distortion::processTube

/* Distortion::processTube(float*, float*, int, float) */

void __thiscall
Distortion::processTube(Distortion *this,float *param_1,float *param_2,int param_3,float param_4)

{
  float fVar1;
  float fVar2;
  float fVar3;
  uint uVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  int iVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  
  *(float *)(this + 8) = param_4;
  fVar7 = DAT_0007085c;
  fVar6 = DAT_00070858;
  fVar5 = DAT_0007082c;
  uVar4 = DAT_0006fc30;
  fVar3 = DAT_0006fc0c;
  fVar2 = DAT_0006fbd4;
  fVar1 = DAT_0006fb38;
  fVar10 = DAT_00070554 * param_4 + DAT_0006fb38;
  if (0 < param_3) {
    iVar8 = 0;
    fVar11 = fVar10 - DAT_0006fc0c;
    do {
      while (fVar9 = *param_1 * fVar10, DAT_0006fc0c < fVar9) {
        fVar9 = (fVar1 - (fVar9 - fVar3) / fVar11) * fVar5;
        fVar9 = (fVar2 - fVar9 * fVar9) * fVar6 + fVar3;
LAB_00043fe4:
        *param_1 = fVar9;
        iVar8 = iVar8 + 1;
        param_1 = param_1 + 1;
        if (iVar8 == param_3) goto LAB_00044057;
      }
      if (fVar7 <= fVar9) goto LAB_00043fe4;
      fVar9 = (fVar1 - (fVar7 - fVar9) / fVar11) * fVar5;
      *param_1 = (float)((uint)((fVar2 - fVar9 * fVar9) * fVar6 + fVar3) ^ uVar4);
      iVar8 = iVar8 + 1;
      param_1 = param_1 + 1;
    } while (iVar8 != param_3);
LAB_00044057:
    fVar7 = DAT_0007085c;
    fVar6 = DAT_00070858;
    fVar5 = DAT_0007082c;
    uVar4 = DAT_0006fc30;
    fVar3 = DAT_0006fc0c;
    fVar2 = DAT_0006fbd4;
    fVar10 = DAT_00070554 * *(float *)(this + 8) + fVar1;
    iVar8 = 0;
    fVar11 = fVar10 - DAT_0006fc0c;
    do {
      while (fVar9 = *param_2 * fVar10, fVar9 <= DAT_0006fc0c) {
        if (fVar7 <= fVar9) goto LAB_000440f3;
        fVar9 = (fVar1 - (fVar7 - fVar9) / fVar11) * fVar5;
        *param_2 = (float)((uint)((fVar2 - fVar9 * fVar9) * fVar6 + fVar3) ^ uVar4);
        iVar8 = iVar8 + 1;
        param_2 = param_2 + 1;
        if (iVar8 == param_3) {
          return;
        }
      }
      fVar9 = (fVar1 - (fVar9 - fVar3) / fVar11) * fVar5;
      fVar9 = (fVar2 - fVar9 * fVar9) * fVar6 + fVar3;
LAB_000440f3:
      *param_2 = fVar9;
      iVar8 = iVar8 + 1;
      param_2 = param_2 + 1;
    } while (iVar8 != param_3);
  }
  return;
}


// ADDRESS 00061d00 NAME MMFilter::process

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* MMFilter::process(int, float, float, float, float, float, float, float*, float*, int) */

void __thiscall
MMFilter::process(MMFilter *this,int param_1,float param_2,float param_3,float param_4,float param_5
                 ,float param_6,float param_7,float *param_8,float *param_9,int param_10)

{
  float fVar1;
  bool bVar2;
  float fVar3;
  uint uVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  long lVar8;
  float *pfVar9;
  int iVar10;
  int iVar11;
  MMFilter *pMVar12;
  float *pfVar13;
  MMFilter *pMVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  double dVar18;
  ulong uVar19;
  undefined4 uVar20;
  float fVar21;
  float fVar22;
  float local_29c;
  float local_258;
  int local_24c;
  int local_248;
  int local_244;
  float local_238 [64];
  float local_138 [66];
  
  iVar10 = *(int *)this;
  fVar1 = *(float *)(this + 0x1510);
  if (param_6 != *(float *)(this + 0x1514)) {
    *(float *)(this + 0x1514) = param_6;
    *(float *)(this + 0x10d4) = param_6;
    if ((param_6 != 0.0) || (NAN(param_6))) {
      *(float *)(this + 0x10e0) = DAT_0006fb38 / (param_6 * *(float *)(this + 0x10d0));
    }
    else {
      *(undefined4 *)(this + 0x10e0) = 0;
    }
  }
  if (param_7 != *(float *)(this + 0x1518)) {
    *(float *)(this + 0x1518) = param_7;
    *(float *)(this + 0x10d8) = param_7;
    if ((param_7 != 0.0) || (NAN(param_7))) {
      *(float *)(this + 0x10e4) = DAT_0006fb38 / (param_7 * *(float *)(this + 0x10d0));
    }
    else {
      *(undefined4 *)(this + 0x10e4) = 0;
    }
  }
  _memcpy(local_138,param_8,(long)param_10 * 4);
  _memcpy(local_238,param_9,(long)param_10 * 4);
  local_29c = *(float *)(this + 0x1500);
  if (((local_29c != param_2) || (NAN(local_29c) || NAN(param_2))) || (iVar10 != param_1)) {
    fVar22 = *(float *)(this + 0x150c);
    fVar21 = fVar22 * *(float *)(this + 0x10dc) * local_29c + (DAT_0006fb38 - fVar22) * local_29c;
    if (fVar21 < DAT_0006fb38) {
      if (fVar21 <= 0.0) {
        uVar19 = (ulong)(uint)DAT_000717f8;
      }
      else {
        dVar18 = (double)_log10((double)(DAT_0006fb38 - fVar21));
        dVar18 = dVar18 * _DAT_00070570;
        if (dVar18 <= DAT_0006fb50) {
          if ((DAT_00070578 <= dVar18) || (NAN(dVar18) || NAN(DAT_00070578))) {
            dVar18 = dVar18 * _DAT_00070580 + _DAT_00070588;
            uVar20 = (undefined4)((ulong)dVar18 >> 0x20);
            fVar21 = (float)dVar18;
          }
          else {
            uVar20 = 0;
            fVar21 = DAT_00070848;
          }
        }
        else {
          uVar20 = 0;
          fVar21 = DAT_00070844;
        }
        uVar19 = CONCAT44(uVar20,fVar21 * DAT_000717e8);
      }
    }
    else {
      uVar19 = (ulong)(uint)DAT_000717f4;
    }
    fVar21 = (float)_logf(uVar19);
    fVar15 = (float)_logf(DAT_0006fbf8);
    fVar15 = (DAT_00070a98 / fVar15) * fVar21 + _DAT_0006fbfc;
    fVar21 = 0.0;
    if (0.0 <= fVar15) {
      fVar21 = fVar15;
    }
    fVar15 = *(float *)(this + 0x10fc);
    if (fVar21 <= *(float *)(this + 0x10fc)) {
      fVar15 = fVar21;
    }
    if (iVar10 != param_1) {
      setFilterType(this,param_1,fVar15,*(float *)(this + 0x1504),DAT_0006fb38);
      local_29c = *(float *)(this + 0x1500);
      fVar22 = *(float *)(this + 0x150c);
      iVar10 = *(int *)(this + 0x10e8);
    }
    else {
      iVar10 = *(int *)(this + 0x10e8);
    }
    if (iVar10 == 1) {
      local_258 = (param_2 - local_29c) / (float)param_10;
      bVar2 = true;
    }
    else {
      local_258 = (param_2 - local_29c) / (float)(param_10 * 2);
      bVar2 = true;
    }
  }
  else {
    fVar22 = *(float *)(this + 0x150c);
    bVar2 = false;
    local_258 = 0.0;
  }
  if (((fVar22 != 0.0) || (NAN(fVar22))) ||
     ((param_3 != *(float *)(this + 0x1504) ||
      ((NAN(param_3) || NAN(*(float *)(this + 0x1504)) || (fVar22 != param_4)))))) {
    *(float *)(this + 0x1504) = param_3;
    *(float *)(this + 0x150c) = param_4;
    fVar22 = param_4 * *(float *)(this + 0x10dc) * local_29c + (DAT_0006fb38 - param_4) * local_29c;
    if (fVar22 < DAT_0006fb38) {
      if (fVar22 <= 0.0) {
        uVar19 = (ulong)(uint)DAT_000717f8;
      }
      else {
        dVar18 = (double)_log10((double)(DAT_0006fb38 - fVar22));
        dVar18 = dVar18 * _DAT_00070570;
        if (dVar18 <= DAT_0006fb50) {
          if ((DAT_00070578 <= dVar18) || (NAN(dVar18) || NAN(DAT_00070578))) {
            dVar18 = dVar18 * _DAT_00070580 + _DAT_00070588;
            uVar20 = (undefined4)((ulong)dVar18 >> 0x20);
            fVar22 = (float)dVar18;
          }
          else {
            uVar20 = 0;
            fVar22 = DAT_00070848;
          }
        }
        else {
          uVar20 = 0;
          fVar22 = DAT_00070844;
        }
        uVar19 = CONCAT44(uVar20,fVar22 * DAT_000717e8);
      }
    }
    else {
      uVar19 = (ulong)(uint)DAT_000717f4;
    }
    fVar22 = (float)_logf(uVar19);
    fVar21 = (float)_logf(DAT_0006fbf8);
    fVar21 = (DAT_00070a98 / fVar21) * fVar22 + _DAT_0006fbfc;
    fVar22 = 0.0;
    if (0.0 <= fVar21) {
      fVar22 = fVar21;
    }
    (**(code **)(**(long **)(this + 8) + 0x18))(*(undefined4 *)(this + 0x1504));
    (**(code **)(**(long **)(this + 0x10) + 0x18))(*(undefined4 *)(this + 0x1504));
    (**(code **)(**(long **)(this + 8) + 0x10))(fVar22);
    (**(code **)(**(long **)(this + 0x10) + 0x10))(fVar22);
    if (*(int *)(this + 0x10e8) == 1) goto LAB_000624d4;
LAB_0006206f:
    if (0 < param_10) {
      iVar11 = 0;
      lVar8 = 0;
      iVar10 = 0x80;
      do {
        fVar22 = param_8[lVar8];
        fVar21 = param_9[lVar8];
        *(float *)(this + (long)(&DAT_00001100 + lVar8 * 8)) = fVar22;
        *(float *)(this + (long)(&DAT_00001104 + lVar8 * 8)) = fVar22;
        *(float *)(this + (long)(&DAT_00001100 + (long)iVar10 * 4)) = fVar21;
        *(float *)(this + (long)(&DAT_00001304 + lVar8 * 8)) = fVar21;
        iVar11 = iVar11 + 1;
        lVar8 = lVar8 + 1;
        iVar10 = iVar10 + 2;
      } while (iVar11 != param_10);
    }
    iVar10 = param_10 * 2;
    if (0 < iVar10) {
      local_244 = 0;
      do {
        iVar11 = iVar10 - local_244;
        if (iVar11 < 0x10) {
          pMVar14 = this + (long)(&DAT_00001100 + (long)local_244 * 4);
          pMVar12 = this + (long)(&DAT_00001300 + (long)local_244 * 4);
          if (0 < iVar11) goto LAB_00062141;
        }
        else {
          pMVar14 = this + (long)(&DAT_00001100 + (long)local_244 * 4);
          pMVar12 = this + (long)(&DAT_00001300 + (long)local_244 * 4);
          iVar11 = 0x10;
LAB_00062141:
          lVar8 = 0;
          do {
            EnvelopeFollower::process
                      ((EnvelopeFollower *)(this + 0x10d0),
                       (*(float *)(pMVar14 + lVar8 * 4) + *(float *)(pMVar12 + lVar8 * 4)) *
                       DAT_0006fbd4 * DAT_0006fbd4);
            lVar8 = lVar8 + 1;
          } while ((int)lVar8 < iVar11);
        }
        (**(code **)(**(long **)(this + 8) + 0x40))
                  (*(long **)(this + 8),pMVar14,pMVar12,iVar11,*(undefined8 *)(this + 0x10));
        if (bVar2) {
          fVar22 = (float)iVar11 * local_258 + *(float *)(this + 0x1500);
          *(float *)(this + 0x1500) = fVar22;
          fVar21 = *(float *)(this + 0x150c) * *(float *)(this + 0x10dc) * fVar22 +
                   fVar22 * (DAT_0006fb38 - *(float *)(this + 0x150c));
          fVar22 = DAT_000717f4;
          if ((fVar21 < DAT_0006fb38) && (fVar22 = DAT_000717f8, 0.0 < fVar21)) {
            dVar18 = (double)_log10((double)(DAT_0006fb38 - fVar21));
            dVar18 = dVar18 * _DAT_00070570;
            fVar22 = DAT_00070844;
            if ((dVar18 <= DAT_0006fb50) && (fVar22 = DAT_00070848, DAT_00070578 <= dVar18)) {
              fVar22 = (float)(dVar18 * _DAT_00070580 + _DAT_00070588);
            }
            fVar22 = DAT_000717e8 * fVar22;
          }
          fVar22 = (float)_logf(fVar22);
          fVar21 = (float)_logf(DAT_0006fbf8);
          fVar21 = fVar22 * (DAT_00070a98 / fVar21) + _DAT_0006fbfc;
          fVar22 = 0.0;
          if (0.0 <= fVar21) {
            fVar22 = fVar21;
          }
          (**(code **)(**(long **)(this + 8) + 0x10))(fVar22);
          (**(code **)(**(long **)(this + 0x10) + 0x10))(fVar22);
        }
        local_244 = local_244 + iVar11;
      } while (local_244 < iVar10);
    }
    *(float *)(this + 0x1500) = param_2;
    *(float *)(this + 0x1504) = param_3;
    fVar22 = DAT_0006fbd4;
    if (0 < param_10) {
      iVar11 = 0;
      lVar8 = 0;
      iVar10 = 0x80;
      do {
        param_8[lVar8] =
             (*(float *)(this + (long)(&DAT_00001100 + lVar8 * 8)) +
             *(float *)(this + (long)(&DAT_00001104 + lVar8 * 8))) * fVar22;
        param_9[lVar8] =
             (*(float *)(this + (long)(&DAT_00001100 + (long)iVar10 * 4)) +
             *(float *)(this + (long)(&DAT_00001304 + lVar8 * 8))) * fVar22;
        iVar11 = iVar11 + 1;
        lVar8 = lVar8 + 1;
        iVar10 = iVar10 + 2;
      } while (iVar11 != param_10);
    }
    iVar10 = *(int *)(this + 0x10ec);
    if (iVar10 == 1) goto LAB_000626ea;
LAB_0006233a:
    fVar7 = DAT_000717fc;
    fVar6 = DAT_00070888;
    fVar5 = DAT_0007082c;
    uVar4 = DAT_0006fc30;
    fVar3 = DAT_0006fc0c;
    fVar15 = DAT_0006fbd4;
    fVar21 = DAT_0006fbcc;
    fVar22 = DAT_0006fb38;
    if (iVar10 == 2) {
      if (param_10 < 1) goto LAB_000623eb;
      iVar10 = 0;
      lVar8 = 0;
      do {
        fVar16 = *(float *)(this + 0x1504) * fVar21 + fVar22;
        fVar17 = param_8[lVar8];
        if (DAT_00070888 < fVar17) {
          fVar17 = (fVar22 - (fVar17 - fVar6) / (fVar16 - fVar6)) * fVar5;
          fVar17 = (fVar15 - fVar17 * fVar17) * DAT_0006fc0c + fVar6;
        }
        else if (fVar17 < fVar7) {
          fVar17 = (fVar22 - ((float)((uint)fVar17 ^ uVar4) - fVar6) / (fVar16 - fVar6)) *
                   DAT_0007082c;
          fVar17 = (float)((uint)((fVar15 - fVar17 * fVar17) * fVar3 + fVar6) ^ uVar4);
        }
        param_8[lVar8] = fVar17;
        fVar16 = *(float *)(this + 0x1504) * fVar21 + fVar22;
        fVar17 = param_9[lVar8];
        if (fVar17 <= DAT_00070888) {
          if (fVar17 < DAT_000717fc) {
            fVar17 = (fVar22 - ((float)((uint)fVar17 ^ uVar4) - fVar6) / (fVar16 - fVar6)) *
                     DAT_0007082c;
            fVar17 = (float)((uint)((DAT_0006fbd4 - fVar17 * fVar17) * DAT_0006fc0c + fVar6) ^ uVar4
                            );
          }
        }
        else {
          fVar17 = (fVar22 - (fVar17 - fVar6) / (fVar16 - fVar6)) * DAT_0007082c;
          fVar17 = (DAT_0006fbd4 - fVar17 * fVar17) * DAT_0006fc0c + fVar6;
        }
        param_9[lVar8] = fVar17;
        iVar10 = iVar10 + 1;
        lVar8 = lVar8 + 1;
      } while (iVar10 != param_10);
    }
    else if (param_10 < 1) goto LAB_000623eb;
  }
  else {
    if (*(int *)(this + 0x10e8) != 1) goto LAB_0006206f;
LAB_000624d4:
    if (0 < param_10) {
      local_248 = 0;
      do {
        local_24c = param_10 - local_248;
        if (local_24c < 0x10) {
          if (0 < local_24c) goto LAB_0006251b;
        }
        else {
          local_24c = 0x10;
LAB_0006251b:
          pfVar13 = param_8 + local_248;
          pfVar9 = param_9 + local_248;
          iVar10 = 0;
          do {
            EnvelopeFollower::process
                      ((EnvelopeFollower *)(this + 0x10d0),
                       (*pfVar13 + *pfVar9) * DAT_0006fbd4 * DAT_0006fbd4);
            iVar10 = iVar10 + 1;
            pfVar13 = pfVar13 + 1;
            pfVar9 = pfVar9 + 1;
          } while (iVar10 < local_24c);
        }
        (**(code **)(**(long **)(this + 8) + 0x40))
                  (*(long **)(this + 8),param_8 + local_248,param_9 + local_248,local_24c,
                   *(undefined8 *)(this + 0x10));
        if (bVar2) {
          fVar22 = (float)local_24c * local_258 + *(float *)(this + 0x1500);
          *(float *)(this + 0x1500) = fVar22;
          fVar21 = *(float *)(this + 0x150c) * *(float *)(this + 0x10dc) * fVar22 +
                   fVar22 * (DAT_0006fb38 - *(float *)(this + 0x150c));
          fVar22 = DAT_000717f4;
          if ((fVar21 < DAT_0006fb38) && (fVar22 = DAT_000717f8, 0.0 < fVar21)) {
            dVar18 = (double)_log10((double)(DAT_0006fb38 - fVar21));
            dVar18 = dVar18 * _DAT_00070570;
            fVar22 = DAT_00070844;
            if ((dVar18 <= DAT_0006fb50) && (fVar22 = DAT_00070848, DAT_00070578 <= dVar18)) {
              fVar22 = (float)(dVar18 * _DAT_00070580 + _DAT_00070588);
            }
            fVar22 = DAT_000717e8 * fVar22;
          }
          fVar22 = (float)_logf(fVar22);
          fVar21 = (float)_logf(DAT_0006fbf8);
          fVar21 = fVar22 * (DAT_00070a98 / fVar21) + _DAT_0006fbfc;
          fVar22 = 0.0;
          if (0.0 <= fVar21) {
            fVar22 = fVar21;
          }
          (**(code **)(**(long **)(this + 8) + 0x10))(fVar22);
          (**(code **)(**(long **)(this + 0x10) + 0x10))(fVar22);
        }
        local_248 = local_248 + local_24c;
      } while (local_248 < param_10);
    }
    *(float *)(this + 0x1500) = param_2;
    *(float *)(this + 0x1504) = param_3;
    iVar10 = *(int *)(this + 0x10ec);
    if (iVar10 != 1) goto LAB_0006233a;
LAB_000626ea:
    fVar22 = DAT_0006fb38;
    if (param_10 < 1) goto LAB_000623eb;
    iVar10 = 0;
    lVar8 = 0;
    do {
      fVar21 = (float)((uint)param_9[lVar8] & DAT_00070610);
      if ((float)((uint)param_9[lVar8] & DAT_00070610) <=
          (float)((uint)param_8[lVar8] & DAT_00070610)) {
        fVar21 = (float)((uint)param_8[lVar8] & DAT_00070610);
      }
      fVar21 = (float)EnvelopeFollower::process((EnvelopeFollower *)(this + 0x10b8),fVar21);
      if (fVar22 < fVar21) {
        fVar21 = fVar22 / fVar21;
        fVar15 = *(float *)(this + 0x10f0);
        if (fVar21 < *(float *)(this + 0x10f0)) {
          *(float *)(this + 0x10f0) = fVar21;
          *(float *)(this + 0x10f4) = (fVar22 - fVar21) / (DAT_00070884 * *(float *)(this + 0x10f8))
          ;
          fVar15 = fVar21;
        }
      }
      else {
        fVar15 = *(float *)(this + 0x10f0);
      }
      if (fVar15 < fVar22) {
        param_8[lVar8] = fVar15 * param_8[lVar8];
        param_9[lVar8] = param_9[lVar8] * *(float *)(this + 0x10f0);
        *(float *)(this + 0x10f0) = *(float *)(this + 0x10f0) + *(float *)(this + 0x10f4);
      }
      iVar10 = iVar10 + 1;
      lVar8 = lVar8 + 1;
    } while (iVar10 != param_10);
  }
  lVar8 = 0;
  do {
    param_8[lVar8] =
         (fVar22 - *(float *)(this + 0x1510)) * local_138[lVar8] +
         *(float *)(this + 0x1510) * param_8[lVar8];
    param_9[lVar8] =
         (fVar22 - *(float *)(this + 0x1510)) * local_238[lVar8] +
         *(float *)(this + 0x1510) * param_9[lVar8];
    *(float *)(this + 0x1510) = (param_5 - fVar1) / (float)param_10 + *(float *)(this + 0x1510);
    lVar8 = lVar8 + 1;
  } while ((int)lVar8 < param_10);
LAB_000623eb:
  *(float *)(this + 0x1510) = param_5;
  return;
}


// ADDRESS 00063c80 NAME CAFilterBiquad::makeLowPassFilter

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* CAFilterBiquad::makeLowPassFilter(float, float, float, bool) */

void __thiscall
CAFilterBiquad::makeLowPassFilter
          (CAFilterBiquad *this,float param_1,float param_2,float param_3,bool param_4)

{
  float fVar1;
  double dVar2;
  double dVar3;
  double dVar4;
  double dVar5;
  double dVar6;
  
  dVar4 = ((double)param_2 / (double)param_1) * DAT_00070620;
  dVar2 = (double)_sin(dVar4);
  dVar3 = (double)_cos(dVar4);
  if (param_4) {
    dVar2 = dVar2 / ((double)param_3 + (double)param_3);
  }
  else {
    dVar4 = (double)_sinh(((double)param_3 * _DAT_00070800 * dVar4) / dVar2);
    dVar2 = dVar2 * dVar4;
  }
  dVar4 = DAT_0006fb50;
  dVar5 = DAT_0006fb50 - dVar3;
  dVar6 = dVar2 + DAT_0006fb50;
  fVar1 = (float)((dVar5 * DAT_00070568) / dVar6);
  *(float *)(this + 0x30) = fVar1;
  *(float *)(this + 0x34) = (float)(dVar5 / dVar6);
  *(float *)(this + 0x38) = fVar1;
  *(float *)(this + 0x3c) = (float)((dVar3 * _DAT_00070780) / dVar6);
  *(float *)(this + 0x40) = (float)((dVar4 - dVar2) / dVar6);
  if (((*(ulong *)(this + 0x30) & 0x7f800000) == 0) && ((*(ulong *)(this + 0x30) & 0x7fffffff) != 0)
     ) {
    *(undefined4 *)(this + 0x30) = 0;
  }
  if (((*(ulong *)(this + 0x34) & 0x7f800000) == 0) && ((*(ulong *)(this + 0x34) & 0x7fffffff) != 0)
     ) {
    *(undefined4 *)(this + 0x34) = 0;
  }
  if (((*(ulong *)(this + 0x38) & 0x7f800000) == 0) && ((*(ulong *)(this + 0x38) & 0x7fffffff) != 0)
     ) {
    *(undefined4 *)(this + 0x38) = 0;
  }
  if (((*(ulong *)(this + 0x3c) & 0x7f800000) == 0) && ((*(ulong *)(this + 0x3c) & 0x7fffffff) != 0)
     ) {
    *(undefined4 *)(this + 0x3c) = 0;
  }
  if (((*(ulong *)(this + 0x40) & 0x7f800000) == 0) && ((*(ulong *)(this + 0x40) & 0x7fffffff) != 0)
     ) {
    *(undefined4 *)(this + 0x40) = 0;
  }
  return;
}


// ADDRESS 00064cd0 NAME CAFilterBiquad::process

/* CAFilterBiquad::process(float*, int) */

void __thiscall CAFilterBiquad::process(CAFilterBiquad *this,float *param_1,int param_2)

{
  float fVar1;
  int iVar2;
  float fVar3;
  
  if (this[0x18] != (CAFilterBiquad)0x0) {
    this[0x18] = (CAFilterBiquad)0x0;
    updateFilter(this,*(float *)(this + 0x24),*(float *)(this + 0x28));
    *(undefined4 *)(this + 0x1c) = *(undefined4 *)(this + 0x24);
    *(undefined4 *)(this + 0x20) = *(undefined4 *)(this + 0x28);
  }
  if (0 < param_2) {
    iVar2 = 0;
    do {
      fVar1 = *param_1;
      fVar3 = ((fVar1 * *(float *)(this + 0x30) + *(float *)(this + 0x34) * *(float *)(this + 0x4c)
               + *(float *)(this + 0x38) * *(float *)(this + 0x50)) -
              *(float *)(this + 0x44) * *(float *)(this + 0x3c)) -
              *(float *)(this + 0x40) * *(float *)(this + 0x48);
      *(float *)(this + 0x48) = *(float *)(this + 0x44);
      *(float *)(this + 0x44) = fVar3;
      *(undefined4 *)(this + 0x50) = *(undefined4 *)(this + 0x4c);
      *(float *)(this + 0x4c) = fVar1;
      *param_1 = fVar3;
      iVar2 = iVar2 + 1;
      param_1 = param_1 + 1;
    } while (iVar2 != param_2);
  }
  if (((((*(ulong *)(this + 0x44) & 0x7f800000) == 0) &&
       ((*(ulong *)(this + 0x44) & 0x7fffffff) != 0)) || (DAT_0006fb40 < *(float *)(this + 0x44)))
     || (((*(float *)(this + 0x44) < DAT_00071800 || (DAT_0006fb40 < *(float *)(this + 0x48))) ||
         (*(float *)(this + 0x48) < DAT_00071800)))) {
    *(undefined4 *)(this + 0x44) = 0;
    *(undefined4 *)(this + 0x48) = 0;
  }
  return;
}


