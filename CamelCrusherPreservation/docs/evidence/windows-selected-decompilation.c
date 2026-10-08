// ADDRESS 1800010f0 FUN_1800010f0

void FUN_1800010f0(longlong *param_1,void *param_2,void *param_3,longlong param_4,longlong param_5,
                  int param_6,char param_7)

{
  float *pfVar1;
  char cVar2;
  byte bVar3;
  byte bVar4;
  int iVar5;
  float *_Dst;
  void *_Dst_00;
  bool bVar6;
  bool bVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float *pfVar15;
  float *pfVar16;
  uint uVar17;
  undefined4 *puVar18;
  undefined4 *puVar19;
  int iVar20;
  longlong lVar21;
  float *pfVar22;
  longlong lVar23;
  longlong lVar24;
  float fVar25;
  undefined8 uVar26;
  undefined8 uVar27;
  undefined8 uVar28;
  undefined8 uVar29;
  float fVar30;
  float fVar31;
  float fVar32;
  int local_118;
  void *local_110;
  longlong local_108;
  void *local_100;
  
  _Dst = (float *)param_1[0x883];
  _Dst_00 = (void *)param_1[0x882];
  param_1[0x386] =
       (longlong)
       ((double)((float)param_6 * *(float *)((longlong)param_1 + 0x1c2c)) /
        ((double)*(float *)(param_1 + 0x552) * DAT_1800747d0) + (double)param_1[0x386]);
  uVar26 = FUN_18000cb90(*(longlong *)param_1[1],param_6);
  fVar8 = DAT_1800747ac;
  if ((float)uVar26 <= DAT_1800747ac) {
    bVar6 = false;
LAB_1800011c0:
    bVar7 = false;
    if (bVar6) goto LAB_1800011cd;
  }
  else {
    bVar6 = true;
    uVar26 = FUN_18000cb90(*(longlong *)(param_1[1] + 8),param_6);
    if ((float)uVar26 <= 0.0) goto LAB_1800011c0;
    bVar7 = true;
LAB_1800011cd:
    uVar26 = FUN_18000cb90(*(longlong *)(param_1[1] + 0x10),param_6);
    if (0.0 < (float)uVar26) {
      bVar6 = true;
      goto LAB_1800011f4;
    }
  }
  bVar6 = false;
LAB_1800011f4:
  uVar26 = FUN_18000cb90(*(longlong *)(param_1[1] + 0x18),param_6);
  uVar27 = FUN_18000cb90(*(longlong *)(param_1[1] + 0x30),param_6);
  fVar14 = DAT_1800747cc;
  fVar13 = DAT_1800747c8;
  fVar12 = DAT_1800747c4;
  fVar11 = DAT_1800747c0;
  fVar10 = DAT_1800747bc;
  fVar9 = DAT_1800747b8;
  iVar20 = 0x40;
  local_118 = 0;
  local_110 = param_2;
  local_108 = param_4;
  local_100 = param_3;
  if (0 < param_6) {
    do {
      iVar5 = *(int *)((longlong)param_1 + 0x1c24);
      lVar23 = (longlong)iVar5;
      if ((iVar5 < *(int *)(param_1 + 900)) &&
         (*(int *)((longlong)param_1 + lVar23 * 4 + 0x20) <= iVar20 + local_118)) {
        cVar2 = *(char *)((longlong)param_1 + lVar23 + 0x1020);
        bVar3 = *(byte *)((longlong)param_1 + lVar23 + 0x1420);
        bVar4 = *(byte *)((longlong)param_1 + lVar23 + 0x1820);
        *(int *)((longlong)param_1 + 0x1c24) = iVar5 + 1;
        if ((cVar2 == -0x50) && (iVar20 = 0, 0 < *(int *)((longlong)param_1 + 0x14))) {
          lVar23 = 0x8000;
          do {
            if (*(int *)(param_1[3] + 0x8800) < iVar20) {
              uVar17 = 0;
            }
            else {
              uVar17 = *(uint *)(lVar23 + param_1[3]);
            }
            if (bVar3 == uVar17) {
              FUN_1800053e0(param_1,iVar20,(float)(uint)bVar4 / fVar9);
              break;
            }
            iVar20 = iVar20 + 1;
            lVar23 = lVar23 + 4;
          } while (iVar20 < *(int *)((longlong)param_1 + 0x14));
        }
      }
      iVar20 = 0x40;
      if (param_6 - local_118 < 0x40) {
        iVar20 = param_6 - local_118;
      }
      lVar23 = (longlong)iVar20;
      fVar32 = fVar12 / (float)iVar20;
      memcpy(_Dst_00,local_110,lVar23 * 4);
      memcpy(_Dst,local_100,lVar23 * 4);
      if (bVar7) {
        uVar28 = FUN_18000cb90(*(longlong *)(param_1[1] + 8),iVar20);
        FUN_18001c680((longlong)(param_1 + 0x616),(longlong)_Dst_00,(longlong)_Dst,iVar20,
                      (int)uVar28);
      }
      if (fVar8 < (float)uVar26) {
        uVar28 = FUN_18000cb90(*(longlong *)(param_1[1] + 0x20),iVar20);
        uVar29 = FUN_18000cb90(*(longlong *)(param_1[1] + 0x28),iVar20);
        FUN_180020a30((int *)(param_1 + 0x618),0,(float)uVar28,(float)uVar29,0.0,fVar12,0.0,0.0,
                      _Dst_00,_Dst,iVar20);
      }
      if (bVar6) {
        uVar28 = FUN_18000cb90(*(longlong *)(param_1[1] + 0x10),iVar20);
        FUN_18001c6c0((longlong)(param_1 + 0x616),(longlong)_Dst_00,(longlong)_Dst,iVar20,
                      (int)uVar28);
      }
      if (fVar8 < (float)uVar27) {
        uVar28 = FUN_18000cb90(*(longlong *)(param_1[1] + 0x38),iVar20);
        fVar25 = (float)uVar28;
        if (DAT_180074790 < (float)uVar28) {
          fVar25 = DAT_180074790;
        }
        FUN_18001be70((float *)(param_1 + 0x87c),(longlong)_Dst_00,_Dst,iVar20,fVar25,DAT_1800747b4)
        ;
      }
      uVar28 = FUN_18000cb90(*(longlong *)(param_1[1] + 0x50),iVar20);
      uVar29 = FUN_18000cb90(*(longlong *)(param_1[1] + 0x58),iVar20);
      fVar31 = ((float)uVar28 - *(float *)(param_1 + 0x885)) * fVar32;
      fVar25 = FUN_18004db30((float)uVar29,DAT_1800747b0);
      lVar24 = 0;
      fVar32 = (fVar25 - *(float *)((longlong)param_1 + 0x4424)) * fVar32;
      if (3 < lVar23) {
        pfVar16 = _Dst + 2;
        pfVar15 = (float *)((longlong)local_100 + 0xc);
        pfVar22 = (float *)((longlong)_Dst_00 + 4);
        do {
          pfVar1 = (float *)(((longlong)local_100 - (longlong)_Dst) + (longlong)pfVar16);
          pfVar22[-1] = ((fVar12 - *(float *)(param_1 + 0x885)) *
                         *(float *)((longlong)local_110 + lVar24 * 4) +
                        *(float *)(param_1 + 0x885) * pfVar22[-1]) *
                        *(float *)((longlong)param_1 + 0x4424);
          pfVar16[-2] = ((fVar12 - *(float *)(param_1 + 0x885)) * pfVar15[-3] +
                        *(float *)(param_1 + 0x885) * pfVar16[-2]) *
                        *(float *)((longlong)param_1 + 0x4424);
          fVar30 = fVar32 + *(float *)((longlong)param_1 + 0x4424);
          fVar25 = fVar31 + *(float *)(param_1 + 0x885);
          *(float *)((longlong)param_1 + 0x4424) = fVar30;
          *(float *)(param_1 + 0x885) = fVar25;
          *pfVar22 = ((fVar12 - fVar25) *
                      *(float *)(((longlong)local_110 - (longlong)_Dst_00) + (longlong)pfVar22) +
                     fVar25 * *pfVar22) * fVar30;
          *(float *)(((longlong)_Dst - (longlong)_Dst_00) + (longlong)pfVar22) =
               ((fVar12 - *(float *)(param_1 + 0x885)) *
                *(float *)(((longlong)local_100 - (longlong)_Dst_00) + (longlong)pfVar22) +
               *(float *)(param_1 + 0x885) *
               *(float *)(((longlong)_Dst - (longlong)_Dst_00) + (longlong)pfVar22)) *
               *(float *)((longlong)param_1 + 0x4424);
          fVar30 = fVar32 + *(float *)((longlong)param_1 + 0x4424);
          fVar25 = fVar31 + *(float *)(param_1 + 0x885);
          *(float *)((longlong)param_1 + 0x4424) = fVar30;
          *(float *)(param_1 + 0x885) = fVar25;
          pfVar22[1] = ((fVar12 - fVar25) *
                        *(float *)((longlong)pfVar1 + ((longlong)local_110 - (longlong)local_100)) +
                       fVar25 * pfVar22[1]) * fVar30;
          *pfVar16 = ((fVar12 - *(float *)(param_1 + 0x885)) * *pfVar1 +
                     *(float *)(param_1 + 0x885) * *pfVar16) *
                     *(float *)((longlong)param_1 + 0x4424);
          fVar30 = fVar32 + *(float *)((longlong)param_1 + 0x4424);
          fVar25 = fVar31 + *(float *)(param_1 + 0x885);
          *(float *)((longlong)param_1 + 0x4424) = fVar30;
          *(float *)(param_1 + 0x885) = fVar25;
          pfVar22[2] = ((fVar12 - fVar25) *
                        *(float *)(((longlong)local_110 - (longlong)local_100) + (longlong)pfVar15)
                       + fVar25 * pfVar22[2]) * fVar30;
          pfVar16[1] = ((fVar12 - *(float *)(param_1 + 0x885)) * *pfVar15 +
                       *(float *)(param_1 + 0x885) * pfVar16[1]) *
                       *(float *)((longlong)param_1 + 0x4424);
          lVar24 = lVar24 + 4;
          pfVar22 = pfVar22 + 4;
          pfVar16 = pfVar16 + 4;
          pfVar15 = pfVar15 + 4;
          *(float *)((longlong)param_1 + 0x4424) = fVar32 + *(float *)((longlong)param_1 + 0x4424);
          *(float *)(param_1 + 0x885) = fVar31 + *(float *)(param_1 + 0x885);
        } while (lVar24 < lVar23 + -3);
      }
      if (lVar24 < lVar23) {
        lVar21 = lVar23 - lVar24;
        pfVar16 = (float *)((longlong)_Dst_00 + lVar24 * 4);
        do {
          lVar21 = lVar21 + -1;
          *pfVar16 = ((fVar12 - *(float *)(param_1 + 0x885)) *
                      *(float *)((longlong)pfVar16 + ((longlong)local_110 - (longlong)_Dst_00)) +
                     *(float *)(param_1 + 0x885) * *pfVar16) *
                     *(float *)((longlong)param_1 + 0x4424);
          *(float *)((longlong)pfVar16 + ((longlong)_Dst - (longlong)_Dst_00)) =
               ((fVar12 - *(float *)(param_1 + 0x885)) *
                *(float *)((longlong)pfVar16 + ((longlong)local_100 - (longlong)_Dst_00)) +
               *(float *)(param_1 + 0x885) *
               *(float *)((longlong)pfVar16 + ((longlong)_Dst - (longlong)_Dst_00))) *
               *(float *)((longlong)param_1 + 0x4424);
          *(float *)((longlong)param_1 + 0x4424) = fVar32 + *(float *)((longlong)param_1 + 0x4424);
          *(float *)(param_1 + 0x885) = fVar31 + *(float *)(param_1 + 0x885);
          pfVar16 = pfVar16 + 1;
        } while (lVar21 != 0);
      }
      lVar24 = 0;
      if (3 < lVar23) {
        pfVar16 = (float *)((longlong)_Dst_00 + 0xc);
        pfVar15 = _Dst + 1;
        lVar21 = (lVar23 - 4U >> 2) + 1;
        lVar24 = lVar21 * 4;
        do {
          fVar32 = pfVar16[-3];
          fVar25 = pfVar15[-1];
          fVar31 = fVar13;
          if ((fVar32 <= fVar13) && (fVar31 = fVar32, fVar32 < fVar14)) {
            fVar31 = fVar14;
          }
          fVar32 = fVar13;
          if ((fVar25 <= fVar13) && (fVar32 = fVar25, fVar25 < fVar14)) {
            fVar32 = fVar14;
          }
          pfVar16[-3] = fVar31;
          pfVar15[-1] = fVar32;
          fVar32 = *(float *)(((longlong)_Dst_00 - (longlong)_Dst) + (longlong)pfVar15);
          fVar25 = *pfVar15;
          fVar31 = fVar13;
          if ((fVar32 <= fVar13) && (fVar31 = fVar32, fVar32 < fVar14)) {
            fVar31 = fVar14;
          }
          fVar32 = fVar13;
          if ((fVar25 <= fVar13) && (fVar32 = fVar25, fVar25 < fVar14)) {
            fVar32 = fVar14;
          }
          *(float *)(((longlong)_Dst_00 - (longlong)_Dst) + (longlong)pfVar15) = fVar31;
          *pfVar15 = fVar32;
          fVar32 = pfVar16[-1];
          fVar25 = pfVar15[1];
          fVar31 = fVar13;
          if ((fVar32 <= fVar13) && (fVar31 = fVar32, fVar32 < fVar14)) {
            fVar31 = fVar14;
          }
          fVar32 = fVar13;
          if ((fVar25 <= fVar13) && (fVar32 = fVar25, fVar25 < fVar14)) {
            fVar32 = fVar14;
          }
          pfVar16[-1] = fVar31;
          pfVar15[1] = fVar32;
          fVar32 = *pfVar16;
          fVar25 = pfVar15[2];
          fVar31 = fVar13;
          if ((fVar32 <= fVar13) && (fVar31 = fVar32, fVar32 < fVar14)) {
            fVar31 = fVar14;
          }
          fVar32 = fVar13;
          if ((fVar25 <= fVar13) && (fVar32 = fVar25, fVar25 < fVar14)) {
            fVar32 = fVar14;
          }
          *pfVar16 = fVar31;
          pfVar15[2] = fVar32;
          pfVar15 = pfVar15 + 4;
          pfVar16 = pfVar16 + 4;
          lVar21 = lVar21 + -1;
        } while (lVar21 != 0);
      }
      if (lVar24 < lVar23) {
        pfVar16 = _Dst + lVar24;
        lVar24 = lVar23 - lVar24;
        do {
          fVar32 = *(float *)((longlong)pfVar16 + ((longlong)_Dst_00 - (longlong)_Dst));
          fVar25 = *pfVar16;
          fVar31 = fVar13;
          if ((fVar32 <= fVar13) && (fVar31 = fVar32, fVar32 < fVar14)) {
            fVar31 = fVar14;
          }
          fVar32 = fVar13;
          if ((fVar25 <= fVar13) && (fVar32 = fVar25, fVar25 < fVar14)) {
            fVar32 = fVar14;
          }
          *(float *)((longlong)pfVar16 + ((longlong)_Dst_00 - (longlong)_Dst)) = fVar31;
          *pfVar16 = fVar32;
          pfVar16 = pfVar16 + 1;
          lVar24 = lVar24 + -1;
        } while (lVar24 != 0);
      }
      if (param_7 == '\0') {
        lVar24 = 0;
        if (3 < lVar23) {
          pfVar16 = (float *)(local_108 + 4);
          pfVar15 = (float *)(param_5 + 8);
          pfVar22 = _Dst + 3;
          do {
            lVar21 = lVar24 * 4;
            pfVar1 = (float *)((longlong)pfVar15 + ((longlong)_Dst - param_5));
            lVar24 = lVar24 + 4;
            pfVar16[-1] = *(float *)((longlong)_Dst_00 + lVar21) + pfVar16[-1];
            pfVar15[-2] = pfVar22[-3] + pfVar15[-2];
            *pfVar16 = *(float *)((longlong)pfVar16 + ((longlong)_Dst_00 - local_108)) + *pfVar16;
            *(float *)((longlong)pfVar16 + (param_5 - local_108)) =
                 *(float *)((longlong)pfVar16 + ((longlong)_Dst - local_108)) +
                 *(float *)((longlong)pfVar16 + (param_5 - local_108));
            pfVar16[1] = *(float *)(((longlong)_Dst_00 - (longlong)_Dst) + (longlong)pfVar1) +
                         pfVar16[1];
            *pfVar15 = *pfVar15 + *pfVar1;
            pfVar16[2] = *(float *)((longlong)pfVar22 + ((longlong)_Dst_00 - (longlong)_Dst)) +
                         pfVar16[2];
            pfVar15[1] = *pfVar22 + pfVar15[1];
            pfVar16 = pfVar16 + 4;
            pfVar15 = pfVar15 + 4;
            pfVar22 = pfVar22 + 4;
          } while (lVar24 < lVar23 + -3);
        }
        if (lVar24 < lVar23) {
          lVar21 = lVar23 - lVar24;
          pfVar16 = (float *)(local_108 + lVar24 * 4);
          do {
            lVar21 = lVar21 + -1;
            *pfVar16 = *(float *)((longlong)pfVar16 + ((longlong)_Dst_00 - local_108)) + *pfVar16;
            *(float *)((longlong)pfVar16 + (param_5 - local_108)) =
                 *(float *)((longlong)pfVar16 + ((longlong)_Dst - local_108)) +
                 *(float *)((longlong)pfVar16 + (param_5 - local_108));
            pfVar16 = pfVar16 + 1;
          } while (lVar21 != 0);
        }
      }
      else {
        lVar24 = 0;
        if (3 < lVar23) {
          puVar19 = (undefined4 *)(local_108 + 4);
          pfVar16 = _Dst + 2;
          pfVar15 = (float *)(param_5 + 0xc);
          do {
            lVar21 = lVar24 * 4;
            lVar24 = lVar24 + 4;
            puVar19[-1] = *(undefined4 *)((longlong)_Dst_00 + lVar21);
            puVar18 = puVar19 + 4;
            pfVar15[-3] = pfVar16[-2];
            *puVar19 = *(undefined4 *)((longlong)_Dst_00 + (-0x10 - local_108) + (longlong)puVar18);
            *(undefined4 *)((param_5 - local_108) + -0x10 + (longlong)puVar18) =
                 *(undefined4 *)((longlong)_Dst + (-0x10 - local_108) + (longlong)puVar18);
            puVar19[1] = *(undefined4 *)
                          ((longlong)_Dst_00 + (-0x10 - (longlong)_Dst) + (longlong)(pfVar16 + 4));
            *(float *)((longlong)pfVar16 + (param_5 - (longlong)_Dst)) = *pfVar16;
            puVar19[2] = *(undefined4 *)
                          ((longlong)_Dst_00 + (-0x10 - param_5) + (longlong)(pfVar15 + 4));
            *pfVar15 = pfVar16[1];
            puVar19 = puVar18;
            pfVar16 = pfVar16 + 4;
            pfVar15 = pfVar15 + 4;
          } while (lVar24 < lVar23 + -3);
        }
        if (lVar24 < lVar23) {
          lVar21 = lVar23 - lVar24;
          puVar19 = (undefined4 *)(local_108 + lVar24 * 4);
          do {
            lVar21 = lVar21 + -1;
            *puVar19 = *(undefined4 *)((longlong)puVar19 + ((longlong)_Dst_00 - local_108));
            *(undefined4 *)((longlong)puVar19 + (param_5 - local_108)) =
                 *(undefined4 *)((longlong)puVar19 + ((longlong)_Dst - local_108));
            puVar19 = puVar19 + 1;
          } while (lVar21 != 0);
        }
      }
      fVar32 = (fVar10 / *(float *)(param_1 + 0x552)) * (float)iVar20;
      *(float *)((longlong)param_1 + 0x2c94) = *(float *)((longlong)param_1 + 0x2c94) - fVar32;
      *(float *)(param_1 + 0x593) = *(float *)(param_1 + 0x593) - fVar32;
      if (0 < lVar23) {
        lVar24 = (lVar23 - 1U >> 3) + 1;
        pfVar16 = _Dst;
        do {
          fVar32 = *(float *)((longlong)pfVar16 + ((longlong)_Dst_00 - (longlong)_Dst));
          if (*(float *)((longlong)param_1 + 0x2c94) <= fVar32 &&
              fVar32 != *(float *)((longlong)param_1 + 0x2c94)) {
            *(float *)((longlong)param_1 + 0x2c94) = fVar32;
          }
          fVar32 = *(float *)((longlong)pfVar16 + ((longlong)_Dst_00 - (longlong)_Dst));
          if (fVar32 < fVar11 - *(float *)((longlong)param_1 + 0x2c94)) {
            *(float *)((longlong)param_1 + 0x2c94) = fVar11 - fVar32;
          }
          fVar32 = *pfVar16;
          if (*(float *)(param_1 + 0x593) <= fVar32 && fVar32 != *(float *)(param_1 + 0x593)) {
            *(float *)(param_1 + 0x593) = fVar32;
          }
          if (*pfVar16 < fVar11 - *(float *)(param_1 + 0x593)) {
            *(float *)(param_1 + 0x593) = fVar11 - *pfVar16;
          }
          pfVar16 = pfVar16 + 8;
          lVar24 = lVar24 + -1;
        } while (lVar24 != 0);
      }
      if (*(float *)((longlong)param_1 + 0x2c94) <= 0.0 &&
          *(float *)((longlong)param_1 + 0x2c94) != 0.0) {
        *(undefined4 *)((longlong)param_1 + 0x2c94) = 0;
      }
      if (*(float *)(param_1 + 0x593) <= 0.0 && *(float *)(param_1 + 0x593) != 0.0) {
        *(undefined4 *)(param_1 + 0x593) = 0;
      }
      lVar23 = lVar23 * 4;
      local_110 = (void *)((longlong)local_110 + lVar23);
      local_100 = (void *)((longlong)local_100 + lVar23);
      local_108 = local_108 + lVar23;
      param_5 = param_5 + lVar23;
      local_118 = local_118 + iVar20;
    } while (local_118 < param_6);
  }
  *(undefined4 *)(param_1 + 900) = 0;
  *(undefined4 *)((longlong)param_1 + 0x1c24) = 0;
  return;
}



// ADDRESS 1800024f0 FUN_1800024f0

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1800024f0(undefined8 *param_1,char *param_2,char *param_3)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  void *pvVar5;
  char *pcVar6;
  undefined4 *puVar7;
  longlong lVar8;
  char **ppcVar9;
  char *pcVar10;
  ulonglong uVar11;
  char **ppcVar12;
  undefined auStackY_1aa8 [32];
  char *local_1a48 [512];
  undefined4 local_a48 [512];
  uint local_248 [128];
  ulonglong local_48;
  
  local_48 = DAT_18009d6e0 ^ (ulonglong)auStackY_1aa8;
  FUN_180005800(param_1,0x11,0x1a,param_2);
  *param_1 = CamelCrusher::vftable;
  FUN_18001c0c0((undefined4 *)(param_1 + 0x616));
  FUN_18001fed0((undefined4 *)(param_1 + 0x618));
  FUN_18001bdc0((undefined4 *)(param_1 + 0x87c));
  pcVar10 = param_3;
  do {
    cVar1 = *pcVar10;
    pcVar10[(longlong)param_1 + (0x2cab - (longlong)param_3)] = cVar1;
    pcVar10 = pcVar10 + 1;
  } while (cVar1 != '\0');
  lVar8 = (longlong)(char *)((longlong)param_1 + 0x2eab) - (longlong)param_3;
  do {
    cVar1 = *param_3;
    param_3[lVar8] = cVar1;
    param_3 = param_3 + 1;
  } while (cVar1 != '\0');
  lVar8 = -1;
  pcVar10 = (char *)((longlong)param_1 + 0x2eab);
  do {
    pcVar6 = pcVar10;
    if (lVar8 == 0) break;
    lVar8 = lVar8 + -1;
    pcVar6 = pcVar10 + 1;
    cVar1 = *pcVar10;
    pcVar10 = pcVar6;
  } while (cVar1 != '\0');
  *(undefined4 *)(pcVar6 + -1) = _DAT_180074ad8;
  pcVar6[3] = DAT_180074adc;
  puVar3 = (undefined4 *)operator_new(0x22d8);
  uVar2 = DAT_1800747c4;
  puVar7 = (undefined4 *)0x0;
  puVar4 = puVar7;
  if (puVar3 != (undefined4 *)0x0) {
    puVar4 = FUN_18000c970(puVar3,0,0,"DistOn","DistOn","",0,DAT_1800747c4);
  }
  *(undefined4 **)param_1[1] = puVar4;
  puVar3 = (undefined4 *)operator_new(0x22d8);
  puVar4 = puVar7;
  if (puVar3 != (undefined4 *)0x0) {
    puVar4 = FUN_18000c970(puVar3,1,1,"DistMech","DistMech","%",0,uVar2);
  }
  *(undefined4 **)(param_1[1] + 8) = puVar4;
  puVar3 = (undefined4 *)operator_new(0x22d8);
  puVar4 = puVar7;
  if (puVar3 != (undefined4 *)0x0) {
    puVar4 = FUN_18000c970(puVar3,1,1,"DistTube","DistTube","%",0,uVar2);
  }
  *(undefined4 **)(param_1[1] + 0x10) = puVar4;
  puVar3 = (undefined4 *)operator_new(0x22d8);
  puVar4 = puVar7;
  if (puVar3 != (undefined4 *)0x0) {
    puVar4 = FUN_18000c970(puVar3,0,0,"MmFilterOn","MmFilterOn","",0,uVar2);
  }
  *(undefined4 **)(param_1[1] + 0x18) = puVar4;
  puVar3 = (undefined4 *)operator_new(0x22d8);
  puVar4 = puVar7;
  if (puVar3 != (undefined4 *)0x0) {
    puVar4 = FUN_18000c970(puVar3,6,1,"MmFilterCutoff","MmFilterCutoff","Hz",0,uVar2);
  }
  *(undefined4 **)(param_1[1] + 0x20) = puVar4;
  puVar3 = (undefined4 *)operator_new(0x22d8);
  puVar4 = puVar7;
  if (puVar3 != (undefined4 *)0x0) {
    puVar4 = FUN_18000c970(puVar3,1,1,"MmFilterRes","MmFilterRes","%",0,uVar2);
  }
  *(undefined4 **)(param_1[1] + 0x28) = puVar4;
  puVar3 = (undefined4 *)operator_new(0x22d8);
  puVar4 = puVar7;
  if (puVar3 != (undefined4 *)0x0) {
    puVar4 = FUN_18000c970(puVar3,0,0,"CompressOn","CompressOn","",0,uVar2);
  }
  *(undefined4 **)(param_1[1] + 0x30) = puVar4;
  puVar3 = (undefined4 *)operator_new(0x22d8);
  puVar4 = puVar7;
  if (puVar3 != (undefined4 *)0x0) {
    puVar4 = FUN_18000c970(puVar3,7,1,"CompressAmount","CompressAmnt","dB",0,DAT_180074790);
  }
  *(undefined4 **)(param_1[1] + 0x38) = puVar4;
  puVar3 = (undefined4 *)operator_new(0x22d8);
  puVar4 = puVar7;
  if (puVar3 != (undefined4 *)0x0) {
    puVar4 = FUN_18000c970(puVar3,0,0,"CompressMode","CompressMode","",0,uVar2);
  }
  *(undefined4 **)(param_1[1] + 0x40) = puVar4;
  puVar3 = (undefined4 *)operator_new(0x22d8);
  puVar4 = puVar7;
  if (puVar3 != (undefined4 *)0x0) {
    puVar4 = FUN_18000c970(puVar3,0,0,"MasterOn","MasterOn","",0,uVar2);
  }
  *(undefined4 **)(param_1[1] + 0x48) = puVar4;
  puVar3 = (undefined4 *)operator_new(0x22d8);
  puVar4 = puVar7;
  if (puVar3 != (undefined4 *)0x0) {
    puVar4 = FUN_18000c970(puVar3,1,1,"MasterMix","MasterMix","%",0,uVar2);
  }
  *(undefined4 **)(param_1[1] + 0x50) = puVar4;
  puVar3 = (undefined4 *)operator_new(0x22d8);
  puVar4 = puVar7;
  if (puVar3 != (undefined4 *)0x0) {
    puVar4 = FUN_18000c970(puVar3,8,1,"MasterVolume","MasterVol","dB",0,uVar2);
  }
  *(undefined4 **)(param_1[1] + 0x58) = puVar4;
  puVar3 = (undefined4 *)operator_new(0x22d8);
  puVar4 = puVar7;
  if (puVar3 != (undefined4 *)0x0) {
    puVar4 = FUN_18000c970(puVar3,0,0,"Unused1","Unused1","",0,uVar2);
  }
  *(undefined4 **)(param_1[1] + 0x60) = puVar4;
  puVar3 = (undefined4 *)operator_new(0x22d8);
  puVar4 = puVar7;
  if (puVar3 != (undefined4 *)0x0) {
    puVar4 = FUN_18000c970(puVar3,0,0,"Unused2","Unused2","",0,uVar2);
  }
  *(undefined4 **)(param_1[1] + 0x68) = puVar4;
  puVar3 = (undefined4 *)operator_new(0x22d8);
  puVar4 = puVar7;
  if (puVar3 != (undefined4 *)0x0) {
    puVar4 = FUN_18000c970(puVar3,0,0,"Unused3","Unused3","",0,uVar2);
  }
  *(undefined4 **)(param_1[1] + 0x70) = puVar4;
  puVar3 = (undefined4 *)operator_new(0x22d8);
  puVar4 = puVar7;
  if (puVar3 != (undefined4 *)0x0) {
    puVar4 = FUN_18000c970(puVar3,0,0,"Unused4","Unused4","",0,uVar2);
  }
  *(undefined4 **)(param_1[1] + 0x78) = puVar4;
  puVar3 = (undefined4 *)operator_new(0x22d8);
  puVar4 = puVar7;
  if (puVar3 != (undefined4 *)0x0) {
    puVar4 = FUN_18000c970(puVar3,0,0,"Unused5","Unused5","",0,uVar2);
  }
  *(undefined4 **)(param_1[1] + 0x80) = puVar4;
  puVar3 = (undefined4 *)operator_new(0x22d8);
  puVar4 = puVar7;
  if (puVar3 != (undefined4 *)0x0) {
    puVar4 = FUN_18000c970(puVar3,0,0,"Unused","",(char *)0x0,0,uVar2);
  }
  *(undefined4 **)(param_1[1] + 0x88) = puVar4;
  puVar3 = (undefined4 *)operator_new(0x22d8);
  puVar4 = puVar7;
  if (puVar3 != (undefined4 *)0x0) {
    puVar4 = FUN_18000c970(puVar3,0,0,"Randomize","",(char *)0x0,0,uVar2);
  }
  *(undefined4 **)(param_1[1] + 0x90) = puVar4;
  puVar3 = (undefined4 *)operator_new(0x22d8);
  puVar4 = puVar7;
  if (puVar3 != (undefined4 *)0x0) {
    puVar4 = FUN_18000c970(puVar3,0,0,"ParamDisplay","",(char *)0x0,0,uVar2);
  }
  *(undefined4 **)(param_1[1] + 0x98) = puVar4;
  puVar3 = (undefined4 *)operator_new(0x22d8);
  puVar4 = puVar7;
  if (puVar3 != (undefined4 *)0x0) {
    puVar4 = FUN_18000c970(puVar3,1,0,"VersionDisplay","",(char *)0x0,0,uVar2);
  }
  *(undefined4 **)(param_1[1] + 0xa0) = puVar4;
  puVar3 = (undefined4 *)operator_new(0x22d8);
  puVar4 = puVar7;
  if (puVar3 != (undefined4 *)0x0) {
    puVar4 = FUN_18000c970(puVar3,1,0,"GlobalMenu","",(char *)0x0,0,uVar2);
  }
  *(undefined4 **)(param_1[1] + 0xa8) = puVar4;
  puVar3 = (undefined4 *)operator_new(0x22d8);
  puVar4 = puVar7;
  if (puVar3 != (undefined4 *)0x0) {
    puVar4 = FUN_18000c970(puVar3,1,0,"UpDownPreset","",(char *)0x0,0,uVar2);
  }
  *(undefined4 **)(param_1[1] + 0xb0) = puVar4;
  puVar3 = (undefined4 *)operator_new(0x22d8);
  puVar4 = puVar7;
  if (puVar3 != (undefined4 *)0x0) {
    puVar4 = FUN_18000c970(puVar3,1,0,"Dummy","",(char *)0x0,0,uVar2);
  }
  *(undefined4 **)(param_1[1] + 0xb8) = puVar4;
  puVar3 = (undefined4 *)operator_new(0x22d8);
  puVar4 = puVar7;
  if (puVar3 != (undefined4 *)0x0) {
    puVar4 = FUN_18000c970(puVar3,1,0,"PresetSelector","",(char *)0x0,0,uVar2);
  }
  *(undefined4 **)(param_1[1] + 0xc0) = puVar4;
  puVar3 = (undefined4 *)operator_new(0x22d8);
  puVar4 = puVar7;
  if (puVar3 != (undefined4 *)0x0) {
    puVar4 = FUN_18000c970(puVar3,1,0,"InfoLink","",(char *)0x0,0,uVar2);
  }
  *(undefined4 **)(param_1[1] + 200) = puVar4;
  pvVar5 = operator_new(0x100);
  param_1[0x882] = pvVar5;
  pvVar5 = operator_new(0x100);
  param_1[0x883] = pvVar5;
  *(undefined4 *)((longlong)param_1 + 0x4424) = 0;
  *(undefined4 *)(param_1 + 0x885) = 0;
  *(undefined *)(param_1 + 0x594) = 0;
  SHGetFolderPathA(0,0x23,0);
  FUN_18004ee30((char *)(param_1 + 0x3c9),(byte *)"%s\\Camel Audio\\%s",local_248,"CamelCrusherData"
               );
  FUN_18004ee30((char *)((longlong)param_1 + 0x2a94),&DAT_180074924,(uint *)(param_1 + 0x3c9),
                (ulonglong)(uint)(int)DAT_18009c600);
  puVar4 = (undefined4 *)(ulonglong)(uint)(int)DAT_18009c600;
  ppcVar12 = (char **)(param_1 + 0x3c9);
  pcVar10 = "%s%cMidiConfig.txt";
  FUN_18004ee30((char *)(param_1 + 0x409),(byte *)"%s%cMidiConfig.txt",(uint *)ppcVar12,puVar4);
  if (0 < *(int *)((longlong)param_1 + 0x14)) {
    pcVar10 = (char *)local_a48;
    ppcVar9 = local_1a48;
    ppcVar12 = (char **)(param_1[1] - (longlong)local_1a48);
    uVar11 = (ulonglong)*(uint *)((longlong)param_1 + 0x14);
    do {
      *ppcVar9 = (char *)(*(longlong *)((longlong)ppcVar12 + (longlong)ppcVar9) + 0x18);
      *(undefined4 *)pcVar10 = 0xffffffff;
      ppcVar9 = ppcVar9 + 1;
      pcVar10 = (char *)((longlong)pcVar10 + 4);
      uVar11 = uVar11 - 1;
    } while (uVar11 != 0);
  }
  pcVar6 = (char *)operator_new(0x8804);
  if (pcVar6 != (char *)0x0) {
    puVar4 = local_a48;
    ppcVar12 = local_1a48;
    pcVar10 = (char *)(ulonglong)*(uint *)((longlong)param_1 + 0x14);
    puVar7 = (undefined4 *)FUN_18000bab0(pcVar6,*(uint *)((longlong)param_1 + 0x14),ppcVar12,puVar4)
    ;
  }
  param_1[3] = puVar7;
  FUN_180005490((longlong)param_1,pcVar10,ppcVar12,puVar4);
  if ((DAT_180074908 != *(float *)((longlong)param_1 + 0x1c2c)) || ((double)param_1[0x386] != 0.0))
  {
    *(undefined4 *)((longlong)param_1 + 0x1c2c) = 0x42f00000;
    param_1[0x386] = 0;
  }
  __security_check_cookie(local_48 ^ (ulonglong)auStackY_1aa8);
  return;
}



// ADDRESS 1800043f0 FUN_1800043f0

longlong * FUN_1800043f0(longlong *param_1)

{
  FUN_18000ba10(param_1,0x11,0x43614372);
  *(undefined4 *)((longlong)param_1 + 0x54) = 0x3f800000;
  *param_1 = (longlong)CamelCrusherProgram::vftable;
  return param_1;
}



// ADDRESS 180004430 FUN_180004430

void FUN_180004430(longlong param_1)

{
  longlong lVar1;
  
  lVar1 = *(longlong *)(param_1 + 8);
  *(undefined4 *)(lVar1 + 0x10) = 0x3f000000;
  *(undefined4 *)(lVar1 + 0x24) = 0x3f800000;
  *(undefined4 *)(lVar1 + 0x2c) = 0x3f800000;
  *(undefined4 *)(lVar1 + 0x28) = 0x3f800000;
  return;
}


// ADDRESS 18000b930 FUN_18000b930

ulonglong FUN_18000b930(longlong *param_1,longlong param_2,int param_3)

{
  int iVar1;
  ulonglong extraout_RAX;
  ulonglong uVar2;
  undefined4 extraout_var;
  undefined8 uVar3;
  ulonglong uVar4;
  uint uVar5;
  ulonglong uVar6;
  float fVar7;
  undefined4 uVar8;
  
  uVar4 = 0;
  uVar2 = uVar4;
  uVar6 = uVar4;
  if (0 < *(int *)(param_1 + 10)) {
    do {
      uVar5 = (int)uVar6 + 1;
      *(undefined4 *)(uVar2 + param_1[1]) = 0;
      uVar2 = uVar2 + 4;
      uVar6 = (ulonglong)uVar5;
    } while ((int)uVar5 < *(int *)(param_1 + 10));
  }
  fVar7 = (float)FUN_18000c570(param_2);
  uVar2 = extraout_RAX;
  if (0.0 <= fVar7) {
    FUN_18000c6f0(param_2,(longlong)(param_1 + 2));
    if (param_3 == *(int *)(param_1 + 0xb)) {
      iVar1 = FUN_18000c640(param_2);
      uVar2 = CONCAT44(extraout_var,iVar1);
      if (*(int *)(param_1 + 10) < iVar1) goto LAB_18000b989;
      if (0 < iVar1) {
        do {
          uVar8 = FUN_18000c570(param_2);
          uVar4 = uVar4 + 1;
          *(undefined4 *)(param_1[1] + -4 + uVar4 * 4) = uVar8;
        } while ((longlong)uVar4 < (longlong)iVar1);
      }
      param_3 = *(int *)(param_1 + 0xb);
    }
    uVar3 = (**(code **)(*param_1 + 0x20))(param_1,param_2,fVar7,param_3);
    uVar2 = CONCAT71((int7)((ulonglong)uVar3 >> 8),1);
  }
  else {
LAB_18000b989:
    uVar2 = uVar2 & 0xffffffffffffff00;
  }
  return uVar2;
}



// ADDRESS 18000c510 FUN_18000c510

void FUN_18000c510(longlong param_1,undefined4 param_2)

{
  undefined local_res10;
  undefined uStackX_11;
  undefined uStackX_12;
  undefined uStackX_13;
  
  local_res10 = (undefined)param_2;
  *(undefined *)((longlong)*(int *)(param_1 + 8) + *(longlong *)(param_1 + 0x10)) = local_res10;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
  uStackX_11 = (undefined)((uint)param_2 >> 8);
  *(undefined *)((longlong)*(int *)(param_1 + 8) + *(longlong *)(param_1 + 0x10)) = uStackX_11;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
  uStackX_12 = (undefined)((uint)param_2 >> 0x10);
  *(undefined *)((longlong)*(int *)(param_1 + 8) + *(longlong *)(param_1 + 0x10)) = uStackX_12;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
  uStackX_13 = (undefined)((uint)param_2 >> 0x18);
  *(undefined *)((longlong)*(int *)(param_1 + 8) + *(longlong *)(param_1 + 0x10)) = uStackX_13;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
  return;
}



// ADDRESS 18000c570 FUN_18000c570

undefined4 FUN_18000c570(longlong param_1)

{
  undefined uVar1;
  undefined uVar2;
  undefined uVar3;
  int iVar4;
  longlong lVar5;
  undefined4 local_res8;
  
  iVar4 = *(int *)(param_1 + 8);
  lVar5 = *(longlong *)(param_1 + 0x10);
  uVar1 = *(undefined *)(iVar4 + lVar5);
  *(int *)(param_1 + 8) = iVar4 + 1;
  uVar2 = *(undefined *)((iVar4 + 1) + lVar5);
  *(int *)(param_1 + 8) = iVar4 + 2;
  uVar3 = *(undefined *)((iVar4 + 2) + lVar5);
  *(int *)(param_1 + 8) = iVar4 + 3;
  local_res8._0_2_ = CONCAT11(uVar2,uVar1);
  local_res8 = CONCAT13(*(undefined *)((iVar4 + 3) + lVar5),CONCAT12(uVar3,(undefined2)local_res8));
  *(int *)(param_1 + 8) = iVar4 + 4;
  return local_res8;
}



// ADDRESS 18000c5e0 FUN_18000c5e0

void FUN_18000c5e0(longlong param_1,undefined4 param_2)

{
  undefined uStackX_11;
  undefined uStackX_12;
  undefined uStackX_13;
  
  *(char *)((longlong)*(int *)(param_1 + 8) + *(longlong *)(param_1 + 0x10)) = (char)param_2;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
  uStackX_11 = (undefined)((uint)param_2 >> 8);
  *(undefined *)((longlong)*(int *)(param_1 + 8) + *(longlong *)(param_1 + 0x10)) = uStackX_11;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
  uStackX_12 = (undefined)((uint)param_2 >> 0x10);
  *(undefined *)((longlong)*(int *)(param_1 + 8) + *(longlong *)(param_1 + 0x10)) = uStackX_12;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
  uStackX_13 = (undefined)((uint)param_2 >> 0x18);
  *(undefined *)((longlong)*(int *)(param_1 + 8) + *(longlong *)(param_1 + 0x10)) = uStackX_13;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
  return;
}



// ADDRESS 18000c640 FUN_18000c640

undefined4 FUN_18000c640(longlong param_1)

{
  undefined uVar1;
  undefined uVar2;
  undefined uVar3;
  int iVar4;
  longlong lVar5;
  undefined4 local_res8;
  
  iVar4 = *(int *)(param_1 + 8);
  lVar5 = *(longlong *)(param_1 + 0x10);
  uVar1 = *(undefined *)(iVar4 + lVar5);
  *(int *)(param_1 + 8) = iVar4 + 1;
  uVar2 = *(undefined *)((iVar4 + 1) + lVar5);
  *(int *)(param_1 + 8) = iVar4 + 2;
  uVar3 = *(undefined *)((iVar4 + 2) + lVar5);
  *(int *)(param_1 + 8) = iVar4 + 3;
  local_res8 = CONCAT13(*(undefined *)((iVar4 + 3) + lVar5),CONCAT12(uVar3,CONCAT11(uVar2,uVar1)));
  *(int *)(param_1 + 8) = iVar4 + 4;
  return local_res8;
}



// ADDRESS 18001be70 FUN_18001be70

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_18001be70(float *param_1,longlong param_2,float *param_3,int param_4,float param_5,
                  float param_6)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  ulonglong uVar5;
  float fVar6;
  longlong lVar7;
  longlong lVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  
  fVar4 = DAT_1800747c4;
  lVar7 = (longlong)param_4;
  fVar1 = param_1[3];
  fVar2 = param_1[2];
  fVar13 = DAT_1800747c4 / (DAT_1800747c4 - *param_1);
  fVar3 = *param_1;
  param_1[2] = param_6;
  fVar6 = DAT_18007930c;
  uVar5 = DAT_180075a20;
  if (param_4 < 1) {
    *param_1 = param_5;
  }
  else {
    lVar8 = param_2 - (longlong)param_3;
    do {
      fVar11 = *(float *)(lVar8 + (longlong)param_3);
      fVar12 = *param_3;
      fVar10 = (float)(double)((ulonglong)(double)fVar11 & uVar5);
      fVar9 = (float)(double)((ulonglong)(double)fVar12 & uVar5);
      if (fVar10 <= fVar9) {
        fVar10 = fVar9;
      }
      if (param_1[1] == 0.0) {
        fVar10 = (float)(double)((ulonglong)(double)fVar10 & uVar5);
      }
      else {
        fVar10 = FUN_18000c350((longlong)(param_1 + 6),fVar10);
      }
      fVar10 = fVar10 * fVar13;
      fVar11 = fVar11 * fVar13;
      fVar12 = fVar12 * fVar13;
      if ((fVar6 < fVar10) &&
         (fVar9 = (fVar4 - (fVar10 - fVar6) / (fVar13 - fVar6)) * DAT_180079308,
         fVar10 = ((DAT_1800747ac - fVar9 * fVar9) * _DAT_180079304 + fVar6) / fVar10,
         fVar10 < param_1[4])) {
        param_1[4] = fVar10;
        param_1[5] = (fVar4 - fVar10) / (fVar1 * fVar2);
      }
      fVar10 = param_1[4];
      if (fVar10 < fVar4) {
        fVar11 = fVar11 * fVar10;
        fVar12 = fVar12 * fVar10;
        param_1[4] = fVar10 + param_1[5];
      }
      *(float *)(lVar8 + (longlong)param_3) = fVar11;
      *param_3 = fVar12;
      param_3 = param_3 + 1;
      lVar7 = lVar7 + -1;
      *param_1 = (param_5 - fVar3) / (float)param_4 + *param_1;
    } while (lVar7 != 0);
    *param_1 = param_5;
  }
  return;
}



// ADDRESS 18001c0d0 FUN_18001c0d0

void FUN_18001c0d0(longlong param_1,longlong param_2,int param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float *pfVar4;
  longlong lVar5;
  longlong lVar6;
  longlong lVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  
  fVar3 = DAT_180079320;
  fVar2 = DAT_180075934;
  fVar1 = DAT_1800747c0;
  lVar7 = (longlong)param_3;
  lVar5 = 0;
  fVar10 = *(float *)(param_1 + 4) * DAT_180075298 + DAT_1800747c4;
  fVar9 = DAT_180075930 / (fVar10 - DAT_180075934);
  if (3 < lVar7) {
    pfVar4 = (float *)(param_2 + 8);
    lVar6 = (lVar7 - 4U >> 2) + 1;
    lVar5 = lVar6 * 4;
    do {
      fVar8 = fVar10 * pfVar4[-2];
      if (fVar8 <= fVar2) {
        if (fVar8 < fVar3) {
          fVar8 = fVar1 - (((fVar1 - fVar8) - fVar2) * fVar9 + fVar2);
        }
      }
      else {
        fVar8 = (fVar8 - fVar2) * fVar9 + fVar2;
      }
      pfVar4[-2] = fVar8;
      fVar8 = fVar10 * pfVar4[-1];
      if (fVar8 <= fVar2) {
        if (fVar8 < fVar3) {
          fVar8 = fVar1 - (((fVar1 - fVar8) - fVar2) * fVar9 + fVar2);
        }
      }
      else {
        fVar8 = (fVar8 - fVar2) * fVar9 + fVar2;
      }
      pfVar4[-1] = fVar8;
      fVar8 = fVar10 * *pfVar4;
      if (fVar8 <= fVar2) {
        if (fVar8 < fVar3) {
          fVar8 = fVar1 - (((fVar1 - fVar8) - fVar2) * fVar9 + fVar2);
        }
      }
      else {
        fVar8 = (fVar8 - fVar2) * fVar9 + fVar2;
      }
      *pfVar4 = fVar8;
      fVar8 = fVar10 * pfVar4[1];
      if (fVar8 <= fVar2) {
        if (fVar8 < fVar3) {
          fVar8 = fVar1 - (((fVar1 - fVar8) - fVar2) * fVar9 + fVar2);
        }
      }
      else {
        fVar8 = (fVar8 - fVar2) * fVar9 + fVar2;
      }
      pfVar4[1] = fVar8;
      pfVar4 = pfVar4 + 4;
      lVar6 = lVar6 + -1;
    } while (lVar6 != 0);
  }
  for (; lVar5 < lVar7; lVar5 = lVar5 + 1) {
    fVar8 = fVar10 * *(float *)(param_2 + lVar5 * 4);
    if (fVar8 <= fVar2) {
      if (fVar8 < fVar3) {
        fVar8 = fVar1 - (((fVar1 - fVar8) - fVar2) * fVar9 + fVar2);
      }
    }
    else {
      fVar8 = (fVar8 - fVar2) * fVar9 + fVar2;
    }
    *(float *)(param_2 + lVar5 * 4) = fVar8;
  }
  return;
}



// ADDRESS 18001c2c0 FUN_18001c2c0

void FUN_18001c2c0(longlong param_1,longlong param_2,int param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float *pfVar8;
  longlong lVar9;
  longlong lVar10;
  longlong lVar11;
  float fVar12;
  float fVar13;
  
  fVar7 = DAT_180079328;
  fVar6 = DAT_180079324;
  fVar5 = DAT_180079308;
  fVar4 = DAT_1800747d8;
  fVar3 = DAT_1800747c4;
  fVar2 = DAT_1800747c0;
  fVar1 = DAT_1800747ac;
  lVar11 = (longlong)param_3;
  lVar9 = 0;
  fVar13 = *(float *)(param_1 + 8) * DAT_180076884 + DAT_1800747c4;
  if (3 < lVar11) {
    pfVar8 = (float *)(param_2 + 8);
    lVar10 = (lVar11 - 4U >> 2) + 1;
    lVar9 = lVar10 * 4;
    do {
      fVar12 = fVar13 * pfVar8[-2];
      if (fVar12 <= fVar4) {
        if (fVar12 < fVar7) {
          fVar12 = (fVar3 - ((fVar2 - fVar12) - fVar4) / (fVar13 - fVar4)) * fVar5;
          fVar12 = fVar2 - ((fVar1 - fVar12 * fVar12) * fVar6 + fVar4);
        }
      }
      else {
        fVar12 = (fVar3 - (fVar12 - fVar4) / (fVar13 - fVar4)) * fVar5;
        fVar12 = (fVar1 - fVar12 * fVar12) * fVar6 + fVar4;
      }
      pfVar8[-2] = fVar12;
      fVar12 = fVar13 * pfVar8[-1];
      if (fVar12 <= fVar4) {
        if (fVar12 < fVar7) {
          fVar12 = (fVar3 - ((fVar2 - fVar12) - fVar4) / (fVar13 - fVar4)) * fVar5;
          fVar12 = fVar2 - ((fVar1 - fVar12 * fVar12) * fVar6 + fVar4);
        }
      }
      else {
        fVar12 = (fVar3 - (fVar12 - fVar4) / (fVar13 - fVar4)) * fVar5;
        fVar12 = (fVar1 - fVar12 * fVar12) * fVar6 + fVar4;
      }
      pfVar8[-1] = fVar12;
      fVar12 = fVar13 * *pfVar8;
      if (fVar12 <= fVar4) {
        if (fVar12 < fVar7) {
          fVar12 = (fVar3 - ((fVar2 - fVar12) - fVar4) / (fVar13 - fVar4)) * fVar5;
          fVar12 = fVar2 - ((fVar1 - fVar12 * fVar12) * fVar6 + fVar4);
        }
      }
      else {
        fVar12 = (fVar3 - (fVar12 - fVar4) / (fVar13 - fVar4)) * fVar5;
        fVar12 = (fVar1 - fVar12 * fVar12) * fVar6 + fVar4;
      }
      *pfVar8 = fVar12;
      fVar12 = fVar13 * pfVar8[1];
      if (fVar12 <= fVar4) {
        if (fVar12 < fVar7) {
          fVar12 = (fVar3 - ((fVar2 - fVar12) - fVar4) / (fVar13 - fVar4)) * fVar5;
          fVar12 = fVar2 - ((fVar1 - fVar12 * fVar12) * fVar6 + fVar4);
        }
      }
      else {
        fVar12 = (fVar3 - (fVar12 - fVar4) / (fVar13 - fVar4)) * fVar5;
        fVar12 = (fVar1 - fVar12 * fVar12) * fVar6 + fVar4;
      }
      pfVar8[1] = fVar12;
      pfVar8 = pfVar8 + 4;
      lVar10 = lVar10 + -1;
    } while (lVar10 != 0);
  }
  for (; lVar9 < lVar11; lVar9 = lVar9 + 1) {
    fVar12 = fVar13 * *(float *)(param_2 + lVar9 * 4);
    if (fVar12 <= fVar4) {
      if (fVar12 < fVar7) {
        fVar12 = (fVar3 - ((fVar2 - fVar12) - fVar4) / (fVar13 - fVar4)) * fVar5;
        fVar12 = fVar2 - ((fVar1 - fVar12 * fVar12) * fVar6 + fVar4);
      }
    }
    else {
      fVar12 = (fVar3 - (fVar12 - fVar4) / (fVar13 - fVar4)) * fVar5;
      fVar12 = (fVar1 - fVar12 * fVar12) * fVar6 + fVar4;
    }
    *(float *)(param_2 + lVar9 * 4) = fVar12;
  }
  return;
}



// ADDRESS 18001c680 FUN_18001c680

void FUN_18001c680(longlong param_1,longlong param_2,longlong param_3,int param_4,undefined4 param_5
                  )

{
  *(undefined4 *)(param_1 + 4) = param_5;
  FUN_18001c0d0(param_1,param_2,param_4);
  FUN_18001c0d0(param_1,param_3,param_4);
  return;
}



// ADDRESS 18001c6c0 FUN_18001c6c0

void FUN_18001c6c0(longlong param_1,longlong param_2,longlong param_3,int param_4,undefined4 param_5
                  )

{
  *(undefined4 *)(param_1 + 8) = param_5;
  FUN_18001c2c0(param_1,param_2,param_4);
  FUN_18001c2c0(param_1,param_3,param_4);
  return;
}



// ADDRESS 180020a30 FUN_180020a30

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_180020a30(int *param_1,int param_2,float param_3,float param_4,float param_5,float param_6,
                  float param_7,float param_8,void *param_9,float *param_10,int param_11)

{
  bool bVar1;
  float fVar2;
  double dVar3;
  double dVar4;
  double dVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  int iVar9;
  longlong lVar10;
  int *piVar11;
  float *pfVar12;
  float *pfVar13;
  int *piVar14;
  float *pfVar15;
  longlong lVar16;
  ulonglong uVar17;
  longlong lVar18;
  int iVar19;
  int iVar20;
  ulonglong uVar21;
  float fVar22;
  undefined8 uVar23;
  double dVar24;
  double dVar25;
  double dVar26;
  float fVar27;
  float fVar28;
  float fVar29;
  float fVar30;
  undefined4 uVar31;
  undefined4 uVar32;
  float fVar33;
  float fVar34;
  undefined8 local_2f8;
  undefined8 local_2f0;
  float local_2e8 [60];
  float afStack_1f8 [110];
  
  fVar2 = DAT_1800747c4;
  iVar20 = *param_1;
  uVar17 = 0;
  bVar1 = false;
  fVar34 = 0.0;
  lVar10 = (longlong)param_11;
  fVar22 = (param_6 - (float)param_1[0x4c4]) / (float)param_11;
  if ((float)param_1[0x4c5] != param_7) {
    param_1[0x4c5] = (int)param_7;
    param_1[0x3b5] = (int)param_7;
    if (param_7 == 0.0) {
      param_1[0x3b8] = 0;
    }
    else {
      param_1[0x3b8] = (int)(fVar2 / (param_7 * (float)param_1[0x3b4]));
    }
  }
  if ((float)param_1[0x4c6] != param_8) {
    param_1[0x4c6] = (int)param_8;
    param_1[0x3b6] = (int)param_8;
    if (param_8 == 0.0) {
      param_1[0x3b9] = 0;
    }
    else {
      param_1[0x3b9] = (int)(fVar2 / (param_8 * (float)param_1[0x3b4]));
    }
  }
  local_2f8 = lVar10;
  memcpy(local_2e8,param_9,lVar10 * 4);
  memcpy(afStack_1f8 + 4,param_10,lVar10 * 4);
  fVar29 = DAT_1800768d8;
  dVar5 = DAT_1800768d0;
  dVar4 = DAT_1800768c8;
  dVar26 = DAT_1800768c0;
  dVar3 = DAT_180075948;
  fVar27 = (float)param_1[0x4c0];
  uVar31 = SUB84(DAT_1800768c0,0);
  uVar32 = (undefined4)((ulonglong)DAT_1800768c0 >> 0x20);
  if ((param_3 != fVar27) || (iVar20 != param_2)) {
    fVar27 = (float)param_1[0x4c3] * (float)param_1[0x3b7] * fVar27 +
             (fVar2 - (float)param_1[0x4c3]) * fVar27;
    fVar34 = DAT_180079e40;
    if ((fVar27 < fVar2) && (fVar34 = DAT_1800794ac, 0.0 < fVar27)) {
      uVar23 = FUN_180051ac0((ulonglong)(uint)(fVar2 - fVar27));
      dVar24 = (double)((float)uVar23 * fVar29);
      dVar25 = dVar3;
      if ((dVar24 <= dVar3) && (dVar25 = dVar24, dVar24 < dVar5)) {
        dVar25 = 0.0;
      }
      fVar34 = (float)(dVar25 * dVar4 + dVar26);
    }
    uVar23 = FUN_180054b20((ulonglong)DAT_1800747bc);
    fVar27 = DAT_180079e54 / (float)uVar23;
    uVar23 = FUN_180054b20((ulonglong)(uint)(fVar34 * _DAT_180079e58));
    fVar34 = fVar27 * (float)uVar23 + _DAT_180079470;
    if (fVar34 < 0.0) {
      fVar34 = 0.0;
    }
    if ((float)param_1[0x3bf] < fVar34) {
      fVar34 = (float)param_1[0x3bf];
    }
    if (iVar20 != param_2) {
      FUN_18001e460(param_1,param_2,fVar34,param_1[0x4c1],fVar2);
    }
    uVar31 = SUB84(DAT_1800768c0,0);
    uVar32 = (undefined4)((ulonglong)DAT_1800768c0 >> 0x20);
    bVar1 = true;
    if (param_1[0x3ba] == 1) {
      fVar34 = (param_3 - (float)param_1[0x4c0]) / (float)param_11;
    }
    else {
      fVar34 = (param_3 - (float)param_1[0x4c0]) / (float)(param_11 * 2);
    }
  }
  fVar27 = DAT_1800768d8;
  if ((((float)param_1[0x4c3] != 0.0) || ((float)param_1[0x4c1] != param_4)) ||
     ((float)param_1[0x4c3] != param_5)) {
    param_1[0x4c1] = (int)param_4;
    param_1[0x4c3] = (int)param_5;
    fVar28 = param_5 * (float)param_1[0x3b7] * (float)param_1[0x4c0] +
             (fVar2 - param_5) * (float)param_1[0x4c0];
    fVar29 = DAT_180079e40;
    if ((fVar28 < fVar2) && (fVar29 = DAT_1800794ac, 0.0 < fVar28)) {
      uVar23 = FUN_180051ac0((ulonglong)(uint)(fVar2 - fVar28));
      dVar25 = (double)((float)uVar23 * fVar27);
      dVar26 = dVar3;
      if ((dVar25 <= dVar3) && (dVar26 = dVar25, dVar25 < dVar5)) {
        dVar26 = 0.0;
      }
      fVar29 = (float)(dVar26 * dVar4 + (double)CONCAT44(uVar32,uVar31));
    }
    uVar23 = FUN_180054b20((ulonglong)DAT_1800747bc);
    fVar27 = DAT_180079e54 / (float)uVar23;
    uVar23 = FUN_180054b20((ulonglong)(uint)(fVar29 * _DAT_180079e58));
    fVar27 = fVar27 * (float)uVar23 + _DAT_180079470;
    if (fVar27 < 0.0) {
      fVar27 = 0.0;
    }
    (**(code **)(**(longlong **)(param_1 + 2) + 0x18))(*(longlong **)(param_1 + 2),param_4);
    (**(code **)(**(longlong **)(param_1 + 4) + 0x18))(*(longlong **)(param_1 + 4),param_1[0x4c1]);
    (**(code **)(**(longlong **)(param_1 + 2) + 0x10))(*(longlong **)(param_1 + 2),fVar27);
    (**(code **)(**(longlong **)(param_1 + 4) + 0x10))(*(longlong **)(param_1 + 4),fVar27);
  }
  fVar27 = DAT_1800747ac;
  if (param_1[0x3ba] == 1) {
    local_2f0 = 0;
    if (0 < param_11) {
      do {
        iVar19 = (int)uVar17;
        iVar9 = param_11 - iVar19;
        lVar10 = 0x10;
        iVar20 = 0x10;
        if ((0xf < iVar9) || (lVar10 = param_11 - local_2f0, iVar20 = iVar9, 0 < lVar10)) {
          pfVar12 = param_10 + local_2f0;
          lVar16 = lVar10;
          do {
            FUN_18000c350((longlong)(param_1 + 0x3b4),
                          (*(float *)((longlong)pfVar12 + ((longlong)param_9 - (longlong)param_10))
                          + *pfVar12) * fVar27 * fVar27);
            pfVar12 = pfVar12 + 1;
            lVar16 = lVar16 + -1;
          } while (lVar16 != 0);
        }
        lVar16 = local_2f0;
        (**(code **)(**(longlong **)(param_1 + 2) + 0x40))
                  (*(longlong **)(param_1 + 2),(void *)((longlong)param_9 + (longlong)iVar19 * 4),
                   param_10 + iVar19,iVar20,*(undefined8 *)(param_1 + 4));
        if (bVar1) {
          fVar29 = (float)iVar20 * fVar34 + (float)param_1[0x4c0];
          param_1[0x4c0] = (int)fVar29;
          fVar28 = (float)param_1[0x4c3] * (float)param_1[0x3b7] * fVar29 +
                   (fVar2 - (float)param_1[0x4c3]) * fVar29;
          fVar29 = DAT_180079e40;
          if ((fVar28 < fVar2) && (fVar29 = DAT_1800794ac, 0.0 < fVar28)) {
            uVar23 = FUN_180051ac0((ulonglong)(uint)(fVar2 - fVar28));
            dVar25 = (double)((float)uVar23 * DAT_1800768d8);
            dVar26 = dVar3;
            if ((dVar25 <= dVar3) && (dVar26 = dVar25, dVar25 < dVar5)) {
              dVar26 = 0.0;
            }
            fVar29 = (float)(dVar26 * dVar4 + DAT_1800768c0);
          }
          uVar23 = FUN_180054b20((ulonglong)DAT_1800747bc);
          fVar28 = DAT_180079e54 / (float)uVar23;
          uVar23 = FUN_180054b20((ulonglong)(uint)(fVar29 * _DAT_180079e58));
          fVar29 = fVar28 * (float)uVar23 + _DAT_180079470;
          if (fVar29 < 0.0) {
            fVar29 = 0.0;
          }
          (**(code **)(**(longlong **)(param_1 + 2) + 0x10))(*(longlong **)(param_1 + 2),fVar29);
          (**(code **)(**(longlong **)(param_1 + 4) + 0x10))(*(longlong **)(param_1 + 4),fVar29);
        }
        uVar17 = (ulonglong)(uint)(iVar19 + iVar20);
        local_2f0 = lVar16 + lVar10;
      } while (iVar19 + iVar20 < param_11);
    }
    param_1[0x4c0] = (int)param_3;
    param_1[0x4c1] = (int)param_4;
    lVar10 = local_2f8;
  }
  else {
    uVar21 = uVar17;
    if (3 < lVar10) {
      lVar16 = (lVar10 - 4U >> 2) + 1;
      uVar21 = lVar16 * 4;
      piVar11 = param_1 + 0x3c1;
      pfVar12 = param_10 + 1;
      piVar14 = (int *)((longlong)param_9 + 0xc);
      do {
        iVar20 = piVar14[-3];
        fVar27 = pfVar12[-1];
        lVar16 = lVar16 + -1;
        piVar11[-1] = iVar20;
        *piVar11 = iVar20;
        piVar11[0x7f] = (int)fVar27;
        piVar11[0x80] = (int)fVar27;
        iVar20 = *(int *)((longlong)pfVar12 + ((longlong)param_9 - (longlong)param_10));
        fVar27 = *pfVar12;
        piVar11[1] = iVar20;
        piVar11[2] = iVar20;
        piVar11[0x81] = (int)fVar27;
        piVar11[0x82] = (int)fVar27;
        iVar20 = piVar14[-1];
        fVar27 = pfVar12[1];
        piVar11[3] = iVar20;
        piVar11[4] = iVar20;
        piVar11[0x83] = (int)fVar27;
        piVar11[0x84] = (int)fVar27;
        iVar20 = *piVar14;
        fVar27 = pfVar12[2];
        piVar11[5] = iVar20;
        piVar11[6] = iVar20;
        piVar11[0x85] = (int)fVar27;
        piVar11[0x86] = (int)fVar27;
        piVar11 = piVar11 + 8;
        pfVar12 = pfVar12 + 4;
        piVar14 = piVar14 + 4;
      } while (lVar16 != 0);
    }
    if ((longlong)uVar21 < lVar10) {
      pfVar12 = param_10 + uVar21;
      lVar16 = lVar10 - uVar21;
      piVar11 = param_1 + uVar21 * 2 + 0x3c1;
      do {
        iVar20 = *(int *)((longlong)pfVar12 + ((longlong)param_9 - (longlong)param_10));
        fVar27 = *pfVar12;
        pfVar12 = pfVar12 + 1;
        lVar16 = lVar16 + -1;
        piVar11[-1] = iVar20;
        *piVar11 = iVar20;
        piVar11[0x7f] = (int)fVar27;
        piVar11[0x80] = (int)fVar27;
        piVar11 = piVar11 + 2;
      } while (lVar16 != 0);
    }
    fVar27 = DAT_1800747ac;
    iVar20 = param_11 * 2;
    param_7 = 0.0;
    uVar21 = uVar17;
    if (0 < iVar20) {
      do {
        lVar16 = 0x10;
        param_11 = 0x10;
        iVar9 = iVar20 - (int)(float)uVar17;
        if (iVar9 < 0x10) {
          lVar16 = lVar10 * 2 - uVar21;
          param_11 = iVar9;
        }
        pfVar12 = (float *)(param_1 + uVar21 + 0x3c0);
        fVar29 = (float)uVar17;
        if (0 < lVar16) {
          pfVar13 = pfVar12;
          lVar10 = lVar16;
          do {
            FUN_18000c350((longlong)(param_1 + 0x3b4),
                          (*(float *)((longlong)pfVar13 +
                                     (longlong)param_1 + ((uVar21 * 4 + 0x1100) - (longlong)pfVar12)
                                     ) + *pfVar13) * fVar27 * fVar27);
            pfVar13 = pfVar13 + 1;
            lVar10 = lVar10 + -1;
            fVar29 = param_7;
          } while (lVar10 != 0);
        }
        (**(code **)(**(longlong **)(param_1 + 2) + 0x40))
                  (*(longlong **)(param_1 + 2),pfVar12,param_1 + uVar21 + 0x440,param_11,
                   *(undefined8 *)(param_1 + 4));
        if (bVar1) {
          fVar28 = (float)param_11 * fVar34 + (float)param_1[0x4c0];
          param_1[0x4c0] = (int)fVar28;
          fVar30 = (float)param_1[0x4c3] * (float)param_1[0x3b7] * fVar28 +
                   (fVar2 - (float)param_1[0x4c3]) * fVar28;
          fVar28 = DAT_180079e40;
          if ((fVar30 < fVar2) && (fVar28 = DAT_1800794ac, 0.0 < fVar30)) {
            uVar23 = FUN_180051ac0((ulonglong)(uint)(fVar2 - fVar30));
            dVar25 = (double)((float)uVar23 * DAT_1800768d8);
            dVar26 = dVar3;
            if ((dVar25 <= dVar3) && (dVar26 = dVar25, dVar25 < dVar5)) {
              dVar26 = 0.0;
            }
            fVar28 = (float)(dVar26 * dVar4 + DAT_1800768c0);
          }
          uVar23 = FUN_180054b20((ulonglong)DAT_1800747bc);
          fVar30 = DAT_180079e54 / (float)uVar23;
          uVar23 = FUN_180054b20((ulonglong)(uint)(fVar28 * _DAT_180079e58));
          fVar28 = fVar30 * (float)uVar23 + _DAT_180079470;
          if (fVar28 < 0.0) {
            fVar28 = 0.0;
          }
          (**(code **)(**(longlong **)(param_1 + 2) + 0x10))(*(longlong **)(param_1 + 2),fVar28);
          (**(code **)(**(longlong **)(param_1 + 4) + 0x10))(*(longlong **)(param_1 + 4),fVar28);
        }
        param_7 = (float)((int)fVar29 + param_11);
        uVar17 = (ulonglong)(uint)param_7;
        uVar21 = uVar21 + lVar16;
        lVar10 = local_2f8;
      } while ((int)param_7 < iVar20);
    }
    lVar16 = 0;
    param_1[0x4c0] = (int)param_3;
    param_1[0x4c1] = (int)param_4;
    if (3 < lVar10) {
      lVar18 = (lVar10 - 4U >> 2) + 1;
      lVar16 = lVar18 * 4;
      piVar11 = param_1 + 0x450;
      pfVar12 = param_10 + 1;
      pfVar13 = (float *)((longlong)param_9 + 0xc);
      do {
        pfVar13[-3] = ((float)piVar11[-0x90] + (float)piVar11[-0x8f]) * fVar27;
        lVar18 = lVar18 + -1;
        pfVar12[-1] = ((float)piVar11[-0x10] + (float)piVar11[-0xf]) * fVar27;
        *(float *)((longlong)pfVar12 + ((longlong)param_9 - (longlong)param_10)) =
             ((float)piVar11[-0x8e] + (float)piVar11[-0x8d]) * fVar27;
        *pfVar12 = ((float)piVar11[-0xe] + (float)piVar11[-0xd]) * fVar27;
        pfVar13[-1] = ((float)piVar11[-0x8c] + (float)piVar11[-0x8b]) * fVar27;
        pfVar12[1] = ((float)piVar11[-0xc] + (float)piVar11[-0xb]) * fVar27;
        *pfVar13 = ((float)piVar11[-0x8a] + (float)piVar11[-0x89]) * fVar27;
        pfVar12[2] = ((float)piVar11[-10] + (float)piVar11[-9]) * fVar27;
        piVar11 = piVar11 + 8;
        pfVar12 = pfVar12 + 4;
        pfVar13 = pfVar13 + 4;
      } while (lVar18 != 0);
    }
    if (lVar16 < lVar10) {
      lVar18 = lVar10 - lVar16;
      pfVar12 = (float *)(param_1 + lVar16 * 2 + 0x3c0);
      pfVar13 = param_10 + lVar16;
      do {
        lVar18 = lVar18 + -1;
        *(float *)((longlong)pfVar13 + ((longlong)param_9 - (longlong)param_10)) =
             (pfVar12[1] + *pfVar12) * fVar27;
        *pfVar13 = (pfVar12[0x81] + pfVar12[0x80]) * fVar27;
        pfVar12 = pfVar12 + 2;
        pfVar13 = pfVar13 + 1;
      } while (lVar18 != 0);
    }
  }
  fVar8 = DAT_18007a228;
  fVar7 = DAT_180079e44;
  fVar6 = DAT_1800794a0;
  fVar30 = DAT_18007947c;
  fVar28 = DAT_180079370;
  uVar17 = DAT_180075a20;
  fVar29 = DAT_1800747d8;
  fVar34 = DAT_1800747c0;
  lVar16 = 0;
  if (param_1[0x3bb] == 1) {
    if (0 < lVar10) {
      lVar18 = (longlong)param_9 - (longlong)param_10;
      pfVar12 = param_10;
      lVar16 = lVar10;
      do {
        fVar27 = (float)(double)((ulonglong)(double)*pfVar12 & uVar17);
        fVar34 = (float)(double)((ulonglong)(double)*(float *)((longlong)pfVar12 + lVar18) & uVar17)
        ;
        if (fVar34 < fVar27) {
          fVar34 = fVar27;
        }
        fVar34 = FUN_18000c350((longlong)(param_1 + 0x3ae),fVar34);
        if ((fVar2 < fVar34) && (fVar34 = fVar2 / fVar34, fVar34 < (float)param_1[0x3bc])) {
          param_1[0x3bc] = (int)fVar34;
          param_1[0x3bd] = (int)((fVar2 - fVar34) / ((float)param_1[0x3be] * fVar28));
        }
        if ((float)param_1[0x3bc] < fVar2) {
          *(float *)((longlong)pfVar12 + lVar18) =
               (float)param_1[0x3bc] * *(float *)((longlong)pfVar12 + lVar18);
          *pfVar12 = (float)param_1[0x3bc] * *pfVar12;
          param_1[0x3bc] = (int)((float)param_1[0x3bd] + (float)param_1[0x3bc]);
        }
        pfVar12 = pfVar12 + 1;
        lVar16 = lVar16 + -1;
      } while (lVar16 != 0);
    }
  }
  else if (param_1[0x3bb] == 2) {
    if (3 < lVar10) {
      pfVar13 = (float *)((longlong)param_9 + 0xc);
      pfVar12 = param_10 + 1;
      lVar18 = (lVar10 - 4U >> 2) + 1;
      lVar16 = lVar18 * 4;
      do {
        fVar28 = pfVar13[-3];
        fVar33 = (float)param_1[0x4c1] * fVar30 + fVar2;
        if (fVar28 <= fVar7) {
          if (fVar28 < fVar8) {
            fVar28 = (fVar2 - ((fVar34 - fVar28) - fVar7) / (fVar33 - fVar7)) * fVar6;
            fVar28 = fVar34 - ((fVar27 - fVar28 * fVar28) * fVar29 + fVar7);
          }
        }
        else {
          fVar28 = (fVar2 - (fVar28 - fVar7) / (fVar33 - fVar7)) * fVar6;
          fVar28 = (fVar27 - fVar28 * fVar28) * fVar29 + fVar7;
        }
        pfVar13[-3] = fVar28;
        fVar28 = pfVar12[-1];
        fVar33 = (float)param_1[0x4c1] * fVar30 + fVar2;
        if (fVar28 <= fVar7) {
          if (fVar28 < fVar8) {
            fVar28 = (fVar2 - ((fVar34 - fVar28) - fVar7) / (fVar33 - fVar7)) * fVar6;
            fVar28 = fVar34 - ((fVar27 - fVar28 * fVar28) * fVar29 + fVar7);
          }
        }
        else {
          fVar28 = (fVar2 - (fVar28 - fVar7) / (fVar33 - fVar7)) * fVar6;
          fVar28 = (fVar27 - fVar28 * fVar28) * fVar29 + fVar7;
        }
        pfVar12[-1] = fVar28;
        fVar28 = *(float *)((longlong)pfVar12 + ((longlong)param_9 - (longlong)param_10));
        fVar33 = (float)param_1[0x4c1] * fVar30 + fVar2;
        if (fVar28 <= fVar7) {
          if (fVar28 < fVar8) {
            fVar28 = (fVar2 - ((fVar34 - fVar28) - fVar7) / (fVar33 - fVar7)) * fVar6;
            fVar28 = fVar34 - ((fVar27 - fVar28 * fVar28) * fVar29 + fVar7);
          }
        }
        else {
          fVar28 = (fVar2 - (fVar28 - fVar7) / (fVar33 - fVar7)) * fVar6;
          fVar28 = (fVar27 - fVar28 * fVar28) * fVar29 + fVar7;
        }
        *(float *)((longlong)pfVar12 + ((longlong)param_9 - (longlong)param_10)) = fVar28;
        fVar28 = *pfVar12;
        fVar33 = (float)param_1[0x4c1] * fVar30 + fVar2;
        if (fVar28 <= fVar7) {
          if (fVar28 < fVar8) {
            fVar28 = (fVar2 - ((fVar34 - fVar28) - fVar7) / (fVar33 - fVar7)) * fVar6;
            fVar28 = fVar34 - ((fVar27 - fVar28 * fVar28) * fVar29 + fVar7);
          }
        }
        else {
          fVar28 = (fVar2 - (fVar28 - fVar7) / (fVar33 - fVar7)) * fVar6;
          fVar28 = (fVar27 - fVar28 * fVar28) * fVar29 + fVar7;
        }
        *pfVar12 = fVar28;
        fVar28 = pfVar13[-1];
        fVar33 = (float)param_1[0x4c1] * fVar30 + fVar2;
        if (fVar28 <= fVar7) {
          if (fVar28 < fVar8) {
            fVar28 = (fVar2 - ((fVar34 - fVar28) - fVar7) / (fVar33 - fVar7)) * fVar6;
            fVar28 = fVar34 - ((fVar27 - fVar28 * fVar28) * fVar29 + fVar7);
          }
        }
        else {
          fVar28 = (fVar2 - (fVar28 - fVar7) / (fVar33 - fVar7)) * fVar6;
          fVar28 = (fVar27 - fVar28 * fVar28) * fVar29 + fVar7;
        }
        pfVar13[-1] = fVar28;
        fVar28 = pfVar12[1];
        fVar33 = (float)param_1[0x4c1] * fVar30 + fVar2;
        if (fVar28 <= fVar7) {
          if (fVar28 < fVar8) {
            fVar28 = (fVar2 - ((fVar34 - fVar28) - fVar7) / (fVar33 - fVar7)) * fVar6;
            fVar28 = fVar34 - ((fVar27 - fVar28 * fVar28) * fVar29 + fVar7);
          }
        }
        else {
          fVar28 = (fVar2 - (fVar28 - fVar7) / (fVar33 - fVar7)) * fVar6;
          fVar28 = (fVar27 - fVar28 * fVar28) * fVar29 + fVar7;
        }
        pfVar12[1] = fVar28;
        fVar28 = *pfVar13;
        fVar33 = (float)param_1[0x4c1] * fVar30 + fVar2;
        if (fVar28 <= fVar7) {
          if (fVar28 < fVar8) {
            fVar28 = (fVar2 - ((fVar34 - fVar28) - fVar7) / (fVar33 - fVar7)) * fVar6;
            fVar28 = fVar34 - ((fVar27 - fVar28 * fVar28) * fVar29 + fVar7);
          }
        }
        else {
          fVar28 = (fVar2 - (fVar28 - fVar7) / (fVar33 - fVar7)) * fVar6;
          fVar28 = (fVar27 - fVar28 * fVar28) * fVar29 + fVar7;
        }
        *pfVar13 = fVar28;
        fVar28 = pfVar12[2];
        fVar33 = (float)param_1[0x4c1] * fVar30 + fVar2;
        if (fVar28 <= fVar7) {
          if (fVar28 < fVar8) {
            fVar28 = (fVar2 - ((fVar34 - fVar28) - fVar7) / (fVar33 - fVar7)) * fVar6;
            fVar28 = fVar34 - ((fVar27 - fVar28 * fVar28) * fVar29 + fVar7);
          }
        }
        else {
          fVar28 = (fVar2 - (fVar28 - fVar7) / (fVar33 - fVar7)) * fVar6;
          fVar28 = (fVar27 - fVar28 * fVar28) * fVar29 + fVar7;
        }
        pfVar12[2] = fVar28;
        pfVar12 = pfVar12 + 4;
        pfVar13 = pfVar13 + 4;
        lVar18 = lVar18 + -1;
      } while (lVar18 != 0);
    }
    if (lVar16 < lVar10) {
      pfVar12 = param_10 + lVar16;
      lVar16 = lVar10 - lVar16;
      do {
        fVar28 = *(float *)((longlong)pfVar12 + ((longlong)param_9 - (longlong)param_10));
        fVar33 = (float)param_1[0x4c1] * fVar30 + fVar2;
        if (fVar28 <= fVar7) {
          if (fVar28 < fVar8) {
            fVar28 = (fVar2 - ((fVar34 - fVar28) - fVar7) / (fVar33 - fVar7)) * fVar6;
            fVar28 = fVar34 - ((fVar27 - fVar28 * fVar28) * fVar29 + fVar7);
          }
        }
        else {
          fVar28 = (fVar2 - (fVar28 - fVar7) / (fVar33 - fVar7)) * fVar6;
          fVar28 = (fVar27 - fVar28 * fVar28) * fVar29 + fVar7;
        }
        *(float *)((longlong)pfVar12 + ((longlong)param_9 - (longlong)param_10)) = fVar28;
        fVar28 = *pfVar12;
        fVar33 = (float)param_1[0x4c1] * fVar30 + fVar2;
        if (fVar28 <= fVar7) {
          if (fVar28 < fVar8) {
            fVar28 = (fVar2 - ((fVar34 - fVar28) - fVar7) / (fVar33 - fVar7)) * fVar6;
            fVar28 = fVar34 - ((fVar27 - fVar28 * fVar28) * fVar29 + fVar7);
          }
        }
        else {
          fVar28 = (fVar2 - (fVar28 - fVar7) / (fVar33 - fVar7)) * fVar6;
          fVar28 = (fVar27 - fVar28 * fVar28) * fVar29 + fVar7;
        }
        *pfVar12 = fVar28;
        pfVar12 = pfVar12 + 1;
        lVar16 = lVar16 + -1;
      } while (lVar16 != 0);
    }
  }
  if (lVar10 < 4) {
    lVar16 = 0;
  }
  else {
    lVar16 = 0;
    pfVar12 = param_10 + 1;
    pfVar13 = (float *)((longlong)param_9 + 0xc);
    do {
      lVar16 = lVar16 + 4;
      pfVar15 = pfVar12 + 4;
      pfVar13[-3] = (fVar2 - (float)param_1[0x4c4]) * *(float *)((longlong)&local_2f8 + lVar16 * 4)
                    + (float)param_1[0x4c4] * pfVar13[-3];
      pfVar12[-1] = (fVar2 - (float)param_1[0x4c4]) * afStack_1f8[lVar16] +
                    (float)param_1[0x4c4] * pfVar12[-1];
      fVar34 = fVar22 + (float)param_1[0x4c4];
      param_1[0x4c4] = (int)fVar34;
      *(float *)((longlong)pfVar12 + ((longlong)param_9 - (longlong)param_10)) =
           (fVar2 - fVar34) *
           *(float *)(((longlong)&local_2f8 - (longlong)param_10) + (longlong)pfVar15) +
           fVar34 * *(float *)((longlong)pfVar12 + ((longlong)param_9 - (longlong)param_10));
      *pfVar12 = (fVar2 - (float)param_1[0x4c4]) *
                 *(float *)(((longlong)afStack_1f8 - (longlong)param_10) + (longlong)pfVar15) +
                 (float)param_1[0x4c4] * *pfVar12;
      fVar34 = fVar22 + (float)param_1[0x4c4];
      param_1[0x4c4] = (int)fVar34;
      pfVar13[-1] = (fVar2 - fVar34) *
                    *(float *)((longlong)&local_2f8 + (4 - (longlong)param_10) + (longlong)pfVar15)
                    + fVar34 * pfVar13[-1];
      pfVar12[1] = (fVar2 - (float)param_1[0x4c4]) *
                   *(float *)((longlong)afStack_1f8 + (4 - (longlong)param_10) + (longlong)pfVar15)
                   + (float)param_1[0x4c4] * pfVar12[1];
      fVar34 = fVar22 + (float)param_1[0x4c4];
      param_1[0x4c4] = (int)fVar34;
      *pfVar13 = (fVar2 - fVar34) *
                 *(float *)(((longlong)&local_2f0 - (longlong)param_10) + (longlong)pfVar15) +
                 fVar34 * *pfVar13;
      pfVar12[2] = (fVar2 - (float)param_1[0x4c4]) *
                   *(float *)((longlong)afStack_1f8 + (8 - (longlong)param_10) + (longlong)pfVar15)
                   + (float)param_1[0x4c4] * pfVar12[2];
      param_1[0x4c4] = (int)(fVar22 + (float)param_1[0x4c4]);
      pfVar12 = pfVar15;
      pfVar13 = pfVar13 + 4;
    } while (lVar16 < lVar10 + -3);
  }
  if (lVar16 < lVar10) {
    lVar10 = lVar10 - lVar16;
    pfVar12 = (float *)((longlong)param_9 + lVar16 * 4);
    do {
      pfVar13 = pfVar12 + 1;
      lVar10 = lVar10 + -1;
      *pfVar12 = (fVar2 - (float)param_1[0x4c4]) *
                 *(float *)((longlong)&local_2f0 + (4 - (longlong)param_9) + (longlong)pfVar13) +
                 (float)param_1[0x4c4] * *pfVar12;
      *(float *)((longlong)param_10 + (-4 - (longlong)param_9) + (longlong)pfVar13) =
           (fVar2 - (float)param_1[0x4c4]) *
           *(float *)((longlong)afStack_1f8 + (0xc - (longlong)param_9) + (longlong)pfVar13) +
           (float)param_1[0x4c4] *
           *(float *)((longlong)param_10 + (-4 - (longlong)param_9) + (longlong)pfVar13);
      param_1[0x4c4] = (int)(fVar22 + (float)param_1[0x4c4]);
      pfVar12 = pfVar13;
    } while (lVar10 != 0);
  }
  param_1[0x4c4] = (int)param_6;
  return;
}


