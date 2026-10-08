// ADDRESS 00009e60 NAME CVST2AUPlugin::SetParameterTranslated

/* CVST2AUPlugin::SetParameterTranslated(int, float) */

void CVST2AUPlugin::SetParameterTranslated(int param_1,float param_2)

{
  undefined4 in_register_0000003c;
  
                    /* WARNING: Could not recover jumptable at 0x00009e7a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*(long *)(CONCAT44(in_register_0000003c,param_1) + 0x218) + 0x58))
            (CONCAT44(in_register_0000003c,param_1) + 0x218);
  return;
}


// ADDRESS 00009e80 NAME CVST2AUPlugin::GetParameterTranslated

/* CVST2AUPlugin::GetParameterTranslated(int) */

void CVST2AUPlugin::GetParameterTranslated(int param_1)

{
  undefined4 in_register_0000003c;
  
                    /* WARNING: Could not recover jumptable at 0x00009e9a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*(long *)(CONCAT44(in_register_0000003c,param_1) + 0x218) + 0x60))
            (CONCAT44(in_register_0000003c,param_1) + 0x218);
  return;
}


// ADDRESS 0000b0e0 NAME CVST2AUPlugin::GetParameterInfo

/* WARNING: Removing unreachable block (ram,0x0000b133) */
/* WARNING: Removing unreachable block (ram,0x0000b1c2) */
/* WARNING: Removing unreachable block (ram,0x0000b15a) */
/* WARNING: Removing unreachable block (ram,0x0000b189) */
/* WARNING: Removing unreachable block (ram,0x0000b18e) */
/* WARNING: Removing unreachable block (ram,0x0000b213) */
/* WARNING: Removing unreachable block (ram,0x0000b19d) */
/* WARNING: Removing unreachable block (ram,0x0000b1a5) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* CVST2AUPlugin::GetParameterInfo(unsigned int, unsigned int, AudioUnitParameterInfo&) */

undefined * __thiscall
CVST2AUPlugin::GetParameterInfo
          (CVST2AUPlugin *this,uint param_1,uint param_2,AudioUnitParameterInfo *param_3)

{
  byte *in_RAX;
  undefined *puVar1;
  undefined4 in_register_00000014;
  undefined unaff_BL;
  
  *in_RAX = *in_RAX << 1 | (char)*in_RAX < '\0';
  *in_RAX = *in_RAX + (char)in_RAX;
  if (param_1 == 0) {
    puVar1 = &DAT_0a40e59d;
    _DAT_0a40e59d = _DAT_0a40e59d | 0xa40e59d;
  }
  else {
    puVar1 = (undefined *)
             AUBase::GetParameterInfo
                       ((uint)this,param_1,
                        (AudioUnitParameterInfo *)
                        CONCAT62((int6)(CONCAT44(in_register_00000014,param_2) >> 0x10),
                                 CONCAT11(unaff_BL,(char)param_2)));
  }
  return puVar1;
}


// ADDRESS 0000b290 NAME CVST2AUPlugin::RestoreState

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x0000b3a7) overlaps instruction at (ram,0x0000b3a3)
    */
/* CVST2AUPlugin::RestoreState(void const*) */

undefined8 __thiscall CVST2AUPlugin::RestoreState(CVST2AUPlugin *this,void *param_1)

{
  long lVar1;
  long lVar2;
  long lVar3;
  undefined8 uVar4;
  ulong uVar5;
  undefined auVar6 [16];
  undefined local_3c [12];
  
  uVar4 = 0xffffd582;
  if (param_1 != (void *)0x0) {
    lVar1 = _CFDictionaryGetValue(param_1,&cf_version);
    uVar4 = 0xffffd59d;
    if (lVar1 != 0) {
      _CFNumberGetValue(lVar1,3,local_3c);
      lVar1 = _CFDictionaryGetValue(param_1,&cf_data);
      lVar2 = _CFGetTypeID(lVar1);
      lVar3 = _CFDataGetTypeID();
      uVar4 = 0xffffffff;
      if (lVar2 == lVar3) {
        if (lVar1 != 0) {
          lVar2 = _CFDataGetLength(lVar1);
          lVar1 = _CFDataGetBytePtr(lVar1);
          if ((((0 < lVar2) && (lVar1 != 0)) && (DAT_000a73e1 == '\0')) && (0 < lVar2 >> 2)) {
            uVar5 = 0;
            do {
              auVar6 = func_0xfffffffff3b9135b();
              (**(code **)(auVar6._0_8_ + 0x58))(*auVar6._8_8_,this + 0x218,uVar5 & 0xffffffff);
              uVar5 = uVar5 + 1;
            } while (uVar5 != lVar2 >> 2);
          }
        }
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      }
    }
  }
  return uVar4;
}


// ADDRESS 0000b7b0 NAME CVST2AUPlugin::SaveState

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Restarted to delay deadcode elimination for space: stack */
/* CVST2AUPlugin::SaveState(void const**) */

undefined8 __thiscall CVST2AUPlugin::SaveState(CVST2AUPlugin *this,void **param_1)

{
  ulong uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined8 uVar5;
  void *pvVar6;
  long lVar7;
  void *pvVar8;
  long lVar9;
  undefined *puVar10;
  ulong uVar11;
  ulong uVar12;
  uint uVar13;
  undefined local_58 [8];
  undefined4 local_50;
  undefined8 local_40;
  
  uVar5 = 0xffffd582;
  if (param_1 != (void **)0x0) {
    puVar10 = PTR_000991a8;
    pvVar6 = (void *)_CFDictionaryCreateMutable(0,0,PTR_000991a0);
    if (DAT_000a73e1 == '\0') {
      if (DAT_000a73c0 != 0) {
        uVar12 = (ulong)DAT_000a73c0;
        uVar1 = uVar12 * 4;
        pvVar8 = operator_new__(uVar1);
        uVar11 = 0;
        do {
          uVar13 = (**(code **)(*(long *)(this + 0x218) + 0x60))(this + 0x218,uVar11 & 0xffffffff);
          local_40 = CONCAT44(local_40._4_4_,uVar13);
          *(uint *)((long)pvVar8 + uVar11 * 4) =
               uVar13 >> 0x18 | (uVar13 & 0xff0000) >> 8 | (uVar13 & 0xff00) << 8 | uVar13 << 0x18;
          uVar11 = uVar11 + 1;
        } while (uVar11 != uVar12);
        lVar9 = _CFDataCreate(0,pvVar8,uVar1);
        if (pvVar8 != (void *)0x0) {
          operator_delete__(pvVar8);
        }
        if (lVar9 != 0) {
          iVar3 = (**(code **)(*(long *)(this + 0x218) + 0x70))(this + 0x218);
          lVar7 = _CFArrayGetValueAtIndex(s_pcInfo,(long)iVar3);
          uVar4 = (**(code **)(*(long *)this + 0x20))(this);
          _GetComponentInfo(*(undefined8 *)(this + 8),local_58,0,0,0);
          uVar2 = local_40._4_4_;
          uVar5 = _CFNumberCreate(0,3,&local_40);
          local_40._0_4_ = uVar4;
          _CFDictionarySetValue(pvVar6,&cf_version,uVar5);
          _CFRelease(uVar5);
          uVar5 = _CFNumberCreate(0,3,&local_40);
          local_40._4_4_ = uVar2;
          _CFDictionarySetValue(pvVar6,&cf_type,uVar5);
          _CFRelease(uVar5);
          uVar5 = _CFNumberCreate(0,3,&local_40);
          _CFDictionarySetValue(pvVar6,&cf_subtype,uVar5);
          _CFRelease(uVar5);
          local_40 = CONCAT44(uVar2,local_50);
          uVar5 = _CFNumberCreate(0,3,&local_40);
          _CFDictionarySetValue(pvVar6,&cf_manufacturer,uVar5);
          _CFRelease(uVar5);
          _CFDictionarySetValue(pvVar6,&cf_name,*(undefined8 *)(lVar7 + 8));
          _CFDictionarySetValue(pvVar6,&cf_data,lVar9);
          *param_1 = pvVar6;
          return 0;
        }
      }
    }
    else {
      local_40 = 0;
      uVar5 = (**(code **)(*(long *)(this + 0x218) + 0xa8))(this + 0x218,&local_40,1);
      if (0 < (int)uVar5) {
        if (local_40 == 0) {
          return uVar5;
        }
        puVar10[-0x77] = puVar10[-0x77] + (char)puVar10;
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      }
    }
    *param_1 = (void *)0x0;
    uVar5 = 0xffffffff;
  }
  return uVar5;
}


// ADDRESS 0002fce0 NAME CAPlugin::randomUniform

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* CAPlugin::randomUniform(float, float) */

float CAPlugin::randomUniform(float param_1,float param_2)

{
  int iVar1;
  
  iVar1 = _rand();
  return (float)iVar1 * (param_2 - param_1) * _DAT_00070760 + param_1;
}


// ADDRESS 0002fd20 NAME CAPlugin::randomGaussian

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* CAPlugin::randomGaussian(float, float, float, float) */

float CAPlugin::randomGaussian(float param_1,float param_2,float param_3,float param_4)

{
  int iVar1;
  float fVar2;
  double dVar3;
  double dVar4;
  double dVar5;
  
  do {
    iVar1 = _rand();
    dVar5 = (((double)iVar1 + (double)iVar1) - _DAT_00070778) / _DAT_00070778;
    iVar1 = _rand();
    dVar3 = (((double)iVar1 + (double)iVar1) - _DAT_00070778) / _DAT_00070778;
    dVar3 = dVar5 * dVar5 + dVar3 * dVar3;
  } while (DAT_0006fb50 < dVar3);
  dVar4 = (double)_log(dVar3);
  fVar2 = (float)((double)param_1 +
                 (double)(float)SQRT((dVar4 * _DAT_00070780) / dVar3) * dVar5 * (double)param_2);
  if (param_3 <= fVar2) {
    param_3 = fVar2;
  }
  if (param_3 <= param_4) {
    param_4 = param_3;
  }
  return param_4;
}


// ADDRESS 000300f0 NAME CAPlugin::randomInt

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* CAPlugin::randomInt(int, int) */

int __thiscall CAPlugin::randomInt(CAPlugin *this,int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = _rand();
  iVar1 = (int)((float)param_1 +
               (float)iVar1 * (((float)param_2 + DAT_0006fb38) - (float)param_1) * _DAT_00070760);
  if (iVar1 < param_1) {
    iVar1 = param_1;
  }
  if (iVar1 <= param_2) {
    param_2 = iVar1;
  }
  return param_2;
}


// ADDRESS 00030160 NAME CAPlugin::randomize

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* CAPlugin::randomize() */

void CAPlugin::randomize(void)

{
  int iVar1;
  long in_RDI;
  long lVar2;
  int iVar3;
  
  if (0 < *(int *)(in_RDI + 0x14)) {
    iVar3 = 0;
    lVar2 = 0;
    do {
      iVar1 = _rand();
      PParam::setParam(*(PParam **)(*(long *)(in_RDI + 8) + lVar2),
                       (float)iVar1 * _DAT_00070760 + 0.0);
      iVar3 = iVar3 + 1;
      lVar2 = lVar2 + 8;
    } while (iVar3 < *(int *)(in_RDI + 0x14));
  }
  return;
}


// ADDRESS 000301c0 NAME CAPlugin::randomBinary

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* CAPlugin::randomBinary(float) */

uint CAPlugin::randomBinary(float param_1)

{
  int iVar1;
  
  iVar1 = _rand();
  return ~-(uint)(param_1 <= (float)iVar1 * _DAT_00070760 + 0.0) & DAT_0006fb38;
}


// ADDRESS 00030410 NAME CAPluginVST::process

/* CAPluginVST::process(float**, float**, int) */

void __thiscall CAPluginVST::process(CAPluginVST *this,float **param_1,float **param_2,int param_3)

{
  (**(code **)(*(long *)this + 0x4c8))(this,*param_1,param_1[1],*param_2,param_2[1],param_3,0);
  return;
}


// ADDRESS 00030440 NAME CAPluginVST::processReplacing

/* CAPluginVST::processReplacing(float**, float**, int) */

void __thiscall
CAPluginVST::processReplacing(CAPluginVST *this,float **param_1,float **param_2,int param_3)

{
  (**(code **)(*(long *)this + 0x4c8))(this,*param_1,param_1[1],*param_2,param_2[1],param_3,1);
  return;
}


// ADDRESS 000310b0 NAME CAPluginVST::process

/* CAPluginVST::process(float*, float*, float*, float*, int, bool) */

void __thiscall
CAPluginVST::process
          (CAPluginVST *this,float *param_1,float *param_2,float *param_3,float *param_4,int param_5
          ,bool param_6)

{
  float fVar1;
  float fVar2;
  char cVar3;
  int iVar4;
  long lVar5;
  
  if ((((DAT_000707a8 <= (float)((uint)*param_1 & DAT_00070610)) ||
       (DAT_000707a8 <= (float)((uint)*param_2 & DAT_00070610))) ||
      (DAT_000707a8 <= (float)((uint)param_1[(long)param_5 + -1] & DAT_00070610))) ||
     (DAT_000707a8 <= (float)((uint)param_2[(long)param_5 + -1] & DAT_00070610))) {
    *(undefined4 *)(this + 0x730) = 0;
  }
  else {
    *(uint *)(this + 0x730) = param_5 + *(int *)(this + 0x730) & 0xfffffff;
  }
  fVar1 = *(float *)(this + 0x18);
  fVar2 = *(float *)(*(long *)(this + 0x110) + 0x2ca4);
  cVar3 = CAPlugin::checkLegitCopy();
  lVar5 = *(long *)(this + 0x110);
  if (((AEffGUIEditor::~AEffGUIEditor[lVar5 + 1] == (code)0x0) &&
      (*(uint *)(this + 0x730) <= (uint)(int)(fVar1 * fVar2))) && (cVar3 != '\0')) {
    getCurrentBPM(this,false);
    *(undefined *)(*(long *)(this + 0x110) + 0x1c28) = 1;
    (**(code **)**(undefined8 **)(this + 0x110))
              (*(undefined8 **)(this + 0x110),param_1,param_2,param_3,param_4,param_5,param_6);
    *(undefined *)(*(long *)(this + 0x110) + 0x1c28) = 0;
  }
  else {
    *(undefined4 *)(&DAT_00002c94 + lVar5) = 0;
    *(undefined4 *)(&DAT_00002c98 + lVar5) = 0;
    if (param_6) {
      iVar4 = 0;
      lVar5 = 0;
      if (0 < param_5) {
        do {
          param_3[lVar5] = param_1[lVar5];
          param_4[lVar5] = param_2[lVar5];
          iVar4 = iVar4 + 1;
          lVar5 = lVar5 + 1;
        } while (iVar4 != param_5);
      }
    }
    else {
      iVar4 = 0;
      lVar5 = 0;
      if (0 < param_5) {
        do {
          param_3[lVar5] = param_3[lVar5] + param_1[lVar5];
          param_4[lVar5] = param_4[lVar5] + param_2[lVar5];
          iVar4 = iVar4 + 1;
          lVar5 = lVar5 + 1;
        } while (iVar4 != param_5);
      }
    }
    if (cVar3 == '\0') {
      return;
    }
    (**(code **)(**(long **)(this + 0x110) + 0x90))();
  }
  updateChangedParams();
  return;
}


// ADDRESS 00031cf0 NAME CAPluginVST::processEvents

/* CAPluginVST::processEvents(VstEvents*) */

undefined8 __thiscall CAPluginVST::processEvents(CAPluginVST *this,VstEvents *param_1)

{
  byte bVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  byte bVar5;
  long lVar6;
  
  (**(code **)(**(long **)(this + 0x110) + 0x90))();
  updateChangedParams();
  *(undefined *)(*(long *)(this + 0x110) + 0x2a85) = 0;
  iVar4 = *(int *)param_1;
  if (0 < iVar4) {
    lVar6 = 0;
    do {
      while (piVar2 = *(int **)(param_1 + lVar6 * 8 + 0x10), *piVar2 == 1) {
        if ((*(byte *)(piVar2 + 6) & 0xf0) == 0xb0) {
          if (*(char *)((long)piVar2 + 0x19) == '\0') {
            uVar3 = (uint)*(byte *)((long)piVar2 + 0x1a);
            if (*(int *)(this + 0x73c) <= (int)(uint)*(byte *)((long)piVar2 + 0x1a)) {
              uVar3 = *(int *)(this + 0x73c) - 1;
            }
            *(uint *)(this + 0xd68) = uVar3;
          }
        }
        else if ((*(byte *)(piVar2 + 6) & 0xf0) == 0xc0) {
          bVar1 = *(byte *)((long)piVar2 + 0x19);
          if (*(int *)(this + 0xd68) != -1) {
            loadFactoryBank((int)this);
          }
          bVar5 = 0x13;
          if (bVar1 < 0x14) {
            bVar5 = bVar1;
          }
          (**(code **)(*(long *)this + 0x78))(this,bVar5);
          *(undefined4 *)(this + 0xd68) = 0xffffffff;
        }
        CAPlugin::addEvent(*(CAPlugin **)(this + 0x110),(uchar *)(piVar2 + 6),3,piVar2[2]);
        iVar4 = *(int *)param_1;
        lVar6 = lVar6 + 1;
        if (iVar4 <= lVar6) goto LAB_00031d95;
      }
      lVar6 = lVar6 + 1;
    } while (lVar6 < iVar4);
  }
LAB_00031d95:
  *(undefined *)(*(long *)(this + 0x110) + 0x2a85) = 1;
  return 1;
}


