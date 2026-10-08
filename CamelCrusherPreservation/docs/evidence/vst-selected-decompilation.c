/* Analysis evidence only. Decompiler errors require verification against instructions. */
// ADDRESS 00003940 NAME CamelCrusher::resume

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* CamelCrusher::resume() */

void CamelCrusher::resume(void)

{
  long *in_RDI;
  int iVar1;
  
  if (0 < *(int *)(in_RDI + 2)) {
    iVar1 = 0;
    do {
      PParam::resetToStored();
      iVar1 = iVar1 + 1;
    } while (iVar1 < *(int *)(in_RDI + 2));
  }
  (**(code **)(*in_RDI + 0x48))();
  *(undefined4 *)(in_RDI + 0x8c3) = 0;
                    /* WARNING: Could not recover jumptable at 0x000039b1. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*in_RDI + 0x50))(*(undefined4 *)((long)in_RDI + 0x1c2c),(float)(double)in_RDI[0x386])
  ;
  return;
}


// ADDRESS 000039c0 NAME CamelCrusher::process

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* CamelCrusher::process(float*, float*, float*, float*, int, bool) */

void __thiscall
CamelCrusher::process
          (CamelCrusher *this,float *param_1,float *param_2,float *param_3,float *param_4,
          int param_5,bool param_6)

{
  int *piVar1;
  CamelCrusher CVar2;
  CamelCrusher CVar3;
  CamelCrusher CVar4;
  float *pfVar5;
  float *pfVar6;
  bool bVar7;
  bool bVar8;
  bool bVar9;
  int iVar10;
  int iVar11;
  long lVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  uint uVar18;
  float fVar19;
  double dVar20;
  float *local_78;
  float *local_70;
  float *local_68;
  int local_58;
  float local_4c;
  size_t local_48;
  float local_3c;
  
  pfVar5 = *(float **)(this + 0x4608);
  pfVar6 = *(float **)(this + 0x4610);
  *(double *)(this + 0x1c30) =
       (double)((float)param_5 * *(float *)(this + 0x1c2c)) /
       ((double)*(float *)(this + 0x2a90) * _DAT_0005a6e8) + *(double *)(this + 0x1c30);
  fVar13 = (float)PParam::advanceTimeGetParam(**(PParam ***)(this + 8),param_5);
  bVar8 = false;
  bVar7 = false;
  if (DAT_0005a698 < fVar13) {
    fVar13 = (float)PParam::advanceTimeGetParam(*(PParam **)(*(long *)(this + 8) + 8),param_5);
    bVar7 = 0.0 < fVar13;
    fVar13 = (float)PParam::advanceTimeGetParam(*(PParam **)(*(long *)(this + 8) + 0x10),param_5);
    bVar8 = 0.0 < fVar13;
  }
  fVar13 = (float)PParam::advanceTimeGetParam(*(PParam **)(*(long *)(this + 8) + 0x18),param_5);
  fVar14 = (float)PParam::advanceTimeGetParam(*(PParam **)(*(long *)(this + 8) + 0x30),param_5);
  if (0 < param_5) {
    iVar10 = 0x40;
    local_58 = 0;
    local_78 = param_1;
    local_70 = param_2;
    local_68 = param_3;
    do {
      iVar11 = *(int *)(this + 0x1c24);
      if ((iVar11 < *(int *)(this + 0x1c20)) &&
         (lVar12 = (long)iVar11, *(int *)(this + lVar12 * 4 + 0x20) <= iVar10 + local_58)) {
        CVar2 = this[(long)(&UNK_00001020 + lVar12)];
        CVar3 = this[(long)(&UNK_00001420 + lVar12)];
        CVar4 = this[lVar12 + 0x1820];
        *(int *)(this + 0x1c24) = iVar11 + 1;
        if ((CVar2 == (CamelCrusher)0xb0) && (0 < *(int *)(this + 0x14))) {
          lVar12 = *(long *)(this + 0x18);
          piVar1 = (int *)(lVar12 + 0x8800);
          iVar10 = 0;
          do {
            uVar18 = 0;
            if (iVar10 <= *piVar1) {
              uVar18 = *(uint *)(lVar12 + 0x8000);
            }
            if (uVar18 == (byte)CVar3) {
              CAPlugin::setParam((CAPlugin *)this,iVar10,(float)(uint)(byte)CVar4 / _DAT_0005a6ac);
              break;
            }
            iVar10 = iVar10 + 1;
            lVar12 = lVar12 + 4;
          } while (iVar10 != *(int *)(this + 0x14));
        }
      }
      iVar10 = param_5 - local_58;
      if (iVar10 < 0x40) {
        local_4c = (float)iVar10;
        local_3c = DAT_0005a62c / local_4c;
        local_48 = (long)iVar10 << 2;
      }
      else {
        iVar10 = 0x40;
        local_4c = 64.0;
        local_3c = 0.015625;
        local_48 = 0x100;
      }
      _memcpy(pfVar5,local_78,local_48);
      _memcpy(pfVar6,local_70,local_48);
      if (bVar7) {
        fVar19 = (float)PParam::advanceTimeGetParam(*(PParam **)(*(long *)(this + 8) + 8),iVar10);
        Distortion::processMech((Distortion *)(this + 0x30ac),pfVar5,pfVar6,iVar10,fVar19);
      }
      if (DAT_0005a698 < fVar13) {
        fVar19 = (float)PParam::advanceTimeGetParam(*(PParam **)(*(long *)(this + 8) + 0x20),iVar10)
        ;
        fVar16 = (float)PParam::advanceTimeGetParam(*(PParam **)(*(long *)(this + 8) + 0x28),iVar10)
        ;
        MMFilter::process((MMFilter *)(this + 0x30b8),0,fVar19,fVar16,0.0,DAT_0005a62c,0.0,0.0,
                          pfVar5,pfVar6,iVar10);
      }
      if (bVar8) {
        fVar19 = (float)PParam::advanceTimeGetParam(*(PParam **)(*(long *)(this + 8) + 0x10),iVar10)
        ;
        Distortion::processTube((Distortion *)(this + 0x30ac),pfVar5,pfVar6,iVar10,fVar19);
      }
      if (DAT_0005a698 < fVar14) {
        fVar19 = (float)PParam::advanceTimeGetParam(*(PParam **)(*(long *)(this + 8) + 0x38),iVar10)
        ;
        CACompressor::process
                  ((CACompressor *)(this + 0x45d8),pfVar5,pfVar6,iVar10,
                   (float)(~-(uint)(fVar19 <= DAT_0005a694) & (uint)DAT_0005a694 |
                          (uint)fVar19 & -(uint)(fVar19 <= DAT_0005a694)),DAT_0005a6b0);
      }
      fVar15 = (float)PParam::advanceTimeGetParam(*(PParam **)(*(long *)(this + 8) + 0x50),iVar10);
      fVar16 = (float)PParam::advanceTimeGetParam(*(PParam **)(*(long *)(this + 8) + 0x58),iVar10);
      fVar19 = *(float *)(this + 0x4620);
      dVar20 = (double)_pow((double)fVar16,DAT_0005a6f0);
      fVar16 = *(float *)(this + 0x461c);
      if (0 < iVar10) {
        iVar11 = 0;
        lVar12 = 0;
        fVar17 = *(float *)(this + 0x4620);
        do {
          pfVar5[lVar12] =
               (fVar17 * pfVar5[lVar12] + (DAT_0005a62c - fVar17) * local_78[lVar12]) *
               *(float *)(this + 0x461c);
          pfVar6[lVar12] =
               (*(float *)(this + 0x4620) * pfVar6[lVar12] +
               (DAT_0005a62c - *(float *)(this + 0x4620)) * local_70[lVar12]) *
               *(float *)(this + 0x461c);
          *(float *)(this + 0x461c) =
               *(float *)(this + 0x461c) + ((float)dVar20 - fVar16) * local_3c;
          fVar17 = (fVar15 - fVar19) * local_3c + *(float *)(this + 0x4620);
          *(float *)(this + 0x4620) = fVar17;
          iVar11 = iVar11 + 1;
          lVar12 = lVar12 + 1;
        } while (iVar11 != iVar10);
        iVar11 = 0;
        lVar12 = 0;
        do {
          fVar19 = pfVar5[lVar12];
          fVar16 = pfVar6[lVar12];
          fVar15 = DAT_0005a6b8;
          if (DAT_0005a6b8 <= fVar19) {
            fVar15 = fVar19;
          }
          fVar17 = DAT_0005a6b8;
          if (DAT_0005a6b8 <= fVar16) {
            fVar17 = fVar16;
          }
          bVar9 = fVar16 <= DAT_0005a6b4;
          uVar18 = ~-(uint)bVar9 & (uint)DAT_0005a6b4;
          pfVar5[lVar12] =
               (float)(~-(uint)(fVar19 <= DAT_0005a6b4) & (uint)DAT_0005a6b4 |
                      (uint)fVar15 & -(uint)(fVar19 <= DAT_0005a6b4));
          pfVar6[lVar12] = (float)(uVar18 | (uint)fVar17 & -(uint)bVar9);
          iVar11 = iVar11 + 1;
          lVar12 = lVar12 + 1;
        } while (iVar11 != iVar10);
      }
      if (param_6) {
        iVar11 = 0;
        lVar12 = 0;
        if (0 < iVar10) {
          do {
            local_68[lVar12] = pfVar5[lVar12];
            param_4[lVar12] = pfVar6[lVar12];
            iVar11 = iVar11 + 1;
            lVar12 = lVar12 + 1;
          } while (iVar11 != iVar10);
          goto LAB_00003dae;
        }
LAB_00004074:
        local_4c = (DAT_0005a6bc / *(float *)(this + 0x2a90)) * local_4c;
        *(float *)(this + 0x2c94) = *(float *)(this + 0x2c94) - local_4c;
        *(float *)(this + 0x2c98) = *(float *)(this + 0x2c98) - local_4c;
        if (0.0 < *(float *)(this + 0x2c94) || *(float *)(this + 0x2c94) == 0.0) goto LAB_000040c1;
LAB_00003e8e:
        *(undefined4 *)(this + 0x2c94) = 0;
        if (*(float *)(this + 0x2c98) <= 0.0 && *(float *)(this + 0x2c98) != 0.0) {
LAB_00003ea6:
          *(undefined4 *)(this + 0x2c98) = 0;
        }
      }
      else {
        iVar11 = 0;
        lVar12 = 0;
        if (iVar10 < 1) goto LAB_00004074;
        do {
          local_68[lVar12] = local_68[lVar12] + pfVar5[lVar12];
          param_4[lVar12] = param_4[lVar12] + pfVar6[lVar12];
          iVar11 = iVar11 + 1;
          lVar12 = lVar12 + 1;
        } while (iVar11 != iVar10);
LAB_00003dae:
        local_4c = (DAT_0005a6bc / *(float *)(this + 0x2a90)) * local_4c;
        *(float *)(this + 0x2c94) = *(float *)(this + 0x2c94) - local_4c;
        *(float *)(this + 0x2c98) = *(float *)(this + 0x2c98) - local_4c;
        iVar11 = 0;
        lVar12 = 0;
        do {
          fVar19 = *(float *)(lVar12 + (long)pfVar5);
          fVar16 = fVar19;
          fVar15 = *(float *)(this + 0x2c94);
          if (*(float *)(this + 0x2c94) < fVar19) {
            *(float *)(this + 0x2c94) = fVar19;
            fVar16 = *(float *)(lVar12 + (long)pfVar5);
            fVar15 = fVar19;
          }
          if (fVar16 < (float)((uint)fVar15 ^ DAT_0005a700)) {
            *(uint *)(this + 0x2c94) = (uint)fVar16 ^ DAT_0005a700;
          }
          fVar19 = *(float *)(lVar12 + (long)pfVar6);
          fVar16 = fVar19;
          fVar15 = *(float *)(this + 0x2c98);
          if (*(float *)(this + 0x2c98) < fVar19) {
            *(float *)(this + 0x2c98) = fVar19;
            fVar16 = *(float *)(lVar12 + (long)pfVar6);
            fVar15 = fVar19;
          }
          if (fVar16 < (float)((uint)fVar15 ^ DAT_0005a700)) {
            *(uint *)(this + 0x2c98) = (uint)fVar16 ^ DAT_0005a700;
          }
          iVar11 = iVar11 + 8;
          lVar12 = lVar12 + 0x20;
        } while (iVar11 < iVar10);
        if (*(float *)(this + 0x2c94) <= 0.0 && *(float *)(this + 0x2c94) != 0.0) goto LAB_00003e8e;
LAB_000040c1:
        if (*(float *)(this + 0x2c98) <= 0.0 && *(float *)(this + 0x2c98) != 0.0) goto LAB_00003ea6;
      }
      if (param_5 <= local_58 + iVar10) break;
      local_58 = local_58 + iVar10;
      local_78 = (float *)((long)local_78 + local_48);
      local_70 = (float *)((long)local_70 + local_48);
      local_68 = (float *)((long)local_68 + local_48);
      param_4 = (float *)((long)param_4 + local_48);
    } while( true );
  }
  *(undefined4 *)(this + 0x1c20) = 0;
  *(undefined4 *)(this + 0x1c24) = 0;
  return;
}


// ADDRESS 00004190 NAME CamelCrusher::setParamCustom

/* CamelCrusher::setParamCustom(int, float) */

void __thiscall CamelCrusher::setParamCustom(CamelCrusher *this,int param_1,float param_2)

{
  if (param_1 == 8) {
    *(uint *)(this + 0x45dc) = ~-(uint)(DAT_0005a698 <= param_2) & DAT_0005a6cc;
    return;
  }
  if (param_1 != 9) {
    return;
  }
  this[0x2ca1] = (CamelCrusher)(param_2 < DAT_0005a698);
  return;
}


// ADDRESS 00004360 NAME CamelCrusher::processAllEvents

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
    CVar3 = in_RDI[(long)(&UNK_00001420 + lVar5)];
    CVar4 = in_RDI[lVar5 + 0x1820];
    *(int *)(in_RDI + 0x1c24) = iVar7 + 1;
    if ((CVar2 == (CAPlugin)0xb0) && (0 < *(int *)(in_RDI + 0x14))) {
      lVar5 = *(long *)(in_RDI + 0x18);
      piVar1 = (int *)(lVar5 + 0x8800);
      iVar7 = 0;
      do {
        uVar6 = 0;
        if (iVar7 <= *piVar1) {
          uVar6 = *(uint *)(lVar5 + 0x8000);
        }
        if (uVar6 == (byte)CVar3) {
          CAPlugin::setParam(in_RDI,iVar7,(float)(uint)(byte)CVar4 / _DAT_0005a6ac);
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


// ADDRESS 00004420 NAME CamelCrusher::CamelCrusher

/* CamelCrusher::CamelCrusher(char const*, char const*) */

void __thiscall CamelCrusher::CamelCrusher(CamelCrusher *this,char *param_1,char *param_2)

{
  CamelCrusher *pCVar1;
  PParam **ppPVar2;
  long lVar3;
  int iVar4;
  size_t sVar5;
  PParam *pPVar6;
  void *pvVar7;
  ConfigStore *this_00;
  long lVar8;
  char *pcVar9;
  char *local_1838 [512];
  int local_838 [514];
  
  CAPlugin::CAPlugin((CAPlugin *)this,0x11,0x1a,param_1);
  *(undefined ***)this = &PTR_process_0007cfb0;
  Distortion::Distortion((Distortion *)(this + 0x30ac));
  MMFilter::MMFilter((MMFilter *)(this + 0x30b8));
  CACompressor::CACompressor((CACompressor *)(this + 0x45d8));
  _strcpy((char *)(this + 0x2cab),param_2);
  pCVar1 = this + 0x2eab;
  _strcpy((char *)pCVar1,param_2);
  sVar5 = _strlen((char *)pCVar1);
  *(undefined4 *)(pCVar1 + sVar5) = 0x61746144;
  *(undefined *)((long)(pCVar1 + sVar5) + 4) = 0;
  ppPVar2 = *(PParam ***)(this + 8);
  pPVar6 = (PParam *)operator_new(0x22d8);
  PParam::PParam(pPVar6,0,false,"DistOn","DistOn","",0.0,DAT_0005a62c);
  *ppPVar2 = pPVar6;
  lVar3 = *(long *)(this + 8);
  pPVar6 = (PParam *)operator_new(0x22d8);
  PParam::PParam(pPVar6,1,true,"DistMech","DistMech","%",0.0,DAT_0005a62c);
  *(PParam **)(lVar3 + 8) = pPVar6;
  lVar3 = *(long *)(this + 8);
  pPVar6 = (PParam *)operator_new(0x22d8);
  PParam::PParam(pPVar6,1,true,"DistTube","DistTube","%",0.0,DAT_0005a62c);
  *(PParam **)(lVar3 + 0x10) = pPVar6;
  lVar3 = *(long *)(this + 8);
  pPVar6 = (PParam *)operator_new(0x22d8);
  PParam::PParam(pPVar6,0,false,"MmFilterOn","MmFilterOn","",0.0,DAT_0005a62c);
  *(PParam **)(lVar3 + 0x18) = pPVar6;
  lVar3 = *(long *)(this + 8);
  pPVar6 = (PParam *)operator_new(0x22d8);
  PParam::PParam(pPVar6,6,true,"MmFilterCutoff","MmFilterCutoff","Hz",0.0,DAT_0005a62c);
  *(PParam **)(lVar3 + 0x20) = pPVar6;
  lVar3 = *(long *)(this + 8);
  pPVar6 = (PParam *)operator_new(0x22d8);
  PParam::PParam(pPVar6,1,true,"MmFilterRes","MmFilterRes","%",0.0,DAT_0005a62c);
  *(PParam **)(lVar3 + 0x28) = pPVar6;
  lVar3 = *(long *)(this + 8);
  pPVar6 = (PParam *)operator_new(0x22d8);
  PParam::PParam(pPVar6,0,false,"CompressOn","CompressOn","",0.0,DAT_0005a62c);
  *(PParam **)(lVar3 + 0x30) = pPVar6;
  lVar3 = *(long *)(this + 8);
  pPVar6 = (PParam *)operator_new(0x22d8);
  PParam::PParam(pPVar6,7,true,"CompressAmount","CompressAmnt","dB",0.0,DAT_0005a694);
  *(PParam **)(lVar3 + 0x38) = pPVar6;
  lVar3 = *(long *)(this + 8);
  pPVar6 = (PParam *)operator_new(0x22d8);
  PParam::PParam(pPVar6,0,false,"CompressMode","CompressMode","",0.0,DAT_0005a62c);
  *(PParam **)(lVar3 + 0x40) = pPVar6;
  lVar3 = *(long *)(this + 8);
  pPVar6 = (PParam *)operator_new(0x22d8);
  PParam::PParam(pPVar6,0,false,"MasterOn","MasterOn","",0.0,DAT_0005a62c);
  *(PParam **)(lVar3 + 0x48) = pPVar6;
  lVar3 = *(long *)(this + 8);
  pPVar6 = (PParam *)operator_new(0x22d8);
  PParam::PParam(pPVar6,1,true,"MasterMix","MasterMix","%",0.0,DAT_0005a62c);
  *(PParam **)(lVar3 + 0x50) = pPVar6;
  lVar3 = *(long *)(this + 8);
  pPVar6 = (PParam *)operator_new(0x22d8);
  PParam::PParam(pPVar6,8,true,"MasterVolume","MasterVol","dB",0.0,DAT_0005a62c);
  *(PParam **)(lVar3 + 0x58) = pPVar6;
  lVar3 = *(long *)(this + 8);
  pPVar6 = (PParam *)operator_new(0x22d8);
  PParam::PParam(pPVar6,0,false,"Unused1","Unused1","",0.0,DAT_0005a62c);
  *(PParam **)(lVar3 + 0x60) = pPVar6;
  lVar3 = *(long *)(this + 8);
  pPVar6 = (PParam *)operator_new(0x22d8);
  PParam::PParam(pPVar6,0,false,"Unused2","Unused2","",0.0,DAT_0005a62c);
  *(PParam **)(lVar3 + 0x68) = pPVar6;
  lVar3 = *(long *)(this + 8);
  pPVar6 = (PParam *)operator_new(0x22d8);
  PParam::PParam(pPVar6,0,false,"Unused3","Unused3","",0.0,DAT_0005a62c);
  *(PParam **)(lVar3 + 0x70) = pPVar6;
  lVar3 = *(long *)(this + 8);
  pPVar6 = (PParam *)operator_new(0x22d8);
  PParam::PParam(pPVar6,0,false,"Unused4","Unused4","",0.0,DAT_0005a62c);
  *(PParam **)(lVar3 + 0x78) = pPVar6;
  lVar3 = *(long *)(this + 8);
  pPVar6 = (PParam *)operator_new(0x22d8);
  PParam::PParam(pPVar6,0,false,"Unused5","Unused5","",0.0,DAT_0005a62c);
  *(PParam **)(lVar3 + 0x80) = pPVar6;
  lVar3 = *(long *)(this + 8);
  pPVar6 = (PParam *)operator_new(0x22d8);
  PParam::PParam(pPVar6,0,false,"Unused","",(char *)0x0,0.0,DAT_0005a62c);
  *(PParam **)(lVar3 + 0x88) = pPVar6;
  lVar3 = *(long *)(this + 8);
  pPVar6 = (PParam *)operator_new(0x22d8);
  PParam::PParam(pPVar6,0,false,"Randomize","",(char *)0x0,0.0,DAT_0005a62c);
  *(PParam **)(lVar3 + 0x90) = pPVar6;
  lVar3 = *(long *)(this + 8);
  pPVar6 = (PParam *)operator_new(0x22d8);
  PParam::PParam(pPVar6,0,false,"ParamDisplay","",(char *)0x0,0.0,DAT_0005a62c);
  *(PParam **)(lVar3 + 0x98) = pPVar6;
  lVar3 = *(long *)(this + 8);
  pPVar6 = (PParam *)operator_new(0x22d8);
  PParam::PParam(pPVar6,1,false,"VersionDisplay","",(char *)0x0,0.0,DAT_0005a62c);
  *(PParam **)(lVar3 + 0xa0) = pPVar6;
  lVar3 = *(long *)(this + 8);
  pPVar6 = (PParam *)operator_new(0x22d8);
  pcVar9 = "";
  PParam::PParam(pPVar6,1,false,"GlobalMenu","",(char *)0x0,0.0,DAT_0005a62c);
  *(PParam **)(lVar3 + 0xa8) = pPVar6;
  lVar3 = *(long *)(this + 8);
  pPVar6 = (PParam *)operator_new(0x22d8);
  PParam::PParam(pPVar6,1,false,"UpDownPreset",pcVar9,(char *)0x0,0.0,DAT_0005a62c);
  *(PParam **)(lVar3 + 0xb0) = pPVar6;
  lVar3 = *(long *)(this + 8);
  pPVar6 = (PParam *)operator_new(0x22d8);
  PParam::PParam(pPVar6,1,false,"Dummy","",(char *)0x0,0.0,DAT_0005a62c);
  *(PParam **)(lVar3 + 0xb8) = pPVar6;
  lVar3 = *(long *)(this + 8);
  pPVar6 = (PParam *)operator_new(0x22d8);
  PParam::PParam(pPVar6,1,false,"PresetSelector","",(char *)0x0,0.0,DAT_0005a62c);
  *(PParam **)(lVar3 + 0xc0) = pPVar6;
  lVar3 = *(long *)(this + 8);
  pPVar6 = (PParam *)operator_new(0x22d8);
  PParam::PParam(pPVar6,1,false,"InfoLink","",(char *)0x0,0.0,DAT_0005a62c);
  *(PParam **)(lVar3 + 200) = pPVar6;
  pvVar7 = operator_new__(0x100);
  *(void **)(this + 0x4608) = pvVar7;
  pvVar7 = operator_new__(0x100);
  *(void **)(this + 0x4610) = pvVar7;
  *(undefined4 *)(this + 0x461c) = 0;
  *(undefined4 *)(this + 0x4620) = 0;
  this[0x2ca0] = (CamelCrusher)0x0;
  _sprintf((char *)(this + 0x1e48),"%s%c%s",param_1,(ulong)(uint)(int)(char)_g_dirSeparator,
           "CamelCrusherData");
  _sprintf((char *)(this + 0x2a94),"%s%c",this + 0x1e48,(ulong)(uint)(int)(char)_g_dirSeparator);
  _g_dirSeparator = _g_dirSeparator << 0x15 | _g_dirSeparator >> 0x2b;
  _sprintf((char *)(this + 0x2048),"%s%cMidiConfig.txt");
  if (0 < *(int *)(this + 0x14)) {
    lVar8 = 0;
    lVar3 = *(long *)(this + 8);
    do {
      local_1838[lVar8] = (char *)(*(long *)(lVar3 + lVar8 * 8) + 0x18);
      local_838[lVar8] = -1;
      iVar4 = (int)lVar8;
      lVar8 = lVar8 + 1;
    } while (iVar4 + 1 < *(int *)(this + 0x14));
  }
  this_00 = (ConfigStore *)operator_new(0x8804);
  ConfigStore::ConfigStore(this_00,*(int *)(this + 0x14),local_1838,local_838);
  *(ConfigStore **)(this + 0x18) = this_00;
  CAPlugin::loadMidiMap();
  if (((*(float *)(this + 0x1c2c) != DAT_0005a6d8) ||
      (NAN(*(float *)(this + 0x1c2c)) || NAN(DAT_0005a6d8))) || (*(double *)(this + 0x1c30) != 0.0))
  {
    *(undefined4 *)(this + 0x1c2c) = 0x42f00000;
    *(undefined8 *)(this + 0x1c30) = 0;
  }
  return;
}


// ADDRESS 00004d70 NAME CamelCrusher::CamelCrusher

/* CamelCrusher::CamelCrusher(char const*, char const*) */

void __thiscall CamelCrusher::CamelCrusher(CamelCrusher *this,char *param_1,char *param_2)

{
  CamelCrusher(this,param_1,param_2);
  return;
}


// ADDRESS 00005de0 NAME CamelCrusherProgram::clearCustom

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


// ADDRESS 00006510 NAME PParam::PParam

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


// ADDRESS 00007420 NAME PParam::advanceTimeGetParam

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
    if (fVar4 <= DAT_0005a62c) {
      fVar2 = DAT_0005a62c - fVar4;
    }
    else {
      fVar2 = 0.0;
      fVar4 = DAT_0005a62c;
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
    if ((_DAT_0005a630 <= fVar4) || (NAN(fVar4) || NAN(_DAT_0005a630))) {
      fVar2 = DAT_0005a62c;
      if (fVar4 <= DAT_0005a62c) {
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


// ADDRESS 000074f0 NAME PParam::PParam

/* PParam::PParam(PParamType, bool, char*, char*, char*, float, float) */

ulong __thiscall
PParam::PParam(PParam *this,PParamType param_1,bool param_2,char *param_3,char *param_4,
              char *param_5,float param_6,float param_7)

{
  char *pcVar1;
  undefined *puVar2;
  char **ppcVar3;
  ulong uVar4;
  PParam *pPVar5;
  char *unaff_R12;
  char *unaff_R13;
  bool bVar6;
  
  puVar2 = &stack0xfffffffffffffff8;
  do {
    bVar6 = SBORROW8((long)puVar2,0x40);
    ppcVar3 = (char **)(puVar2 + -0x40);
    puVar2 = puVar2 + -0x40;
  } while (!bVar6);
  pcVar1 = *ppcVar3;
  uVar4 = (ulong)pcVar1 & 0xffffffff;
  pPVar5 = this + 0x18;
  *(undefined8 *)(uVar4 - 8) = 0x7531;
  _strcpy((char *)pPVar5,pcVar1);
  if (unaff_R12 == (char *)0x0) {
    this[0x118] = (PParam)0x0;
  }
  else {
    pPVar5 = this + 0x118;
    *(undefined8 *)(uVar4 - 8) = 0x7549;
    _strcpy((char *)pPVar5,unaff_R12);
  }
  if (unaff_R13 == (char *)0x0) {
    this[0x98] = (PParam)0x0;
  }
  else {
    pPVar5 = this + 0x98;
    *(undefined8 *)(uVar4 - 8) = 0x7561;
    _strcpy((char *)pPVar5,unaff_R13);
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
  *(undefined4 *)(this + 0xc229c) = 0;
  *(undefined4 *)(this + 0x1b8) = 0;
  *(undefined4 *)(this + 0xc22d8) = 0;
  *(undefined4 *)(this + 0x1c0) = 0;
  this[0x1c4] = (PParam)param_2;
  this[0xc20f9c5] = (PParam)0x0;
  *(undefined4 *)(this + 0x1c8) = 0;
  *(undefined4 *)(this + 0x22cc) = 0;
  *(undefined4 *)(this + 0x22d0) = 0;
  this[0x22d4] = (PParam)0x0;
  this[0x22d5] = (PParam)0x0;
  return (ulong)pPVar5 & 0xffffffff;
}


// ADDRESS 0002c890 NAME CAProgram::load

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


// ADDRESS 0002ca10 NAME CAProgram::save

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


// ADDRESS 0002cbc0 NAME CAProgram::loadCustom

/* CAProgram::loadCustom(FileIO*, float, int) */

void CAProgram::loadCustom(FileIO *param_1,float param_2,int param_3)

{
  return;
}


// ADDRESS 0002cbd0 NAME CAProgram::saveCustom

/* CAProgram::saveCustom(FileIO*, float) */

void CAProgram::saveCustom(FileIO *param_1,float param_2)

{
  return;
}


// ADDRESS 0002dd50 NAME EnvelopeFollower::process

/* EnvelopeFollower::process(float) */

float __thiscall EnvelopeFollower::process(EnvelopeFollower *this,float param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  
  fVar2 = *(float *)(this + 0xc) - *(float *)(this + 0x14);
  if (param_1 <= fVar2) {
    if ((float)((uint)fVar2 ^ DAT_0005a700) <= param_1) {
      fVar3 = 0.0;
      goto LAB_0002dd83;
    }
    param_1 = (float)((uint)param_1 ^ DAT_0005a700);
  }
  fVar3 = param_1 - fVar2;
LAB_0002dd83:
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


// ADDRESS 00031140 NAME CACompressor::process

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
  
  fVar4 = DAT_0005a62c;
  fVar1 = *(float *)this;
  fVar12 = DAT_0005a62c / (DAT_0005a62c - fVar1);
  fVar2 = *(float *)(this + 8);
  fVar3 = *(float *)(this + 0xc);
  *(float *)(this + 8) = param_5;
  if (0 < param_3) {
    iVar6 = 0;
    lVar5 = 0;
    fVar7 = fVar12 - _DAT_0005b2f8;
    do {
      fVar11 = param_1[lVar5];
      fVar10 = param_2[lVar5];
      fVar9 = (float)((uint)fVar11 & DAT_0005b100);
      fVar8 = (float)((uint)fVar10 & DAT_0005b100);
      if (fVar9 <= fVar8) {
        fVar9 = fVar8;
      }
      if ((*(float *)(this + 4) != 0.0) || (NAN(*(float *)(this + 4)))) {
        fVar9 = (float)EnvelopeFollower::process((EnvelopeFollower *)(this + 0x18),fVar9);
      }
      else {
        fVar9 = (float)((uint)fVar9 & DAT_0005b100);
      }
      fVar11 = fVar11 * fVar12;
      fVar10 = fVar10 * fVar12;
      fVar9 = fVar9 * fVar12;
      if (fVar9 <= _DAT_0005b2f8) {
        fVar8 = *(float *)(this + 0x10);
      }
      else {
        fVar8 = (fVar4 - (fVar9 - _DAT_0005b2f8) / fVar7) * DAT_0005b2fc;
        fVar9 = ((DAT_0005a698 - fVar8 * fVar8) * _DAT_0005b300 + _DAT_0005b2f8) / fVar9;
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


// ADDRESS 000329b0 NAME Distortion::processMech

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
  
  fVar3 = DAT_0005b328;
  fVar2 = DAT_0005b258;
  uVar1 = DAT_0005a700;
  fVar6 = DAT_0005ab94 * *(float *)(this + 4) + DAT_0005a62c;
  fVar7 = DAT_0005a6a4 / (fVar6 - DAT_0005b258);
  if (0 < param_2) {
    iVar4 = 0;
    do {
      while (fVar5 = *param_1 * fVar6, fVar5 <= DAT_0005b258) {
        if (fVar3 <= fVar5) goto LAB_00032a0c;
        *param_1 = (float)((uint)((fVar3 - fVar5) * fVar7 + fVar2) ^ uVar1);
        iVar4 = iVar4 + 1;
        param_1 = param_1 + 1;
        if (iVar4 == param_2) {
          return;
        }
      }
      fVar5 = (fVar5 - fVar2) * fVar7 + fVar2;
LAB_00032a0c:
      *param_1 = fVar5;
      iVar4 = iVar4 + 1;
      param_1 = param_1 + 1;
    } while (iVar4 != param_2);
  }
  return;
}


// ADDRESS 00032a60 NAME Distortion::processTube

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
  
  fVar7 = DAT_0005b330;
  fVar6 = DAT_0005b32c;
  fVar5 = DAT_0005b2fc;
  uVar4 = DAT_0005a700;
  fVar3 = DAT_0005a6d0;
  fVar2 = DAT_0005a698;
  fVar1 = DAT_0005a62c;
  fVar10 = DAT_0005b034 * *(float *)(this + 8) + DAT_0005a62c;
  if (0 < param_2) {
    iVar8 = 0;
    fVar11 = fVar10 - DAT_0005a6d0;
    do {
      while (fVar9 = *param_1 * fVar10, fVar9 <= DAT_0005a6d0) {
        if (fVar7 <= fVar9) goto LAB_00032b14;
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
LAB_00032b14:
      *param_1 = fVar9;
      iVar8 = iVar8 + 1;
      param_1 = param_1 + 1;
    } while (iVar8 != param_2);
  }
  return;
}


// ADDRESS 00032c60 NAME Distortion::processMech

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
  fVar3 = DAT_0005b328;
  fVar2 = DAT_0005b258;
  fVar6 = DAT_0005ab94;
  uVar1 = DAT_0005a700;
  fVar10 = DAT_0005a6a4;
  fVar8 = DAT_0005a62c;
  fVar7 = param_4 * DAT_0005ab94 + DAT_0005a62c;
  fVar9 = DAT_0005a6a4 / (fVar7 - DAT_0005b258);
  if (0 < param_3) {
    iVar4 = 0;
    do {
      while (fVar5 = *param_1 * fVar7, DAT_0005b258 < fVar5) {
        fVar5 = (fVar5 - fVar2) * fVar9 + fVar2;
LAB_00032ccc:
        *param_1 = fVar5;
        iVar4 = iVar4 + 1;
        param_1 = param_1 + 1;
        if (iVar4 == param_3) goto LAB_00032d16;
      }
      if (fVar3 <= fVar5) goto LAB_00032ccc;
      *param_1 = (float)((uint)((fVar3 - fVar5) * fVar9 + fVar2) ^ uVar1);
      iVar4 = iVar4 + 1;
      param_1 = param_1 + 1;
    } while (iVar4 != param_3);
LAB_00032d16:
    fVar3 = DAT_0005b328;
    uVar1 = DAT_0005a700;
    fVar8 = fVar6 * *(float *)(this + 4) + fVar8;
    fVar10 = fVar10 / (fVar8 - fVar2);
    iVar4 = 0;
    do {
      while (fVar6 = *param_2 * fVar8, fVar6 <= DAT_0005b258) {
        if (fVar3 <= fVar6) goto LAB_00032d5c;
        *param_2 = (float)((uint)((fVar3 - fVar6) * fVar10 + fVar2) ^ uVar1);
        iVar4 = iVar4 + 1;
        param_2 = param_2 + 1;
        if (iVar4 == param_3) {
          return;
        }
      }
      fVar6 = (fVar6 - fVar2) * fVar10 + fVar2;
LAB_00032d5c:
      *param_2 = fVar6;
      iVar4 = iVar4 + 1;
      param_2 = param_2 + 1;
    } while (iVar4 != param_3);
  }
  return;
}


// ADDRESS 00032db0 NAME Distortion::processTube

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
  fVar7 = DAT_0005b330;
  fVar6 = DAT_0005b32c;
  fVar5 = DAT_0005b2fc;
  uVar4 = DAT_0005a700;
  fVar3 = DAT_0005a6d0;
  fVar2 = DAT_0005a698;
  fVar1 = DAT_0005a62c;
  fVar10 = DAT_0005b034 * param_4 + DAT_0005a62c;
  if (0 < param_3) {
    iVar8 = 0;
    fVar11 = fVar10 - DAT_0005a6d0;
    do {
      while (fVar9 = *param_1 * fVar10, DAT_0005a6d0 < fVar9) {
        fVar9 = (fVar1 - (fVar9 - fVar3) / fVar11) * fVar5;
        fVar9 = (fVar2 - fVar9 * fVar9) * fVar6 + fVar3;
LAB_00032e64:
        *param_1 = fVar9;
        iVar8 = iVar8 + 1;
        param_1 = param_1 + 1;
        if (iVar8 == param_3) goto LAB_00032ed7;
      }
      if (fVar7 <= fVar9) goto LAB_00032e64;
      fVar9 = (fVar1 - (fVar7 - fVar9) / fVar11) * fVar5;
      *param_1 = (float)((uint)((fVar2 - fVar9 * fVar9) * fVar6 + fVar3) ^ uVar4);
      iVar8 = iVar8 + 1;
      param_1 = param_1 + 1;
    } while (iVar8 != param_3);
LAB_00032ed7:
    fVar7 = DAT_0005b330;
    fVar6 = DAT_0005b32c;
    fVar5 = DAT_0005b2fc;
    uVar4 = DAT_0005a700;
    fVar3 = DAT_0005a6d0;
    fVar2 = DAT_0005a698;
    fVar10 = DAT_0005b034 * *(float *)(this + 8) + fVar1;
    iVar8 = 0;
    fVar11 = fVar10 - DAT_0005a6d0;
    do {
      while (fVar9 = *param_2 * fVar10, fVar9 <= DAT_0005a6d0) {
        if (fVar7 <= fVar9) goto LAB_00032f73;
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
LAB_00032f73:
      *param_2 = fVar9;
      iVar8 = iVar8 + 1;
      param_2 = param_2 + 1;
    } while (iVar8 != param_3);
  }
  return;
}


// ADDRESS 0004d4d0 NAME MMFilter::process

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
      *(float *)(this + 0x10e0) = DAT_0005a62c / (param_6 * *(float *)(this + 0x10d0));
    }
    else {
      *(undefined4 *)(this + 0x10e0) = 0;
    }
  }
  if (param_7 != *(float *)(this + 0x1518)) {
    *(float *)(this + 0x1518) = param_7;
    *(float *)(this + 0x10d8) = param_7;
    if ((param_7 != 0.0) || (NAN(param_7))) {
      *(float *)(this + 0x10e4) = DAT_0005a62c / (param_7 * *(float *)(this + 0x10d0));
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
    fVar21 = fVar22 * *(float *)(this + 0x10dc) * local_29c + (DAT_0005a62c - fVar22) * local_29c;
    if (fVar21 < DAT_0005a62c) {
      if (fVar21 <= 0.0) {
        uVar19 = (ulong)(uint)DAT_0005c258;
      }
      else {
        dVar18 = (double)_log10((double)(DAT_0005a62c - fVar21));
        dVar18 = dVar18 * _DAT_0005b060;
        if (dVar18 <= DAT_0005b050) {
          if ((DAT_0005b068 <= dVar18) || (NAN(dVar18) || NAN(DAT_0005b068))) {
            dVar18 = dVar18 * _DAT_0005b070 + _DAT_0005b078;
            uVar20 = (undefined4)((ulong)dVar18 >> 0x20);
            fVar21 = (float)dVar18;
          }
          else {
            uVar20 = 0;
            fVar21 = DAT_0005b31c;
          }
        }
        else {
          uVar20 = 0;
          fVar21 = DAT_0005b318;
        }
        uVar19 = CONCAT44(uVar20,fVar21 * DAT_0005c248);
      }
    }
    else {
      uVar19 = (ulong)(uint)DAT_0005c254;
    }
    fVar21 = (float)_logf(uVar19);
    fVar15 = (float)_logf(DAT_0005a6bc);
    fVar15 = (DAT_0005b4d8 / fVar15) * fVar21 + _DAT_0005a6c0;
    fVar21 = 0.0;
    if (0.0 <= fVar15) {
      fVar21 = fVar15;
    }
    fVar15 = *(float *)(this + 0x10fc);
    if (fVar21 <= *(float *)(this + 0x10fc)) {
      fVar15 = fVar21;
    }
    if (iVar10 != param_1) {
      setFilterType(this,param_1,fVar15,*(float *)(this + 0x1504),DAT_0005a62c);
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
    fVar22 = param_4 * *(float *)(this + 0x10dc) * local_29c + (DAT_0005a62c - param_4) * local_29c;
    if (fVar22 < DAT_0005a62c) {
      if (fVar22 <= 0.0) {
        uVar19 = (ulong)(uint)DAT_0005c258;
      }
      else {
        dVar18 = (double)_log10((double)(DAT_0005a62c - fVar22));
        dVar18 = dVar18 * _DAT_0005b060;
        if (dVar18 <= DAT_0005b050) {
          if ((DAT_0005b068 <= dVar18) || (NAN(dVar18) || NAN(DAT_0005b068))) {
            dVar18 = dVar18 * _DAT_0005b070 + _DAT_0005b078;
            uVar20 = (undefined4)((ulong)dVar18 >> 0x20);
            fVar22 = (float)dVar18;
          }
          else {
            uVar20 = 0;
            fVar22 = DAT_0005b31c;
          }
        }
        else {
          uVar20 = 0;
          fVar22 = DAT_0005b318;
        }
        uVar19 = CONCAT44(uVar20,fVar22 * DAT_0005c248);
      }
    }
    else {
      uVar19 = (ulong)(uint)DAT_0005c254;
    }
    fVar22 = (float)_logf(uVar19);
    fVar21 = (float)_logf(DAT_0005a6bc);
    fVar21 = (DAT_0005b4d8 / fVar21) * fVar22 + _DAT_0005a6c0;
    fVar22 = 0.0;
    if (0.0 <= fVar21) {
      fVar22 = fVar21;
    }
    (**(code **)(**(long **)(this + 8) + 0x18))(*(undefined4 *)(this + 0x1504));
    (**(code **)(**(long **)(this + 0x10) + 0x18))(*(undefined4 *)(this + 0x1504));
    (**(code **)(**(long **)(this + 8) + 0x10))(fVar22);
    (**(code **)(**(long **)(this + 0x10) + 0x10))(fVar22);
    if (*(int *)(this + 0x10e8) == 1) goto LAB_0004dca4;
LAB_0004d83f:
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
          if (0 < iVar11) goto LAB_0004d911;
        }
        else {
          pMVar14 = this + (long)(&DAT_00001100 + (long)local_244 * 4);
          pMVar12 = this + (long)(&DAT_00001300 + (long)local_244 * 4);
          iVar11 = 0x10;
LAB_0004d911:
          lVar8 = 0;
          do {
            EnvelopeFollower::process
                      ((EnvelopeFollower *)(this + 0x10d0),
                       (*(float *)(pMVar14 + lVar8 * 4) + *(float *)(pMVar12 + lVar8 * 4)) *
                       DAT_0005a698 * DAT_0005a698);
            lVar8 = lVar8 + 1;
          } while ((int)lVar8 < iVar11);
        }
        (**(code **)(**(long **)(this + 8) + 0x40))
                  (*(long **)(this + 8),pMVar14,pMVar12,iVar11,*(undefined8 *)(this + 0x10));
        if (bVar2) {
          fVar22 = (float)iVar11 * local_258 + *(float *)(this + 0x1500);
          *(float *)(this + 0x1500) = fVar22;
          fVar21 = *(float *)(this + 0x150c) * *(float *)(this + 0x10dc) * fVar22 +
                   fVar22 * (DAT_0005a62c - *(float *)(this + 0x150c));
          fVar22 = DAT_0005c254;
          if ((fVar21 < DAT_0005a62c) && (fVar22 = DAT_0005c258, 0.0 < fVar21)) {
            dVar18 = (double)_log10((double)(DAT_0005a62c - fVar21));
            dVar18 = dVar18 * _DAT_0005b060;
            fVar22 = DAT_0005b318;
            if ((dVar18 <= DAT_0005b050) && (fVar22 = DAT_0005b31c, DAT_0005b068 <= dVar18)) {
              fVar22 = (float)(dVar18 * _DAT_0005b070 + _DAT_0005b078);
            }
            fVar22 = DAT_0005c248 * fVar22;
          }
          fVar22 = (float)_logf(fVar22);
          fVar21 = (float)_logf(DAT_0005a6bc);
          fVar21 = fVar22 * (DAT_0005b4d8 / fVar21) + _DAT_0005a6c0;
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
    fVar22 = DAT_0005a698;
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
    if (iVar10 == 1) goto LAB_0004deba;
LAB_0004db0a:
    fVar7 = DAT_0005c25c;
    fVar6 = DAT_0005b358;
    fVar5 = DAT_0005b2fc;
    uVar4 = DAT_0005a700;
    fVar3 = DAT_0005a6d0;
    fVar15 = DAT_0005a698;
    fVar21 = DAT_0005a690;
    fVar22 = DAT_0005a62c;
    if (iVar10 == 2) {
      if (param_10 < 1) goto LAB_0004dbbb;
      iVar10 = 0;
      lVar8 = 0;
      do {
        fVar16 = *(float *)(this + 0x1504) * fVar21 + fVar22;
        fVar17 = param_8[lVar8];
        if (DAT_0005b358 < fVar17) {
          fVar17 = (fVar22 - (fVar17 - fVar6) / (fVar16 - fVar6)) * fVar5;
          fVar17 = (fVar15 - fVar17 * fVar17) * DAT_0005a6d0 + fVar6;
        }
        else if (fVar17 < fVar7) {
          fVar17 = (fVar22 - ((float)((uint)fVar17 ^ uVar4) - fVar6) / (fVar16 - fVar6)) *
                   DAT_0005b2fc;
          fVar17 = (float)((uint)((fVar15 - fVar17 * fVar17) * fVar3 + fVar6) ^ uVar4);
        }
        param_8[lVar8] = fVar17;
        fVar16 = *(float *)(this + 0x1504) * fVar21 + fVar22;
        fVar17 = param_9[lVar8];
        if (fVar17 <= DAT_0005b358) {
          if (fVar17 < DAT_0005c25c) {
            fVar17 = (fVar22 - ((float)((uint)fVar17 ^ uVar4) - fVar6) / (fVar16 - fVar6)) *
                     DAT_0005b2fc;
            fVar17 = (float)((uint)((DAT_0005a698 - fVar17 * fVar17) * DAT_0005a6d0 + fVar6) ^ uVar4
                            );
          }
        }
        else {
          fVar17 = (fVar22 - (fVar17 - fVar6) / (fVar16 - fVar6)) * DAT_0005b2fc;
          fVar17 = (DAT_0005a698 - fVar17 * fVar17) * DAT_0005a6d0 + fVar6;
        }
        param_9[lVar8] = fVar17;
        iVar10 = iVar10 + 1;
        lVar8 = lVar8 + 1;
      } while (iVar10 != param_10);
    }
    else if (param_10 < 1) goto LAB_0004dbbb;
  }
  else {
    if (*(int *)(this + 0x10e8) != 1) goto LAB_0004d83f;
LAB_0004dca4:
    if (0 < param_10) {
      local_248 = 0;
      do {
        local_24c = param_10 - local_248;
        if (local_24c < 0x10) {
          if (0 < local_24c) goto LAB_0004dceb;
        }
        else {
          local_24c = 0x10;
LAB_0004dceb:
          pfVar13 = param_8 + local_248;
          pfVar9 = param_9 + local_248;
          iVar10 = 0;
          do {
            EnvelopeFollower::process
                      ((EnvelopeFollower *)(this + 0x10d0),
                       (*pfVar13 + *pfVar9) * DAT_0005a698 * DAT_0005a698);
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
                   fVar22 * (DAT_0005a62c - *(float *)(this + 0x150c));
          fVar22 = DAT_0005c254;
          if ((fVar21 < DAT_0005a62c) && (fVar22 = DAT_0005c258, 0.0 < fVar21)) {
            dVar18 = (double)_log10((double)(DAT_0005a62c - fVar21));
            dVar18 = dVar18 * _DAT_0005b060;
            fVar22 = DAT_0005b318;
            if ((dVar18 <= DAT_0005b050) && (fVar22 = DAT_0005b31c, DAT_0005b068 <= dVar18)) {
              fVar22 = (float)(dVar18 * _DAT_0005b070 + _DAT_0005b078);
            }
            fVar22 = DAT_0005c248 * fVar22;
          }
          fVar22 = (float)_logf(fVar22);
          fVar21 = (float)_logf(DAT_0005a6bc);
          fVar21 = fVar22 * (DAT_0005b4d8 / fVar21) + _DAT_0005a6c0;
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
    if (iVar10 != 1) goto LAB_0004db0a;
LAB_0004deba:
    fVar22 = DAT_0005a62c;
    if (param_10 < 1) goto LAB_0004dbbb;
    iVar10 = 0;
    lVar8 = 0;
    do {
      fVar21 = (float)((uint)param_9[lVar8] & DAT_0005b100);
      if ((float)((uint)param_9[lVar8] & DAT_0005b100) <=
          (float)((uint)param_8[lVar8] & DAT_0005b100)) {
        fVar21 = (float)((uint)param_8[lVar8] & DAT_0005b100);
      }
      fVar21 = (float)EnvelopeFollower::process((EnvelopeFollower *)(this + 0x10b8),fVar21);
      if (fVar22 < fVar21) {
        fVar21 = fVar22 / fVar21;
        fVar15 = *(float *)(this + 0x10f0);
        if (fVar21 < *(float *)(this + 0x10f0)) {
          *(float *)(this + 0x10f0) = fVar21;
          *(float *)(this + 0x10f4) = (fVar22 - fVar21) / (DAT_0005b354 * *(float *)(this + 0x10f8))
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
LAB_0004dbbb:
  *(float *)(this + 0x1510) = param_5;
  return;
}


// ADDRESS 0004f480 NAME CAFilterBiquad::makeLowPassFilter

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
  
  dVar4 = ((double)param_2 / (double)param_1) * DAT_0005b110;
  dVar2 = (double)_sin(dVar4);
  dVar3 = (double)_cos(dVar4);
  if (param_4) {
    dVar2 = dVar2 / ((double)param_3 + (double)param_3);
  }
  else {
    dVar4 = (double)_sinh(((double)param_3 * _DAT_0005b2d8 * dVar4) / dVar2);
    dVar2 = dVar2 * dVar4;
  }
  dVar4 = DAT_0005b050;
  dVar5 = DAT_0005b050 - dVar3;
  dVar6 = dVar2 + DAT_0005b050;
  fVar1 = (float)((dVar5 * DAT_0005b058) / dVar6);
  *(float *)(this + 0x30) = fVar1;
  *(float *)(this + 0x34) = (float)(dVar5 / dVar6);
  *(float *)(this + 0x38) = fVar1;
  *(float *)(this + 0x3c) = (float)((dVar3 * _DAT_0005b270) / dVar6);
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


// ADDRESS 00050530 NAME CAFilterBiquad::process

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
       ((*(ulong *)(this + 0x44) & 0x7fffffff) != 0)) || (DAT_0005b03c < *(float *)(this + 0x44)))
     || (((*(float *)(this + 0x44) < DAT_0005c260 || (DAT_0005b03c < *(float *)(this + 0x48))) ||
         (*(float *)(this + 0x48) < DAT_0005c260)))) {
    *(undefined4 *)(this + 0x44) = 0;
    *(undefined4 *)(this + 0x48) = 0;
  }
  return;
}


