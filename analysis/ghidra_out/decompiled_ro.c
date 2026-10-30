// ===== FUN_00982000 @ 00982000

/* WARNING: Control flow encountered bad instruction data */

void FUN_00982000(void)

{
  undefined4 *puVar1;
  
  for (puVar1 = (undefined4 *)&DAT_009b4a80; puVar1 < (undefined4 *)0x9fd0a0; puVar1 = puVar1 + 1) {
    *puVar1 = 0;
  }
  coproc_moveto_Data_Synchronization(0);
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00982100 @ 00982100

void FUN_00982100(void)

{
  (*(code *)&SUB_ffb18b40)();
  return;
}


// ===== FUN_009821a4 @ 009821a4

undefined8 FUN_009821a4(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  
  iVar3 = 0x437c;
  puVar1 = param_1;
  puVar2 = param_2;
  do {
    *puVar2 = *puVar1;
    iVar3 = iVar3 + -1;
    puVar1 = puVar1 + 1;
    puVar2 = puVar2 + 1;
  } while (iVar3 != 0);
  return CONCAT44(param_2,param_1);
}


// ===== FUN_00982280 @ 00982280

void FUN_00982280(undefined4 *param_1)

{
  ushort uVar1;
  ushort *puVar2;
  uint uVar3;
  ushort *puVar4;
  ushort *puVar5;
  ushort *puVar6;
  uint uVar7;
  int *piVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  int *piVar13;
  ushort *puVar14;
  int iVar15;
  int iVar16;
  uint uVar17;
  int iVar18;
  uint uVar19;
  uint uVar20;
  int local_38;
  int local_34;
  
  puVar4 = (ushort *)*param_1;
  puVar6 = (ushort *)param_1[1];
  piVar8 = (int *)param_1[3];
  iVar9 = param_1[4];
  uVar10 = param_1[5];
  uVar11 = param_1[6];
  iVar12 = param_1[7];
  piVar13 = (int *)param_1[8];
  uVar7 = param_1[10];
  uVar3 = param_1[9];
  puVar2 = (ushort *)param_1[2];
  while (puVar4 < puVar6) {
    iVar15 = 0;
    iVar18 = 0;
    puVar14 = (ushort *)(iVar12 + (uint)*puVar2 * 2);
    if (puVar6 < puVar14) {
      puVar14 = puVar6;
    }
    local_38 = 0;
    local_34 = 0;
    while (puVar4 < puVar14) {
      puVar5 = puVar4 + 1;
      uVar1 = *puVar4;
      puVar4 = puVar4 + 2;
      uVar19 = *(uint *)(iVar9 + (uint)uVar1 * 4);
      uVar20 = *(uint *)(iVar9 + (uint)*puVar5 * 4);
      if (uVar10 < uVar19) {
        uVar19 = uVar10;
      }
      iVar15 = iVar15 + uVar19;
      if (uVar11 < uVar20) {
        uVar20 = uVar11;
      }
      iVar18 = iVar18 + uVar20;
      if (uVar3 <= uVar19 || uVar7 <= uVar20) {
        if (uVar19 < uVar3) {
          iVar16 = uVar20 - uVar7;
        }
        else {
          iVar16 = uVar19 - uVar3;
        }
        uVar17 = (uint)(param_1[0xb] * iVar16) >> 0x10;
        if (0x100 < uVar17) {
          uVar17 = 0x100;
        }
        uVar17 = (uint)*(ushort *)(param_1[0xc] + uVar17 * 2);
        local_38 = local_38 + (uVar19 * uVar17 >> 8);
        local_34 = local_34 + (uVar20 * uVar17 >> 8);
      }
    }
    *piVar8 = *piVar8 + iVar15;
    piVar8[1] = piVar8[1] + iVar18;
    piVar8 = piVar8 + 2;
    *piVar13 = *piVar13 + local_38;
    piVar13[1] = piVar13[1] + local_34;
    piVar13 = piVar13 + 2;
    puVar2 = puVar2 + 1;
  }
  *param_1 = puVar4;
  return;
}


// ===== FUN_009823c4 @ 009823c4

bool FUN_009823c4(uint param_1)

{
  if (param_1 - 0x1000 < 0x1fff000) {
    return (param_1 & 3) == 0;
  }
  return false;
}


// ===== FUN_009823f0 @ 009823f0

undefined4 FUN_009823f0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 local_c;
  undefined4 uStack_8;
  
  local_c = 0;
  uStack_8 = param_3;
  (*(code *)&SUB_ffb1ff74)(&local_c);
  return local_c;
}


// ===== FUN_009823f4 @ 009823f4

undefined4 FUN_009823f4(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 local_c;
  undefined4 uStack_8;
  
  local_c = param_4;
  uStack_8 = param_3;
  (*(code *)&SUB_ffb1ff74)(&local_c);
  return local_c;
}


// ===== FUN_00982418 @ 00982418

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00982418(void)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  undefined8 uVar5;
  
  iVar2 = _DAT_00004ed0;
  _DAT_009b4a94 = 0;
  iVar1 = FUN_009823c4(_DAT_00004ed0);
  if (iVar1 != 0) {
    piVar3 = *(int **)(iVar2 + 4);
    iVar2 = FUN_009823c4(piVar3);
    if ((iVar2 != 0) && (*piVar3 == -0x4d6644)) {
      piVar4 = (int *)piVar3[5];
      uVar5 = FUN_009823c4(piVar4);
      piVar3 = (int *)((ulonglong)uVar5 >> 0x20);
      if (((int)uVar5 != 0) && (*piVar4 == -0x4d5f7c)) {
        *piVar3 = piVar4[3];
        piVar3[5] = 1;
      }
    }
  }
  piVar3 = _DAT_00004ed4;
  uVar5 = FUN_009823c4(_DAT_00004ed4);
  iVar2 = (int)((ulonglong)uVar5 >> 0x20);
  if (((int)uVar5 != 0) && (*piVar3 == -0x4dda98)) {
    *(int *)(iVar2 + 4) = piVar3[7];
    *(uint *)(iVar2 + 0x14) = *(uint *)(iVar2 + 0x14) | 2;
  }
  *(undefined4 *)(iVar2 + 8) = _DAT_00001bec;
  return;
}


// ===== FUN_00982420 @ 00982420

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00982420(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  undefined8 uVar5;
  
  *(undefined4 *)(param_2 + 0x14) = param_4;
  iVar2 = _DAT_00004ed0;
  iVar1 = FUN_009823c4(_DAT_00004ed0);
  if (iVar1 != 0) {
    piVar3 = *(int **)(iVar2 + 4);
    iVar2 = FUN_009823c4(piVar3);
    if ((iVar2 != 0) && (*piVar3 == -0x4d6644)) {
      piVar4 = (int *)piVar3[5];
      uVar5 = FUN_009823c4(piVar4);
      piVar3 = (int *)((ulonglong)uVar5 >> 0x20);
      if (((int)uVar5 != 0) && (*piVar4 == -0x4d5f7c)) {
        *piVar3 = piVar4[3];
        piVar3[5] = 1;
      }
    }
  }
  piVar3 = _DAT_00004ed4;
  uVar5 = FUN_009823c4(_DAT_00004ed4);
  iVar2 = (int)((ulonglong)uVar5 >> 0x20);
  if (((int)uVar5 != 0) && (*piVar3 == -0x4dda98)) {
    *(int *)(iVar2 + 4) = piVar3[7];
    *(uint *)(iVar2 + 0x14) = *(uint *)(iVar2 + 0x14) | 2;
  }
  *(undefined4 *)(iVar2 + 8) = _DAT_00001bec;
  return;
}


// ===== FUN_009824f0 @ 009824f0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_009824f0(void)

{
  FUN_00982418();
  _DAT_009b4a8c = _DAT_009b4a84;
  _DAT_009b4a90 = _DAT_009b4a88;
  _DAT_009b4a98 = FUN_009823f0();
  _DAT_009b4a9c = _DAT_009b4a98;
  return;
}


// ===== FUN_00982520 @ 00982520

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00982520(int param_1,uint param_2)

{
  if (param_2 < 0x17 || param_1 != 0) {
    return;
  }
  _DAT_009b4a98 = FUN_009823f0();
  _DAT_009b4aa0 = _DAT_009b4aa0 + 1;
  return;
}


// ===== FUN_00982538 @ 00982538

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00982538(void)

{
  _DAT_009b4a98 = FUN_009823f0();
  _DAT_009b4aa0 = _DAT_009b4aa0 + 1;
  return;
}


// ===== FUN_0098255c @ 0098255c

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_0098255c(void)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int *piVar6;
  uint uVar7;
  int iVar8;
  bool bVar9;
  bool bVar10;
  
  iVar1 = _DAT_009b4a88;
  uVar5 = _DAT_009b4a84;
  iVar8 = _DAT_009b4a80;
  FUN_00982418();
  iVar2 = FUN_009823f0();
  uVar3 = iVar2 - _DAT_009b4abc;
  uVar4 = uVar3;
  if (9999 < uVar3) {
    uVar4 = 0;
  }
  uVar7 = iVar2 - _DAT_009b4a98;
  if (9999 < uVar3) {
    _DAT_009b4abc = iVar2;
    _DAT_009b4ac0 = uVar4;
    _DAT_009b4ac4 = uVar4;
  }
  bVar9 = uVar5 <= _DAT_009b4a84;
  if (_DAT_009b4a84 != uVar5) {
    bVar9 = 0x270e < uVar7;
  }
  if ((bVar9 && (_DAT_009b4a84 != uVar5 && uVar7 != 9999)) &&
     (_DAT_009b4ac0 = _DAT_009b4ac0 + 1, 9 < _DAT_009b4ac0)) {
    _DAT_009b4ab8 = _DAT_009b4ab8 | 2;
  }
  if ((_DAT_009b4a88 != iVar1 && 9999 < uVar7) &&
     (_DAT_009b4ac4 = _DAT_009b4ac4 + 1, 9 < _DAT_009b4ac4)) {
    _DAT_009b4ab8 = _DAT_009b4ab8 | 4;
  }
  if (((_DAT_009b4a80 != iVar8) || ((_DAT_009b4a84 != uVar5 && ((_DAT_009b4ab8 & 2) == 0)))) ||
     ((_DAT_009b4a88 != iVar1 && ((_DAT_009b4ab8 & 4) == 0)))) {
    _DAT_009b4a9c = iVar2;
  }
  uVar4 = iVar2 - _DAT_009b4a9c;
  uVar5 = uVar4;
  if (4999 < uVar4) {
    uVar5 = uVar7;
  }
  if (_DAT_009b4a80 == 0 && 4999 < uVar5) {
    _DAT_009b4a8c = _DAT_009b4a84;
    _DAT_009b4a90 = _DAT_009b4a88;
  }
  if (_DAT_009b4a80 == 0) {
    uVar5 = 0;
  }
  else {
    uVar5 = _DAT_009b4a94 & 1;
  }
  if ((((_DAT_009b4a94 & 2) != 0) && ((_DAT_009b4ab8 & 2) == 0)) && (_DAT_009b4a84 != _DAT_009b4a8c)
     ) {
    uVar5 = uVar5 | 2;
  }
  if (((_DAT_009b4ab8 & 4) == 0) && (_DAT_009b4a88 != _DAT_009b4a90)) {
    uVar5 = uVar5 | 4;
  }
  iVar8 = 2999;
  bVar10 = uVar7 < 4000;
  bVar9 = uVar7 == 4000;
  if (!bVar10) {
    bVar9 = uVar4 == 2999;
  }
  if ((bVar10 || uVar4 < 2999) || bVar9) {
    iVar8 = 1;
  }
  if ((!bVar10 && uVar4 >= 2999) && !bVar9) {
    iVar8 = 0;
  }
  uVar5 = uVar5 | iVar8 << 3;
  if (_DAT_009b4a94 != 3 || _DAT_009b4ab8 != 0) {
    bVar10 = uVar7 < 8000;
    bVar9 = uVar7 == 8000;
    if (!bVar10) {
      bVar9 = uVar4 == 5999;
    }
    if ((bVar10 || uVar4 < 5999) || bVar9) {
      uVar7 = 1;
    }
    if ((!bVar10 && uVar4 >= 5999) && !bVar9) {
      uVar7 = 0;
    }
    uVar5 = uVar5 | uVar7 << 3;
  }
  uVar4 = iVar2 - _DAT_009b4ad8;
  _DAT_009b4ad8 = iVar2;
  if (uVar4 < 1000) {
    uVar3 = 0;
    piVar6 = (int *)&DAT_009b4ac8;
    do {
      if ((uVar5 & 1 << (uVar3 & 0xff)) != 0) {
        *piVar6 = *piVar6 + uVar4;
      }
      uVar3 = uVar3 + 1;
      piVar6 = piVar6 + 1;
    } while (uVar3 != 4);
  }
  return uVar5;
}


// ===== FUN_0098275c @ 0098275c

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0098275c(code *param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  _DAT_009b4ab0 = _DAT_009b4ab0 + 1;
  iVar1 = FUN_0098255c();
  if (iVar1 == 0) {
    return;
  }
  iVar2 = FUN_009823f0();
  _DAT_009b4aa4 = _DAT_009b4aa4 + 1;
  _DAT_009b4ab4 = iVar1;
  while (iVar1 = FUN_0098255c(), iVar1 != 0) {
    (*param_1)(0x32);
  }
  iVar1 = FUN_009823f0();
  uVar3 = iVar1 - iVar2;
                    /* WARNING: Read-only address (ram,0x009b4aa8) is written */
  _DAT_009b4aa8 = _DAT_009b4aa8 + uVar3;
                    /* WARNING: Read-only address (ram,0x009b4aac) is written */
  if (_DAT_009b4aac < uVar3) {
    _DAT_009b4aac = uVar3;
  }
  return;
}


// ===== FUN_009827d8 @ 009827d8

void FUN_009827d8(int param_1,int param_2)

{
  uint uVar1;
  char *pcVar2;
  uint uVar3;
  
  pcVar2 = &DAT_009b4adc;
  for (uVar1 = 0; (*(char *)(param_1 + uVar1) != '\0' && (uVar1 != 0x3f)); uVar1 = uVar1 + 1) {
    *pcVar2 = *(char *)(param_1 + uVar1);
    pcVar2 = pcVar2 + 1;
  }
  pcVar2 = &UNK_009b4adf;
  (&DAT_009b4adc)[uVar1] = 0;
  for (uVar3 = 3; uVar3 < uVar1; uVar3 = uVar3 + 1) {
    if (*pcVar2 == '/') {
      *pcVar2 = '\0';
      if (param_2 != 0) {
        (*(code *)&SUB_ffae5b3c)(&DAT_009b4adc);
      }
      (*(code *)&SUB_ff96afb0)(&DAT_009b4adc);
      *pcVar2 = '/';
    }
    pcVar2 = pcVar2 + 1;
  }
  return;
}


// ===== FUN_009827dc @ 009827dc

void FUN_009827dc(int param_1,int param_2,undefined4 param_3,char *param_4)

{
  uint uVar1;
  char *pcVar2;
  uint uVar3;
  
  pcVar2 = param_4;
  for (uVar1 = 0; (*(char *)(param_1 + uVar1) != '\0' && (uVar1 != 0x3f)); uVar1 = uVar1 + 1) {
    *pcVar2 = *(char *)(param_1 + uVar1);
    pcVar2 = pcVar2 + 1;
  }
  pcVar2 = &UNK_009b4adf;
  param_4[uVar1] = '\0';
  for (uVar3 = 3; uVar3 < uVar1; uVar3 = uVar3 + 1) {
    if (*pcVar2 == '/') {
      *pcVar2 = '\0';
      if (param_2 != 0) {
        (*(code *)&SUB_ffae5b3c)(&DAT_009b4adc);
      }
      (*(code *)&SUB_ff96afb0)(&DAT_009b4adc);
      *pcVar2 = '/';
    }
    pcVar2 = pcVar2 + 1;
  }
  return;
}


// ===== FUN_0098287c @ 0098287c

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0098287c(void)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  pcVar1 = _DAT_009b4b24;
  _DAT_009b4ab0 = _DAT_009b4ab0 + 1;
  iVar2 = FUN_0098255c();
  if (iVar2 == 0) {
    return;
  }
  iVar3 = FUN_009823f0();
  _DAT_009b4aa4 = _DAT_009b4aa4 + 1;
  _DAT_009b4ab4 = iVar2;
  while (iVar2 = FUN_0098255c(), iVar2 != 0) {
    (*pcVar1)(0x32);
  }
  iVar2 = FUN_009823f0();
  uVar4 = iVar2 - iVar3;
                    /* WARNING: Read-only address (ram,0x009b4aa8) is written */
  _DAT_009b4aa8 = _DAT_009b4aa8 + uVar4;
                    /* WARNING: Read-only address (ram,0x009b4aac) is written */
  if (_DAT_009b4aac < uVar4) {
    _DAT_009b4aac = uVar4;
  }
  return;
}


// ===== FUN_0098288c @ 0098288c

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0098288c(undefined4 param_1)

{
  _DAT_009b4b24 = param_1;
  return;
}


// ===== FUN_0098289c @ 0098289c

/* WARNING: Control flow encountered bad instruction data */

void FUN_0098289c(void)

{
  FUN_0098287c();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_009828c0 @ 009828c0

void FUN_009828c0(undefined4 param_1)

{
  int iVar1;
  int *piVar2;
  
  FUN_0098287c();
  iVar1 = (*(code *)&SUB_ffae5b2c)(param_1);
  if (-1 < iVar1) {
    return;
  }
  FUN_009827d8(param_1,0);
  iVar1 = (*(code *)&SUB_ffae5b2c)(param_1);
  if (iVar1 < 0) {
    FUN_009827d8(param_1,1);
    iVar1 = (*(code *)&SUB_ffae5b2c)(param_1);
    if (iVar1 < 0) {
      piVar2 = (int *)&DAT_009b4b1c;
      goto LAB_00982920;
    }
  }
  piVar2 = (int *)&DAT_009b4b20;
LAB_00982920:
  *piVar2 = *piVar2 + 1;
  return;
}


// ===== FUN_0098293c @ 0098293c

undefined4 FUN_0098293c(undefined4 param_1,uint param_2,uint param_3)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  for (uVar4 = param_2 & 0xffffffe0; uVar4 < param_2 + param_3; uVar4 = uVar4 + 0x20) {
    coproc_moveto_Invalidate_Data_Cache_by_MVA(uVar4);
  }
  uVar4 = 0;
  coproc_moveto_Data_Synchronization(0);
  for (; uVar4 < param_3; uVar4 = uVar4 + iVar2) {
    FUN_0098287c();
    uVar3 = param_3 - uVar4;
    if (0x1ffff < uVar3) {
      uVar3 = 0x20000;
    }
    iVar2 = (*(code *)&SUB_ffae5b54)(param_1,param_2 + uVar4,uVar3);
    if (iVar2 < 1) break;
  }
  uVar1 = 0;
  if (uVar4 != param_3) {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}


// ===== FUN_009829b8 @ 009829b8

undefined4 FUN_009829b8(undefined4 param_1,uint param_2,uint param_3)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  for (uVar4 = param_2 & 0xffffffe0; uVar4 < param_2 + param_3; uVar4 = uVar4 + 0x20) {
    coproc_moveto_Clean_Data_Cache_by_MVA(uVar4);
  }
  uVar4 = 0;
  coproc_moveto_Data_Synchronization(0);
  for (; uVar4 < param_3; uVar4 = uVar4 + iVar2) {
    FUN_0098287c();
    uVar3 = param_3 - uVar4;
    if (0x1ffff < uVar3) {
      uVar3 = 0x20000;
    }
    iVar2 = (*(code *)&SUB_ffae5b6c)(param_1,param_2 + uVar4,uVar3);
    if (iVar2 < 1) break;
  }
  uVar1 = 0;
  if (uVar4 != param_3) {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}


// ===== FUN_00982a34 @ 00982a34

undefined4 FUN_00982a34(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  FUN_0098287c();
  iVar1 = (*(code *)&SUB_ffae5b60)(param_1,param_2,0);
  uVar2 = 0;
  if (param_2 != iVar1) {
    uVar2 = 0xffffffff;
  }
  return uVar2;
}


// ===== FUN_00982a68 @ 00982a68

/* WARNING: Control flow encountered bad instruction data */

void FUN_00982a68(void)

{
  FUN_0098287c();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00982a90 @ 00982a90

/* WARNING: Control flow encountered bad instruction data */

undefined4 FUN_00982a90(int param_1,int param_2)

{
  if (param_1 < 0) {
    return 0xffffffff;
  }
  FUN_0098287c();
  if (param_2 != 0) {
    (*(code *)&SUB_ffb4aa0c)(param_1,2,0);
    (*(code *)&SUB_ffb4aa0c)(param_1,0x15,0);
  }
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00982af0 @ 00982af0

/* WARNING: Control flow encountered bad instruction data */

void FUN_00982af0(void)

{
  FUN_0098287c();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00982b14 @ 00982b14

int FUN_00982b14(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_0098289c();
  if (iVar1 < 0) {
    return -1;
  }
  iVar2 = (*(code *)&SUB_ffb4aa0c)(iVar1,10,param_2);
  FUN_00982a90(iVar1,0);
  return -(uint)(iVar2 != 0);
}


// ===== FUN_00982b64 @ 00982b64

int FUN_00982b64(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = (*(code *)&SUB_ffb4aa0c)(param_1,2,0);
  if (iVar1 == 0) {
    iVar1 = (*(code *)&SUB_ffb4aa0c)(param_1,0x15);
    return -(uint)(iVar1 != 0);
  }
  return -1;
}


// ===== FUN_00982bac @ 00982bac

int FUN_00982bac(undefined4 param_1)

{
  int iVar1;
  
  FUN_0098287c();
  iVar1 = (*(code *)&SUB_ffae5b3c)(param_1);
  return -(uint)(iVar1 != 0);
}


// ===== FUN_00982bd8 @ 00982bd8

undefined4 FUN_00982bd8(void)

{
  int iVar1;
  
  iVar1 = FUN_0098289c();
  if (iVar1 < 0) {
    return 0;
  }
  FUN_00982a90(iVar1,0);
  return 1;
}


// ===== FUN_00982c00 @ 00982c00

undefined4 FUN_00982c00(undefined4 param_1,undefined4 param_2,uint param_3,uint *param_4)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  
  *param_4 = 0;
  iVar1 = FUN_0098289c();
  if (iVar1 < 0) {
    uVar4 = 0xffffffff;
  }
  else {
    uVar2 = FUN_00982a68();
    if (((param_3 < uVar2 || (int)uVar2 < 0) || (iVar3 = FUN_00982a34(iVar1,0), iVar3 != 0)) ||
       (iVar3 = FUN_0098293c(iVar1,param_2,uVar2), iVar3 != 0)) {
      uVar4 = 0xffffffff;
    }
    else {
      *param_4 = uVar2;
      uVar4 = 0;
    }
    FUN_00982a90(iVar1,0);
  }
  return uVar4;
}


// ===== FUN_00982c98 @ 00982c98

undefined4 FUN_00982c98(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar1 = FUN_009828c0();
  if (iVar1 < 0) {
    return 0xffffffff;
  }
  iVar2 = FUN_009829b8(iVar1,param_2,param_3);
  iVar1 = FUN_00982a90(iVar1,1);
  if (iVar1 == 0 && iVar2 == 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = 0xffffffff;
  }
  return uVar3;
}


// ===== FUN_00982ce4 @ 00982ce4

uint FUN_00982ce4(byte *param_1,int param_2)

{
  byte *pbVar1;
  byte *pbVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  
  pbVar2 = param_1 + param_2;
  uVar4 = 0xffffffff;
  if (param_1 == pbVar2) {
    return 0;
  }
  do {
    pbVar1 = param_1 + 1;
    uVar4 = uVar4 ^ *param_1;
    iVar3 = 8;
    do {
      uVar5 = 0;
      if ((uVar4 & 1) != 0) {
        uVar5 = 0xffffffff;
      }
      iVar3 = iVar3 + -1;
      uVar4 = uVar5 & 0xedb88320 ^ uVar4 >> 1;
    } while (iVar3 != 0);
    param_1 = pbVar1;
  } while (pbVar1 != pbVar2);
  return ~uVar4;
}


// ===== FUN_00982d3c @ 00982d3c

undefined4 FUN_00982d3c(undefined4 *param_1)

{
  return *param_1;
}


// ===== FUN_00982d44 @ 00982d44

void FUN_00982d44(undefined4 param_1,uint param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  iVar1 = FUN_0098289c();
  *param_3 = iVar1;
  if (iVar1 < 0) {
    return;
  }
  iVar1 = FUN_00982a68();
  if ((0xf < iVar1) && (iVar2 = FUN_00982a34(*param_3,0), iVar2 == 0)) {
    iVar2 = FUN_0098293c(*param_3,&DAT_009b4b40,0x10);
    if (((iVar2 == 0) && (((DAT_009b4b40 == 'L' && (DAT_009b4b41 == 'T')) && (DAT_009b4b42 == 'R')))
        ) && (DAT_009b4b43 == 'C')) {
      iVar2 = FUN_00982d3c(&DAT_009b4b44);
      param_3[1] = iVar2;
      uVar3 = FUN_00982d3c(&DAT_009b4b48);
      param_3[2] = uVar3;
      iVar2 = FUN_00982d3c(&DAT_009b4b4c);
      param_3[3] = iVar2;
      if ((uVar3 <= param_2) && (uVar3 + 0x10 == iVar1)) {
        return;
      }
    }
  }
  FUN_00982a90(*param_3,0);
  *param_3 = -1;
  return;
}


// ===== FUN_00982e28 @ 00982e28

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00982e28(undefined4 *param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar2;
  int iVar1;
  int iVar3;
  bool bVar4;
  int iVar5;
  
  iVar5 = param_1[3];
  _DAT_009b4b40 = 0x4352544c;
  _DAT_009b4b44 = iVar5 + 1;
  _DAT_009b4b48 = param_3;
  _DAT_009b4b4c = FUN_00982ce4(param_2,param_3);
  uVar2 = param_1[1];
  if (*(char *)(param_1 + 4) == '\0') {
    uVar2 = *param_1;
  }
  iVar1 = FUN_009828c0(uVar2);
  if (iVar1 < 0) {
    bVar4 = false;
  }
  else {
    iVar3 = FUN_009829b8(iVar1,&DAT_009b4b40,0x10);
    if (iVar3 == 0) {
      if (param_3 == 0) {
        bVar4 = true;
      }
      else {
        iVar3 = FUN_009829b8(iVar1,param_2,param_3);
        bVar4 = iVar3 == 0;
      }
    }
    else {
      bVar4 = false;
    }
    iVar1 = FUN_00982a90(iVar1,1);
    if (iVar1 != 0) {
      bVar4 = false;
    }
  }
  param_1[5] = param_1[5] + 1;
  if (bVar4) {
    param_1[3] = iVar5 + 1;
    *(byte *)(param_1 + 4) = *(byte *)(param_1 + 4) ^ 1;
    return 0;
  }
  param_1[6] = param_1[6] + 1;
  return 0xffffffff;
}


// ===== FUN_00982f20 @ 00982f20

undefined4 FUN_00982f20(undefined4 *param_1,undefined4 param_2,undefined4 param_3,uint *param_4)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  undefined4 uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint local_4c;
  uint local_48 [4];
  uint local_38;
  int local_34;
  
  FUN_00982d44(*param_1,param_3,local_48);
  FUN_00982d44(param_1[1],param_3,local_48 + 4);
  if ((int)(local_38 | local_48[0]) < 0) {
    uVar4 = ~local_38 >> 0x1f;
  }
  else if ((int)(local_34 - local_48[1]) < 1) {
    uVar4 = 0;
  }
  else {
    uVar4 = 1;
  }
  uVar5 = 0;
  do {
    uVar7 = uVar4 ^ uVar5;
    uVar9 = local_48[uVar7 * 4];
    if (-1 < (int)uVar9) {
      uVar8 = local_48[uVar7 * 4 + 2];
      iVar2 = FUN_0098293c(uVar9,param_2,uVar8);
      if (iVar2 == 0) {
        uVar3 = FUN_00982ce4(param_2,uVar8);
        bVar1 = local_48[uVar7 * 4 + 3] == uVar3;
      }
      else {
        bVar1 = false;
      }
      FUN_00982a90(uVar9,0);
      local_48[uVar7 * 4] = 0xffffffff;
      if (bVar1) {
        if (-1 < (int)local_48[(uVar7 ^ 1) * 4]) {
          FUN_00982a90(local_48[(uVar7 ^ 1) * 4],0);
        }
        *param_4 = uVar8;
        *(char *)((int)param_1 + 0x11) = (char)uVar5 + '\x01';
        uVar4 = local_48[uVar7 * 4 + 1];
        *(char *)(param_1 + 4) = (char)(uVar7 ^ 1);
        param_1[3] = uVar4;
        return 0;
      }
    }
    if (uVar5 == 1) {
      param_1[3] = 0;
      *(undefined2 *)(param_1 + 4) = 0;
      local_4c = 0;
      if ((param_1[2] == 0) ||
         (iVar2 = FUN_00982c00(param_1[2],param_2,param_3,&local_4c), iVar2 != 0)) {
        uVar6 = 0xffffffff;
        *param_4 = 0;
      }
      else {
        *param_4 = local_4c;
        *(undefined1 *)((int)param_1 + 0x11) = 3;
        FUN_00982e28(param_1,param_2);
        FUN_00982e28(param_1,param_2,local_4c);
        uVar6 = 0;
      }
      return uVar6;
    }
    uVar5 = 1;
  } while( true );
}


// ===== FUN_009830e8 @ 009830e8

void FUN_009830e8(undefined4 *param_1,undefined4 *param_2,uint param_3)

{
  undefined1 *puVar1;
  undefined4 *puVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  undefined4 *puVar6;
  
  if ((((uint)param_1 | (uint)param_2) & 3) == 0) {
    puVar2 = param_1;
    puVar6 = param_2;
    for (uVar4 = param_3; 0xf < uVar4; uVar4 = uVar4 - 0x10) {
      *puVar2 = *puVar6;
      puVar2[1] = puVar6[1];
      puVar2[2] = puVar6[2];
      puVar2[3] = puVar6[3];
      puVar2 = puVar2 + 4;
      puVar6 = puVar6 + 4;
    }
    uVar4 = param_3 & 0xfffffff0;
    param_3 = param_3 - uVar4;
    for (iVar5 = 0; 3 < param_3 + iVar5; iVar5 = iVar5 + -4) {
      *(undefined4 *)((int)param_1 + (uVar4 - iVar5)) =
           *(undefined4 *)((int)param_2 + (uVar4 - iVar5));
    }
    uVar3 = param_3 & 0xfffffffc;
    param_2 = (undefined4 *)((int)param_2 + uVar3 + uVar4);
    param_1 = (undefined4 *)((int)param_1 + uVar3 + uVar4);
    param_3 = param_3 - uVar3;
  }
  puVar1 = (undefined1 *)((int)param_1 - 1);
  puVar2 = (undefined4 *)((int)param_2 + param_3);
  for (; param_2 != puVar2; param_2 = (undefined4 *)((int)param_2 + 1)) {
    puVar1 = puVar1 + 1;
    *puVar1 = *(undefined1 *)param_2;
  }
  return;
}


// ===== FUN_0098319c @ 0098319c

void FUN_0098319c(undefined1 *param_1,uint param_2)

{
  uint uVar1;
  undefined4 *puVar2;
  undefined1 *puVar3;
  uint uVar4;
  uint uVar5;
  
  if (((uint)param_1 & 3) == 0) {
    param_1 = param_1 + 0x10;
    puVar3 = param_1;
    uVar5 = param_2;
    do {
      uVar5 = uVar5 - 0x10;
      *(undefined4 *)(puVar3 + -0x10) = 0;
      *(undefined4 *)(puVar3 + -0xc) = 0;
      *(undefined4 *)(puVar3 + -8) = 0;
      *(undefined4 *)(puVar3 + -4) = 0;
      puVar3 = puVar3 + 0x10;
    } while (0xf < uVar5);
    uVar4 = param_2 & 0xfffffff0;
    uVar1 = param_2 & 0xf;
    puVar2 = (undefined4 *)(param_1 + (uVar4 - 0x10));
    for (uVar5 = uVar1; 3 < uVar5; uVar5 = uVar5 - 4) {
      *puVar2 = 0;
      puVar2 = puVar2 + 1;
    }
    param_2 = 0;
    param_1 = (undefined1 *)(uVar1 + (int)(param_1 + (uVar4 - 0x10)));
  }
  puVar3 = param_1 + param_2;
  for (; param_1 != puVar3; param_1 = param_1 + 1) {
    *param_1 = 0;
  }
  return;
}


// ===== thunk_EXT_FUN_ffb2f664 @ 00983224

void thunk_EXT_FUN_ffb2f664(void)

{
  (*(code *)&LAB_ffb2f664)();
  return;
}


// ===== FUN_00983230 @ 00983230

/* WARNING: Control flow encountered bad instruction data */

void FUN_00983230(int param_1)

{
  if (param_1 != 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  return;
}


// ===== FUN_00983244 @ 00983244

undefined4 FUN_00983244(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 local_c;
  undefined4 uStack_8;
  
  local_c = 0;
  uStack_8 = param_3;
  (*(code *)&SUB_ffb1ff74)(&local_c);
  return local_c;
}


// ===== FUN_00983248 @ 00983248

undefined4 FUN_00983248(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 local_c;
  undefined4 uStack_8;
  
  local_c = param_4;
  uStack_8 = param_3;
  (*(code *)&SUB_ffb1ff74)(&local_c);
  return local_c;
}


// ===== FUN_0098326c @ 0098326c

void FUN_0098326c(void)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = 0x15;
  puVar2 = (undefined4 *)&DAT_009de84c;
  do {
    FUN_00983230(*puVar2);
    iVar1 = iVar1 + -1;
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  } while (iVar1 != 0);
  return;
}


// ===== FUN_00983298 @ 00983298

uint FUN_00983298(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(&DAT_009de84c + param_1 * 4);
  if (iVar1 == 0) {
    iVar1 = thunk_EXT_FUN_ffb2f664(param_2 + 0x20);
    *(int *)(&DAT_009de84c + param_1 * 4) = iVar1;
    if (iVar1 == 0) {
      return 0;
    }
  }
  return iVar1 + 0x1fU & 0xffffffe0;
}


// ===== FUN_009832dc @ 009832dc

void FUN_009832dc(int param_1,int param_2)

{
  int iVar1;
  
  for (iVar1 = 0; (*(char *)(param_2 + iVar1) != '\0' && (iVar1 != 0x2e)); iVar1 = iVar1 + 1) {
    *(char *)(param_1 + iVar1) = *(char *)(param_2 + iVar1);
  }
  *(undefined1 *)(param_1 + iVar1) = 0;
  if (iVar1 != 0) {
    *(undefined1 *)(param_1 + iVar1 + -1) = 0x44;
  }
  return;
}


// ===== FUN_0098331c @ 0098331c

uint FUN_0098331c(int param_1,int param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = thunk_EXT_FUN_ffb2f664(param_3 + 0x20);
  *(int *)(param_1 + param_2 * 4) = iVar1;
  uVar2 = 0;
  if (iVar1 != 0) {
    uVar2 = iVar1 + 0x1fU & 0xffffffe0;
  }
  return uVar2;
}


// ===== FUN_00983344 @ 00983344

bool FUN_00983344(int param_1,int param_2)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  
  pcVar3 = (char *)(param_1 + -1);
  pcVar2 = (char *)(param_2 + -1);
  do {
    pcVar3 = pcVar3 + 1;
    cVar1 = *pcVar3;
    pcVar2 = pcVar2 + 1;
    if (cVar1 == '\0') break;
  } while (cVar1 == *pcVar2);
  return cVar1 == *pcVar2;
}


// ===== FUN_00983374 @ 00983374

undefined4 FUN_00983374(undefined4 *param_1)

{
  return *param_1;
}


// ===== FUN_00983394 @ 00983394

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool FUN_00983394(undefined4 *param_1)

{
  int iVar1;
  
  if (_DAT_009b59a0 == 0) {
    return false;
  }
  if (DAT_009b8238 != '\0') {
    iVar1 = FUN_00983344(*param_1,&DAT_009b8238);
    if (iVar1 == 0) {
      return false;
    }
    iVar1 = FUN_00983344(param_1[1],&DAT_009b82d8);
    if (iVar1 == 0) {
      return false;
    }
    if ((param_1[3] == _DAT_009b5994) && (param_1[2] == _DAT_009b5998)) {
      return param_1[4] == _DAT_009b599c;
    }
  }
  return false;
}


// ===== FUN_00983430 @ 00983430

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00983430(uint param_1,int param_2,int *param_3,int *param_4,int *param_5)

{
  int iVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  
  if ((int)-(param_2 + (uint)(_DAT_009b83a8 < param_1)) < 0 ==
      (SBORROW4(0,param_2) != SBORROW4(-param_2,(uint)(_DAT_009b83a8 < param_1)))) {
    *param_4 = 0;
    *param_3 = 0;
  }
  else {
    iVar5 = _DAT_009b8384 - 1;
    if (param_2 < (int)(uint)(param_1 < *(uint *)(&DAT_009b8238 + (_DAT_009b8384 + 0x5b) * 4))) {
      puVar2 = (uint *)&DAT_009b83a8;
      iVar5 = 0;
      do {
        iVar1 = iVar5;
        puVar2 = puVar2 + 1;
        uVar6 = *puVar2;
        iVar5 = iVar1 + 1;
        if (_DAT_009b8384 <= iVar1 + 2U) break;
      } while ((int)(uint)(param_1 < uVar6) <= param_2);
      uVar3 = *(uint *)(&DAT_009b8238 + (iVar1 + 0x5c) * 4);
      uVar4 = -((int)-(uint)(uVar6 < uVar3) >> 0x1f);
      iVar7 = -(uint)(uVar6 < uVar3) + (uint)CARRY4(uVar4,uVar6 - uVar3);
      uVar4 = uVar4 + (uVar6 - uVar3) >> 1 | iVar7 * -0x80000000;
      uVar6 = (param_1 - uVar3) * 0x10;
      uVar6 = FUN_009a6904(uVar6 + uVar4,
                           ((param_2 - (uint)(param_1 < uVar3)) * 0x10 | param_1 - uVar3 >> 0x1c) +
                           (iVar7 >> 1) + (uint)CARRY4(uVar6,uVar4));
      if (uVar6 < 0x10) {
        if (uVar6 == 0) {
          iVar5 = iVar1;
        }
        *param_3 = iVar1;
        iVar1 = uVar6 << 0xc;
        *param_4 = iVar5;
        goto LAB_00983458;
      }
      *param_4 = iVar5;
      *param_3 = iVar5;
    }
    else {
      *param_4 = iVar5;
      *param_3 = iVar5;
    }
  }
  iVar1 = 0;
LAB_00983458:
  *param_5 = iVar1;
  return;
}


// ===== FUN_00983528 @ 00983528

void FUN_00983528(int param_1,uint param_2,undefined4 param_3)

{
  char cVar1;
  int iVar2;
  int iVar3;
  undefined1 *puVar4;
  char *pcVar5;
  char local_10 [4];
  undefined4 local_c;
  undefined4 uStack_8;
  
  uStack_8 = param_3;
  iVar2 = 0;
  iVar3 = 0;
  pcVar5 = &UNK_009b82d7;
  while( true ) {
    pcVar5 = pcVar5 + 1;
    cVar1 = *pcVar5;
    if ((cVar1 == '\0') || (iVar3 == 0x97)) break;
    if (cVar1 == '/') {
      iVar2 = iVar3;
    }
    *(char *)(param_1 + iVar3) = cVar1;
    iVar3 = iVar3 + 1;
  }
  cVar1 = (char)(param_2 / 10);
  local_10[1] = cVar1 + '0';
  local_10[0] = 0x53;
  local_10[2] = (char)param_2 + cVar1 * -10 + '0';
  local_10[3] = 0x2e;
  local_c = 0x505453;
  puVar4 = (undefined1 *)(param_1 + iVar2);
  pcVar5 = local_10;
  do {
    puVar4 = puVar4 + 1;
    *puVar4 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (puVar4 != (undefined1 *)(param_1 + 8 + iVar2));
  return;
}


// ===== FUN_009835d4 @ 009835d4

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_009835d4(uint param_1)

{
  uint uVar1;
  byte *pbVar2;
  int iVar3;
  
  uVar1 = _DAT_009b8464;
  pbVar2 = &DAT_009b5968;
  iVar3 = 0;
  while( true ) {
    if (_DAT_009b5964 == iVar3) {
      if (_DAT_009b5964 == 8) {
        return;
      }
      (&DAT_009b5968)[_DAT_009b5964 * 4] = (char)_DAT_009b8460;
      (&DAT_009b5969)[_DAT_009b5964 * 4] = (char)uVar1;
      (&DAT_009b596a)[_DAT_009b5964 * 4] = (char)param_1;
      _DAT_009b5964 = _DAT_009b5964 + 1;
      return;
    }
    if (((pbVar2[2] == param_1) && (*pbVar2 == _DAT_009b8460)) && (pbVar2[1] == _DAT_009b8464))
    break;
    iVar3 = iVar3 + 1;
    pbVar2 = pbVar2 + 4;
  }
  return;
}


// ===== FUN_009835d8 @ 009835d8

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_009835d8(uint param_1,undefined4 param_2,int param_3)

{
  byte *pbVar1;
  uint uVar2;
  int iVar3;
  
  uVar2 = *(uint *)(param_3 + 0x22c);
  pbVar1 = &DAT_009b5968;
  iVar3 = 0;
  while( true ) {
    if (_DAT_009b5964 == iVar3) {
      if (_DAT_009b5964 == 8) {
        return;
      }
      (&DAT_009b5968)[_DAT_009b5964 * 4] = (char)*(uint *)(param_3 + 0x228);
      (&DAT_009b5969)[_DAT_009b5964 * 4] = (char)uVar2;
      (&DAT_009b596a)[_DAT_009b5964 * 4] = (char)param_1;
      _DAT_009b5964 = _DAT_009b5964 + 1;
      return;
    }
    if (((pbVar1[2] == param_1) && ((uint)*pbVar1 == *(uint *)(param_3 + 0x228))) &&
       (pbVar1[1] == uVar2)) break;
    iVar3 = iVar3 + 1;
    pbVar1 = pbVar1 + 4;
  }
  return;
}


// ===== FUN_00983660 @ 00983660

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool FUN_00983660(int param_1,int *param_2)

{
  if (((_DAT_009b5940 == 0x3153544c) &&
      (_DAT_009b5944 == (_DAT_009b8460 | param_1 << 0x10 | _DAT_009b8464 << 8 | 0x41000000))) &&
     (_DAT_009b5948 == *param_2)) {
    return _DAT_009b594c == param_2[1];
  }
  return false;
}


// ===== FUN_009836d4 @ 009836d4

void FUN_009836d4(undefined4 param_1)

{
  (*(code *)&SUB_ffb1828c)(param_1,1000);
  return;
}


// ===== FUN_009836e4 @ 009836e4

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_009836e4(void)

{
  while (_DAT_009b5918 == 1 || _DAT_009b58fc == 1) {
    FUN_009836d4(_DAT_009b58f4);
  }
  return;
}


// ===== FUN_00983710 @ 00983710

void FUN_00983710(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  FUN_009836e4();
  puVar2 = (undefined4 *)(param_1 + -4);
  do {
    puVar2 = puVar2 + 1;
    FUN_00983230(*puVar2);
  } while (puVar2 != (undefined4 *)(param_1 + 0x18));
  FUN_0098319c(param_1,0x3c);
  iVar1 = 0x15;
  puVar2 = (undefined4 *)&DAT_009de84c;
  do {
    FUN_00983230(*puVar2);
    iVar1 = iVar1 + -1;
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  } while (iVar1 != 0);
  return;
}


// ===== FUN_00983748 @ 00983748

void FUN_00983748(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_00983244();
  if ((uint)(iVar1 - param_1[6]) < 100) {
    return;
  }
  (**(code **)*param_1)(1);
  iVar2 = FUN_00983244();
  param_1[6] = iVar2;
  *(int *)(param_1[1] + 0xc0) = (*(int *)(param_1[1] + 0xc0) - iVar1) + iVar2;
  return;
}


// ===== FUN_0098379c @ 0098379c

void FUN_0098379c(int param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  
  iVar1 = (**(code **)(param_4 + 0x30))(*(undefined4 *)(param_4 + 0xc));
  if (iVar1 != 0) {
    *(undefined4 *)(*(int *)(param_1 + 4) + 0x174) = 1;
  }
  return;
}


// ===== FUN_009837c4 @ 009837c4

undefined4 FUN_009837c4(undefined4 *param_1,uint param_2,undefined4 *param_3,uint param_4)

{
  uint uVar1;
  undefined4 *puVar2;
  int iVar3;
  uint *puVar4;
  
  puVar4 = (uint *)*param_1;
  if ((param_2 <= puVar4[1]) && (param_4 <= puVar4[1] - param_2)) {
    uVar1 = *puVar4;
LAB_00983828:
    uVar1 = uVar1 + param_2 & 0xfffffff | 0x10000000;
    if ((((uint)param_3 | param_4 | uVar1) & 3) == 0) {
      puVar2 = (undefined4 *)((int)param_3 + (param_4 & 0xfffffffc));
      iVar3 = uVar1 - (int)param_3;
      for (; puVar2 != param_3; param_3 = param_3 + 1) {
        *param_3 = *(undefined4 *)(iVar3 + (int)param_3);
      }
    }
    else {
      puVar2 = (undefined4 *)((int)param_3 + param_4);
      iVar3 = uVar1 - (int)param_3;
      for (; param_3 != puVar2; param_3 = (undefined4 *)((int)param_3 + 1)) {
        *(undefined1 *)param_3 = *(undefined1 *)(iVar3 + (int)param_3);
      }
    }
    return 0;
  }
  if (((int *)param_1[1] != (int *)0x0) && (iVar3 = *(int *)param_1[1], iVar3 - 1U < param_2)) {
    uVar1 = param_2 - iVar3;
    if ((uVar1 <= puVar4[3]) && (param_4 <= (iVar3 + puVar4[3]) - param_2)) {
      param_2 = puVar4[2];
      goto LAB_00983828;
    }
  }
  return 0xffffffff;
}


// ===== FUN_00983890 @ 00983890

void FUN_00983890(void)

{
  if (-1 < DAT_009b4920) {
    FUN_00982a90(DAT_009b4920,0);
  }
  DAT_009b4920 = 0xffffffff;
  return;
}


// ===== FUN_009838bc @ 009838bc

undefined4 FUN_009838bc(int param_1,int param_2,undefined4 param_3,int param_4)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  if (param_2 == *(int *)(param_1 + 0x10)) {
    uVar3 = 1;
  }
  else {
    uVar3 = 0;
    if (*(int *)(param_1 + 0xc) != param_2) {
      uVar3 = 0xffffffff;
    }
  }
  if (param_2 == *(int *)(param_1 + 0x14)) {
    uVar3 = 2;
  }
  else if (uVar3 == 0xffffffff) {
    uVar3 = (uint)(*(uint *)(param_1 + 0x1c) < *(uint *)(param_1 + 0x18));
    if (*(uint *)(param_1 + 0x20) < *(uint *)(param_1 + (uVar3 + 6) * 4)) {
      uVar3 = 2;
    }
    uVar1 = *(undefined4 *)(param_1 + uVar3 * 4);
    *(int *)(*(int *)(param_1 + 0x34) + 0x18) = *(int *)(*(int *)(param_1 + 0x34) + 0x18) + 1;
    iVar2 = FUN_00982a34(uVar1,param_2);
    if (iVar2 != 0) {
      *(int *)(*(int *)(param_1 + 0x34) + 0x1c) = *(int *)(*(int *)(param_1 + 0x34) + 0x1c) + 1;
      return 0xffffffff;
    }
  }
  iVar4 = param_1 + uVar3 * 4;
  iVar2 = *(int *)(param_1 + 0x24) + 1;
  *(int *)(param_1 + 0x24) = iVar2;
  *(int *)(iVar4 + 0x18) = iVar2;
  iVar2 = FUN_0098293c(*(undefined4 *)(param_1 + uVar3 * 4),param_3);
  if (iVar2 == 0) {
    *(int *)(iVar4 + 0xc) = param_2 + param_4;
    uVar1 = 0;
  }
  else {
    uVar1 = 0xffffffff;
    *(int *)(*(int *)(param_1 + 0x34) + 0x1c) = *(int *)(*(int *)(param_1 + 0x34) + 0x1c) + 1;
    *(undefined4 *)(iVar4 + 0xc) = 0xffffffff;
  }
  return uVar1;
}


// ===== FUN_009839bc @ 009839bc

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_009839bc(int param_1,uint param_2,undefined4 param_3,uint param_4)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined *puVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  
  uVar7 = param_2 + param_4;
  if ((*(int *)(param_1 + 0x2c) != 0) && (uVar7 <= *(uint *)(param_1 + 0x30))) {
    FUN_009830e8(param_3,*(int *)(param_1 + 0x2c) + param_2,param_4,*(uint *)(param_1 + 0x30),
                 param_1,param_2,param_3);
    return 0;
  }
  uVar8 = 2;
  *(int *)(*(int *)(param_1 + 0x34) + 0x14) = *(int *)(*(int *)(param_1 + 0x34) + 0x14) + 1;
  iVar2 = FUN_00983244();
  puVar4 = &DAT_009b58f0;
  uVar5 = 0;
  while( true ) {
    iVar6 = uVar5 * 0x1c;
    if ((((*(int *)(&DAT_009b58fc + iVar6) != 0) && (*(int *)(puVar4 + 0x20) == param_1)) &&
        (*(uint *)(&DAT_009b5900 + iVar6) == param_2)) &&
       (param_4 <= *(uint *)(&DAT_009b5904 + iVar6))) {
      uVar8 = uVar5;
    }
    puVar4 = puVar4 + 0x1c;
    if (uVar5 == 1) break;
    uVar5 = 1;
  }
  if (uVar8 < 2) {
    iVar6 = uVar8 * 0x1c;
    while (*(int *)(&DAT_009b58fc + iVar6) == 1) {
      FUN_009836d4(_DAT_009b58f4);
    }
    iVar3 = *(int *)(&UNK_009b590c + iVar6);
    if (iVar3 == 0) {
      FUN_009830e8(param_3,*(undefined4 *)(&DAT_009b5914 + iVar6),param_4);
    }
    iVar6 = *(int *)(param_1 + 0x34);
    *(undefined4 *)(&DAT_009b58fc + uVar8 * 0x1c) = 0;
    *(int *)(iVar6 + 0x24) = *(int *)(iVar6 + 0x24) + 1;
  }
  else {
    FUN_009836e4();
    if ((param_1 == _DAT_009b5910) && (_DAT_009b5900 < param_2)) {
      _DAT_009b58fc = 0;
    }
    if ((param_1 == _DAT_009b592c) && (_DAT_009b591c < param_2)) {
      _DAT_009b5918 = 0;
    }
    iVar3 = FUN_009838bc(param_1,param_2,param_3,param_4);
  }
  if ((((iVar3 == 0) && (_DAT_009b58f8 != 0)) && (param_4 - 0x8000 < 0x8001)) &&
     (uVar7 < *(uint *)(param_1 + 0x28))) {
    if ((_DAT_009b58fc != 0) || (iVar6 = 0, _DAT_009b5914 == 0)) {
      if ((_DAT_009b5918 != 0) || (_DAT_009b5930 == 0)) goto LAB_00983bdc;
      iVar6 = 1;
    }
    uVar8 = *(uint *)(param_1 + 0x28) - uVar7;
    if (0xffff < uVar8) {
      uVar8 = 0x10000;
    }
    iVar6 = iVar6 * 0x1c;
    *(uint *)(&DAT_009b5900 + iVar6) = uVar7;
    *(uint *)(&DAT_009b5904 + iVar6) = uVar8;
    *(int *)(&DAT_009b5910 + iVar6) = param_1;
    _DAT_009b5934 = _DAT_009b5934 + 1;
    *(int *)(&DAT_009b5908 + iVar6) = _DAT_009b5934;
    uVar1 = _DAT_009b58f0;
    *(undefined4 *)(&DAT_009b58fc + iVar6) = 1;
    (*(code *)&SUB_ffb18430)(uVar1);
  }
LAB_00983bdc:
  iVar6 = FUN_00983244();
  *(int *)(*(int *)(param_1 + 0x34) + 0x28) =
       (*(int *)(*(int *)(param_1 + 0x34) + 0x28) - iVar2) + iVar6;
                    /* WARNING: Read-only address (ram,0x009b5900) is written */
                    /* WARNING: Read-only address (ram,0x009b5910) is written */
  return iVar3;
}


// ===== FUN_00983c04 @ 00983c04

uint FUN_00983c04(undefined4 param_1,int param_2,char *param_3)

{
  int iVar1;
  int iVar2;
  int local_60;
  int local_5c;
  int local_58;
  int local_54;
  uint local_50;
  char local_4c;
  char local_4b;
  char local_4a;
  char local_49;
  undefined1 auStack_40 [48];
  
  FUN_009832dc(auStack_40,param_1);
  iVar1 = FUN_0098289c(auStack_40);
  if (-1 < iVar1) {
    iVar2 = FUN_0098293c(iVar1,&local_60,0x20);
    if ((((((iVar2 == 0) && (local_60 == 0x31444148)) && (local_5c == param_2)) &&
         ((local_58 == 0x168 && (local_54 == 0xd5)))) &&
        ((local_50 < 0x101 && ((local_4c == *param_3 && (local_4b == param_3[1])))))) &&
       ((local_4a == param_3[2] && (local_49 == param_3[3])))) {
      DAT_009b4920 = iVar1;
      DAT_009b4924 = 0;
      DAT_009b4928 = 0xffffffff;
      DAT_009b492c = 0xffffffff;
      DAT_009b4930 = 0xffffffff;
      DAT_009b4934 = 0xffffffff;
      return local_50;
    }
    FUN_00982a90(iVar1,0);
  }
  return 0xffffffff;
}


// ===== FUN_00983d0c @ 00983d0c

int FUN_00983d0c(int *param_1,int param_2,int param_3)

{
  bool bVar1;
  int iVar2;
  undefined *puVar3;
  int **ppiVar4;
  uint uVar5;
  char *pcVar6;
  undefined1 *puVar7;
  char *pcVar8;
  int *piStack_20;
  int iStack_1c;
  
  piStack_20 = param_1;
  iStack_1c = param_2;
  iVar2 = FUN_0098289c(param_2);
  uVar5 = 0;
  *param_1 = iVar2;
  param_1[1] = 0;
  param_1[2] = 0;
  if (-1 < iVar2) {
    for (; *(char *)(param_2 + uVar5) != '\0'; uVar5 = uVar5 + 1) {
    }
    if (0xd < uVar5) {
      if (param_3 != 0) {
        iVar2 = -0xe;
      }
      else {
        iVar2 = -8;
      }
      if (param_3 != 0) {
        puVar3 = &DAT_009a6bc4;
      }
      else {
        puVar3 = &DAT_009a6bc9;
      }
      FUN_0098943c(param_1 + 3,puVar3,param_2 + uVar5 + iVar2);
      puVar7 = &DAT_009a8b44;
      if (param_3 != 0) {
        puVar7 = &DAT_009a8b4c;
      }
      iVar2 = FUN_00982a34(*param_1,0);
      if ((iVar2 == 0) && (iVar2 = FUN_0098293c(*param_1,&piStack_20,8), iVar2 == 0)) {
        pcVar8 = puVar7 + -1;
        bVar1 = true;
        ppiVar4 = &piStack_20;
        pcVar6 = pcVar8;
        do {
          pcVar6 = pcVar6 + 1;
          if (*pcVar6 != *(char *)ppiVar4) {
            bVar1 = false;
          }
          ppiVar4 = (int **)((int)ppiVar4 + 1);
        } while (pcVar6 != puVar7 + 7);
        if (!bVar1) {
          FUN_0098948c(&piStack_20,8,0,param_1 + 3);
          iVar2 = 1;
          ppiVar4 = &piStack_20;
          do {
            pcVar8 = pcVar8 + 1;
            if (*pcVar8 != *(char *)ppiVar4) {
              iVar2 = 0;
            }
            ppiVar4 = (int **)((int)ppiVar4 + 1);
          } while (pcVar8 != puVar7 + 7);
          param_1[2] = iVar2;
        }
      }
      iVar2 = *param_1;
    }
  }
  return iVar2;
}


// ===== FUN_00983e48 @ 00983e48

undefined4 FUN_00983e48(undefined4 *param_1,int param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  param_1[1] = param_2;
  iVar1 = FUN_00982a34(*param_1);
  if ((iVar1 == 0) && (iVar1 = FUN_0098293c(*param_1,param_3,param_4), iVar1 == 0)) {
    if (param_1[2] != 0) {
      FUN_0098948c(param_3,param_4,param_2,param_1 + 3);
    }
    param_1[1] = param_2 + param_4;
    uVar2 = 0;
  }
  else {
    uVar2 = 0xfffffffd;
  }
  return uVar2;
}


// ===== FUN_00983ec0 @ 00983ec0

undefined4 FUN_00983ec0(undefined4 param_1,int param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  
  puVar1 = DAT_00983f08;
  iVar2 = FUN_00983e48(param_1,*(int *)(DAT_00983f04 + param_2 * 4 + 0x23c) + 8,DAT_00983f08);
  if (iVar2 == 0) {
    *param_3 = *puVar1;
    param_3[1] = puVar1[1];
    uVar3 = 0;
  }
  else {
    uVar3 = 0xfffffffd;
  }
  return uVar3;
}


// ===== FUN_00983ec4 @ 00983ec4

undefined4 FUN_00983ec4(undefined4 param_1,int param_2,undefined4 *param_3,int param_4)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  
  puVar1 = DAT_00983f08;
  iVar2 = FUN_00983e48(param_1,*(int *)(param_4 + param_2 * 4 + 0x23c) + 8,DAT_00983f08);
  if (iVar2 == 0) {
    *param_3 = *puVar1;
    param_3[1] = puVar1[1];
    uVar3 = 0;
  }
  else {
    uVar3 = 0xfffffffd;
  }
  return uVar3;
}


// ===== FUN_00983f64 @ 00983f64

undefined4 FUN_00983f64(void)

{
  int iVar1;
  undefined4 uVar2;
  
  DAT_009b4940 = 0;
  DAT_009b4938 = FUN_009828c0();
  if (DAT_009b4938 < 0) {
    DAT_009b493c = 1;
    uVar2 = 0xffffffff;
  }
  else {
    iVar1 = FUN_009829b8(DAT_009b4938,&DAT_009a8b1c);
    if (iVar1 == 0) {
      DAT_009b493c = 0;
      uVar2 = 0;
    }
    else {
      DAT_009b493c = 1;
      uVar2 = 0xffffffff;
    }
  }
  return uVar2;
}


// ===== FUN_00983f68 @ 00983f68

undefined4 FUN_00983f68(void)

{
  int iVar1;
  undefined4 in_r3;
  undefined4 uVar2;
  
  DAT_009b4940 = in_r3;
  DAT_009b4938 = FUN_009828c0();
  if (DAT_009b4938 < 0) {
    DAT_009b493c = 1;
    uVar2 = 0xffffffff;
  }
  else {
    iVar1 = FUN_009829b8(DAT_009b4938,&DAT_009a8b1c);
    if (iVar1 == 0) {
      DAT_009b493c = 0;
      uVar2 = 0;
    }
    else {
      DAT_009b493c = 1;
      uVar2 = 0xffffffff;
    }
  }
  return uVar2;
}


// ===== FUN_00983fbc @ 00983fbc

void FUN_00983fbc(int param_1)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0x18) != 0) {
    if (*(int *)(param_1 + 0x20) < 0) goto LAB_0098402c;
    iVar1 = FUN_00982a34(*(int *)(param_1 + 0x20),*(int *)(param_1 + 0x14) * 0x438 + 0x36d8);
    if ((iVar1 != 0) ||
       (iVar1 = FUN_009829b8(*(undefined4 *)(param_1 + 0x20),*(undefined4 *)(param_1 + 0x34)),
       iVar1 != 0)) {
      FUN_00982a90(*(undefined4 *)(param_1 + 0x20),0);
      *(undefined4 *)(param_1 + 0x20) = 0xffffffff;
      goto LAB_0098402c;
    }
  }
  if (-1 < *(int *)(param_1 + 0x20)) {
    *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + *(int *)(param_1 + 0x18);
  }
LAB_0098402c:
  *(undefined4 *)(param_1 + 0x18) = 0;
  return;
}


// ===== FUN_00983fc0 @ 00983fc0

void FUN_00983fc0(int param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  
  if (param_4 != 0) {
    if (*(int *)(param_1 + 0x20) < 0) goto LAB_0098402c;
    iVar1 = FUN_00982a34(*(int *)(param_1 + 0x20),*(int *)(param_1 + 0x14) * 0x438 + 0x36d8);
    if ((iVar1 != 0) ||
       (iVar1 = FUN_009829b8(*(undefined4 *)(param_1 + 0x20),*(undefined4 *)(param_1 + 0x34)),
       iVar1 != 0)) {
      FUN_00982a90(*(undefined4 *)(param_1 + 0x20),0);
      *(undefined4 *)(param_1 + 0x20) = 0xffffffff;
      goto LAB_0098402c;
    }
  }
  if (-1 < *(int *)(param_1 + 0x20)) {
    *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + *(int *)(param_1 + 0x18);
  }
LAB_0098402c:
  *(undefined4 *)(param_1 + 0x18) = 0;
  return;
}


// ===== FUN_00984058 @ 00984058

undefined4
FUN_00984058(undefined4 param_1,undefined4 param_2,undefined1 *param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  undefined4 local_30;
  undefined4 uStack_2c;
  undefined4 local_28;
  undefined4 uStack_24;
  undefined4 local_20;
  undefined1 local_1c;
  undefined1 local_1b;
  undefined1 local_1a;
  undefined1 local_19;
  undefined4 local_18;
  undefined4 local_14;
  
  local_1c = *param_3;
  local_28 = 0x168;
  uStack_24 = 0xd5;
  local_1b = param_3[1];
  local_1a = param_3[2];
  local_19 = param_3[3];
  local_18 = DAT_009b4940;
  local_30 = 0x324c4148;
  local_14 = 0;
  iVar1 = DAT_009b493c;
  uStack_2c = param_2;
  local_20 = param_4;
  if (-1 < DAT_009b4938) {
    if (DAT_009b493c == 0) {
      iVar1 = FUN_00982a34(DAT_009b4938,0);
      if (iVar1 == 0) {
        iVar2 = FUN_009829b8(DAT_009b4938,&local_30,0x20);
        iVar1 = 0;
        if (iVar2 != 0) {
          iVar1 = 1;
        }
      }
      else {
        iVar1 = 1;
      }
    }
    iVar2 = FUN_00982a90(DAT_009b4938,1);
    if (iVar2 != 0) goto LAB_0098411c;
  }
  if (iVar1 == 0) {
    DAT_009b4938 = 0xffffffff;
    return 0;
  }
LAB_0098411c:
  DAT_009b4938 = 0xffffffff;
  FUN_00982bac(param_1);
  return 0xffffffff;
}


// ===== FUN_0098413c @ 0098413c

void FUN_0098413c(undefined4 *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  while (iVar1 = FUN_0098255c(), iVar1 != 0) {
    *(int *)(param_1[1] + 0xb4) = *(int *)(param_1[1] + 0xb4) + 0x14;
    (**(code **)*param_1)(0x14);
    uVar2 = FUN_00983244();
    param_1[6] = uVar2;
  }
  return;
}


// ===== FUN_0098417c @ 0098417c

bool FUN_0098417c(int *param_1)

{
  int iVar1;
  code *pcVar2;
  
  FUN_0098413c();
  pcVar2 = *(code **)(*param_1 + 4);
  if (pcVar2 != (code *)0x0) {
    (*pcVar2)(*(undefined4 *)(*param_1 + 0xc),2,0);
  }
  FUN_00983748(param_1);
  pcVar2 = *(code **)(*param_1 + 0x14);
  if (pcVar2 == (code *)0x0) {
    return false;
  }
  iVar1 = (*pcVar2)(*(undefined4 *)(*param_1 + 0xc));
  if (iVar1 != 0) {
    *(undefined4 *)(param_1[1] + 0x174) = 1;
  }
  return iVar1 != 0;
}


// ===== FUN_009841e4 @ 009841e4

void FUN_009841e4(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  code *pcVar4;
  undefined4 uVar5;
  
  FUN_0098413c();
  param_1[3] = param_1[3] + 0x40;
  iVar1 = FUN_00983244();
  pcVar4 = *(code **)(*param_1 + 4);
  if (pcVar4 != (code *)0x0) {
    uVar5 = *(undefined4 *)(*param_1 + 0xc);
    uVar2 = 0;
    if (param_1[4] != 0) {
      uVar2 = FUN_009a5bf0(param_1[3] * 100,param_1[4]);
    }
    (*pcVar4)(uVar5,1,uVar2);
  }
  iVar3 = FUN_00983244();
  *(int *)(param_1[1] + 0xbc) = (*(int *)(param_1[1] + 0xbc) - iVar1) + iVar3;
  iVar1 = FUN_00983244();
  if ((uint)(iVar1 - param_1[6]) < 100) {
    return;
  }
  (**(code **)*param_1)(1);
  iVar3 = FUN_00983244();
  param_1[6] = iVar3;
  *(int *)(param_1[1] + 0xc0) = (*(int *)(param_1[1] + 0xc0) - iVar1) + iVar3;
  return;
}


// ===== FUN_0098426c @ 0098426c

void FUN_0098426c(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  uVar3 = param_2;
  iVar1 = FUN_00983244();
  FUN_00996450(*param_1,param_2,param_3,param_4,param_5,uVar3);
  iVar2 = FUN_00983244();
  *(int *)(param_1[1] + 0xb8) = (iVar2 + *(int *)(param_1[1] + 0xb8)) - iVar1;
  return;
}


// ===== FUN_009842cc @ 009842cc

void FUN_009842cc(undefined4 param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined4 *puVar5;
  
  iVar4 = 0;
  puVar5 = &DAT_009b4920 + (param_2 & 1);
  iVar2 = param_2 * 0xb400 + 0x20;
  while( true ) {
    uVar3 = *(int *)(&DAT_009de84c + iVar4 + (param_2 & 1) * 4) + 0x1fU & 0xffffffe0;
    if (param_2 != puVar5[2]) {
      FUN_009836e4();
      if (((DAT_009b4920 < 0) || (iVar1 = FUN_00982a34(DAT_009b4920,iVar2), iVar1 != 0)) ||
         (iVar1 = FUN_0098293c(DAT_009b4920,uVar3,0x5a00), iVar1 != 0)) {
        FUN_0098319c(uVar3,0x5a00);
        DAT_009b4924 = 1;
      }
      puVar5[2] = param_2;
    }
    *(uint *)(&DAT_009de810 + iVar4 + param_2 * 4) = uVar3;
    puVar5 = puVar5 + 2;
    iVar2 = iVar2 + 0x5a00;
    if (iVar4 == 0x1c) break;
    iVar4 = 0x1c;
  }
  return;
}


// ===== FUN_00984394 @ 00984394

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00984394(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  
  if (param_1[1] == 0) {
    return 0;
  }
  *(int *)(param_1[2] + 0x8c) = *(int *)(param_1[2] + 0x8c) + 1;
  iVar1 = FUN_009829b8(*param_1,_DAT_009b58ec);
  iVar2 = param_1[2];
  if (iVar1 == 0) {
    *(int *)(iVar2 + 0x88) = *(int *)(iVar2 + 0x88) + param_1[1];
    param_1[1] = 0;
    return 0;
  }
  *(int *)(iVar2 + 0x90) = *(int *)(iVar2 + 0x90) + 1;
  return 0xffffffff;
}


// ===== FUN_009843a4 @ 009843a4

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_009843a4(undefined4 *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  *(int *)(param_2 + 0x8c) = *(int *)(param_2 + 0x8c) + 1;
  iVar1 = FUN_009829b8(*param_1,_DAT_009b58ec);
  iVar2 = param_1[2];
  if (iVar1 == 0) {
    *(int *)(iVar2 + 0x88) = *(int *)(iVar2 + 0x88) + param_1[1];
    param_1[1] = 0;
    return 0;
  }
  *(int *)(iVar2 + 0x90) = *(int *)(iVar2 + 0x90) + 1;
  return 0xffffffff;
}


// ===== FUN_0098440c @ 0098440c

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0098440c(int param_1,int param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  
  while( true ) {
    if (param_3 == 0) {
      return 0;
    }
    uVar2 = 0x4000 - *(int *)(param_1 + 4);
    if (param_3 <= uVar2) {
      uVar2 = param_3;
    }
    FUN_009830e8(_DAT_009b58ec + *(int *)(param_1 + 4),param_2,uVar2);
    iVar1 = uVar2 + *(int *)(param_1 + 4);
    *(int *)(param_1 + 4) = iVar1;
    if ((iVar1 == 0x4000) && (iVar1 = FUN_00984394(param_1), iVar1 != 0)) break;
    param_2 = param_2 + uVar2;
    param_3 = param_3 - uVar2;
  }
  return 0xffffffff;
}


// ===== FUN_00984490 @ 00984490

void FUN_00984490(int param_1)

{
  int iVar1;
  ushort uVar2;
  undefined1 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  iVar5 = 0;
  iVar4 = param_1;
  do {
    iVar6 = 0;
    iVar1 = iVar5 * 2;
    uVar2 = *(ushort *)(*(int *)(param_1 + 0x28) + iVar1);
    do {
      uVar3 = (undefined1)iVar4;
      if (uVar2 == 0) {
        uVar3 = 0;
      }
      iVar4 = iVar6 * 4;
      if (uVar2 != 0) {
        uVar3 = FUN_009a5bf0((uint)(uVar2 >> 1) +
                             *(int *)(*(int *)(param_1 + 0x24) + iVar4 + iVar5 * 0xc));
      }
      *(undefined1 *)(*(int *)(param_1 + 0x30) + iVar6 + iVar5 * 3) = uVar3;
      iVar6 = iVar6 + 1;
      iVar4 = *(int *)(param_1 + 0x24) + iVar4;
      *(undefined4 *)(iVar4 + iVar5 * 0xc) = 0;
    } while (iVar6 != 3);
    iVar6 = 0;
    iVar5 = iVar5 + 1;
    *(undefined2 *)(*(int *)(param_1 + 0x28) + iVar1) = 0;
  } while (iVar5 != 0x2d0);
  if ((*(int *)(param_1 + 0x18) != 0) &&
     (iVar6 = *(int *)(param_1 + 0x10), iVar6 != *(int *)(param_1 + 0x18) + *(int *)(param_1 + 0x14)
     )) {
    FUN_00983fbc(param_1);
  }
  iVar4 = *(int *)(param_1 + 0x18);
  if (iVar4 == 0) {
    iVar6 = *(int *)(param_1 + 0x10);
  }
  if (iVar4 == 0) {
    *(int *)(param_1 + 0x14) = iVar6;
  }
  FUN_00995d2c(*(undefined4 *)(param_1 + 0x30),iVar4 * 0x438 + *(int *)(param_1 + 0x34));
  iVar4 = *(int *)(param_1 + 0x18) + 1;
  *(int *)(param_1 + 0x18) = iVar4;
  if (iVar4 != 0x10) {
    return;
  }
  if (*(int *)(param_1 + 0x18) != 0) {
    if (*(int *)(param_1 + 0x20) < 0) goto LAB_0098402c;
    iVar4 = FUN_00982a34(*(int *)(param_1 + 0x20),*(int *)(param_1 + 0x14) * 0x438 + 0x36d8);
    if ((iVar4 != 0) ||
       (iVar4 = FUN_009829b8(*(undefined4 *)(param_1 + 0x20),*(undefined4 *)(param_1 + 0x34)),
       iVar4 != 0)) {
      FUN_00982a90(*(undefined4 *)(param_1 + 0x20),0);
      *(undefined4 *)(param_1 + 0x20) = 0xffffffff;
      goto LAB_0098402c;
    }
  }
  if (-1 < *(int *)(param_1 + 0x20)) {
    *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + *(int *)(param_1 + 0x18);
  }
LAB_0098402c:
  *(undefined4 *)(param_1 + 0x18) = 0;
  return;
}


// ===== FUN_009845bc @ 009845bc

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool FUN_009845bc(int param_1,int param_2)

{
  int iVar1;
  bool bVar2;
  
  if (*(code **)(param_1 + 0x17c1c) == FUN_00984d20) {
    *(undefined4 *)(param_1 + 0x17c1c) = _DAT_009de790;
    *(undefined4 *)(param_1 + 0x17c20) = _DAT_009de794;
    if ((param_2 != 0) && (-1 < _DAT_009de7a0)) {
      FUN_00984490(&DAT_009de790);
    }
    FUN_00983fbc(&DAT_009de790);
    iVar1 = _DAT_009de7ac;
    bVar2 = -1 < _DAT_009de7b0;
    if (bVar2) {
      FUN_00982a90(_DAT_009de7b0,1);
    }
    bVar2 = bVar2 && iVar1 == 0xd5;
    _DAT_009de7b0 = -1;
  }
  else {
    bVar2 = false;
  }
  return bVar2;
}


// ===== FUN_009845c8 @ 009845c8

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool FUN_009845c8(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  bool bVar2;
  
  if (param_3 == param_4) {
    *(undefined4 *)(param_1 + 0xc1c) = _DAT_009de790;
    *(undefined4 *)(param_1 + 0xc20) = _DAT_009de794;
    if ((param_2 != 0) && (-1 < _DAT_009de7a0)) {
      FUN_00984490(&DAT_009de790);
    }
    FUN_00983fbc(&DAT_009de790);
    iVar1 = _DAT_009de7ac;
    bVar2 = -1 < _DAT_009de7b0;
    if (bVar2) {
      FUN_00982a90(_DAT_009de7b0,1);
    }
    bVar2 = bVar2 && iVar1 == 0xd5;
    _DAT_009de7b0 = -1;
  }
  else {
    bVar2 = false;
  }
  return bVar2;
}


// ===== FUN_00984650 @ 00984650

int FUN_00984650(int param_1,uint param_2)

{
  return (param_2 & 0x1f) * 0x2d0 + *(int *)(&DAT_009de810 + (param_1 * 7 + (param_2 >> 5)) * 4);
}


// ===== FUN_00984674 @ 00984674

void FUN_00984674(uint param_1,int param_2)

{
  int iVar1;
  short *psVar2;
  int iVar3;
  undefined2 *puVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  uint uVar12;
  undefined2 *puVar13;
  bool bVar14;
  undefined2 local_30;
  short local_2e;
  short local_2c;
  undefined2 local_2a;
  
  bVar14 = param_1 == 6;
  if (param_1 < 7) {
    bVar14 = DAT_009b493c == 0;
  }
  if (bVar14) {
    uVar7 = 0;
    if (param_1 == 6) {
      iVar10 = 0x15;
    }
    else {
      iVar10 = 0x20;
    }
    iVar1 = param_1 * 0x20;
    if (param_2 == 0) {
      uVar9 = 0x168;
      uVar12 = 0;
    }
    else {
      uVar12 = 0x168;
      uVar9 = uVar7;
      while( true ) {
        iVar11 = iVar1;
        do {
          iVar3 = FUN_00984650(uVar7);
          psVar2 = (short *)(iVar3 + -2);
          uVar5 = 0;
          do {
            psVar2 = psVar2 + 1;
            uVar6 = uVar5 + 1;
            if (*psVar2 != 0) {
              if (uVar5 <= uVar12) {
                uVar12 = uVar5;
              }
              if (uVar9 <= uVar5) {
                uVar9 = uVar6;
              }
            }
            uVar5 = uVar6;
          } while (uVar6 != 0x168);
          iVar11 = iVar11 + 1;
        } while (iVar10 + iVar1 != iVar11);
        if (uVar7 == 1) break;
        uVar7 = 1;
      }
      if (uVar9 <= uVar12) {
        return;
      }
    }
    local_2e = (short)uVar12;
    local_2c = (short)uVar9 - local_2e;
    local_30 = (undefined2)param_1;
    local_2a = (undefined2)iVar10;
    FUN_009836e4();
    DAT_009b493c = FUN_009829b8(DAT_009b4938,&local_30);
    iVar11 = 0;
    uVar9 = uVar9 - uVar12;
    while (DAT_009b493c == 0) {
      iVar3 = FUN_00984650(iVar11,iVar1);
      if (param_2 != 0) {
        iVar8 = 0;
        uVar7 = uVar12;
        do {
          uVar5 = 0;
          puVar4 = (undefined2 *)(iVar3 + iVar8 * 2);
          puVar13 = (undefined2 *)(iVar3 + uVar7 * 2);
          do {
            uVar5 = uVar5 + 1;
            *puVar4 = *puVar13;
            puVar4 = puVar4 + 1;
            puVar13 = puVar13 + 1;
          } while (uVar5 < uVar9);
          uVar7 = uVar7 + 0x168;
          iVar8 = iVar8 + uVar9;
        } while (iVar10 * 0x168 + uVar12 != uVar7);
      }
      DAT_009b493c = FUN_009829b8(DAT_009b4938,iVar3,iVar10 * uVar9 * 2);
      if (iVar11 == 1) break;
      iVar11 = 1;
    }
    DAT_009b4940 = DAT_009b4940 + 1;
  }
  return;
}


// ===== FUN_00984820 @ 00984820

void FUN_00984820(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  uint uVar5;
  
  if (param_2 == -1) {
    return;
  }
  FUN_00984674(param_2,1);
  if (param_2 == 6) {
    iVar4 = 0x15;
  }
  else {
    iVar4 = 0x20;
  }
  uVar5 = iVar4 * 0x2d0;
  uVar1 = FUN_00984650(0,param_2 << 5);
  FUN_0098319c(uVar1,uVar5);
  puVar2 = (undefined4 *)FUN_00984650(1,param_2 << 5);
  if (((uint)puVar2 & 3) == 0) {
    puVar3 = puVar2 + 4;
    do {
      uVar5 = uVar5 - 0x10;
      puVar3[-4] = 0;
      puVar3[-3] = 0;
      puVar3[-2] = 0;
      puVar3[-1] = 0;
      puVar3 = puVar3 + 4;
    } while (0xf < uVar5);
    puVar2 = puVar2 + 4 + iVar4 * 0xb4 + -4;
    puVar3 = puVar2;
    for (uVar5 = 0; 3 < uVar5; uVar5 = uVar5 - 4) {
      *puVar3 = 0;
      puVar3 = puVar3 + 1;
    }
    uVar5 = 0;
  }
  puVar3 = (undefined4 *)((int)puVar2 + uVar5);
  for (; puVar2 != puVar3; puVar2 = (undefined4 *)((int)puVar2 + 1)) {
    *(undefined1 *)puVar2 = 0;
  }
  return;
}


// ===== FUN_00984828 @ 00984828

void FUN_00984828(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  uint uVar5;
  
  FUN_00984674(param_2,1);
  if (param_2 == 6) {
    iVar4 = 0x15;
  }
  else {
    iVar4 = 0x20;
  }
  uVar5 = iVar4 * 0x2d0;
  uVar1 = FUN_00984650(0,param_2 << 5);
  FUN_0098319c(uVar1,uVar5);
  puVar2 = (undefined4 *)FUN_00984650(1,param_2 << 5);
  if (((uint)puVar2 & 3) == 0) {
    puVar3 = puVar2 + 4;
    do {
      uVar5 = uVar5 - 0x10;
      puVar3[-4] = 0;
      puVar3[-3] = 0;
      puVar3[-2] = 0;
      puVar3[-1] = 0;
      puVar3 = puVar3 + 4;
    } while (0xf < uVar5);
    puVar2 = puVar2 + 4 + iVar4 * 0xb4 + -4;
    puVar3 = puVar2;
    for (uVar5 = 0; 3 < uVar5; uVar5 = uVar5 - 4) {
      *puVar3 = 0;
      puVar3 = puVar3 + 1;
    }
    uVar5 = 0;
  }
  puVar3 = (undefined4 *)((int)puVar2 + uVar5);
  for (; puVar2 != puVar3; puVar2 = (undefined4 *)((int)puVar2 + 1)) {
    *(undefined1 *)puVar2 = 0;
  }
  return;
}


// ===== FUN_0098487c @ 0098487c

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_0098487c(undefined4 param_1,int param_2,char *param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  ushort *puVar6;
  uint uVar7;
  ushort *puVar8;
  ushort uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  ushort local_50;
  ushort local_4e;
  ushort local_4c;
  ushort local_4a;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  uint local_38;
  char local_34;
  char local_33;
  char local_32;
  char local_31;
  uint local_30;
  
  iVar1 = FUN_0098289c();
  if (-1 < iVar1) {
    iVar2 = FUN_0098293c(iVar1,&local_48,0x20);
    if (((((((iVar2 == 0) && (local_48 == 0x324c4148)) && (local_44 == param_2)) &&
          ((local_40 == 0x168 && (local_3c == 0xd5)))) &&
         ((local_34 == *param_3 && ((local_33 == param_3[1] && (local_32 == param_3[2])))))) &&
        (local_31 == param_3[3])) && (local_38 < 0x101)) {
      iVar2 = 0;
      while( true ) {
        iVar4 = 0;
        do {
          uVar3 = FUN_00984650(iVar2,iVar4);
          iVar4 = iVar4 + 1;
          FUN_0098319c(uVar3,0x2d0);
        } while (iVar4 != 0xd5);
        if (iVar2 == 1) break;
        iVar2 = 1;
      }
      iVar2 = thunk_EXT_FUN_ffb2f664(0x5a20);
      if (iVar2 == 0) {
        uVar11 = 1;
        uVar12 = 0;
      }
      else {
        uVar12 = iVar2 + 0x1fU & 0xffffffe0;
        uVar11 = (uint)(uVar12 == 0);
      }
    }
    else {
      uVar12 = 0;
      uVar11 = 1;
      iVar2 = 0;
    }
    uVar13 = 0;
    while ((uVar13 < local_30 && (uVar11 == 0))) {
      iVar4 = FUN_0098293c(iVar1,&local_50,8);
      if ((iVar4 == 0) && (local_50 < 7)) {
        if (local_50 == 6) {
          uVar9 = 0x15;
        }
        else {
          uVar9 = 0x20;
        }
        if ((local_4a != uVar9) || (local_4c == 0)) goto LAB_00984a0c;
        uVar11 = (uint)(0x168 < (uint)local_4e + (uint)local_4c);
        for (iVar4 = 0; uVar11 == 0 && iVar4 != 2; iVar4 = iVar4 + 1) {
          uVar11 = FUN_0098293c(iVar1,uVar12,(uint)local_4c * (uint)local_4a * 2);
          uVar14 = 0;
          while ((uVar14 < local_4a && (uVar11 == 0))) {
            iVar5 = FUN_00984650(iVar4,uVar14 + (uint)local_50 * 0x20);
            uVar7 = 0;
            puVar6 = (ushort *)(iVar5 + (uint)local_4e * 2);
            puVar8 = (ushort *)(uVar12 + uVar14 * local_4c * 2);
            while (uVar7 < local_4c) {
              uVar7 = uVar7 + 1;
              uVar10 = (uint)*puVar6 + (uint)*puVar8;
              if (0xffff < (uint)*puVar6 + (uint)*puVar8) {
                uVar10 = 0xffff;
              }
              *puVar6 = (ushort)uVar10;
              puVar6 = puVar6 + 1;
              puVar8 = puVar8 + 1;
            }
            uVar14 = uVar14 + 1;
          }
        }
      }
      else {
LAB_00984a0c:
        uVar11 = 1;
      }
      uVar13 = uVar13 + 1;
    }
    FUN_00983230(iVar2);
    FUN_00982a90(iVar1,0);
    if (uVar11 == 0) {
      _DAT_009de848 = 0;
      return local_38;
    }
  }
  return 0xffffffff;
}


// ===== FUN_00984b10 @ 00984b10

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00984b10(int param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5)

{
  undefined2 uVar1;
  int iVar2;
  char *pcVar3;
  undefined2 *puVar4;
  uint uVar5;
  
  uVar5 = 0;
  pcVar3 = &DAT_009b4b60;
  do {
    if (*(char *)(param_2 + uVar5) == '\0') {
      (&DAT_009b4b60)[uVar5] = 0;
      if (uVar5 < 4) {
        return;
      }
LAB_00984b3c:
      if ((&UNK_009b4b5c)[uVar5] != '.') {
        return;
      }
      (&UNK_009b4b5d)[uVar5] = 0x59;
      (&UNK_009b4b5e)[uVar5] = 0x55;
      (&UNK_009b4b5f)[uVar5] = 0x56;
      iVar2 = FUN_00983298(0x14,0x8460);
      if (iVar2 == 0) {
        return;
      }
      _DAT_009de7b0 = FUN_00982af0(&DAT_009b4b60);
      if (_DAT_009de7b0 < 0) {
        return;
      }
      _DAT_009de7b8 = iVar2 + 0x21c0;
      _DAT_009de7bc = iVar2 + 0x2760;
      _DAT_009de7c0 = iVar2 + 0x3870;
      _DAT_009de7c4 = iVar2 + 0x40e0;
      _DAT_009de7b4 = iVar2;
      FUN_0098319c(iVar2,0x2760);
      puVar4 = (undefined2 *)(_DAT_009de7bc + -2);
      for (iVar2 = 0; iVar2 != param_3; iVar2 = iVar2 + 1) {
        uVar1 = FUN_009a5bf0(iVar2 * 0x2d0,param_3);
        puVar4 = puVar4 + 1;
        *puVar4 = uVar1;
      }
                    /* WARNING: Read-only address (ram,0x009de798) is written */
      _UNK_009de798 = param_5;
                    /* WARNING: Read-only address (ram,0x009de7a0) is written */
      _DAT_009de7a0 = 0xffffffff;
                    /* WARNING: Read-only address (ram,0x009de7a8) is written */
      _UNK_009de7a8 = 0;
                    /* WARNING: Read-only address (ram,0x009de7ac) is written */
      _DAT_009de7ac = 0;
      _DAT_009de790 = *(undefined4 *)(param_1 + 0x17c1c);
                    /* WARNING: Read-only address (ram,0x009de79c) is written */
                    /* WARNING: Read-only address (ram,0x009de790) is written */
      _DAT_009de794 = *(undefined4 *)(param_1 + 0x17c20);
      _UNK_009de79c = param_4;
      *(undefined **)(param_1 + 0x17c20) = &DAT_009de790;
                    /* WARNING: Read-only address (ram,0x009de794) is written */
      *(code **)(param_1 + 0x17c1c) = FUN_00984d20;
      return;
    }
    if (uVar5 == 0x2f) {
      DAT_009b4b8f = 0;
      goto LAB_00984b3c;
    }
    *pcVar3 = *(char *)(param_2 + uVar5);
    uVar5 = uVar5 + 1;
    pcVar3 = pcVar3 + 1;
  } while( true );
}


// ===== FUN_00984c7c @ 00984c7c

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00984c7c(void)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  do {
    FUN_009836d4(_DAT_009b58f0);
    while( true ) {
      iVar2 = 0;
      iVar3 = 2;
      while( true ) {
        if (*(int *)(&DAT_009b58fc + iVar2 * 0x1c) == 1) {
          if (iVar3 == 2) {
            iVar3 = iVar2;
          }
          else if (*(uint *)(&DAT_009b5908 + iVar2 * 0x1c) < *(uint *)(&DAT_009b5908 + iVar3 * 0x1c)
                  ) {
            iVar3 = iVar2;
          }
        }
        if (iVar2 == 1) break;
        iVar2 = 1;
      }
      if (iVar3 == 2) break;
      iVar3 = iVar3 * 0x1c;
      uVar1 = FUN_009838bc(*(undefined4 *)(&DAT_009b5910 + iVar3),
                           *(undefined4 *)(&DAT_009b5900 + iVar3),
                           *(undefined4 *)(&DAT_009b5914 + iVar3),
                           *(undefined4 *)(&DAT_009b5904 + iVar3));
      *(undefined4 *)(&UNK_009b590c + iVar3) = uVar1;
      *(undefined4 *)(&DAT_009b58fc + iVar3) = 2;
      (*(code *)&SUB_ffb18430)(_DAT_009b58f4);
    }
  } while( true );
}


// ===== FUN_00984d20 @ 00984d20

void FUN_00984d20(undefined4 *param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  byte *pbVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  int iVar8;
  int iVar9;
  
  puVar7 = param_1;
  iVar8 = param_3;
  iVar9 = param_3;
  for (iVar5 = 0; iVar5 != iVar8; iVar5 = iVar5 + 1) {
    iVar1 = FUN_009a5bf0(param_1[2] * 0xd5,param_1[3],param_3,iVar8,puVar7,iVar8,iVar9);
    if (param_1[4] != iVar1) {
      if (-1 < (int)param_1[4]) {
        FUN_00984490(param_1);
      }
      param_1[4] = iVar1;
    }
    pbVar3 = *(byte **)(param_2 + iVar5 * 4);
    for (param_3 = 0; param_3 != param_4; param_3 = param_3 + 1) {
      uVar4 = (uint)*(ushort *)(param_1[0xb] + param_3 * 2);
      iVar6 = param_1[9];
      iVar1 = uVar4 * 0xc;
      iVar2 = iVar6 + iVar1;
      *(uint *)(iVar6 + iVar1) = *(int *)(iVar6 + iVar1) + (uint)*pbVar3;
      iVar1 = uVar4 * 2;
      *(uint *)(iVar2 + 4) = *(int *)(iVar2 + 4) + (uint)pbVar3[1];
      *(uint *)(iVar2 + 8) = *(int *)(iVar2 + 8) + (uint)pbVar3[2];
      *(short *)(param_1[10] + iVar1) = *(short *)(param_1[10] + iVar1) + 1;
      pbVar3 = pbVar3 + 3;
    }
    param_1[2] = param_1[2] + 1;
  }
  if ((code *)*param_1 == (code *)0x0) {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x00984d74. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)*param_1)(param_1[1],param_2,iVar5,param_4);
  return;
}


// ===== FUN_00984e3c @ 00984e3c

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00984e3c(undefined4 param_1,int *param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  int iVar9;
  int *piVar10;
  undefined1 local_d8;
  undefined1 local_d7;
  undefined1 local_d6;
  undefined1 local_d5;
  undefined1 auStack_d4 [8];
  int local_cc;
  undefined1 auStack_c8 [164];
  
  FUN_00983528(auStack_c8,param_1);
  iVar1 = FUN_0098289c(auStack_c8);
  if (iVar1 < 0) {
LAB_00984e74:
    uVar7 = 0xffffffff;
  }
  else {
    iVar2 = FUN_0098293c(iVar1,&DAT_009b5940,0x20);
    if (iVar2 == 0) {
      uVar3 = FUN_00983660(param_1,param_2);
      iVar2 = -(uVar3 ^ 1);
    }
    else {
      iVar2 = -1;
    }
    local_d8 = 0x53;
    local_d7 = (undefined1)_DAT_009b8460;
    iVar8 = *param_2;
    local_d6 = (undefined1)_DAT_009b8464;
    local_d5 = (undefined1)param_1;
    FUN_0098943c(auStack_d4,&local_d8,&DAT_009b8378);
    local_cc = iVar8;
    if (iVar2 == 0) {
      piVar10 = (int *)&DAT_009b4be4;
      iVar6 = 0;
      iVar2 = 0;
      iVar8 = 0;
      do {
        if (param_3 == 0) {
          iVar9 = *piVar10;
        }
        else {
          iVar9 = param_3;
        }
        iVar4 = FUN_0098293c(iVar1,iVar9,0x4204);
        if (iVar4 != 0) {
          iVar9 = -2;
          break;
        }
        FUN_0098948c(iVar9,0x4204,iVar6,auStack_d4);
        piVar5 = (int *)(iVar9 + -4);
        do {
          piVar5 = piVar5 + 1;
          iVar8 = iVar8 + *piVar5;
          iVar2 = iVar2 + iVar8;
        } while ((int *)(iVar9 + 0x4200) != piVar5);
        if (param_3 != 0) {
          FUN_00999fb0(*piVar10,iVar9,0x1081,param_4);
        }
        iVar6 = iVar6 + 0x4204;
        piVar10 = piVar10 + 1;
        iVar9 = 0;
      } while (iVar6 != 0x10c304);
    }
    else {
      iVar2 = 0;
      iVar9 = -1;
      iVar8 = iVar2;
    }
    FUN_00982a90(iVar1,0);
    if (iVar9 == 0) {
      if ((*param_2 == iVar8) && (param_2[1] == iVar2)) {
        _DAT_009b598c = _DAT_009b598c + 1;
        return 0;
      }
    }
    else if (iVar9 != -2) goto LAB_00984e74;
    _DAT_009b5988 = _DAT_009b5988 + 1;
    iVar1 = FUN_009828c0(auStack_c8);
    if (-1 < iVar1) {
      FUN_00982a90(iVar1,1);
    }
    FUN_009835d4(param_1);
    uVar7 = 0xfffffffe;
  }
  return uVar7;
}


// ===== FUN_00985044 @ 00985044

void FUN_00985044(undefined4 *param_1,undefined4 *param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  
  local_1c = 0;
  local_18 = 0;
  local_14 = 0;
  iVar1 = (*(code *)&SUB_ffb2f750)(&local_1c,&local_18,param_3,&SUB_ffb2f750,param_1);
  if (iVar1 != 0) {
    local_18 = 0;
  }
  iVar1 = (*(code *)&SUB_ffb2f734)(&local_14);
  if (iVar1 != 0) {
    local_14 = 0;
  }
  *param_1 = local_18;
  *param_2 = local_14;
  return;
}


// ===== FUN_009850b0 @ 009850b0

void FUN_009850b0(uint param_1,uint param_2)

{
  uint local_10;
  uint local_c;
  
  local_10 = param_1;
  local_c = param_2;
  FUN_00985044(&local_10,&local_c);
  *(uint *)(param_1 + 0x1a4) = local_c >> 10 & 0xffff | (local_10 >> 10) << 0x10;
  return;
}


// ===== FUN_009850ec @ 009850ec

undefined4 FUN_009850ec(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int local_48 [14];
  
  piVar3 = local_48;
  iVar2 = 0;
  do {
    iVar1 = FUN_00983298(iVar2,0x5a00);
    *piVar3 = iVar1;
    if (iVar1 == 0) {
      FUN_009850b0(param_1);
      FUN_0098326c();
      return 0xfffffff9;
    }
    iVar2 = iVar2 + 1;
    piVar3 = piVar3 + 1;
  } while (iVar2 != 0xe);
  FUN_00994d88(&DAT_009de810,local_48);
  return 0;
}


// ===== FUN_00985158 @ 00985158

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00985158(int *param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  uint local_28;
  uint local_24 [2];
  
  if ((param_2 == 0) || ((*param_1 == 0 && (param_1[1] == 0)))) {
    if (_DAT_009b58f8 == 0) {
      uVar1 = (*(code *)&SUB_ffb17ea0)("LatentAheadWork",0);
      uVar2 = (*(code *)&SUB_ffb17ea0)("LatentAheadDone",0);
      if (((uVar1 != 0) && (uVar2 != 0)) && (((uVar1 | uVar2) & 1) == 0)) {
        _DAT_009b58f0 = uVar1;
        _DAT_009b58f4 = uVar2;
        (*(code *)&SUB_ffb18b40)("LatentRead",0x1e,0x1000,FUN_00984c7c,0);
        _DAT_009b58f8 = 1;
      }
    }
    FUN_009836e4();
    _DAT_009b58fc = 0;
    _DAT_009b5914 = 0;
    _DAT_009b5918 = 0;
    _DAT_009b5930 = 0;
    if (((param_2 != 0) && (_DAT_009b58f8 != 0)) &&
       ((FUN_00985044(&local_28,local_24), 0xb603f < local_28 && (0x1001f < local_24[0])))) {
      _DAT_009b5914 = FUN_0098331c(param_1,0,0x10000);
      if (_DAT_009b5914 != 0) {
        _DAT_009b5930 = FUN_0098331c(param_1,1,0x10000);
      }
    }
  }
  return;
}


// ===== FUN_009852b0 @ 009852b0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_009852b0(void)

{
  uint uVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)&DAT_009b8580;
  for (uVar1 = 0; uVar1 < _DAT_009b857c; uVar1 = uVar1 + 1) {
    FUN_00983230(*puVar2);
    puVar2 = puVar2 + 1;
  }
  _DAT_009b857c = 0;
  _DAT_009de8a4 = 0;
  _DAT_009de8ac = 0;
  _DAT_009de8a8 = 0;
  DAT_009b4944 = 0xffffffff;
  _DAT_009de8a0 = 0;
  _DAT_009b8220 = 0;
  return;
}


// ===== FUN_0098533c @ 0098533c

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_0098533c(int param_1,int *param_2)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  char *pcVar8;
  undefined *puVar9;
  byte *pbVar10;
  char *pcVar11;
  undefined *puVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  uint uVar17;
  uint *puVar18;
  undefined4 *puVar19;
  uint uVar20;
  uint uVar21;
  uint uVar22;
  uint uVar23;
  uint uVar24;
  uint uVar25;
  byte *pbVar26;
  bool bVar27;
  bool bVar28;
  undefined8 uVar29;
  undefined8 uVar30;
  uint local_68;
  char *local_58;
  undefined1 auStack_40 [28];
  
  iVar3 = FUN_00983394(param_2);
  if (iVar3 != 0) {
    return 0;
  }
  _DAT_009b59a0 = 0;
  iVar3 = FUN_00983d0c(auStack_40,*param_2,0);
  if (iVar3 < 0) {
    DAT_009b8238 = 0;
    *(int *)(param_1 + 4) = iVar3;
    return iVar3;
  }
  iVar4 = FUN_00983344(*param_2,&DAT_009b8238);
  if (iVar4 == 0) {
    FUN_009852b0();
    iVar15 = *param_2;
    DAT_009b8238 = 0;
    iVar4 = FUN_00983e48(auStack_40,0,&DAT_009b6d20,0x40);
    if (iVar4 == 0) {
      pcVar11 = "LTPACK2";
      pcVar8 = &DAT_009b6d20;
      iVar4 = 0;
      do {
        if (*pcVar8 != *pcVar11) goto LAB_009854b0;
        iVar4 = iVar4 + 1;
        pcVar8 = pcVar8 + 1;
        pcVar11 = pcVar11 + 1;
      } while (iVar4 != 8);
      uVar22 = FUN_00983374(&UNK_009b6d28);
      _DAT_009b8394 = uVar22;
      iVar4 = FUN_00983374(&UNK_009b6d2c);
      if (((iVar4 == 0x41) && (iVar4 = FUN_00983374(&UNK_009b6d30), iVar4 == 8000)) &&
         (iVar4 = FUN_00983374(&UNK_009b6d34), iVar4 == 0x7a12)) {
        puVar9 = &UNK_009b6d37;
        local_58 = &DAT_009b8238;
        iVar4 = 0;
        puVar12 = &UNK_009b8377;
        do {
          puVar9 = puVar9 + 1;
          iVar4 = iVar4 + 1;
          puVar12 = puVar12 + 1;
          *puVar12 = *puVar9;
        } while (iVar4 != 8);
        DAT_009b8380 = 0;
        _DAT_009b8384 = (uint)_DAT_009b6d40;
        uVar17 = (uint)_DAT_009b6d42;
        uVar21 = (uint)_DAT_009b6d44;
        uVar24 = (uint)_DAT_009b6d46;
        _DAT_009b8388 = uVar17;
        _DAT_009b838c = uVar21;
        _DAT_009b8390 = uVar24;
        iVar4 = FUN_00983374(&UNK_009b6d48);
        _DAT_009b8398 = iVar4;
        iVar16 = FUN_00983374(&UNK_009b6d4c);
        iVar5 = FUN_00983374(&UNK_009b6d50);
        iVar6 = FUN_00983374(&UNK_009b6d54);
        _DAT_009b839c = FUN_00983374(&UNK_009b6d58);
        uVar29 = FUN_00983374(&UNK_009b6d5c);
        iVar14 = (int)((ulonglong)uVar29 >> 0x20);
        _DAT_009b83a0 = (int)uVar29;
        uVar25 = uVar17 - 1;
        bVar28 = 0xe < uVar25;
        bVar27 = uVar25 == 0xf;
        if (uVar25 < 0x10) {
          bVar28 = 0x1e < iVar14 - 1U;
          bVar27 = iVar14 - 1U == 0x1f;
        }
        if ((uVar24 < 0x11 && (uVar21 - 1 < 0x10 && (!bVar28 || bVar27))) &&
           (iVar4 == uVar21 * uVar17 * iVar14)) {
          if (uVar24 == 0) {
            iVar13 = 0;
          }
          else {
            iVar13 = uVar24 * uVar21 * uVar17;
          }
          if ((iVar16 == iVar13) &&
             (iVar14 = iVar14 * 4 + 0x40 + (uVar17 + 3 & 0xfffffffc) + (uVar21 + 3 & 0xfffffffc) +
                       (uVar24 + 3 & 0xfffffffc),
             _DAT_009b83a0 == 0x13002 && iVar16 * 4 + iVar4 * 8 + iVar14 == uVar22)) {
            iVar4 = 0;
            local_68 = 0;
            for (uVar22 = 0x40; uVar22 < _DAT_009b8394; uVar22 = uVar22 + uVar24) {
              uVar24 = _DAT_009b8394 - uVar22;
              if (0x14ff < uVar24) {
                uVar24 = 0x1500;
              }
              iVar16 = FUN_00983e48(auStack_40,uVar22,&DAT_009b6d20,uVar24);
              uVar21 = _DAT_009b8384;
              if (iVar16 != 0) goto LAB_009853e4;
              if (uVar22 == 0x40) {
                puVar9 = &DAT_009b6d20;
                puVar19 = (undefined4 *)&DAT_009b83a4;
                for (uVar17 = 0; uVar25 = _DAT_009b8388, uVar17 != uVar21; uVar17 = uVar17 + 1) {
                  uVar29 = FUN_00983374(puVar9);
                  puVar19 = puVar19 + 1;
                  *puVar19 = (int)uVar29;
                  puVar9 = (undefined *)((int)((ulonglong)uVar29 >> 0x20) + 4);
                }
                puVar12 = &UNK_009b8427;
                puVar9 = &DAT_009b6d20 + uVar17 * 4;
                for (uVar21 = 0; uVar20 = _DAT_009b838c, uVar21 != uVar25; uVar21 = uVar21 + 1) {
                  puVar12 = puVar12 + 1;
                  *puVar12 = *puVar9;
                  puVar9 = puVar9 + 1;
                }
                iVar16 = (uVar21 + 3 & 0xfffffffc) + uVar17 * 4;
                bVar27 = false;
                uVar17 = 0;
                _DAT_009b8458 = 0;
                pbVar26 = &UNK_009b8437;
                pbVar10 = &DAT_009b6d20 + iVar16;
                for (uVar21 = 0; uVar25 = _DAT_009b8390, uVar21 != uVar20; uVar21 = uVar21 + 1) {
                  bVar1 = *pbVar10;
                  pbVar26 = pbVar26 + 1;
                  *pbVar26 = bVar1;
                  uVar17 = uVar17 | (uint)(bVar1 >> 7) << (uVar21 & 0xff);
                  bVar27 = true;
                  pbVar10 = pbVar10 + 1;
                }
                uVar21 = 0;
                if (bVar27) {
                  _DAT_009b8458 = uVar17;
                }
                puVar12 = &UNK_009b8447;
                puVar9 = &DAT_009b6d20 + iVar16 + (uVar20 + 3 & 0xfffffffc);
                for (; uVar21 != uVar25; uVar21 = uVar21 + 1) {
                  puVar12 = puVar12 + 1;
                  *puVar12 = *puVar9;
                  puVar9 = puVar9 + 1;
                }
              }
              uVar21 = 0;
              do {
                uVar29 = FUN_00983374(&DAT_009b6d20 + uVar21);
                uVar21 = (int)((ulonglong)uVar29 >> 0x20) + 4;
                local_68 = local_68 + (int)uVar29;
                iVar4 = iVar4 + local_68;
              } while (uVar21 < uVar24);
            }
            if ((iVar6 == iVar4 && iVar5 == local_68) &&
               (uVar22 = 0, (_DAT_009b8458 == 0) == (_DAT_009b8390 == 0))) {
              _DAT_009b845c = 0;
              for (uVar24 = uVar22; _DAT_009b838c != uVar24; uVar24 = uVar24 + 1) {
                if ((_DAT_009b8458 >> (uVar24 & 0xff) & 1) != 0) {
                  if (uVar22 != 0) {
                    _DAT_009b845c = uVar24;
                  }
                  goto LAB_009856e4;
                }
                uVar22 = 1;
              }
              if (uVar22 != 0) {
                _DAT_009b845c = _DAT_009b838c;
              }
LAB_009856e4:
              puVar18 = (uint *)&DAT_009b83a8;
              for (uVar22 = 1; uVar22 < _DAT_009b8384; uVar22 = uVar22 + 1) {
                if (puVar18[1] <= *puVar18) goto LAB_009854b0;
                puVar18 = puVar18 + 1;
              }
              _DAT_009b83a4 = iVar14;
              for (iVar4 = 0; (*(char *)(iVar15 + iVar4) != '\0' && (iVar4 != 0x9f));
                  iVar4 = iVar4 + 1) {
                *local_58 = *(char *)(iVar15 + iVar4);
                local_58 = local_58 + 1;
              }
              (&DAT_009b8238)[iVar4] = 0;
              iVar4 = 0;
              goto LAB_009853e8;
            }
          }
        }
      }
LAB_009854b0:
      iVar4 = -2;
    }
    else {
LAB_009853e4:
      iVar4 = -3;
    }
LAB_009853e8:
    iVar15 = param_2[1];
    pcVar8 = &UNK_009b82d7;
    for (iVar16 = 0; (*(char *)(iVar15 + iVar16) != '\0' && (iVar16 != 0x9f)); iVar16 = iVar16 + 1)
    {
      pcVar8 = pcVar8 + 1;
      *pcVar8 = *(char *)(iVar15 + iVar16);
    }
    (&DAT_009b82d8)[iVar16] = 0;
    *(int *)(param_1 + 0x18c) = *(int *)(param_1 + 0x18c) + 1;
    if (iVar4 != 0) goto LAB_0098596c;
  }
  uVar22 = 0;
  pbVar10 = &UNK_009b8437;
  while ((_DAT_009b838c != uVar22 && (pbVar10 = pbVar10 + 1, (*pbVar10 & 0x7f) != param_2[3]))) {
    uVar22 = uVar22 + 1;
  }
  uVar24 = 0;
  pcVar8 = &UNK_009b8427;
  while ((_DAT_009b8388 != uVar24 && (pcVar8 = pcVar8 + 1, (int)*pcVar8 != param_2[2]))) {
    uVar24 = uVar24 + 1;
  }
  uVar21 = param_2[4];
  if ((int)uVar21 < 1) {
    uVar17 = 0;
  }
  else {
    uVar17 = uVar21 + 1 & 0xff;
  }
  uVar25 = 0;
  pbVar10 = &UNK_009b8447;
  while ((_DAT_009b8390 != uVar25 && (pbVar10 = pbVar10 + 1, *pbVar10 != uVar17))) {
    uVar25 = uVar25 + 1;
  }
  if (uVar22 < _DAT_009b838c) {
    uVar17 = _DAT_009b8458 >> (uVar22 & 0xff) & 1;
  }
  else {
    uVar17 = 0;
  }
  if (_DAT_009b838c == uVar22 || _DAT_009b8388 == uVar24) {
LAB_00985968:
    iVar4 = -2;
    goto LAB_0098596c;
  }
  if (uVar17 == 0) {
    uVar21 = uVar24;
    local_68 = uVar22;
  }
  else {
    uVar21 = uVar21 >> 0x1f;
    if (_DAT_009b8390 == uVar25) {
      uVar21 = 1;
    }
    if (uVar21 != 0) goto LAB_00985968;
    uVar21 = 0;
    local_68 = _DAT_009b845c;
  }
  iVar4 = FUN_00983e48(auStack_40,
                       _DAT_009b8384 * 8 * (_DAT_009b8388 * local_68 + uVar21) + _DAT_009b83a4,
                       &DAT_009b6d20);
  uVar2 = _DAT_009b8394;
  uVar20 = _DAT_009b8384;
  puVar9 = &DAT_009b6d20;
  puVar18 = (uint *)&DAT_009b8470;
  for (uVar23 = 0; (iVar4 == 0 && (uVar20 != uVar23)); uVar23 = uVar23 + 1) {
    uVar29 = FUN_00983374(puVar9);
    puVar18[1] = (uint)uVar29;
    uVar30 = FUN_00983374((int)((ulonglong)uVar29 >> 0x20) + 4);
    uVar7 = (uint)uVar30;
    if (uVar7 == 0) {
      iVar4 = -2;
    }
    puVar18[0x21] = uVar7;
    if ((uVar7 != 0) && ((uint)uVar29 < uVar2)) {
      iVar4 = -2;
    }
    puVar9 = (undefined *)((int)((ulonglong)uVar30 >> 0x20) + 8);
    puVar18 = puVar18 + 1;
  }
  _DAT_009b8574 = 0;
  uVar20 = 0;
  if (iVar4 == 0) {
    uVar20 = uVar17;
  }
  if (uVar20 == 0) {
    if (iVar4 == 0) {
LAB_00985a74:
      if ((_DAT_009b8224 != local_68) || (_DAT_009b8228 != uVar21)) {
        _DAT_009de8a4 = 0;
      }
      iVar4 = 0;
    }
  }
  else {
    iVar4 = FUN_00983e48(auStack_40,
                         _DAT_009b83a4 +
                         (_DAT_009b8390 * (uVar22 * _DAT_009b8388 + uVar24) + _DAT_009b8398 * 2 +
                         uVar25) * 4,&DAT_009b6d20,4);
    if (iVar4 == 0) {
      _DAT_009b8574 = FUN_00983374(&DAT_009b6d20);
      if (_DAT_009b8574 != 0) goto LAB_00985a74;
      iVar4 = -2;
    }
    else {
      iVar4 = -3;
    }
  }
  _DAT_009b8460 = local_68;
  if (uVar17 == 0) {
    _DAT_009b8470 = 5;
  }
  else {
    _DAT_009b8470 = param_2[4];
    if (0xb < _DAT_009b8470) {
      _DAT_009b8470 = 5;
    }
  }
  _DAT_009b8464 = uVar21;
  _DAT_009b8468 = uVar22;
  _DAT_009b846c = uVar24;
LAB_0098596c:
  FUN_00982a90(iVar3,0);
  if (iVar4 == 0) {
    _DAT_009b5994 = param_2[3];
    _DAT_009b5998 = param_2[2];
    _DAT_009b599c = param_2[4];
    _DAT_009b59a0 = 1;
  }
  else {
    DAT_009b8238 = 0;
    FUN_009852b0();
    *(int *)(param_1 + 4) = iVar4;
  }
                    /* WARNING: Read-only address (ram,0x009b6d40) is written */
                    /* WARNING: Read-only address (ram,0x009b6d42) is written */
                    /* WARNING: Read-only address (ram,0x009b6d44) is written */
                    /* WARNING: Read-only address (ram,0x009b6d46) is written */
  return iVar4;
}


// ===== FUN_00985bbc @ 00985bbc

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * FUN_00985bbc(int param_1)

{
  int iVar1;
  
  if (param_1 == 0) {
    return (undefined *)0x0;
  }
  if (param_1 == _DAT_009b582c) {
    iVar1 = 0;
  }
  else {
    if (param_1 != _DAT_009b588c) {
      return (undefined *)0x0;
    }
    iVar1 = 1;
  }
  return &DAT_009b582c + (-iVar1 & 0x60);
}


// ===== FUN_00985c08 @ 00985c08

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int * FUN_00985c08(void)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  
  piVar1 = (int *)FUN_00985bbc();
  piVar3 = (int *)&DAT_009b582c;
  iVar2 = 0;
  while (iVar2 != 2 && piVar1 == (int *)0x0) {
    iVar2 = iVar2 + 1;
    piVar1 = piVar3;
    if (*piVar3 != 0) {
      piVar1 = (int *)0x0;
    }
    piVar3 = piVar3 + 0x18;
  }
  if (piVar1 != (int *)0x0) {
    return piVar1;
  }
  piVar1 = (int *)&DAT_009b588c;
  if (_DAT_009b5830 <= _DAT_009b5890) {
    piVar1 = (int *)&DAT_009b582c;
  }
  return piVar1;
}


// ===== FUN_00985c78 @ 00985c78

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool FUN_00985c78(int *param_1)

{
  undefined4 uVar1;
  int *piVar2;
  int iVar3;
  code *pcVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  
  FUN_0098413c();
  iVar3 = *(int *)(param_1[1] + 0xa4) + 1;
  *(int *)(param_1[1] + 0xa4) = iVar3;
  pcVar4 = *(code **)(*param_1 + 4);
  if (pcVar4 != (code *)0x0) {
    uVar6 = *(undefined4 *)(*param_1 + 0xc);
    uVar1 = 0;
    if (param_1[5] != 0) {
      uVar1 = FUN_009a5bf0(iVar3 * 100,param_1[5]);
    }
    (*pcVar4)(uVar6,2,uVar1);
  }
  FUN_00983748(param_1);
  iVar3 = param_1[7];
  if (iVar3 != 0) {
    if (*(int *)(iVar3 + 0x20) != 0) {
      return false;
    }
    if ((((_DAT_009b5828 != 0) && ((int *)param_1[9] != (int *)0x0)) && (*(int *)param_1[9] != 0))
       && ((((*(uint *)(iVar3 + 0x24) & 0xf) == 0 && (-1 < *(int *)(iVar3 + 0x2c))) &&
           (iVar3 = FUN_00982b64(), iVar3 == 0)))) {
      iVar7 = param_1[8];
      iVar5 = *param_1;
      piVar2 = (int *)FUN_00985c08(iVar7);
      iVar3 = param_1[7];
      *piVar2 = iVar7;
      iVar7 = *(int *)(iVar3 + 0x50);
      piVar2[1] = *(int *)(iVar3 + 0x24);
      piVar2[2] = iVar7;
      FUN_009975a8(piVar2 + 3,param_1[9],0x54);
      pcVar4 = *(code **)(iVar5 + 0x18);
      if (pcVar4 != (code *)0x0) {
        (*pcVar4)(*(undefined4 *)(iVar5 + 0xc));
      }
    }
  }
  pcVar4 = *(code **)(*param_1 + 0x14);
  if (pcVar4 == (code *)0x0) {
    return false;
  }
  iVar3 = (*pcVar4)(*(undefined4 *)(*param_1 + 0xc));
  if (iVar3 != 0) {
    *(undefined4 *)(param_1[1] + 0x174) = 1;
  }
  return iVar3 != 0;
}


// ===== FUN_00985dc4 @ 00985dc4

void FUN_00985dc4(void)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FUN_00985bbc();
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = 0;
  }
  return;
}


// ===== FUN_00985ddc @ 00985ddc

uint FUN_00985ddc(int param_1,int param_2)

{
  uint uVar1;
  byte *pbVar2;
  
  pbVar2 = (byte *)(param_1 + -1);
  uVar1 = 0x811c9dc5;
  while( true ) {
    pbVar2 = pbVar2 + 1;
    if (*pbVar2 == 0) break;
    uVar1 = (uVar1 ^ *pbVar2) * 0x1000193;
  }
  pbVar2 = (byte *)(param_2 + -1);
  while( true ) {
    pbVar2 = pbVar2 + 1;
    if (*pbVar2 == 0) break;
    uVar1 = (uVar1 ^ *pbVar2) * 0x1000193;
  }
  return uVar1 | 1;
}


// ===== FUN_00985e30 @ 00985e30

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool FUN_00985e30(int param_1,int param_2,uint *param_3,uint *param_4)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = 0x5692c;
  if (param_2 != 0) {
    iVar3 = 0x1748c;
  }
  FUN_00985044(param_3,param_4);
  if (_DAT_009b857c != 0) {
    if ((param_1 != 0) && (iVar1 = FUN_00983344(param_1,&DAT_009b8238), iVar1 == 0)) {
      return false;
    }
    uVar2 = 0xad48c;
    if (iVar3 != 0x1748c) {
      uVar2 = 0xec92c;
    }
    if (uVar2 <= *param_3) {
      uVar2 = 0x3f4a0;
      if (param_2 != 0) {
        uVar2 = 0x8020;
      }
      return uVar2 <= *param_4;
    }
  }
  return false;
}


// ===== FUN_00985ef4 @ 00985ef4

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool FUN_00985ef4(int param_1,int param_2,int param_3,uint *param_4,uint *param_5)

{
  uint unaff_r4;
  uint uVar1;
  
  if (param_1 == 0) {
    if (param_3 != 0) {
      unaff_r4 = 0x85000;
    }
    uVar1 = 0x20020;
    if (param_3 == 0) {
      unaff_r4 = 0x44000;
    }
  }
  else if (param_2 == 0) {
    uVar1 = 0x3f4a0;
    unaff_r4 = 0x7b928;
  }
  else {
    uVar1 = 0x20020;
    unaff_r4 = 0x3c488;
  }
  if (_DAT_009b857c == 0) {
    unaff_r4 = unaff_r4 + 0x12f2be;
  }
  FUN_00985044(param_4,param_5);
  if (*param_4 == 0) {
    return *param_5 == 0;
  }
  if (*param_4 < unaff_r4) {
    return false;
  }
  return uVar1 <= *param_5;
}


// ===== FUN_00985fb4 @ 00985fb4

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_00985fb4(code *param_1,undefined4 param_2)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  undefined1 local_f8;
  undefined1 local_f7;
  undefined1 local_f6;
  byte local_f5;
  undefined4 local_f4;
  undefined4 local_f0;
  undefined1 auStack_ec [8];
  undefined4 local_e4;
  undefined4 local_e0;
  undefined4 local_dc;
  undefined1 auStack_c8 [164];
  
  if (((_DAT_009b5960 != 0) || (DAT_009b8238 == '\0')) || (_DAT_009b5964 == 0)) {
    return 0;
  }
  _DAT_009b5964 = _DAT_009b5964 + -1;
  if ((byte)(&DAT_009b5968)[_DAT_009b5964 * 4] != _DAT_009b8460) {
    return 1;
  }
  if ((byte)(&DAT_009b5969)[_DAT_009b5964 * 4] != _DAT_009b8464) {
    return 1;
  }
  bVar1 = (&DAT_009b596a)[_DAT_009b5964 * 4];
  uVar11 = (uint)bVar1;
  if (_DAT_009b8384 <= uVar11) {
    return 1;
  }
  iVar2 = FUN_00983d0c(&local_e0,&DAT_009b8238,0);
  if (iVar2 < 0) {
    return 1;
  }
  FUN_00983528(auStack_c8,uVar11);
  iVar3 = FUN_00983ec0(&local_e0,uVar11,&local_f4);
  if (iVar3 != 0) goto LAB_00986088;
  iVar3 = FUN_0098289c(auStack_c8);
  if (-1 < iVar3) {
    iVar4 = FUN_0098293c(iVar3,&DAT_009b5940,0x20);
    if (iVar4 == 0) {
      iVar4 = FUN_00983660(uVar11,&local_f4);
    }
    else {
      iVar4 = 0;
    }
    FUN_00982a90(iVar3,0);
    if (iVar4 != 0) {
      FUN_00982a90(iVar2,0);
      return iVar4;
    }
  }
  iVar3 = thunk_EXT_FUN_ffb2f664(0x8428);
  if (iVar3 == 0) goto LAB_00986088;
  iVar4 = FUN_009828c0(auStack_c8);
  if (iVar4 < 0) {
    _DAT_009b5960 = 1;
  }
  else {
    uVar8 = iVar3 + 0x1fU & 0xffffffe0;
    _DAT_009b5940 = 0;
    _DAT_009b5944 = 0;
    _DAT_009b5948 = 0;
    _DAT_009b594c = 0;
    _DAT_009b5950 = 0;
    _DAT_009b5954 = 0;
    _DAT_009b5958 = 0;
    _DAT_009b595c = 0;
    local_f8 = 0x53;
    local_f7 = (undefined1)_DAT_009b8460;
    local_f6 = (undefined1)_DAT_009b8464;
    local_f5 = bVar1;
    FUN_0098943c(auStack_ec,&local_f8,&DAT_009b8378);
    local_e4 = local_f4;
    iVar5 = FUN_009829b8(iVar4,&DAT_009b5940);
    if (iVar5 == 0) {
      local_dc = *(undefined4 *)(&DAT_009b8474 + uVar11 * 4);
      iVar5 = FUN_00982a34(local_e0);
      if (iVar5 == 0) {
        iVar6 = FUN_00998f98(&UNK_009b59a4,*(undefined4 *)(&DAT_009b84f4 + uVar11 * 4),&DAT_00983f0c
                             ,&local_e0,&DAT_009b6d20,0x1500);
        iVar5 = 0;
        if (iVar6 != 0) {
          iVar5 = -2;
        }
      }
      else {
        iVar5 = -2;
      }
    }
    else {
      iVar5 = -4;
    }
    for (uVar9 = 0; uVar9 != 0x42 && iVar5 == 0; uVar9 = uVar9 + 1) {
      if ((param_1 != (code *)0x0) && (iVar5 = (*param_1)(param_2), iVar5 != 0)) {
        iVar5 = 1;
        goto LAB_00986244;
      }
      uVar10 = 0;
      if ((uVar9 - 1 & 1) != 0) {
        uVar10 = 0xffffffff;
      }
      iVar5 = uVar8 + (uVar10 & 0x4204);
      if (uVar9 == 0x41) {
LAB_009862b4:
        FUN_0098948c(iVar5,0x4204,(uVar9 - 1) * 0x4204,auStack_ec);
        iVar5 = FUN_009829b8(iVar4,iVar5);
        if (iVar5 == 0) {
          iVar5 = 0;
        }
        else {
          iVar5 = -4;
        }
      }
      else {
        uVar10 = 0;
        if ((uVar9 & 1) != 0) {
          uVar10 = 0xffffffff;
        }
        FUN_00999358(&UNK_009b59a4,uVar8 + (uVar10 & 0x4204));
        if (uVar9 != 0) goto LAB_009862b4;
        iVar5 = 0;
      }
    }
    if (iVar5 == 0) {
      if ((_DAT_009b59b0 == 0x41) && (iVar5 = FUN_00999f44(), iVar5 == 0)) {
        _DAT_009b5940 = 0x3153544c;
        _DAT_009b5944 = _DAT_009b8460 | uVar11 << 0x10 | _DAT_009b8464 << 8 | 0x41000000;
        _DAT_009b5948 = local_f4;
        _DAT_009b5950 = 0;
        _DAT_009b5954 = 0;
        _DAT_009b5958 = 0;
        _DAT_009b595c = 0;
        _DAT_009b594c = local_f0;
        iVar5 = FUN_00982a34(iVar4,0);
        if (iVar5 == 0) {
          iVar6 = FUN_009829b8(iVar4,&DAT_009b5940);
          iVar5 = 0;
          if (iVar6 != 0) {
            iVar5 = -4;
          }
        }
        else {
          iVar5 = -4;
        }
      }
      else {
        iVar5 = -2;
      }
    }
LAB_00986244:
    iVar4 = FUN_00982a90(iVar4,1);
    if ((iVar4 == 0 || iVar5 != 0) && (iVar5 != -4)) {
      if (iVar5 == 0) {
        piVar7 = (int *)&DAT_009b5990;
      }
      else {
        if (iVar5 != 1) goto LAB_0098627c;
        piVar7 = (int *)&DAT_009b5964;
      }
      *piVar7 = *piVar7 + 1;
    }
    else {
      _DAT_009b5960 = 1;
    }
  }
LAB_0098627c:
  FUN_00983230(iVar3);
LAB_00986088:
  FUN_00982a90(iVar2,0);
                    /* WARNING: Read-only address (ram,0x009b59b0) is written */
  return 1;
}


// ===== FUN_00986414 @ 00986414

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool FUN_00986414(int param_1)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  
  if (_DAT_009b857c == 0) {
    return false;
  }
  if (param_1 == 0) {
    return true;
  }
  pcVar3 = (char *)(param_1 + -1);
  pcVar2 = &UNK_009b8237;
  do {
    pcVar3 = pcVar3 + 1;
    cVar1 = *pcVar3;
    pcVar2 = pcVar2 + 1;
    if (cVar1 == '\0') break;
  } while (cVar1 == *pcVar2);
  return cVar1 == *pcVar2;
}


// ===== FUN_0098644c @ 0098644c

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_0098644c(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  int iVar2;
  int local_7c;
  int local_78;
  int local_74;
  undefined4 local_70;
  undefined *local_6c;
  undefined1 auStack_68 [16];
  undefined4 local_58;
  undefined4 uStack_54;
  
  uVar1 = FUN_00983394();
  if (uVar1 == 0) {
    uVar1 = 1;
  }
  else if (_DAT_009de8a4 != 0) {
    local_6c = &UNK_009d6968;
    local_70 = param_2;
    FUN_0098319c(&UNK_009d68c0,0x7ed0);
    iVar2 = FUN_0098f788(&UNK_009d68c0,FUN_009837c4,&local_70);
    if ((((((iVar2 == 0) && (iVar2 = FUN_0099a0f8(&DAT_009d68f8,auStack_68), iVar2 == 0)) &&
          (FUN_00983430(local_58,uStack_54,&local_7c,&local_78,&local_74),
          _DAT_009b8224 == _DAT_009b8460)) &&
         ((_DAT_009b8228 == _DAT_009b8464 && (_DAT_009b822c == local_7c)))) &&
        ((_DAT_009b8230 == local_78 && (_DAT_009b8234 == local_74)))) &&
       ((_DAT_009de8a8 == 0 || (_DAT_009b846c + _DAT_009b8468 * 0x10 == DAT_009b4944)))) {
      if (_DAT_009b8574 == 0) {
        return 0;
      }
      return (uint)(_DAT_009b8220 != _DAT_009b8574);
    }
  }
  return uVar1;
}


// ===== FUN_009865ac @ 009865ac

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int * FUN_009865ac(int *param_1,int param_2,int param_3,undefined4 *param_4)

{
  int iVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  char cVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  undefined4 *puVar11;
  char extraout_r1;
  uint uVar12;
  code *pcVar13;
  char *pcVar14;
  byte *pbVar15;
  undefined1 uVar16;
  char *pcVar17;
  undefined *puVar18;
  int iVar19;
  int **ppiVar20;
  undefined4 *puVar21;
  undefined *puVar22;
  int *piVar23;
  int *piVar24;
  uint uVar25;
  char *pcVar26;
  uint uVar27;
  int iVar28;
  undefined4 *puVar29;
  undefined4 uVar30;
  bool bVar31;
  bool bVar32;
  bool bVar33;
  undefined8 uVar34;
  undefined *local_274;
  int *local_26c;
  int local_268;
  uint local_264;
  int local_260;
  int local_25c;
  undefined4 local_258;
  int local_254;
  int local_250;
  int local_24c;
  undefined4 *local_248;
  undefined4 *local_240;
  int local_23c;
  byte *local_234;
  uint local_218;
  int local_214;
  uint local_210;
  int local_20c;
  undefined *local_208;
  undefined4 local_204;
  undefined4 local_200;
  undefined4 local_1fc;
  undefined4 local_1f8;
  undefined4 local_1f4;
  undefined4 local_1f0;
  undefined4 local_1dc [6];
  int local_1c4;
  int *local_1c0;
  undefined4 local_1bc;
  undefined4 local_1b8;
  int local_1b4;
  uint local_1b0;
  int local_1ac;
  undefined *local_1a8;
  undefined4 *local_1a4;
  undefined *local_1a0;
  int local_19c [4];
  undefined4 local_18c;
  undefined4 local_188;
  undefined4 local_184;
  undefined4 local_180;
  undefined4 local_17c;
  uint local_174;
  int local_170;
  uint local_16c;
  int *local_168;
  undefined4 local_164 [3];
  int local_158;
  undefined4 local_150;
  undefined *local_148;
  undefined *local_144;
  int *local_140;
  int local_13c;
  int local_138;
  int local_134;
  int local_130;
  uint local_12c;
  int *local_128 [4];
  int local_118;
  undefined4 local_114;
  int local_110;
  int *local_10c [4];
  undefined1 auStack_fc [36];
  int local_d8;
  undefined1 auStack_d0 [92];
  int iStack_74;
  int local_70 [13];
  int local_3c;
  int local_38;
  
  iVar4 = _DAT_009b4aa8;
  iVar3 = _DAT_009b4aa4;
  iVar6 = FUN_00983244();
  param_1[0x25] = iVar6;
  if (DAT_009b8238 == '\0') {
    piVar23 = (int *)0xfffffff6;
    goto LAB_00986648;
  }
  *param_1 = 1;
  iVar6 = *(int *)(param_2 + 8);
  FUN_00985044(param_1 + 0x53,param_1 + 0x54);
  if ((*(int *)(param_2 + 0x1c) != 0) &&
     (iVar7 = FUN_00985e30(0,*(int *)(param_2 + 0x2c) != 0,param_1 + 0x53,param_1 + 0x54),
     iVar7 == 0)) {
LAB_00986644:
    piVar23 = (int *)0xffffffea;
    goto LAB_00986648;
  }
  bVar2 = iVar6 == 0;
  bVar31 = param_4 != (undefined4 *)0x0;
  if (bVar2 && bVar31) {
    if ((*(int *)(param_2 + 0x24) == 0) || (*(int *)(param_2 + 0x28) == 0)) {
LAB_009866ac:
      iVar7 = 0;
      iVar28 = *(int *)(param_2 + 0x1c);
      goto LAB_009866b4;
    }
    uVar12 = 0;
    for (pcVar17 = &DAT_009b8238; *pcVar17 != '\0'; pcVar17 = pcVar17 + 1) {
      uVar12 = uVar12 + 1;
    }
    local_164[0] = 0;
    if (7 < uVar12) {
      puVar18 = &UNK_009b822f + uVar12;
      iVar7 = 0;
      puVar11 = local_164;
      do {
        puVar18 = puVar18 + 1;
        iVar7 = iVar7 + 1;
        *(undefined *)puVar11 = *puVar18;
        puVar11 = (undefined4 *)((int)puVar11 + 1);
      } while (iVar7 != 4);
    }
    iVar7 = FUN_00994d0c(local_164);
    if (iVar7 == 0) goto LAB_009866ac;
    uVar12 = 0x811c9dc5;
    pbVar15 = (byte *)(param_3 + -1);
    while( true ) {
      pbVar15 = pbVar15 + 1;
      if (*pbVar15 == 0) break;
      uVar12 = (uVar12 ^ *pbVar15) * 0x1000193;
    }
    uVar25 = *(uint *)(param_2 + 0x24);
    piVar23 = (int *)(uVar12 | 1);
    iVar28 = FUN_00983c04(uVar25,piVar23,local_164);
    if (iVar28 != -1) {
      FUN_00983890();
      goto LAB_009866ac;
    }
    iVar28 = FUN_009850ec(param_1);
    if (iVar28 == 0) {
      iVar28 = FUN_0098487c(uVar25,piVar23,local_164);
      if (iVar28 < 0) {
LAB_00986878:
        FUN_0098326c();
        goto LAB_009866ac;
      }
      iVar19 = 0xf;
      puVar11 = (undefined4 *)&UNK_009de7dc;
      while( true ) {
        uVar30 = FUN_00983298(iVar19,0x6270);
        puVar11[1] = uVar30;
        uVar30 = FUN_00983298(iVar19 + 2,0x9678);
        puVar11[3] = uVar30;
        if (iVar19 == 0x10) break;
        iVar19 = 0x10;
        puVar11 = puVar11 + 1;
      }
      _DAT_009de7f0 = FUN_00983298(0x13,0xbb20);
      if ((((_DAT_009de7e0 == 0) || (_DAT_009de7e4 == 0)) || (_DAT_009de7e8 == 0)) ||
         (_DAT_009de7f0 == 0 || _DAT_009de7ec == 0)) {
        FUN_009850b0(param_1);
      }
      else {
        iVar19 = FUN_00983244();
        if (iVar28 != 0) {
          FUN_00994f70(&UNK_009de7c8,&DAT_009de810,iVar7,iVar28,0x888,0xd5);
        }
        iVar7 = FUN_00983244();
        param_1[0x67] = param_1[0x67] | 0x10;
        param_1[0x68] = iVar7 - iVar19;
        FUN_009832dc(auStack_d0,uVar25);
        FUN_009836e4();
        iVar7 = FUN_009828c0(auStack_d0);
        local_128[2] = (int *)0x168;
        local_128[3] = (int *)0xd5;
        if (iVar7 < 0) {
          uVar25 = 1;
        }
        local_128[0] = (int *)0x0;
        local_114 = local_164[0];
        local_110 = 0;
        local_10c[0] = (int *)0x0;
        local_128[1] = piVar23;
        local_118 = iVar28;
        if (iVar7 >= 0) {
          iVar28 = FUN_009829b8(iVar7,local_128,0x20);
          uVar25 = 0;
          if (iVar28 != 0) {
            uVar25 = 1;
          }
        }
        for (iVar28 = 0; uVar25 == 0 && iVar28 != 7; iVar28 = iVar28 + 1) {
          uVar12 = 0;
          do {
            uVar30 = FUN_00984650(uVar12,iVar28 << 5);
            uVar25 = FUN_009829b8(iVar7,uVar30,0x5a00);
            uVar27 = uVar12 ^ 1;
            if (uVar25 != 0) {
              uVar27 = 0;
            }
            uVar12 = 1;
          } while (uVar27 != 0);
        }
        local_128[0] = (int *)0x31444148;
        if (uVar25 == 0) {
          iVar28 = FUN_00982a34(iVar7,0);
          if (iVar28 != 0) {
            uVar25 = 1;
            goto LAB_009890ac;
          }
          iVar28 = FUN_009829b8(iVar7,local_128,0x20);
          uVar25 = (uint)(iVar28 != 0);
          if (-1 < iVar7) goto LAB_00986a20;
LAB_00986a34:
          if (uVar25 == 0) goto LAB_00986878;
        }
        else {
LAB_009890ac:
          if (-1 < iVar7) {
LAB_00986a20:
            iVar7 = FUN_00982a90(iVar7,1);
            if (iVar7 == 0) goto LAB_00986a34;
          }
        }
        FUN_00982bac(auStack_d0);
      }
      FUN_0098326c();
    }
LAB_00986900:
    piVar23 = (int *)0xfffffff9;
    goto LAB_00986648;
  }
  iVar28 = *(int *)(param_2 + 0x1c);
  if (iVar6 == 0) {
    iVar7 = 0;
  }
  else {
    iVar7 = *(int *)(param_2 + 0x2c);
  }
LAB_009866b4:
  local_158 = 0;
  local_150 = 0;
  local_140 = (int *)0x0;
  local_138 = 0;
  local_134 = 0;
  local_130 = 0;
  local_12c = 0;
  FUN_0098319c(local_164,0x3c);
  local_148 = &UNK_009d68c0;
  local_144 = &UNK_009b85e0;
  if (iVar28 == 0) {
    local_13c = FUN_0098331c(local_164,2,0x20000);
    local_134 = FUN_0098331c(local_164,3,0x10000);
    if (iVar6 != 0) {
      if (iVar7 == 0) {
        iVar7 = FUN_0098331c(local_164,5,0x3f480);
      }
      local_138 = iVar7;
      local_130 = FUN_0098331c(local_164,4,0x4000);
    }
    if (((local_13c == 0) || (local_134 == 0)) ||
       ((iVar6 != 0 && ((local_138 == 0 || (local_130 == 0)))))) {
      local_140 = (int *)&UNK_009b85e0;
      FUN_00983710(local_164);
      goto LAB_00986900;
    }
    local_140 = (int *)&UNK_009b85e0;
    local_12c = 0x20000;
    FUN_00985158(local_164,0);
    local_26c = local_140;
    local_25c = local_130;
    local_264 = local_12c;
  }
  else {
    local_13c = FUN_0098331c(local_164,2,0x8000);
    if (iVar7 == 0) {
      iVar7 = FUN_0098331c(local_164,5,0x3f480);
    }
    local_138 = iVar7;
    local_25c = FUN_0098331c(local_164,4,0x4000);
    if ((local_13c == 0) || (local_25c == 0 || local_138 == 0)) {
      local_140 = (int *)&UNK_009b85e0;
      local_130 = local_25c;
      FUN_00983710(local_164);
      goto LAB_00986644;
    }
    local_264 = 0x8000;
    local_26c = (int *)&UNK_009b85e0;
  }
  local_250 = local_134;
  local_260 = local_138;
  local_268 = local_13c;
  local_274 = local_144;
  puVar18 = local_148;
  local_258 = local_150;
  local_254 = local_158;
  if ((param_4 != (undefined4 *)0x0) && (_DAT_009e70b8 == 0)) {
    FUN_00989cb4(0x888);
  }
  FUN_0098319c(puVar18,0x7ed0);
  FUN_00985044(param_1 + 0x55,param_1 + 0x56);
  param_1[8] = local_264;
  _DAT_c02200f0 = 0x46;
  local_19c[0] = -1;
  local_19c[1] = 0xffffffff;
  local_19c[2] = 0xffffffff;
  local_1ac = param_1[0x25];
  local_170 = 0;
  local_1bc = 0;
  local_1b8 = 0;
  local_1b4 = 0;
  local_1b0 = 0;
  local_1a8 = (undefined *)0x0;
  local_1a4 = (undefined4 *)0x0;
  local_1a0 = (undefined *)0x0;
  local_20c = *(int *)(param_2 + 0x1c);
  local_208 = puVar18 + 0xa8;
  local_1c4 = param_2;
  local_1c0 = param_1;
  if (local_20c == 0) {
    local_170 = local_250;
    iVar7 = 0;
    local_19c[3] = 0;
    local_18c = 0;
    local_188 = 0;
    local_184 = 0;
    local_180 = 0;
    local_17c = 0;
    local_16c = 0;
    local_168 = param_1;
    do {
      piVar23 = (int *)FUN_0098289c(param_3);
      local_19c[iVar7] = (int)piVar23;
      if ((int)piVar23 < 0) goto LAB_00987168;
      iVar7 = iVar7 + 1;
    } while (iVar7 != 3);
    uVar12 = FUN_00982a68(local_19c[0]);
    local_174 = uVar12 & ~((int)uVar12 >> 0x1f);
    if (local_170 != 0) {
      local_16c = local_174;
      if (0xffff < local_174) {
        local_16c = 0x10000;
      }
      if ((int)uVar12 < 1) {
        local_16c = 0;
      }
      iVar7 = FUN_00982a34(local_19c[0],0);
      if ((iVar7 != 0) || (iVar7 = FUN_0098293c(local_19c[0],local_170,local_16c), iVar7 != 0)) {
        local_16c = 0;
      }
      local_19c[3] = local_16c;
    }
    pcVar13 = FUN_009839bc;
    piVar23 = local_19c;
LAB_00986d7c:
    piVar23 = (int *)FUN_0098f788(puVar18,pcVar13,piVar23);
    if (piVar23 == (int *)0x0) {
      *param_1 = 2;
      param_1[0xc] = *(int *)(puVar18 + 0x20);
      param_1[0xd] = *(int *)(puVar18 + 0x24);
      param_1[0xe] = *(int *)(puVar18 + 0xc4);
      param_1[0xf] = *(int *)(puVar18 + 0x28);
      param_1[0x10] = *(int *)(puVar18 + 0x2c);
      param_1[0x11] = *(int *)(puVar18 + 0x30);
      param_1[0x12] = *(int *)(puVar18 + 0x34);
      param_1[0x13] = (uint)*(ushort *)(puVar18 + 0x38);
      param_1[0x14] = (uint)*(ushort *)(puVar18 + 0x3a);
      param_1[0x15] = (uint)*(ushort *)(puVar18 + 0x3c);
      param_1[0x16] = (uint)*(ushort *)(puVar18 + 0x3e);
      piVar23 = (int *)FUN_009944b0(auStack_d0,puVar18,&DAT_009a9080);
      if (piVar23 == (int *)0x0) {
        iVar7 = FUN_0099a0f8(puVar18 + 0x38,local_128);
        if (iVar7 == 0) {
          FUN_00994b88(auStack_d0,auStack_fc);
          iVar7 = local_118;
          FUN_00983430(local_118,local_114,&local_218,&local_214,&local_210);
          param_1[0x5f] = local_110;
          param_1[0x5e] = iVar7;
          param_1[0x60] = local_d8;
          uVar12 = local_210 >> 0xc;
          param_1[0x61] = local_218 | local_214 << 8 | uVar12 << 0x10;
          param_1[0x62] = (uint)*(ushort *)(puVar18 + 0x40);
          FUN_009836e4();
          if ((((_DAT_009de8a4 != 0) && (_DAT_009b8224 == _DAT_009b8460)) &&
              (_DAT_009b8228 == _DAT_009b8464)) &&
             (((local_218 == _DAT_009b822c && (local_214 == _DAT_009b8230)) &&
              (local_210 == _DAT_009b8234)))) goto LAB_009878b8;
          _DAT_009de8a4 = 0;
          iVar7 = FUN_00983244();
          uVar25 = _DAT_009b857c;
          if (_DAT_009b857c == 0) {
            piVar23 = (int *)&DAT_009b4be4;
            iVar28 = 0;
            do {
              if (iVar28 - 0x3aU < 8) {
                iVar19 = 1;
              }
              else {
                iVar19 = 8;
              }
              iVar8 = thunk_EXT_FUN_ffb2f664(iVar19 * 0x4204 + 0x20);
              if (iVar8 == 0) goto LAB_00986fb4;
              *(int *)(&DAT_009b8580 + _DAT_009b857c * 4) = iVar8;
              iVar9 = 0;
              piVar24 = piVar23;
              _DAT_009b857c = _DAT_009b857c + 1;
              do {
                iVar1 = iVar9 * 0x4204;
                iVar9 = iVar9 + 1;
                *piVar24 = iVar1 + (iVar8 + 0x1fU & 0xffffffe0);
                piVar24 = piVar24 + 1;
              } while (iVar19 != iVar9);
              iVar28 = iVar28 + 8;
              piVar23 = piVar23 + 8;
            } while (iVar28 != 0x48);
            iVar28 = thunk_EXT_FUN_ffb2f664(0x13022);
            if (iVar28 == 0) {
LAB_00986fb4:
              FUN_009852b0();
              goto LAB_00986fb8;
            }
            *(int *)(&DAT_009b8580 + _DAT_009b857c * 4) = iVar28;
            _DAT_009b8578 = iVar28 + 0x1fU & 0xffffffe0;
            _DAT_009b857c = _DAT_009b857c + 1;
            iVar28 = FUN_0098289c(&DAT_009b82d8);
            if (-1 < iVar28) {
              FUN_00982a90(iVar28,0);
              iVar28 = thunk_EXT_FUN_ffb2f664(0xfe78);
              if (iVar28 == 0) goto LAB_00986fb4;
              *(int *)(&DAT_009b8580 + _DAT_009b857c * 4) = iVar28;
              _DAT_009de8a8 = iVar28 + 0x1fU & 0xffffffe0;
              _DAT_009b857c = _DAT_009b857c + 1;
            }
          }
          piVar23 = (int *)FUN_00983d0c(&local_1f4,&DAT_009b8238);
          if (-1 < (int)piVar23) {
            if (uVar25 == 0) {
              iVar28 = FUN_00983e48(&local_1f4,_DAT_009b839c,_DAT_009b8578,0x13002);
            }
            else {
              iVar28 = 0;
            }
            local_204 = 0;
            local_200 = 0;
            local_1fc = 0;
            local_1f8 = 0;
            if ((iVar28 == 0) && (iVar28 = FUN_00983ec0(&local_1f4,local_218), iVar28 == 0)) {
              iVar28 = 0;
              if (local_210 != 0) {
                iVar19 = FUN_00983ec0(&local_1f4,local_214);
                iVar28 = 0;
                if (iVar19 != 0) {
                  iVar28 = -3;
                }
              }
            }
            else {
              iVar28 = -3;
            }
            bVar32 = _DAT_009b5960 == 0;
            do {
              bVar33 = bVar32;
              if (iVar28 != 0) {
                bVar33 = false;
              }
              if (bVar33) {
                iVar28 = FUN_00984e3c(local_218,&local_204);
                if (iVar28 != 0) goto LAB_00987350;
                param_1[0x66] = param_1[0x66] + 1;
                piVar24 = (int *)0x0;
              }
              else if (iVar28 == 0) {
LAB_00987350:
                local_1f0 = *(undefined4 *)(&UNK_009b823c + (local_218 + 0x8e) * 4);
                iVar28 = FUN_00982a34(local_1f4);
                if (iVar28 == 0) {
                  iVar28 = FUN_00998f98(&UNK_009b59a4,*(undefined4 *)(&DAT_009b84f4 + local_218 * 4)
                                        ,&DAT_00983f0c,&local_1f4,&DAT_009b6d20,0x1500);
                  if (iVar28 == 0) {
                    iVar28 = 0;
                    puVar11 = (undefined4 *)&DAT_009b4be4;
                    do {
                      iVar28 = iVar28 + 1;
                      FUN_00999358(&UNK_009b59a4,*puVar11);
                      puVar11 = puVar11 + 1;
                    } while (iVar28 != 0x41);
                    if (_DAT_009b59b0 == 0x41) {
                      iVar28 = FUN_00999f44(&UNK_009b59a4);
                      piVar24 = (int *)0x0;
                      if (iVar28 != 0) {
                        piVar24 = (int *)0xfffffffe;
                      }
                      goto LAB_009873e8;
                    }
                  }
                  piVar24 = (int *)0xfffffffe;
                }
                else {
                  piVar24 = (int *)0xfffffffd;
                }
LAB_009873e8:
                param_1[100] = param_1[100] + (uint)(piVar24 == (int *)0x0);
                if ((piVar24 == (int *)0x0) && (_DAT_009b5960 == 0)) {
                  FUN_009835d4(local_218);
                }
              }
              else {
                piVar24 = (int *)0xfffffffd;
              }
              if (piVar24 != (int *)0x0 || local_210 == 0) goto LAB_009875d4;
              iVar28 = thunk_EXT_FUN_ffb2f664(0x8428);
              if (iVar28 == 0) {
                piVar24 = (int *)0xfffffff9;
                goto LAB_009875d4;
              }
              if (!bVar32) goto LAB_00987734;
              iVar19 = FUN_00984e3c(local_214,&local_1fc);
              if (iVar19 == 0) {
                param_1[0x66] = param_1[0x66] + 1;
                piVar24 = (int *)0x0;
                goto LAB_009875cc;
              }
              if (iVar19 != -2) goto LAB_00987734;
              bVar32 = false;
              FUN_00983230(iVar28);
              iVar28 = 0;
            } while( true );
          }
          FUN_009852b0();
          param_1[1] = (int)piVar23;
        }
        else {
          piVar23 = (int *)0xfffffff5;
        }
      }
    }
  }
  else {
    if (!bVar2 && !bVar31) {
      pcVar13 = FUN_009837c4;
      param_1[0x5b] = 3;
      piVar23 = &local_20c;
      goto LAB_00986d7c;
    }
    piVar23 = (int *)0xfffffffe;
  }
  goto LAB_00987168;
LAB_00987734:
  local_1f0 = *(undefined4 *)(&DAT_009b8474 + local_214 * 4);
  iVar19 = FUN_00982a34(local_1f4);
  if (iVar19 == 0) {
    iVar19 = FUN_00998f98(&UNK_009b59a4,*(undefined4 *)(&DAT_009b84f4 + local_214 * 4),&DAT_00983f0c
                          ,&local_1f4,&DAT_009b6d20,0x1500);
    if (iVar19 == 0) {
      uVar25 = 0;
      puVar11 = (undefined4 *)&DAT_009b4be4;
      do {
        uVar27 = 0;
        if ((uVar25 & 1) != 0) {
          uVar27 = 0xffffffff;
        }
        uVar25 = uVar25 + 1;
        FUN_00999358(&UNK_009b59a4);
        FUN_00999fb0(*puVar11,(iVar28 + 0x1fU & 0xffffffe0) + (uVar27 & 0x4204),0x1081,local_210);
        puVar11 = puVar11 + 1;
      } while (uVar25 != 0x41);
      if (_DAT_009b59b0 == 0x41) {
        iVar19 = FUN_00999f44(&UNK_009b59a4);
        piVar24 = (int *)0x0;
        if (iVar19 != 0) {
          piVar24 = (int *)0xfffffffe;
        }
        goto LAB_0098781c;
      }
    }
    piVar24 = (int *)0xfffffffe;
  }
  else {
    piVar24 = (int *)0xfffffffd;
  }
LAB_0098781c:
  param_1[100] = param_1[100] + (uint)(piVar24 == (int *)0x0);
  if ((piVar24 == (int *)0x0) && (_DAT_009b5960 == 0)) {
    FUN_009835d4(local_214);
  }
LAB_009875cc:
  FUN_00983230(iVar28);
LAB_009875d4:
  FUN_00982a90(piVar23,0);
  if (piVar24 == (int *)0x0) {
    uVar25 = 0;
    puVar22 = &DAT_009b4b90;
    do {
      if (uVar25 < 8) {
        uVar16 = (&UNK_009a8b3c)[uVar25];
      }
      else {
        uVar16 = 0;
      }
      uVar25 = uVar25 + 1;
      *puVar22 = uVar16;
      puVar22 = puVar22 + 1;
    } while (uVar25 != 0x54);
    pcVar14 = &UNK_009b8377;
    DAT_009b4b98 = 0x41;
    _DAT_009b4b9c = 8000;
    _DAT_009b4ba0 = 0x7a12;
    iVar28 = 0;
    pcVar17 = &DAT_009b4ba4;
    do {
      pcVar14 = pcVar14 + 1;
      pcVar26 = pcVar17;
      if (*pcVar14 == '\0') break;
      iVar28 = iVar28 + 1;
      pcVar26 = pcVar17 + 1;
      *pcVar17 = *pcVar14;
      pcVar17 = pcVar26;
    } while (iVar28 != 8);
    *pcVar26 = ' ';
    cVar5 = DAT_009b8460;
    pcVar26[3] = ' ';
    pcVar26[1] = cVar5 + 'A';
    pcVar26[2] = DAT_009b8464 + 'A';
    pcVar26[4] = (char)local_218 + 'a';
    pcVar26[6] = ' ';
    pcVar26[5] = (char)local_214 + 'a';
    pcVar26[7] = (char)(uVar12 / 10) + '0';
    FUN_009a5e2c(uVar12,10,uVar12 * -0x33333333);
    pcVar26[8] = extraout_r1 + '0';
    piVar24 = (int *)FUN_00994150(&UNK_009de8c4,&DAT_009b4b90,&DAT_009b4be4,_DAT_009b8578);
  }
  iVar28 = FUN_00983244();
  param_1[0x65] = (param_1[0x65] - iVar7) + iVar28;
  if (piVar24 == (int *)0x0) {
    _DAT_009de8a4 = 1;
    _DAT_009b8220 = 0;
    _DAT_009b8224 = _DAT_009b8460;
    _DAT_009b8228 = _DAT_009b8464;
    _DAT_009b822c = local_218;
    _DAT_009b8230 = local_214;
    _DAT_009b8234 = local_210;
    param_1[2] = param_1[2] + 1;
LAB_009878b8:
    if (_DAT_009de8a8 != 0) {
      iVar7 = _DAT_009b846c + _DAT_009b8468 * 0x10;
      if (iVar7 != DAT_009b4944) {
        iVar28 = 0;
        _DAT_009de8ac = 0;
        DAT_009b4944 = iVar7;
        iVar7 = FUN_00983d0c(local_1dc,&DAT_009b82d8,1);
        uVar12 = _DAT_009de8a8;
        if (iVar7 < 0) goto LAB_009878fc;
        iVar8 = FUN_00983e48(local_1dc,0,_DAT_009de8a8,0x30);
        iVar19 = _DAT_009b8388;
        bVar32 = iVar8 == 0;
        pcVar17 = &DAT_009a8b4c;
        while( true ) {
          bVar33 = bVar32;
          if (iVar28 == 8) {
            bVar33 = false;
          }
          if (!bVar33) break;
          pcVar14 = (char *)(uVar12 + iVar28);
          iVar28 = iVar28 + 1;
          bVar32 = *pcVar14 == *pcVar17;
          pcVar17 = pcVar17 + 1;
        }
        bVar33 = false;
        iVar28 = _DAT_009b838c;
        if (bVar32) {
          uVar34 = FUN_00983374(uVar12 + 8);
          iVar28 = (int)((ulonglong)uVar34 >> 0x20);
          if ((int)uVar34 == iVar28) {
            uVar34 = FUN_00983374(uVar12 + 0xc);
            iVar28 = (int)((ulonglong)uVar34 >> 0x20);
            bVar33 = (int)uVar34 == iVar19;
          }
          else {
            bVar33 = false;
          }
        }
        pcVar17 = &UNK_009b8437;
        pcVar14 = (char *)(uVar12 + 0xf);
        while ((bVar33 && ((char *)(uVar12 + iVar28 + 0xf) != pcVar14))) {
          pcVar14 = pcVar14 + 1;
          pcVar17 = pcVar17 + 1;
          bVar33 = *pcVar14 == *pcVar17;
        }
        pcVar17 = &UNK_009b8427;
        pcVar14 = (char *)(uVar12 + 0x1f);
        while (uVar25 = 0, bVar33) {
          if ((char *)(uVar12 + iVar19 + 0x1f) == pcVar14) {
            iVar28 = FUN_00983e48(local_1dc,(_DAT_009b8468 * iVar19 + _DAT_009b846c) * 0xfe58 + 0x30
                                  ,_DAT_009de8a8,0xfe58);
            if (iVar28 == 0) {
              iVar28 = FUN_00994378(&UNK_009de8b0,_DAT_009de8a8,0xfe58);
              uVar25 = (uint)(iVar28 == 0);
            }
            else {
              uVar25 = 0;
            }
            break;
          }
          pcVar14 = pcVar14 + 1;
          pcVar17 = pcVar17 + 1;
          bVar33 = *pcVar14 == *pcVar17;
        }
        FUN_00982a90(iVar7,0);
        _DAT_009de8ac = uVar25;
      }
      if (_DAT_009de8ac != 0) {
        FUN_00994488(&UNK_009de8b0,_DAT_009b8470);
      }
    }
LAB_009878fc:
    param_1[3] = _DAT_009de8ac;
    if ((_DAT_009b8574 == 0) || (_DAT_009b8574 == _DAT_009b8220)) {
LAB_00987c10:
      piVar23 = &iStack_74;
      piVar24 = param_1 + 0x16;
      do {
        piVar23 = piVar23 + 1;
        piVar24 = piVar24 + 1;
        *piVar24 = *piVar23;
      } while (param_1 + 0x1f != piVar24);
      uVar12 = 0x811c9dc5;
      param_1[0x20] = local_3c;
      param_1[0x21] = local_38;
      *param_1 = 3;
      local_234 = (byte *)(param_3 + -1);
      pbVar15 = local_234;
      while( true ) {
        pbVar15 = pbVar15 + 1;
        if (*pbVar15 == 0) break;
        uVar12 = (uVar12 ^ *pbVar15) * 0x1000193;
      }
      uVar12 = uVar12 | 1;
      local_24c = *(int *)(param_2 + 0x24);
      local_1dc[0] = 0;
      if (local_24c != 0) {
        uVar25 = 0;
        for (pcVar17 = &DAT_009b8238; *pcVar17 != '\0'; pcVar17 = pcVar17 + 1) {
          uVar25 = uVar25 + 1;
        }
        if (uVar25 < 8) {
          local_24c = 0;
        }
        else {
          puVar22 = &UNK_009b822f + uVar25;
          iVar7 = 0;
          puVar11 = local_1dc;
          do {
            puVar22 = puVar22 + 1;
            iVar7 = iVar7 + 1;
            *(undefined *)puVar11 = *puVar22;
            puVar11 = (undefined4 *)((int)puVar11 + 1);
          } while (iVar7 != 4);
          local_24c = FUN_00994d0c(local_1dc);
        }
      }
      uVar27 = *(uint *)(param_2 + 0x28);
      uVar25 = uVar27;
      if (0xff < uVar27) {
        uVar25 = 0x100;
      }
      bVar32 = local_24c != 0;
      puVar11 = param_4;
      puVar29 = param_4;
      local_248 = param_4;
      local_240 = param_4;
      if (bVar2 && bVar32) {
        if (!bVar2 || !bVar31) goto LAB_009883f4;
        uVar10 = FUN_00983c04(*(undefined4 *)(param_2 + 0x24),uVar12,local_1dc);
        if (uVar10 != 0xffffffff) {
          bVar33 = uVar10 == 0;
          param_1[0x67] = param_1[0x67] | 0x204;
          if (bVar33) {
            FUN_00983890();
            local_24c = 0;
          }
          bVar32 = !bVar33 && (bVar33 && bVar32);
          puVar29 = (undefined4 *)0x2;
          uVar25 = uVar10;
          goto LAB_00987f10;
        }
        iVar7 = FUN_009850ec(param_1);
        if (iVar7 != 0) goto LAB_00986fc0;
        uVar10 = FUN_0098487c(*(undefined4 *)(param_2 + 0x24),uVar12,local_1dc);
        if ((int)uVar10 < 0) {
          iVar7 = FUN_00982bd8(*(undefined4 *)(param_2 + 0x24));
          puVar29 = (undefined4 *)0x0;
          if (iVar7 != 0) {
            param_1[0x67] = param_1[0x67] | 0x40;
          }
          bVar32 = uVar27 != 0;
        }
        else {
          puVar29 = (undefined4 *)0x1;
          param_1[0x67] = param_1[0x67] | 4;
          bVar32 = false;
          uVar25 = uVar10;
        }
        if (uVar25 == 0) {
          FUN_0098326c();
          local_24c = 0;
        }
        if (!bVar32) goto LAB_00987f10;
        local_140 = local_26c;
        local_130 = local_25c;
        local_12c = local_264;
        local_158 = local_254;
        local_150 = local_258;
        local_148 = puVar18;
        local_144 = local_274;
        local_13c = local_268;
        local_138 = local_260;
        local_134 = local_250;
        local_25c = FUN_0098331c(local_164,4,0x4000);
        piVar23 = local_140;
        puVar18 = local_148;
        local_254 = local_158;
        local_258 = local_150;
        local_274 = local_144;
        local_26c = local_140;
        local_268 = local_13c;
        local_260 = local_138;
        local_250 = local_134;
        local_264 = local_12c;
        iVar7 = FUN_00983298(0xe,0x40f8);
        if (iVar7 != 0 && local_25c != 0) {
          FUN_00996174(piVar23,puVar18,auStack_d0,&UNK_009de8c4,0,local_25c);
          piVar23[0x2084] = (int)FUN_009841e4;
          piVar23[0x2085] = (int)&local_1c4;
          FUN_00994db0(piVar23,&DAT_009de810,local_24c,iVar7);
          param_1[0x67] = param_1[0x67] | 8;
          goto LAB_00987f10;
        }
        goto LAB_00987e84;
      }
      if (iVar6 == 0) {
LAB_009883f4:
        bVar32 = false;
LAB_00988374:
        if (param_4 == (undefined4 *)0x0) goto LAB_009883e0;
        puVar29 = (undefined4 *)0x0;
LAB_00987f10:
        local_240 = (undefined4 *)FUN_00985ddc(param_3,param_4);
        puVar11 = (undefined4 *)FUN_00985bbc();
        if ((!bVar2 || !bVar31) || (_DAT_009b5828 == 0 || puVar11 == (undefined4 *)0x0)) {
          if (puVar11 != (undefined4 *)0x0) goto LAB_00988408;
          local_248 = (undefined4 *)0x0;
          goto LAB_009883e0;
        }
        if ((puVar11[3] == 0) || (bVar32 || _DAT_009e70b8 != 0)) {
LAB_00988408:
          *puVar11 = 0;
          local_248 = (undefined4 *)0x0;
          goto LAB_009883e0;
        }
        iVar7 = FUN_00990d70(puVar18,local_268,local_264,puVar11 + 7,puVar11[6]);
        if (iVar7 != 0) {
          bVar32 = false;
          goto LAB_00988408;
        }
        param_1[0x31] = 2;
        local_248 = (undefined4 *)0x1;
        iVar7 = 0;
        bVar32 = false;
      }
      else {
        FUN_00996174(local_26c,puVar18,auStack_d0,&UNK_009de8c4,local_260,local_25c);
        local_26c[0x2084] = (int)FUN_009841e4;
        local_26c[0x2085] = (int)&local_1c4;
        local_1b4 = *(int *)(puVar18 + 0xc4) * *(int *)(puVar18 + 0x24);
        if (uVar27 == 0 || !bVar32) goto LAB_009883f4;
        if (param_4 == (undefined4 *)0x0) {
          piVar23 = (int *)FUN_00983298(0,0x5a00);
          piVar24 = (int *)FUN_00983298(7,0x5a00);
          if (piVar24 != (int *)0x0 && piVar23 != (int *)0x0) {
            iVar7 = 0;
            ppiVar20 = local_128;
            do {
              iVar7 = iVar7 + 1;
              *ppiVar20 = piVar23;
              ppiVar20[7] = piVar24;
              ppiVar20 = ppiVar20 + 1;
            } while (iVar7 != 7);
            FUN_00994d88(&DAT_009de810,local_128);
            goto LAB_009882f0;
          }
          FUN_009850b0(param_1);
          FUN_0098326c();
          goto LAB_009882a8;
        }
        iVar7 = FUN_009850ec(param_1);
        if (iVar7 == 0) {
LAB_009882f0:
          iVar7 = FUN_00983298(0xe,0x40f8);
          if (iVar7 == 0) {
            if (param_4 == (undefined4 *)0x0) goto LAB_009882a8;
            goto LAB_009883a8;
          }
          if ((param_4 == (undefined4 *)0x0) &&
             (iVar28 = FUN_00983f64(*(undefined4 *)(param_2 + 0x24)), iVar28 != 0)) {
LAB_009882a8:
            if (-1 < DAT_009b4938) {
              FUN_00984058(*(undefined4 *)(param_2 + 0x24),0,local_1dc);
            }
            goto LAB_009883a8;
          }
          FUN_00994db0(local_26c,&DAT_009de810,local_24c,iVar7);
          if (param_4 == (undefined4 *)0x0) {
            uVar27 = param_1[0x67];
            local_26c[0x2081] = (int)FUN_00984820;
            local_26c[0x2082] = 0;
            param_1[0x67] = uVar27 | 0x100;
          }
          bVar32 = true;
          param_1[0x67] = param_1[0x67] | 1;
          goto LAB_00988374;
        }
LAB_009883a8:
        FUN_009850b0(param_1);
        FUN_0098326c();
        param_1[0x67] = param_1[0x67] | 0x20;
        if (param_4 != (undefined4 *)0x0) goto LAB_00986fc0;
        bVar32 = false;
LAB_009883e0:
        iVar7 = -1;
      }
      if ((bool)((bVar32 ^ 1U) & bVar2)) {
        puVar22 = &UNK_009b53a8;
        for (local_23c = 0; local_23c != 0x10 && iVar7 != 0; local_23c = local_23c + 1) {
          if ((*(uint *)(puVar22 + -4) == uVar12) &&
             (iVar28 = FUN_00990c24(puVar18,local_268), iVar28 == 0)) {
            param_1[0x31] = 1;
            iVar7 = 0;
          }
          puVar22 = puVar22 + 0x48;
        }
      }
      piVar23 = (int *)0x0;
      if (iVar7 != 0) {
        if (iVar6 == 0) {
          bVar2 = false;
          pcVar13 = FUN_0098417c;
LAB_00988010:
          *(code **)(puVar18 + 0x3844) = pcVar13;
          *(int **)(puVar18 + 0x3848) = &local_1c4;
        }
        else {
          bVar2 = true;
          if ((*(int *)(param_2 + 0x2c) == local_260) && (*(int *)(param_2 + 0x30) != 0)) {
            pcVar13 = (code *)&LAB_00983798;
            goto LAB_00988010;
          }
        }
        local_128[0] = local_26c;
        local_158 = local_254;
        local_150 = local_258;
        local_144 = local_274;
        local_140 = local_26c;
        local_13c = local_268;
        local_138 = local_260;
        local_134 = local_250;
        local_130 = local_25c;
        local_12c = local_264;
        local_148 = puVar18;
        local_128[1] = param_1;
        FUN_00985158(local_164,1);
        puVar18 = local_148;
        local_254 = local_158;
        local_258 = local_150;
        local_274 = local_144;
        local_26c = local_140;
        local_268 = local_13c;
        local_260 = local_138;
        local_250 = local_134;
        local_25c = local_130;
        local_264 = local_12c;
        pcVar13 = FUN_0098426c;
        if (!bVar2 && !bVar32) {
          pcVar13 = (code *)0x0;
        }
        piVar23 = (int *)FUN_009906b4(local_148,local_13c,local_12c,pcVar13,local_128);
        if (piVar23 == (int *)0xfffffffa) {
          piVar23 = (int *)0xfffffff2;
        }
        else if (piVar23 == (int *)0x0) {
          iVar7 = (_DAT_009b53a0 & 0xf) * 0x48;
          *(uint *)(&DAT_009b53a4 + iVar7) = uVar12;
          FUN_00990b2c(puVar18,&UNK_009b53a8 + iVar7);
          _DAT_009b53a0 = _DAT_009b53a0 + 1;
        }
      }
      iVar7 = FUN_00983244();
      param_1[0x26] = iVar7;
      if (piVar23 != (int *)0x0) goto LAB_00987168;
      if (iVar6 == 0) {
        if (bVar32) {
          thunk_FUN_00991d5c(local_26c);
          goto LAB_00989008;
        }
LAB_00988490:
        if (param_4 != (undefined4 *)0x0) goto LAB_0098849c;
LAB_009890a0:
        iVar6 = FUN_00983244();
        param_1[0x28] = iVar6;
      }
      else {
        thunk_FUN_00991d5c(local_26c);
        iVar6 = FUN_00983244();
        param_1[0x27] = iVar6;
        param_1[0xb] = param_1[10];
        *param_1 = 4;
        if (((*(int *)(param_2 + 0x1c) != 0) && (*(code **)(param_2 + 0x20) != (code *)0x0)) &&
           (iVar6 = (**(code **)(param_2 + 0x20))(*(undefined4 *)(param_2 + 0xc)), iVar6 == 0)) {
          param_1[0x5c] = 1;
LAB_00988fc4:
          piVar23 = (int *)0xffffffeb;
          goto LAB_00987168;
        }
        (**(code **)(param_2 + 8))(*(undefined4 *)(param_2 + 0xc),local_260);
        FUN_00983230(local_258);
        if (!bVar32) {
          local_260 = 0;
          local_258 = 0;
          goto LAB_00988490;
        }
        local_258 = 0;
        local_260 = 0;
LAB_00989008:
        iVar6 = local_26c[0x2081];
        if (iVar6 != 0) {
          FUN_00984820(0,local_26c[0x2083]);
          local_26c[0x2081] = 0;
        }
        local_26c[0x2073] = 0;
        FUN_00983230(_DAT_009de884);
        _DAT_009de884 = 0;
        uVar30 = *(undefined4 *)(param_2 + 0x24);
        if (iVar6 == 0) {
          FUN_00983f64(uVar30);
          iVar6 = 0;
          do {
            iVar7 = iVar6 + 1;
            FUN_00984674(iVar6,0);
            iVar6 = iVar7;
          } while (iVar7 != 7);
        }
        iVar6 = FUN_00984058(uVar30,uVar12);
        if (iVar6 == 0) {
          param_1[0x67] = param_1[0x67] | 2;
        }
        if (param_4 == (undefined4 *)0x0) {
          FUN_0098326c();
          goto LAB_009890a0;
        }
        puVar29 = (undefined4 *)0x1;
LAB_0098849c:
        iVar6 = 0;
        FUN_0098319c(local_274,0x1e2d0);
        *(undefined4 *)(local_274 + 0x1e2c8) = 0;
        if (puVar29 == (undefined4 *)0x2 && (local_24c != 0 && uVar25 != 0)) {
          _DAT_009de7f0 = FUN_00983298(0x13,0xbb20);
          if (_DAT_009de7f0 == 0) {
LAB_00987e84:
            FUN_009850b0(param_1);
            goto LAB_00986fc0;
          }
          puVar29 = (undefined4 *)&DAT_009de810;
          while( true ) {
            iVar7 = 0;
            puVar21 = puVar29;
            do {
              iVar7 = iVar7 + 1;
              *puVar21 = 0;
              puVar21 = puVar21 + 1;
            } while (iVar7 != 7);
            iVar7 = 0;
            while( true ) {
              iVar28 = FUN_00983298(iVar7 + iVar6,0x5a00);
              if (iVar28 == 0) {
                FUN_009850b0(param_1);
                goto LAB_00987e84;
              }
              if (iVar7 == 1) break;
              iVar7 = 1;
            }
            puVar29 = puVar29 + 7;
            if (iVar6 != 0) break;
            iVar6 = 7;
          }
          _DAT_009de848 = 1;
          FUN_00994f70(&UNK_009de7c8,&DAT_009de810,local_24c,uVar25,local_3c,local_38);
          _DAT_009de808 = &LAB_009842c4;
          _DAT_009de80c = 0;
          *(undefined **)(local_274 + 0x1e2c8) = &UNK_009de7c8;
        }
        else if (puVar29 != (undefined4 *)0x0 && (local_24c != 0 && uVar25 != 0)) {
          iVar6 = FUN_00983244();
          iVar7 = 0xf;
          puVar29 = (undefined4 *)&UNK_009de7dc;
          while( true ) {
            uVar30 = FUN_00983298(iVar7,0x6270);
            puVar29[1] = uVar30;
            uVar30 = FUN_00983298(iVar7 + 2,0x9678);
            puVar29[3] = uVar30;
            if (iVar7 == 0x10) break;
            iVar7 = 0x10;
            puVar29 = puVar29 + 1;
          }
          _DAT_009de7f0 = FUN_00983298(0x13,0xbb20);
          if (((_DAT_009de7e0 == 0) || (_DAT_009de7e4 == 0)) ||
             ((_DAT_009de7e8 == 0 || (_DAT_009de7f0 == 0 || _DAT_009de7ec == 0))))
          goto LAB_00987e84;
          iVar7 = 0;
          FUN_00994f70(&UNK_009de7c8,&DAT_009de810,local_24c,uVar25,local_3c,local_38);
          puVar29 = (undefined4 *)&DAT_009de884;
          do {
            puVar29 = puVar29 + 1;
            iVar7 = iVar7 + 1;
            FUN_00983230(*puVar29);
            *puVar29 = 0;
          } while (iVar7 != 4);
          *(undefined **)(local_274 + 0x1e2c8) = &UNK_009de7c8;
          param_1[0x67] = param_1[0x67] | 0x10;
          iVar7 = FUN_00983244();
          param_1[0x68] = iVar7 - iVar6;
        }
        *param_1 = 5;
        local_1b0 = local_38 + 7U >> 3;
        *(undefined1 **)(local_274 + 0x17c00) = &LAB_0098388c;
        *(code **)(local_274 + 0x17bf8) = FUN_00985c78;
        *(int **)(local_274 + 0x17bfc) = &local_1c4;
        puVar22 = &UNK_009de8b0;
        if (_DAT_009de8ac == 0) {
          puVar22 = (undefined *)0x0;
        }
        *(undefined **)(local_274 + 0x17c28) = puVar22;
        uVar12 = 0x811c9dc5;
        while( true ) {
          local_234 = local_234 + 1;
          if (*local_234 == 0) break;
          uVar12 = (uVar12 ^ *local_234) * 0x1000193;
        }
        *(uint *)(local_274 + 0x17c2c) = uVar12;
        iVar6 = FUN_00996940(&UNK_009b4f6c,0x400,puVar18,auStack_d0,*(undefined4 *)(param_2 + 0x10))
        ;
        puVar22 = &UNK_009b4f6c;
        if (iVar6 == 0) {
          puVar22 = (undefined *)0x0;
        }
        *(int *)(local_274 + 0x17c18) = iVar6;
        *(undefined **)(local_274 + 0x17c14) = puVar22;
        FUN_00990b2c(puVar18,&UNK_009b4f28);
        pcVar17 = &DAT_009b4ef8;
        for (uVar12 = 0; *(char *)((int)param_4 + uVar12) != '\0'; uVar12 = uVar12 + 1) {
          if (uVar12 == 0x2f) {
            DAT_009b4f27 = 0;
            goto LAB_00988684;
          }
          *pcVar17 = *(char *)((int)param_4 + uVar12);
          pcVar17 = pcVar17 + 1;
        }
        (&DAT_009b4ef8)[uVar12] = 0;
        if (4 < uVar12) {
LAB_00988684:
          if ((&DAT_009b4ef4)[uVar12] == '.') {
            (&UNK_009b4ef5)[uVar12] = 0x50;
            (&UNK_009b4ef6)[uVar12] = 0x52;
            (&UNK_009b4ef7)[uVar12] = 0x54;
          }
        }
        if (local_254 != 0) {
          FUN_009836e4();
          local_170 = 0;
          local_16c = 0;
          FUN_00983230(local_254);
          local_250 = 0;
        }
        FUN_00985044(param_1 + 0x59,param_1 + 0x5a);
        if (_DAT_009b4ef4 == 0 && _DAT_009e70b8 == 0) {
          if (local_248 == (undefined4 *)0x0) {
            iVar6 = FUN_00989eac(&UNK_009b4e90,&DAT_009b4ef8,local_3c,local_38,4,
                                 *(undefined4 *)(local_274 + 0x17c14),
                                 *(undefined4 *)(local_274 + 0x17c18));
          }
          else {
            iVar6 = FUN_00989d50(&UNK_009b4e90,&DAT_009b4ef8,local_3c,local_38,4,puVar11[1],
                                 puVar11[2]);
          }
          if (iVar6 == 0) {
            *(code **)(local_274 + 0x17c1c) = FUN_00989f5c;
            *(undefined **)(local_274 + 0x17c20) = &UNK_009b4e90;
            *(undefined4 *)(local_274 + 0x17c24) = 1;
            _DAT_009b4e3c = 0;
            if (local_248 == (undefined4 *)0x0) {
              puVar22 = (undefined *)0x0;
            }
            else {
              FUN_009975a8(&UNK_009b4de8,puVar11 + 3,0x54);
              puVar22 = &UNK_009b4de8;
            }
            *(undefined **)(local_274 + 0x1e2c0) = puVar22;
            *(undefined **)(local_274 + 0x1e2c4) = &DAT_009b4e3c;
            local_1a0 = &DAT_009b4e3c;
            puVar22 = (undefined *)0x0;
            if (local_248 != (undefined4 *)0x0) {
              puVar22 = &UNK_009b4de8;
            }
            local_1a8 = &UNK_009b4e90;
            if (local_248 != (undefined4 *)0x0) {
              param_1[0x29] = *(uint *)(puVar22 + 4) >> 3;
            }
            local_1a4 = local_240;
            if (*(int *)(local_274 + 0x1e2c8) != 0) {
              if (local_248 == (undefined4 *)0x0) {
                uVar30 = 0;
              }
              else {
                uVar30 = _DAT_009b4dec;
              }
              FUN_00984b10(local_274,*(undefined4 *)(param_2 + 0x24),local_3c,local_38,uVar30);
            }
            local_150 = local_258;
            local_144 = local_274;
            local_140 = local_26c;
            local_158 = 0;
            local_13c = local_268;
            local_138 = local_260;
            local_134 = local_250;
            local_130 = local_25c;
            local_12c = local_264;
            local_148 = puVar18;
            FUN_00985158(local_164,1);
            puVar22 = local_144;
            puVar18 = local_148;
            local_254 = local_158;
            local_258 = local_150;
            local_274 = local_144;
            local_26c = local_140;
            local_268 = local_13c;
            local_260 = local_138;
            local_250 = local_134;
            local_25c = local_130;
            local_264 = local_12c;
            piVar23 = (int *)FUN_00996db4(local_144,local_148,auStack_d0,&UNK_009de8c4,0,0,0x5c);
            iVar6 = FUN_009845bc(puVar22,piVar23 == (int *)0x0);
            if (iVar6 != 0) {
              param_1[0x67] = param_1[0x67] | 0x80;
            }
            *(undefined4 *)(puVar22 + 0x1e2c4) = 0;
            *(undefined4 *)(puVar22 + 0x1e2c0) = 0;
            local_1a8 = (undefined *)0x0;
            *(undefined4 *)(puVar22 + 0x17c1c) = 0;
            *(undefined4 *)(puVar22 + 0x17c24) = 0;
            if (piVar23 != (int *)0xfffffff2) {
              iVar7 = FUN_0098a170(&UNK_009b4e90);
              param_1[0x33] = _DAT_009b4ed0;
              iVar6 = _DAT_009b4ed4;
              param_1[0x39] = iVar7;
              param_1[0x34] = iVar6;
              param_1[0x35] = _DAT_009b4ed8;
              param_1[0x36] = _DAT_009b4edc;
              param_1[0x37] = _DAT_009b4ee0;
              param_1[0x38] = _DAT_009b4ee4;
              piVar24 = (int *)0x0;
              if (piVar23 != (int *)0x0 || iVar7 != 0) {
                if ((piVar23 == (int *)0x0) && (_DAT_009b4ec4 == 0)) {
                  _DAT_009b4ef4 = 1;
                  piVar23 = (int *)0x0;
                }
                goto LAB_00988bb8;
              }
LAB_00988dd8:
              *param_1 = 7;
              goto LAB_00988de0;
            }
            iVar6 = FUN_00989e14();
            if (((iVar6 == 0) && (_DAT_009b4e3c != 0)) && (_DAT_009b5828 != 0)) {
              puVar11 = (undefined4 *)FUN_00985c08(local_240);
              *puVar11 = local_240;
              puVar11[1] = _DAT_009b4eb4;
              puVar11[2] = _DAT_009b4ee0;
              FUN_009975a8(puVar11 + 3,&DAT_009b4e3c,0x54);
              param_1[0x32] = 1;
              if (*(code **)(param_2 + 0x18) != (code *)0x0) {
                (**(code **)(param_2 + 0x18))(*(undefined4 *)(param_2 + 0xc));
              }
            }
            else {
              FUN_00985dc4(local_240);
              FUN_00982bac(&DAT_009b4ef8);
            }
            param_1[0x33] = _DAT_009b4ed0;
            iVar6 = _DAT_009b4edc;
            param_1[0x35] = _DAT_009b4ed8;
            param_1[0x36] = iVar6;
            param_1[0x2a] = *(int *)(puVar22 + 0x17c08);
            iVar6 = *(int *)(puVar22 + 0x17c10);
            param_1[0x2b] = *(int *)(puVar22 + 0x17c0c);
            param_1[0x2c] = iVar6;
          }
          else {
            iVar7 = FUN_0098a170(&UNK_009b4e90);
            param_1[0x39] = iVar7 + -10;
            local_254 = 0;
            piVar23 = (int *)0x0;
            if (iVar6 != -7) {
LAB_00988bb8:
              FUN_00985dc4(local_240);
              if (local_248 != (undefined4 *)0x0) goto LAB_00988fc4;
              piVar24 = piVar23;
              if ((piVar23 == (int *)0x0) &&
                 (piVar24 = (int *)FUN_00990c24(puVar18,local_268,local_264,&UNK_009b4f28),
                 piVar24 == (int *)0x0)) goto LAB_00988bf0;
LAB_00988de0:
              FUN_00985dc4(local_240);
              if (piVar24 == (int *)0x0) {
                if (*param_1 != 7) goto LAB_00988fb8;
                FUN_00982bac(param_4);
                if ((_DAT_009b5824 == 0) ||
                   (iVar6 = FUN_00982b14(&DAT_009b4ef8,param_4), iVar6 != 0)) {
LAB_00988e38:
                  iVar6 = FUN_0098289c(&DAT_009b4ef8);
                  if (-1 < iVar6) {
                    uVar12 = FUN_00982a68();
                    if ((int)uVar12 < 0) {
                      bVar2 = false;
                      iVar7 = -1;
                    }
                    else {
                      iVar7 = FUN_009828c0(param_4);
                      if (iVar7 < 0) {
                        bVar2 = false;
                      }
                      else {
                        iVar28 = FUN_00982a34(iVar6,0);
                        bVar2 = iVar28 == 0;
                      }
                    }
                    uVar25 = 0;
                    while( true ) {
                      bVar31 = bVar2;
                      if (uVar12 <= uVar25) {
                        bVar31 = false;
                      }
                      if (!bVar31) break;
                      uVar27 = uVar12 - uVar25;
                      if (local_264 <= uVar12 - uVar25) {
                        uVar27 = local_264;
                      }
                      iVar28 = FUN_0098293c(iVar6,local_268,uVar27);
                      if (iVar28 == 0) {
                        iVar28 = FUN_009829b8(iVar7,local_268,uVar27);
                        bVar2 = iVar28 == 0;
                      }
                      else {
                        bVar2 = false;
                      }
                      uVar25 = uVar25 + uVar27;
                    }
                    FUN_00982a90(iVar6);
                    if (((iVar7 < 0) || (iVar6 = FUN_00982a90(iVar7,1), iVar6 == 0)) && (bVar2))
                    goto LAB_00988fb8;
                    FUN_00982bac(param_4);
                  }
                  FUN_00982bac(&DAT_009b4ef8);
                  piVar23 = (int *)0xfffffffc;
                }
                else {
                  iVar6 = FUN_00982bd8(param_4);
                  piVar23 = (int *)0x0;
                  if (iVar6 == 0) goto LAB_00988e38;
                }
              }
              else {
                if (piVar24 != (int *)0xfffffff2) {
LAB_00988fb8:
                  FUN_00982bac(&DAT_009b4ef8);
                }
                piVar23 = piVar24;
              }
              param_1[0x2a] = *(int *)(local_274 + 0x17c08);
              iVar6 = *(int *)(local_274 + 0x17c10);
              param_1[0x2b] = *(int *)(local_274 + 0x17c0c);
              param_1[0x2c] = iVar6;
              goto LAB_009890a0;
            }
            piVar23 = (int *)0xfffffff9;
          }
        }
        else {
          local_254 = 0;
LAB_00988bf0:
          local_158 = local_254;
          local_150 = local_258;
          local_144 = local_274;
          local_140 = local_26c;
          local_13c = local_268;
          local_138 = local_260;
          local_134 = local_250;
          local_130 = local_25c;
          local_12c = local_264;
          local_148 = puVar18;
          _DAT_009b58ec = FUN_0098331c(local_164,6,0x4000);
          puVar22 = local_144;
          puVar18 = local_148;
          local_254 = local_158;
          local_258 = local_150;
          local_274 = local_144;
          local_26c = local_140;
          local_268 = local_13c;
          local_260 = local_138;
          local_250 = local_134;
          local_25c = local_130;
          local_264 = local_12c;
          if (_DAT_009b58ec == 0) goto LAB_00986fc0;
          piVar23 = (int *)FUN_009828c0(&DAT_009b4ef8);
          local_128[1] = (int *)0x0;
          local_128[0] = piVar23;
          local_128[2] = param_1;
          if (-1 < (int)piVar23) {
            if (*(int *)(puVar22 + 0x1e2c8) != 0) {
              FUN_00984b10(puVar22,*(undefined4 *)(param_2 + 0x24),local_3c,local_38,0);
            }
            FUN_00985158(local_164,1);
            puVar22 = local_144;
            puVar18 = local_148;
            local_254 = local_158;
            local_258 = local_150;
            local_274 = local_144;
            local_26c = local_140;
            local_268 = local_13c;
            local_260 = local_138;
            local_250 = local_134;
            local_25c = local_130;
            local_264 = local_12c;
            piVar24 = (int *)FUN_00996db4(local_144,local_148,auStack_d0,&UNK_009de8c4,FUN_0098440c,
                                          local_128,0x5c);
            iVar6 = FUN_009845bc(puVar22,piVar24 == (int *)0x0);
            if (iVar6 != 0) {
              param_1[0x67] = param_1[0x67] | 0x80;
            }
            if (piVar24 == (int *)0x0) {
              iVar6 = FUN_00984394(local_128);
              if (iVar6 == 0) {
                *param_1 = 6;
                piVar24 = (int *)0x0;
              }
              else {
                piVar24 = (int *)0xfffffffc;
              }
            }
            iVar6 = FUN_00982a90(local_128[0],1);
            if (iVar6 == 0 && piVar24 == (int *)0x0) goto LAB_00988dd8;
            goto LAB_00988de0;
          }
        }
      }
    }
    else {
      if (_DAT_009de8a0 != (char *)0x0) {
LAB_00987978:
        piVar23 = (int *)FUN_00983d0c(local_1dc,&DAT_009b8238,0);
        if (-1 < (int)piVar23) {
          iVar7 = FUN_00983e48(local_1dc,_DAT_009b8574,_DAT_009de8a0,0x3004);
          FUN_00982a90(piVar23,0);
          if (iVar7 == 0) {
            if ((((*_DAT_009de8a0 == 'L') && (_DAT_009de8a0[1] == 'T')) && (_DAT_009de8a0[2] == 'V')
                ) && (_DAT_009de8a0[3] == 'C')) {
              _DAT_009deb10 = _DAT_009de8a0 + 4;
              _DAT_009deb18 = _DAT_009de8a0 + 0x2004;
              _DAT_009deb14 = _DAT_009de8a0 + 0x1004;
              _DAT_009b8220 = _DAT_009b8574;
              param_1[4] = param_1[4] + 1;
              goto LAB_00987c10;
            }
            piVar23 = (int *)0xfffffffe;
          }
          else {
            piVar23 = (int *)0xfffffffd;
          }
        }
        _DAT_009b8220 = 0;
        _DAT_009deb10 = (char *)(_DAT_009b8578 + 0x10002);
        _DAT_009deb14 = _DAT_009deb10;
        _DAT_009deb18 = _DAT_009deb10;
        goto LAB_009876fc;
      }
      if (_DAT_009b857c < 0x14) {
        iVar7 = thunk_EXT_FUN_ffb2f664(0x3024);
        if (iVar7 != 0) {
          iVar28 = _DAT_009b857c * 4;
          _DAT_009b857c = _DAT_009b857c + 1;
          *(int *)(&DAT_009b8580 + iVar28) = iVar7;
          _DAT_009de8a0 = (char *)(iVar7 + 0x1fU & 0xffffffe0);
          goto LAB_00987978;
        }
LAB_00986fb8:
        param_1[1] = -7;
      }
LAB_00986fc0:
      piVar23 = (int *)0xfffffff9;
    }
  }
  else {
    FUN_009852b0();
    piVar23 = piVar24;
LAB_009876fc:
    param_1[1] = (int)piVar23;
  }
LAB_00987168:
  if (-1 < DAT_009b4938) {
    DAT_009b493c = 1;
    FUN_00984058(*(undefined4 *)(param_2 + 0x24),0,local_1dc);
  }
  FUN_009836e4();
  iVar6 = 0;
  piVar24 = local_19c;
  do {
    if (-1 < *piVar24) {
      FUN_00982a90(*piVar24,0);
    }
    iVar6 = iVar6 + 1;
    piVar24 = piVar24 + 1;
  } while (iVar6 != 3);
  local_170 = 0;
  if (-1 < DAT_009b4920) {
    if (DAT_009b4924 == 0) {
      FUN_00983890();
      if (piVar23 == (int *)0x0) {
        FUN_009832dc(local_128,*(undefined4 *)(param_2 + 0x24));
        FUN_00982bac(local_128);
      }
    }
    else if (piVar23 == (int *)0x0) {
      FUN_00983890();
      piVar23 = (int *)0xfffffff9;
    }
    else {
      FUN_00983890();
    }
  }
  FUN_00989c5c();
  local_158 = local_254;
  local_150 = local_258;
  local_144 = local_274;
  local_140 = local_26c;
  local_13c = local_268;
  local_138 = local_260;
  local_134 = local_250;
  local_130 = local_25c;
  local_12c = local_264;
  local_148 = puVar18;
  FUN_00983710(local_164);
  FUN_00985044(param_1 + 0x57,param_1 + 0x58);
  _DAT_c02200f0 = 0x44;
  param_1[0x51] = _DAT_009b4aa4 - iVar3;
  param_1[0x52] = _DAT_009b4aa8 - iVar4;
LAB_00986648:
  param_1[1] = (int)piVar23;
  return piVar23;
}


// ===== FUN_0098912c @ 0098912c

void FUN_0098912c(int param_1)

{
  uint *puVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  uint *puVar5;
  int *local_c4;
  int *local_c0;
  int local_b8;
  int local_a8 [3];
  uint uStack_9c;
  uint local_98 [12];
  int local_68 [17];
  
  FUN_00997590(local_98,0,0x20);
  iVar2 = 0;
  puVar5 = &DAT_009a8b54;
  puVar1 = &uStack_9c;
  do {
    iVar2 = iVar2 + 1;
    puVar1 = puVar1 + 1;
    *puVar1 = *puVar5 ^ puVar5[8];
    puVar5 = puVar5 + 1;
  } while (iVar2 != 8);
  iVar2 = 0;
  piVar4 = local_a8;
  piVar3 = local_68;
  do {
    iVar2 = iVar2 + 1;
    *piVar3 = *piVar4;
    piVar4 = piVar4 + 1;
    piVar3 = piVar3 + 1;
  } while (iVar2 != 0x10);
  local_b8 = 10;
  do {
    local_b8 = local_b8 + -1;
  } while (local_b8 != 0);
  piVar4 = (int *)(param_1 + -4);
  local_c4 = local_a8;
  local_c0 = local_68;
  do {
    piVar4 = piVar4 + 1;
    *piVar4 = *local_c0 + *local_c4;
    local_c4 = local_c4 + 1;
    local_c0 = local_c0 + 1;
  } while ((int *)(param_1 + 0x3c) != piVar4);
  return;
}


// ===== FUN_0098943c @ 0098943c

void FUN_0098943c(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  *param_1 = *param_2;
  param_1[1] = *param_3;
  param_1[2] = 0x4c54;
  return;
}


// ===== FUN_0098948c @ 0098948c

void FUN_0098948c(byte *param_1,int param_2,uint param_3,undefined4 param_4)

{
  uint uVar1;
  byte *pbVar2;
  uint local_58 [16];
  
  uVar1 = param_3 >> 6;
  pbVar2 = param_1 + param_2;
  param_3 = param_3 & 0x3f;
  FUN_0098912c(local_58,param_4,uVar1);
  for (; pbVar2 != param_1; param_1 = param_1 + 1) {
    if (param_3 == 0x40) {
      uVar1 = uVar1 + 1;
      FUN_0098912c(local_58,param_4,uVar1);
      param_3 = 0;
    }
    *param_1 = *param_1 ^
               (byte)(*(uint *)((int)local_58 + (param_3 & 0xfffffffc)) >> ((param_3 & 3) << 3));
    param_3 = param_3 + 1;
  }
  return;
}


// ===== FUN_00989514 @ 00989514

undefined4 FUN_00989514(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 local_c;
  undefined4 uStack_8;
  
  local_c = 0;
  uStack_8 = param_3;
  (*(code *)&SUB_ffb1ff74)(&local_c);
  return local_c;
}


// ===== FUN_00989518 @ 00989518

undefined4 FUN_00989518(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 local_c;
  undefined4 uStack_8;
  
  local_c = param_4;
  uStack_8 = param_3;
  (*(code *)&SUB_ffb1ff74)(&local_c);
  return local_c;
}


// ===== FUN_0098955c @ 0098955c

void FUN_0098955c(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0x30) != 0 || param_3 == 0) {
    return;
  }
  iVar1 = FUN_009829b8(*(undefined4 *)(param_1 + 0x2c));
  if (iVar1 == 0) {
    *(int *)(param_1 + 0x50) = *(int *)(param_1 + 0x50) + param_3;
  }
  else {
    *(undefined4 *)(param_1 + 0x30) = 1;
  }
  return;
}


// ===== FUN_00989560 @ 00989560

void FUN_00989560(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  uint in_r12;
  
  if (*(int *)(param_1 + 0x30) != 0 || in_r12 >> 5 != 0) {
    return;
  }
  iVar1 = FUN_009829b8(*(undefined4 *)(param_1 + 0x2c));
  if (iVar1 == 0) {
    *(int *)(param_1 + 0x50) = *(int *)(param_1 + 0x50) + param_3;
  }
  else {
    *(undefined4 *)(param_1 + 0x30) = 1;
  }
  return;
}


// ===== FUN_009895a0 @ 009895a0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_009895a0(int param_1)

{
  undefined4 uVar1;
  uint uVar2;
  
  if (_DAT_009e6f70 != 0) {
    if ((_DAT_009e6f6c != 0) && (*(uint *)(param_1 + 8) <= _DAT_009e6f68)) {
      *(int *)(param_1 + 0x14) = _DAT_009e6f6c;
      *(int *)(param_1 + 0x10) = _DAT_009e6f70;
      _DAT_009e6f6c = 0;
      _DAT_009e6f70 = 0;
      _DAT_009e6f68 = 0;
      goto LAB_009895f8;
    }
  }
  uVar1 = (*(code *)&SUB_ffb2a56c)(*(uint *)(param_1 + 8) << 5);
  *(undefined4 *)(param_1 + 0x10) = uVar1;
  uVar1 = (*(code *)&SUB_ffb2a56c)(*(undefined4 *)(param_1 + 0x1c));
  *(undefined4 *)(param_1 + 0x14) = uVar1;
LAB_009895f8:
  uVar2 = *(uint *)(param_1 + 0x10);
  if ((uVar2 != 0) && ((uVar2 & 0xf0000000) == 0x10000000)) {
    uVar2 = uVar2 & 0xfffffff;
  }
  *(uint *)(param_1 + 0x18) = uVar2;
  return;
}


// ===== FUN_009895a4 @ 009895a4

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_009895a4(int param_1,int *param_2)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = *param_2;
  if (iVar3 != 0) {
    if ((_DAT_009e6f6c != 0) && (*(uint *)(param_1 + 8) <= _DAT_009e6f68)) {
      *(int *)(param_1 + 0x14) = _DAT_009e6f6c;
      *(int *)(param_1 + 0x10) = iVar3;
      _DAT_009e6f6c = 0;
      *param_2 = 0;
      _DAT_009e6f68 = 0;
      goto LAB_009895f8;
    }
  }
  uVar1 = (*(code *)&SUB_ffb2a56c)(*(uint *)(param_1 + 8) << 5);
  *(undefined4 *)(param_1 + 0x10) = uVar1;
  uVar1 = (*(code *)&SUB_ffb2a56c)(*(undefined4 *)(param_1 + 0x1c));
  *(undefined4 *)(param_1 + 0x14) = uVar1;
LAB_009895f8:
  uVar2 = *(uint *)(param_1 + 0x10);
  if ((uVar2 != 0) && ((uVar2 & 0xf0000000) == 0x10000000)) {
    uVar2 = uVar2 & 0xfffffff;
  }
  *(uint *)(param_1 + 0x18) = uVar2;
  return;
}


// ===== FUN_00989644 @ 00989644

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00989644(undefined4 *param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  undefined1 *puVar6;
  undefined4 *puVar7;
  uint uVar8;
  undefined *puVar9;
  int iVar10;
  undefined4 *puVar11;
  int iVar12;
  char *pcVar13;
  uint uVar14;
  uint uVar15;
  undefined4 uVar16;
  uint uVar17;
  uint uVar18;
  uint uVar19;
  uint uVar20;
  undefined local_2c;
  char local_2b;
  
  if (param_1[0xc] != 0) {
    return;
  }
  uVar18 = param_1[8];
  if (uVar18 == 0) {
    return;
  }
  uVar5 = param_1[6];
  uVar15 = uVar18 + 7 & 0xfffffff8;
  for (; iVar10 = param_1[2], uVar18 < uVar15; uVar18 = uVar18 + 1) {
    puVar7 = (undefined4 *)(uVar5 + iVar10 * (param_1[8] + -1) * 2);
    puVar11 = (undefined4 *)(uVar5 + uVar18 * iVar10 * 2);
    for (uVar17 = 0; uVar17 < (uint)param_1[2] >> 1; uVar17 = uVar17 + 1) {
      *puVar11 = *puVar7;
      puVar7 = puVar7 + 1;
      puVar11 = puVar11 + 1;
    }
  }
  for (uVar18 = uVar5 & 0xffffffe0; uVar18 < uVar5 + uVar15 * iVar10 * 2; uVar18 = uVar18 + 0x20) {
    coproc_moveto_Clean_Data_Cache_by_MVA(uVar18);
  }
  coproc_moveto_Data_Synchronization(0);
  if (_DAT_009e70b8 == 0) {
    iVar10 = 0x15;
    uVar16 = param_1[2];
    do {
      iVar2 = (*(code *)&SUB_ffb1828c)(_DAT_00023480,500);
      if (iVar2 == 0) {
        _DAT_00023488 = 1;
        _DAT_009e6b30 = param_1[4];
        _DAT_009e6b2c = 1;
        _DAT_009e6b48 = 1;
        _DAT_009e6b4c = 1;
        _DAT_009e6b50 = 8;
        _DAT_009e6b54 = 8;
        _DAT_009e6b58 = param_1[5];
        _DAT_009e6b5c = param_1[7] + -8;
        _DAT_009e6b60 = param_1[3];
        _DAT_009e70c4 = 0;
        _DAT_009e6b38 = 0;
        _DAT_009e6b3c = 0;
        _DAT_009e70bc = 0;
        _DAT_009e6b64 = &DAT_009e70bc;
        _DAT_009e70c0 = 0;
        _DAT_009e6b34 = uVar16;
        _DAT_009e6b40 = uVar16;
        _DAT_009e6b44 = uVar15;
        iVar10 = FUN_00989514();
        uVar16 = (*(code *)&SUB_ff93a608)(&DAT_00023488,&DAT_009e6b2c,&LAB_0098953c,0);
        iVar2 = FUN_00989514();
        goto LAB_009897f8;
      }
      iVar10 = iVar10 + -1;
      param_1[0x11] = param_1[0x11] + 1;
    } while (iVar10 != 0);
    param_1[8] = 0;
    param_1[0xd] = 1;
    goto LAB_009896f0;
  }
LAB_0098974c:
  param_1[8] = 0;
LAB_009896f0:
  param_1[0xc] = 1;
  return;
LAB_009897f8:
  if ((_DAT_009e70c4 != 0) || (iVar3 = FUN_00989514(), 0x13 < (uint)(iVar3 - iVar2)))
  goto LAB_00989814;
  iVar3 = 2000;
  do {
    if (_DAT_009e70c4 != 0) break;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  goto LAB_009897f8;
LAB_00989814:
  iVar2 = 0x5dd;
  while ((_DAT_009e70c4 == 0 && (iVar2 = iVar2 + -1, iVar2 != 0))) {
    FUN_009a3580(2);
  }
  iVar2 = FUN_00989514();
  param_1[0x12] = param_1[0x12] + (iVar2 - iVar10);
  param_1[0x10] = param_1[0x10] + 1;
  (*(code *)&SUB_ff93aa58)(&DAT_00023488);
  if (_DAT_009e6f74 < 0x10) {
    iVar12 = _DAT_009e6f74 * 0x14;
    _DAT_009e6f74 = _DAT_009e6f74 + 1;
    *(undefined4 *)(&DAT_009e6f78 + iVar12) = uVar16;
    iVar3 = _DAT_009e70c4;
    *(int *)(&DAT_009e6f84 + iVar12) = iVar2 - iVar10;
    *(int *)(&DAT_009e6f7c + iVar12) = iVar3;
    *(int *)(&DAT_009e6f80 + iVar12) = _DAT_009e70c0;
    *(uint *)(&DAT_009e6f88 + iVar12) = _DAT_009e70bc;
  }
  if (param_1[0x10] == 1) {
    if (_DAT_009e70c4 == 0) {
      iVar10 = 0xdead;
    }
    else {
      iVar10 = _DAT_009e70c0;
    }
    param_1[0x15] = iVar10;
  }
  uVar18 = _DAT_009e70bc;
  if (_DAT_009e70c4 == 0) {
    param_1[5] = 0;
    _DAT_009e70b8 = 1;
  }
  else if (((_DAT_009e70c0 == 0) && (4 < _DAT_009e70bc)) && (_DAT_009e70bc <= (uint)param_1[7])) {
    param_1[8] = 0;
    if (uVar18 != 0) {
      iVar10 = param_1[5];
      uVar5 = 0;
      while( true ) {
        if ((uVar18 <= uVar5 + 1) || (*(char *)(iVar10 + uVar5) != -1)) goto LAB_009896f0;
        cVar1 = *(char *)(iVar10 + uVar5 + 1);
        if (cVar1 == -0x26) break;
        uVar15 = uVar5 + 2;
        if (cVar1 != -0x28) {
          uVar15 = uVar15 + CONCAT11(*(undefined1 *)(iVar10 + uVar15),
                                     *(undefined1 *)(iVar10 + uVar5 + 3));
        }
        uVar5 = uVar15;
      }
      if (uVar5 < uVar18) {
        uVar15 = (uint)CONCAT11(*(undefined1 *)(iVar10 + uVar5 + 2),
                                *(undefined1 *)(iVar10 + uVar5 + 3));
        iVar2 = uVar15 + uVar5;
        pcVar13 = (char *)((uVar18 - 1) + iVar10);
        goto LAB_009899b8;
      }
    }
    goto LAB_009896f0;
  }
  goto LAB_0098974c;
LAB_009899b8:
  if (uVar18 <= iVar2 + 3U) goto LAB_009896f0;
  if ((pcVar13[-1] == -1) && (*pcVar13 == -0x27)) {
    uVar17 = iVar2 + 2;
    if (param_1[9] != 0) {
      local_2c = 0xff;
      local_2b = ((char)param_1[9] - 1U & 7) - 0x30;
      iVar2 = 2;
      puVar9 = &local_2c;
      goto LAB_00989a9c;
    }
    _DAT_009e6b68 = 0xd8ff;
    if ((param_1[0xe] == 0) || (0xffff < param_1[0xf] + 4)) {
      uVar14 = 2;
    }
    else {
      iVar2 = param_1[0xf] + 2;
      _DAT_009e6b6a = 0xe1ff;
      DAT_009e6b6c = (undefined1)((uint)iVar2 >> 8);
      DAT_009e6b6d = (undefined1)iVar2;
      FUN_0098955c(param_1,&DAT_009e6b68,6);
      FUN_0098955c(param_1,param_1[0xe],param_1[0xf]);
      uVar14 = 0;
    }
    uVar8 = 2;
    goto LAB_00989a1c;
  }
  pcVar13 = pcVar13 + -1;
  uVar18 = uVar18 - 1;
  goto LAB_009899b8;
LAB_00989a1c:
  if ((uVar5 <= uVar8) || (0x3ff < uVar14 + 4)) {
    uVar8 = param_1[2];
    (&DAT_009e6b68)[uVar14] = 0xff;
    (&UNK_009e6b69)[uVar14] = 0xdd;
    (&DAT_009e6b6a)[uVar14] = 0;
    (&DAT_009e6b6b)[uVar14] = 4;
    (&DAT_009e6b6c)[uVar14] = (char)(uVar8 >> 0xb);
    (&DAT_009e6b6d)[uVar14] = (char)((uVar8 >> 4) << 1);
    puVar9 = &DAT_009e6b6d + uVar14;
    for (uVar8 = uVar5; uVar8 < uVar17; uVar8 = uVar8 + 1) {
      puVar9 = puVar9 + 1;
      *puVar9 = *(undefined1 *)(iVar10 + uVar8);
    }
    if (uVar17 < uVar5) {
      iVar2 = 0;
    }
    else {
      iVar2 = uVar15 + 2;
    }
    puVar9 = &DAT_009e6b68;
    iVar2 = iVar2 + 6 + uVar14;
LAB_00989a9c:
    FUN_0098955c(param_1,puVar9,iVar2);
    FUN_0098955c(param_1,iVar10 + uVar17,(uVar18 - uVar17) + -2);
    param_1[9] = param_1[9] + 1;
    return;
  }
  puVar6 = (undefined1 *)(iVar10 + uVar8);
  uVar4 = (uint)CONCAT11(*(undefined1 *)(iVar10 + uVar8 + 2),puVar6[3]);
  if (0x42 < uVar4 && *(char *)(iVar10 + uVar8 + 1) == -0x25) {
    param_1[0x16] = (uint)(byte)puVar6[5];
    param_1[0x17] = (uint)(byte)puVar6[6];
    param_1[0x18] = (uint)(byte)puVar6[7];
  }
  uVar19 = uVar14 + 2 + uVar4;
  if (0x400 < uVar19) goto LAB_009896f0;
  uVar20 = 0;
  puVar9 = &DAT_009e6b68 + uVar14;
  do {
    uVar20 = uVar20 + 1;
    *puVar9 = *puVar6;
    puVar9 = puVar9 + 1;
    puVar6 = puVar6 + 1;
  } while (uVar20 < uVar4 + 2);
  if (*(char *)(iVar10 + uVar8 + 1) == -0x40) {
    (&DAT_009e6b6d)[uVar14] = (char)((uint)param_1[1] >> 8);
    (&DAT_009e6b6e)[uVar14] = (char)param_1[1];
    (&DAT_009e6b6f)[uVar14] = (char)((uint)*param_1 >> 8);
    (&DAT_009e6b70)[uVar14] = (char)*param_1;
  }
  uVar8 = uVar8 + 2 + uVar4;
  uVar14 = uVar19;
  goto LAB_00989a1c;
}


// ===== FUN_0098965c @ 0098965c

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0098965c(undefined4 *param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  undefined1 *puVar6;
  uint uVar7;
  undefined4 *puVar8;
  uint uVar9;
  undefined *puVar10;
  int iVar11;
  undefined4 *puVar12;
  int iVar13;
  char *pcVar14;
  uint uVar15;
  uint uVar16;
  undefined4 uVar17;
  uint uVar18;
  uint in_r12;
  uint uVar19;
  uint uVar20;
  undefined local_2c;
  char local_2b;
  
  uVar5 = param_1[6];
  uVar16 = in_r12 + 7 & 0xfffffff8;
  for (; iVar11 = param_1[2], in_r12 < uVar16; in_r12 = in_r12 + 1) {
    puVar8 = (undefined4 *)(uVar5 + iVar11 * (param_1[8] + -1) * 2);
    puVar12 = (undefined4 *)(uVar5 + in_r12 * iVar11 * 2);
    for (uVar7 = 0; uVar7 < (uint)param_1[2] >> 1; uVar7 = uVar7 + 1) {
      *puVar12 = *puVar8;
      puVar8 = puVar8 + 1;
      puVar12 = puVar12 + 1;
    }
  }
  for (uVar7 = uVar5 & 0xffffffe0; uVar7 < uVar5 + uVar16 * iVar11 * 2; uVar7 = uVar7 + 0x20) {
    coproc_moveto_Clean_Data_Cache_by_MVA(uVar7);
  }
  coproc_moveto_Data_Synchronization(0);
  if (_DAT_009e70b8 == 0) {
    iVar11 = 0x15;
    uVar17 = param_1[2];
    do {
      iVar2 = (*(code *)&SUB_ffb1828c)(_DAT_00023480,500);
      if (iVar2 == 0) {
        _DAT_00023488 = 1;
        _DAT_009e6b30 = param_1[4];
        _DAT_009e6b2c = 1;
        _DAT_009e6b48 = 1;
        _DAT_009e6b4c = 1;
        _DAT_009e6b50 = 8;
        _DAT_009e6b54 = 8;
        _DAT_009e6b58 = param_1[5];
        _DAT_009e6b5c = param_1[7] + -8;
        _DAT_009e6b60 = param_1[3];
        _DAT_009e70c4 = 0;
        _DAT_009e6b38 = 0;
        _DAT_009e6b3c = 0;
        _DAT_009e70bc = 0;
        _DAT_009e6b64 = &DAT_009e70bc;
        _DAT_009e70c0 = 0;
        _DAT_009e6b34 = uVar17;
        _DAT_009e6b40 = uVar17;
        _DAT_009e6b44 = uVar16;
        iVar11 = FUN_00989514();
        uVar17 = (*(code *)&SUB_ff93a608)(&DAT_00023488,&DAT_009e6b2c,&LAB_0098953c,0);
        iVar2 = FUN_00989514();
        goto LAB_009897f8;
      }
      iVar11 = iVar11 + -1;
      param_1[0x11] = param_1[0x11] + 1;
    } while (iVar11 != 0);
    param_1[8] = 0;
    param_1[0xd] = 1;
    goto LAB_009896f0;
  }
LAB_0098974c:
  param_1[8] = 0;
LAB_009896f0:
  param_1[0xc] = 1;
  return;
LAB_009897f8:
  if ((_DAT_009e70c4 != 0) || (iVar3 = FUN_00989514(), 0x13 < (uint)(iVar3 - iVar2)))
  goto LAB_00989814;
  iVar3 = 2000;
  do {
    if (_DAT_009e70c4 != 0) break;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  goto LAB_009897f8;
LAB_00989814:
  iVar2 = 0x5dd;
  while ((_DAT_009e70c4 == 0 && (iVar2 = iVar2 + -1, iVar2 != 0))) {
    FUN_009a3580(2);
  }
  iVar2 = FUN_00989514();
  param_1[0x12] = param_1[0x12] + (iVar2 - iVar11);
  param_1[0x10] = param_1[0x10] + 1;
  (*(code *)&SUB_ff93aa58)(&DAT_00023488);
  if (_DAT_009e6f74 < 0x10) {
    iVar13 = _DAT_009e6f74 * 0x14;
    _DAT_009e6f74 = _DAT_009e6f74 + 1;
    *(undefined4 *)(&DAT_009e6f78 + iVar13) = uVar17;
    iVar3 = _DAT_009e70c4;
    *(int *)(&DAT_009e6f84 + iVar13) = iVar2 - iVar11;
    *(int *)(&DAT_009e6f7c + iVar13) = iVar3;
    *(int *)(&DAT_009e6f80 + iVar13) = _DAT_009e70c0;
    *(uint *)(&DAT_009e6f88 + iVar13) = _DAT_009e70bc;
  }
  if (param_1[0x10] == 1) {
    if (_DAT_009e70c4 == 0) {
      iVar11 = 0xdead;
    }
    else {
      iVar11 = _DAT_009e70c0;
    }
    param_1[0x15] = iVar11;
  }
  uVar5 = _DAT_009e70bc;
  if (_DAT_009e70c4 == 0) {
    param_1[5] = 0;
    _DAT_009e70b8 = 1;
  }
  else if (((_DAT_009e70c0 == 0) && (4 < _DAT_009e70bc)) && (_DAT_009e70bc <= (uint)param_1[7])) {
    param_1[8] = 0;
    if (uVar5 != 0) {
      iVar11 = param_1[5];
      uVar16 = 0;
      while( true ) {
        if ((uVar5 <= uVar16 + 1) || (*(char *)(iVar11 + uVar16) != -1)) goto LAB_009896f0;
        cVar1 = *(char *)(iVar11 + uVar16 + 1);
        if (cVar1 == -0x26) break;
        uVar7 = uVar16 + 2;
        if (cVar1 != -0x28) {
          uVar7 = uVar7 + CONCAT11(*(undefined1 *)(iVar11 + uVar7),
                                   *(undefined1 *)(iVar11 + uVar16 + 3));
        }
        uVar16 = uVar7;
      }
      if (uVar16 < uVar5) {
        uVar7 = (uint)CONCAT11(*(undefined1 *)(iVar11 + uVar16 + 2),
                               *(undefined1 *)(iVar11 + uVar16 + 3));
        iVar2 = uVar7 + uVar16;
        pcVar14 = (char *)((uVar5 - 1) + iVar11);
        goto LAB_009899b8;
      }
    }
    goto LAB_009896f0;
  }
  goto LAB_0098974c;
LAB_009899b8:
  if (uVar5 <= iVar2 + 3U) goto LAB_009896f0;
  if ((pcVar14[-1] == -1) && (*pcVar14 == -0x27)) {
    uVar18 = iVar2 + 2;
    if (param_1[9] != 0) {
      local_2c = 0xff;
      local_2b = ((char)param_1[9] - 1U & 7) - 0x30;
      iVar2 = 2;
      puVar10 = &local_2c;
      goto LAB_00989a9c;
    }
    _DAT_009e6b68 = 0xd8ff;
    if ((param_1[0xe] == 0) || (0xffff < param_1[0xf] + 4)) {
      uVar15 = 2;
    }
    else {
      iVar2 = param_1[0xf] + 2;
      _DAT_009e6b6a = 0xe1ff;
      DAT_009e6b6c = (undefined1)((uint)iVar2 >> 8);
      DAT_009e6b6d = (undefined1)iVar2;
      FUN_0098955c(param_1,&DAT_009e6b68,6);
      FUN_0098955c(param_1,param_1[0xe],param_1[0xf]);
      uVar15 = 0;
    }
    uVar9 = 2;
    goto LAB_00989a1c;
  }
  pcVar14 = pcVar14 + -1;
  uVar5 = uVar5 - 1;
  goto LAB_009899b8;
LAB_00989a1c:
  if ((uVar16 <= uVar9) || (0x3ff < uVar15 + 4)) {
    uVar9 = param_1[2];
    (&DAT_009e6b68)[uVar15] = 0xff;
    (&UNK_009e6b69)[uVar15] = 0xdd;
    (&DAT_009e6b6a)[uVar15] = 0;
    (&DAT_009e6b6b)[uVar15] = 4;
    (&DAT_009e6b6c)[uVar15] = (char)(uVar9 >> 0xb);
    (&DAT_009e6b6d)[uVar15] = (char)((uVar9 >> 4) << 1);
    puVar10 = &DAT_009e6b6d + uVar15;
    for (uVar9 = uVar16; uVar9 < uVar18; uVar9 = uVar9 + 1) {
      puVar10 = puVar10 + 1;
      *puVar10 = *(undefined1 *)(iVar11 + uVar9);
    }
    if (uVar18 < uVar16) {
      iVar2 = 0;
    }
    else {
      iVar2 = uVar7 + 2;
    }
    puVar10 = &DAT_009e6b68;
    iVar2 = iVar2 + 6 + uVar15;
LAB_00989a9c:
    FUN_0098955c(param_1,puVar10,iVar2);
    FUN_0098955c(param_1,iVar11 + uVar18,(uVar5 - uVar18) + -2);
    param_1[9] = param_1[9] + 1;
    return;
  }
  puVar6 = (undefined1 *)(iVar11 + uVar9);
  uVar4 = (uint)CONCAT11(*(undefined1 *)(iVar11 + uVar9 + 2),puVar6[3]);
  if (0x42 < uVar4 && *(char *)(iVar11 + uVar9 + 1) == -0x25) {
    param_1[0x16] = (uint)(byte)puVar6[5];
    param_1[0x17] = (uint)(byte)puVar6[6];
    param_1[0x18] = (uint)(byte)puVar6[7];
  }
  uVar19 = uVar15 + 2 + uVar4;
  if (0x400 < uVar19) goto LAB_009896f0;
  uVar20 = 0;
  puVar10 = &DAT_009e6b68 + uVar15;
  do {
    uVar20 = uVar20 + 1;
    *puVar10 = *puVar6;
    puVar10 = puVar10 + 1;
    puVar6 = puVar6 + 1;
  } while (uVar20 < uVar4 + 2);
  if (*(char *)(iVar11 + uVar9 + 1) == -0x40) {
    (&DAT_009e6b6d)[uVar15] = (char)((uint)param_1[1] >> 8);
    (&DAT_009e6b6e)[uVar15] = (char)param_1[1];
    (&DAT_009e6b6f)[uVar15] = (char)((uint)*param_1 >> 8);
    (&DAT_009e6b70)[uVar15] = (char)*param_1;
  }
  uVar9 = uVar9 + 2 + uVar4;
  uVar15 = uVar19;
  goto LAB_00989a1c;
}


// ===== FUN_00989c5c @ 00989c5c

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00989c5c(void)

{
  if (_DAT_009e6f70 != 0) {
    (*(code *)&SUB_ffb2a5b0)();
  }
  if (_DAT_009e6f6c != 0) {
    (*(code *)&SUB_ffb2a5b0)();
  }
  _DAT_009e6f6c = 0;
  _DAT_009e6f70 = 0;
  _DAT_009e6f68 = 0;
  return;
}


// ===== FUN_00989cb4 @ 00989cb4

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00989cb4(int param_1)

{
  uint uVar1;
  
  uVar1 = param_1 + 0xfU & 0xfffffff0;
  if (((_DAT_009e6f70 != 0) && (_DAT_009e6f6c != 0)) && (uVar1 <= _DAT_009e6f68)) {
    return 0;
  }
  FUN_00989c5c();
  _DAT_009e6f6c = (*(code *)&SUB_ffb2a56c)(0x28000);
  if (_DAT_009e6f6c == 0) {
    _DAT_009e6f70 = 0;
  }
  else {
    _DAT_009e6f70 = (*(code *)&SUB_ffb2a56c)(uVar1 << 5);
    if (_DAT_009e6f70 != 0) {
      _DAT_009e6f68 = uVar1;
      return 0;
    }
  }
  FUN_00989c5c();
  return 0xfffffff9;
}


// ===== FUN_00989d50 @ 00989d50

undefined4
FUN_00989d50(int *param_1,undefined4 param_2,int param_3,int param_4,int param_5,int param_6,
            int param_7)

{
  undefined1 *puVar1;
  int iVar2;
  
  puVar1 = (undefined1 *)((int)param_1 + -1);
  do {
    puVar1 = puVar1 + 1;
    *puVar1 = 0;
  } while (puVar1 != (undefined1 *)((int)param_1 + 99));
  *param_1 = param_3;
  param_1[1] = param_4;
  param_1[3] = param_5;
  param_1[7] = 0x28000;
  param_1[2] = param_3 + 0xfU & 0xfffffff0;
  FUN_009895a0(param_1);
  param_1[0xb] = -1;
  if ((param_1[4] == 0) || (param_1[5] == 0)) {
    param_1[0xc] = 1;
    return 0xfffffff9;
  }
  param_1[9] = param_6;
  param_1[0x14] = param_7;
  iVar2 = FUN_00982af0(param_2);
  param_1[0xb] = iVar2;
  if ((iVar2 < 0) || (iVar2 = FUN_00982a34(iVar2,param_7), iVar2 != 0)) {
    param_1[0xc] = 1;
    return 0xffffffff;
  }
  return 0;
}


// ===== FUN_00989e14 @ 00989e14

int FUN_00989e14(int param_1)

{
  int iVar1;
  uint uVar2;
  
  if (*(int *)(param_1 + 0x30) == 0) {
    uVar2 = 0;
    if ((*(int *)(param_1 + 0x20) == 0) && (uVar2 = 0, *(int *)(param_1 + 0x24) != 0)) {
      uVar2 = 1;
    }
  }
  else {
    uVar2 = 0;
  }
  if ((-1 < *(int *)(param_1 + 0x2c)) &&
     (iVar1 = FUN_00982a90(*(int *)(param_1 + 0x2c),1), iVar1 != 0)) {
    uVar2 = 0;
  }
  *(undefined4 *)(param_1 + 0x2c) = 0xffffffff;
  if (*(int *)(param_1 + 0x10) != 0) {
    (*(code *)&SUB_ffb2a5b0)();
  }
  if (*(int *)(param_1 + 0x14) != 0) {
    (*(code *)&SUB_ffb2a5b0)();
  }
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined4 *)(param_1 + 0x10) = 0;
  return -(uVar2 ^ 1);
}


// ===== FUN_00989eac @ 00989eac

undefined4
FUN_00989eac(int *param_1,undefined4 param_2,int param_3,int param_4,int param_5,int param_6,
            int param_7)

{
  undefined1 *puVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  puVar1 = (undefined1 *)((int)param_1 + -1);
  do {
    puVar1 = puVar1 + 1;
    *puVar1 = 0;
  } while (puVar1 != (undefined1 *)((int)param_1 + 99));
  *param_1 = param_3;
  param_1[1] = param_4;
  param_1[3] = param_5;
  param_1[0xe] = param_6;
  param_1[0xf] = param_7;
  param_1[7] = 0x28000;
  param_1[2] = param_3 + 0xfU & 0xfffffff0;
  FUN_009895a0(param_1);
  param_1[0xb] = -1;
  if ((param_1[4] == 0) || (iVar4 = param_1[5], iVar4 == 0)) {
    param_1[0xc] = 1;
    return 0xfffffff9;
  }
  iVar2 = FUN_009828c0(param_2);
  if (iVar2 < 0) {
    iVar4 = 1;
  }
  param_1[0xb] = iVar2;
  if (iVar2 < 0) {
    param_1[0xc] = iVar4;
    uVar3 = 0xffffffff;
  }
  else {
    uVar3 = 0;
  }
  return uVar3;
}


// ===== FUN_00989f5c @ 00989f5c

void FUN_00989f5c(int param_1,int param_2,int param_3,uint param_4)

{
  short sVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  byte *pbVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  byte *pbVar9;
  int iVar10;
  uint uVar11;
  uint *local_44;
  
  if (*(int *)(param_1 + 0x30) == 0) {
    iVar7 = 0;
    while ((iVar7 != param_3 && (*(int *)(param_1 + 0x30) == 0))) {
      iVar2 = FUN_00989514();
      iVar10 = *(int *)(param_2 + iVar7 * 4);
      iVar8 = *(int *)(param_1 + 0x18) + *(int *)(param_1 + 8) * *(int *)(param_1 + 0x20) * 2;
      FUN_0098cf8c(iVar10,iVar8,param_4 >> 1);
      uVar11 = param_4 & 0xfffffffe;
      pbVar9 = (byte *)(iVar10 + (param_4 - 1) * 3);
      local_44 = (uint *)(iVar8 + (param_4 >> 1) * 4);
      while (uVar11 < *(uint *)(param_1 + 8)) {
        pbVar5 = pbVar9;
        if (uVar11 < param_4) {
          pbVar5 = (byte *)(iVar10 + uVar11 * 3);
        }
        iVar4 = (uint)*pbVar5 + (uint)*pbVar9;
        sVar1 = (ushort)pbVar5[1] + (ushort)pbVar9[1];
        iVar8 = (uint)pbVar5[2] + (uint)pbVar9[2];
        uVar11 = uVar11 + 2;
        uVar6 = (short)iVar4 * -0x2b33 + sVar1 * -0x54cd + iVar8 * 0x8000 + 0x10000 >> 0x11;
        if (0x7e < (int)uVar6) {
          uVar6 = 0x7f;
        }
        uVar3 = (short)iVar8 * -0x14d1 + sVar1 * -0x6b2f + iVar4 * 0x8000 + 0x10000 >> 0x11;
        if (0x7e < (int)uVar3) {
          uVar3 = 0x7f;
        }
        *local_44 = ((int)((uint)*pbVar9 * 0x4c8b + (uint)pbVar9[1] * 0x9646 +
                           (uint)pbVar9[2] * 0x1d2f + 0x8000) >> 0x10) << 0x18 |
                    ((int)((uint)*pbVar5 * 0x4c8b + (uint)pbVar5[1] * 0x9646 +
                           (uint)pbVar5[2] * 0x1d2f + 0x8000) >> 0x10) << 8 | uVar6 & 0xff |
                    (uVar3 & 0xff) << 0x10;
        local_44 = local_44 + 1;
      }
      iVar8 = FUN_00989514();
      *(int *)(param_1 + 0x4c) = (*(int *)(param_1 + 0x4c) - iVar2) + iVar8;
      iVar2 = *(int *)(param_1 + 0x20) + 1;
      *(int *)(param_1 + 0x20) = iVar2;
      if (iVar2 == 0x10) {
        FUN_00989644(param_1);
      }
      iVar7 = iVar7 + 1;
    }
  }
  return;
}


// ===== FUN_0098a170 @ 0098a170

undefined4 FUN_0098a170(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 local_14;
  undefined4 uStack_10;
  
  iVar2 = param_1;
  local_14 = param_2;
  uStack_10 = param_3;
  FUN_00989644();
  local_14 = CONCAT22(local_14._2_2_,0xd9ff);
  FUN_0098955c(param_1,&local_14,2,0xffffd9ff,iVar2);
  if (-1 < *(int *)(param_1 + 0x2c)) {
    FUN_00982a90(*(int *)(param_1 + 0x2c),1);
  }
  if (*(int *)(param_1 + 0x10) != 0) {
    (*(code *)&SUB_ffb2a5b0)();
  }
  if (*(int *)(param_1 + 0x14) != 0) {
    (*(code *)&SUB_ffb2a5b0)();
  }
  *(undefined4 *)(param_1 + 0x14) = 0;
  uVar1 = 0;
  if (*(int *)(param_1 + 0x30) != 0) {
    uVar1 = 0xffffffff;
  }
  *(undefined4 *)(param_1 + 0x10) = 0;
  return uVar1;
}


// ===== FUN_0098a1f0 @ 0098a1f0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0098a1f0(undefined4 param_1,undefined4 param_2,int param_3,int param_4)

{
  ushort uVar1;
  bool bVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  byte *pbVar6;
  uint uVar7;
  code *pcVar8;
  int *local_2c;
  int local_28;
  int local_24;
  
  iVar3 = _DAT_009e70d0;
  local_28 = param_3;
  local_24 = param_4;
  do {
    local_2c = (int *)0x0;
    (*(code *)&SUB_ffb170fc)(_DAT_0001271c,&local_2c,0);
    (*(code *)&SUB_ffb1828c)(_DAT_00012720,0);
    local_28 = 0;
    _DAT_009e70cc = 1;
    *(int *)(iVar3 + 0x10) = *(int *)(iVar3 + 0x10) + 1;
    (*(code *)&SUB_ffb1ff74)(&local_28);
    if ((local_2c != (int *)0x0) && (_DAT_009e72dc != (code *)0x0)) {
      (*_DAT_009e72dc)();
    }
    if (local_2c != (int *)0x0) {
      if (local_2c[2] == 0x4c544e4e) {
        if (_DAT_009e72e0 == (code *)0x0) goto LAB_0098a2a4;
        piVar4 = (int *)local_2c[1];
        pcVar8 = _DAT_009e72e0;
      }
      else {
        if (*local_2c == 0 && (&UNK_009e7318 < local_2c || local_2c < &UNK_009e72e8)) {
          uVar7 = *(uint *)(iVar3 + 0x14);
          *(uint *)(iVar3 + 0x14) = uVar7 + 1;
          if (_DAT_009e7328 == (code *)0x0) {
            bVar2 = false;
          }
          else {
            iVar5 = (*_DAT_009e7328)(local_2c[1]);
            bVar2 = false;
            if (iVar5 != 0) {
              bVar2 = true;
              *(int *)(iVar3 + 0x18) = *(int *)(iVar3 + 0x18) + 1;
            }
          }
          iVar5 = iVar3 + (uVar7 & 0xf);
          *(char *)(iVar5 + 0x1c) = (char)local_2c[1];
          *(bool *)(iVar5 + 0x2c) = bVar2;
          if (!bVar2) goto LAB_0098a3b0;
        }
        else {
LAB_0098a3b0:
          piVar4 = local_2c;
          iVar5 = *local_2c;
          switch(iVar5) {
          case 0:
            uVar7 = local_2c[1];
            if (_DAT_00001bcc == 1) {
              pbVar6 = &UNK_009a8ba3;
              do {
                if (*pbVar6 == uVar7) goto code_r0x0098a41c;
                iVar5 = iVar5 + 1;
                pbVar6 = pbVar6 + 1;
              } while (iVar5 != 6);
            }
            else {
code_r0x0098a41c:
              pcVar8 = (code *)0xff81800c;
code_r0x0098a420:
              (*pcVar8)(uVar7,local_2c[2],local_2c[3]);
            }
            break;
          case 1:
            if (_DAT_00001bcc == 1) {
              if (local_2c[1] != 4) break;
code_r0x0098a444:
              (*(code *)0xff818d98)(0x12,0);
              if (iRam00001bd4 != 0) {
                (*(code *)0xffb167c0)(iRam00001bd4,4);
              }
            }
            else if (local_2c[1] == 4) goto code_r0x0098a444;
            (*(code *)0xff818b7c)(piVar4[1]);
            break;
          case 2:
            uVar7 = local_2c[1];
            if (_DAT_00001bcc != 1) {
code_r0x0098a4c8:
              pcVar8 = (code *)0xff818d98;
              goto code_r0x0098a420;
            }
            iVar5 = 0;
            pbVar6 = &UNK_009a8b9f;
            do {
              if (*pbVar6 == uVar7) goto code_r0x0098a4c8;
              iVar5 = iVar5 + 1;
              pbVar6 = pbVar6 + 1;
            } while (iVar5 != 4);
            break;
          case 3:
            iVar5 = 0;
            uVar7 = local_2c[1];
            if (uVar7 == 0xd) {
              _DAT_00001bcc = 0;
            }
            else {
              if (_DAT_00001bcc != 1) {
code_r0x0098a510:
                pcVar8 = (code *)0xff818f70;
                goto code_r0x0098a420;
              }
              pbVar6 = &UNK_009a8b98;
              do {
                if (uVar7 == *pbVar6) goto code_r0x0098a510;
                iVar5 = iVar5 + 1;
                pbVar6 = pbVar6 + 1;
              } while (iVar5 != 7);
            }
          }
        }
        if (_DAT_009e72d8 == (code *)0x0) goto LAB_0098a2a4;
        piVar4 = local_2c;
        pcVar8 = _DAT_009e72d8;
      }
      (*pcVar8)(piVar4);
    }
LAB_0098a2a4:
    local_24 = 0;
    (*(code *)&SUB_ffb1ff74)(&local_24);
    uVar7 = local_24 - local_28;
    if ((local_2c != (int *)0x0) && (*(uint *)(iVar3 + 0x3c) < uVar7)) {
      iVar5 = *local_2c;
      uVar1 = *(ushort *)(local_2c + 1);
      *(uint *)(iVar3 + 0x3c) = uVar7;
      *(uint *)(iVar3 + 0x40) = (uint)uVar1 | iVar5 << 0x10;
    }
    if (200 < uVar7) {
      *(int *)(iVar3 + 0x44) = *(int *)(iVar3 + 0x44) + 1;
    }
    _DAT_009e70cc = 0;
    (*(code *)&SUB_ffb18430)(_DAT_00012720);
  } while( true );
}


// ===== FUN_0098a56c @ 0098a56c

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0098a56c(undefined4 param_1)

{
  _DAT_009e72dc = param_1;
  return;
}


// ===== FUN_0098a57c @ 0098a57c

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0098a57c(undefined4 param_1)

{
  _DAT_009e72d8 = param_1;
  return;
}


// ===== FUN_0098a58c @ 0098a58c

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0098a58c(undefined4 param_1)

{
  _DAT_009e72e0 = param_1;
  return;
}


// ===== FUN_0098a59c @ 0098a59c

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0098a59c(undefined4 param_1)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = _DAT_009e70d4 & 0x1f;
  _DAT_009e70d4 = _DAT_009e70d4 + 1;
  *(undefined4 *)(&UNK_009e70d8 + uVar2 * 0x10) = 4;
  iVar1 = uVar2 * 0x10;
  *(undefined4 *)(&UNK_009e70e0 + iVar1) = 0x4c544e4e;
  *(undefined4 *)(&UNK_009e70dc + iVar1) = param_1;
  *(undefined4 *)(&UNK_009e70e4 + iVar1) = 0;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0098a5f4 @ 0098a5f4

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0098a5f4(void)

{
  if (_DAT_009e70cc == 0) {
    _DAT_009e70c8 = _DAT_009e70c8 + 1;
    (*(code *)&SUB_ffb1828c)(_DAT_00012720);
    return 1;
  }
  return 0;
}


// ===== FUN_0098a608 @ 0098a608

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0098a608(undefined4 param_1,undefined4 param_2,int *param_3)

{
  *param_3 = *param_3 + 1;
  (*(code *)&SUB_ffb1828c)(_DAT_00012720);
  return 1;
}


// ===== FUN_0098a644 @ 0098a644

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0098a644(int param_1)

{
  if (param_1 != 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  return;
}


// ===== FUN_0098a6a8 @ 0098a6a8

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0098a6a8(int *param_1,undefined4 param_2,code *param_3)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  
  iVar1 = (*(code *)&SUB_ffb5610c)("tGuiMainTa");
  *param_1 = iVar1;
  if (iVar1 + 1U < 2) {
    iVar1 = 2;
  }
  else {
    iVar1 = 0x65;
    while( true ) {
      if (((_DAT_0001271c != 0 && _DAT_00012720 != 0) && (*(int *)(_DAT_0001271c + 0x18) == 0)) &&
         (*(int *)(_DAT_00012720 + 8) == 1)) {
        (*(code *)&SUB_ffb1828c)(_DAT_00012720);
        iVar1 = (*(code *)&SUB_ffb562f8)(*param_1);
        if (iVar1 != 0) {
          (*(code *)&SUB_ffb18430)(_DAT_00012720);
          iVar1 = 4;
          goto LAB_0098a74c;
        }
        (*(code *)&SUB_ffb177d8)(_DAT_0001271c,&DAT_009b4948);
        param_1[2] = 0;
        (*(code *)&SUB_ffb57968)(*param_1);
        iVar1 = param_1[2];
        _DAT_009e7328 = param_2;
        if (0xfe < iVar1 - 1U) {
          iVar1 = 0x17;
          param_1[2] = 0x17;
        }
        _DAT_009e70d0 = param_1;
        uVar2 = (*(code *)&SUB_ffb18b40)("LatentGui",iVar1,0x2000,FUN_0098a1f0,0);
        param_1[1] = uVar2;
        if ((0xfff < uVar2) && ((uVar2 & 3) == 0)) {
          (*(code *)&SUB_ffb18430)(_DAT_00012720);
          iVar1 = 1;
          uVar3 = 0;
          goto LAB_0098a7f8;
        }
        (*(code *)&SUB_ffb564cc)(*param_1);
        (*(code *)&SUB_ffb18430)(_DAT_00012720);
        iVar1 = 5;
        goto LAB_0098a74c;
      }
      iVar1 = iVar1 + -1;
      if (iVar1 == 0) break;
      (*param_3)(0x32);
    }
    iVar1 = 3;
  }
LAB_0098a74c:
  uVar3 = 0xffffffff;
LAB_0098a7f8:
  param_1[3] = iVar1;
  return uVar3;
}


// ===== FUN_0098a850 @ 0098a850

uint FUN_0098a850(int param_1,uint param_2)

{
  uint uVar1;
  
  if (param_2 < 0xd) {
    uVar1 = (int)(uint)*(ushort *)(param_1 + 4) >> (param_2 & 0xff) & 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// ===== FUN_0098a868 @ 0098a868

uint FUN_0098a868(undefined4 *param_1)

{
  uint uVar1;
  
  uVar1 = (*(code *)*param_1)(param_1[9]);
  return uVar1 | 1;
}


// ===== FUN_0098a86c @ 0098a86c

uint FUN_0098a86c(int param_1,undefined4 param_2,undefined4 param_3,code *param_4)

{
  uint uVar1;
  
  uVar1 = (*param_4)(*(undefined4 *)(param_1 + 0x24));
  return uVar1 | 1;
}


// ===== FUN_0098a880 @ 0098a880

void FUN_0098a880(int param_1)

{
  if (*(uint *)(param_1 + 0x107c) == 0) {
    return;
  }
  if ((((*(int *)(param_1 + 0x34) == 0) || (1 < (byte)(*(char *)(param_1 + 0x38) - 2U))) ||
      (*(int *)(param_1 + 0x106c) == 0)) ||
     (*(uint *)(param_1 + 0x107c) !=
      (*(uint *)(param_1 + *(int *)(param_1 + 0x1070) * 8 + 0x6c) & 0xffffff))) {
    *(undefined4 *)(param_1 + 0x107c) = 0;
    return;
  }
  return;
}


// ===== FUN_0098a8e0 @ 0098a8e0

void FUN_0098a8e0(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  iVar1 = 0;
  iVar2 = *(int *)(param_1 + 0x1100);
  piVar3 = (int *)(param_1 + 0x107c);
  while( true ) {
    if (iVar2 == iVar1) {
      return;
    }
    piVar3 = piVar3 + 1;
    if (*piVar3 == param_2) break;
    iVar1 = iVar1 + 1;
  }
  *(int *)(param_1 + 0x1100) = iVar2 + -1;
  *(undefined4 *)(param_1 + (iVar1 + 0x420) * 4) = *(undefined4 *)(param_1 + (iVar2 + 0x41f) * 4);
  return;
}


// ===== FUN_0098a8e4 @ 0098a8e4

void FUN_0098a8e4(int param_1,int param_2,int param_3)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = *(int *)(param_1 + 0x1100);
  piVar2 = (int *)(param_1 + 0x107c);
  while( true ) {
    if (iVar1 == param_3) {
      return;
    }
    piVar2 = piVar2 + 1;
    if (*piVar2 == param_2) break;
    param_3 = param_3 + 1;
  }
  *(int *)(param_1 + 0x1100) = iVar1 + -1;
  *(undefined4 *)(param_1 + (param_3 + 0x420) * 4) = *(undefined4 *)(param_1 + (iVar1 + 0x41f) * 4);
  return;
}


// ===== FUN_0098a930 @ 0098a930

uint FUN_0098a930(int param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = param_1 + param_2 * 0xc;
  uVar3 = (uint)*(char *)(param_1 + param_2 * 0xc);
  uVar1 = (uint)*(char *)(iVar2 + 1);
  uVar3 = uVar3 & ~((int)uVar3 >> 0x1f);
  if ((int)uVar1 <= (int)uVar3) {
    uVar3 = uVar1;
  }
  return param_2 & 0xff | (uVar3 & 0xff) << 8 | (uint)*(byte *)(iVar2 + 3) << 0x10 | 0x5000000;
}


// ===== FUN_0098a978 @ 0098a978

void FUN_0098a978(int param_1,undefined4 param_2)

{
  int iVar1;
  int extraout_r1;
  uint uVar2;
  uint extraout_r1_00;
  int *piVar3;
  int iVar4;
  
  piVar3 = *(int **)(param_1 + 0x68);
  if (piVar3 == (int *)0x0) {
    FUN_009a5ce4(param_2,*(undefined4 *)(param_1 + 0x60));
    uVar2 = extraout_r1_00;
  }
  else {
    iVar1 = piVar3[1];
    iVar4 = *piVar3;
    if (iVar1 == 0) {
      iVar1 = *(int *)(param_1 + 0x60);
    }
    FUN_009a5ce4(param_2,iVar1);
    uVar2 = (uint)*(byte *)(iVar4 + extraout_r1);
  }
  uVar2 = FUN_0098a930(*(undefined4 *)(param_1 + 100),uVar2);
  *(uint *)(param_1 + 0x54) = uVar2;
  if ((uVar2 & 0xff) == (uint)*(byte *)(param_1 + 0x58)) {
    *(undefined4 *)(param_1 + 0x54) = *(undefined4 *)(param_1 + 0x58);
  }
  return;
}


// ===== FUN_0098a9d8 @ 0098a9d8

uint FUN_0098a9d8(char *param_1,uint param_2,uint param_3,undefined4 param_4)

{
  char *pcVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  undefined8 uVar5;
  byte bVar6;
  byte bVar7;
  
  uVar2 = param_3 & 0xff;
  if (param_2 <= uVar2) {
    uVar2 = (int)*param_1 & ~((int)*param_1 >> 0x1f);
    if ((int)param_1[1] <= (int)uVar2) {
      uVar2 = (int)param_1[1];
    }
    return (uVar2 & 0xff) << 8 | (uint)(byte)param_1[3] << 0x10 | 0x5000000;
  }
  pcVar1 = param_1 + uVar2 * 0xc;
  uVar4 = (uint)(char)(param_3 >> 8);
  bVar6 = (byte)(param_3 >> 0x10);
  uVar3 = (int)param_1[uVar2 * 0xc];
  if ((int)param_1[uVar2 * 0xc] < (int)uVar4) {
    uVar3 = uVar4;
  }
  bVar7 = (byte)(param_3 >> 0x18);
  if ((int)pcVar1[1] <= (int)uVar3) {
    uVar3 = (int)pcVar1[1];
  }
  uVar3 = uVar3 & 0xff;
  if ((byte)pcVar1[2] <= bVar6) {
    bVar6 = pcVar1[3];
  }
  uVar5 = FUN_0098a850(pcVar1,bVar6,uVar2,uVar3,param_1,param_3,param_3,param_4);
  uVar4 = (uint)uVar5 ^ 1;
  if (0xb < bVar7) {
    uVar4 = uVar4 | 1;
  }
  if ((uVar4 & 1) != 0) {
    bVar7 = 5;
  }
  return uVar2 | uVar3 << 8 | (int)((ulonglong)uVar5 >> 0x20) << 0x10 | (uint)bVar7 << 0x18;
}


// ===== FUN_0098aa70 @ 0098aa70

uint FUN_0098aa70(char *param_1,char *param_2,undefined4 param_3,ushort param_4)

{
  char *pcVar1;
  uint uVar2;
  undefined1 extraout_r1;
  char *pcVar3;
  char *pcVar4;
  uint uVar5;
  undefined4 unaff_r4;
  uint uVar6;
  undefined4 in_lr;
  undefined8 uVar7;
  byte bStackY_1d;
  byte local_1c;
  undefined2 uVar8;
  undefined4 uVar9;
  byte bVar10;
  byte bVar11;
  
  uVar2 = param_4 >> 4 & 0x3f;
  bVar10 = (byte)((uint)param_3 >> 0x19);
  pcVar4 = (char *)(uint)bVar10;
  local_1c = (byte)param_4;
  uVar8 = CONCAT11((local_1c & 0xf) - 6,bVar10);
  uVar5 = CONCAT22((short)(CONCAT13(5,(uint3)((byte)(param_4 >> 4) & 0xf) << 0x10) >> 0x10),uVar8);
  if (pcVar4 < param_2 && 0xf < uVar2) {
    pcVar4 = param_1 + (int)pcVar4 * 0xc;
    if (*(ushort *)(pcVar4 + 4) != 0) {
      uVar5 = 0;
      do {
        if (((int)(uint)*(ushort *)(pcVar4 + 4) >> (uVar5 & 0xff) & 1U) != 0) break;
        uVar5 = uVar5 + 1;
      } while (uVar5 != 0xd);
      uVar2 = uVar2 - 0x10;
      pcVar4 = (char *)(uVar5 + uVar2 / 0xc);
      uVar9 = CONCAT13(5,CONCAT12((char)pcVar4,uVar8));
      FUN_009a5e2c(uVar2,0xc,uVar2 * -0x55555555);
      uVar5 = CONCAT13(extraout_r1,(int3)uVar9);
    }
  }
  pcVar3 = (char *)(uVar5 & 0xff);
  if (param_2 <= pcVar3) {
    uVar2 = (int)*param_1 & ~((int)*param_1 >> 0x1f);
    if ((int)param_1[1] <= (int)uVar2) {
      uVar2 = (int)param_1[1];
    }
    return (uVar2 & 0xff) << 8 | (uint)(byte)param_1[3] << 0x10 | 0x5000000;
  }
  pcVar1 = param_1 + (int)pcVar3 * 0xc;
  uVar6 = (uint)(char)(uVar5 >> 8);
  bVar10 = (byte)(uVar5 >> 0x10);
  uVar2 = (int)param_1[(int)pcVar3 * 0xc];
  if ((int)param_1[(int)pcVar3 * 0xc] < (int)uVar6) {
    uVar2 = uVar6;
  }
  bVar11 = (byte)(uVar5 >> 0x18);
  if ((int)pcVar1[1] <= (int)uVar2) {
    uVar2 = (int)pcVar1[1];
  }
  uVar2 = uVar2 & 0xff;
  if ((byte)pcVar1[2] <= bVar10) {
    bVar10 = pcVar1[3];
  }
  uVar7 = FUN_0098a850(pcVar1,bVar10,pcVar3,uVar2,param_1,uVar5,uVar5,pcVar4,unaff_r4,in_lr);
  uVar5 = (uint)uVar7 ^ 1;
  if (0xb < bVar11) {
    uVar5 = uVar5 | 1;
  }
  if ((uVar5 & 1) != 0) {
    bVar11 = 5;
  }
  return (uint)pcVar3 | uVar2 << 8 | (int)((ulonglong)uVar7 >> 0x20) << 0x10 | (uint)bVar11 << 0x18;
}


// ===== FUN_0098ab48 @ 0098ab48

void FUN_0098ab48(int param_1)

{
  bool bVar1;
  uint *puVar2;
  int iVar3;
  undefined4 uVar4;
  uint *puVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  byte local_80;
  undefined1 auStack_7f [4];
  undefined1 auStack_7b [4];
  undefined1 local_77;
  undefined1 auStack_76 [2];
  undefined4 local_74;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  undefined4 local_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 local_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  uint local_48;
  uint local_44;
  undefined4 local_40;
  int local_3c;
  int local_38;
  uint local_34;
  uint local_30;
  undefined4 local_2c;
  uint local_28;
  undefined4 local_24;
  
  FUN_0098a880();
  if (*(int *)(param_1 + 0x34) != 0) {
    FUN_00997590(auStack_76,0,0x4e);
    local_80 = *(byte *)(param_1 + 0x38);
    uVar6 = (uint)local_80;
    FUN_009975a8(auStack_7f,param_1 + 0x54,4);
    FUN_009975a8(auStack_7b,param_1 + 0x58,4);
    local_77 = *(undefined1 *)(param_1 + 0x5c);
    local_74 = *(undefined4 *)(param_1 + 0x1108);
    uStack_70 = *(undefined4 *)(param_1 + 0x110c);
    uStack_6c = *(undefined4 *)(param_1 + 0x1110);
    uStack_68 = *(undefined4 *)(param_1 + 0x1114);
    local_64 = *(undefined4 *)(param_1 + 0x1118);
    uStack_60 = *(undefined4 *)(param_1 + 0x111c);
    uStack_5c = *(undefined4 *)(param_1 + 0x1120);
    uStack_58 = *(undefined4 *)(param_1 + 0x1124);
    local_54 = *(undefined4 *)(param_1 + 0x1128);
    uStack_50 = *(undefined4 *)(param_1 + 0x112c);
    uStack_4c = *(undefined4 *)(param_1 + 0x1130);
    local_28 = (uint)(*(int *)(param_1 + 0x1074) == 0);
    local_24 = *(undefined4 *)(param_1 + 0x1104);
    if ((uVar6 - 2 < 2) && (iVar9 = *(int *)(param_1 + 0x106c), iVar9 != 0)) {
      iVar7 = *(int *)(param_1 + 0x1070);
      iVar8 = param_1 + (iVar7 + 0xd) * 8;
      iVar3 = param_1 + iVar7 * 8;
      uVar6 = *(uint *)(iVar8 + 4) & 0xffffff;
      local_48 = uVar6;
      local_40 = FUN_0098aa70(*(undefined4 *)(param_1 + 100),*(undefined4 *)(param_1 + 0x60),
                              *(undefined4 *)(iVar3 + 0x6c),*(undefined4 *)(iVar3 + 0x70));
      local_44 = *(byte *)(iVar8 + 7) & 1;
      bVar1 = false;
      local_34 = (uint)(uVar6 == *(uint *)(param_1 + 0x1078));
      uVar4 = 0;
      local_30 = (uint)(*(uint *)(param_1 + 0x107c) == uVar6);
      local_3c = iVar9 - iVar7;
      puVar5 = (uint *)(param_1 + 0x107c);
      puVar2 = puVar5 + *(int *)(param_1 + 0x1100);
      while (puVar2 != puVar5) {
        puVar5 = puVar5 + 1;
        if (*puVar5 == uVar6) {
          uVar4 = 1;
        }
        bVar1 = true;
      }
      if (bVar1) {
        local_2c = uVar4;
      }
      local_38 = iVar9;
      if (uVar6 != *(uint *)(param_1 + 0x1078)) {
        (**(code **)(param_1 + 0x14))(*(undefined4 *)(param_1 + 0x24),uVar6);
      }
    }
    *(int *)(param_1 + 0x1164) = *(int *)(param_1 + 0x1164) + 1;
    (**(code **)(param_1 + 0x10))(*(undefined4 *)(param_1 + 0x24),&local_80);
  }
  return;
}


// ===== FUN_0098ace4 @ 0098ace4

undefined4 FUN_0098ace4(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  if (*(int *)(param_1 + 0x34) == 0) {
    iVar1 = (**(code **)(param_1 + 4))(*(undefined4 *)(param_1 + 0x24));
    *(int *)(param_1 + 0x30) = iVar1;
    if ((iVar1 != 0) || (*(int *)(param_1 + 0x3c) != 0)) {
      return 0;
    }
    *(char *)(param_1 + 0x39) = (char)param_2;
    uVar2 = FUN_0098a868(param_1);
    *(undefined4 *)(param_1 + 0x3c) = uVar2;
    *(int *)(param_1 + 0x1140) = *(int *)(param_1 + 0x1140) + 1;
    (**(code **)(param_1 + 8))(*(undefined4 *)(param_1 + 0x24),6);
  }
  else {
    if (param_2 == 2) {
      *(int *)(param_1 + 0x1148) = *(int *)(param_1 + 0x1148) + 1;
      *(undefined1 *)(param_1 + 0x38) = 2;
      iVar1 = FUN_0098a868();
      iVar1 = iVar1 + 4000;
    }
    else {
      *(undefined1 *)(param_1 + 0x38) = 1;
      iVar1 = 0;
    }
    *(int *)(param_1 + 0x48) = iVar1;
    FUN_0098ab48(param_1);
  }
  return 1;
}


// ===== FUN_0098ace8 @ 0098ace8

undefined4 FUN_0098ace8(int param_1,int param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_4 == 0) {
    iVar1 = (**(code **)(param_1 + 4))(*(undefined4 *)(param_1 + 0x24));
    *(int *)(param_1 + 0x30) = iVar1;
    if ((iVar1 != 0) || (*(int *)(param_1 + 0x3c) != 0)) {
      return 0;
    }
    *(char *)(param_1 + 0x39) = (char)param_2;
    uVar2 = FUN_0098a868(param_1);
    *(undefined4 *)(param_1 + 0x3c) = uVar2;
    *(int *)(param_1 + 0x1140) = *(int *)(param_1 + 0x1140) + 1;
    (**(code **)(param_1 + 8))(*(undefined4 *)(param_1 + 0x24),6);
  }
  else {
    if (param_2 == 2) {
      *(int *)(param_1 + 0x1148) = *(int *)(param_1 + 0x1148) + 1;
      *(undefined1 *)(param_1 + 0x38) = 2;
      iVar1 = FUN_0098a868();
      iVar1 = iVar1 + 4000;
    }
    else {
      *(undefined1 *)(param_1 + 0x38) = 1;
      iVar1 = 0;
    }
    *(int *)(param_1 + 0x48) = iVar1;
    FUN_0098ab48(param_1);
  }
  return 1;
}


// ===== FUN_0098ada0 @ 0098ada0

bool FUN_0098ada0(uint param_1,uint param_2)

{
  bool bVar1;
  char cStack_7;
  char cStack_6;
  char cStack_5;
  char cStack_3;
  char cStack_2;
  char cStack_1;
  
  if ((((param_1 & 0xff) == (param_2 & 0xff)) &&
      (cStack_3 = (char)(param_1 >> 8), cStack_7 = (char)(param_2 >> 8), cStack_3 == cStack_7)) &&
     (cStack_2 = (char)(param_1 >> 0x10), cStack_6 = (char)(param_2 >> 0x10), cStack_2 == cStack_6))
  {
    cStack_1 = (char)(param_1 >> 0x18);
    cStack_5 = (char)(param_2 >> 0x18);
    bVar1 = cStack_1 == cStack_5;
  }
  else {
    bVar1 = false;
  }
  return bVar1;
}


// ===== FUN_0098ae00 @ 0098ae00

void FUN_0098ae00(undefined4 *param_1,undefined4 *param_2,int param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  undefined4 uVar1;
  undefined1 *puVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  puVar2 = (undefined1 *)((int)param_1 + -1);
  do {
    puVar2 = puVar2 + 1;
    *puVar2 = 0;
  } while (puVar2 != (undefined1 *)((int)param_1 + 0x11b7));
  uVar1 = param_2[1];
  uVar3 = param_2[2];
  uVar4 = param_2[3];
  *param_1 = *param_2;
  param_1[1] = uVar1;
  param_1[2] = uVar3;
  param_1[3] = uVar4;
  uVar1 = param_2[5];
  uVar3 = param_2[6];
  uVar4 = param_2[7];
  param_1[4] = param_2[4];
  param_1[5] = uVar1;
  param_1[6] = uVar3;
  param_1[7] = uVar4;
  uVar1 = param_2[9];
  uVar3 = param_2[10];
  uVar4 = param_2[0xb];
  param_1[8] = param_2[8];
  param_1[9] = uVar1;
  param_1[10] = uVar3;
  param_1[0xb] = uVar4;
  if (param_3 == 0) {
    param_3 = 1;
  }
  param_1[0x18] = param_3;
  param_1[0x19] = param_4;
  param_1[0x1a] = param_5;
  uVar1 = FUN_0098a9d8(param_4,param_3,param_6);
  *(undefined1 *)(param_1 + 0x17) = 0;
  param_1[0x16] = uVar1;
  param_1[0x15] = uVar1;
  return;
}


// ===== FUN_0098ae84 @ 0098ae84

void FUN_0098ae84(int param_1)

{
  bool bVar1;
  uint *puVar2;
  int iVar3;
  undefined4 uVar4;
  uint *puVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  byte bStack_80;
  undefined1 auStack_7f [4];
  undefined1 auStack_7b [4];
  undefined1 uStack_77;
  undefined1 auStack_76 [2];
  undefined4 uStack_74;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  uint uStack_48;
  uint uStack_44;
  undefined4 uStack_40;
  int iStack_3c;
  int iStack_38;
  uint uStack_34;
  uint uStack_30;
  undefined4 uStack_2c;
  uint uStack_28;
  undefined4 uStack_24;
  
  *(undefined4 *)(param_1 + 0x1074) = 1;
  FUN_0098a880();
  if (*(int *)(param_1 + 0x34) != 0) {
    FUN_00997590(auStack_76,0,0x4e);
    bStack_80 = *(byte *)(param_1 + 0x38);
    uVar6 = (uint)bStack_80;
    FUN_009975a8(auStack_7f,param_1 + 0x54,4);
    FUN_009975a8(auStack_7b,param_1 + 0x58,4);
    uStack_77 = *(undefined1 *)(param_1 + 0x5c);
    uStack_74 = *(undefined4 *)(param_1 + 0x1108);
    uStack_70 = *(undefined4 *)(param_1 + 0x110c);
    uStack_6c = *(undefined4 *)(param_1 + 0x1110);
    uStack_68 = *(undefined4 *)(param_1 + 0x1114);
    uStack_64 = *(undefined4 *)(param_1 + 0x1118);
    uStack_60 = *(undefined4 *)(param_1 + 0x111c);
    uStack_5c = *(undefined4 *)(param_1 + 0x1120);
    uStack_58 = *(undefined4 *)(param_1 + 0x1124);
    uStack_54 = *(undefined4 *)(param_1 + 0x1128);
    uStack_50 = *(undefined4 *)(param_1 + 0x112c);
    uStack_4c = *(undefined4 *)(param_1 + 0x1130);
    uStack_28 = (uint)(*(int *)(param_1 + 0x1074) == 0);
    uStack_24 = *(undefined4 *)(param_1 + 0x1104);
    if ((uVar6 - 2 < 2) && (iVar9 = *(int *)(param_1 + 0x106c), iVar9 != 0)) {
      iVar7 = *(int *)(param_1 + 0x1070);
      iVar8 = param_1 + (iVar7 + 0xd) * 8;
      iVar3 = param_1 + iVar7 * 8;
      uVar6 = *(uint *)(iVar8 + 4) & 0xffffff;
      uStack_48 = uVar6;
      uStack_40 = FUN_0098aa70(*(undefined4 *)(param_1 + 100),*(undefined4 *)(param_1 + 0x60),
                               *(undefined4 *)(iVar3 + 0x6c),*(undefined4 *)(iVar3 + 0x70));
      uStack_44 = *(byte *)(iVar8 + 7) & 1;
      bVar1 = false;
      uStack_34 = (uint)(uVar6 == *(uint *)(param_1 + 0x1078));
      uVar4 = 0;
      uStack_30 = (uint)(*(uint *)(param_1 + 0x107c) == uVar6);
      iStack_3c = iVar9 - iVar7;
      puVar5 = (uint *)(param_1 + 0x107c);
      puVar2 = puVar5 + *(int *)(param_1 + 0x1100);
      while (puVar2 != puVar5) {
        puVar5 = puVar5 + 1;
        if (*puVar5 == uVar6) {
          uVar4 = 1;
        }
        bVar1 = true;
      }
      if (bVar1) {
        uStack_2c = uVar4;
      }
      iStack_38 = iVar9;
      if (uVar6 != *(uint *)(param_1 + 0x1078)) {
        (**(code **)(param_1 + 0x14))(*(undefined4 *)(param_1 + 0x24),uVar6);
      }
    }
    *(int *)(param_1 + 0x1164) = *(int *)(param_1 + 0x1164) + 1;
    (**(code **)(param_1 + 0x10))(*(undefined4 *)(param_1 + 0x24),&bStack_80);
  }
  return;
}


// ===== FUN_0098ae94 @ 0098ae94

void FUN_0098ae94(int param_1,int *param_2)

{
  bool bVar1;
  uint *puVar2;
  int iVar3;
  undefined4 uVar4;
  uint *puVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  byte bStack_80;
  undefined1 auStack_7f [4];
  undefined1 auStack_7b [4];
  undefined1 uStack_77;
  undefined1 auStack_76 [2];
  undefined4 uStack_74;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  uint uStack_48;
  uint uStack_44;
  undefined4 uStack_40;
  int iStack_3c;
  int iStack_38;
  uint uStack_34;
  uint uStack_30;
  undefined4 uStack_2c;
  uint uStack_28;
  undefined4 uStack_24;
  
  *(int **)(param_1 + 0x68) = param_2;
  if (param_2 != (int *)0x0) {
    for (iVar6 = 0; param_2[1] != iVar6; iVar6 = iVar6 + 1) {
      if (*(char *)(*param_2 + iVar6) == *(char *)(param_1 + 0x54)) goto FUN_0098ab48;
    }
    *(undefined4 *)(param_1 + 0x54) = *(undefined4 *)(param_1 + 0x58);
  }
FUN_0098ab48:
  FUN_0098a880();
  if (*(int *)(param_1 + 0x34) != 0) {
    FUN_00997590(auStack_76,0,0x4e);
    bStack_80 = *(byte *)(param_1 + 0x38);
    uVar7 = (uint)bStack_80;
    FUN_009975a8(auStack_7f,param_1 + 0x54,4);
    FUN_009975a8(auStack_7b,param_1 + 0x58,4);
    uStack_77 = *(undefined1 *)(param_1 + 0x5c);
    uStack_74 = *(undefined4 *)(param_1 + 0x1108);
    uStack_70 = *(undefined4 *)(param_1 + 0x110c);
    uStack_6c = *(undefined4 *)(param_1 + 0x1110);
    uStack_68 = *(undefined4 *)(param_1 + 0x1114);
    uStack_64 = *(undefined4 *)(param_1 + 0x1118);
    uStack_60 = *(undefined4 *)(param_1 + 0x111c);
    uStack_5c = *(undefined4 *)(param_1 + 0x1120);
    uStack_58 = *(undefined4 *)(param_1 + 0x1124);
    uStack_54 = *(undefined4 *)(param_1 + 0x1128);
    uStack_50 = *(undefined4 *)(param_1 + 0x112c);
    uStack_4c = *(undefined4 *)(param_1 + 0x1130);
    uStack_28 = (uint)(*(int *)(param_1 + 0x1074) == 0);
    uStack_24 = *(undefined4 *)(param_1 + 0x1104);
    if ((uVar7 - 2 < 2) && (iVar6 = *(int *)(param_1 + 0x106c), iVar6 != 0)) {
      iVar8 = *(int *)(param_1 + 0x1070);
      iVar9 = param_1 + (iVar8 + 0xd) * 8;
      iVar3 = param_1 + iVar8 * 8;
      uVar7 = *(uint *)(iVar9 + 4) & 0xffffff;
      uStack_48 = uVar7;
      uStack_40 = FUN_0098aa70(*(undefined4 *)(param_1 + 100),*(undefined4 *)(param_1 + 0x60),
                               *(undefined4 *)(iVar3 + 0x6c),*(undefined4 *)(iVar3 + 0x70));
      uStack_44 = *(byte *)(iVar9 + 7) & 1;
      bVar1 = false;
      uStack_34 = (uint)(uVar7 == *(uint *)(param_1 + 0x1078));
      uVar4 = 0;
      uStack_30 = (uint)(*(uint *)(param_1 + 0x107c) == uVar7);
      iStack_3c = iVar6 - iVar8;
      puVar5 = (uint *)(param_1 + 0x107c);
      puVar2 = puVar5 + *(int *)(param_1 + 0x1100);
      while (puVar2 != puVar5) {
        puVar5 = puVar5 + 1;
        if (*puVar5 == uVar7) {
          uVar4 = 1;
        }
        bVar1 = true;
      }
      if (bVar1) {
        uStack_2c = uVar4;
      }
      iStack_38 = iVar6;
      if (uVar7 != *(uint *)(param_1 + 0x1078)) {
        (**(code **)(param_1 + 0x14))(*(undefined4 *)(param_1 + 0x24),uVar7);
      }
    }
    *(int *)(param_1 + 0x1164) = *(int *)(param_1 + 0x1164) + 1;
    (**(code **)(param_1 + 0x10))(*(undefined4 *)(param_1 + 0x24),&bStack_80);
  }
  return;
}


// ===== FUN_0098aee4 @ 0098aee4

void FUN_0098aee4(int param_1,int param_2,uint param_3)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  uint uVar5;
  
  iVar3 = param_3 + 0x1ffffe00;
  if (0x200 < param_3) {
    param_3 = 0x200;
    param_2 = param_2 + iVar3 * 8;
  }
  for (uVar5 = 0; param_3 != uVar5; uVar5 = uVar5 + 1) {
    puVar4 = (undefined4 *)(param_1 + 0x6c + uVar5 * 8);
    puVar1 = (undefined4 *)(param_2 + uVar5 * 8);
    uVar2 = puVar1[1];
    *puVar4 = *puVar1;
    puVar4[1] = uVar2;
  }
  *(uint *)(param_1 + 0x106c) = param_3;
  if (param_3 != 0) {
    param_3 = param_3 - 1;
  }
  *(undefined4 *)(param_1 + 0x1074) = 1;
  *(uint *)(param_1 + 0x1070) = param_3;
  return;
}


// ===== FUN_0098aef0 @ 0098aef0

void FUN_0098aef0(int param_1,int param_2,int param_3,int param_4)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int iVar4;
  bool in_ZR;
  bool in_CY;
  
  if (in_CY && !in_ZR) {
    param_3 = 0x200;
    param_2 = param_2 + param_4 * 8;
  }
  for (iVar4 = 0; param_3 != iVar4; iVar4 = iVar4 + 1) {
    puVar3 = (undefined4 *)(param_1 + 0x6c + iVar4 * 8);
    puVar1 = (undefined4 *)(param_2 + iVar4 * 8);
    uVar2 = puVar1[1];
    *puVar3 = *puVar1;
    puVar3[1] = uVar2;
  }
  *(int *)(param_1 + 0x106c) = param_3;
  if (param_3 != 0) {
    param_3 = param_3 + -1;
  }
  *(undefined4 *)(param_1 + 0x1074) = 1;
  *(int *)(param_1 + 0x1070) = param_3;
  return;
}


// ===== FUN_0098af4c @ 0098af4c

undefined4 FUN_0098af4c(int param_1,int param_2)

{
  undefined4 uVar1;
  
  *(int *)(param_1 + 0x1160) = *(int *)(param_1 + 0x1160) + 1;
  if (*(int *)(param_1 + 0x34) == 0) {
    if (param_2 == 4) {
      FUN_0098ace4(param_1,1);
      return 1;
    }
    if ((param_2 == 6) && (*(int *)(param_1 + 0x3c) == 0)) {
      *(undefined1 *)(param_1 + 0x39) = 3;
      uVar1 = FUN_0098a868();
      *(undefined4 *)(param_1 + 0x3c) = uVar1;
      *(int *)(param_1 + 0x1158) = *(int *)(param_1 + 0x1158) + 1;
    }
  }
  return 0;
}


// ===== FUN_0098afc4 @ 0098afc4

void FUN_0098afc4(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6)

{
  int iVar1;
  char cVar2;
  uint uVar3;
  
  *(int *)(param_1 + 0x30) = param_2;
  if (*(int *)(param_1 + 0x34) == 0 || param_6 != 0) {
    if (*(int *)(param_1 + 0x34) != 0) goto FUN_0098a880;
  }
  else {
    *(undefined1 *)(param_1 + 0x38) = 0;
    *(undefined4 *)(param_1 + 0x34) = 0;
    *(undefined4 *)(param_1 + 0x48) = 0;
    *(undefined4 *)(param_1 + 0x40) = 0;
    *(int *)(param_1 + 0x113c) = *(int *)(param_1 + 0x113c) + 1;
  }
  if ((param_2 == 6 || (param_4 == 0 || param_5 == 0)) || (param_3 != 1 && param_2 != 1))
  goto FUN_0098a880;
  iVar1 = (**(code **)(param_1 + 0xc))(*(undefined4 *)(param_1 + 0x24),param_4);
  if (iVar1 != 0) {
    *(int *)(param_1 + 0x1138) = *(int *)(param_1 + 0x1138) + 1;
    goto FUN_0098a880;
  }
  *(int *)(param_1 + 0x34) = param_4;
  *(int *)(param_1 + 0x1134) = *(int *)(param_1 + 0x1134) + 1;
  uVar3 = (uint)*(byte *)(param_1 + 0x39);
  *(undefined4 *)(param_1 + 0x3c) = 0;
  if (uVar3 == 0) {
    uVar3 = 3;
  }
  *(undefined1 *)(param_1 + 0x39) = 0;
  *(undefined4 *)(param_1 + 0x1078) = 0;
  if (uVar3 - 2 < 2) {
    if (*(int *)(param_1 + 0x106c) == 0) {
      uVar3 = 1;
      goto LAB_0098b104;
    }
    if (uVar3 == 2) {
      *(int *)(param_1 + 0x1148) = *(int *)(param_1 + 0x1148) + 1;
      cVar2 = '\x02';
    }
    else {
      cVar2 = '\x03';
    }
    *(int *)(param_1 + 0x1070) = *(int *)(param_1 + 0x106c) + -1;
    *(char *)(param_1 + 0x38) = cVar2;
    if (cVar2 != '\x02') goto LAB_0098b108;
    iVar1 = FUN_0098a868(param_1);
    iVar1 = iVar1 + 4000;
  }
  else {
LAB_0098b104:
    *(char *)(param_1 + 0x38) = (char)uVar3;
LAB_0098b108:
    iVar1 = 0;
  }
  *(int *)(param_1 + 0x48) = iVar1;
  FUN_0098ab48(param_1);
FUN_0098a880:
  if (*(uint *)(param_1 + 0x107c) == 0) {
    return;
  }
  if ((((*(int *)(param_1 + 0x34) == 0) || (1 < (byte)(*(char *)(param_1 + 0x38) - 2U))) ||
      (*(int *)(param_1 + 0x106c) == 0)) ||
     (*(uint *)(param_1 + 0x107c) !=
      (*(uint *)(param_1 + *(int *)(param_1 + 0x1070) * 8 + 0x6c) & 0xffffff))) {
    *(undefined4 *)(param_1 + 0x107c) = 0;
    return;
  }
  return;
}


// ===== FUN_0098b11c @ 0098b11c

void FUN_0098b11c(int param_1)

{
  int iVar1;
  uint uVar2;
  int in_stack_00000000;
  
  if (in_stack_00000000 == -0x7a64a8) {
    uVar2 = LZCOUNT(*(undefined4 *)(param_1 + 0x106c));
  }
  else {
    uVar2 = 0;
  }
  iVar1 = *(int *)(param_1 + 0x34);
  if (in_stack_00000000 == -0x7a64a8) {
    uVar2 = uVar2 >> 5;
  }
  FUN_0098afc4(param_1);
  if ((uVar2 != 0) && (*(int *)(param_1 + 0x34) != iVar1 && *(int *)(param_1 + 0x34) != 0)) {
    *(int *)(param_1 + 0x1154) = *(int *)(param_1 + 0x1154) + 1;
  }
  return;
}


// ===== FUN_0098b1a0 @ 0098b1a0

void FUN_0098b1a0(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = FUN_0098a868();
  *(undefined4 *)(param_1 + 0x50) = uVar1;
  return;
}


// ===== FUN_0098b1b4 @ 0098b1b4

uint FUN_0098b1b4(int *param_1,undefined4 param_2,uint param_3)

{
  uint uVar1;
  
  if (param_1 == (int *)0x0) {
    return param_3;
  }
  uVar1 = 0;
  while( true ) {
    if (uVar1 == param_1[1]) {
      return 0;
    }
    if (param_3 == *(byte *)(*param_1 + uVar1)) break;
    uVar1 = uVar1 + 1;
  }
  if ((uint)param_1[1] <= uVar1) {
    uVar1 = 0;
  }
  return uVar1;
}


// ===== FUN_0098b1fc @ 0098b1fc

uint FUN_0098b1fc(int param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  code *UNRECOVERED_JUMPTABLE;
  
  if (param_1 == 0) {
    return 0;
  }
  uVar2 = 0;
  do {
    uVar1 = uVar2;
    uVar2 = uVar1 + 1;
    if (*(uint *)(param_1 + 0xc) <= uVar2) {
      return uVar1;
    }
  } while (*(byte *)(*(int *)(param_1 + 8) + uVar2) <= param_2);
                    /* WARNING: Could not recover jumptable at 0x0098b230. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar2 = (*UNRECOVERED_JUMPTABLE)(uVar1);
  return uVar2;
}


// ===== FUN_0098b23c @ 0098b23c

int * FUN_0098b23c(int *param_1,int *param_2,int param_3,int param_4,uint param_5)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  bool bVar6;
  
  if (param_2 != (int *)0x0) {
    param_4 = FUN_0098b1b4(param_2);
    iVar2 = FUN_0098b1fc(param_2,param_4);
    uVar5 = (uint)*(byte *)(param_2[2] + iVar2);
    if (iVar2 + 1U < (uint)param_2[3]) {
      uVar3 = (uint)*(byte *)(param_2[2] + iVar2 + 1U);
    }
    else {
      uVar3 = param_2[1];
    }
    for (uVar4 = 0; (uVar4 != param_2[1] && (*(byte *)(*param_2 + uVar4) != param_5));
        uVar4 = uVar4 + 1) {
    }
    bVar6 = uVar4 < uVar5;
    uVar1 = uVar5;
    if (!bVar6) {
      uVar1 = uVar3;
    }
    if ((bVar6 || uVar3 < uVar4) || uVar4 == uVar1) {
      param_5 = 0xffffffff;
    }
    param_3 = uVar3 - uVar5;
    param_4 = param_4 - uVar5;
    if ((!bVar6 && uVar3 >= uVar4) && uVar4 != uVar1) {
      param_5 = uVar4 - uVar5;
    }
  }
  *param_1 = param_3;
  param_1[1] = param_4;
  param_1[2] = param_5;
  return param_1;
}


// ===== FUN_0098b2d8 @ 0098b2d8

void FUN_0098b2d8(int *param_1,int param_2,int param_3,int *param_4,int param_5,uint param_6)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  
  iVar2 = 0;
  uVar3 = 0;
  uVar7 = 0;
  while (uVar6 = uVar7, uVar3 < (uint)param_4[3]) {
    uVar4 = uVar3 + 1;
    if (uVar4 < (uint)param_4[3]) {
      uVar5 = (uint)*(byte *)(param_4[2] + uVar4);
    }
    else {
      uVar5 = param_4[1];
    }
    uVar3 = (uint)*(byte *)(param_4[2] + uVar3);
    uVar7 = uVar6;
    while (uVar3 < uVar5) {
      bVar1 = *(byte *)(*param_4 + uVar3);
      uVar3 = uVar3 + 1;
      if (*(char *)(param_5 + (uint)bVar1) != '\0' || bVar1 == param_6) {
        *(byte *)(param_2 + uVar7) = bVar1;
        uVar7 = uVar7 + 1;
      }
    }
    uVar3 = uVar4;
    if (uVar6 < uVar7) {
      *(char *)(param_3 + iVar2) = (char)uVar6;
      iVar2 = iVar2 + 1;
    }
  }
  *param_1 = param_2;
  param_1[1] = uVar6;
  param_1[2] = param_3;
  param_1[3] = iVar2;
  return;
}


// ===== FUN_0098b374 @ 0098b374

void FUN_0098b374(int param_1,uint param_2,uint param_3)

{
  char cVar1;
  bool bVar2;
  uint *puVar3;
  undefined4 uVar4;
  uint *puVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 *in_r12;
  byte bStack_80;
  undefined1 auStack_7f [4];
  undefined1 auStack_7b [4];
  undefined1 uStack_77;
  undefined1 auStack_76 [2];
  undefined4 uStack_74;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  uint uStack_48;
  uint uStack_44;
  undefined4 uStack_40;
  int iStack_3c;
  uint local_38;
  uint uStack_34;
  uint uStack_30;
  undefined4 uStack_2c;
  uint uStack_28;
  
  uVar10 = param_2 & 0xffffff;
  local_38 = param_2;
  uStack_34 = param_3;
  if ((param_2 & 0x1000000) != 0) {
    FUN_0098a8e0(param_1,uVar10);
  }
  for (iVar6 = 0; *(int *)(param_1 + 0x106c) != iVar6; iVar6 = iVar6 + 1) {
    iVar7 = param_1 + (iVar6 + 0xd) * 8;
    if ((*(uint *)(iVar7 + 4) & 0xffffff) == uVar10) {
      uVar11 = *(undefined4 *)(param_1 + 100);
      uVar12 = *(undefined4 *)(param_1 + 0x60);
      uVar4 = FUN_0098aa70(uVar11,uVar12,*(undefined4 *)(iVar7 + 4),*(undefined4 *)(iVar7 + 8));
      uVar11 = FUN_0098aa70(uVar11,uVar12,local_38,uStack_34);
      iVar6 = FUN_0098ada0(uVar4,uVar11);
      *(uint *)(iVar7 + 4) = local_38;
      *(uint *)(iVar7 + 8) = uStack_34;
      if ((iVar6 == 0) && (*(uint *)(param_1 + 0x1078) == uVar10)) {
        *(undefined4 *)(param_1 + 0x1078) = 0;
      }
      goto FUN_0098ab48;
    }
  }
  if (*(int *)(param_1 + 0x106c) == 0x200) {
    iVar6 = param_1;
    do {
      in_r12 = (undefined4 *)(iVar6 + 0x6c);
      iVar7 = iVar6 + 8;
      *in_r12 = *(undefined4 *)(iVar6 + 0x74);
      *(undefined4 *)(iVar6 + 0x70) = *(undefined4 *)(iVar6 + 0x78);
      iVar6 = iVar7;
    } while (param_1 + 0xff8 != iVar7);
    *(undefined4 *)(param_1 + 0x106c) = 0x1ff;
    if (*(int *)(param_1 + 0x1070) != 0) {
      *(int *)(param_1 + 0x1070) = *(int *)(param_1 + 0x1070) + -1;
    }
  }
  iVar6 = *(int *)(param_1 + 0x106c);
  if (iVar6 != 0) {
    in_r12 = (undefined4 *)LZCOUNT(*(int *)(param_1 + 0x1070) - (iVar6 + -1));
  }
  iVar8 = iVar6 + 1;
  iVar7 = param_1 + iVar6 * 8;
  *(int *)(param_1 + 0x106c) = iVar8;
  *(uint *)(iVar7 + 0x6c) = local_38;
  *(uint *)(iVar7 + 0x70) = uStack_34;
  if (iVar6 != 0) {
    uVar10 = (uint)in_r12 >> 5;
  }
  else {
    uVar10 = 1;
  }
  if (*(int *)(param_1 + 0x34) == 0) {
    iVar7 = 0;
    if (iVar8 != 0) {
      iVar7 = iVar6;
    }
    *(int *)(param_1 + 0x1070) = iVar7;
    if (((*(int *)(param_1 + 0x50) != 0) &&
        (iVar6 = FUN_0098a868(param_1), (uint)(iVar6 - *(int *)(param_1 + 0x50)) < 2000)) ||
       (iVar6 = FUN_0098ace4(param_1,2), iVar6 == 0)) {
      *(int *)(param_1 + 0x114c) = *(int *)(param_1 + 0x114c) + 1;
      uVar4 = FUN_0098a868(param_1);
      *(undefined4 *)(param_1 + 0x4c) = uVar4;
    }
    return;
  }
  cVar1 = *(char *)(param_1 + 0x38);
  if (cVar1 != '\x02') {
    if (cVar1 == '\x03') {
      uVar10 = uVar10 & 1;
    }
    else {
      uVar10 = 0;
    }
    if (uVar10 == 0) goto FUN_0098ab48;
  }
  iVar7 = 0;
  if (iVar8 != 0) {
    iVar7 = iVar6;
  }
  *(int *)(param_1 + 0x1070) = iVar7;
  if (cVar1 == '\x02') {
    iVar6 = FUN_0098a868(param_1);
    *(int *)(param_1 + 0x48) = iVar6 + 4000;
  }
FUN_0098ab48:
  FUN_0098a880();
  if (*(int *)(param_1 + 0x34) != 0) {
    FUN_00997590(auStack_76,0,0x4e);
    bStack_80 = *(byte *)(param_1 + 0x38);
    uVar10 = (uint)bStack_80;
    FUN_009975a8(auStack_7f,param_1 + 0x54,4);
    FUN_009975a8(auStack_7b,param_1 + 0x58,4);
    uStack_77 = *(undefined1 *)(param_1 + 0x5c);
    uStack_74 = *(undefined4 *)(param_1 + 0x1108);
    uStack_70 = *(undefined4 *)(param_1 + 0x110c);
    uStack_6c = *(undefined4 *)(param_1 + 0x1110);
    uStack_68 = *(undefined4 *)(param_1 + 0x1114);
    uStack_64 = *(undefined4 *)(param_1 + 0x1118);
    uStack_60 = *(undefined4 *)(param_1 + 0x111c);
    uStack_5c = *(undefined4 *)(param_1 + 0x1120);
    uStack_58 = *(undefined4 *)(param_1 + 0x1124);
    uStack_54 = *(undefined4 *)(param_1 + 0x1128);
    uStack_50 = *(undefined4 *)(param_1 + 0x112c);
    uStack_4c = *(undefined4 *)(param_1 + 0x1130);
    uStack_28 = (uint)(*(int *)(param_1 + 0x1074) == 0);
    if ((uVar10 - 2 < 2) && (uVar10 = *(uint *)(param_1 + 0x106c), uVar10 != 0)) {
      iVar7 = *(int *)(param_1 + 0x1070);
      iVar8 = param_1 + (iVar7 + 0xd) * 8;
      iVar6 = param_1 + iVar7 * 8;
      uVar9 = *(uint *)(iVar8 + 4) & 0xffffff;
      uStack_48 = uVar9;
      uStack_40 = FUN_0098aa70(*(undefined4 *)(param_1 + 100),*(undefined4 *)(param_1 + 0x60),
                               *(undefined4 *)(iVar6 + 0x6c),*(undefined4 *)(iVar6 + 0x70));
      uStack_44 = *(byte *)(iVar8 + 7) & 1;
      bVar2 = false;
      uStack_34 = (uint)(uVar9 == *(uint *)(param_1 + 0x1078));
      uVar4 = 0;
      uStack_30 = (uint)(*(uint *)(param_1 + 0x107c) == uVar9);
      iStack_3c = uVar10 - iVar7;
      puVar5 = (uint *)(param_1 + 0x107c);
      puVar3 = puVar5 + *(int *)(param_1 + 0x1100);
      while (puVar3 != puVar5) {
        puVar5 = puVar5 + 1;
        if (*puVar5 == uVar9) {
          uVar4 = 1;
        }
        bVar2 = true;
      }
      if (bVar2) {
        uStack_2c = uVar4;
      }
      local_38 = uVar10;
      if (uVar9 != *(uint *)(param_1 + 0x1078)) {
        (**(code **)(param_1 + 0x14))(*(undefined4 *)(param_1 + 0x24),uVar9);
      }
    }
    *(int *)(param_1 + 0x1164) = *(int *)(param_1 + 0x1164) + 1;
    (**(code **)(param_1 + 0x10))(*(undefined4 *)(param_1 + 0x24),&bStack_80);
  }
  return;
}


// ===== FUN_0098b574 @ 0098b574

void FUN_0098b574(int param_1,uint param_2)

{
  bool bVar1;
  uint *puVar2;
  int iVar3;
  undefined4 uVar4;
  uint *puVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  byte bStack_80;
  undefined1 auStack_7f [4];
  undefined1 auStack_7b [4];
  undefined1 uStack_77;
  undefined1 auStack_76 [2];
  undefined4 uStack_74;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  uint uStack_48;
  uint uStack_44;
  undefined4 uStack_40;
  int iStack_3c;
  int iStack_38;
  uint uStack_34;
  uint uStack_30;
  undefined4 uStack_2c;
  uint uStack_28;
  undefined4 uStack_24;
  
  if (1 < param_2) {
    param_2 = 2;
  }
  *(uint *)(param_1 + 0x1104) = param_2;
  FUN_0098a880();
  if (*(int *)(param_1 + 0x34) != 0) {
    FUN_00997590(auStack_76,0,0x4e);
    bStack_80 = *(byte *)(param_1 + 0x38);
    uVar6 = (uint)bStack_80;
    FUN_009975a8(auStack_7f,param_1 + 0x54,4);
    FUN_009975a8(auStack_7b,param_1 + 0x58,4);
    uStack_77 = *(undefined1 *)(param_1 + 0x5c);
    uStack_74 = *(undefined4 *)(param_1 + 0x1108);
    uStack_70 = *(undefined4 *)(param_1 + 0x110c);
    uStack_6c = *(undefined4 *)(param_1 + 0x1110);
    uStack_68 = *(undefined4 *)(param_1 + 0x1114);
    uStack_64 = *(undefined4 *)(param_1 + 0x1118);
    uStack_60 = *(undefined4 *)(param_1 + 0x111c);
    uStack_5c = *(undefined4 *)(param_1 + 0x1120);
    uStack_58 = *(undefined4 *)(param_1 + 0x1124);
    uStack_54 = *(undefined4 *)(param_1 + 0x1128);
    uStack_50 = *(undefined4 *)(param_1 + 0x112c);
    uStack_4c = *(undefined4 *)(param_1 + 0x1130);
    uStack_28 = (uint)(*(int *)(param_1 + 0x1074) == 0);
    uStack_24 = *(undefined4 *)(param_1 + 0x1104);
    if ((uVar6 - 2 < 2) && (iVar9 = *(int *)(param_1 + 0x106c), iVar9 != 0)) {
      iVar7 = *(int *)(param_1 + 0x1070);
      iVar8 = param_1 + (iVar7 + 0xd) * 8;
      iVar3 = param_1 + iVar7 * 8;
      uVar6 = *(uint *)(iVar8 + 4) & 0xffffff;
      uStack_48 = uVar6;
      uStack_40 = FUN_0098aa70(*(undefined4 *)(param_1 + 100),*(undefined4 *)(param_1 + 0x60),
                               *(undefined4 *)(iVar3 + 0x6c),*(undefined4 *)(iVar3 + 0x70));
      uStack_44 = *(byte *)(iVar8 + 7) & 1;
      bVar1 = false;
      uStack_34 = (uint)(uVar6 == *(uint *)(param_1 + 0x1078));
      uVar4 = 0;
      uStack_30 = (uint)(*(uint *)(param_1 + 0x107c) == uVar6);
      iStack_3c = iVar9 - iVar7;
      puVar5 = (uint *)(param_1 + 0x107c);
      puVar2 = puVar5 + *(int *)(param_1 + 0x1100);
      while (puVar2 != puVar5) {
        puVar5 = puVar5 + 1;
        if (*puVar5 == uVar6) {
          uVar4 = 1;
        }
        bVar1 = true;
      }
      if (bVar1) {
        uStack_2c = uVar4;
      }
      iStack_38 = iVar9;
      if (uVar6 != *(uint *)(param_1 + 0x1078)) {
        (**(code **)(param_1 + 0x14))(*(undefined4 *)(param_1 + 0x24),uVar6);
      }
    }
    *(int *)(param_1 + 0x1164) = *(int *)(param_1 + 0x1164) + 1;
    (**(code **)(param_1 + 0x10))(*(undefined4 *)(param_1 + 0x24),&bStack_80);
  }
  return;
}


// ===== FUN_0098b588 @ 0098b588

void FUN_0098b588(int param_1,int param_2,uint param_3)

{
  uint *puVar1;
  int iVar2;
  undefined4 uVar3;
  uint *puVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  bool bVar9;
  byte bStack_80;
  undefined1 auStack_7f [4];
  undefined1 auStack_7b [4];
  undefined1 uStack_77;
  undefined1 auStack_76 [2];
  undefined4 uStack_74;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  uint uStack_48;
  uint uStack_44;
  undefined4 uStack_40;
  int iStack_3c;
  int iStack_38;
  uint uStack_34;
  uint uStack_30;
  undefined4 uStack_2c;
  uint uStack_28;
  undefined4 uStack_24;
  
  uVar5 = 0;
  *(undefined4 *)(param_1 + 0x1100) = 0;
  while( true ) {
    bVar9 = 0x1f < uVar5;
    if (uVar5 != 0x20) {
      bVar9 = param_3 <= uVar5;
    }
    if (bVar9) break;
    iVar8 = *(int *)(param_1 + 0x1100);
    *(int *)(param_1 + 0x1100) = iVar8 + 1;
    *(undefined4 *)(param_1 + (iVar8 + 0x420) * 4) = *(undefined4 *)(param_2 + uVar5 * 4);
    uVar5 = uVar5 + 1;
  }
  FUN_0098a880();
  if (*(int *)(param_1 + 0x34) != 0) {
    FUN_00997590(auStack_76,0,0x4e);
    bStack_80 = *(byte *)(param_1 + 0x38);
    uVar5 = (uint)bStack_80;
    FUN_009975a8(auStack_7f,param_1 + 0x54,4);
    FUN_009975a8(auStack_7b,param_1 + 0x58,4);
    uStack_77 = *(undefined1 *)(param_1 + 0x5c);
    uStack_74 = *(undefined4 *)(param_1 + 0x1108);
    uStack_70 = *(undefined4 *)(param_1 + 0x110c);
    uStack_6c = *(undefined4 *)(param_1 + 0x1110);
    uStack_68 = *(undefined4 *)(param_1 + 0x1114);
    uStack_64 = *(undefined4 *)(param_1 + 0x1118);
    uStack_60 = *(undefined4 *)(param_1 + 0x111c);
    uStack_5c = *(undefined4 *)(param_1 + 0x1120);
    uStack_58 = *(undefined4 *)(param_1 + 0x1124);
    uStack_54 = *(undefined4 *)(param_1 + 0x1128);
    uStack_50 = *(undefined4 *)(param_1 + 0x112c);
    uStack_4c = *(undefined4 *)(param_1 + 0x1130);
    uStack_28 = (uint)(*(int *)(param_1 + 0x1074) == 0);
    uStack_24 = *(undefined4 *)(param_1 + 0x1104);
    if ((uVar5 - 2 < 2) && (iVar8 = *(int *)(param_1 + 0x106c), iVar8 != 0)) {
      iVar6 = *(int *)(param_1 + 0x1070);
      iVar7 = param_1 + (iVar6 + 0xd) * 8;
      iVar2 = param_1 + iVar6 * 8;
      uVar5 = *(uint *)(iVar7 + 4) & 0xffffff;
      uStack_48 = uVar5;
      uStack_40 = FUN_0098aa70(*(undefined4 *)(param_1 + 100),*(undefined4 *)(param_1 + 0x60),
                               *(undefined4 *)(iVar2 + 0x6c),*(undefined4 *)(iVar2 + 0x70));
      uStack_44 = *(byte *)(iVar7 + 7) & 1;
      bVar9 = false;
      uStack_34 = (uint)(uVar5 == *(uint *)(param_1 + 0x1078));
      uVar3 = 0;
      uStack_30 = (uint)(*(uint *)(param_1 + 0x107c) == uVar5);
      iStack_3c = iVar8 - iVar6;
      puVar4 = (uint *)(param_1 + 0x107c);
      puVar1 = puVar4 + *(int *)(param_1 + 0x1100);
      while (puVar1 != puVar4) {
        puVar4 = puVar4 + 1;
        if (*puVar4 == uVar5) {
          uVar3 = 1;
        }
        bVar9 = true;
      }
      if (bVar9) {
        uStack_2c = uVar3;
      }
      iStack_38 = iVar8;
      if (uVar5 != *(uint *)(param_1 + 0x1078)) {
        (**(code **)(param_1 + 0x14))(*(undefined4 *)(param_1 + 0x24),uVar5);
      }
    }
    *(int *)(param_1 + 0x1164) = *(int *)(param_1 + 0x1164) + 1;
    (**(code **)(param_1 + 0x10))(*(undefined4 *)(param_1 + 0x24),&bStack_80);
  }
  return;
}


// ===== FUN_0098b58c @ 0098b58c

void FUN_0098b58c(int param_1,int param_2,uint param_3,uint param_4)

{
  uint *puVar1;
  int iVar2;
  undefined4 uVar3;
  uint *puVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  bool bVar9;
  byte bStack_80;
  undefined1 auStack_7f [4];
  undefined1 auStack_7b [4];
  undefined1 uStack_77;
  undefined1 auStack_76 [2];
  undefined4 uStack_74;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  uint uStack_48;
  uint uStack_44;
  undefined4 uStack_40;
  int iStack_3c;
  int iStack_38;
  uint uStack_34;
  uint uStack_30;
  undefined4 uStack_2c;
  uint uStack_28;
  undefined4 uStack_24;
  
  *(uint *)(param_1 + 0x1100) = param_4;
  while( true ) {
    bVar9 = 0x1f < param_4;
    if (param_4 != 0x20) {
      bVar9 = param_3 <= param_4;
    }
    if (bVar9) break;
    iVar8 = *(int *)(param_1 + 0x1100);
    *(int *)(param_1 + 0x1100) = iVar8 + 1;
    *(undefined4 *)(param_1 + (iVar8 + 0x420) * 4) = *(undefined4 *)(param_2 + param_4 * 4);
    param_4 = param_4 + 1;
  }
  FUN_0098a880();
  if (*(int *)(param_1 + 0x34) != 0) {
    FUN_00997590(auStack_76,0,0x4e);
    bStack_80 = *(byte *)(param_1 + 0x38);
    uVar5 = (uint)bStack_80;
    FUN_009975a8(auStack_7f,param_1 + 0x54,4);
    FUN_009975a8(auStack_7b,param_1 + 0x58,4);
    uStack_77 = *(undefined1 *)(param_1 + 0x5c);
    uStack_74 = *(undefined4 *)(param_1 + 0x1108);
    uStack_70 = *(undefined4 *)(param_1 + 0x110c);
    uStack_6c = *(undefined4 *)(param_1 + 0x1110);
    uStack_68 = *(undefined4 *)(param_1 + 0x1114);
    uStack_64 = *(undefined4 *)(param_1 + 0x1118);
    uStack_60 = *(undefined4 *)(param_1 + 0x111c);
    uStack_5c = *(undefined4 *)(param_1 + 0x1120);
    uStack_58 = *(undefined4 *)(param_1 + 0x1124);
    uStack_54 = *(undefined4 *)(param_1 + 0x1128);
    uStack_50 = *(undefined4 *)(param_1 + 0x112c);
    uStack_4c = *(undefined4 *)(param_1 + 0x1130);
    uStack_28 = (uint)(*(int *)(param_1 + 0x1074) == 0);
    uStack_24 = *(undefined4 *)(param_1 + 0x1104);
    if ((uVar5 - 2 < 2) && (iVar8 = *(int *)(param_1 + 0x106c), iVar8 != 0)) {
      iVar6 = *(int *)(param_1 + 0x1070);
      iVar7 = param_1 + (iVar6 + 0xd) * 8;
      iVar2 = param_1 + iVar6 * 8;
      uVar5 = *(uint *)(iVar7 + 4) & 0xffffff;
      uStack_48 = uVar5;
      uStack_40 = FUN_0098aa70(*(undefined4 *)(param_1 + 100),*(undefined4 *)(param_1 + 0x60),
                               *(undefined4 *)(iVar2 + 0x6c),*(undefined4 *)(iVar2 + 0x70));
      uStack_44 = *(byte *)(iVar7 + 7) & 1;
      bVar9 = false;
      uStack_34 = (uint)(uVar5 == *(uint *)(param_1 + 0x1078));
      uVar3 = 0;
      uStack_30 = (uint)(*(uint *)(param_1 + 0x107c) == uVar5);
      iStack_3c = iVar8 - iVar6;
      puVar4 = (uint *)(param_1 + 0x107c);
      puVar1 = puVar4 + *(int *)(param_1 + 0x1100);
      while (puVar1 != puVar4) {
        puVar4 = puVar4 + 1;
        if (*puVar4 == uVar5) {
          uVar3 = 1;
        }
        bVar9 = true;
      }
      if (bVar9) {
        uStack_2c = uVar3;
      }
      iStack_38 = iVar8;
      if (uVar5 != *(uint *)(param_1 + 0x1078)) {
        (**(code **)(param_1 + 0x14))(*(undefined4 *)(param_1 + 0x24),uVar5);
      }
    }
    *(int *)(param_1 + 0x1164) = *(int *)(param_1 + 0x1164) + 1;
    (**(code **)(param_1 + 0x10))(*(undefined4 *)(param_1 + 0x24),&bStack_80);
  }
  return;
}


// ===== FUN_0098b5cc @ 0098b5cc

void FUN_0098b5cc(void)

{
  bool bVar1;
  uint *puVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  undefined4 uVar6;
  uint uVar7;
  uint *puVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  uint uVar13;
  undefined8 uVar14;
  byte bStack_80;
  undefined1 auStack_7f [4];
  undefined1 auStack_7b [4];
  undefined1 uStack_77;
  undefined1 auStack_76 [2];
  undefined4 uStack_74;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  uint uStack_48;
  uint uStack_44;
  undefined4 uStack_40;
  int iStack_3c;
  int iStack_38;
  uint uStack_34;
  uint uStack_30;
  undefined4 uStack_2c;
  uint uStack_28;
  undefined4 uStack_24;
  
  uVar14 = FUN_0098a8e0();
  uVar4 = (uint)((ulonglong)uVar14 >> 0x20);
  iVar3 = (int)uVar14;
  uVar7 = *(uint *)(iVar3 + 0x106c);
  uVar9 = 0;
  while( true ) {
    if (uVar7 == uVar9) {
      return;
    }
    uVar13 = uVar9 + 1;
    if ((*(uint *)(iVar3 + uVar9 * 8 + 0x6c) & 0xffffff) == uVar4) break;
    uVar9 = uVar13;
  }
  iVar12 = iVar3 + uVar9 * 8;
  for (; uVar13 < uVar7; uVar13 = uVar13 + 1) {
    *(undefined4 *)(iVar12 + 0x6c) = *(undefined4 *)(iVar12 + 0x74);
    *(undefined4 *)(iVar12 + 0x70) = *(undefined4 *)(iVar12 + 0x78);
    iVar12 = iVar12 + 8;
  }
  uVar13 = *(uint *)(iVar3 + 0x1070);
  *(uint *)(iVar3 + 0x106c) = uVar7 - 1;
  if ((uVar9 < uVar13) || (uVar9 != 0 && uVar13 == uVar9)) {
    *(uint *)(iVar3 + 0x1070) = uVar13 - 1;
  }
  if ((uVar7 - 1 != 0) && (uVar7 - 2 < *(uint *)(iVar3 + 0x1070))) {
    *(uint *)(iVar3 + 0x1070) = uVar7 - 2;
  }
  if (*(uint *)(iVar3 + 0x1078) == uVar4) {
    *(undefined4 *)(iVar3 + 0x1078) = 0;
  }
  if (*(uint *)(iVar3 + 0x107c) == uVar4) {
    *(undefined4 *)(iVar3 + 0x107c) = 0;
  }
  FUN_0098a880();
  if (*(int *)(iVar3 + 0x34) != 0) {
    FUN_00997590(auStack_76,0,0x4e);
    bStack_80 = *(byte *)(iVar3 + 0x38);
    uVar9 = (uint)bStack_80;
    FUN_009975a8(auStack_7f,iVar3 + 0x54,4);
    FUN_009975a8(auStack_7b,iVar3 + 0x58,4);
    uStack_77 = *(undefined1 *)(iVar3 + 0x5c);
    uStack_74 = *(undefined4 *)(iVar3 + 0x1108);
    uStack_70 = *(undefined4 *)(iVar3 + 0x110c);
    uStack_6c = *(undefined4 *)(iVar3 + 0x1110);
    uStack_68 = *(undefined4 *)(iVar3 + 0x1114);
    uStack_64 = *(undefined4 *)(iVar3 + 0x1118);
    uStack_60 = *(undefined4 *)(iVar3 + 0x111c);
    uStack_5c = *(undefined4 *)(iVar3 + 0x1120);
    uStack_58 = *(undefined4 *)(iVar3 + 0x1124);
    uStack_54 = *(undefined4 *)(iVar3 + 0x1128);
    uStack_50 = *(undefined4 *)(iVar3 + 0x112c);
    uStack_4c = *(undefined4 *)(iVar3 + 0x1130);
    uStack_28 = (uint)(*(int *)(iVar3 + 0x1074) == 0);
    uStack_24 = *(undefined4 *)(iVar3 + 0x1104);
    if ((uVar9 - 2 < 2) && (iVar12 = *(int *)(iVar3 + 0x106c), iVar12 != 0)) {
      iVar10 = *(int *)(iVar3 + 0x1070);
      iVar11 = iVar3 + (iVar10 + 0xd) * 8;
      iVar5 = iVar3 + iVar10 * 8;
      uVar9 = *(uint *)(iVar11 + 4) & 0xffffff;
      uStack_48 = uVar9;
      uStack_40 = FUN_0098aa70(*(undefined4 *)(iVar3 + 100),*(undefined4 *)(iVar3 + 0x60),
                               *(undefined4 *)(iVar5 + 0x6c),*(undefined4 *)(iVar5 + 0x70));
      uStack_44 = *(byte *)(iVar11 + 7) & 1;
      bVar1 = false;
      uStack_34 = (uint)(uVar9 == *(uint *)(iVar3 + 0x1078));
      uVar6 = 0;
      uStack_30 = (uint)(*(uint *)(iVar3 + 0x107c) == uVar9);
      iStack_3c = iVar12 - iVar10;
      puVar8 = (uint *)(iVar3 + 0x107c);
      puVar2 = puVar8 + *(int *)(iVar3 + 0x1100);
      while (puVar2 != puVar8) {
        puVar8 = puVar8 + 1;
        if (*puVar8 == uVar9) {
          uVar6 = 1;
        }
        bVar1 = true;
      }
      if (bVar1) {
        uStack_2c = uVar6;
      }
      iStack_38 = iVar12;
      if (uVar9 != *(uint *)(iVar3 + 0x1078)) {
        (**(code **)(iVar3 + 0x14))(*(undefined4 *)(iVar3 + 0x24),uVar9);
      }
    }
    *(int *)(iVar3 + 0x1164) = *(int *)(iVar3 + 0x1164) + 1;
    (**(code **)(iVar3 + 0x10))(*(undefined4 *)(iVar3 + 0x24),&bStack_80);
  }
  return;
}


// ===== FUN_0098b6b4 @ 0098b6b4

bool FUN_0098b6b4(int param_1,uint param_2)

{
  bool bVar1;
  byte bVar2;
  short sVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  int extraout_r1;
  uint uVar7;
  uint extraout_r1_00;
  uint uVar8;
  int iVar9;
  int iVar10;
  code *pcVar11;
  int iVar12;
  uint *puVar13;
  
  bVar1 = 1 < param_2 - 0x88c;
  if ((*(char *)(param_1 + 0x38) == '\x02') &&
     (param_2 != 0x880 &&
      ((bVar1 && (param_2 != 0x8a2 && param_2 != 0x870)) &&
      (param_2 != 0x888 && (param_2 != 0x80c && param_2 != 0x81f))))) {
    *(undefined1 *)(param_1 + 0x38) = 3;
    *(undefined4 *)(param_1 + 0x48) = 0;
  }
  iVar9 = 0;
  iVar10 = param_1 + 0x1176;
  do {
    sVar3 = *(short *)(iVar10 + 0x22);
    if ((*(ushort *)(iVar10 + 2) == param_2) || (sVar3 == 0)) {
      iVar10 = param_1 + iVar9 * 2;
      *(short *)(iVar10 + 0x1178) = (short)param_2;
      *(short *)(iVar10 + 0x1198) = sVar3 + 1;
      break;
    }
    iVar9 = iVar9 + 1;
    iVar10 = iVar10 + 2;
  } while (iVar9 != 0x10);
  FUN_0098a880(param_1);
  iVar10 = *(int *)(param_1 + 0x107c);
  if ((iVar10 != 0) && (param_2 != 0x880 && (bVar1 && (param_2 != 0x8a2 && param_2 != 0x870)))) {
    *(undefined4 *)(param_1 + 0x107c) = 0;
    if (param_2 == 0x839) {
      *(int *)(param_1 + 0x1174) = *(int *)(param_1 + 0x1174) + 1;
      (**(code **)(param_1 + 0x1c))(*(undefined4 *)(param_1 + 0x24),iVar10);
      FUN_0098b5cc(param_1,iVar10);
      return false;
    }
    if (param_2 != 0x888 && (param_2 != 0x80c && param_2 != 0x81f)) goto LAB_0098b80c;
    if (param_2 < 0x871) {
      return true;
    }
LAB_0098bd0c:
    if (param_2 == 0x888) {
      *(undefined1 *)(param_1 + 0x38) = 0;
      *(undefined4 *)(param_1 + 0x34) = 0;
      *(undefined4 *)(param_1 + 0x48) = 0;
      *(undefined4 *)(param_1 + 0x40) = 0;
      *(int *)(param_1 + 0x113c) = *(int *)(param_1 + 0x113c) + 1;
LAB_0098b844:
      return true;
    }
    if (param_2 < 0x888) {
      if (param_2 == 0x880) {
        *(undefined4 *)(param_1 + 0x44) = 1;
        return true;
      }
      return true;
    }
    if (param_2 < 0x88e) {
      if (param_2 < 0x88c) {
        return true;
      }
    }
    else if (param_2 != 0x8a2) {
      return true;
    }
    goto LAB_0098b80c;
  }
  if (0x870 < param_2) goto LAB_0098bd0c;
  if (param_2 < 0x84f) {
    if (param_2 == 0x820) {
      if (1 < (byte)(*(char *)(param_1 + 0x38) - 2U)) {
        return false;
      }
      if (*(int *)(param_1 + 0x106c) == 0) {
        return false;
      }
      if (*(int *)(param_1 + 0x1124) == 0) {
        return false;
      }
      *(uint *)(param_1 + 0x107c) =
           *(uint *)(param_1 + *(int *)(param_1 + 0x1070) * 8 + 0x6c) & 0xffffff;
      *(int *)(param_1 + 0x1170) = *(int *)(param_1 + 0x1170) + 1;
      goto LAB_0098b80c;
    }
    if (param_2 < 0x821) {
      if (param_2 != 0x819) {
        return true;
      }
      if (*(char *)(param_1 + 0x38) != '\x01') goto LAB_0098b984;
      *(undefined4 *)(param_1 + 0x54) = *(undefined4 *)(param_1 + 0x58);
      *(undefined1 *)(param_1 + 0x5c) = 0;
      goto LAB_0098b80c;
    }
    if (param_2 < 0x82b) {
      return param_2 < 0x829;
    }
    if (param_2 != 0x839) {
      return true;
    }
    if (*(char *)(param_1 + 0x38) != '\x01') {
      if (*(int *)(param_1 + 0x106c) != 0) {
        iVar10 = param_1 + (*(int *)(param_1 + 0x1070) + 0xd) * 8;
        bVar2 = *(byte *)(iVar10 + 7);
        uVar8 = bVar2 & 1;
        if ((bVar2 & 1) == 0) {
          uVar6 = *(uint *)(param_1 + 0x1100);
          uVar7 = *(uint *)(iVar10 + 4) & 0xffffff;
          puVar13 = (uint *)(param_1 + 0x107c);
          for (; uVar6 != uVar8; uVar8 = uVar8 + 1) {
            puVar13 = puVar13 + 1;
            if (*puVar13 == uVar7) goto LAB_0098b80c;
          }
          if (uVar6 != 0x20) {
            *(uint *)(param_1 + 0x1100) = uVar6 + 1;
            pcVar11 = *(code **)(param_1 + 0x20);
            *(uint *)(param_1 + (uVar6 + 0x420) * 4) = uVar7;
            goto LAB_0098b90c;
          }
        }
      }
      goto LAB_0098b80c;
    }
    iVar10 = FUN_0098ada0(*(undefined4 *)(param_1 + 0x58),*(undefined4 *)(param_1 + 0x54));
    if (iVar10 != 0) goto LAB_0098b80c;
    *(undefined4 *)(param_1 + 0x58) = *(undefined4 *)(param_1 + 0x54);
    pcVar11 = *(code **)(param_1 + 0x18);
    goto LAB_0098b90c;
  }
  switch(param_2) {
  case 0x84f:
  case 0x851:
  case 0x85d:
    goto LAB_0098b7ec;
  default:
    goto LAB_0098b844;
  case 0x856:
  case 0x85a:
  case 0x86b:
    iVar10 = -1;
    goto code_r0x0098b874;
  case 0x858:
  case 0x864:
    uVar8 = 0x858;
    if ((*(char *)(param_1 + 0x38) != '\x01') || (*(char *)(param_1 + 0x5c) != '\0')) {
code_r0x0098bab8:
      if (param_2 == uVar8) {
        iVar10 = -1;
      }
      else {
        iVar10 = 1;
      }
      goto code_r0x0098b874;
    }
    iVar10 = *(int *)(param_1 + 0x68);
    if (param_2 == 0x858) {
      iVar9 = -1;
    }
    else {
      iVar9 = 1;
    }
    if (iVar10 == 0) {
      uVar8 = 0;
    }
    else {
      iVar12 = *(int *)(iVar10 + 0xc);
      if (iVar12 == 0) break;
      uVar4 = FUN_0098b1b4(iVar10,*(undefined4 *)(param_1 + 0x60),*(undefined1 *)(param_1 + 0x54));
      iVar5 = FUN_0098b1fc(iVar10,uVar4);
      FUN_009a5ce4(iVar9 + iVar12 + iVar5,iVar12);
      uVar8 = (uint)*(byte *)(*(int *)(iVar10 + 8) + extraout_r1);
    }
    goto code_r0x0098baa4;
  case 0x85c:
  case 0x860:
    uVar8 = 0x85c;
    if (*(char *)(param_1 + 0x38) != '\x01') goto code_r0x0098bab8;
    if (param_2 == 0x85c) {
      iVar10 = -1;
    }
    else {
      iVar10 = 1;
    }
    uVar8 = (uint)*(byte *)(param_1 + 0x5c);
    do {
      while( true ) {
        uVar8 = uVar8 + iVar10;
        if (4 < uVar8) goto LAB_0098b80c;
        if (uVar8 == 0) goto code_r0x0098b9f8;
        iVar12 = (uint)*(byte *)(param_1 + 0x54) * 0xc;
        iVar9 = *(int *)(param_1 + 100) + iVar12;
        if (uVar8 == 1) break;
        if (uVar8 == 2) {
          if (1 < *(byte *)(iVar9 + 2)) goto code_r0x0098b9f8;
        }
        else if (uVar8 == 3) {
          iVar9 = FUN_0098a850(iVar9,*(undefined1 *)(param_1 + 0x56));
          if (iVar9 != 0) goto code_r0x0098b9f8;
        }
        else if ((*(code **)(param_1 + 0x2c) != (code *)0x0) &&
                (iVar9 = (**(code **)(param_1 + 0x2c))(*(undefined4 *)(param_1 + 0x24)), iVar9 != 0)
                ) {
          uVar8 = 4;
          goto code_r0x0098b9f8;
        }
      }
    } while (*(char *)(iVar9 + 1) <= *(char *)(*(int *)(param_1 + 100) + iVar12));
code_r0x0098b9f8:
    *(char *)(param_1 + 0x5c) = (char)uVar8;
    break;
  case 0x862:
  case 0x866:
  case 0x86a:
    iVar10 = 1;
code_r0x0098b874:
    if (*(char *)(param_1 + 0x38) == '\x01') {
      iVar9 = (uint)*(byte *)(param_1 + 0x54) * 0xc;
      iVar12 = *(int *)(param_1 + 100) + iVar9;
      switch(*(undefined1 *)(param_1 + 0x5c)) {
      case 0:
        iVar5 = *(int *)(param_1 + 0x68);
        iVar9 = *(int *)(param_1 + 0x60);
        iVar12 = FUN_0098b1b4(iVar5,iVar9);
        if ((iVar5 != 0) && (*(int *)(iVar5 + 4) != 0)) {
          iVar9 = *(int *)(iVar5 + 4);
        }
        FUN_009a5ce4(iVar10 + iVar12 + iVar9,iVar9);
        uVar8 = extraout_r1_00;
code_r0x0098baa4:
        FUN_0098a978(param_1,uVar8);
        break;
      case 1:
        iVar10 = *(char *)(param_1 + 0x55) + iVar10;
        if ((*(char *)(*(int *)(param_1 + 100) + iVar9) <= iVar10) &&
           (iVar10 <= *(char *)(iVar12 + 1))) {
          *(char *)(param_1 + 0x55) = (char)iVar10;
        }
        break;
      case 2:
        iVar10 = (uint)*(byte *)(param_1 + 0x56) + iVar10;
        if ((iVar10 != -1) && (iVar10 < (int)(uint)*(byte *)(iVar12 + 2))) {
          iVar9 = FUN_0098a850(iVar12);
          if ((iVar9 == 0) || (iVar9 = FUN_0098a850(iVar12,iVar10), iVar9 == 0)) {
            *(undefined1 *)(param_1 + 0x57) = 5;
          }
          *(char *)(param_1 + 0x56) = (char)iVar10;
        }
        break;
      case 3:
        uVar8 = (uint)*(byte *)(param_1 + 0x57) + iVar10;
        if (uVar8 < 0xc) {
          *(char *)(param_1 + 0x57) = (char)uVar8;
        }
        break;
      case 4:
        uVar8 = *(uint *)(param_1 + 0x1104) + iVar10;
        if (uVar8 < 3 && *(uint *)(param_1 + 0x1104) != uVar8) {
          *(uint *)(param_1 + 0x1104) = uVar8;
          pcVar11 = *(code **)(param_1 + 0x28);
          if (pcVar11 != (code *)0x0) {
LAB_0098b90c:
            (*pcVar11)(*(undefined4 *)(param_1 + 0x24));
          }
        }
      }
    }
    else if (*(int *)(param_1 + 0x106c) != 0) {
      iVar9 = *(int *)(param_1 + 0x106c) + -1;
      uVar8 = iVar10 + *(int *)(param_1 + 0x1070);
      uVar8 = uVar8 & ~((int)uVar8 >> 0x1f);
      if (iVar9 < (int)uVar8) {
        *(int *)(param_1 + 0x1070) = iVar9;
      }
      else {
        *(uint *)(param_1 + 0x1070) = uVar8;
      }
    }
    break;
  case 0x868:
    if (*(char *)(param_1 + 0x38) == '\x01') {
      *(undefined1 *)(param_1 + 0x38) = 3;
LAB_0098b984:
      iVar10 = *(int *)(param_1 + 0x106c);
      if (iVar10 != 0) {
        iVar10 = iVar10 + -1;
      }
      *(int *)(param_1 + 0x1070) = iVar10;
    }
    else {
      *(undefined1 *)(param_1 + 0x38) = 1;
    }
    break;
  case 0x870:
    break;
  }
LAB_0098b80c:
  FUN_0098ab48(param_1);
LAB_0098b7ec:
  return false;
}


// ===== FUN_0098bd60 @ 0098bd60

void FUN_0098bd60(int param_1,uint *param_2)

{
  bool bVar1;
  uint *puVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  uint *puVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  byte bStack_80;
  undefined1 auStack_7f [4];
  undefined1 auStack_7b [4];
  undefined1 uStack_77;
  undefined1 auStack_76 [2];
  undefined4 uStack_74;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  uint uStack_48;
  uint uStack_44;
  undefined4 uStack_40;
  int iStack_3c;
  int iStack_38;
  uint uStack_34;
  uint uStack_30;
  undefined4 uStack_2c;
  uint uStack_28;
  undefined4 uStack_24;
  
  uVar3 = param_2[1];
  uVar6 = param_2[2];
  uVar8 = param_2[3];
  *(uint *)(param_1 + 0x1108) = *param_2;
  *(uint *)(param_1 + 0x110c) = uVar3;
  *(uint *)(param_1 + 0x1110) = uVar6;
  *(uint *)(param_1 + 0x1114) = uVar8;
  uVar3 = param_2[5];
  uVar6 = param_2[6];
  uVar8 = param_2[7];
  *(uint *)(param_1 + 0x1118) = param_2[4];
  *(uint *)(param_1 + 0x111c) = uVar3;
  *(uint *)(param_1 + 0x1120) = uVar6;
  *(uint *)(param_1 + 0x1124) = uVar8;
  uVar3 = param_2[9];
  uVar6 = param_2[10];
  *(uint *)(param_1 + 0x1128) = param_2[8];
  *(uint *)(param_1 + 0x112c) = uVar3;
  *(uint *)(param_1 + 0x1130) = uVar6;
  if (*(int *)(param_1 + 0x34) == 0) {
    return;
  }
  if (*(char *)(param_1 + 0x38) != '\x01') {
    if (*(char *)(param_1 + 0x38) != '\x03') {
      return;
    }
    if (*(int *)(param_1 + 0x106c) == 0) {
      return;
    }
    if ((*(uint *)(param_1 + *(int *)(param_1 + 0x1070) * 8 + 0x6c) & 0xffffff) != *param_2) {
      return;
    }
  }
  FUN_0098a880();
  if (*(int *)(param_1 + 0x34) != 0) {
    FUN_00997590(auStack_76,0,0x4e);
    bStack_80 = *(byte *)(param_1 + 0x38);
    uVar3 = (uint)bStack_80;
    FUN_009975a8(auStack_7f,param_1 + 0x54,4);
    FUN_009975a8(auStack_7b,param_1 + 0x58,4);
    uStack_77 = *(undefined1 *)(param_1 + 0x5c);
    uStack_74 = *(undefined4 *)(param_1 + 0x1108);
    uStack_70 = *(undefined4 *)(param_1 + 0x110c);
    uStack_6c = *(undefined4 *)(param_1 + 0x1110);
    uStack_68 = *(undefined4 *)(param_1 + 0x1114);
    uStack_64 = *(undefined4 *)(param_1 + 0x1118);
    uStack_60 = *(undefined4 *)(param_1 + 0x111c);
    uStack_5c = *(undefined4 *)(param_1 + 0x1120);
    uStack_58 = *(undefined4 *)(param_1 + 0x1124);
    uStack_54 = *(undefined4 *)(param_1 + 0x1128);
    uStack_50 = *(undefined4 *)(param_1 + 0x112c);
    uStack_4c = *(undefined4 *)(param_1 + 0x1130);
    uStack_28 = (uint)(*(int *)(param_1 + 0x1074) == 0);
    uStack_24 = *(undefined4 *)(param_1 + 0x1104);
    if ((uVar3 - 2 < 2) && (iVar11 = *(int *)(param_1 + 0x106c), iVar11 != 0)) {
      iVar9 = *(int *)(param_1 + 0x1070);
      iVar10 = param_1 + (iVar9 + 0xd) * 8;
      iVar4 = param_1 + iVar9 * 8;
      uVar3 = *(uint *)(iVar10 + 4) & 0xffffff;
      uStack_48 = uVar3;
      uStack_40 = FUN_0098aa70(*(undefined4 *)(param_1 + 100),*(undefined4 *)(param_1 + 0x60),
                               *(undefined4 *)(iVar4 + 0x6c),*(undefined4 *)(iVar4 + 0x70));
      uStack_44 = *(byte *)(iVar10 + 7) & 1;
      bVar1 = false;
      uStack_34 = (uint)(uVar3 == *(uint *)(param_1 + 0x1078));
      uVar5 = 0;
      uStack_30 = (uint)(*(uint *)(param_1 + 0x107c) == uVar3);
      iStack_3c = iVar11 - iVar9;
      puVar7 = (uint *)(param_1 + 0x107c);
      puVar2 = puVar7 + *(int *)(param_1 + 0x1100);
      while (puVar2 != puVar7) {
        puVar7 = puVar7 + 1;
        if (*puVar7 == uVar3) {
          uVar5 = 1;
        }
        bVar1 = true;
      }
      if (bVar1) {
        uStack_2c = uVar5;
      }
      iStack_38 = iVar11;
      if (uVar3 != *(uint *)(param_1 + 0x1078)) {
        (**(code **)(param_1 + 0x14))(*(undefined4 *)(param_1 + 0x24),uVar3);
      }
    }
    *(int *)(param_1 + 0x1164) = *(int *)(param_1 + 0x1164) + 1;
    (**(code **)(param_1 + 0x10))(*(undefined4 *)(param_1 + 0x24),&bStack_80);
  }
  return;
}


// ===== FUN_0098bde4 @ 0098bde4

void FUN_0098bde4(int param_1,uint param_2,int param_3)

{
  bool bVar1;
  uint *puVar2;
  int iVar3;
  undefined4 uVar4;
  uint *puVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  byte bStack_80;
  undefined1 auStack_7f [4];
  undefined1 auStack_7b [4];
  undefined1 uStack_77;
  undefined1 auStack_76 [2];
  undefined4 uStack_74;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  uint uStack_48;
  uint uStack_44;
  undefined4 uStack_40;
  int iStack_3c;
  int iStack_38;
  uint uStack_34;
  uint uStack_30;
  undefined4 uStack_2c;
  uint uStack_28;
  undefined4 uStack_24;
  
  if (param_3 == 0) {
    if (*(uint *)(param_1 + 0x1078) == param_2) {
      *(undefined4 *)(param_1 + 0x1078) = 0;
    }
  }
  else {
    *(uint *)(param_1 + 0x1078) = param_2;
  }
  if (*(int *)(param_1 + 0x34) == 0) {
    return;
  }
  if (1 < (byte)(*(char *)(param_1 + 0x38) - 2U)) {
    return;
  }
  if (*(int *)(param_1 + 0x106c) == 0) {
    return;
  }
  if ((*(uint *)(param_1 + *(int *)(param_1 + 0x1070) * 8 + 0x6c) & 0xffffff) != param_2) {
    return;
  }
  if (param_3 == 0) {
    *(int *)(param_1 + 0x1168) = *(int *)(param_1 + 0x1168) + 1;
    return;
  }
  FUN_0098a880();
  if (*(int *)(param_1 + 0x34) != 0) {
    FUN_00997590(auStack_76,0,0x4e);
    bStack_80 = *(byte *)(param_1 + 0x38);
    uVar6 = (uint)bStack_80;
    FUN_009975a8(auStack_7f,param_1 + 0x54,4);
    FUN_009975a8(auStack_7b,param_1 + 0x58,4);
    uStack_77 = *(undefined1 *)(param_1 + 0x5c);
    uStack_74 = *(undefined4 *)(param_1 + 0x1108);
    uStack_70 = *(undefined4 *)(param_1 + 0x110c);
    uStack_6c = *(undefined4 *)(param_1 + 0x1110);
    uStack_68 = *(undefined4 *)(param_1 + 0x1114);
    uStack_64 = *(undefined4 *)(param_1 + 0x1118);
    uStack_60 = *(undefined4 *)(param_1 + 0x111c);
    uStack_5c = *(undefined4 *)(param_1 + 0x1120);
    uStack_58 = *(undefined4 *)(param_1 + 0x1124);
    uStack_54 = *(undefined4 *)(param_1 + 0x1128);
    uStack_50 = *(undefined4 *)(param_1 + 0x112c);
    uStack_4c = *(undefined4 *)(param_1 + 0x1130);
    uStack_28 = (uint)(*(int *)(param_1 + 0x1074) == 0);
    uStack_24 = *(undefined4 *)(param_1 + 0x1104);
    if ((uVar6 - 2 < 2) && (iVar9 = *(int *)(param_1 + 0x106c), iVar9 != 0)) {
      iVar7 = *(int *)(param_1 + 0x1070);
      iVar8 = param_1 + (iVar7 + 0xd) * 8;
      iVar3 = param_1 + iVar7 * 8;
      uVar6 = *(uint *)(iVar8 + 4) & 0xffffff;
      uStack_48 = uVar6;
      uStack_40 = FUN_0098aa70(*(undefined4 *)(param_1 + 100),*(undefined4 *)(param_1 + 0x60),
                               *(undefined4 *)(iVar3 + 0x6c),*(undefined4 *)(iVar3 + 0x70));
      uStack_44 = *(byte *)(iVar8 + 7) & 1;
      bVar1 = false;
      uStack_34 = (uint)(uVar6 == *(uint *)(param_1 + 0x1078));
      uVar4 = 0;
      uStack_30 = (uint)(*(uint *)(param_1 + 0x107c) == uVar6);
      iStack_3c = iVar9 - iVar7;
      puVar5 = (uint *)(param_1 + 0x107c);
      puVar2 = puVar5 + *(int *)(param_1 + 0x1100);
      while (puVar2 != puVar5) {
        puVar5 = puVar5 + 1;
        if (*puVar5 == uVar6) {
          uVar4 = 1;
        }
        bVar1 = true;
      }
      if (bVar1) {
        uStack_2c = uVar4;
      }
      iStack_38 = iVar9;
      if (uVar6 != *(uint *)(param_1 + 0x1078)) {
        (**(code **)(param_1 + 0x14))(*(undefined4 *)(param_1 + 0x24),uVar6);
      }
    }
    *(int *)(param_1 + 0x1164) = *(int *)(param_1 + 0x1164) + 1;
    (**(code **)(param_1 + 0x10))(*(undefined4 *)(param_1 + 0x24),&bStack_80);
  }
  return;
}


// ===== FUN_0098be60 @ 0098be60

void FUN_0098be60(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  FUN_0098a880();
  iVar1 = FUN_0098a868(param_1);
  if ((*(int *)(param_1 + 0x44) != 0) && (*(int *)(param_1 + 0x34) != 0)) {
    *(undefined4 *)(param_1 + 0x44) = 0;
    *(undefined4 *)(param_1 + 0x1078) = 0;
    FUN_0098ab48(param_1);
  }
  if ((*(int *)(param_1 + 0x3c) != 0) && (0x5dc < (uint)(iVar1 - *(int *)(param_1 + 0x3c)))) {
    *(undefined1 *)(param_1 + 0x39) = 0;
    *(undefined4 *)(param_1 + 0x3c) = 0;
    *(int *)(param_1 + 0x1144) = *(int *)(param_1 + 0x1144) + 1;
  }
  if ((*(int *)(param_1 + 0x40) != 0) && (0x5dc < (uint)(iVar1 - *(int *)(param_1 + 0x40)))) {
    *(undefined4 *)(param_1 + 0x40) = 0;
  }
  if (*(int *)(param_1 + 0x4c) != 0) {
    if ((*(int *)(param_1 + 0x34) == 0) && ((uint)(iVar1 - *(int *)(param_1 + 0x4c)) < 0x3a99)) {
      if (*(int *)(param_1 + 0x30) != 0) {
        return;
      }
      if (*(int *)(param_1 + 0x3c) != 0) {
        return;
      }
      if ((*(int *)(param_1 + 0x50) == 0) ||
         (iVar3 = FUN_0098a868(param_1), 1999 < (uint)(iVar3 - *(int *)(param_1 + 0x50)))) {
        *(undefined4 *)(param_1 + 0x4c) = 0;
        iVar3 = *(int *)(param_1 + 0x106c);
        if (iVar3 != 0) {
          iVar3 = iVar3 + -1;
        }
        *(int *)(param_1 + 0x1070) = iVar3;
        FUN_0098ace4(param_1,2);
      }
    }
    else {
      *(undefined4 *)(param_1 + 0x4c) = 0;
    }
  }
  if (*(int *)(param_1 + 0x34) == 0) {
    return;
  }
  if (*(char *)(param_1 + 0x38) != '\x02') {
    return;
  }
  if (*(int *)(param_1 + 0x48) == 0) {
    return;
  }
  if (iVar1 - *(int *)(param_1 + 0x48) < 0) {
    return;
  }
  *(int *)(param_1 + 0x1150) = *(int *)(param_1 + 0x1150) + 1;
  if (*(int *)(param_1 + 0x40) == 0) {
    uVar2 = FUN_0098a868(param_1);
    *(undefined4 *)(param_1 + 0x40) = uVar2;
    *(undefined4 *)(param_1 + 0x48) = 0;
                    /* WARNING: Could not recover jumptable at 0x0098bf98. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(param_1 + 8))(*(undefined4 *)(param_1 + 0x24),6);
    return;
  }
  return;
}


// ===== FUN_0098c00c @ 0098c00c

void FUN_0098c00c(int *param_1,int param_2)

{
  short sVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  short sVar5;
  byte bVar6;
  byte bVar7;
  byte bVar8;
  ushort uVar9;
  ushort uVar10;
  ushort uVar11;
  short sVar12;
  longlong lVar13;
  longlong lVar14;
  int iVar15;
  uint uVar16;
  int *piVar17;
  uint uVar18;
  undefined4 *puVar19;
  ushort uVar20;
  int iVar21;
  ushort *puVar22;
  uint uVar23;
  byte *pbVar24;
  ushort uVar25;
  int iVar26;
  uint uVar27;
  uint uVar28;
  undefined4 uVar29;
  int iVar30;
  uint uVar31;
  byte bVar32;
  uint uVar33;
  undefined4 uVar34;
  undefined4 uVar35;
  undefined4 uVar36;
  byte bVar37;
  uint uVar38;
  undefined4 uVar39;
  undefined4 uVar40;
  undefined4 uVar41;
  byte bVar42;
  uint uVar43;
  uint uVar44;
  undefined4 uVar45;
  undefined4 uVar46;
  undefined4 uVar47;
  undefined4 *puVar48;
  uint *puVar49;
  undefined4 *puVar50;
  ushort uVar51;
  uint *puVar52;
  uint uVar53;
  uint uVar54;
  undefined4 uVar55;
  undefined4 uVar56;
  undefined4 uVar57;
  ushort uVar58;
  uint uVar59;
  uint uVar60;
  ushort uVar61;
  int iVar62;
  int local_48;
  uint local_44;
  uint local_40;
  uint local_3c;
  
  if (param_2 != 0) {
    local_48 = param_2;
    do {
      iVar15 = param_1[0x1c];
      iVar21 = *param_1;
      iVar26 = param_1[1];
      iVar30 = param_1[0x1d];
      uVar58 = *(ushort *)(iVar15 + 4);
      uVar51 = *(ushort *)(iVar15 + 6);
      uVar61 = *(ushort *)(iVar21 + 4);
      uVar20 = *(ushort *)(iVar21 + 6);
      uVar25 = *(ushort *)(iVar26 + 4);
      uVar9 = *(ushort *)(iVar26 + 6);
      uVar10 = *(ushort *)(iVar30 + 4);
      uVar11 = *(ushort *)(iVar30 + 6);
      param_1[0x1c] = iVar15 + 4;
      *param_1 = iVar21 + 4;
      param_1[1] = iVar26 + 4;
      param_1[0x1d] = iVar30 + 4;
      uVar16 = param_1[3];
      iVar15 = param_1[4];
      uVar27 = param_1[6];
      iVar21 = uVar58 - uVar16;
      if (uVar58 < uVar16 || iVar21 == 0) {
        iVar21 = 0;
      }
      iVar26 = uVar20 - uVar16;
      if (uVar20 < uVar16 || iVar26 == 0) {
        iVar26 = 0;
      }
      uVar43 = iVar15 * iVar21 + 0x800U >> 0xc;
      uVar18 = iVar15 * iVar26 + 0x800U >> 0xc;
      if (uVar27 < uVar43) {
        uVar43 = uVar27;
      }
      if (uVar27 < uVar18) {
        uVar18 = uVar27;
      }
      iVar21 = uVar25 - uVar16;
      if (uVar25 < uVar16 || iVar21 == 0) {
        iVar21 = 0;
      }
      iVar26 = uVar11 - uVar16;
      if (uVar11 < uVar16 || iVar26 == 0) {
        iVar26 = 0;
      }
      uVar33 = iVar15 * iVar21 + 0x800U >> 0xc;
      uVar31 = iVar15 * iVar26 + 0x800U >> 0xc;
      if (uVar27 < uVar33) {
        uVar33 = uVar27;
      }
      if (uVar27 < uVar31) {
        uVar31 = uVar27;
      }
      uVar27 = param_1[5];
      iVar21 = uVar51 - uVar16;
      if (uVar51 < uVar16 || iVar21 == 0) {
        iVar21 = 0;
      }
      iVar26 = uVar9 - uVar16;
      if (uVar9 < uVar16 || iVar26 == 0) {
        iVar26 = 0;
      }
      uVar23 = iVar15 * iVar21 + 0x800U >> 0xc;
      uVar28 = iVar15 * iVar26 + 0x800U >> 0xc;
      if (uVar27 < uVar23) {
        uVar23 = uVar27;
      }
      if (uVar27 < uVar28) {
        uVar28 = uVar27;
      }
      uVar27 = param_1[7];
      iVar21 = uVar61 - uVar16;
      if (uVar61 < uVar16 || iVar21 == 0) {
        iVar21 = 0;
      }
      iVar26 = uVar10 - uVar16;
      if (uVar10 < uVar16 || iVar26 == 0) {
        iVar26 = 0;
      }
      uVar16 = iVar15 * iVar21 + 0x800U >> 0xc;
      uVar38 = iVar15 * iVar26 + 0x800U >> 0xc;
      if (uVar27 < uVar16) {
        uVar16 = uVar27;
      }
      if (uVar27 < uVar38) {
        uVar38 = uVar27;
      }
      iVar15 = uVar28 * 3 + uVar23;
      iVar21 = param_1[0x1e];
      param_1[0x1e] = iVar15 * 3;
      iVar26 = uVar16 * 3 + uVar38;
      iVar30 = param_1[0x20];
      param_1[0x20] = iVar26;
      iVar62 = param_1[0x1f];
      param_1[0x1f] = (uVar33 + uVar31) * 3 + uVar43 + uVar18 * 9;
      uVar16 = iVar15 + iVar21 + 8U >> 4;
      uVar27 = (uVar43 + uVar18) * 3 + uVar33 * 9 + uVar31 + iVar62 + 0x10 >> 5;
      uVar43 = iVar26 * 3 + iVar30 + 8U >> 4;
      if (param_1[0x1b] == 0) {
        lVar13 = (longlong)(int)uVar43 * (longlong)param_1[10] +
                 (longlong)(int)uVar27 * (longlong)param_1[9] +
                 (longlong)param_1[8] * (longlong)(int)uVar16 + 0x800;
        lVar14 = (longlong)(int)uVar43 * (longlong)param_1[0xd] +
                 (longlong)(int)uVar27 * (longlong)param_1[0xc] +
                 (longlong)param_1[0xb] * (longlong)(int)uVar16 + 0x800;
        local_44 = (uint)lVar13 >> 0xc | (int)((ulonglong)lVar13 >> 0x20) * 0x100000;
        local_40 = (uint)lVar14 >> 0xc | (int)((ulonglong)lVar14 >> 0x20) * 0x100000;
        lVar13 = (longlong)(int)uVar43 * (longlong)param_1[0x10] +
                 (longlong)(int)uVar27 * (longlong)param_1[0xf] +
                 (longlong)param_1[0xe] * (longlong)(int)uVar16 + 0x800;
        local_3c = (uint)lVar13 >> 0xc | (int)((ulonglong)lVar13 >> 0x20) * 0x100000;
      }
      else {
        local_44 = (int)(param_1[10] * uVar43 + param_1[9] * uVar27 + param_1[8] * uVar16 + 0x800)
                   >> 0xc;
        local_40 = (int)(param_1[0xd] * uVar43 + param_1[0xc] * uVar27 + param_1[0xb] * uVar16 +
                        0x800) >> 0xc;
        local_3c = (int)(param_1[0x10] * uVar43 + param_1[0xf] * uVar27 + param_1[0xe] * uVar16 +
                        0x800) >> 0xc;
      }
      piVar17 = (int *)param_1[0x24];
      if (piVar17 != (int *)0x0) {
        local_44 = local_44 + *piVar17;
        local_40 = local_40 + piVar17[1];
        local_3c = local_3c + piVar17[2];
        param_1[0x24] = (int)(piVar17 + 3);
      }
      if ((int)local_44 < (int)local_40) {
        uVar16 = local_40;
      }
      else {
        uVar16 = local_44;
      }
      if ((int)uVar16 < (int)local_3c) {
        uVar16 = local_3c;
      }
      uVar27 = local_44;
      uVar43 = local_40;
      uVar18 = local_3c;
      if (0 < (int)uVar16) {
        if ((int)uVar16 < 0x80000) {
          if (((int)local_44 <= (int)(uVar16 - 0x80000)) ||
             ((int)(uVar16 * 0xd0a) < (int)((uVar16 - local_44) * 0x1000))) {
            uVar27 = FUN_00994c68(param_1[0x11],0,local_44,uVar16);
          }
          if (((int)local_40 <= (int)(uVar16 - 0x80000)) ||
             ((int)(uVar16 * 0xcd9) < (int)((uVar16 - local_40) * 0x1000))) {
            uVar43 = FUN_00994c68(param_1[0x11],1,local_40,uVar16);
          }
          if (((int)local_3c <= (int)(uVar16 - 0x80000)) ||
             ((int)(uVar16 * 0xe14) < (int)((uVar16 - local_3c) * 0x1000))) {
            uVar18 = FUN_00994c68(param_1[0x11],2,local_3c,uVar16);
          }
        }
        else {
          uVar27 = FUN_00994c68(param_1[0x11],0,local_44,uVar16);
          uVar43 = FUN_00994c68(param_1[0x11],1,local_40,uVar16);
          uVar18 = FUN_00994c68(param_1[0x11],2,local_3c,uVar16);
        }
      }
      iVar15 = param_1[0x12];
      puVar22 = (ushort *)param_1[0x13];
      iVar21 = param_1[0x15];
      if ((int)uVar27 < -0x2000) {
        uVar33 = (uint)*puVar22;
      }
      else if ((int)uVar27 < 0x2000) {
        uVar33 = (uint)*(ushort *)(iVar15 + (uVar27 + 0x2000) * 2);
      }
      else if ((int)uVar27 < 0x80000) {
        uVar33 = (uint)puVar22[(int)uVar27 >> 4];
        uVar33 = uVar33 + ((int)((uVar27 & 0xf) * ((puVar22 + ((int)uVar27 >> 4))[1] - uVar33) + 8)
                          >> 4);
      }
      else {
        uVar33 = (uint)puVar22[0x8000];
      }
      if ((int)uVar43 < -0x2000) {
        uVar27 = (uint)*puVar22;
      }
      else if ((int)uVar43 < 0x2000) {
        uVar27 = (uint)*(ushort *)(iVar15 + (uVar43 + 0x2000) * 2);
      }
      else if ((int)uVar43 < 0x80000) {
        uVar27 = (uint)puVar22[(int)uVar43 >> 4];
        uVar27 = uVar27 + ((int)((uVar43 & 0xf) * ((puVar22 + ((int)uVar43 >> 4))[1] - uVar27) + 8)
                          >> 4);
      }
      else {
        uVar27 = (uint)puVar22[0x8000];
      }
      if ((int)uVar18 < -0x2000) {
        uVar43 = (uint)*puVar22;
      }
      else if ((int)uVar18 < 0x2000) {
        uVar43 = (uint)*(ushort *)(iVar15 + (uVar18 + 0x2000) * 2);
      }
      else if ((int)uVar18 < 0x80000) {
        uVar43 = (uint)puVar22[(int)uVar18 >> 4];
        uVar43 = uVar43 + ((int)((uVar18 & 0xf) * ((puVar22 + ((int)uVar18 >> 4))[1] - uVar43) + 8)
                          >> 4);
      }
      else {
        uVar43 = (uint)puVar22[0x8000];
      }
      uVar31 = iVar21 - 1;
      uVar18 = uVar33 >> 9;
      uVar33 = uVar33 & 0xffff01ff;
      if (uVar31 <= uVar18) {
        uVar18 = iVar21 - 2;
        uVar33 = 0x200;
      }
      uVar23 = uVar27 >> 9;
      uVar27 = uVar27 & 0xffff01ff;
      if (uVar31 <= uVar23) {
        uVar23 = iVar21 - 2;
        uVar27 = 0x200;
      }
      uVar28 = uVar43 >> 9;
      uVar43 = uVar43 & 0xffff01ff;
      if (uVar31 <= uVar28) {
        uVar28 = iVar21 - 2;
        uVar43 = 0x200;
      }
      iVar15 = uVar23 * iVar21 + uVar18;
      piVar17 = (int *)(param_1[0x14] + uVar28 * 4);
      puVar49 = (uint *)(*piVar17 + iVar15 * 4);
      puVar52 = (uint *)(piVar17[1] + iVar15 * 4);
      uVar18 = uVar33;
      if ((int)uVar27 < (int)uVar33) {
        uVar31 = uVar33;
        if ((int)uVar43 < (int)uVar27) {
          uVar23 = puVar49[1];
          uVar28 = puVar49[iVar21 + 1];
          uVar18 = uVar27;
        }
        else if ((int)uVar43 < (int)uVar33) {
          uVar23 = puVar49[1];
          uVar28 = puVar52[1];
          uVar18 = uVar43;
          uVar43 = uVar27;
        }
        else {
          uVar23 = *puVar52;
          uVar28 = puVar52[1];
          uVar31 = uVar43;
          uVar43 = uVar27;
        }
      }
      else if ((int)uVar27 < (int)uVar43) {
        uVar23 = *puVar52;
        uVar28 = puVar52[iVar21];
        uVar31 = uVar43;
        uVar18 = uVar27;
        uVar43 = uVar33;
      }
      else {
        uVar31 = uVar27;
        if ((int)uVar33 < (int)uVar43) {
          uVar23 = puVar49[iVar21];
          uVar28 = puVar52[iVar21];
          uVar18 = uVar43;
          uVar43 = uVar33;
        }
        else {
          uVar23 = puVar49[iVar21];
          uVar28 = puVar49[iVar21 + 1];
        }
      }
      uVar33 = *puVar49;
      uVar38 = puVar52[iVar21 + 1];
      uVar27 = (uVar33 & 0x7ff) << 5 | (uVar33 & 0x7ff) >> 6;
      uVar53 = (uVar23 & 0x7ff) << 5 | (uVar23 & 0x7ff) >> 6;
      uVar59 = (uVar28 & 0x7ff) << 5 | (uVar28 & 0x7ff) >> 6;
      uVar44 = (uVar33 >> 0xb & 0x7ff) << 5 | (uVar33 >> 0xb & 0x7ff) >> 6;
      uVar54 = (uVar23 >> 0xb & 0x7ff) << 5 | (uVar23 >> 0xb & 0x7ff) >> 6;
      uVar60 = (uVar28 >> 0xb & 0x7ff) << 5 | (uVar28 >> 0xb & 0x7ff) >> 6;
      uVar27 = (int)(uVar43 * (((uVar38 & 0x7ff) << 5 | (uVar38 & 0x7ff) >> 6) - uVar59) +
                     uVar18 * (uVar59 - uVar53) + uVar31 * (uVar53 - uVar27) + uVar27 * 0x200 +
                    0x100) >> 9;
      if ((int)uVar27 < 0) {
        uVar27 = 0;
      }
      if (0xffff < (int)uVar27) {
        uVar27 = 0xffff;
      }
      uVar53 = (uVar33 >> 0x16) << 6 | uVar33 >> 0x1a;
      uVar23 = (uVar23 >> 0x16) << 6 | uVar23 >> 0x1a;
      uVar28 = (uVar28 >> 0x16) << 6 | uVar28 >> 0x1a;
      uVar33 = (int)(uVar43 * (((uVar38 >> 0xb & 0x7ff) << 5 | (uVar38 >> 0xb & 0x7ff) >> 6) -
                              uVar60) +
                     uVar18 * (uVar60 - uVar54) + uVar31 * (uVar54 - uVar44) + uVar44 * 0x200 +
                    0x100) >> 9;
      if ((int)uVar33 < 0) {
        uVar33 = 0;
      }
      if (0xffff < (int)uVar33) {
        uVar33 = 0xffff;
      }
      iVar15 = param_1[0x17];
      uVar43 = (int)(uVar43 * (((uVar38 >> 0x16) << 6 | uVar38 >> 0x1a) - uVar28) +
                     uVar18 * (uVar28 - uVar23) + uVar31 * (uVar23 - uVar53) + uVar53 * 0x200 +
                    0x100) >> 9;
      if ((int)uVar43 < 0) {
        uVar43 = 0;
      }
      if (0xffff < (int)uVar43) {
        uVar43 = 0xffff;
      }
      if (iVar15 != 0) {
        iVar21 = iVar15 + -0x1800;
        if (uVar27 < 0x400) {
          uVar18 = uVar27 >> 1;
        }
        else {
          uVar18 = (uVar27 >> 7) + 0x1f8;
        }
        if (uVar33 < 0x400) {
          uVar31 = uVar33 >> 1;
        }
        else {
          uVar31 = (uVar33 >> 7) + 0x1f8;
        }
        if (uVar43 < 0x400) {
          uVar23 = uVar43 >> 1;
        }
        else {
          uVar23 = (uVar43 >> 7) + 0x1f8;
        }
        uVar58 = *(ushort *)(iVar21 + uVar18 * 2);
        uVar51 = *(ushort *)(iVar21 + uVar31 * 2 + 0x800);
        uVar61 = *(ushort *)(iVar21 + uVar23 * 2 + 0x1000);
        uVar20 = uVar58 & 0x7ff;
        uVar25 = uVar51 & 0x7ff;
        uVar18 = (uint)(uVar61 >> 0xb);
        uVar61 = uVar61 & 0x7ff;
        puVar19 = (undefined4 *)
                  (iVar15 + (((uint)(uVar51 >> 0xb) + uVar18 * 0x10 + uVar18) * 0x11 +
                            (uint)(uVar58 >> 0xb)) * 0xc);
        puVar48 = puVar19 + 0x363;
        uVar58 = uVar20;
        if (uVar25 < uVar20) {
          uVar51 = uVar20;
          if (uVar61 < uVar25) {
            puVar48 = puVar19 + 3;
            puVar50 = puVar19 + 0x36;
            uVar58 = uVar25;
          }
          else if (uVar61 < uVar20) {
            puVar48 = puVar19 + 3;
            puVar50 = puVar19 + 0x366;
            uVar58 = uVar61;
            uVar61 = uVar25;
          }
          else {
            puVar50 = puVar19 + 0x366;
            uVar51 = uVar61;
            uVar61 = uVar25;
          }
        }
        else if (uVar25 < uVar61) {
          puVar50 = puVar19 + 0x396;
          uVar51 = uVar61;
          uVar58 = uVar25;
          uVar61 = uVar20;
        }
        else {
          uVar51 = uVar25;
          if (uVar20 < uVar61) {
            puVar48 = puVar19 + 0x33;
            puVar50 = puVar19 + 0x396;
            uVar58 = uVar61;
            uVar61 = uVar20;
          }
          else {
            puVar48 = puVar19 + 0x33;
            puVar50 = puVar19 + 0x36;
          }
        }
        sVar1 = 0x800 - uVar51;
        sVar2 = uVar51 - uVar58;
        sVar3 = uVar58 - uVar61;
        uVar34 = *puVar19;
        uVar39 = *puVar48;
        uVar45 = *puVar50;
        uVar55 = puVar19[0x399];
        uVar35 = puVar19[1];
        uVar40 = puVar48[1];
        uVar46 = puVar50[1];
        uVar56 = puVar19[0x39a];
        uVar36 = puVar19[2];
        uVar41 = puVar48[2];
        uVar47 = puVar50[2];
        uVar57 = puVar19[0x39b];
        uVar29 = *(undefined4 *)param_1[0x19];
        param_1[0x19] = (int)((undefined4 *)param_1[0x19] + 1);
        sVar4 = (short)uVar29;
        iVar15 = (int)(short)((int)(short)((uint)uVar55 >> 0x10) * (int)(short)uVar61 +
                              (int)(short)((uint)uVar45 >> 0x10) * (int)sVar3 +
                              (int)(short)((uint)uVar39 >> 0x10) * (int)sVar2 +
                              (int)(short)((uint)uVar34 >> 0x10) * (int)sVar1 >> 0xb) * (int)sVar4;
        iVar21 = (int)(short)((int)(short)((uint)uVar56 >> 0x10) * (int)(short)uVar61 +
                              (int)(short)((uint)uVar46 >> 0x10) * (int)sVar3 +
                              (int)(short)((uint)uVar40 >> 0x10) * (int)sVar2 +
                              (int)(short)((uint)uVar35 >> 0x10) * (int)sVar1 >> 0xb) * (int)sVar4;
        if (param_1[0x18] == 0) {
          sVar5 = (short)((uint)uVar29 >> 0x10);
          iVar15 = (int)(short)((int)(short)uVar56 * (int)(short)uVar61 +
                                (int)(short)uVar46 * (int)sVar3 +
                                (int)(short)uVar40 * (int)sVar2 + (int)(short)uVar35 * (int)sVar1 >>
                               0xb) * (int)sVar5 + iVar15;
          sVar12 = *(short *)param_1[0x1a];
          param_1[0x1a] = (int)((short *)param_1[0x1a] + 1);
          iVar21 = (int)(short)((int)(short)((uint)uVar57 >> 0x10) * (int)(short)uVar61 +
                                (int)(short)((uint)uVar47 >> 0x10) * (int)sVar3 +
                                (int)(short)((uint)uVar41 >> 0x10) * (int)sVar2 +
                                (int)(short)((uint)uVar36 >> 0x10) * (int)sVar1 >> 0xb) *
                   (int)sVar12 +
                   (int)(short)((int)(short)uVar57 * (int)(short)uVar61 +
                                (int)(short)uVar47 * (int)sVar3 +
                                (int)(short)uVar41 * (int)sVar2 + (int)(short)uVar36 * (int)sVar1 >>
                               0xb) * (int)sVar5 + iVar21;
        }
        uVar27 = uVar27 + ((int)(short)((int)(short)uVar55 * (int)(short)uVar61 +
                                        (int)(short)uVar45 * (int)sVar3 +
                                        (int)(short)uVar39 * (int)sVar2 +
                                        (int)(short)uVar34 * (int)sVar1 >> 0xb) * (int)sVar4 >> 7);
        if ((int)uVar27 < 0) {
          uVar27 = 0;
        }
        if (0xffff < (int)uVar27) {
          uVar27 = 0xffff;
        }
        uVar33 = uVar33 + (iVar15 >> 7);
        if ((int)uVar33 < 0) {
          uVar33 = 0;
        }
        if (0xffff < (int)uVar33) {
          uVar33 = 0xffff;
        }
        uVar43 = uVar43 + (iVar21 >> 7);
        if ((int)uVar43 < 0) {
          uVar43 = 0;
        }
        if (0xffff < (int)uVar43) {
          uVar43 = 0xffff;
        }
      }
      pbVar24 = (byte *)param_1[2];
      if (0x80000 < (int)uVar16) {
        if ((0x80000 < (int)local_44) && (uVar27 = uVar27 + (local_44 - 0x80000), 0xffff < uVar27))
        {
          uVar27 = 0xffff;
        }
        if ((0x80000 < (int)local_40) && (uVar33 = uVar33 + (local_40 - 0x80000), 0xffff < uVar33))
        {
          uVar33 = 0xffff;
        }
        if ((0x80000 < (int)local_3c) && (uVar43 = uVar43 + (local_3c - 0x80000), 0xffff < uVar43))
        {
          uVar43 = 0xffff;
        }
      }
      bVar32 = *(byte *)(param_1[0x16] + (uVar27 * 0xfff + 0x8000 >> 0x10));
      bVar37 = *(byte *)(param_1[0x21] + (uVar33 * 0xfff + 0x8000 >> 0x10));
      bVar42 = *(byte *)(param_1[0x22] + (uVar43 * 0xfff + 0x8000 >> 0x10));
      iVar15 = param_1[0x23];
      if (iVar15 != 0) {
        bVar6 = *(byte *)(iVar15 + (uint)bVar32);
        sVar1 = *(short *)param_1[0x19];
        bVar7 = *(byte *)(iVar15 + 0x100 + (uint)bVar37);
        bVar8 = *(byte *)(iVar15 + 0x200 + (uint)bVar42);
        param_1[0x19] = (int)((short *)param_1[0x19] + 2);
        iVar15 = (uint)bVar32 + ((int)(short)(ushort)bVar6 * (int)sVar1 + 0x400 >> 0xb);
        if (iVar15 < 0) {
          iVar15 = 0;
        }
        if (0xff < iVar15) {
          iVar15 = 0xff;
        }
        bVar32 = (byte)iVar15;
        iVar15 = (uint)bVar37 + ((int)(short)(ushort)bVar7 * (int)sVar1 + 0x400 >> 0xb);
        if (iVar15 < 0) {
          iVar15 = 0;
        }
        if (0xff < iVar15) {
          iVar15 = 0xff;
        }
        bVar37 = (byte)iVar15;
        iVar15 = (uint)bVar42 + ((int)(short)(ushort)bVar8 * (int)sVar1 + 0x400 >> 0xb);
        if (iVar15 < 0) {
          iVar15 = 0;
        }
        if (0xff < iVar15) {
          iVar15 = 0xff;
        }
        bVar42 = (byte)iVar15;
      }
      *pbVar24 = bVar32;
      pbVar24[1] = bVar37;
      pbVar24[2] = bVar42;
      local_48 = local_48 + -1;
      param_1[2] = (int)(pbVar24 + 3);
    } while (local_48 != 0);
  }
  return;
}


// ===== FUN_0098cb9c @ 0098cb9c

void FUN_0098cb9c(int *param_1,uint *param_2)

{
  short sVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  short sVar5;
  byte bVar6;
  byte bVar7;
  byte bVar8;
  ushort uVar9;
  ushort uVar10;
  ushort uVar11;
  short sVar12;
  longlong lVar13;
  longlong lVar14;
  int *piVar15;
  uint uVar16;
  undefined4 *puVar17;
  ushort uVar18;
  ushort *puVar19;
  uint uVar20;
  byte *pbVar21;
  ushort uVar22;
  int iVar23;
  uint uVar24;
  undefined4 uVar25;
  int iVar26;
  uint uVar27;
  byte bVar28;
  uint uVar29;
  undefined4 uVar30;
  undefined4 uVar31;
  undefined4 uVar32;
  uint uVar33;
  byte bVar34;
  uint uVar35;
  undefined4 uVar36;
  undefined4 uVar37;
  undefined4 uVar38;
  uint uVar39;
  byte bVar40;
  uint uVar41;
  undefined4 uVar42;
  undefined4 uVar43;
  undefined4 uVar44;
  uint uVar45;
  undefined4 *puVar46;
  uint *puVar47;
  undefined4 *puVar48;
  ushort uVar49;
  uint *puVar50;
  uint uVar51;
  uint uVar52;
  undefined4 uVar53;
  undefined4 uVar54;
  undefined4 uVar55;
  ushort uVar56;
  int iVar57;
  uint uVar58;
  uint uVar59;
  ushort uVar60;
  int iVar61;
  int iVar62;
  int local_48;
  uint uStack_44;
  uint uStack_40;
  uint uStack_3c;
  
  uVar33 = *param_2;
  uVar39 = param_2[1];
  uVar45 = param_2[2];
  local_48 = 1;
  iVar62 = param_1[0x1b];
  while( true ) {
    if (iVar62 == 0) {
      lVar13 = (longlong)(int)uVar45 * (longlong)param_1[10] +
               (longlong)(int)uVar39 * (longlong)param_1[9] +
               (longlong)param_1[8] * (longlong)(int)uVar33 + 0x800;
      lVar14 = (longlong)(int)uVar45 * (longlong)param_1[0xd] +
               (longlong)(int)uVar39 * (longlong)param_1[0xc] +
               (longlong)param_1[0xb] * (longlong)(int)uVar33 + 0x800;
      uStack_44 = (uint)lVar13 >> 0xc | (int)((ulonglong)lVar13 >> 0x20) * 0x100000;
      uStack_40 = (uint)lVar14 >> 0xc | (int)((ulonglong)lVar14 >> 0x20) * 0x100000;
      lVar13 = (longlong)(int)uVar45 * (longlong)param_1[0x10] +
               (longlong)(int)uVar39 * (longlong)param_1[0xf] +
               (longlong)param_1[0xe] * (longlong)(int)uVar33 + 0x800;
      uStack_3c = (uint)lVar13 >> 0xc | (int)((ulonglong)lVar13 >> 0x20) * 0x100000;
    }
    else {
      uStack_44 = (int)(param_1[10] * uVar45 + param_1[9] * uVar39 + param_1[8] * uVar33 + 0x800) >>
                  0xc;
      uStack_40 = (int)(param_1[0xd] * uVar45 + param_1[0xc] * uVar39 + param_1[0xb] * uVar33 +
                       0x800) >> 0xc;
      uStack_3c = (int)(param_1[0x10] * uVar45 + param_1[0xf] * uVar39 + param_1[0xe] * uVar33 +
                       0x800) >> 0xc;
    }
    piVar15 = (int *)param_1[0x24];
    if (piVar15 != (int *)0x0) {
      uStack_44 = uStack_44 + *piVar15;
      uStack_40 = uStack_40 + piVar15[1];
      uStack_3c = uStack_3c + piVar15[2];
      param_1[0x24] = (int)(piVar15 + 3);
    }
    if ((int)uStack_44 < (int)uStack_40) {
      uVar33 = uStack_40;
    }
    else {
      uVar33 = uStack_44;
    }
    if ((int)uVar33 < (int)uStack_3c) {
      uVar33 = uStack_3c;
    }
    uVar39 = uStack_44;
    uVar45 = uStack_40;
    uVar16 = uStack_3c;
    if (0 < (int)uVar33) {
      if ((int)uVar33 < 0x80000) {
        if (((int)uStack_44 <= (int)(uVar33 - 0x80000)) ||
           ((int)(uVar33 * 0xd0a) < (int)((uVar33 - uStack_44) * 0x1000))) {
          uVar39 = FUN_00994c68(param_1[0x11],0,uStack_44,uVar33);
        }
        if (((int)uStack_40 <= (int)(uVar33 - 0x80000)) ||
           ((int)(uVar33 * 0xcd9) < (int)((uVar33 - uStack_40) * 0x1000))) {
          uVar45 = FUN_00994c68(param_1[0x11],1,uStack_40,uVar33);
        }
        if (((int)uStack_3c <= (int)(uVar33 - 0x80000)) ||
           ((int)(uVar33 * 0xe14) < (int)((uVar33 - uStack_3c) * 0x1000))) {
          uVar16 = FUN_00994c68(param_1[0x11],2,uStack_3c,uVar33);
        }
      }
      else {
        uVar39 = FUN_00994c68(param_1[0x11],0,uStack_44,uVar33);
        uVar45 = FUN_00994c68(param_1[0x11],1,uStack_40,uVar33);
        uVar16 = FUN_00994c68(param_1[0x11],2,uStack_3c,uVar33);
      }
    }
    iVar62 = param_1[0x12];
    puVar19 = (ushort *)param_1[0x13];
    iVar57 = param_1[0x15];
    if ((int)uVar39 < -0x2000) {
      uVar29 = (uint)*puVar19;
    }
    else if ((int)uVar39 < 0x2000) {
      uVar29 = (uint)*(ushort *)(iVar62 + (uVar39 + 0x2000) * 2);
    }
    else if ((int)uVar39 < 0x80000) {
      uVar29 = (uint)puVar19[(int)uVar39 >> 4];
      uVar29 = uVar29 + ((int)((uVar39 & 0xf) * ((puVar19 + ((int)uVar39 >> 4))[1] - uVar29) + 8) >>
                        4);
    }
    else {
      uVar29 = (uint)puVar19[0x8000];
    }
    if ((int)uVar45 < -0x2000) {
      uVar39 = (uint)*puVar19;
    }
    else if ((int)uVar45 < 0x2000) {
      uVar39 = (uint)*(ushort *)(iVar62 + (uVar45 + 0x2000) * 2);
    }
    else if ((int)uVar45 < 0x80000) {
      uVar39 = (uint)puVar19[(int)uVar45 >> 4];
      uVar39 = uVar39 + ((int)((uVar45 & 0xf) * ((puVar19 + ((int)uVar45 >> 4))[1] - uVar39) + 8) >>
                        4);
    }
    else {
      uVar39 = (uint)puVar19[0x8000];
    }
    if ((int)uVar16 < -0x2000) {
      uVar45 = (uint)*puVar19;
    }
    else if ((int)uVar16 < 0x2000) {
      uVar45 = (uint)*(ushort *)(iVar62 + (uVar16 + 0x2000) * 2);
    }
    else if ((int)uVar16 < 0x80000) {
      uVar45 = (uint)puVar19[(int)uVar16 >> 4];
      uVar45 = uVar45 + ((int)((uVar16 & 0xf) * ((puVar19 + ((int)uVar16 >> 4))[1] - uVar45) + 8) >>
                        4);
    }
    else {
      uVar45 = (uint)puVar19[0x8000];
    }
    uVar27 = iVar57 - 1;
    uVar16 = uVar29 >> 9;
    uVar29 = uVar29 & 0xffff01ff;
    if (uVar27 <= uVar16) {
      uVar16 = iVar57 - 2;
      uVar29 = 0x200;
    }
    uVar20 = uVar39 >> 9;
    uVar39 = uVar39 & 0xffff01ff;
    if (uVar27 <= uVar20) {
      uVar20 = iVar57 - 2;
      uVar39 = 0x200;
    }
    uVar24 = uVar45 >> 9;
    uVar45 = uVar45 & 0xffff01ff;
    if (uVar27 <= uVar24) {
      uVar24 = iVar57 - 2;
      uVar45 = 0x200;
    }
    iVar62 = uVar20 * iVar57 + uVar16;
    piVar15 = (int *)(param_1[0x14] + uVar24 * 4);
    puVar47 = (uint *)(*piVar15 + iVar62 * 4);
    puVar50 = (uint *)(piVar15[1] + iVar62 * 4);
    uVar16 = uVar29;
    if ((int)uVar39 < (int)uVar29) {
      uVar27 = uVar29;
      if ((int)uVar45 < (int)uVar39) {
        uVar20 = puVar47[1];
        uVar24 = puVar47[iVar57 + 1];
        uVar16 = uVar39;
      }
      else if ((int)uVar45 < (int)uVar29) {
        uVar20 = puVar47[1];
        uVar24 = puVar50[1];
        uVar16 = uVar45;
        uVar45 = uVar39;
      }
      else {
        uVar20 = *puVar50;
        uVar24 = puVar50[1];
        uVar27 = uVar45;
        uVar45 = uVar39;
      }
    }
    else if ((int)uVar39 < (int)uVar45) {
      uVar20 = *puVar50;
      uVar24 = puVar50[iVar57];
      uVar27 = uVar45;
      uVar16 = uVar39;
      uVar45 = uVar29;
    }
    else {
      uVar27 = uVar39;
      if ((int)uVar29 < (int)uVar45) {
        uVar20 = puVar47[iVar57];
        uVar24 = puVar50[iVar57];
        uVar16 = uVar45;
        uVar45 = uVar29;
      }
      else {
        uVar20 = puVar47[iVar57];
        uVar24 = puVar47[iVar57 + 1];
      }
    }
    uVar29 = *puVar47;
    uVar35 = puVar50[iVar57 + 1];
    uVar39 = (uVar29 & 0x7ff) << 5 | (uVar29 & 0x7ff) >> 6;
    uVar51 = (uVar20 & 0x7ff) << 5 | (uVar20 & 0x7ff) >> 6;
    uVar58 = (uVar24 & 0x7ff) << 5 | (uVar24 & 0x7ff) >> 6;
    uVar41 = (uVar29 >> 0xb & 0x7ff) << 5 | (uVar29 >> 0xb & 0x7ff) >> 6;
    uVar52 = (uVar20 >> 0xb & 0x7ff) << 5 | (uVar20 >> 0xb & 0x7ff) >> 6;
    uVar59 = (uVar24 >> 0xb & 0x7ff) << 5 | (uVar24 >> 0xb & 0x7ff) >> 6;
    uVar39 = (int)(uVar45 * (((uVar35 & 0x7ff) << 5 | (uVar35 & 0x7ff) >> 6) - uVar58) +
                   uVar16 * (uVar58 - uVar51) + uVar27 * (uVar51 - uVar39) + uVar39 * 0x200 + 0x100)
             >> 9;
    if ((int)uVar39 < 0) {
      uVar39 = 0;
    }
    if (0xffff < (int)uVar39) {
      uVar39 = 0xffff;
    }
    uVar51 = (uVar29 >> 0x16) << 6 | uVar29 >> 0x1a;
    uVar20 = (uVar20 >> 0x16) << 6 | uVar20 >> 0x1a;
    uVar24 = (uVar24 >> 0x16) << 6 | uVar24 >> 0x1a;
    uVar29 = (int)(uVar45 * (((uVar35 >> 0xb & 0x7ff) << 5 | (uVar35 >> 0xb & 0x7ff) >> 6) - uVar59)
                   + uVar16 * (uVar59 - uVar52) + uVar27 * (uVar52 - uVar41) + uVar41 * 0x200 +
                  0x100) >> 9;
    if ((int)uVar29 < 0) {
      uVar29 = 0;
    }
    if (0xffff < (int)uVar29) {
      uVar29 = 0xffff;
    }
    iVar62 = param_1[0x17];
    uVar45 = (int)(uVar45 * (((uVar35 >> 0x16) << 6 | uVar35 >> 0x1a) - uVar24) +
                   uVar16 * (uVar24 - uVar20) + uVar27 * (uVar20 - uVar51) + uVar51 * 0x200 + 0x100)
             >> 9;
    if ((int)uVar45 < 0) {
      uVar45 = 0;
    }
    if (0xffff < (int)uVar45) {
      uVar45 = 0xffff;
    }
    if (iVar62 != 0) {
      iVar57 = iVar62 + -0x1800;
      if (uVar39 < 0x400) {
        uVar16 = uVar39 >> 1;
      }
      else {
        uVar16 = (uVar39 >> 7) + 0x1f8;
      }
      if (uVar29 < 0x400) {
        uVar27 = uVar29 >> 1;
      }
      else {
        uVar27 = (uVar29 >> 7) + 0x1f8;
      }
      if (uVar45 < 0x400) {
        uVar20 = uVar45 >> 1;
      }
      else {
        uVar20 = (uVar45 >> 7) + 0x1f8;
      }
      uVar56 = *(ushort *)(iVar57 + uVar16 * 2);
      uVar49 = *(ushort *)(iVar57 + uVar27 * 2 + 0x800);
      uVar60 = *(ushort *)(iVar57 + uVar20 * 2 + 0x1000);
      uVar18 = uVar56 & 0x7ff;
      uVar22 = uVar49 & 0x7ff;
      uVar16 = (uint)(uVar60 >> 0xb);
      uVar60 = uVar60 & 0x7ff;
      puVar17 = (undefined4 *)
                (iVar62 + (((uint)(uVar49 >> 0xb) + uVar16 * 0x10 + uVar16) * 0x11 +
                          (uint)(uVar56 >> 0xb)) * 0xc);
      puVar46 = puVar17 + 0x363;
      uVar56 = uVar18;
      if (uVar22 < uVar18) {
        uVar49 = uVar18;
        if (uVar60 < uVar22) {
          puVar46 = puVar17 + 3;
          puVar48 = puVar17 + 0x36;
          uVar56 = uVar22;
        }
        else if (uVar60 < uVar18) {
          puVar46 = puVar17 + 3;
          puVar48 = puVar17 + 0x366;
          uVar56 = uVar60;
          uVar60 = uVar22;
        }
        else {
          puVar48 = puVar17 + 0x366;
          uVar49 = uVar60;
          uVar60 = uVar22;
        }
      }
      else if (uVar22 < uVar60) {
        puVar48 = puVar17 + 0x396;
        uVar49 = uVar60;
        uVar56 = uVar22;
        uVar60 = uVar18;
      }
      else {
        uVar49 = uVar22;
        if (uVar18 < uVar60) {
          puVar46 = puVar17 + 0x33;
          puVar48 = puVar17 + 0x396;
          uVar56 = uVar60;
          uVar60 = uVar18;
        }
        else {
          puVar46 = puVar17 + 0x33;
          puVar48 = puVar17 + 0x36;
        }
      }
      sVar1 = 0x800 - uVar49;
      sVar2 = uVar49 - uVar56;
      sVar3 = uVar56 - uVar60;
      uVar30 = *puVar17;
      uVar36 = *puVar46;
      uVar42 = *puVar48;
      uVar53 = puVar17[0x399];
      uVar31 = puVar17[1];
      uVar37 = puVar46[1];
      uVar43 = puVar48[1];
      uVar54 = puVar17[0x39a];
      uVar32 = puVar17[2];
      uVar38 = puVar46[2];
      uVar44 = puVar48[2];
      uVar55 = puVar17[0x39b];
      uVar25 = *(undefined4 *)param_1[0x19];
      param_1[0x19] = (int)((undefined4 *)param_1[0x19] + 1);
      sVar4 = (short)uVar25;
      iVar62 = (int)(short)((int)(short)((uint)uVar53 >> 0x10) * (int)(short)uVar60 +
                            (int)(short)((uint)uVar42 >> 0x10) * (int)sVar3 +
                            (int)(short)((uint)uVar36 >> 0x10) * (int)sVar2 +
                            (int)(short)((uint)uVar30 >> 0x10) * (int)sVar1 >> 0xb) * (int)sVar4;
      iVar57 = (int)(short)((int)(short)((uint)uVar54 >> 0x10) * (int)(short)uVar60 +
                            (int)(short)((uint)uVar43 >> 0x10) * (int)sVar3 +
                            (int)(short)((uint)uVar37 >> 0x10) * (int)sVar2 +
                            (int)(short)((uint)uVar31 >> 0x10) * (int)sVar1 >> 0xb) * (int)sVar4;
      if (param_1[0x18] == 0) {
        sVar5 = (short)((uint)uVar25 >> 0x10);
        iVar62 = (int)(short)((int)(short)uVar54 * (int)(short)uVar60 +
                              (int)(short)uVar43 * (int)sVar3 +
                              (int)(short)uVar37 * (int)sVar2 + (int)(short)uVar31 * (int)sVar1 >>
                             0xb) * (int)sVar5 + iVar62;
        sVar12 = *(short *)param_1[0x1a];
        param_1[0x1a] = (int)((short *)param_1[0x1a] + 1);
        iVar57 = (int)(short)((int)(short)((uint)uVar55 >> 0x10) * (int)(short)uVar60 +
                              (int)(short)((uint)uVar44 >> 0x10) * (int)sVar3 +
                              (int)(short)((uint)uVar38 >> 0x10) * (int)sVar2 +
                              (int)(short)((uint)uVar32 >> 0x10) * (int)sVar1 >> 0xb) * (int)sVar12
                 + (int)(short)((int)(short)uVar55 * (int)(short)uVar60 +
                                (int)(short)uVar44 * (int)sVar3 +
                                (int)(short)uVar38 * (int)sVar2 + (int)(short)uVar32 * (int)sVar1 >>
                               0xb) * (int)sVar5 + iVar57;
      }
      uVar39 = uVar39 + ((int)(short)((int)(short)uVar53 * (int)(short)uVar60 +
                                      (int)(short)uVar42 * (int)sVar3 +
                                      (int)(short)uVar36 * (int)sVar2 +
                                      (int)(short)uVar30 * (int)sVar1 >> 0xb) * (int)sVar4 >> 7);
      if ((int)uVar39 < 0) {
        uVar39 = 0;
      }
      if (0xffff < (int)uVar39) {
        uVar39 = 0xffff;
      }
      uVar29 = uVar29 + (iVar62 >> 7);
      if ((int)uVar29 < 0) {
        uVar29 = 0;
      }
      if (0xffff < (int)uVar29) {
        uVar29 = 0xffff;
      }
      uVar45 = uVar45 + (iVar57 >> 7);
      if ((int)uVar45 < 0) {
        uVar45 = 0;
      }
      if (0xffff < (int)uVar45) {
        uVar45 = 0xffff;
      }
    }
    pbVar21 = (byte *)param_1[2];
    if (0x80000 < (int)uVar33) {
      if ((0x80000 < (int)uStack_44) && (uVar39 = uVar39 + (uStack_44 - 0x80000), 0xffff < uVar39))
      {
        uVar39 = 0xffff;
      }
      if ((0x80000 < (int)uStack_40) && (uVar29 = uVar29 + (uStack_40 - 0x80000), 0xffff < uVar29))
      {
        uVar29 = 0xffff;
      }
      if ((0x80000 < (int)uStack_3c) && (uVar45 = uVar45 + (uStack_3c - 0x80000), 0xffff < uVar45))
      {
        uVar45 = 0xffff;
      }
    }
    bVar28 = *(byte *)(param_1[0x16] + (uVar39 * 0xfff + 0x8000 >> 0x10));
    bVar34 = *(byte *)(param_1[0x21] + (uVar29 * 0xfff + 0x8000 >> 0x10));
    bVar40 = *(byte *)(param_1[0x22] + (uVar45 * 0xfff + 0x8000 >> 0x10));
    iVar62 = param_1[0x23];
    if (iVar62 != 0) {
      bVar6 = *(byte *)(iVar62 + (uint)bVar28);
      sVar1 = *(short *)param_1[0x19];
      bVar7 = *(byte *)(iVar62 + 0x100 + (uint)bVar34);
      bVar8 = *(byte *)(iVar62 + 0x200 + (uint)bVar40);
      param_1[0x19] = (int)((short *)param_1[0x19] + 2);
      iVar62 = (uint)bVar28 + ((int)(short)(ushort)bVar6 * (int)sVar1 + 0x400 >> 0xb);
      if (iVar62 < 0) {
        iVar62 = 0;
      }
      if (0xff < iVar62) {
        iVar62 = 0xff;
      }
      bVar28 = (byte)iVar62;
      iVar62 = (uint)bVar34 + ((int)(short)(ushort)bVar7 * (int)sVar1 + 0x400 >> 0xb);
      if (iVar62 < 0) {
        iVar62 = 0;
      }
      if (0xff < iVar62) {
        iVar62 = 0xff;
      }
      bVar34 = (byte)iVar62;
      iVar62 = (uint)bVar40 + ((int)(short)(ushort)bVar8 * (int)sVar1 + 0x400 >> 0xb);
      if (iVar62 < 0) {
        iVar62 = 0;
      }
      if (0xff < iVar62) {
        iVar62 = 0xff;
      }
      bVar40 = (byte)iVar62;
    }
    *pbVar21 = bVar28;
    pbVar21[1] = bVar34;
    pbVar21[2] = bVar40;
    local_48 = local_48 + -1;
    param_1[2] = (int)(pbVar21 + 3);
    if (local_48 == 0) break;
    iVar62 = param_1[0x1c];
    iVar57 = *param_1;
    iVar23 = param_1[1];
    iVar26 = param_1[0x1d];
    uVar56 = *(ushort *)(iVar62 + 4);
    uVar49 = *(ushort *)(iVar62 + 6);
    uVar60 = *(ushort *)(iVar57 + 4);
    uVar18 = *(ushort *)(iVar57 + 6);
    uVar22 = *(ushort *)(iVar23 + 4);
    uVar9 = *(ushort *)(iVar23 + 6);
    uVar10 = *(ushort *)(iVar26 + 4);
    uVar11 = *(ushort *)(iVar26 + 6);
    param_1[0x1c] = iVar62 + 4;
    *param_1 = iVar57 + 4;
    param_1[1] = iVar23 + 4;
    param_1[0x1d] = iVar26 + 4;
    uVar33 = param_1[3];
    iVar62 = param_1[4];
    uVar39 = param_1[6];
    iVar57 = uVar56 - uVar33;
    if (uVar56 < uVar33 || iVar57 == 0) {
      iVar57 = 0;
    }
    iVar23 = uVar18 - uVar33;
    if (uVar18 < uVar33 || iVar23 == 0) {
      iVar23 = 0;
    }
    uVar45 = iVar62 * iVar57 + 0x800U >> 0xc;
    uVar16 = iVar62 * iVar23 + 0x800U >> 0xc;
    if (uVar39 < uVar45) {
      uVar45 = uVar39;
    }
    if (uVar39 < uVar16) {
      uVar16 = uVar39;
    }
    iVar57 = uVar22 - uVar33;
    if (uVar22 < uVar33 || iVar57 == 0) {
      iVar57 = 0;
    }
    iVar23 = uVar11 - uVar33;
    if (uVar11 < uVar33 || iVar23 == 0) {
      iVar23 = 0;
    }
    uVar29 = iVar62 * iVar57 + 0x800U >> 0xc;
    uVar27 = iVar62 * iVar23 + 0x800U >> 0xc;
    if (uVar39 < uVar29) {
      uVar29 = uVar39;
    }
    if (uVar39 < uVar27) {
      uVar27 = uVar39;
    }
    uVar39 = param_1[5];
    iVar57 = uVar49 - uVar33;
    if (uVar49 < uVar33 || iVar57 == 0) {
      iVar57 = 0;
    }
    iVar23 = uVar9 - uVar33;
    if (uVar9 < uVar33 || iVar23 == 0) {
      iVar23 = 0;
    }
    uVar20 = iVar62 * iVar57 + 0x800U >> 0xc;
    uVar24 = iVar62 * iVar23 + 0x800U >> 0xc;
    if (uVar39 < uVar20) {
      uVar20 = uVar39;
    }
    if (uVar39 < uVar24) {
      uVar24 = uVar39;
    }
    uVar39 = param_1[7];
    iVar57 = uVar60 - uVar33;
    if (uVar60 < uVar33 || iVar57 == 0) {
      iVar57 = 0;
    }
    iVar23 = uVar10 - uVar33;
    if (uVar10 < uVar33 || iVar23 == 0) {
      iVar23 = 0;
    }
    uVar33 = iVar62 * iVar57 + 0x800U >> 0xc;
    uVar35 = iVar62 * iVar23 + 0x800U >> 0xc;
    if (uVar39 < uVar33) {
      uVar33 = uVar39;
    }
    if (uVar39 < uVar35) {
      uVar35 = uVar39;
    }
    iVar62 = uVar24 * 3 + uVar20;
    iVar57 = param_1[0x1e];
    param_1[0x1e] = iVar62 * 3;
    iVar23 = uVar33 * 3 + uVar35;
    iVar26 = param_1[0x20];
    param_1[0x20] = iVar23;
    iVar61 = param_1[0x1f];
    param_1[0x1f] = (uVar29 + uVar27) * 3 + uVar45 + uVar16 * 9;
    uVar33 = iVar62 + iVar57 + 8U >> 4;
    uVar39 = (uVar45 + uVar16) * 3 + uVar29 * 9 + uVar27 + iVar61 + 0x10 >> 5;
    uVar45 = iVar23 * 3 + iVar26 + 8U >> 4;
    iVar62 = param_1[0x1b];
  }
  return;
}


// ===== FUN_0098cbbc @ 0098cbbc

undefined4 FUN_0098cbbc(uint *param_1)

{
  byte *pbVar1;
  byte bVar2;
  ushort uVar3;
  uint uVar4;
  undefined4 uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  byte *pbVar11;
  byte *pbVar12;
  uint uVar13;
  byte *pbVar14;
  undefined2 *puVar15;
  undefined2 *puVar16;
  uint uVar17;
  uint uVar18;
  uint uVar19;
  uint uVar20;
  uint uVar21;
  
  uVar9 = *param_1;
  uVar10 = param_1[1];
  pbVar11 = (byte *)param_1[2];
  uVar13 = param_1[3];
  uVar17 = param_1[5];
  uVar18 = param_1[6];
  uVar19 = param_1[7];
  uVar6 = param_1[8];
  uVar7 = param_1[9];
  uVar8 = param_1[10];
  pbVar14 = (byte *)(uVar13 - 1);
  puVar15 = (undefined2 *)(param_1[4] - 2);
  if (param_1[0xb] != 0) goto LAB_0098cc54;
  do {
    pbVar12 = pbVar11;
    if ((undefined2 *)(uVar17 - 2) <= puVar15) {
      uVar19 = uVar19 & uVar8;
      puVar16 = puVar15 + 1;
      *puVar15 = (short)uVar19;
      uVar5 = 0;
      uVar6 = 0;
LAB_0098cee8:
      *param_1 = uVar9;
      param_1[1] = uVar10;
      param_1[2] = (uint)pbVar12;
      param_1[3] = uVar13;
      param_1[4] = (uint)puVar16;
      param_1[5] = uVar17;
      param_1[6] = uVar18;
      param_1[7] = uVar19;
      param_1[0xb] = uVar6;
      return uVar5;
    }
    if ((int)uVar10 < 10) {
      if (pbVar11 < pbVar14) {
        bVar2 = *pbVar11;
        pbVar1 = pbVar11 + 1;
        uVar4 = 0x10 - uVar10;
        if (bVar2 != 0xff && *pbVar1 != 0xff) {
          pbVar11 = pbVar11 + 2;
          uVar10 = uVar10 + 0x10;
          uVar9 = uVar9 | (uint)CONCAT11(bVar2,*pbVar1) << (uVar4 & 0xff);
          goto LAB_0098cc28;
        }
      }
      do {
        if (pbVar14 < pbVar12) {
LAB_0098cea8:
          uVar19 = uVar19 & uVar8;
          puVar16 = puVar15 + 1;
          *puVar15 = (short)uVar19;
          uVar5 = 1;
          uVar6 = 0;
          goto LAB_0098cee8;
        }
        pbVar11 = pbVar12 + 1;
        uVar4 = 0x18 - uVar10;
        if (*pbVar12 == 0xff) {
          if (*pbVar11 != 0) goto LAB_0098cea8;
          pbVar11 = pbVar12 + 2;
        }
        uVar10 = uVar10 + 8;
        uVar9 = uVar9 | (uint)*pbVar12 << (uVar4 & 0xff);
        pbVar12 = pbVar11;
      } while ((int)uVar10 < 0x19);
    }
LAB_0098cc28:
    uVar4 = (uint)*(short *)(uVar6 + (uVar9 >> 0x16) * 2);
    uVar19 = uVar19 & uVar8;
    puVar16 = puVar15 + 1;
    *puVar15 = (short)uVar19;
    pbVar12 = pbVar11;
    puVar15 = puVar16;
    if (uVar4 == 0) {
      for (; (int)uVar10 < 0x19; uVar10 = uVar10 + 8) {
        if (pbVar14 < pbVar12) goto LAB_0098cebc;
        pbVar11 = pbVar12 + 1;
        if (*pbVar12 == 0xff) {
          if (*pbVar11 != 0) goto LAB_0098cebc;
          pbVar11 = pbVar12 + 2;
        }
        uVar9 = uVar9 | (uint)*pbVar12 << (0x18 - uVar10 & 0xff);
        pbVar12 = pbVar11;
      }
      uVar3 = *(ushort *)((uVar6 - 0x400) + (uVar9 >> 0x17) * 2);
      uVar20 = uVar3 & 0xff;
      uVar4 = (uint)(uVar3 >> 8);
      if ((uVar4 == 0) || (0xe < uVar20 - 1)) {
LAB_0098cebc:
        uVar5 = 2;
        uVar6 = 0;
        goto LAB_0098cee8;
      }
      uVar21 = (uVar9 << uVar4) >> (0x20 - uVar20 & 0xff);
      uVar9 = (uVar9 << uVar4) << uVar20;
      uVar10 = (uVar10 - uVar4) - uVar20;
      if ((int)uVar21 < (int)((uint)(1 << uVar20) >> 1)) {
        uVar21 = (uVar21 - (1 << uVar20)) + 1;
      }
      uVar18 = uVar18 + uVar21;
      pbVar11 = pbVar12;
    }
    else {
      uVar9 = uVar9 << (uVar4 & 0xf);
      uVar10 = uVar10 - (uVar4 & 0xf);
      uVar18 = uVar18 + ((int)uVar4 >> 4);
    }
LAB_0098cc54:
    if ((int)uVar10 < 10) {
      pbVar12 = pbVar11;
      if (pbVar11 < pbVar14) {
        bVar2 = *pbVar11;
        pbVar1 = pbVar11 + 1;
        uVar4 = 0x10 - uVar10;
        if (bVar2 != 0xff && *pbVar1 != 0xff) {
          pbVar11 = pbVar11 + 2;
          uVar10 = uVar10 + 0x10;
          uVar9 = uVar9 | (uint)CONCAT11(bVar2,*pbVar1) << (uVar4 & 0xff);
          goto LAB_0098cc8c;
        }
      }
      do {
        if (pbVar14 < pbVar12) {
LAB_0098cecc:
          uVar18 = uVar18 & uVar8;
          puVar16 = puVar15 + 1;
          *puVar15 = (short)uVar18;
          uVar5 = 1;
          uVar6 = 1;
          goto LAB_0098cee8;
        }
        pbVar11 = pbVar12 + 1;
        uVar4 = 0x18 - uVar10;
        if (*pbVar12 == 0xff) {
          if (*pbVar11 != 0) goto LAB_0098cecc;
          pbVar11 = pbVar12 + 2;
        }
        uVar10 = uVar10 + 8;
        uVar9 = uVar9 | (uint)*pbVar12 << (uVar4 & 0xff);
        pbVar12 = pbVar11;
      } while ((int)uVar10 < 0x19);
    }
LAB_0098cc8c:
    uVar4 = (uint)*(short *)(uVar7 + (uVar9 >> 0x16) * 2);
    uVar18 = uVar18 & uVar8;
    puVar16 = puVar15 + 1;
    *puVar15 = (short)uVar18;
    pbVar12 = pbVar11;
    if (uVar4 == 0) {
      for (; (int)uVar10 < 0x19; uVar10 = uVar10 + 8) {
        if (pbVar14 < pbVar12) goto LAB_0098cee0;
        pbVar11 = pbVar12 + 1;
        if (*pbVar12 == 0xff) {
          if (*pbVar11 != 0) goto LAB_0098cee0;
          pbVar11 = pbVar12 + 2;
        }
        uVar9 = uVar9 | (uint)*pbVar12 << (0x18 - uVar10 & 0xff);
        pbVar12 = pbVar11;
      }
      uVar3 = *(ushort *)((uVar7 - 0x400) + (uVar9 >> 0x17) * 2);
      uVar21 = uVar3 & 0xff;
      uVar20 = (uint)(uVar3 >> 8);
      if ((uVar20 == 0) || (0xe < uVar21 - 1)) {
LAB_0098cee0:
        uVar5 = 2;
        uVar6 = 1;
        goto LAB_0098cee8;
      }
      uVar4 = (uVar9 << uVar20) >> (0x20 - uVar21 & 0xff);
      uVar9 = (uVar9 << uVar20) << uVar21;
      uVar10 = (uVar10 - uVar20) - uVar21;
      if ((int)uVar4 < (int)((uint)(1 << uVar21) >> 1)) {
        uVar4 = (uVar4 - (1 << uVar21)) + 1;
      }
    }
    else {
      uVar9 = uVar9 << (uVar4 & 0xf);
      uVar10 = uVar10 - (uVar4 & 0xf);
      uVar4 = (int)uVar4 >> 4;
    }
    uVar19 = uVar19 + uVar4;
    pbVar11 = pbVar12;
    puVar15 = puVar16;
  } while( true );
}


// ===== FUN_0098cf04 @ 0098cf04

void FUN_0098cf04(undefined4 *param_1)

{
  ushort uVar1;
  ushort *puVar2;
  ushort *puVar3;
  ushort *puVar4;
  ushort *puVar5;
  int *piVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  ushort *puVar11;
  int iVar12;
  int iVar13;
  uint uVar14;
  uint uVar15;
  
  puVar3 = (ushort *)*param_1;
  puVar5 = (ushort *)param_1[1];
  piVar6 = (int *)param_1[3];
  iVar7 = param_1[4];
  uVar8 = param_1[5];
  uVar9 = param_1[6];
  iVar10 = param_1[7];
  puVar2 = (ushort *)param_1[2];
  while (puVar3 < puVar5) {
    iVar12 = 0;
    iVar13 = 0;
    puVar11 = (ushort *)(iVar10 + (uint)*puVar2 * 2);
    if (puVar5 < puVar11) {
      puVar11 = puVar5;
    }
    while (puVar3 < puVar11) {
      puVar4 = puVar3 + 1;
      uVar1 = *puVar3;
      puVar3 = puVar3 + 2;
      uVar14 = *(uint *)(iVar7 + (uint)uVar1 * 4);
      uVar15 = *(uint *)(iVar7 + (uint)*puVar4 * 4);
      if (uVar8 < uVar14) {
        uVar14 = uVar8;
      }
      iVar12 = iVar12 + uVar14;
      if (uVar9 < uVar15) {
        uVar15 = uVar9;
      }
      iVar13 = iVar13 + uVar15;
    }
    *piVar6 = *piVar6 + iVar12;
    piVar6[1] = piVar6[1] + iVar13;
    piVar6 = piVar6 + 2;
    puVar2 = puVar2 + 1;
  }
  *param_1 = puVar3;
  return;
}


// ===== FUN_0098cf8c @ 0098cf8c

void FUN_0098cf8c(byte *param_1,uint *param_2,int param_3)

{
  byte *pbVar1;
  byte *pbVar2;
  byte *pbVar3;
  byte bVar4;
  byte bVar5;
  byte bVar6;
  uint *puVar7;
  uint *puVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  
  if (param_3 == 0) {
    return;
  }
  puVar7 = param_2;
  do {
    bVar4 = *param_1;
    bVar5 = param_1[1];
    pbVar1 = param_1 + 2;
    pbVar2 = param_1 + 3;
    bVar6 = param_1[4];
    pbVar3 = param_1 + 5;
    param_1 = param_1 + 6;
    iVar9 = (uint)bVar4 + (uint)*pbVar2;
    iVar10 = (uint)*pbVar1 + (uint)*pbVar3;
    uVar12 = (short)((ushort)bVar5 + (ushort)bVar6) * -0x54cd + (short)iVar9 * -0x2b33 +
             iVar10 * 0x8000 + 0x10000 >> 0x11;
    if (0x7f < (int)uVar12) {
      uVar12 = 0x7f;
    }
    uVar11 = (short)iVar10 * -0x14d1 + (short)((ushort)bVar5 + (ushort)bVar6) * -0x6b2f +
             iVar9 * 0x8000 + 0x10000 >> 0x11;
    if (0x7f < (int)uVar11) {
      uVar11 = 0x7f;
    }
    puVar8 = puVar7 + 1;
    *puVar7 = uVar12 & 0xff |
              ((short)(ushort)bVar5 * 0x1646 +
               (short)(ushort)*pbVar1 * 0x1d2f + (short)(ushort)bVar4 * 0x4c8b +
               (uint)bVar5 * 0x8000 + 0x8000 >> 0x10) << 8 | (uVar11 & 0xff) << 0x10 |
              ((short)(ushort)bVar6 * 0x1646 +
               (short)(ushort)*pbVar3 * 0x1d2f + (short)(ushort)*pbVar2 * 0x4c8b +
               (uint)bVar6 * 0x8000 + 0x8000 >> 0x10) << 0x18;
    puVar7 = puVar8;
  } while (puVar8 < param_2 + param_3);
  return;
}


// ===== FUN_0098cf94 @ 0098cf94

void FUN_0098cf94(byte *param_1,uint *param_2,int param_3)

{
  byte *pbVar1;
  byte *pbVar2;
  byte *pbVar3;
  byte bVar4;
  byte bVar5;
  byte bVar6;
  uint *puVar7;
  uint *puVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  
  puVar7 = param_2;
  do {
    bVar4 = *param_1;
    bVar5 = param_1[1];
    pbVar1 = param_1 + 2;
    pbVar2 = param_1 + 3;
    bVar6 = param_1[4];
    pbVar3 = param_1 + 5;
    param_1 = param_1 + 6;
    iVar9 = (uint)bVar4 + (uint)*pbVar2;
    iVar10 = (uint)*pbVar1 + (uint)*pbVar3;
    uVar12 = (short)((ushort)bVar5 + (ushort)bVar6) * -0x54cd + (short)iVar9 * -0x2b33 +
             iVar10 * 0x8000 + 0x10000 >> 0x11;
    if (0x7f < (int)uVar12) {
      uVar12 = 0x7f;
    }
    uVar11 = (short)iVar10 * -0x14d1 + (short)((ushort)bVar5 + (ushort)bVar6) * -0x6b2f +
             iVar9 * 0x8000 + 0x10000 >> 0x11;
    if (0x7f < (int)uVar11) {
      uVar11 = 0x7f;
    }
    puVar8 = puVar7 + 1;
    *puVar7 = uVar12 & 0xff |
              ((short)(ushort)bVar5 * 0x1646 +
               (short)(ushort)*pbVar1 * 0x1d2f + (short)(ushort)bVar4 * 0x4c8b +
               (uint)bVar5 * 0x8000 + 0x8000 >> 0x10) << 8 | (uVar11 & 0xff) << 0x10 |
              ((short)(ushort)bVar6 * 0x1646 +
               (short)(ushort)*pbVar3 * 0x1d2f + (short)(ushort)*pbVar2 * 0x4c8b +
               (uint)bVar6 * 0x8000 + 0x8000 >> 0x10) << 0x18;
    puVar7 = puVar8;
  } while (puVar8 < param_2 + param_3);
  return;
}


// ===== FUN_0098d070 @ 0098d070

undefined4 FUN_0098d070(code *param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_c;
  
  iVar1 = (*param_1)(param_2,param_3,&local_c);
  if (iVar1 == 0) {
    *param_4 = local_c;
    uVar2 = 0;
  }
  else {
    uVar2 = 0xffffffff;
  }
  return uVar2;
}


// ===== FUN_0098d0b4 @ 0098d0b4

undefined4 FUN_0098d0b4(undefined4 *param_1,int param_2,uint param_3,uint *param_4)

{
  int iVar1;
  undefined4 uVar2;
  uint uStack_c;
  
  if (*(uint *)(param_2 + 8) <= param_3) {
    return 0xffffffff;
  }
  switch(*(undefined4 *)(param_2 + 4)) {
  case 3:
  case 8:
    iVar1 = (*(code *)*param_1)(param_1[1],*(int *)(param_2 + 0xc) + param_3 * 2,&uStack_c,2);
    if (iVar1 == 0) {
      *param_4 = uStack_c & 0xffff;
      return 0;
    }
    break;
  case 4:
  case 9:
    iVar1 = (*(code *)*param_1)(param_1[1],*(int *)(param_2 + 0xc) + param_3 * 4,&uStack_c);
    if (iVar1 == 0) {
      *param_4 = uStack_c;
      uVar2 = 0;
    }
    else {
      uVar2 = 0xffffffff;
    }
    return uVar2;
  }
  return 0xffffffff;
}


// ===== FUN_0098d0c0 @ 0098d0c0

undefined4 FUN_0098d0c0(undefined4 *param_1,int param_2,int param_3,uint *param_4)

{
  int iVar1;
  undefined4 uVar2;
  uint uStack_c;
  
  switch(*(undefined4 *)(param_2 + 4)) {
  case 3:
  case 8:
    iVar1 = (*(code *)*param_1)(param_1[1],*(int *)(param_2 + 0xc) + param_3 * 2,&uStack_c,2);
    if (iVar1 == 0) {
      *param_4 = uStack_c & 0xffff;
      return 0;
    }
    break;
  case 4:
  case 9:
    iVar1 = (*(code *)*param_1)(param_1[1],*(int *)(param_2 + 0xc) + param_3 * 4,&uStack_c);
    if (iVar1 == 0) {
      *param_4 = uStack_c;
      uVar2 = 0;
    }
    else {
      uVar2 = 0xffffffff;
    }
    return uVar2;
  }
  return 0xffffffff;
}


// ===== FUN_0098d150 @ 0098d150

undefined4 FUN_0098d150(undefined4 *param_1,int param_2,uint param_3,uint *param_4)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint local_28;
  uint local_24;
  
  iVar1 = (*(code *)*param_1)(param_1[1],param_2,&local_24,2);
  if ((iVar1 != 0) || (uVar4 = local_24 & 0xffff, 0x400 < uVar4)) {
    return 0xffffffff;
  }
  if (uVar4 != 0) {
    iVar1 = param_2 + 2;
    do {
      iVar2 = (*(code *)*param_1)(param_1[1],iVar1,&local_24,2);
      if (iVar2 != 0) {
        return 0xffffffff;
      }
      uVar5 = local_24 & 0xffff;
      iVar2 = (*(code *)*param_1)(param_1[1],iVar1 + 2,&local_24);
      if (iVar2 != 0) {
        return 0xffffffff;
      }
      uVar6 = local_24 & 0xffff;
      iVar2 = FUN_0098d070(*param_1,param_1[1],iVar1 + 4,&local_28);
      uVar3 = iVar1 + 8;
      if (iVar2 != 0) {
        return 0xffffffff;
      }
      iVar2 = FUN_0098d070(*param_1,param_1[1],uVar3,&local_24);
      iVar1 = iVar1 + 0xc;
      if (iVar2 != 0) {
        return 0xffffffff;
      }
      if (param_3 == uVar5) {
        *param_4 = param_3;
        param_4[1] = uVar6;
        uVar6 = uVar6 - 1;
        param_4[2] = local_28;
        if (0xb < uVar6) {
          param_4[3] = uVar3;
          return 1;
        }
        uVar4 = (uint)((ulonglong)local_28 * (ulonglong)*(uint *)(&DAT_009a8c38 + uVar6 * 4) >> 0x20
                      );
        if (uVar4 != 0 ||
            uVar4 < (4 < (uint)((ulonglong)local_28 *
                               (ulonglong)*(uint *)(&DAT_009a8c38 + uVar6 * 4)))) {
          uVar3 = local_24;
        }
        param_4[3] = uVar3;
        return 1;
      }
    } while (param_2 + uVar4 * 0xc + 2 != iVar1);
  }
  return 0;
}


// ===== FUN_0098d29c @ 0098d29c

undefined4
FUN_0098d29c(undefined4 *param_1,undefined4 param_2,int param_3,int param_4,int param_5,
            undefined4 *param_6,undefined4 *param_7,undefined4 param_8,undefined2 *param_9)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint unaff_r7;
  undefined2 *puVar5;
  uint uVar6;
  undefined4 unaff_r8;
  undefined4 uVar7;
  bool bVar8;
  undefined1 local_40 [4];
  undefined4 local_3c;
  undefined1 auStack_38 [8];
  uint local_30;
  undefined4 local_2c;
  
  if (param_3 != 0) {
    local_30 = 0;
    local_2c = 0;
    iVar2 = FUN_0098d150(param_1,param_2,0x110);
    unaff_r8 = local_2c;
    unaff_r7 = local_30;
    if (iVar2 == 1) {
      uVar4 = local_30;
      if (0x1e < local_30) {
        uVar4 = 0x1f;
      }
      iVar2 = (*(code *)*param_1)(param_1[1],local_2c,param_3);
      if (iVar2 != 0) {
        return 0xffffffff;
      }
      *(undefined1 *)(param_3 + uVar4) = 0;
    }
  }
  local_30 = unaff_r7;
  local_2c = unaff_r8;
  iVar2 = FUN_0098d150(param_1,param_2,0x8769,auStack_38);
  if (((iVar2 != 1) || (iVar2 = FUN_0098d0b4(param_1,auStack_38,0,&local_3c), iVar2 != 0)) ||
     (iVar2 = FUN_0098d150(param_1,local_3c,0x927c,auStack_38), uVar1 = local_2c, iVar2 != 1)) {
    return 0xfffffffe;
  }
  iVar2 = FUN_0098d150(param_1,local_2c,8,auStack_38);
  uVar7 = local_2c;
  uVar4 = local_30;
  if (iVar2 == 1) {
    FUN_0098d0b4(param_1,auStack_38,0,param_8);
  }
  if (param_9 != (undefined2 *)0x0) {
    *param_9 = 0xffff;
    iVar2 = FUN_0098d150(param_1,uVar1,4,auStack_38);
    uVar7 = local_2c;
    uVar4 = local_30;
    if (((iVar2 == 1) && (7 < local_30)) && (iVar2 = FUN_0098d0b4(param_1,auStack_38,7), iVar2 == 0)
       ) {
      *param_9 = local_40._0_2_;
    }
  }
  local_30 = uVar4;
  local_2c = uVar7;
  iVar2 = FUN_0098d150(param_1,uVar1,0xe0,auStack_38);
  uVar7 = local_2c;
  uVar4 = local_30;
  if ((iVar2 == 1) && (8 < local_30)) {
    iVar2 = 0;
    do {
      local_30 = uVar4;
      local_2c = uVar7;
      iVar3 = FUN_0098d0b4(param_1,auStack_38,iVar2,param_5);
      iVar2 = iVar2 + 1;
      if (iVar3 != 0) {
        return 0xffffffff;
      }
      param_5 = param_5 + 4;
    } while (iVar2 != 9);
  }
  local_30 = uVar4;
  local_2c = uVar7;
  iVar2 = FUN_0098d150(param_1,uVar1,0x4001,auStack_38);
  uVar7 = local_2c;
  uVar4 = local_30;
  if (iVar2 != 1) goto LAB_0098d46c;
  if (local_30 == 0x28d) {
    iVar2 = 0x22;
  }
  else if (local_30 < 0x28e) {
    if (local_30 != 0x246) goto LAB_0098d46c;
    iVar2 = 0x19;
  }
  else if (local_30 == 0x1400) {
    iVar2 = 0x47;
  }
  else {
    if (0x1400 < local_30) goto LAB_0098d46c;
    if (local_30 < 0x53b) {
      if (local_30 < 0x520) {
        if (local_30 == 0x4cb) goto LAB_0098d540;
        if (local_30 < 0x4cb) {
          if (0x2be < local_30) {
            bVar8 = local_30 == 0x31c;
            goto LAB_0098d658;
          }
          if (local_30 < 0x2a2) goto LAB_0098d46c;
          uVar6 = 0x10040001 >> (local_30 - 0x2a2 & 0xff);
        }
        else {
          if (0x19 < local_30 - 0x4e2) goto LAB_0098d46c;
          uVar6 = 0x2800003 >> (local_30 - 0x4e2 & 0xff);
        }
      }
      else {
        uVar6 = 0x6000013 >> (local_30 - 0x520 & 0xff);
      }
      if ((uVar6 & 1) == 0) goto LAB_0098d46c;
    }
    else if (local_30 != 0x618) {
      if (local_30 < 0x618) {
        if ((local_30 != 0x549) && (local_30 != 0x5e2)) {
          uVar6 = 0x542;
LAB_0098d654:
          bVar8 = local_30 == uVar6;
LAB_0098d658:
          if (!bVar8) goto LAB_0098d46c;
        }
      }
      else if (local_30 != 0x638) {
        uVar6 = 0x642;
        goto LAB_0098d654;
      }
    }
LAB_0098d540:
    iVar2 = 0x3f;
  }
  puVar5 = (undefined2 *)(param_4 + -2);
  do {
    local_30 = uVar4;
    local_2c = uVar7;
    iVar3 = FUN_0098d0b4(param_1,auStack_38,iVar2,local_40);
    if (iVar3 != 0) {
      return 0xffffffff;
    }
    iVar2 = iVar2 + 1;
    puVar5 = puVar5 + 1;
    *puVar5 = local_40._0_2_;
  } while ((undefined2 *)(param_4 + 6) != puVar5);
LAB_0098d46c:
  if (param_6 != (undefined4 *)0x0) {
    *param_6 = uVar1;
  }
  if (param_7 != (undefined4 *)0x0) {
    *param_7 = local_3c;
  }
  return 0;
}


// ===== FUN_0098d6dc @ 0098d6dc

undefined4 FUN_0098d6dc(int *param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  undefined1 *puVar11;
  int iVar12;
  undefined4 *puVar13;
  
  uVar10 = param_1[10];
  iVar7 = param_1[3];
  iVar9 = param_1[2];
  puVar4 = (undefined4 *)(uVar10 + iVar7);
  uVar6 = iVar9 - iVar7;
  uVar8 = uVar6;
  if (((uVar10 | (uint)puVar4) & 3) == 0) {
    if (0xf < uVar6) {
      iVar5 = (uVar6 & 0xfffffff0) - 0x10;
      puVar3 = puVar4 + 4;
      iVar2 = uVar10 + 0x10;
      do {
        iVar12 = iVar2 + 0x10;
        *(undefined4 *)(iVar2 + -0x10) = puVar3[-4];
        *(undefined4 *)(iVar2 + -0xc) = puVar3[-3];
        *(undefined4 *)(iVar2 + -8) = puVar3[-2];
        *(undefined4 *)(iVar2 + -4) = puVar3[-1];
        puVar3 = puVar3 + 4;
        iVar2 = iVar12;
      } while (iVar12 != uVar10 + 0x20 + iVar5);
      uVar10 = uVar10 + 0x10 + iVar5;
      puVar4 = (undefined4 *)((int)(puVar4 + 4) + iVar5);
      uVar8 = uVar6 & 0xf;
    }
    if (3 < uVar8) {
      iVar2 = (uVar8 & 0xfffffffc) - 4;
      puVar13 = (undefined4 *)(uVar10 - 4);
      puVar3 = puVar4;
      do {
        puVar13 = puVar13 + 1;
        *puVar13 = *puVar3;
        puVar3 = puVar3 + 1;
      } while (puVar13 != (undefined4 *)(uVar10 + iVar2));
      puVar4 = (undefined4 *)((int)puVar4 + (uVar8 & 0xfffffffc));
      uVar10 = uVar10 + 4 + iVar2;
      uVar8 = uVar8 & 3;
    }
  }
  if (uVar8 != 0) {
    puVar11 = (undefined1 *)(uVar10 - 1);
    puVar3 = puVar4;
    do {
      puVar13 = (undefined4 *)((int)puVar3 + 1);
      puVar11 = puVar11 + 1;
      *puVar11 = *(undefined1 *)puVar3;
      puVar3 = puVar13;
    } while (puVar13 != (undefined4 *)((int)puVar4 + uVar8));
  }
  uVar10 = param_1[1] - *param_1;
  uVar8 = (iVar7 + param_1[0xb]) - iVar9;
  if (uVar10 <= uVar8) {
    uVar8 = uVar10;
  }
  param_1[2] = uVar6;
  param_1[3] = 0;
  if (uVar8 == 0) {
    return 0;
  }
  iVar7 = (**(code **)(param_2 + 0x383c))
                    (*(undefined4 *)(param_2 + 0x3840),*param_1,param_1[10] + uVar6,uVar8);
  if (iVar7 == 0) {
    *param_1 = *param_1 + uVar8;
    param_1[2] = param_1[2] + uVar8;
    uVar1 = 0;
  }
  else {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}


// ===== FUN_0098d858 @ 0098d858

undefined4 FUN_0098d858(int param_1,int param_2,ushort *param_3)

{
  ushort uVar1;
  undefined1 uVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  ushort uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  short sVar15;
  int iVar16;
  uint uVar17;
  ushort *puVar18;
  uint uVar19;
  uint uVar20;
  int *piVar21;
  int iVar22;
  uint local_9c;
  ushort *local_98;
  ushort *local_94;
  int local_90;
  uint local_84;
  uint local_70;
  uint local_6c;
  int local_68 [4];
  uint local_58;
  int local_54;
  int local_50;
  int local_4c;
  ushort *local_48;
  ushort *local_44;
  uint local_40;
  uint local_3c;
  int local_38;
  int local_34;
  uint local_30;
  uint local_2c;
  
  uVar9 = ~(-1 << (*(uint *)(param_2 + 0xb0) & 0xff));
  uVar4 = 0;
  uVar19 = *(uint *)(param_2 + 0xc0);
  uVar20 = *(uint *)(param_2 + 0xbc);
  piVar21 = local_68;
  do {
    uVar13 = uVar4;
    if (uVar20 <= uVar4) {
      uVar13 = 0;
    }
    uVar4 = uVar4 + 1;
    *piVar21 = param_2 + (uint)*(byte *)(param_2 + uVar13 + 0xe8) * 0xdd4 + 0xec;
    piVar21 = piVar21 + 1;
  } while (uVar4 != 4);
  local_9c = (uint)*(byte *)(param_1 + 0x18);
  uVar4 = uVar19;
  if (uVar20 < uVar19) {
    uVar4 = uVar20;
  }
  iVar5 = *(int *)(param_1 + 0x28);
  uVar13 = *(uint *)(param_1 + 0x10);
  uVar11 = *(uint *)(param_1 + 0xc);
  uVar14 = *(uint *)(param_1 + 8);
  iVar10 = *(int *)(param_1 + 0x14);
  uVar1 = (ushort)uVar9;
  uVar12 = uVar11;
  if (uVar4 == 0) {
    if (uVar20 != 2) goto LAB_0098dedc;
    local_98 = (ushort *)local_68[0];
    local_90 = local_68[1];
    local_84 = 0;
LAB_0098e354:
    if (uVar19 < 4) {
      local_70 = 2;
      uVar12 = uVar11;
    }
    else {
      local_70 = uVar19 & 0xfffffffe;
      uVar4 = 0;
      local_6c = 2;
      local_94 = param_3;
      do {
        if (iVar10 < 0x19) {
          uVar20 = 0x18 - iVar10;
          if (local_9c == 0) {
            uVar12 = uVar11;
            if (uVar14 - uVar11 < 2) goto LAB_0098e948;
LAB_0098e914:
            if (*(byte *)(iVar5 + uVar11) != 0xff) {
              uVar13 = uVar13 | (uint)*(byte *)(iVar5 + uVar11) << (uVar20 & 0xff);
              uVar12 = uVar11 + 1;
              goto LAB_0098e928;
            }
            if (uVar11 < uVar14) {
              while ((uVar11 + 1 < uVar14 && (*(char *)(iVar5 + uVar11 + 1) == '\0'))) {
                uVar7 = 0xff;
                uVar12 = uVar11 + 2;
                do {
                  uVar13 = uVar13 | uVar7 << (uVar20 & 0xff);
LAB_0098e928:
                  iVar10 = 0x20 - uVar20;
                  uVar11 = uVar12;
                  if (0x18 < iVar10) goto LAB_0098e394;
                  uVar20 = uVar20 - 8;
                  iVar10 = 0x18 - uVar20;
                  if (1 < uVar14 - uVar12) goto LAB_0098e914;
LAB_0098e948:
                  *(uint *)(param_1 + 0xc) = uVar12;
                  *(uint *)(param_1 + 8) = uVar14;
                  iVar16 = FUN_0098d6dc(param_1,param_2);
                  if (iVar16 != 0) goto LAB_0098dd28;
                  uVar11 = *(uint *)(param_1 + 0xc);
                  uVar14 = *(uint *)(param_1 + 8);
                  if (uVar14 <= uVar11) goto LAB_0098e9a8;
                  uVar7 = (uint)*(byte *)(iVar5 + uVar11);
                  uVar12 = uVar11 + 1;
                } while (uVar7 != 0xff);
              }
            }
LAB_0098e9a8:
            iVar10 = 0x20 - uVar20;
            if (0x18 < iVar10) {
              local_9c = 1;
              goto LAB_0098e394;
            }
            local_9c = 1;
            uVar20 = uVar20 - 8;
          }
          do {
            iVar10 = 0x20 - uVar20;
            if (0x18 < iVar10) break;
            iVar10 = 0x20 - (uVar20 - 8);
            uVar20 = uVar20 - 0x10;
          } while (iVar10 < 0x19);
        }
LAB_0098e394:
        uVar20 = (uint)*(short *)((int)local_98 + ((uVar13 >> 0x16) + 0x200) * 2);
        if (uVar20 == 0) {
          uVar6 = *(ushort *)((int)local_98 + (uVar13 >> 0x17) * 2);
          uVar12 = uVar11;
          if (uVar6 == 0) {
            uVar20 = 10;
            piVar21 = (int *)((int)local_98 + 0xc24);
            while( true ) {
              piVar21 = piVar21 + 1;
              uVar7 = uVar13 >> (0x20 - uVar20 & 0xff);
              if ((int)uVar7 <= *piVar21) break;
              uVar20 = uVar20 + 1;
              if (uVar20 == 0x11) goto LAB_0098dbc0;
            }
            iVar16 = (int)local_98 + uVar20 * 4;
            uVar7 = (uint)*(byte *)((int)local_98 +
                                    ((uVar7 + *(int *)(iVar16 + 0xc48)) - *(int *)(iVar16 + 0xc8c))
                                   + 0xcd0);
          }
          else {
            uVar20 = (uint)(uVar6 >> 8);
            uVar7 = uVar6 & 0xff;
          }
          uVar13 = uVar13 << (uVar20 & 0xff);
          iVar10 = iVar10 - uVar20;
          if (uVar7 != 0) {
            if (uVar7 == 0x10) {
              local_84 = local_84 + 0x8000;
            }
            else {
              if (0x10 < uVar7) goto LAB_0098dbc0;
              if (iVar10 < (int)uVar7) {
                uVar20 = 0x18 - iVar10;
                if (local_9c == 0) {
                  if (uVar14 - uVar11 < 2) goto LAB_0098ee8c;
LAB_0098ee58:
                  if (*(byte *)(iVar5 + uVar12) != 0xff) {
                    uVar13 = uVar13 | (uint)*(byte *)(iVar5 + uVar12) << (uVar20 & 0xff);
                    uVar11 = uVar12 + 1;
                    goto LAB_0098ee6c;
                  }
                  if (uVar12 < uVar14) {
                    while ((uVar12 + 1 < uVar14 && (*(char *)(iVar5 + uVar12 + 1) == '\0'))) {
                      uVar17 = 0xff;
                      uVar11 = uVar12 + 2;
                      do {
                        uVar13 = uVar13 | uVar17 << (uVar20 & 0xff);
LAB_0098ee6c:
                        iVar10 = 0x20 - uVar20;
                        if (0x18 < iVar10) goto LAB_0098e6e8;
                        uVar20 = uVar20 - 8;
                        iVar10 = 0x18 - uVar20;
                        uVar12 = uVar11;
                        if (1 < uVar14 - uVar11) goto LAB_0098ee58;
LAB_0098ee8c:
                        *(uint *)(param_1 + 0xc) = uVar11;
                        *(uint *)(param_1 + 8) = uVar14;
                        iVar16 = FUN_0098d6dc(param_1,param_2);
                        if (iVar16 != 0) goto LAB_0098f57c;
                        uVar12 = *(uint *)(param_1 + 0xc);
                        uVar14 = *(uint *)(param_1 + 8);
                        if (uVar14 <= uVar12) goto LAB_0098eef8;
                        uVar17 = (uint)*(byte *)(iVar5 + uVar12);
                        uVar11 = uVar12 + 1;
                      } while (uVar17 != 0xff);
                    }
                  }
LAB_0098eef8:
                  iVar10 = 0x20 - uVar20;
                  uVar11 = uVar12;
                  if (0x18 < iVar10) {
                    local_9c = 1;
                    goto LAB_0098e6e8;
                  }
                  local_9c = 1;
                  uVar20 = uVar20 - 8;
                }
                do {
                  iVar10 = 0x20 - uVar20;
                  uVar20 = uVar20 - 8;
                } while (iVar10 < 0x19);
              }
LAB_0098e6e8:
              uVar20 = uVar13 >> (0x20 - uVar7 & 0xff);
              uVar12 = uVar7 - 1;
              iVar16 = 1 << (uVar12 & 0xff);
              if ((int)uVar20 < iVar16) {
                uVar12 = 0xffffffff;
              }
              iVar10 = iVar10 - uVar7;
              uVar13 = uVar13 << uVar7;
              if ((int)uVar20 < iVar16) {
                uVar20 = uVar20 + (uVar12 << uVar7) + 1;
              }
              local_84 = local_84 + uVar20;
            }
          }
        }
        else {
          local_84 = local_84 + ((int)uVar20 >> 4);
          uVar13 = uVar13 << (uVar20 & 0xf);
          iVar10 = iVar10 - (uVar20 & 0xf);
        }
        local_84 = local_84 & uVar9;
        local_94[2] = (ushort)local_84;
        if (iVar10 < 0x19) {
          uVar20 = 0x18 - iVar10;
          if (local_9c == 0) {
            uVar12 = uVar11;
            if (uVar14 - uVar11 < 2) goto LAB_0098eaac;
LAB_0098ea78:
            if (*(byte *)(iVar5 + uVar11) != 0xff) {
              uVar13 = uVar13 | (uint)*(byte *)(iVar5 + uVar11) << (uVar20 & 0xff);
              uVar12 = uVar11 + 1;
              goto LAB_0098ea8c;
            }
            if (uVar11 < uVar14) {
              while ((uVar11 + 1 < uVar14 && (*(char *)(iVar5 + uVar11 + 1) == '\0'))) {
                uVar7 = 0xff;
                uVar12 = uVar11 + 2;
                do {
                  uVar13 = uVar13 | uVar7 << (uVar20 & 0xff);
LAB_0098ea8c:
                  iVar10 = 0x20 - uVar20;
                  uVar11 = uVar12;
                  if (0x18 < iVar10) goto LAB_0098e3d8;
                  uVar20 = uVar20 - 8;
                  iVar10 = 0x18 - uVar20;
                  if (1 < uVar14 - uVar12) goto LAB_0098ea78;
LAB_0098eaac:
                  *(uint *)(param_1 + 0xc) = uVar12;
                  *(uint *)(param_1 + 8) = uVar14;
                  iVar16 = FUN_0098d6dc(param_1,param_2);
                  if (iVar16 != 0) goto LAB_0098dd28;
                  uVar11 = *(uint *)(param_1 + 0xc);
                  uVar14 = *(uint *)(param_1 + 8);
                  if (uVar14 <= uVar11) goto LAB_0098eb0c;
                  uVar7 = (uint)*(byte *)(iVar5 + uVar11);
                  uVar12 = uVar11 + 1;
                } while (uVar7 != 0xff);
              }
            }
LAB_0098eb0c:
            iVar10 = 0x20 - uVar20;
            if (0x18 < iVar10) {
              local_9c = 1;
              goto LAB_0098e3d8;
            }
            local_9c = 1;
            uVar20 = uVar20 - 8;
          }
          do {
            iVar10 = 0x20 - uVar20;
            if (0x18 < iVar10) break;
            iVar10 = 0x20 - (uVar20 - 8);
            uVar20 = uVar20 - 0x10;
          } while (iVar10 < 0x19);
        }
LAB_0098e3d8:
        uVar20 = (uint)*(short *)(local_90 + ((uVar13 >> 0x16) + 0x200) * 2);
        if (uVar20 == 0) {
          uVar6 = *(ushort *)(local_90 + (uVar13 >> 0x17) * 2);
          uVar12 = uVar11;
          if (uVar6 == 0) {
            uVar20 = 10;
            piVar21 = (int *)(local_90 + 0xc24);
            while( true ) {
              piVar21 = piVar21 + 1;
              uVar7 = uVar13 >> (0x20 - uVar20 & 0xff);
              if ((int)uVar7 <= *piVar21) break;
              uVar20 = uVar20 + 1;
              if (uVar20 == 0x11) goto LAB_0098dbc0;
            }
            iVar16 = local_90 + uVar20 * 4;
            uVar7 = (uint)*(byte *)(local_90 +
                                    ((uVar7 + *(int *)(iVar16 + 0xc48)) - *(int *)(iVar16 + 0xc8c))
                                   + 0xcd0);
          }
          else {
            uVar20 = (uint)(uVar6 >> 8);
            uVar7 = uVar6 & 0xff;
          }
          uVar13 = uVar13 << (uVar20 & 0xff);
          iVar10 = iVar10 - uVar20;
          if (uVar7 != 0) {
            if (uVar7 == 0x10) {
              uVar4 = uVar4 + 0x8000;
            }
            else {
              if (0x10 < uVar7) goto LAB_0098dbc0;
              if (iVar10 < (int)uVar7) {
                uVar20 = 0x18 - iVar10;
                if (local_9c == 0) {
                  if (uVar14 - uVar11 < 2) goto LAB_0098f29c;
LAB_0098f268:
                  if (*(byte *)(iVar5 + uVar12) != 0xff) {
                    uVar13 = uVar13 | (uint)*(byte *)(iVar5 + uVar12) << (uVar20 & 0xff);
                    uVar11 = uVar12 + 1;
                    goto LAB_0098f27c;
                  }
                  if (uVar12 < uVar14) {
                    while ((uVar12 + 1 < uVar14 && (*(char *)(iVar5 + uVar12 + 1) == '\0'))) {
                      uVar17 = 0xff;
                      uVar11 = uVar12 + 2;
                      do {
                        uVar13 = uVar13 | uVar17 << (uVar20 & 0xff);
LAB_0098f27c:
                        iVar10 = 0x20 - uVar20;
                        if (0x18 < iVar10) goto LAB_0098e78c;
                        uVar20 = uVar20 - 8;
                        iVar10 = 0x18 - uVar20;
                        uVar12 = uVar11;
                        if (1 < uVar14 - uVar11) goto LAB_0098f268;
LAB_0098f29c:
                        *(uint *)(param_1 + 0xc) = uVar11;
                        *(uint *)(param_1 + 8) = uVar14;
                        iVar16 = FUN_0098d6dc(param_1,param_2);
                        if (iVar16 != 0) goto LAB_0098f57c;
                        uVar12 = *(uint *)(param_1 + 0xc);
                        uVar14 = *(uint *)(param_1 + 8);
                        if (uVar14 <= uVar12) goto LAB_0098f308;
                        uVar17 = (uint)*(byte *)(iVar5 + uVar12);
                        uVar11 = uVar12 + 1;
                      } while (uVar17 != 0xff);
                    }
                  }
LAB_0098f308:
                  iVar10 = 0x20 - uVar20;
                  uVar11 = uVar12;
                  if (0x18 < iVar10) {
                    local_9c = 1;
                    goto LAB_0098e78c;
                  }
                  local_9c = 1;
                  uVar20 = uVar20 - 8;
                }
                do {
                  iVar10 = 0x20 - uVar20;
                  uVar20 = uVar20 - 8;
                } while (iVar10 < 0x19);
              }
LAB_0098e78c:
              uVar20 = uVar13 >> (0x20 - uVar7 & 0xff);
              uVar12 = uVar7 - 1;
              iVar16 = 1 << (uVar12 & 0xff);
              if ((int)uVar20 < iVar16) {
                uVar12 = 0xffffffff;
              }
              iVar10 = iVar10 - uVar7;
              uVar13 = uVar13 << uVar7;
              if ((int)uVar20 < iVar16) {
                uVar20 = uVar20 + (uVar12 << uVar7) + 1;
              }
              uVar4 = uVar4 + uVar20;
            }
          }
        }
        else {
          uVar4 = uVar4 + ((int)uVar20 >> 4);
          uVar13 = uVar13 << (uVar20 & 0xf);
          iVar10 = iVar10 - (uVar20 & 0xf);
        }
        local_6c = local_6c + 2;
        uVar4 = uVar4 & uVar9;
        local_94[3] = (ushort)uVar4;
        local_94 = local_94 + 2;
      } while (local_70 != local_6c);
      uVar12 = uVar11;
    }
    if (uVar19 <= local_70) goto LAB_0098e1ec;
    if (iVar10 < 0x19) {
      uVar4 = 0x18 - iVar10;
      if (local_9c == 0) {
        if (uVar14 - uVar12 < 2) goto LAB_0098e4a8;
LAB_0098e474:
        if (*(byte *)(iVar5 + uVar12) != 0xff) {
          uVar13 = uVar13 | (uint)*(byte *)(iVar5 + uVar12) << (uVar4 & 0xff);
          uVar12 = uVar12 + 1;
          goto LAB_0098e488;
        }
        if (uVar12 < uVar14) {
          uVar19 = uVar12 + 1;
          uVar9 = uVar12;
          while ((uVar12 = uVar9, uVar19 < uVar14 && (*(char *)(iVar5 + uVar19) == '\0'))) {
            uVar12 = uVar12 + 2;
            uVar13 = uVar13 | 0xff << (uVar4 & 0xff);
LAB_0098e488:
            iVar10 = 0x20 - uVar4;
            if (0x18 < iVar10) goto LAB_0098f3d8;
            while( true ) {
              uVar4 = uVar4 - 8;
              iVar10 = 0x18 - uVar4;
              if (1 < uVar14 - uVar12) goto LAB_0098e474;
LAB_0098e4a8:
              *(uint *)(param_1 + 0xc) = uVar12;
              *(uint *)(param_1 + 8) = uVar14;
              iVar16 = FUN_0098d6dc(param_1,param_2);
              if (iVar16 != 0) goto LAB_0098dd28;
              uVar9 = *(uint *)(param_1 + 0xc);
              uVar14 = *(uint *)(param_1 + 8);
              uVar12 = uVar9;
              if (uVar14 <= uVar9) goto LAB_0098e508;
              uVar12 = uVar9 + 1;
              uVar19 = uVar12;
              if (*(byte *)(iVar5 + uVar9) == 0xff) break;
              iVar10 = 0x20 - uVar4;
              uVar13 = uVar13 | (uint)*(byte *)(iVar5 + uVar9) << (uVar4 & 0xff);
              if (0x18 < iVar10) goto LAB_0098f3d8;
            }
          }
        }
LAB_0098e508:
        iVar10 = 0x20 - uVar4;
        if (0x18 < iVar10) {
          local_9c = 1;
          goto LAB_0098f3d8;
        }
        uVar4 = uVar4 - 8;
        local_9c = 1;
      }
      do {
        iVar10 = 0x20 - uVar4;
        uVar4 = uVar4 - 8;
      } while (iVar10 < 0x19);
    }
LAB_0098f3d8:
    sVar15 = *(short *)((int)local_98 + ((uVar13 >> 0x16) + 0x200) * 2);
    uVar4 = (uint)sVar15;
    if (uVar4 == 0) {
      uVar6 = *(ushort *)((int)local_98 + (uVar13 >> 0x17) * 2);
      if (uVar6 == 0) {
        uVar4 = 10;
        piVar21 = (int *)((int)local_98 + 0xc24);
        do {
          piVar21 = piVar21 + 1;
          uVar9 = uVar13 >> (0x20 - uVar4 & 0xff);
          if ((int)uVar9 <= *piVar21) {
            iVar16 = (int)local_98 + uVar4 * 4;
            uVar9 = (uint)*(byte *)((int)local_98 +
                                    ((uVar9 + *(int *)(iVar16 + 0xc48)) - *(int *)(iVar16 + 0xc8c))
                                   + 0xcd0);
            goto LAB_0098f4dc;
          }
          uVar4 = uVar4 + 1;
        } while (uVar4 != 0x11);
LAB_0098dbc0:
        uVar3 = 0xfffffffc;
        goto LAB_0098dbc4;
      }
      uVar4 = (uint)(uVar6 >> 8);
      uVar9 = uVar6 & 0xff;
LAB_0098f4dc:
      uVar13 = uVar13 << (uVar4 & 0xff);
      iVar10 = iVar10 - uVar4;
      if (uVar9 != 0) {
        if (uVar9 == 0x10) {
          sVar15 = -0x8000;
        }
        else {
          if (0x10 < uVar9) goto LAB_0098dbc0;
          uVar4 = uVar12;
          if (iVar10 < (int)uVar9) {
            do {
              iVar16 = iVar10 + 8;
              if (local_9c == 0) {
                uVar12 = uVar4;
                while (1 < uVar14 - uVar12) {
                  if (*(byte *)(iVar5 + uVar12) == 0xff) {
                    if (uVar14 <= uVar12) goto LAB_0098f710;
                    uVar4 = uVar12 + 1;
                    goto LAB_0098f75c;
                  }
                  uVar4 = uVar12 + 1;
                  uVar13 = uVar13 | (uint)*(byte *)(iVar5 + uVar12) << (0x20U - iVar16 & 0xff);
                  iVar10 = iVar16;
                  uVar2 = 0;
                  if (0x18 < iVar16) goto LAB_0098f6bc;
                  iVar16 = iVar16 + 8;
                  uVar12 = uVar4;
                }
                *(uint *)(param_1 + 0xc) = uVar12;
                *(uint *)(param_1 + 8) = uVar14;
                iVar22 = FUN_0098d6dc(param_1,param_2);
                if (iVar22 != 0) goto LAB_0098dd28;
                uVar12 = *(uint *)(param_1 + 0xc);
                uVar14 = *(uint *)(param_1 + 8);
                if (uVar12 < uVar14) {
                  uVar4 = uVar12 + 1;
                  uVar19 = (uint)*(byte *)(iVar5 + uVar12);
                  if (uVar19 == 0xff) {
LAB_0098f75c:
                    if ((uVar14 <= uVar4) || (*(char *)(iVar5 + uVar4) != '\0')) goto LAB_0098f710;
                    uVar19 = 0xff;
                    uVar4 = uVar12 + 2;
                  }
                }
                else {
LAB_0098f710:
                  uVar4 = uVar12;
                  uVar19 = 0;
                  local_9c = 1;
                }
              }
              else {
                uVar19 = 0;
              }
              uVar13 = uVar13 | uVar19 << (0x20U - iVar16 & 0xff);
              iVar10 = iVar16;
              uVar2 = (char)local_9c;
            } while (iVar16 < 0x19);
LAB_0098f6bc:
            local_9c._0_1_ = uVar2;
          }
          uVar19 = uVar13 >> (0x20 - uVar9 & 0xff);
          iVar10 = iVar10 - uVar9;
          uVar13 = uVar13 << uVar9;
          if ((int)uVar19 < 1 << (uVar9 - 1 & 0xff)) {
            uVar19 = uVar19 + (-1 << uVar9) + 1;
          }
          sVar15 = (short)uVar19;
          uVar12 = uVar4;
        }
      }
    }
    else {
      uVar13 = uVar13 << (uVar4 & 0xf);
      iVar10 = iVar10 - (uVar4 & 0xf);
      sVar15 = (short)((int)uVar4 >> 4);
    }
    param_3[local_70] = (ushort)local_84 + sVar15 & uVar1;
LAB_0098e1ec:
    iVar16 = *(int *)(param_1 + 0x24);
  }
  else {
    uVar11 = 0;
    local_98 = param_3 + -1;
    puVar18 = (ushort *)(param_1 + 0x18);
    do {
      iVar16 = local_68[uVar11];
      if (iVar10 < 0x19) {
        uVar7 = 0x18 - iVar10;
        if (local_9c == 0) {
          if (uVar14 - uVar12 < 2) goto LAB_0098da80;
LAB_0098da4c:
          if (*(byte *)(iVar5 + uVar12) != 0xff) {
            uVar13 = uVar13 | (uint)*(byte *)(iVar5 + uVar12) << (uVar7 & 0xff);
            goto LAB_0098da60;
          }
          if (uVar12 < uVar14) {
            while ((uVar12 + 1 < uVar14 && (*(char *)(iVar5 + uVar12 + 1) == '\0'))) {
              uVar12 = uVar12 + 2;
              uVar13 = uVar13 | 0xff << (uVar7 & 0xff);
              while( true ) {
                iVar10 = 0x20 - uVar7;
                if (0x18 < iVar10) goto LAB_0098d994;
                uVar7 = uVar7 - 8;
                iVar10 = 0x18 - uVar7;
                if (1 < uVar14 - uVar12) goto LAB_0098da4c;
LAB_0098da80:
                *(uint *)(param_1 + 0xc) = uVar12;
                *(uint *)(param_1 + 8) = uVar14;
                iVar22 = FUN_0098d6dc(param_1,param_2);
                if (iVar22 != 0) goto LAB_0098dd28;
                uVar12 = *(uint *)(param_1 + 0xc);
                uVar14 = *(uint *)(param_1 + 8);
                if (uVar14 <= uVar12) goto joined_r0x0098db7c;
                if (*(byte *)(iVar5 + uVar12) == 0xff) break;
                uVar13 = uVar13 | (uint)*(byte *)(iVar5 + uVar12) << (uVar7 & 0xff);
LAB_0098da60:
                uVar12 = uVar12 + 1;
              }
            }
          }
joined_r0x0098db7c:
          iVar10 = 0x20 - uVar7;
          if (0x18 < iVar10) {
            local_9c = 1;
            goto LAB_0098d994;
          }
          uVar7 = uVar7 - 8;
          local_9c = 1;
        }
        do {
          iVar10 = 0x20 - uVar7;
          if (0x18 < iVar10) break;
          iVar10 = 0x20 - (uVar7 - 8);
          uVar7 = uVar7 - 0x10;
        } while (iVar10 < 0x19);
      }
LAB_0098d994:
      uVar7 = (uint)*(short *)(iVar16 + ((uVar13 >> 0x16) + 0x200) * 2);
      if (uVar7 == 0) {
        uVar6 = *(ushort *)(iVar16 + (uVar13 >> 0x17) * 2);
        if (uVar6 == 0) {
          uVar7 = 10;
          piVar21 = (int *)(iVar16 + 0xc24);
          while( true ) {
            piVar21 = piVar21 + 1;
            uVar17 = uVar13 >> (0x20 - uVar7 & 0xff);
            if ((int)uVar17 <= *piVar21) break;
            uVar7 = uVar7 + 1;
            if (uVar7 == 0x11) goto LAB_0098dbc0;
          }
          iVar22 = iVar16 + uVar7 * 4;
          uVar17 = (uint)*(byte *)(iVar16 + ((uVar17 + *(int *)(iVar22 + 0xc48)) -
                                            *(int *)(iVar22 + 0xc8c)) + 0xcd0);
        }
        else {
          uVar7 = (uint)(uVar6 >> 8);
          uVar17 = uVar6 & 0xff;
        }
        uVar13 = uVar13 << (uVar7 & 0xff);
        iVar10 = iVar10 - uVar7;
        sVar15 = 0;
        if (uVar17 != 0) {
          if (uVar17 == 0x10) {
            sVar15 = -0x8000;
          }
          else {
            if (0x10 < uVar17) goto LAB_0098dbc0;
            uVar7 = uVar12;
            if (iVar10 < (int)uVar17) {
              uVar8 = 0x18 - iVar10;
              if (local_9c == 0) {
                if (uVar14 - uVar12 < 2) goto LAB_0098dc58;
LAB_0098dc24:
                if (*(byte *)(iVar5 + uVar7) != 0xff) {
                  uVar13 = uVar13 | (uint)*(byte *)(iVar5 + uVar7) << (uVar8 & 0xff);
                  uVar12 = uVar7 + 1;
                  goto LAB_0098dc38;
                }
                if (uVar7 < uVar14) {
                  while ((uVar7 + 1 < uVar14 && (*(char *)(iVar5 + uVar7 + 1) == '\0'))) {
                    uVar12 = uVar7 + 2;
                    uVar13 = uVar13 | 0xff << (uVar8 & 0xff);
LAB_0098dc38:
                    while( true ) {
                      iVar10 = 0x20 - uVar8;
                      uVar7 = uVar12;
                      if (0x18 < iVar10) goto LAB_0098d9ec;
                      uVar8 = uVar8 - 8;
                      iVar10 = 0x18 - uVar8;
                      if (1 < uVar14 - uVar12) goto LAB_0098dc24;
LAB_0098dc58:
                      *(uint *)(param_1 + 0xc) = uVar12;
                      *(uint *)(param_1 + 8) = uVar14;
                      iVar16 = FUN_0098d6dc(param_1,param_2);
                      if (iVar16 != 0) goto LAB_0098dd28;
                      uVar7 = *(uint *)(param_1 + 0xc);
                      uVar14 = *(uint *)(param_1 + 8);
                      if (uVar14 <= uVar7) goto LAB_0098dce0;
                      uVar12 = uVar7 + 1;
                      if (*(byte *)(iVar5 + uVar7) == 0xff) break;
                      uVar13 = uVar13 | (uint)*(byte *)(iVar5 + uVar7) << (uVar8 & 0xff);
                    }
                  }
                }
LAB_0098dce0:
                iVar10 = 0x20 - uVar8;
                if (0x18 < iVar10) {
                  local_9c = 1;
                  goto LAB_0098d9ec;
                }
                uVar8 = uVar8 - 8;
                local_9c = 1;
              }
              do {
                iVar10 = 0x20 - uVar8;
                if (0x18 < iVar10) break;
                iVar10 = 0x20 - (uVar8 - 8);
                uVar8 = uVar8 - 0x10;
              } while (iVar10 < 0x19);
            }
LAB_0098d9ec:
            uVar12 = uVar13 >> (0x20 - uVar17 & 0xff);
            iVar16 = 1 << (uVar17 - 1 & 0xff);
            uVar8 = uVar12;
            if ((int)uVar12 < iVar16) {
              uVar8 = uVar12 + (-1 << uVar17);
            }
            sVar15 = (short)uVar8;
            iVar10 = iVar10 - uVar17;
            uVar13 = uVar13 << uVar17;
            if ((int)uVar12 < iVar16) {
              sVar15 = sVar15 + 1;
            }
            uVar12 = uVar7;
          }
        }
      }
      else {
        uVar13 = uVar13 << (uVar7 & 0xf);
        iVar10 = iVar10 - (uVar7 & 0xf);
        sVar15 = (short)((int)uVar7 >> 4);
      }
      iVar16 = *(int *)(param_1 + 0x24);
      uVar11 = uVar11 + 1;
      if (iVar16 == 0) {
        uVar6 = (ushort)((uint)(0x10000 << (*(int *)(param_2 + 0xb0) - 1U & 0xff)) >> 0x10);
      }
      else {
        uVar6 = puVar18[1];
      }
      uVar6 = sVar15 + uVar6 & uVar1;
      local_98 = local_98 + 1;
      *local_98 = uVar6;
      puVar18 = puVar18 + 1;
      *puVar18 = uVar6;
    } while (uVar4 != uVar11);
    if (uVar20 != 2 || uVar4 != 2) {
      if (uVar20 == 2) {
        local_84 = (uint)*param_3;
        local_98 = (ushort *)local_68[0];
        local_90 = local_68[1];
        uVar11 = uVar12;
        goto LAB_0098e354;
      }
LAB_0098dedc:
      if (uVar20 < uVar19) {
        local_98 = param_3 + (uVar4 - 1);
        uVar9 = 0;
        local_94 = param_3 + (uVar4 - uVar20);
        do {
          iVar16 = local_68[uVar9];
          if (iVar10 < 0x19) {
            uVar11 = 0x18 - iVar10;
            if (local_9c == 0) {
              uVar7 = uVar12;
              if (uVar14 - uVar12 < 2) goto LAB_0098e064;
LAB_0098e030:
              if (*(byte *)(iVar5 + uVar7) != 0xff) {
                uVar13 = uVar13 | (uint)*(byte *)(iVar5 + uVar7) << (uVar11 & 0xff);
                uVar12 = uVar7 + 1;
                goto LAB_0098e044;
              }
              if (uVar7 < uVar14) {
                while ((uVar7 + 1 < uVar14 && (*(char *)(iVar5 + uVar7 + 1) == '\0'))) {
                  uVar17 = 0xff;
                  uVar12 = uVar7 + 2;
                  do {
                    uVar13 = uVar13 | uVar17 << (uVar11 & 0xff);
LAB_0098e044:
                    iVar10 = 0x20 - uVar11;
                    if (0x18 < iVar10) goto LAB_0098df80;
                    uVar11 = uVar11 - 8;
                    iVar10 = 0x18 - uVar11;
                    uVar7 = uVar12;
                    if (1 < uVar14 - uVar12) goto LAB_0098e030;
LAB_0098e064:
                    *(uint *)(param_1 + 0xc) = uVar12;
                    *(uint *)(param_1 + 8) = uVar14;
                    iVar22 = FUN_0098d6dc(param_1,param_2);
                    if (iVar22 != 0) goto LAB_0098dd28;
                    uVar7 = *(uint *)(param_1 + 0xc);
                    uVar14 = *(uint *)(param_1 + 8);
                    if (uVar14 <= uVar7) goto LAB_0098e0d0;
                    uVar17 = (uint)*(byte *)(iVar5 + uVar7);
                    uVar12 = uVar7 + 1;
                  } while (uVar17 != 0xff);
                }
              }
LAB_0098e0d0:
              iVar10 = 0x20 - uVar11;
              uVar12 = uVar7;
              if (0x18 < iVar10) {
                local_9c = 1;
                goto LAB_0098df80;
              }
              uVar11 = uVar11 - 8;
              local_9c = 1;
            }
            do {
              iVar10 = 0x20 - uVar11;
              if (0x18 < iVar10) break;
              iVar10 = 0x20 - (uVar11 - 8);
              uVar11 = uVar11 - 0x10;
            } while (iVar10 < 0x19);
          }
LAB_0098df80:
          uVar11 = (uint)*(short *)(iVar16 + ((uVar13 >> 0x16) + 0x200) * 2);
          if (uVar11 == 0) {
            uVar6 = *(ushort *)(iVar16 + (uVar13 >> 0x17) * 2);
            if (uVar6 == 0) {
              uVar11 = 10;
              piVar21 = (int *)(iVar16 + 0xc24);
              while( true ) {
                piVar21 = piVar21 + 1;
                uVar7 = uVar13 >> (0x20 - uVar11 & 0xff);
                if ((int)uVar7 <= *piVar21) break;
                uVar11 = uVar11 + 1;
                if (uVar11 == 0x11) goto LAB_0098dbc0;
              }
              iVar22 = iVar16 + uVar11 * 4;
              uVar7 = (uint)*(byte *)(iVar16 + ((uVar7 + *(int *)(iVar22 + 0xc48)) -
                                               *(int *)(iVar22 + 0xc8c)) + 0xcd0);
            }
            else {
              uVar11 = (uint)(uVar6 >> 8);
              uVar7 = uVar6 & 0xff;
            }
            uVar13 = uVar13 << (uVar11 & 0xff);
            iVar10 = iVar10 - uVar11;
            if (uVar7 == 0) {
              sVar15 = 0;
            }
            else if (uVar7 == 0x10) {
              sVar15 = -0x8000;
            }
            else {
              if (0x10 < uVar7) goto LAB_0098dbc0;
              if (iVar10 < (int)uVar7) {
                uVar11 = 0x18 - iVar10;
                if (local_9c == 0) {
                  uVar17 = uVar12;
                  if (uVar14 - uVar12 < 2) goto LAB_0098e280;
LAB_0098e24c:
                  if (*(byte *)(iVar5 + uVar17) != 0xff) {
                    uVar13 = uVar13 | (uint)*(byte *)(iVar5 + uVar17) << (uVar11 & 0xff);
                    uVar12 = uVar17 + 1;
                    goto LAB_0098e260;
                  }
                  if (uVar17 < uVar14) {
                    while ((uVar17 + 1 < uVar14 && (*(char *)(iVar5 + uVar17 + 1) == '\0'))) {
                      uVar8 = 0xff;
                      uVar12 = uVar17 + 2;
                      do {
                        uVar13 = uVar13 | uVar8 << (uVar11 & 0xff);
LAB_0098e260:
                        iVar10 = 0x20 - uVar11;
                        if (0x18 < iVar10) goto LAB_0098dfd8;
                        uVar11 = uVar11 - 8;
                        iVar10 = 0x18 - uVar11;
                        uVar17 = uVar12;
                        if (1 < uVar14 - uVar12) goto LAB_0098e24c;
LAB_0098e280:
                        *(uint *)(param_1 + 0xc) = uVar12;
                        *(uint *)(param_1 + 8) = uVar14;
                        iVar16 = FUN_0098d6dc(param_1,param_2);
                        if (iVar16 != 0) goto LAB_0098dd28;
                        uVar17 = *(uint *)(param_1 + 0xc);
                        uVar14 = *(uint *)(param_1 + 8);
                        if (uVar14 <= uVar17) goto LAB_0098e300;
                        uVar8 = (uint)*(byte *)(iVar5 + uVar17);
                        uVar12 = uVar17 + 1;
                      } while (uVar8 != 0xff);
                    }
                  }
LAB_0098e300:
                  iVar10 = 0x20 - uVar11;
                  uVar12 = uVar17;
                  if (0x18 < iVar10) {
                    local_9c = 1;
                    goto LAB_0098dfd8;
                  }
                  uVar11 = uVar11 - 8;
                  local_9c = 1;
                }
                do {
                  iVar10 = 0x20 - uVar11;
                  if (0x18 < iVar10) break;
                  iVar10 = 0x20 - (uVar11 - 8);
                  uVar11 = uVar11 - 0x10;
                } while (iVar10 < 0x19);
              }
LAB_0098dfd8:
              uVar11 = uVar13 >> (0x20 - uVar7 & 0xff);
              iVar10 = iVar10 - uVar7;
              uVar13 = uVar13 << uVar7;
              if ((int)uVar11 < 1 << (uVar7 - 1 & 0xff)) {
                uVar11 = uVar11 + (-1 << uVar7) + 1;
              }
              sVar15 = (short)uVar11;
            }
          }
          else {
            uVar13 = uVar13 << (uVar11 & 0xf);
            iVar10 = iVar10 - (uVar11 & 0xf);
            sVar15 = (short)((int)uVar11 >> 4);
          }
          uVar9 = uVar9 + 1;
          uVar4 = uVar4 + 1;
          if (uVar20 == uVar9) {
            uVar9 = 0;
          }
          local_98 = local_98 + 1;
          *local_98 = *local_94 + sVar15 & uVar1;
          local_94 = local_94 + 1;
        } while (uVar4 < uVar19);
      }
      goto LAB_0098e1ec;
    }
    if (1 < uVar19) {
      local_50 = iVar5 + uVar12;
      local_4c = local_50;
      if ((local_9c == 0) && (uVar12 + 2 <= uVar14)) {
        local_4c = iVar5 + (uVar14 - 1);
      }
      local_40 = (uint)*param_3;
      local_3c = (uint)param_3[1];
      local_44 = param_3 + (uVar19 - 2 & 0xfffffffe) + 2;
      local_34 = local_68[1] + 0x400;
      local_2c = 0;
      local_38 = local_68[0] + 0x400;
      local_48 = param_3 + 2;
      local_58 = uVar13;
      local_54 = iVar10;
      local_30 = uVar9;
      while( true ) {
        iVar16 = FUN_0098cbbc(&local_58);
        uVar12 = local_50 - iVar5;
        iVar10 = local_54;
        uVar13 = local_58;
        if (iVar16 == 0) break;
        if (iVar16 == 1) {
          if (local_54 < 0x19) {
            uVar4 = 1;
            if (local_9c != 0) {
              uVar4 = local_9c;
            }
            uVar20 = 0x18 - local_54;
            if (local_9c == 0) {
              uVar11 = uVar12;
              if (uVar14 - uVar12 < 2) goto LAB_0098e81c;
LAB_0098e7e8:
              if (*(byte *)(iVar5 + uVar11) != 0xff) {
                uVar13 = uVar13 | (uint)*(byte *)(iVar5 + uVar11) << (uVar20 & 0xff);
                uVar12 = uVar11 + 1;
                goto LAB_0098e7fc;
              }
              if (uVar11 < uVar14) {
                while( true ) {
                  if ((uVar14 <= uVar11 + 1) || (*(char *)(iVar5 + uVar11 + 1) != '\0'))
                  goto LAB_0098e884;
                  uVar12 = uVar11 + 2;
                  uVar13 = uVar13 | 0xff << (uVar20 & 0xff);
LAB_0098e7fc:
                  iVar10 = 0x20 - uVar20;
                  if (0x18 < iVar10) break;
                  while( true ) {
                    uVar20 = uVar20 - 8;
                    iVar10 = 0x18 - uVar20;
                    uVar11 = uVar12;
                    if (1 < uVar14 - uVar12) goto LAB_0098e7e8;
LAB_0098e81c:
                    *(uint *)(param_1 + 0xc) = uVar12;
                    *(uint *)(param_1 + 8) = uVar14;
                    iVar16 = FUN_0098d6dc(param_1,param_2);
                    if (iVar16 != 0) goto LAB_0098dd28;
                    uVar11 = *(uint *)(param_1 + 0xc);
                    uVar14 = *(uint *)(param_1 + 8);
                    if (uVar14 <= uVar11) goto LAB_0098e884;
                    uVar12 = uVar11 + 1;
                    if (*(byte *)(iVar5 + uVar11) == 0xff) break;
                    uVar13 = uVar13 | (uint)*(byte *)(iVar5 + uVar11) << (uVar20 & 0xff);
                    iVar10 = 0x20 - uVar20;
                    if (0x18 < iVar10) {
                      uVar4 = 0;
                      goto LAB_0098deb8;
                    }
                  }
                }
                uVar4 = 0;
                goto LAB_0098deb8;
              }
LAB_0098e884:
              iVar10 = 0x20 - uVar20;
              uVar12 = uVar11;
              if (0x18 < iVar10) goto LAB_0098deb8;
              uVar20 = uVar20 - 8;
            }
            do {
              iVar10 = 0x20 - uVar20;
              if (0x18 < iVar10) break;
              iVar10 = 0x20 - (uVar20 - 8);
              uVar20 = uVar20 - 0x10;
            } while (iVar10 < 0x19);
            goto LAB_0098deb8;
          }
        }
        else {
          iVar16 = local_68[0];
          if (local_2c != 0) {
            iVar16 = local_68[1];
          }
          if (local_54 < 0x19) {
            uVar4 = 0x18 - local_54;
            if (local_9c == 0) {
              if (uVar14 - uVar12 < 2) goto LAB_0098e608;
LAB_0098e5d4:
              if (*(byte *)(iVar5 + uVar12) != 0xff) {
                uVar13 = uVar13 | (uint)*(byte *)(iVar5 + uVar12) << (uVar4 & 0xff);
                uVar20 = uVar12 + 1;
                goto LAB_0098e5e8;
              }
              if (uVar12 < uVar14) {
                while ((uVar12 + 1 < uVar14 && (*(char *)(iVar5 + uVar12 + 1) == '\0'))) {
                  uVar11 = 0xff;
                  uVar20 = uVar12 + 2;
                  do {
                    uVar13 = uVar13 | uVar11 << (uVar4 & 0xff);
LAB_0098e5e8:
                    iVar10 = 0x20 - uVar4;
                    uVar12 = uVar20;
                    if (0x18 < iVar10) goto LAB_0098de58;
                    uVar4 = uVar4 - 8;
                    iVar10 = 0x18 - uVar4;
                    if (1 < uVar14 - uVar20) goto LAB_0098e5d4;
LAB_0098e608:
                    *(uint *)(param_1 + 0xc) = uVar12;
                    *(uint *)(param_1 + 8) = uVar14;
                    iVar22 = FUN_0098d6dc(param_1,param_2);
                    if (iVar22 != 0) goto LAB_0098dd28;
                    uVar12 = *(uint *)(param_1 + 0xc);
                    uVar14 = *(uint *)(param_1 + 8);
                    if (uVar14 <= uVar12) goto LAB_0098e660;
                    uVar11 = (uint)*(byte *)(iVar5 + uVar12);
                    uVar20 = uVar12 + 1;
                  } while (uVar11 != 0xff);
                }
              }
LAB_0098e660:
              iVar10 = 0x20 - uVar4;
              if (0x18 < iVar10) {
                local_9c = 1;
                goto LAB_0098de58;
              }
              local_9c = 1;
              uVar4 = uVar4 - 8;
            }
            do {
              iVar10 = 0x20 - uVar4;
              if (0x18 < iVar10) break;
              iVar10 = 0x20 - (uVar4 - 8);
              uVar4 = uVar4 - 0x10;
            } while (iVar10 < 0x19);
          }
LAB_0098de58:
          uVar4 = (uint)*(short *)(iVar16 + ((uVar13 >> 0x16) + 0x200) * 2);
          if (uVar4 == 0) {
            uVar6 = *(ushort *)(iVar16 + (uVar13 >> 0x17) * 2);
            if (uVar6 == 0) {
              uVar4 = 10;
              piVar21 = (int *)(iVar16 + 0xc24);
              while( true ) {
                piVar21 = piVar21 + 1;
                uVar20 = uVar13 >> (0x20 - uVar4 & 0xff);
                if ((int)uVar20 <= *piVar21) break;
                uVar4 = uVar4 + 1;
                if (uVar4 == 0x11) goto LAB_0098ea3c;
              }
              iVar22 = iVar16 + uVar4 * 4;
              uVar20 = (uint)*(byte *)(iVar16 + ((uVar20 + *(int *)(iVar22 + 0xc48)) -
                                                *(int *)(iVar22 + 0xc8c)) + 0xcd0);
            }
            else {
              uVar4 = (uint)(uVar6 >> 8);
              uVar20 = uVar6 & 0xff;
            }
            uVar13 = uVar13 << (uVar4 & 0xff);
            iVar10 = iVar10 - uVar4;
            uVar4 = 0;
            if (uVar20 != 0) {
              if (uVar20 == 0x10) {
                uVar4 = 0x8000;
              }
              else {
                if (0x10 < uVar20) {
LAB_0098ea3c:
                  goto LAB_0098dbc0;
                }
                if (iVar10 < (int)uVar20) {
                  uVar4 = 0x18 - iVar10;
                  if (local_9c == 0) {
                    uVar11 = uVar12;
                    if (uVar14 - uVar12 < 2) goto LAB_0098ed04;
LAB_0098ecd0:
                    if (*(byte *)(iVar5 + uVar11) != 0xff) {
                      uVar13 = uVar13 | (uint)*(byte *)(iVar5 + uVar11) << (uVar4 & 0xff);
                      uVar12 = uVar11 + 1;
                      goto LAB_0098ece4;
                    }
                    if (uVar11 < uVar14) {
                      while ((uVar11 + 1 < uVar14 && (*(char *)(iVar5 + uVar11 + 1) == '\0'))) {
                        uVar7 = 0xff;
                        uVar12 = uVar11 + 2;
                        do {
                          uVar13 = uVar13 | uVar7 << (uVar4 & 0xff);
LAB_0098ece4:
                          iVar10 = 0x20 - uVar4;
                          if (0x18 < iVar10) goto LAB_0098e574;
                          uVar4 = uVar4 - 8;
                          iVar10 = 0x18 - uVar4;
                          uVar11 = uVar12;
                          if (1 < uVar14 - uVar12) goto LAB_0098ecd0;
LAB_0098ed04:
                          *(uint *)(param_1 + 0xc) = uVar12;
                          *(uint *)(param_1 + 8) = uVar14;
                          iVar16 = FUN_0098d6dc(param_1,param_2);
                          if (iVar16 != 0) goto LAB_0098dd28;
                          uVar11 = *(uint *)(param_1 + 0xc);
                          uVar14 = *(uint *)(param_1 + 8);
                          if (uVar14 <= uVar11) goto LAB_0098ed60;
                          uVar7 = (uint)*(byte *)(iVar5 + uVar11);
                          uVar12 = uVar11 + 1;
                        } while (uVar7 != 0xff);
                      }
                    }
LAB_0098ed60:
                    iVar10 = 0x20 - uVar4;
                    uVar12 = uVar11;
                    if (0x18 < iVar10) {
                      local_9c = 1;
                      goto LAB_0098e574;
                    }
                    uVar4 = uVar4 - 8;
                    local_9c = 1;
                  }
                  do {
                    iVar10 = 0x20 - uVar4;
                    uVar4 = uVar4 - 8;
                  } while (iVar10 < 0x19);
                }
LAB_0098e574:
                uVar4 = uVar13 >> (0x20 - uVar20 & 0xff);
                iVar10 = iVar10 - uVar20;
                uVar13 = uVar13 << uVar20;
                if ((int)uVar4 < 1 << (uVar20 - 1 & 0xff)) {
                  uVar4 = uVar4 + (-1 << uVar20) + 1;
                }
              }
            }
          }
          else {
            uVar13 = uVar13 << (uVar4 & 0xf);
            iVar10 = iVar10 - (uVar4 & 0xf);
            uVar4 = (int)uVar4 >> 4;
          }
          if (local_2c == 0) {
            uVar4 = uVar4 + local_40 & uVar9;
            local_40 = uVar4;
          }
          else {
            uVar4 = uVar4 + local_3c & uVar9;
            local_3c = uVar4;
          }
          local_2c = local_2c ^ 1;
          *local_48 = (ushort)uVar4;
          uVar4 = local_9c;
          local_48 = local_48 + 1;
LAB_0098deb8:
          local_50 = iVar5 + uVar12;
          local_54 = iVar10;
          local_58 = uVar13;
          local_9c = uVar4;
        }
        if ((local_9c == 0) && (uVar12 + 2 <= uVar14)) {
          local_4c = iVar5 + (uVar14 - 1);
        }
        else {
          local_4c = local_50;
        }
      }
      uVar19 = uVar19 & 1;
      if (uVar19 == 0) goto LAB_0098e1ec;
      if (local_54 < 0x19) {
        uVar4 = 0x18 - local_54;
        if (local_9c == 0) {
          uVar9 = uVar12;
          if (uVar14 - uVar12 < 2) goto LAB_0098f014;
LAB_0098efdc:
          if (*(byte *)(iVar5 + uVar9) != 0xff) {
            uVar13 = uVar13 | (uint)*(byte *)(iVar5 + uVar9) << (uVar4 & 0xff);
            uVar12 = uVar9 + 1;
            goto LAB_0098eff4;
          }
          if (uVar9 < uVar14) {
            uVar12 = uVar9 + 1;
            while ((uVar12 < uVar14 && (*(char *)(iVar5 + uVar12) == '\0'))) {
              uVar12 = uVar9 + 2;
              uVar13 = uVar13 | 0xff << (uVar4 & 0xff);
LAB_0098eff4:
              iVar10 = 0x20 - uVar4;
              if (0x18 < iVar10) goto LAB_0098e1b0;
              while( true ) {
                uVar4 = uVar4 - 8;
                iVar10 = 0x18 - uVar4;
                uVar9 = uVar12;
                if (1 < uVar14 - uVar12) goto LAB_0098efdc;
LAB_0098f014:
                *(uint *)(param_1 + 0xc) = uVar12;
                *(uint *)(param_1 + 8) = uVar14;
                iVar16 = FUN_0098d6dc(param_1,param_2);
                if (iVar16 != 0) goto LAB_0098dd28;
                uVar9 = *(uint *)(param_1 + 0xc);
                uVar14 = *(uint *)(param_1 + 8);
                if (uVar14 <= uVar9) goto LAB_0098e180;
                uVar12 = uVar9 + 1;
                if (*(byte *)(iVar5 + uVar9) == 0xff) break;
                iVar10 = 0x20 - uVar4;
                uVar13 = uVar13 | (uint)*(byte *)(iVar5 + uVar9) << (uVar4 & 0xff);
                if (0x18 < iVar10) {
                  goto LAB_0098e1b0;
                }
              }
            }
          }
LAB_0098e180:
          uVar12 = uVar9;
          iVar10 = 0x20 - uVar4;
          if (0x18 < iVar10) {
            local_9c = uVar19;
            goto LAB_0098e1b0;
          }
          uVar4 = uVar4 - 8;
          local_9c = uVar19;
        }
        do {
          iVar10 = 0x20 - uVar4;
          uVar4 = uVar4 - 8;
        } while (iVar10 < 0x19);
      }
LAB_0098e1b0:
      sVar15 = *(short *)(local_68[0] + ((uVar13 >> 0x16) + 0x200) * 2);
      uVar4 = (uint)sVar15;
      if (uVar4 == 0) {
        uVar6 = *(ushort *)(local_68[0] + (uVar13 >> 0x17) * 2);
        if (uVar6 == 0) {
          uVar4 = 10;
          piVar21 = (int *)(local_68[0] + 0xc24);
          do {
            piVar21 = piVar21 + 1;
            uVar9 = uVar13 >> (0x20 - uVar4 & 0xff);
            if ((int)uVar9 <= *piVar21) {
              iVar16 = local_68[0] + uVar4 * 4;
              uVar9 = (uint)*(byte *)(local_68[0] +
                                      ((uVar9 + *(int *)(iVar16 + 0xc48)) - *(int *)(iVar16 + 0xc8c)
                                      ) + 0xcd0);
              goto LAB_0098f138;
            }
            uVar4 = uVar4 + 1;
          } while (uVar4 != 0x11);
          goto LAB_0098dbc0;
        }
        uVar4 = (uint)(uVar6 >> 8);
        uVar9 = uVar6 & 0xff;
LAB_0098f138:
        uVar13 = uVar13 << (uVar4 & 0xff);
        iVar10 = iVar10 - uVar4;
        if (uVar9 != 0) {
          if (uVar9 == 0x10) {
            sVar15 = -0x8000;
          }
          else {
            if (0x10 < uVar9) goto LAB_0098dbc0;
            if (iVar10 < (int)uVar9) {
              uVar4 = 0x18 - iVar10;
              if (local_9c == 0) {
                uVar11 = uVar12;
                do {
                  if (uVar14 - uVar11 < 2) {
                    *(uint *)(param_1 + 0xc) = uVar11;
                    *(uint *)(param_1 + 8) = uVar14;
                    iVar16 = FUN_0098d6dc(param_1,param_2);
                    if (iVar16 != 0) goto LAB_0098f57c;
                    uVar11 = *(uint *)(param_1 + 0xc);
                    uVar14 = *(uint *)(param_1 + 8);
                    if (uVar14 <= uVar11) goto LAB_0098f1b8;
                    uVar12 = uVar11 + 1;
                    if (*(byte *)(iVar5 + uVar11) == 0xff) goto LAB_0098f5e8;
                    iVar10 = 0x20 - uVar4;
                    uVar13 = uVar13 | (uint)*(byte *)(iVar5 + uVar11) << (uVar4 & 0xff);
                    if (0x18 < iVar10) goto LAB_0098f1f4;
                  }
                  else {
                    if (*(byte *)(iVar5 + uVar11) == 0xff) {
                      if (uVar11 < uVar14) {
                        uVar12 = uVar11 + 1;
LAB_0098f5e8:
                        if ((uVar12 < uVar14) && (*(char *)(iVar5 + uVar12) == '\0')) {
                          uVar12 = uVar11 + 2;
                          uVar20 = 0xff << (uVar4 & 0xff);
                          goto LAB_0098f60c;
                        }
                      }
LAB_0098f1b8:
                      iVar10 = 0x20 - uVar4;
                      uVar12 = uVar11;
                      local_9c._0_1_ = (char)uVar19;
                      if (iVar10 < 0x19) {
                        uVar4 = uVar4 - 8;
                        local_9c = uVar19;
                        break;
                      }
                      goto LAB_0098f1f4;
                    }
                    uVar20 = (uint)*(byte *)(iVar5 + uVar11) << (uVar4 & 0xff);
                    uVar12 = uVar11 + 1;
LAB_0098f60c:
                    uVar13 = uVar13 | uVar20;
                    iVar10 = 0x20 - uVar4;
                    if (0x18 < iVar10) goto LAB_0098f1f4;
                  }
                  uVar4 = uVar4 - 8;
                  iVar10 = 0x18 - uVar4;
                  uVar11 = uVar12;
                } while( true );
              }
              do {
                iVar10 = 0x20 - uVar4;
                uVar4 = uVar4 - 8;
              } while (iVar10 < 0x19);
            }
LAB_0098f1f4:
            uVar4 = uVar13 >> (0x20 - uVar9 & 0xff);
            iVar10 = iVar10 - uVar9;
            uVar13 = uVar13 << uVar9;
            if ((int)uVar4 < 1 << (uVar9 - 1 & 0xff)) {
              uVar4 = uVar4 + (-1 << uVar9) + 1;
            }
            sVar15 = (short)uVar4;
          }
        }
      }
      else {
        uVar13 = uVar13 << (uVar4 & 0xf);
        iVar10 = iVar10 - (uVar4 & 0xf);
        sVar15 = (short)((int)uVar4 >> 4);
      }
      *local_48 = (short)local_40 + sVar15 & uVar1;
      goto LAB_0098e1ec;
    }
  }
  uVar3 = 0;
  *(int *)(param_1 + 0x24) = iVar16 + 1;
LAB_0098dbc4:
  *(uint *)(param_1 + 0x10) = uVar13;
  *(int *)(param_1 + 0x14) = iVar10;
  *(uint *)(param_1 + 0xc) = uVar12;
  *(uint *)(param_1 + 8) = uVar14;
  *(undefined1 *)(param_1 + 0x18) = (undefined1)local_9c;
  return uVar3;
LAB_0098f57c:
  uVar12 = uVar11;
LAB_0098dd28:
  local_9c._0_1_ = 0;
  goto LAB_0098dbc0;
}


// ===== FUN_0098f788 @ 0098f788

/* WARNING: Type propagation algorithm not settling */

int FUN_0098f788(uint param_1,code *param_2,undefined4 param_3)

{
  char cVar1;
  byte bVar2;
  longlong lVar3;
  longlong lVar4;
  bool bVar5;
  bool bVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  undefined1 uVar11;
  int iVar12;
  int iVar13;
  uint uVar14;
  uint uVar15;
  uint *puVar16;
  uint uVar17;
  int iVar18;
  uint uVar19;
  int iVar20;
  undefined4 *puVar21;
  code **ppcVar22;
  code **ppcVar23;
  byte *pbVar24;
  ushort *puVar25;
  uint uVar26;
  undefined2 *puVar27;
  uint uVar28;
  uint uVar29;
  uint *puVar30;
  undefined2 *puVar31;
  uint uVar32;
  int *piVar33;
  uint *puVar34;
  uint uVar35;
  undefined4 uVar36;
  byte *pbVar37;
  uint uVar38;
  uint uVar39;
  undefined4 uVar40;
  byte bVar41;
  byte *pbVar42;
  undefined4 *puVar43;
  uint uVar44;
  uint uVar45;
  undefined4 uVar46;
  int iVar47;
  uint uVar48;
  bool bVar49;
  undefined8 uVar50;
  uint local_308;
  int local_2ac;
  int local_2a8;
  undefined4 local_2a4;
  undefined4 local_2a0;
  code *local_29c [3];
  int local_290;
  int iStack_28c;
  int local_288;
  char local_280;
  char local_27f;
  char local_27e;
  int local_27c;
  char local_278;
  char local_277;
  undefined1 auStack_270 [4];
  int local_26c;
  uint local_268;
  undefined4 local_264;
  undefined4 local_260;
  int local_25c;
  int local_258;
  undefined4 uStack_254;
  byte abStack_250 [4];
  undefined4 local_24c;
  undefined4 local_248;
  undefined4 local_244;
  undefined4 local_240;
  undefined4 local_23c;
  uint local_238;
  uint local_234;
  uint local_230;
  undefined4 local_22c;
  undefined2 local_228;
  undefined2 local_226;
  uint local_224;
  uint local_220;
  int local_21c;
  
  if ((param_1 & 3) == 0) {
    iVar20 = param_1 + 0x10;
    do {
      *(undefined4 *)(iVar20 + -0x10) = 0;
      *(undefined4 *)(iVar20 + -0xc) = 0;
      *(undefined4 *)(iVar20 + -8) = 0;
      *(undefined4 *)(iVar20 + -4) = 0;
      iVar20 = iVar20 + 0x10;
    } while (param_1 + 0x7ee0 != iVar20);
  }
  else {
    FUN_00997590(param_1,0,0x7ed0);
  }
  *(code **)(param_1 + 0x383c) = param_2;
  *(undefined4 *)(param_1 + 0x3840) = param_3;
  local_29c[1] = param_2;
  local_29c[2] = (code *)param_3;
  iVar20 = (*param_2)(param_3,0,&local_280,0x10);
  if (iVar20 != 0) {
    return -1;
  }
  if ((((local_280 == 'I') && (local_27f == 'I')) && (local_27e == '*')) &&
     ((local_278 == 'C' && (local_277 == 'R')))) {
    *(undefined2 *)(param_1 + 0x42) = 1;
    local_268 = 0;
    iVar20 = FUN_0098d150(local_29c + 1,local_27c,0x112,auStack_270);
    if ((iVar20 == 1) && (iVar20 = FUN_0098d0b4(local_29c + 1,auStack_270,0), iVar20 == 0)) {
      *(short *)(param_1 + 0x42) = (short)local_2ac;
    }
    iVar20 = 3;
    local_2a8 = local_27c;
    do {
      iVar13 = local_2a8;
      iVar12 = (*param_2)(param_3,local_2a8,&local_228,2);
      if (iVar12 != 0) {
        return -2;
      }
      iVar12 = FUN_0098d070(param_2,param_3,iVar13 + (uint)local_228 * 0xc + 2,&local_2a8);
      iVar13 = local_2a8;
      if (iVar12 != 0) {
        return -2;
      }
      if (local_2a8 == 0) {
        return -2;
      }
      iVar20 = iVar20 + -1;
    } while (iVar20 != 0);
    iVar20 = FUN_0098d150(local_29c + 1,local_2a8,0x103,auStack_270);
    if ((((iVar20 == 1) &&
         (iVar20 = FUN_0098d0b4(local_29c + 1,auStack_270,0,&local_2ac), iVar20 == 0)) &&
        ((local_2ac == 6 &&
         (((iVar20 = FUN_0098d150(local_29c + 1,iVar13,0x111,auStack_270), iVar20 == 1 &&
           (iVar20 = FUN_0098d0b4(local_29c + 1,auStack_270,0,param_1 + 0xa8), iVar20 == 0)) &&
          (iVar20 = FUN_0098d150(local_29c + 1,iVar13,0x117,auStack_270), iVar20 == 1)))))) &&
       (local_288 = FUN_0098d0b4(local_29c + 1,auStack_270,0,param_1 + 0xac), local_288 == 0)) {
      local_290 = 0;
      iStack_28c = 0;
      iVar20 = FUN_0098d150(local_29c + 1,iVar13,0xc640,auStack_270);
      uVar28 = local_268;
      bVar6 = false;
      if ((iVar20 == 1) && (local_268 == 3)) {
        piVar33 = &local_290;
        iVar20 = 0;
        do {
          local_268 = uVar28;
          iVar13 = FUN_0098d0b4(local_29c + 1,auStack_270,iVar20,piVar33);
          iVar20 = iVar20 + 1;
          if (iVar13 != 0) {
            return -1;
          }
          piVar33 = piVar33 + 1;
        } while (iVar20 != 3);
        bVar6 = true;
      }
      local_24c = 0;
      local_2a4 = 0;
      local_2a0 = 0;
      local_238 = 0;
      local_234 = 0;
      local_230 = 0;
      local_22c = 0;
      local_248 = 0;
      local_244 = 0;
      local_240 = 0;
      local_23c = 0;
      iVar20 = FUN_0098d29c(local_29c + 1,local_27c,param_1,param_1 + 0x38,&local_24c,&local_2a4,
                            &local_2a0,param_1 + 0x44,param_1 + 0x40);
      uVar10 = local_22c;
      uVar9 = local_230;
      uVar8 = local_234;
      uVar7 = local_238;
      uVar36 = local_2a0;
      if (iVar20 != 0) {
        return iVar20;
      }
      local_224 = 0;
      local_220 = 0;
      local_21c = 0;
      iVar13 = FUN_0098d150(local_29c + 1,local_2a0,0x9003,&local_228);
      iVar20 = local_21c;
      uVar38 = local_220;
      uVar32 = local_224;
      if ((iVar13 == 1) && (local_224 == 2)) {
        uVar14 = local_220;
        if (0x12 < local_220) {
          uVar14 = 0x13;
        }
        *(undefined1 *)(param_1 + 0x48) = 0;
        iVar13 = (*param_2)(param_3,local_21c,param_1 + 0x48,uVar14);
        if (iVar13 == 0) {
          *(undefined1 *)(param_1 + 0x48 + uVar14) = 0;
        }
        else {
          *(undefined1 *)(param_1 + 0x48) = 0;
        }
      }
      local_260 = param_1 + 0x8c;
      local_25c = param_1 + 0x94;
      local_258 = param_1 + 0x9c;
      puVar43 = &local_260;
      puVar27 = &DAT_009a8c68;
      do {
        puVar31 = puVar27 + 1;
        local_224 = uVar32;
        local_220 = uVar38;
        local_21c = iVar20;
        iVar13 = FUN_0098d150(local_29c + 1,uVar36,*puVar27,&local_228);
        iVar20 = local_21c;
        uVar38 = local_220;
        uVar32 = local_224;
        if (((iVar13 == 1) && (local_224 == 5)) && (local_220 != 0)) {
          puVar21 = (undefined4 *)*puVar43;
          iVar13 = FUN_0098d070(param_2,param_3,local_21c);
          if ((iVar13 != 0) ||
             (iVar13 = FUN_0098d070(param_2,param_3,iVar20 + 4,puVar21 + 1), iVar13 != 0)) {
            puVar21[1] = 0;
            *puVar21 = 0;
          }
        }
        puVar43 = puVar43 + 1;
        puVar27 = puVar31;
      } while (puVar31 != (undefined2 *)&UNK_009a8c6e);
      iVar20 = FUN_0098d150(local_29c + 1,uVar36,0x8827,&local_228);
      if ((iVar20 == 1) && (iVar20 = FUN_0098d0b4(local_29c + 1,&local_228,0), iVar20 == 0)) {
        *(code **)(param_1 + 0xa4) = local_29c[0];
      }
      local_268 = uVar28;
      iVar20 = FUN_0098d150(local_29c + 1,local_2a4,0x95,auStack_270);
      if ((iVar20 == 1) && (local_26c == 2)) {
        uVar28 = local_268;
        if (0x2e < local_268) {
          uVar28 = 0x2f;
        }
        *(undefined1 *)(param_1 + 0x5c) = 0;
        iVar20 = (*param_2)(param_3,local_264,param_1 + 0x5c,uVar28);
        if (iVar20 == 0) {
          *(undefined1 *)(param_1 + 0x5c + uVar28) = 0;
        }
        else {
          *(undefined1 *)(param_1 + 0x5c) = 0;
        }
      }
      local_29c[0] = (code *)0x0;
      iVar12 = *(int *)(param_1 + 0xa8);
      iVar13 = *(int *)(param_1 + 0xac);
      iVar20 = (**(code **)(param_1 + 0x383c))
                         (*(undefined4 *)(param_1 + 0x3840),iVar12,&local_228,2);
      if (((iVar20 == 0) && ((byte)local_228 == -1)) && (local_228._1_1_ == -0x28)) {
        uVar32 = iVar12 + iVar13;
        uVar28 = iVar12 + 6;
        if (uVar28 <= uVar32) {
          uVar38 = iVar12 + 2;
          bVar5 = false;
          while ((iVar20 = (**(code **)(param_1 + 0x383c))
                                     (*(undefined4 *)(param_1 + 0x3840),uVar38,&local_228,4),
                 iVar20 == 0 && ((byte)local_228 == -1))) {
            uVar14 = (uint)local_226 * 0x100 + (uint)(local_226 >> 8) & 0xffff;
            uVar44 = uVar14 - 2;
            if (0x200 < uVar44) {
              return -2;
            }
            uVar38 = uVar38 + uVar14 + 2;
            if (uVar32 < uVar38) {
              return -2;
            }
            uVar11 = local_228._1_1_;
            iVar20 = (**(code **)(param_1 + 0x383c))
                               (*(undefined4 *)(param_1 + 0x3840),uVar28,&local_228,uVar44);
            if (iVar20 != 0) {
              return -1;
            }
            switch(uVar11) {
            case 0xc0:
            case 0xc1:
            case 0xc2:
            case 0xd9:
              return -3;
            case 0xc3:
              uVar28 = local_224 >> 8 & 0xff;
              *(uint *)(param_1 + 0xb8) = (uint)CONCAT11(local_228._1_1_,(undefined1)local_226);
              *(uint *)(param_1 + 0xb4) = (uint)CONCAT11(local_226._1_1_,(undefined1)local_224);
              *(uint *)(param_1 + 0xbc) = uVar28;
              *(uint *)(param_1 + 0xb0) = (uint)(byte)local_228;
              if (3 < uVar28 - 1) {
                return -3;
              }
              if (0xe < (byte)local_228 - 2) {
                return -3;
              }
              puVar27 = &local_228;
              ppcVar22 = local_29c;
              do {
                cVar1 = *(char *)((int)puVar27 + 7);
                ppcVar23 = (code **)((int)ppcVar22 + 1);
                *(undefined1 *)ppcVar22 = *(undefined1 *)(puVar27 + 3);
                if (cVar1 != '\x11') {
                  return -3;
                }
                puVar27 = (undefined2 *)((int)puVar27 + 3);
                ppcVar22 = ppcVar23;
              } while ((code **)(uVar28 + (int)local_29c) != ppcVar23);
              bVar5 = true;
              break;
            case 0xc4:
              if (0x10 < uVar44) {
                uVar28 = 0;
                uVar14 = 0x11;
                do {
                  uVar35 = 0;
                  pbVar37 = (byte *)&local_260;
                  bVar2 = *(byte *)((int)&local_228 + uVar28);
                  uVar39 = (uint)bVar2;
                  pbVar24 = (byte *)((int)&local_228 + uVar28);
                  local_260 = 0;
                  local_25c = 0;
                  local_258 = 0;
                  uStack_254 = 0;
                  abStack_250[0] = 0;
                  pbVar42 = pbVar37;
                  do {
                    pbVar24 = pbVar24 + 1;
                    bVar41 = *pbVar24;
                    pbVar42 = pbVar42 + 1;
                    *pbVar42 = bVar41;
                    uVar35 = uVar35 + bVar41;
                  } while (pbVar42 != abStack_250);
                  bVar49 = uVar35 == 0x100;
                  if (uVar35 < 0x101) {
                    bVar49 = (bVar2 & 0xc) == 0;
                  }
                  if (!bVar49) {
                    return -2;
                  }
                  uVar28 = uVar28 + uVar35 + 0x11;
                  if (uVar44 < uVar28) {
                    return -2;
                  }
                  if (bVar2 >> 4 == 0) {
                    puVar43 = (undefined4 *)((int)&local_228 + uVar14);
                    iVar20 = uVar39 * 0xdd4;
                    iVar13 = param_1 + iVar20 + 0xec;
                    if ((param_1 & 3) == 0) {
                      iVar12 = iVar13 + 0x10;
                      do {
                        *(undefined4 *)(iVar12 + -0x10) = 0;
                        *(undefined4 *)(iVar12 + -0xc) = 0;
                        *(undefined4 *)(iVar12 + -8) = 0;
                        *(undefined4 *)(iVar12 + -4) = 0;
                        iVar12 = iVar12 + 0x10;
                      } while (iVar13 + 0xde0 != iVar12);
                      *(undefined4 *)(iVar13 + 0xdd0) = 0;
                    }
                    else {
                      FUN_00997590(iVar13,0,0xdd4);
                    }
                    uVar15 = param_1 + iVar20 + 0xdbc;
                    puVar21 = puVar43;
                    if (((uVar15 | (uint)puVar43) & 3) == 0) {
                      if (0xf < uVar35) {
                        uVar45 = uVar35 & 0xfffffff0;
                        iVar13 = uVar15 + 0x10;
                        do {
                          uVar36 = *puVar21;
                          *(undefined4 *)(iVar13 + -8) = puVar21[2];
                          uVar40 = puVar21[1];
                          uVar46 = puVar21[3];
                          *(undefined4 *)(iVar13 + -0x10) = uVar36;
                          *(undefined4 *)(iVar13 + -0xc) = uVar40;
                          *(undefined4 *)(iVar13 + -4) = uVar46;
                          iVar13 = iVar13 + 0x10;
                          puVar21 = puVar21 + 4;
                        } while (uVar45 + 0x10 + uVar15 != iVar13);
                        uVar35 = uVar35 & 0xf;
                        uVar15 = uVar45 + uVar15;
                        puVar21 = (undefined4 *)((int)puVar43 + uVar45);
                      }
                      if (3 < uVar35) {
                        uVar45 = uVar35 & 0xfffffffc;
                        iVar13 = FUN_009975a8(uVar15,puVar21,uVar45);
                        puVar21 = (undefined4 *)((int)puVar21 + uVar45);
                        uVar15 = iVar13 + uVar45;
                        uVar35 = uVar35 & 3;
                      }
                    }
                    if (uVar35 != 0) {
                      FUN_009975a8(uVar15,puVar21,uVar35);
                    }
                    uVar35 = 0;
                    uVar15 = 1;
                    uVar45 = 8;
                    pbVar42 = (byte *)&local_260;
                    iVar13 = uVar39 * 0x6ea;
                    puVar16 = (uint *)(param_1 + 0xcec + iVar20);
                    local_308 = 0;
                    do {
                      pbVar42 = pbVar42 + 1;
                      bVar2 = *pbVar42;
                      puVar16[0x13] = local_308;
                      puVar16[0x24] = uVar35;
                      if (bVar2 == 0) {
                        uVar48 = 0xffffffff;
                      }
                      else {
                        uVar29 = bVar2 + uVar35;
                        uVar48 = uVar35;
                        while( true ) {
                          if ((uint)(1 << (uVar15 & 0xff)) <= uVar48) {
                            return -2;
                          }
                          if ((int)uVar15 < 10) {
                            bVar2 = *(byte *)((int)puVar43 + uVar48 + (local_308 - uVar35));
                            puVar25 = (ushort *)
                                      (param_1 + 0xea + (iVar13 + (uVar48 << (uVar45 & 0xff))) * 2);
                            do {
                              puVar25 = puVar25 + 1;
                              *puVar25 = (ushort)((uVar15 & 0xff) << 8) | (ushort)bVar2;
                            } while ((ushort *)
                                     (param_1 + 0xea +
                                     (iVar13 + (1 << (uVar45 & 0xff)) + (uVar48 << (uVar45 & 0xff)))
                                     * 2) != puVar25);
                          }
                          uVar26 = uVar48 + 1;
                          if (uVar26 == uVar29) break;
                          uVar48 = uVar26;
                        }
                        local_308 = uVar29 + (local_308 - uVar35);
                        uVar35 = uVar26;
                      }
                      uVar15 = uVar15 + 1;
                      puVar16 = puVar16 + 1;
                      *puVar16 = uVar48;
                      uVar35 = uVar35 << 1;
                      uVar45 = uVar45 - 1;
                    } while (uVar15 != 0x11);
                    iVar12 = 1;
                    iVar20 = 0;
                    iVar47 = 0;
                    do {
                      pbVar37 = pbVar37 + 1;
                      uVar35 = (uint)*pbVar37;
                      if (uVar35 == 0) {
                        iVar18 = iVar20;
                      }
                      else {
                        pbVar42 = (byte *)((int)&local_22c + iVar47 + uVar14 + 3);
                        iVar18 = uVar35 + iVar20;
                        do {
                          while( true ) {
                            pbVar42 = pbVar42 + 1;
                            uVar15 = (uint)*pbVar42;
                            if ((0xf < uVar15) ||
                               ((uVar45 = uVar15 + iVar12, uVar15 != 0 && (10 < uVar45)))) break;
                            uVar26 = 10 - uVar45;
                            uVar29 = 0;
                            uVar48 = uVar45;
                            do {
                              uVar17 = uVar45;
                              if ((uVar15 != 0) &&
                                 (uVar17 = uVar48, (int)uVar29 < 1 << (uVar15 - 1 & 0xff))) {
                                uVar17 = uVar45 + (uVar29 + (-1 << uVar15) + 1) * 0x10;
                              }
                              uVar19 = iVar20 << uVar15 | uVar29;
                              puVar27 = (undefined2 *)
                                        (param_1 + 0x4ea +
                                        (iVar13 + (uVar19 << (uVar26 & 0xff))) * 2);
                              do {
                                puVar27 = puVar27 + 1;
                                *puVar27 = (short)uVar17;
                              } while (puVar27 !=
                                       (undefined2 *)
                                       (param_1 + 0x4ea +
                                       (iVar13 + (1 << (uVar26 & 0xff)) +
                                       (uVar19 << (uVar26 & 0xff))) * 2));
                              uVar29 = uVar29 + 1;
                              uVar48 = uVar48 + 0x10;
                            } while (uVar29 != 1 << uVar15);
                            iVar20 = iVar20 + 1;
                            if (iVar20 == iVar18) goto code_r0x00990550;
                          }
                          iVar20 = iVar20 + 1;
                        } while (iVar20 != iVar18);
code_r0x00990550:
                        iVar47 = iVar47 + uVar35;
                      }
                      iVar12 = iVar12 + 1;
                      iVar20 = iVar18 << 1;
                    } while (iVar12 != 0xb);
                    iVar20 = param_1 + uVar39 * 0xdd4;
                    *(undefined4 *)(iVar20 + 0xd30) = 0x7fffffff;
                    *(undefined1 *)(iVar20 + 0xebc) = 1;
                  }
                  uVar14 = uVar28 + 0x11;
                } while (uVar14 <= uVar44);
              }
              break;
            case 0xda:
              if (!bVar5) {
                return -3;
              }
              uVar28 = *(uint *)(param_1 + 0xbc);
              if ((byte)local_228 != uVar28) {
                return -3;
              }
              if (uVar28 != 0) {
                uVar32 = 0;
                puVar27 = &local_228;
                do {
                  uVar14 = 4;
                  uVar44 = 0;
                  bVar2 = *(byte *)(puVar27 + 1) >> 4;
                  ppcVar22 = local_29c;
                  do {
                    if (*(char *)((int)puVar27 + 1) == *(char *)ppcVar22) {
                      uVar14 = uVar44;
                    }
                    uVar44 = uVar44 + 1;
                    ppcVar22 = (code **)((int)ppcVar22 + 1);
                  } while (uVar28 != uVar44);
                  if (uVar14 == 4 || 3 < bVar2) {
                    return -2;
                  }
                  if (*(char *)(param_1 + (uint)bVar2 * 0xdd4 + 0xebc) == '\0') {
                    return -2;
                  }
                  uVar32 = uVar32 + 1;
                  *(byte *)(param_1 + uVar14 + 0xe8) = bVar2;
                  puVar27 = puVar27 + 1;
                } while (uVar28 != uVar32);
              }
              bVar2 = *(byte *)((int)&local_226 + uVar28 * 2 + 1);
              bVar41 = bVar2 & 0xf;
              if ((bVar2 & 0xf) != 0) {
                bVar41 = 1;
              }
              if (*(char *)((int)&local_228 + uVar28 * 2 + 1) != '\x01') {
                bVar41 = bVar41 | 1;
              }
              if (bVar41 != 0) {
                return -3;
              }
              *(uint *)(param_1 + 0x7eb8) = uVar38;
              uVar28 = *(int *)(param_1 + 0xb4) * uVar28;
              *(uint *)(param_1 + 0xc0) = uVar28;
              if (0x1180 < uVar28) {
                return -3;
              }
              if ((bVar6) && (local_290 != 0)) {
                uVar32 = local_290 + 1;
                if (2 < uVar32) {
                  return -3;
                }
                if (iStack_28c == 0) {
                  return -3;
                }
                if (local_288 == 0) {
                  return -3;
                }
                *(uint *)(param_1 + 0xc4) = uVar32;
                if (uVar32 != 0) {
                  *(undefined4 *)(param_1 + 0xd0) = 0;
                  *(int *)(param_1 + 200) = iStack_28c;
                  *(int *)(param_1 + 0xcc) = local_288;
                  *(int *)(param_1 + 0xd4) = iStack_28c;
                }
                uVar32 = iStack_28c * local_290 + local_288;
              }
              else {
                *(uint *)(param_1 + 200) = uVar28;
                *(undefined4 *)(param_1 + 0xc4) = 1;
                uVar32 = uVar28;
              }
              iVar20 = 0;
              lVar4 = (ulonglong)*(uint *)(param_1 + 0xb8) * (ulonglong)uVar28;
              *(uint *)(param_1 + 0x20) = uVar32;
              uVar38 = uVar32;
              uVar14 = FUN_009a69d8((int)lVar4,(int)((ulonglong)lVar4 >> 0x20));
              lVar3 = CONCAT44(iVar20,uVar38);
              if (iVar20 != 0 || uVar38 != 0) {
                return -3;
              }
              *(uint *)(param_1 + 0x24) = uVar14;
              *(undefined1 *)(param_1 + 0x7ebe) = 0;
              iVar20 = *(int *)(param_1 + 0xc4);
              if (iVar20 != 0) {
                puVar34 = (uint *)(param_1 + 0x7ea8);
                puVar16 = (uint *)(param_1 + 0xc4);
                do {
                  puVar30 = puVar16 + 1;
                  uVar35 = *puVar30;
                  uVar50 = FUN_009a5ce4(uVar28,uVar35);
                  iVar13 = 0;
                  uVar38 = uVar28;
                  uVar44 = FUN_009a69d8((int)lVar3,(int)((ulonglong)lVar3 >> 0x20));
                  lVar3 = (ulonglong)uVar14 * (ulonglong)uVar35 + lVar3;
                  if (((int)((ulonglong)uVar50 >> 0x20) != 0) || (iVar13 != 0 || uVar38 != 0)) {
                    *(undefined1 *)(param_1 + 0x7ebe) = 1;
                  }
                  puVar16[7] = uVar44;
                  puVar34[6] = uVar38;
                  puVar16[5] = (uint)uVar50;
                  puVar34 = puVar34 + 1;
                  *puVar34 = (uint)uVar50;
                  puVar16 = puVar30;
                } while (puVar30 != (uint *)(param_1 + 0xc4) + iVar20);
              }
              if (lVar3 != lVar4) {
                return -3;
              }
              if ((uVar7 < uVar9) && (uVar10 < uVar14 && (uVar8 < uVar10 && uVar9 < uVar32))) {
                *(uint *)(param_1 + 0x28) = uVar7;
                *(uint *)(param_1 + 0x2c) = uVar8;
                uVar32 = (uVar9 + 1) - uVar7;
                uVar14 = (uVar10 + 1) - uVar8;
              }
              *(uint *)(param_1 + 0x30) = uVar32;
              *(uint *)(param_1 + 0x34) = uVar14;
              *(undefined1 *)(param_1 + 0x7ebc) = 1;
              return 0;
            case 0xdd:
              if (local_228 != 0) {
                return -3;
              }
            }
            uVar28 = uVar38 + 4;
            if (uVar32 < uVar28) {
              return -2;
            }
          }
        }
      }
    }
  }
  return -2;
}


// ===== FUN_009906b4 @ 009906b4

undefined4 FUN_009906b4(int param_1,int param_2,undefined4 param_3,code *param_4,undefined4 param_5)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  uint uVar5;
  undefined4 *puVar6;
  undefined1 *puVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  undefined1 *puVar11;
  undefined1 *puVar12;
  undefined4 *puVar13;
  uint uVar14;
  int iVar15;
  uint uVar16;
  int *piVar17;
  int iVar18;
  undefined1 *puVar19;
  undefined1 *puVar20;
  uint uVar21;
  bool bVar22;
  uint local_3c;
  
  if (*(char *)(param_1 + 0x7ebc) != '\0') {
    if ((param_4 != (code *)0x0) && (*(char *)(param_1 + 0x7ebe) != '\0')) {
      return 0xfffffffd;
    }
    uVar14 = *(uint *)(param_1 + 0xc4);
    uVar1 = FUN_009a5bf0(param_3,uVar14);
    uVar1 = uVar1 & 0xffffffe0;
    if (param_2 != 0 && 0xfff < uVar1) {
      bVar22 = uVar14 != 1;
      *(uint *)(param_1 + 0x3878) = uVar1;
      if (bVar22) {
        *(uint *)(param_1 + 0x38a8) = uVar1;
      }
      *(int *)(param_1 + 0x3874) = param_2;
      if (bVar22) {
        param_2 = param_2 + uVar1;
      }
      if (bVar22) {
        *(int *)(param_1 + 0x38a4) = param_2;
      }
      *(undefined4 *)(param_1 + 0x384c) = *(undefined4 *)(param_1 + 0x7eb8);
      puVar20 = (undefined1 *)(param_1 + 0x384c);
      local_3c = 1;
      iVar18 = param_1 + uVar14 * 0x2300 + 0x15ac;
      *(int *)(param_1 + 0x3850) = *(int *)(param_1 + 0xa8) + *(int *)(param_1 + 0xac);
      piVar17 = (int *)(param_1 + 200);
      puVar11 = (undefined1 *)(param_1 + 0x387c);
      do {
        uVar1 = *(uint *)(param_1 + 0x3870);
        if (local_3c < uVar14) {
          uVar14 = piVar17[7];
joined_r0x009907b8:
          while (uVar1 < uVar14) {
            iVar2 = FUN_0098d858(puVar20,param_1,iVar18);
            if (iVar2 != 0) {
              return 0xfffffffc;
            }
            if ((param_4 != (code *)0x0) && (iVar2 = piVar17[4], iVar2 != 0)) {
              iVar10 = piVar17[6];
              iVar15 = 0;
              do {
                iVar8 = iVar15 * *piVar17;
                iVar9 = iVar2 * (uVar1 - iVar10) + iVar15;
                iVar15 = iVar15 + 1;
                (*param_4)(param_5,iVar9,piVar17[2],iVar18 + iVar8 * 2,*piVar17);
              } while (iVar2 != iVar15);
            }
            uVar1 = *(uint *)(param_1 + 0x3870);
            if ((*(code **)(param_1 + 0x3844) != (code *)0x0) && ((uVar1 & 0x3f) == 0)) {
              iVar2 = (**(code **)(param_1 + 0x3844))(*(undefined4 *)(param_1 + 0x3848));
              if (iVar2 != 0) {
                return 0xfffffffa;
              }
              uVar1 = *(uint *)(param_1 + 0x3870);
            }
          }
        }
        else if (param_4 != (code *)0x0) {
          uVar14 = *(uint *)(param_1 + 0xb8);
          goto joined_r0x009907b8;
        }
        if (*(uint *)(param_1 + 0xc4) == local_3c) {
          *(undefined4 *)(param_1 + 0x384c) = *(undefined4 *)(param_1 + 0x7eb8);
          *(undefined4 *)(param_1 + 0x3858) = 0;
          *(undefined4 *)(param_1 + 0x3854) = 0;
          *(undefined4 *)(param_1 + 0x385c) = 0;
          *(undefined4 *)(param_1 + 0x3860) = 0;
          *(undefined1 *)(param_1 + 0x3864) = 0;
          *(undefined4 *)(param_1 + 0x3870) = 0;
          *(undefined2 *)(param_1 + 0x3866) = 0;
          *(undefined4 *)(param_1 + 0x3868) = 0;
          *(undefined2 *)(param_1 + 0x386c) = 0;
          goto LAB_00990a48;
        }
        uVar14 = *(int *)(param_1 + 0x3854) - *(int *)(param_1 + 0x3858);
        uVar16 = *(uint *)(puVar11 + 0x28);
        uVar3 = *(undefined4 *)(puVar11 + 0x2c);
        if ((((uint)puVar20 | (uint)puVar11) & 3) == 0) {
          iVar2 = param_1 + 0x385c;
          puVar7 = puVar11 + 0x10;
          do {
            puVar12 = puVar7 + 0x10;
            *(undefined4 *)(puVar7 + -0x10) = *(undefined4 *)(iVar2 + -0x10);
            *(undefined4 *)(puVar7 + -0xc) = *(undefined4 *)(iVar2 + -0xc);
            *(undefined4 *)(puVar7 + -8) = *(undefined4 *)(iVar2 + -8);
            *(undefined4 *)(puVar7 + -4) = *(undefined4 *)(iVar2 + -4);
            iVar2 = iVar2 + 0x10;
            puVar7 = puVar12;
          } while (puVar12 != puVar11 + 0x40);
        }
        else {
          puVar12 = puVar11 + -1;
          puVar7 = puVar20;
          do {
            puVar19 = puVar7 + 1;
            puVar12 = puVar12 + 1;
            *puVar12 = *puVar7;
            puVar7 = puVar19;
          } while (puVar19 != (undefined1 *)(param_1 + 0x387c));
        }
        *(undefined4 *)(puVar11 + 0x2c) = uVar3;
        *(uint *)(puVar11 + 0x28) = uVar16;
        puVar13 = (undefined4 *)(*(int *)(param_1 + 0x3874) + *(int *)(param_1 + 0x3858));
        uVar21 = uVar14;
        if (((uVar16 | (uint)puVar13) & 3) == 0) {
          if (0xf < uVar14) {
            uVar21 = uVar14 & 0xfffffff0;
            puVar4 = puVar13 + 4;
            iVar2 = uVar16 + 0x10;
            do {
              iVar15 = iVar2 + 0x10;
              *(undefined4 *)(iVar2 + -0x10) = puVar4[-4];
              *(undefined4 *)(iVar2 + -0xc) = puVar4[-3];
              *(undefined4 *)(iVar2 + -8) = puVar4[-2];
              *(undefined4 *)(iVar2 + -4) = puVar4[-1];
              puVar4 = puVar4 + 4;
              iVar2 = iVar15;
            } while (iVar15 != uVar16 + uVar21 + 0x10);
            puVar13 = (undefined4 *)((uVar21 - 0x10) + (int)(puVar13 + 4));
            uVar16 = uVar16 + uVar21;
            uVar21 = uVar14 & 0xf;
          }
          if (3 < uVar21) {
            uVar5 = uVar21 & 0xfffffffc;
            iVar2 = uVar5 - 4;
            puVar6 = (undefined4 *)(uVar16 - 4);
            puVar4 = puVar13;
            do {
              puVar6 = puVar6 + 1;
              *puVar6 = *puVar4;
              puVar4 = puVar4 + 1;
            } while ((undefined4 *)(uVar16 + iVar2) != puVar6);
            uVar21 = uVar21 & 3;
            puVar13 = (undefined4 *)((int)puVar13 + uVar5);
            uVar16 = uVar16 + 4 + iVar2;
          }
        }
        if (uVar21 != 0) {
          puVar7 = (undefined1 *)(uVar16 - 1);
          puVar4 = puVar13;
          do {
            puVar6 = (undefined4 *)((int)puVar4 + 1);
            puVar7 = puVar7 + 1;
            *puVar7 = *(undefined1 *)puVar4;
            puVar4 = puVar6;
          } while ((undefined4 *)((int)puVar13 + uVar21) != puVar6);
        }
        *(uint *)(puVar11 + 0x24) = uVar1;
        *(uint *)(puVar11 + 8) = uVar14;
        *(undefined4 *)(puVar11 + 0xc) = 0;
        uVar14 = *(uint *)(param_1 + 0xc4);
        local_3c = local_3c + 1;
        puVar11 = puVar11 + 0x30;
        piVar17 = piVar17 + 1;
        if (uVar14 < local_3c) {
          *(undefined4 *)(param_1 + 0x384c) = *(undefined4 *)(param_1 + 0x7eb8);
          *(undefined4 *)(param_1 + 0x3858) = 0;
          *(undefined4 *)(param_1 + 0x3854) = 0;
          *(undefined4 *)(param_1 + 0x385c) = 0;
          *(undefined4 *)(param_1 + 0x3860) = 0;
          *(undefined1 *)(param_1 + 0x3864) = 0;
          *(undefined4 *)(param_1 + 0x3870) = 0;
          *(undefined2 *)(param_1 + 0x3866) = 0;
          *(undefined4 *)(param_1 + 0x3868) = 0;
          *(undefined2 *)(param_1 + 0x386c) = 0;
          local_3c = uVar14;
          if (uVar14 != 0) {
LAB_00990a48:
            uVar3 = *(undefined4 *)(param_1 + 0xc0);
            FUN_009975a8(param_1 + 0x7eac,param_1 + 0xd8,local_3c << 2);
            *(undefined4 *)(param_1 + 0x7ec8) = uVar3;
            if (local_3c == 2) {
              *(undefined4 *)(param_1 + 0x7ecc) = uVar3;
            }
          }
          *(undefined4 *)(param_1 + 0x7eb4) = 0;
          *(undefined1 *)(param_1 + 0x7ebd) = 1;
          return 0;
        }
      } while( true );
    }
  }
  return 0xfffffffb;
}


// ===== FUN_00990b2c @ 00990b2c

void FUN_00990b2c(int param_1,undefined4 *param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined4 *puVar5;
  int *piVar6;
  
  if (((uint)param_2 & 3) == 0) {
    puVar5 = param_2 + 4;
    do {
      puVar5[-4] = 0;
      puVar5[-3] = 0;
      puVar5[-2] = 0;
      puVar5[-1] = 0;
      puVar5 = puVar5 + 4;
    } while (puVar5 != param_2 + 0x14);
    param_2[0x10] = 0;
  }
  else {
    FUN_00997590(param_2,0,0x44);
  }
  *param_2 = *(undefined4 *)(param_1 + 0xc4);
  param_2[1] = *(undefined4 *)(param_1 + 0xa8);
  param_2[2] = *(undefined4 *)(param_1 + 0xac);
  if (*(int *)(param_1 + 0xc4) == 0) {
    return;
  }
  uVar4 = 0;
  piVar6 = (int *)(param_1 + 0x384c);
  do {
    param_2[3] = (*piVar6 + piVar6[3]) - piVar6[2];
    param_2[4] = piVar6[4];
    param_2[6] = piVar6[5];
    uVar4 = uVar4 + 1;
    *(char *)(param_2 + 9) = (char)piVar6[6];
    iVar2 = piVar6[9];
    *(undefined2 *)(param_2 + 7) = *(undefined2 *)((int)piVar6 + 0x1a);
    iVar1 = piVar6[7];
    param_2[5] = iVar2;
    *(short *)((int)param_2 + 0x1e) = (short)iVar1;
    uVar3 = *(uint *)(param_1 + 0xc4);
    *(undefined2 *)(param_2 + 8) = *(undefined2 *)((int)piVar6 + 0x1e);
    *(short *)((int)param_2 + 0x22) = (short)piVar6[8];
    piVar6 = piVar6 + 0xc;
    param_2 = param_2 + 7;
  } while (uVar4 < uVar3);
  return;
}


// ===== FUN_00990b30 @ 00990b30

void FUN_00990b30(int param_1,undefined4 *param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined4 *puVar5;
  int *piVar6;
  bool in_ZR;
  
  if (in_ZR) {
    puVar5 = param_2 + 4;
    do {
      puVar5[-4] = param_3;
      puVar5[-3] = param_3;
      puVar5[-2] = param_3;
      puVar5[-1] = param_3;
      puVar5 = puVar5 + 4;
    } while (puVar5 != param_2 + 0x14);
    param_2[0x10] = param_3;
  }
  else {
    FUN_00997590(param_2,0,0x44);
  }
  *param_2 = *(undefined4 *)(param_1 + 0xc4);
  param_2[1] = *(undefined4 *)(param_1 + 0xa8);
  param_2[2] = *(undefined4 *)(param_1 + 0xac);
  if (*(int *)(param_1 + 0xc4) == 0) {
    return;
  }
  uVar4 = 0;
  piVar6 = (int *)(param_1 + 0x384c);
  do {
    param_2[3] = (*piVar6 + piVar6[3]) - piVar6[2];
    param_2[4] = piVar6[4];
    param_2[6] = piVar6[5];
    uVar4 = uVar4 + 1;
    *(char *)(param_2 + 9) = (char)piVar6[6];
    iVar2 = piVar6[9];
    *(undefined2 *)(param_2 + 7) = *(undefined2 *)((int)piVar6 + 0x1a);
    iVar1 = piVar6[7];
    param_2[5] = iVar2;
    *(short *)((int)param_2 + 0x1e) = (short)iVar1;
    uVar3 = *(uint *)(param_1 + 0xc4);
    *(undefined2 *)(param_2 + 8) = *(undefined2 *)((int)piVar6 + 0x1e);
    *(short *)((int)param_2 + 0x22) = (short)piVar6[8];
    piVar6 = piVar6 + 0xc;
    param_2 = param_2 + 7;
  } while (uVar4 < uVar3);
  return;
}


// ===== FUN_00990c24 @ 00990c24

undefined4 FUN_00990c24(int param_1,uint param_2,undefined4 param_3,uint *param_4)

{
  undefined2 *puVar1;
  uint uVar2;
  uint *puVar3;
  uint uVar4;
  uint uVar5;
  undefined4 uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  
  if ((((*(char *)(param_1 + 0x7ebc) != '\0') &&
       (uVar4 = *(uint *)(param_1 + 0xc4), *param_4 == uVar4)) &&
      (uVar7 = param_4[1], uVar7 == *(uint *)(param_1 + 0xa8))) &&
     (uVar5 = param_4[2], uVar5 == *(uint *)(param_1 + 0xac))) {
    uVar2 = FUN_009a5bf0(param_3,uVar4);
    uVar2 = uVar2 & 0xffffffe0;
    if (param_2 != 0 && 0xfff < uVar2) {
      uVar9 = 0;
      puVar3 = (uint *)(param_1 + 0x384c);
      do {
        puVar3[0xb] = uVar2;
        uVar8 = param_4[3];
        puVar3[1] = uVar7 + uVar5;
        *puVar3 = uVar8;
        puVar3[3] = 0;
        puVar3[2] = 0;
        uVar8 = param_4[4];
        puVar3[10] = param_2;
        puVar3[4] = uVar8;
        uVar9 = uVar9 + 1;
        puVar3[5] = param_4[6];
        *(char *)(puVar3 + 6) = (char)param_4[9];
        uVar8 = param_4[5];
        *(short *)((int)puVar3 + 0x1a) = (short)param_4[7];
        puVar3[9] = uVar8;
        param_2 = param_2 + uVar2;
        *(undefined2 *)(puVar3 + 7) = *(undefined2 *)((int)param_4 + 0x1e);
        *(short *)((int)puVar3 + 0x1e) = (short)param_4[8];
        puVar1 = (undefined2 *)((int)param_4 + 0x22);
        param_4 = param_4 + 7;
        *(undefined2 *)(puVar3 + 8) = *puVar1;
        puVar3 = puVar3 + 0xc;
      } while (uVar9 < uVar4);
      uVar6 = *(undefined4 *)(param_1 + 0xc0);
      FUN_009975a8(param_1 + 0x7eac,param_1 + 0xd8,uVar4 << 2);
      *(undefined4 *)(param_1 + 0x7ec8) = uVar6;
      if (uVar4 == 2) {
        *(undefined4 *)(param_1 + 0x7ecc) = uVar6;
      }
      *(undefined4 *)(param_1 + 0x7eb4) = 0;
      *(undefined1 *)(param_1 + 0x7ebd) = 1;
      return 0;
    }
  }
  return 0xfffffffb;
}


// ===== FUN_00990d70 @ 00990d70

void FUN_00990d70(int param_1)

{
  int iVar1;
  undefined4 in_stack_00000000;
  
  iVar1 = FUN_00990c24();
  if (iVar1 == 0) {
    *(undefined4 *)(param_1 + 0x7eb4) = in_stack_00000000;
  }
  return;
}


// ===== FUN_00990d90 @ 00990d90

undefined4 FUN_00990d90(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  
  iVar2 = *(int *)(param_1 + 0xc4);
  if (iVar2 != 0) {
    piVar4 = (int *)(param_1 + 0x7eac);
    if (*(char *)(param_1 + 0x7ebe) == '\0') {
      iVar3 = 0;
      do {
        iVar1 = iVar3 * 4;
        iVar3 = iVar3 + 1;
        if (*piVar4 != *(int *)(param_1 + 0xd8 + iVar1)) {
          return 0;
        }
        piVar4 = piVar4 + 1;
      } while (iVar2 != iVar3);
      return 1;
    }
    iVar3 = 0;
    do {
      iVar3 = iVar3 + 1;
      if (piVar4[7] != *(int *)(param_1 + 0xc0)) {
        return 0;
      }
      piVar4 = piVar4 + 1;
    } while (iVar2 != iVar3);
  }
  return 1;
}


// ===== FUN_00990e24 @ 00990e24

undefined4 FUN_00990e24(int param_1,int param_2)

{
  uint uVar1;
  int *piVar2;
  uint uVar3;
  undefined1 *puVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  int *piVar10;
  int *piVar11;
  uint uVar12;
  int iVar13;
  int iVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  undefined4 *puVar18;
  undefined4 *puVar19;
  uint local_40;
  int local_38;
  uint *local_34;
  
  if ((*(char *)(param_1 + 0x7ebd) == '\0') ||
     (local_40 = *(uint *)(param_1 + 0x7eb4), *(uint *)(param_1 + 0x24) <= local_40)) {
    return 0xfffffffb;
  }
  if (*(char *)(param_1 + 0x7ebe) == '\0') {
    if (*(int *)(param_1 + 0xc4) == 0) goto LAB_00990fbc;
    piVar11 = (int *)(param_1 + 0xc4);
    iVar14 = param_1 + 0x38ac;
    iVar13 = param_1 + 0x384c;
    piVar10 = (int *)(param_1 + 0x7ea8);
    uVar12 = 0;
    do {
      piVar10 = piVar10 + 1;
      iVar7 = *piVar10;
      if (iVar7 == piVar11[5]) {
        iVar7 = FUN_0098d858(iVar13,param_1,iVar14);
        if (iVar7 != 0) {
          return 0xfffffffc;
        }
        *piVar10 = 0;
        iVar7 = 0;
      }
      piVar2 = piVar11 + 3;
      piVar11 = piVar11 + 1;
      uVar3 = param_2 + *piVar2 * 2;
      uVar16 = *piVar11 * 2;
      puVar8 = (undefined4 *)(uVar16 * iVar7 + iVar14);
      if (((uVar3 | (uint)puVar8) & 3) == 0) {
        if (0xf < uVar16) {
          uVar16 = (*piVar11 + -8) * 2;
          uVar17 = uVar16 & 0xfffffff0;
          iVar7 = uVar3 + 0x10;
          puVar9 = puVar8;
          do {
            iVar6 = iVar7 + 0x10;
            *(undefined4 *)(iVar7 + -0x10) = *puVar9;
            *(undefined4 *)(iVar7 + -0xc) = puVar9[1];
            *(undefined4 *)(iVar7 + -8) = puVar9[2];
            *(undefined4 *)(iVar7 + -4) = puVar9[3];
            iVar7 = iVar6;
            puVar9 = puVar9 + 4;
          } while (iVar6 != uVar3 + 0x20 + uVar17);
          uVar3 = uVar3 + 0x10 + uVar17;
          uVar16 = uVar16 - uVar17;
          puVar8 = (undefined4 *)((int)puVar8 + uVar17 + 0x10);
        }
        if (3 < uVar16) {
          uVar17 = uVar16 & 0xfffffffc;
          iVar7 = uVar17 - 4;
          puVar18 = (undefined4 *)(uVar3 - 4);
          puVar9 = puVar8;
          do {
            puVar18 = puVar18 + 1;
            *puVar18 = *puVar9;
            puVar9 = puVar9 + 1;
          } while (puVar18 != (undefined4 *)(uVar3 + iVar7));
          uVar16 = uVar16 & 3;
          uVar3 = uVar3 + 4 + iVar7;
          puVar8 = (undefined4 *)((int)puVar8 + uVar17);
        }
      }
      if (uVar16 != 0) {
        puVar4 = (undefined1 *)(uVar3 - 1);
        puVar9 = puVar8;
        do {
          puVar18 = (undefined4 *)((int)puVar9 + 1);
          puVar4 = puVar4 + 1;
          *puVar4 = *(undefined1 *)puVar9;
          puVar9 = puVar18;
        } while (puVar18 != (undefined4 *)((int)puVar8 + uVar16));
      }
      uVar12 = uVar12 + 1;
      *piVar10 = *piVar10 + 1;
      iVar14 = iVar14 + 0x2300;
      iVar13 = iVar13 + 0x30;
    } while (uVar12 < *(uint *)(param_1 + 0xc4));
  }
  else {
    if (*(int *)(param_1 + 0xc4) == 0) goto LAB_00990fbc;
    uVar12 = 0;
    local_34 = (uint *)(param_1 + 0xc4);
    local_38 = param_1 + 0x384c;
    puVar8 = (undefined4 *)(param_1 + 0x38ac);
    piVar10 = (int *)(param_1 + 0x7ec0);
    do {
      uVar3 = local_34[3];
      local_34 = local_34 + 1;
      uVar16 = *local_34;
      if (local_40 == 0) {
        piVar10[2] = *(int *)(param_1 + 0xc0);
      }
      if (uVar16 != 0) {
        iVar13 = piVar10[2];
        uVar3 = param_2 + uVar3 * 2;
        do {
          iVar14 = *(int *)(param_1 + 0xc0);
          if (iVar14 == iVar13) {
            if ((local_40 == 0) && (*local_34 == uVar16)) {
              iVar13 = FUN_0098d858(local_38,param_1,puVar8);
              if (iVar13 != 0) {
                return 0xfffffffc;
              }
              iVar13 = *piVar10;
              puVar9 = (undefined4 *)((int)puVar8 + iVar13 * 2);
            }
            else {
              iVar13 = FUN_0098d858(local_38,param_1,puVar8);
              if (iVar13 != 0) {
                return 0xfffffffc;
              }
              iVar13 = 0;
              puVar9 = puVar8;
            }
            piVar10[2] = iVar13;
            iVar14 = *(int *)(param_1 + 0xc0);
          }
          else {
            puVar9 = (undefined4 *)((int)puVar8 + iVar13 * 2);
          }
          uVar17 = iVar14 - iVar13;
          if (uVar16 <= (uint)(iVar14 - iVar13)) {
            uVar17 = uVar16;
          }
          uVar1 = uVar17 * 2;
          uVar5 = uVar1;
          uVar15 = uVar3;
          if (((uVar3 | (uint)puVar9) & 3) == 0) {
            if (0xf < uVar1) {
              uVar5 = (uVar17 - 8) * 2;
              uVar15 = uVar5 & 0xfffffff0;
              puVar18 = puVar9 + 4;
              iVar13 = uVar3 + 0x10;
              do {
                iVar14 = iVar13 + 0x10;
                *(undefined4 *)(iVar13 + -0x10) = puVar18[-4];
                *(undefined4 *)(iVar13 + -0xc) = puVar18[-3];
                *(undefined4 *)(iVar13 + -8) = puVar18[-2];
                *(undefined4 *)(iVar13 + -4) = puVar18[-1];
                puVar18 = puVar18 + 4;
                iVar13 = iVar14;
              } while (iVar14 != uVar3 + 0x20 + uVar15);
              puVar9 = (undefined4 *)((int)(puVar9 + 4) + uVar15);
              uVar5 = uVar5 - uVar15;
              uVar15 = uVar3 + 0x10 + uVar15;
            }
            if (3 < uVar5) {
              iVar13 = (uVar5 & 0xfffffffc) - 4;
              puVar19 = (undefined4 *)(uVar15 - 4);
              puVar18 = puVar9;
              do {
                puVar19 = puVar19 + 1;
                *puVar19 = *puVar18;
                puVar18 = puVar18 + 1;
              } while (puVar19 != (undefined4 *)(uVar15 + iVar13));
              puVar9 = (undefined4 *)((int)puVar9 + (uVar5 & 0xfffffffc));
              uVar5 = uVar5 & 3;
              uVar15 = uVar15 + 4 + iVar13;
            }
          }
          if (uVar5 != 0) {
            puVar4 = (undefined1 *)(uVar15 - 1);
            puVar18 = puVar9;
            do {
              puVar19 = (undefined4 *)((int)puVar18 + 1);
              puVar4 = puVar4 + 1;
              *puVar4 = *(undefined1 *)puVar18;
              puVar18 = puVar19;
            } while (puVar19 != (undefined4 *)((int)puVar9 + uVar5));
          }
          uVar3 = uVar3 + uVar1;
          uVar16 = uVar16 - uVar17;
          iVar13 = uVar17 + piVar10[2];
          piVar10[2] = iVar13;
        } while (uVar16 != 0);
      }
      uVar12 = uVar12 + 1;
      local_38 = local_38 + 0x30;
      puVar8 = puVar8 + 0x8c0;
      piVar10 = piVar10 + 1;
    } while (uVar12 < *(uint *)(param_1 + 0xc4));
  }
  local_40 = *(uint *)(param_1 + 0x7eb4);
LAB_00990fbc:
  *(uint *)(param_1 + 0x7eb4) = local_40 + 1;
  return 0;
}


// ===== FUN_00991240 @ 00991240

int FUN_00991240(int param_1,int param_2,int param_3,undefined4 param_4,uint param_5,int param_6)

{
  longlong lVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  ushort *puVar5;
  
  if (param_6 < (int)(uint)(param_5 < 0x100000)) {
    uVar2 = FUN_009a5bf0(param_5 << 0xc,param_3);
  }
  else {
    uVar2 = FUN_009a6904(param_5 << 0xc,param_6 << 0xc | param_5 >> 0x14,param_3,param_3 >> 0x1f);
  }
  iVar4 = *(int *)(param_1 + param_2 * 4 + 0x25c);
  if ((int)uVar2 >> 4 < 0x3ff) {
    puVar5 = (ushort *)(iVar4 + ((int)uVar2 >> 4) * 2);
    uVar3 = (uint)*puVar5;
    uVar3 = uVar3 + ((int)((uVar2 & 0xf) * (puVar5[1] - uVar3) + 8) >> 4);
  }
  else {
    uVar3 = (uint)*(ushort *)(iVar4 + 0x7fe);
  }
  lVar1 = (longlong)param_3 * (longlong)(int)uVar3 + 0x800;
  return param_3 - ((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14);
}


// ===== FUN_009912ec @ 009912ec

void FUN_009912ec(int param_1,uint param_2,uint param_3,int param_4)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  char *pcVar9;
  int iVar10;
  uint *puVar11;
  char *pcVar12;
  uint uVar13;
  char *local_84;
  char *local_80;
  int local_7c;
  uint local_78;
  int local_74;
  uint local_70;
  int local_6c;
  int local_64;
  int local_60;
  uint local_5c;
  uint local_4c;
  int local_48;
  int local_44;
  uint local_40;
  int local_3c;
  int local_38;
  uint local_34;
  int local_30;
  int local_2c;
  
  uVar13 = 0;
  uVar8 = 0x6fd1ddb3;
  if (param_4 == 1) {
    uVar8 = 0x2545f491;
  }
  uVar1 = *(uint *)(param_1 + 0x17c2c);
  puVar11 = &local_4c;
  do {
    uVar4 = param_3 * -0x61c88647 ^ uVar1 ^ uVar13;
    uVar4 = (uVar4 ^ uVar4 >> 0x10) * -0x7a143595;
    uVar5 = (uVar4 ^ uVar4 >> 0xd) * -0x3d4d51cb;
    uVar4 = uVar5 ^ uVar5 >> 0x10;
    uVar4 = uVar4 ^ uVar4 << 0xd;
    uVar4 = uVar4 ^ uVar4 >> 0x11;
    uVar4 = uVar4 ^ uVar4 << 5;
    if (uVar5 == uVar5 >> 0x10) {
      uVar5 = 0xfffffff8;
      uVar3 = 5;
      uVar4 = 0x40aec71f;
    }
    else {
      uVar5 = (uint)(char)(&DAT_009a8f7c)[uVar4 & 0xff];
      uVar3 = (uint)(char)(&DAT_009a8f7c)[uVar4 >> 8 & 0xff];
    }
    uVar13 = uVar13 + 0x2545f491;
    *puVar11 = uVar4;
    puVar11[1] = uVar5;
    puVar11[2] = uVar3;
    puVar11 = puVar11 + 3;
  } while (uVar8 != uVar13);
  if (param_2 != 0) {
    uVar8 = 0;
    if ((param_3 & 1) != 0) {
      uVar8 = 0xffffffff;
    }
    uVar13 = 0;
    if ((param_3 + 3 & 1) != 0) {
      uVar13 = 0xffffffff;
    }
    local_7c = param_1 + 0x1af78;
    local_70 = local_4c;
    local_74 = param_1 + 0x1d1a8;
    local_80 = (char *)(param_1 + (uVar8 & 0x19a4) + 0x17c32);
    local_84 = (char *)(param_1 + (uVar13 & 0x19a4) + 0x17c32);
    local_64 = local_2c;
    local_60 = local_3c;
    local_5c = local_34;
    local_6c = local_48;
    local_78 = param_2;
    do {
      uVar8 = local_78;
      if (0xff < local_78) {
        uVar8 = 0x100;
      }
      uVar8 = (uVar8 + 3 & 0xfffffffc) - 1 >> 2;
      pcVar12 = local_80 + 10;
      pcVar9 = local_84 + 10;
      iVar7 = local_7c + 0x10;
      do {
        local_70 = local_70 ^ local_70 << 0xd;
        local_70 = local_70 ^ local_70 >> 0x11;
        local_70 = local_70 ^ local_70 << 5;
        iVar6 = (int)(char)(&DAT_009a8f7c)[local_70 & 0xff];
        iVar2 = local_6c + local_44 * 4 + iVar6;
        *(short *)(iVar7 + -0x10) = (short)pcVar12[-0xc] + pcVar9[-0xc] * 4 + (short)iVar2;
        pcVar12[-0xc] = (char)iVar2;
        iVar10 = (int)(char)(&DAT_009a8f7c)[local_70 >> 8 & 0xff];
        iVar2 = local_44 + iVar6 * 4 + iVar10;
        *(short *)(iVar7 + -0xc) = (short)pcVar12[-9] + pcVar9[-9] * 4 + (short)iVar2;
        pcVar12[-9] = (char)iVar2;
        local_6c = (int)(char)(&DAT_009a8f7c)[local_70 >> 0x10 & 0xff];
        iVar2 = iVar6 + iVar10 * 4 + local_6c;
        *(short *)(iVar7 + -8) = (short)pcVar12[-6] + pcVar9[-6] * 4 + (short)iVar2;
        pcVar12[-6] = (char)iVar2;
        local_44 = (int)(char)(&DAT_009a8f7c)[local_70 >> 0x18];
        iVar2 = iVar10 + local_6c * 4 + local_44;
        *(short *)(iVar7 + -4) = (short)pcVar12[-3] + pcVar9[-3] * 4 + (short)iVar2;
        iVar7 = iVar7 + 0x10;
        pcVar12[-3] = (char)iVar2;
        pcVar9 = pcVar9 + 0xc;
        pcVar12 = pcVar12 + 0xc;
      } while (local_7c + 0x20 + uVar8 * 0x10 != iVar7);
      if (param_4 != 1) {
        pcVar12 = local_80 + 0xb;
        iVar7 = local_7c + 0x12;
        pcVar9 = local_84 + 0xb;
        do {
          uVar13 = local_40 ^ local_40 << 0xd;
          uVar13 = uVar13 ^ uVar13 >> 0x11;
          local_40 = uVar13 ^ uVar13 << 5;
          iVar2 = (int)(char)(&DAT_009a8f7c)[local_40 & 0xff];
          iVar6 = local_60 + local_38 * 4 + iVar2;
          *(short *)(iVar7 + -0x10) = (short)pcVar12[-0xc] + pcVar9[-0xc] * 4 + (short)iVar6;
          pcVar12[-0xc] = (char)iVar6;
          iVar6 = (int)(char)(&DAT_009a8f7c)[local_40 >> 8 & 0xff];
          iVar10 = local_38 + iVar2 * 4 + iVar6;
          *(short *)(iVar7 + -0xc) = (short)pcVar12[-9] + pcVar9[-9] * 4 + (short)iVar10;
          pcVar12[-9] = (char)iVar10;
          local_60 = (int)(char)(&DAT_009a8f7c)[local_40 >> 0x10 & 0xff];
          iVar2 = iVar2 + iVar6 * 4 + local_60;
          *(short *)(iVar7 + -8) = (short)pcVar12[-6] + pcVar9[-6] * 4 + (short)iVar2;
          pcVar12[-6] = (char)iVar2;
          local_38 = (int)(char)(&DAT_009a8f7c)[local_40 >> 0x18];
          iVar2 = iVar6 + local_60 * 4 + local_38;
          *(short *)(iVar7 + -4) = (short)pcVar12[-3] + pcVar9[-3] * 4 + (short)iVar2;
          iVar7 = iVar7 + 0x10;
          pcVar12[-3] = (char)iVar2;
          pcVar9 = pcVar9 + 0xc;
          pcVar12 = pcVar12 + 0xc;
        } while (local_7c + 0x22 + uVar8 * 0x10 != iVar7);
        iVar7 = local_74 + 8;
        pcVar9 = local_80;
        pcVar12 = local_84;
        do {
          local_5c = local_5c ^ local_5c << 0xd;
          local_5c = local_5c ^ local_5c >> 0x11;
          local_5c = local_5c ^ local_5c << 5;
          iVar6 = (int)(char)(&DAT_009a8f7c)[local_5c & 0xff];
          iVar2 = local_30 + local_64 * 4 + iVar6;
          *(short *)(iVar7 + -8) = (short)*pcVar9 + *pcVar12 * 4 + (short)iVar2;
          *pcVar9 = (char)iVar2;
          iVar10 = (int)(char)(&DAT_009a8f7c)[local_5c >> 8 & 0xff];
          iVar2 = local_64 + iVar6 * 4 + iVar10;
          *(short *)(iVar7 + -6) = (short)pcVar9[3] + pcVar12[3] * 4 + (short)iVar2;
          pcVar9[3] = (char)iVar2;
          local_30 = (int)(char)(&DAT_009a8f7c)[local_5c >> 0x10 & 0xff];
          iVar2 = iVar6 + iVar10 * 4 + local_30;
          *(short *)(iVar7 + -4) = (short)pcVar9[6] + pcVar12[6] * 4 + (short)iVar2;
          pcVar9[6] = (char)iVar2;
          local_64 = (int)(char)(&DAT_009a8f7c)[local_5c >> 0x18];
          iVar2 = iVar10 + local_30 * 4 + local_64;
          *(short *)(iVar7 + -2) = (short)pcVar9[9] + pcVar12[9] * 4 + (short)iVar2;
          iVar7 = iVar7 + 8;
          pcVar9[9] = (char)iVar2;
          pcVar9 = pcVar9 + 0xc;
          pcVar12 = pcVar12 + 0xc;
        } while (local_74 + 0x10 + uVar8 * 8 != iVar7);
      }
      local_7c = local_7c + 0x400;
      local_78 = local_78 - 0x100;
      local_80 = local_80 + 0x300;
      local_84 = local_84 + 0x300;
      local_74 = local_74 + 0x200;
    } while (param_1 + (param_2 - 1 >> 8) * 0x400 + 0x1b378 != local_7c);
  }
  return;
}


// ===== FUN_009917d8 @ 009917d8

void FUN_009917d8(byte *param_1,byte *param_2)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  byte *pbVar8;
  uint uVar9;
  uint uVar10;
  bool bVar11;
  int local_30 [5];
  
  iVar4 = 0;
  iVar5 = 0;
  if (param_1 == (byte *)0x0) {
    iVar2 = 0;
    piVar7 = local_30;
    do {
      iVar6 = iVar5;
      iVar2 = iVar2 + 3;
      *piVar7 = 0x10;
      iVar4 = iVar4 + 0x80;
      iVar5 = iVar6 + 0x80;
      piVar7 = piVar7 + 1;
    } while (iVar2 != 0xc);
    iVar5 = iVar6 + 0x82 >> 2;
    if (iVar5 < 0) {
      bVar1 = 0x80;
      goto LAB_00991838;
    }
  }
  else {
    pbVar8 = param_1 + 0xc;
    piVar7 = local_30;
    do {
      uVar10 = (uint)param_1[1];
      uVar3 = (uint)*param_1;
      uVar9 = (uint)param_1[2];
      *piVar7 = ((int)(uVar3 * 0x41bd + uVar10 * 0x810f + uVar9 * 0x1910 + 0x8000) >> 0x10) + 0x10;
      param_1 = param_1 + 3;
      iVar2 = iVar5 + ((int)(uVar10 * -0x4a7e + uVar3 * -0x25f2 + uVar9 * 0x7070 + 0x8000) >> 0x10);
      iVar5 = iVar2 + 0x80;
      iVar4 = iVar4 + ((int)(uVar10 * -0x5e27 + uVar3 * 0x7070 + uVar9 * -0x1249 + 0x8000) >> 0x10)
              + 0x80;
      piVar7 = piVar7 + 1;
    } while (param_1 != pbVar8);
    iVar5 = iVar2 + 0x82 >> 2;
    if (iVar5 < 0) {
      bVar1 = 0x80;
      goto LAB_00991838;
    }
  }
  if (iVar5 < 0x100) {
    bVar1 = ~((byte)iVar5 ^ 0x7f);
  }
  else {
    bVar1 = 0x7f;
  }
LAB_00991838:
  *param_2 = bVar1;
  if (local_30[0] < 0) {
    bVar1 = 0;
  }
  else if (local_30[0] < 0x100) {
    bVar1 = (byte)local_30[0];
  }
  else {
    bVar1 = 0xff;
  }
  uVar9 = iVar4 + 2 >> 2;
  bVar11 = (int)uVar9 < 0;
  if (bVar11) {
    uVar9 = 0x80;
  }
  param_2[1] = bVar1;
  if (!bVar11) {
    if ((int)uVar9 < 0x100) {
      uVar9 = ~(uVar9 ^ 0x7f) & 0xff;
    }
    else {
      uVar9 = 0x7f;
    }
  }
  param_2[2] = (byte)uVar9;
  if (local_30[1] < 0) {
    bVar1 = 0;
  }
  else if (local_30[1] < 0x100) {
    bVar1 = (byte)local_30[1];
  }
  else {
    bVar1 = 0xff;
  }
  param_2[3] = bVar1;
  if (local_30[2] < 0) {
    bVar1 = 0;
  }
  else if (local_30[2] < 0x100) {
    bVar1 = (byte)local_30[2];
  }
  else {
    bVar1 = 0xff;
  }
  param_2[4] = bVar1;
  if (local_30[3] < 0) {
    bVar1 = 0;
  }
  else if (local_30[3] < 0x100) {
    bVar1 = (byte)local_30[3];
  }
  else {
    bVar1 = 0xff;
  }
  param_2[5] = bVar1;
  return;
}


// ===== FUN_009919e0 @ 009919e0

void FUN_009919e0(int param_1,int param_2,int param_3,int param_4,ushort *param_5,int param_6)

{
  ushort uVar1;
  longlong lVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  ushort *puVar9;
  int *piVar10;
  uint *puVar11;
  int iVar12;
  uint uVar13;
  uint *puVar14;
  int iVar15;
  uint local_48 [4];
  uint local_38 [5];
  
  iVar12 = *(int *)(param_1 + 0x81cc);
  if (iVar12 == 0) {
    if (*(int *)(param_1 + 8) != 0) {
      piVar10 = (int *)(param_4 + -4);
      puVar9 = param_5 + -1;
      puVar11 = local_38;
      do {
        puVar9 = puVar9 + 1;
        uVar6 = (uint)*puVar9;
        piVar10 = piVar10 + 1;
        uVar3 = 0;
        if (uVar6 != 0) {
          uVar3 = *piVar10 + (uint)(*puVar9 >> 1);
          if (uVar6 < 0x100) {
            uVar3 = uVar3 * *(int *)(param_1 + 0x7938 + uVar6 * 8 + 4) +
                    (int)((ulonglong)*(uint *)(param_1 + 0x7938 + uVar6 * 8) * (ulonglong)uVar3 >>
                         0x20) >> 8;
          }
          else {
            uVar3 = FUN_009a5bf0();
          }
        }
        *puVar11 = uVar3;
        puVar11 = puVar11 + 1;
      } while (param_5 + 2 != puVar9);
      *(int *)(param_1 + 0x8140) = param_1 + 0x527e + param_3 * 3;
      *(undefined4 *)(param_1 + 0x81c8) = 0;
      FUN_0098cb9c(param_1 + 0x8138,local_38);
      *(undefined1 *)(param_1 + param_3 + 0x5aee) = 1;
      return;
    }
  }
  else {
    puVar9 = param_5 + -1;
    piVar10 = (int *)(param_4 + -4);
    puVar11 = local_48;
    do {
      puVar9 = puVar9 + 1;
      uVar6 = (uint)*puVar9;
      piVar10 = piVar10 + 1;
      uVar3 = 0;
      if (uVar6 != 0) {
        uVar3 = *piVar10 + (uint)(*puVar9 >> 1);
        if (uVar6 < 0x100) {
          uVar3 = uVar3 * *(int *)(param_1 + (uVar6 + 0xf27) * 8 + 4) +
                  (int)((ulonglong)*(uint *)(param_1 + (uVar6 + 0xf27) * 8) * (ulonglong)uVar3 >>
                       0x20) >> 8;
        }
        else {
          uVar3 = FUN_009a5bf0();
        }
      }
      *puVar11 = uVar3;
      puVar11 = puVar11 + 1;
    } while (puVar9 != param_5 + 2);
    puVar9 = param_5 + 3;
    local_38[0] = local_48[0];
    local_38[1] = local_48[1];
    local_38[2] = local_48[2];
    puVar14 = local_38;
    puVar11 = (uint *)(param_6 + -4);
    do {
      puVar11 = puVar11 + 1;
      if (*puVar11 != 0) {
        uVar1 = *param_5;
        if (uVar1 != 0) {
          lVar2 = (ulonglong)*puVar11 * 7 + (ulonglong)(uVar1 >> 1);
          iVar4 = FUN_009a69d8((int)lVar2,(int)((ulonglong)lVar2 >> 0x20),uVar1,0);
          *puVar14 = *puVar14 + iVar4;
        }
      }
      param_5 = param_5 + 1;
      puVar14 = puVar14 + 1;
    } while (param_5 != puVar9);
    uVar3 = (uint)(param_2 * 0xd5) / 0x1aa0;
    if ((*(code **)(param_1 + 0x8204) != (code *)0x0) && (*(uint *)(param_1 + 0x820c) != uVar3)) {
      (**(code **)(param_1 + 0x8204))(*(undefined4 *)(param_1 + 0x8208));
      iVar12 = *(int *)(param_1 + 0x81cc);
      *(uint *)(param_1 + 0x820c) = uVar3;
    }
    iVar15 = ((param_3 * 0x2d & 0x1fffffffU) / 0x5a) * 2 +
             ((uint)(param_2 * 0xd5) / 0xd5 & 0x1f) * 0x2d0;
    iVar5 = *(int *)(iVar12 + uVar3 * 4);
    iVar7 = (int)((ulonglong)
                  ((longlong)*(int *)(param_1 + 0x81ec) * (longlong)(int)local_38[2] +
                  (longlong)*(int *)(param_1 + 0x81e8) * (longlong)(int)local_38[1] +
                  (longlong)(int)local_38[0] * (longlong)*(int *)(param_1 + 0x81e4)) >> 0x20);
    iVar4 = iVar7 >> 0x1f;
    if (iVar4 < 0) {
      uVar6 = 0;
      iVar4 = 0;
    }
    else {
      uVar6 = iVar7 >> 2;
    }
    uVar13 = (uint)*(ushort *)(iVar5 + iVar15);
    uVar8 = uVar6 + uVar13;
    iVar7 = *(int *)(iVar12 + uVar3 * 4 + 0x1c);
    iVar12 = *(int *)(param_1 + 0x81f4);
    if ((int)(uint)(uVar8 < 0x10000) <= (int)(iVar4 + (uint)CARRY4(uVar6,uVar13))) {
      uVar8 = 0xffff;
    }
    *(short *)(iVar5 + iVar15) = (short)uVar8;
    iVar4 = (int)((ulonglong)
                  ((longlong)(int)local_38[2] * (longlong)*(int *)(param_1 + 0x81f8) +
                  (longlong)(int)local_38[0] * (longlong)*(int *)(param_1 + 0x81f0) +
                  (longlong)iVar12 * (longlong)(int)local_38[1]) >> 0x20);
    iVar12 = iVar4 >> 0x1f;
    if (iVar12 < 0) {
      uVar3 = 0;
      iVar12 = 0;
    }
    else {
      uVar3 = iVar4 >> 2;
    }
    uVar6 = (uint)*(ushort *)(iVar7 + iVar15);
    uVar8 = uVar3 + uVar6;
    if ((int)(uint)(uVar8 < 0x10000) <= (int)(iVar12 + (uint)CARRY4(uVar3,uVar6))) {
      uVar8 = 0xffff;
    }
    *(short *)(iVar7 + iVar15) = (short)uVar8;
    if (*(int *)(param_1 + 8) != 0) {
      *(int *)(param_1 + 0x8140) = param_1 + 0x527e + param_3 * 3;
      *(undefined4 *)(param_1 + 0x81c8) = 0;
      FUN_0098cb9c(param_1 + 0x8138,local_48);
      *(undefined1 *)(param_1 + param_3 + 0x5aee) = 1;
    }
  }
  return;
}


// ===== FUN_00991d5c @ 00991d5c

void FUN_00991d5c(int *param_1)

{
  short sVar1;
  short sVar2;
  char cVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  short *psVar11;
  uint uVar12;
  uint uVar13;
  undefined1 uVar14;
  uint uVar15;
  ushort *puVar16;
  int iVar17;
  int iVar18;
  int *piVar19;
  int *piVar20;
  int iVar21;
  uint uVar22;
  int iVar23;
  int iVar24;
  bool bVar25;
  int local_8c;
  undefined1 *local_74;
  int local_70;
  int *local_68;
  int local_5c;
  short *local_58;
  int *local_54;
  short local_48 [4];
  int local_40 [7];
  
  iVar8 = param_1[0x16f];
  if (iVar8 < 0) {
    return;
  }
  uVar12 = (uint)*(ushort *)(param_1 + 0x173);
  if (uVar12 <= *(ushort *)((int)param_1 + 0x5ce)) {
    uVar6 = param_1[3];
    local_74 = (undefined1 *)((int)param_1 + uVar12 + 0x5aed);
    uVar15 = uVar6 + 1 & 1;
    iVar21 = 1 - uVar6;
    iVar17 = *param_1;
    puVar16 = (ushort *)((int)param_1 + uVar12 * 2 + 0x16);
    uVar9 = uVar6 & 1;
    if (uVar12 != 0) goto LAB_00991fec;
    do {
      local_5c = iVar17 + uVar15;
      puVar16 = puVar16 + 1;
      if (uVar6 < (uint)param_1[0x171]) {
        uVar6 = param_1[0x171];
      }
      uVar22 = (uint)*puVar16;
      if ((uint)param_1[0x172] <= (uint)*puVar16) {
        uVar22 = param_1[0x172];
      }
      iVar10 = 0;
      uVar13 = iVar21 + uVar22;
      iVar18 = param_1[0x2073];
      piVar20 = param_1 + 0x173;
      local_40[0] = 0;
      piVar19 = param_1 + uVar12 * 2;
      local_40[1] = 0;
      local_40[2] = 0;
      local_40[3] = 0;
      local_40[4] = 0;
      local_40[5] = 0;
      local_48[0] = 0;
      local_48[1] = 0;
      local_48[2] = 0;
      sVar2 = (short)(iVar21 + uVar6 >> 1);
      while( true ) {
        local_54 = local_40;
        local_58 = local_48;
        local_68 = local_40 + 3;
        local_70 = uVar9 + 0x9c;
        uVar7 = (uint)*(byte *)((local_5c - uVar15) + local_70);
        piVar20 = piVar20 + 1;
        iVar23 = *piVar20;
        uVar4 = (uint)*(byte *)(local_5c + 0x9c);
        local_48[uVar7] = (short)iVar23 * ((short)(uVar13 >> 1) - sVar2) + local_48[uVar7];
        local_5c = local_5c + 2;
        local_40[uVar7] = local_40[uVar7] + piVar19[0x176];
        sVar1 = local_48[uVar4];
        piVar19[0x176] = 0;
        iVar5 = local_40[uVar4];
        local_48[uVar4] =
             (short)iVar23 * ((((short)uVar22 - (short)(uVar13 >> 1)) - (short)uVar6) + sVar2) +
             sVar1;
        iVar23 = piVar19[0x177];
        piVar19[0x177] = 0;
        piVar19 = piVar19 + 0x5a0;
        local_40[uVar4] = iVar5 + iVar23;
        if (iVar18 != 0) {
          iVar5 = param_1[0x207f] + iVar10;
          local_40[uVar7 + 3] = local_40[uVar7 + 3] + *(int *)(iVar5 + uVar12 * 8);
          iVar23 = iVar5 + uVar12 * 8;
          iVar24 = *(int *)(iVar23 + 4);
          *(undefined4 *)(iVar23 + 4) = 0;
          *(undefined4 *)(iVar5 + uVar12 * 8) = 0;
          local_40[uVar4 + 3] = local_40[uVar4 + 3] + iVar24;
        }
        if (iVar10 == 0x1680) break;
        iVar10 = 0x1680;
      }
      iVar10 = 0;
      local_74 = local_74 + 1;
      *local_74 = 0;
      iVar5 = param_1[0xcb6];
      if (iVar5 == 0) {
LAB_00991fb4:
        piVar20 = local_68;
LAB_00991fc8:
        FUN_009919e0(param_1,iVar8,uVar12,local_54,local_58,piVar20);
      }
      else {
        if (*(ushort *)(param_1 + 0xcb7) != uVar12) {
          if (iVar5 == 1) goto LAB_00991fb4;
          if (*(ushort *)((int)param_1 + 0x32de) == uVar12) {
            iVar10 = 1;
          }
          else {
            if (iVar5 == 2) goto LAB_00991fb4;
            iVar10 = 2;
          }
        }
        iVar5 = 0;
        psVar11 = (short *)((int)param_1 + iVar10 * 6 + iVar8 * 0xc + 0x46d6);
        piVar20 = local_68;
        do {
          *(int *)((-0x5acc - (int)param_1) + (int)psVar11 * 2) =
               *(int *)((-0x5acc - (int)param_1) + (int)psVar11 * 2) + *local_54;
          psVar11 = psVar11 + 1;
          *psVar11 = *local_58 + *psVar11;
          if (iVar18 != 0) {
            iVar23 = iVar10 * 3 + iVar5;
            iVar24 = param_1[0x2080] + iVar8 * 0x18;
            *(int *)(iVar24 + iVar23 * 4) = *(int *)(iVar24 + iVar23 * 4) + *piVar20;
          }
          iVar5 = iVar5 + 1;
          piVar20 = piVar20 + 1;
          local_58 = local_58 + 1;
          local_54 = local_54 + 1;
        } while (iVar5 != 3);
        iVar5 = iVar10 + iVar8 * 2;
        piVar20 = (int *)((int)param_1 + iVar5 + 0x5000);
        cVar3 = *(char *)((int)param_1 + iVar5 + 0x50d4) + '\x01';
        *(char *)((int)param_1 + iVar5 + 0x50d4) = cVar3;
        if (cVar3 == '\x02') {
          bVar25 = iVar18 == 0;
          if (!bVar25) {
            piVar20 = (int *)param_1[0x2080];
          }
          if (bVar25) {
            piVar20 = local_68;
          }
          local_58 = (short *)((int)param_1 + iVar8 * 0xc + 0x46d8 + iVar10 * 6);
          if (!bVar25) {
            piVar20 = piVar20 + iVar10 * 3 + iVar8 * 6;
          }
          local_54 = param_1 + iVar10 * 3 + iVar8 * 6 + 0xcb8;
          goto LAB_00991fc8;
        }
      }
      uVar12 = uVar12 + 1;
      if (*(ushort *)((int)param_1 + 0x5ce) < uVar12) goto LAB_00992134;
LAB_00991fec:
      uVar6 = (uint)*puVar16;
    } while( true );
  }
LAB_0099213c:
  iVar17 = param_1[2];
  if (iVar17 != 0) {
    uVar12 = uVar12 >> 2;
    local_8c = (int)param_1 + uVar12 * 0xc + 0x527e;
    iVar21 = iVar8 * 2;
    iVar10 = iVar8 * 0x438 + 0x36d8 + uVar12 * 6;
    do {
      if (*(ushort *)((int)param_1 + 0x5ce) >> 2 < uVar12) break;
      uVar15 = 0;
      uVar9 = 0;
      uVar6 = uVar12 << 2;
      do {
        if ((uVar6 <= *(ushort *)((int)param_1 + 0x5ce) && *(ushort *)(param_1 + 0x173) <= uVar6) &&
           (*(char *)((int)param_1 + uVar6 + 0x5aee) != '\0')) {
          uVar9 = uVar9 | 1 << (uVar15 & 0xff);
        }
        uVar15 = uVar15 + 1;
        uVar6 = uVar6 + 1;
      } while (uVar15 != 4);
      if (uVar9 == 0xf) {
        FUN_009917d8(local_8c,iVar17 + iVar10);
LAB_00992378:
        iVar17 = param_1[2];
      }
      else {
        uVar6 = (uint)*(byte *)((int)param_1 + iVar8 + 0x785e);
        if (uVar6 == 0) {
          uVar14 = 1;
LAB_00992284:
          *(undefined1 *)((int)param_1 + iVar8 + 0x785e) = uVar14;
          *(short *)((int)param_1 + (iVar21 + uVar6) * 0x10 + 0x5dbe) = (short)uVar12;
          *(undefined1 *)(param_1 + (iVar21 + uVar6) * 4 + 6000) = 0;
LAB_009922a8:
          iVar18 = (int)param_1 + (uVar6 + iVar21) * 0x10 + 0x5dc1;
          uVar15 = 0;
          do {
            if ((uVar9 & 1 << (uVar15 & 0xff)) != 0) {
              iVar18 = FUN_009975a8(iVar18,uVar12 * 0xc + iVar8 * -0x20 + uVar6 * -0x10 + -0xb43 +
                                           iVar18,3);
            }
            uVar15 = uVar15 + 1;
            iVar18 = iVar18 + 3;
          } while (uVar15 != 4);
          iVar18 = iVar21 + uVar6;
          uVar9 = (uint)*(byte *)(param_1 + iVar18 * 4 + 6000) | uVar9 & 0xff;
          *(char *)(param_1 + iVar18 * 4 + 6000) = (char)uVar9;
          if (uVar9 == 0xf) {
            FUN_009917d8((int)param_1 + (uVar6 + iVar21) * 0x10 + 0x5dc1,iVar17 + iVar10);
            *(undefined1 *)(param_1 + iVar18 * 4 + 6000) = 0xff;
            goto LAB_00992378;
          }
          iVar17 = param_1[2];
        }
        else {
          if (*(ushort *)((int)param_1 + iVar8 * 0x20 + 0x5dbe) == uVar12) {
            uVar6 = 0;
            goto LAB_009922a8;
          }
          if (uVar6 == 1) {
            uVar14 = 2;
            goto LAB_00992284;
          }
          if (*(ushort *)((int)param_1 + iVar8 * 0x20 + 0x5dce) == uVar12) {
            uVar6 = 1;
            goto LAB_009922a8;
          }
          if (uVar6 != 2) {
            uVar6 = 2;
            goto LAB_009922a8;
          }
        }
      }
      local_8c = local_8c + 0xc;
      uVar12 = uVar12 + 1;
      iVar10 = iVar10 + 6;
    } while (iVar17 != 0);
  }
  param_1[0x16f] = -1;
  return;
LAB_00992134:
  uVar12 = (uint)*(ushort *)(param_1 + 0x173);
  goto LAB_0099213c;
}


// ===== FUN_009923fc @ 009923fc

void FUN_009923fc(int *param_1,int param_2,uint param_3)

{
  uint uVar1;
  
  uVar1 = param_1[1];
  if (uVar1 < param_2 + 2U) {
    param_1[3] = 0;
  }
  else {
    *(char *)(*param_1 + param_2) = (char)(param_3 & 0xffff);
    *(char *)(*param_1 + param_2 + 1) = (char)((param_3 & 0xffff) >> 8);
    uVar1 = param_1[1];
  }
  if (uVar1 < param_2 + 4U) {
    param_1[3] = 0;
    return;
  }
  *(char *)(*param_1 + param_2 + 2U) = (char)(param_3 >> 0x10);
  *(char *)(*param_1 + param_2 + 3) = (char)(param_3 >> 0x18);
  return;
}


// ===== FUN_00992474 @ 00992474

void FUN_00992474(int *param_1,undefined2 *param_2,int param_3)

{
  byte *pbVar1;
  undefined2 *extraout_r1;
  undefined2 *extraout_r1_00;
  undefined2 *extraout_r1_01;
  short sVar2;
  undefined2 uVar3;
  uint uVar4;
  uint uVar5;
  undefined4 *puVar6;
  undefined *puVar7;
  undefined *puVar8;
  undefined2 *puVar9;
  byte *unaff_r7;
  int iVar10;
  undefined2 *puVar11;
  undefined *puVar12;
  uint uVar13;
  int iVar14;
  
  iVar10 = param_1[2];
  uVar13 = param_1[1];
  uVar4 = iVar10 + 2;
  uVar5 = uVar4;
  if (uVar13 < uVar4) {
    uVar5 = 0;
  }
  iVar14 = iVar10 + param_3 * 0xc;
  puVar7 = (undefined *)(iVar14 + 6);
  if (uVar13 < uVar4) {
    param_1[3] = uVar5;
  }
  else {
    *(char *)(*param_1 + iVar10) = (char)param_3;
    *(undefined1 *)(*param_1 + iVar10 + 1) = 0;
    uVar13 = param_1[1];
  }
  uVar5 = iVar10 + 6;
  puVar11 = param_2 + param_3 * 8 + -8;
  puVar9 = param_2;
  do {
    sVar2 = puVar9[1];
    uVar4 = (uint)(ushort)(sVar2 - 3);
    if (uVar4 < 3) {
      param_2 = (undefined2 *)&DAT_009a8ca0;
    }
    else {
      unaff_r7 = (byte *)0x1;
    }
    if (uVar4 < 3) {
      unaff_r7 = *(byte **)(param_2 + uVar4 * 2);
    }
    unaff_r7 = (byte *)(*(int *)(puVar9 + 2) * (int)unaff_r7);
    if (uVar13 < uVar5 - 2) {
      param_1[3] = 0;
    }
    else {
      uVar3 = *puVar9;
      *(char *)(*param_1 + uVar5 + -4) = (char)uVar3;
      *(char *)(*param_1 + uVar5 + -3) = (char)((ushort)uVar3 >> 8);
      sVar2 = puVar9[1];
      uVar13 = param_1[1];
    }
    if (uVar13 < uVar5) {
      param_1[3] = 0;
    }
    else {
      *(char *)(*param_1 + (uVar5 - 2)) = (char)sVar2;
      *(char *)(*param_1 + uVar5 + -1) = (char)((ushort)sVar2 >> 8);
    }
    FUN_009923fc(param_1,uVar5,*(undefined4 *)(puVar9 + 2));
    puVar8 = (undefined *)(uVar5 + 4);
    if (unaff_r7 < &DAT_00000005) {
      FUN_009923fc(param_1,puVar8,0);
      puVar6 = *(undefined4 **)(puVar9 + 4);
      param_2 = extraout_r1;
      if (puVar6 == (undefined4 *)0x0) {
        uVar3 = (undefined2)*(undefined4 *)(puVar9 + 6);
        if (puVar9[1] == 3) goto LAB_009926cc;
LAB_00992674:
        FUN_009923fc(param_1,puVar8);
        param_2 = extraout_r1_00;
      }
      else {
        puVar12 = puVar7;
        if (puVar9[1] == 5) goto LAB_00992690;
        if (unaff_r7 != (byte *)0x0) goto LAB_009925b0;
      }
    }
    else {
      FUN_009923fc(param_1,puVar8,puVar7 + -6);
      puVar6 = *(undefined4 **)(puVar9 + 4);
      param_2 = (undefined2 *)((uint)(unaff_r7 + 1) & 0xfffffffe);
      puVar12 = (undefined *)((int)param_2 + (int)puVar7);
      puVar8 = puVar7;
      if (puVar6 == (undefined4 *)0x0) {
        uVar3 = (undefined2)*(undefined4 *)(puVar9 + 6);
        puVar7 = puVar12;
        if (puVar9[1] != 3) goto LAB_00992674;
LAB_009926cc:
        if ((undefined *)param_1[1] < puVar8 + 2) {
LAB_009925e0:
          param_1[3] = 0;
        }
        else {
          puVar8[*param_1] = (char)uVar3;
          puVar8[*param_1 + 1] = (char)((ushort)uVar3 >> 8);
        }
      }
      else if (puVar9[1] == 5) {
LAB_00992690:
        FUN_009923fc(param_1,puVar8,*puVar6);
        FUN_009923fc(param_1,puVar8 + 4,puVar6[1]);
        param_2 = extraout_r1_01;
        puVar7 = puVar12;
      }
      else {
LAB_009925b0:
        pbVar1 = (byte *)((int)puVar6 + -1);
        unaff_r7 = unaff_r7 + (int)pbVar1;
        do {
          puVar7 = puVar12;
          if ((undefined *)param_1[1] <= puVar8) goto LAB_009925e0;
          pbVar1 = pbVar1 + 1;
          param_2 = (undefined2 *)(uint)*pbVar1;
          puVar8[*param_1] = *pbVar1;
          puVar8 = puVar8 + 1;
        } while (unaff_r7 != pbVar1);
      }
    }
    if (puVar9 == puVar11) {
      FUN_009923fc(param_1,iVar14 + 2,0);
      param_1[2] = (int)puVar7;
      return;
    }
    uVar13 = param_1[1];
    uVar5 = uVar5 + 0xc;
    puVar9 = puVar9 + 8;
  } while( true );
}


// ===== FUN_00992700 @ 00992700

void FUN_00992700(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined8 *puVar5;
  undefined4 *puVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  undefined4 local_40;
  undefined4 uStack_3c;
  undefined4 local_38;
  undefined4 uStack_34;
  undefined4 local_30;
  undefined4 uStack_2c;
  
  uVar7 = *param_2;
  uVar8 = param_2[1];
  uVar3 = param_2[2];
  uVar4 = param_2[3];
  uVar1 = param_2[4];
  uVar2 = param_2[5];
  puVar6 = param_1 + 0x12;
  puVar5 = (undefined8 *)&local_40;
  do {
    uVar9 = FUN_009a6274(uVar7,uVar8,*param_1,param_1[1]);
    uVar10 = FUN_009a6274(uVar3,uVar4,param_1[2],param_1[3]);
    uVar9 = FUN_009a5e5c((int)uVar9,(int)((ulonglong)uVar9 >> 0x20),(int)uVar10,
                         (int)((ulonglong)uVar10 >> 0x20));
    uVar10 = FUN_009a6274(uVar1,uVar2,param_1[4],param_1[5]);
    uVar9 = FUN_009a5e5c((int)uVar9,(int)((ulonglong)uVar9 >> 0x20),(int)uVar10,
                         (int)((ulonglong)uVar10 >> 0x20));
    param_1 = param_1 + 6;
    *puVar5 = uVar9;
    puVar5 = puVar5 + 1;
  } while (puVar6 != param_1);
  *param_3 = local_40;
  param_3[1] = uStack_3c;
  param_3[4] = local_30;
  param_3[5] = uStack_2c;
  param_3[2] = local_38;
  param_3[3] = uStack_34;
  return;
}


// ===== FUN_009927bc @ 009927bc

void FUN_009927bc(uint param_1,int param_2,undefined4 *param_3)

{
  longlong lVar1;
  uint *puVar2;
  int iVar3;
  uint *puVar4;
  uint *puVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  uint uVar9;
  
  if ((param_1 & 3) == 0) {
    iVar3 = param_1 + 0x10;
    do {
      *(undefined4 *)(iVar3 + -0x10) = 0;
      *(undefined4 *)(iVar3 + -0xc) = 0;
      *(undefined4 *)(iVar3 + -8) = 0;
      *(undefined4 *)(iVar3 + -4) = 0;
      iVar3 = iVar3 + 0x10;
    } while (iVar3 != param_1 + 0xa0);
    *(undefined4 *)(param_1 + 0x90) = 0;
  }
  else {
    FUN_00997590(param_1,0,0x94);
  }
  puVar4 = (uint *)(param_2 + 0x5c);
  uVar7 = *(undefined4 *)(param_2 + 0x8c);
  uVar9 = *(uint *)(param_2 + 0x90);
  *(undefined4 *)(param_1 + 0x14) = *(undefined4 *)(param_2 + 0x88);
  *(undefined4 *)(param_1 + 0x18) = uVar7;
  puVar5 = (uint *)(param_1 + 0x1c);
  *puVar5 = uVar9;
  puVar2 = puVar4;
  do {
    puVar2 = puVar2 + 1;
    puVar5 = puVar5 + 1;
    *puVar5 = *puVar2;
  } while ((uint *)(param_2 + 0x80) != puVar2);
  *(undefined4 **)(param_1 + 0x44) = param_3;
  uVar8 = param_3[0x93];
  *(undefined4 **)(param_1 + 0x48) = param_3 + 0x9a;
  uVar7 = param_3[0x92];
  uVar6 = *param_3;
  *(undefined4 *)(param_1 + 0x58) = uVar8;
  *(undefined4 *)(param_1 + 0x84) = param_3[0x94];
  *(undefined4 *)(param_1 + 0x88) = param_3[0x95];
  iVar3 = 0;
  *(undefined4 *)(param_1 + 0x54) = uVar6;
  *(undefined4 *)(param_1 + 0x4c) = uVar7;
  *(undefined4 **)(param_1 + 0x50) = param_3 + 0x11;
  *(undefined4 *)(param_1 + 0x6c) = 1;
  do {
    lVar1 = 0x800;
    puVar2 = (uint *)(param_2 + 0x84);
    puVar5 = puVar4;
    do {
      puVar5 = puVar5 + 1;
      uVar9 = *puVar5;
      if ((int)uVar9 < 0) {
        uVar9 = -uVar9;
      }
      puVar2 = puVar2 + 1;
      lVar1 = (ulonglong)*puVar2 * (ulonglong)uVar9 + lVar1;
      uVar9 = (uint)((ulonglong)lVar1 >> 0x20);
    } while ((uint *)(param_2 + 0x90) != puVar2);
    iVar3 = iVar3 + 3;
    if (uVar9 != 0 || uVar9 < (0x7fffffff < (uint)lVar1)) {
      *(undefined4 *)(param_1 + 0x6c) = 0;
    }
    puVar4 = puVar4 + 3;
  } while (iVar3 != 9);
  return;
}


// ===== FUN_009928e8 @ 009928e8

void FUN_009928e8(int param_1,int *param_2,int param_3,int *param_4,uint param_5,uint param_6,
                 int param_7,int *param_8,uint param_9)

{
  short sVar1;
  short sVar2;
  short sVar3;
  longlong lVar4;
  longlong lVar5;
  ushort uVar6;
  int *piVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  uint *puVar12;
  ushort *puVar13;
  uint *puVar14;
  uint uVar15;
  byte bVar16;
  int iVar17;
  int *piVar18;
  int iVar19;
  uint uVar20;
  undefined4 uVar21;
  short sVar22;
  int iVar23;
  uint uVar24;
  undefined4 *puVar25;
  short sVar26;
  uint uVar27;
  ushort uVar28;
  ushort uVar29;
  uint uVar30;
  uint uVar31;
  byte *pbVar32;
  int iVar33;
  int iVar34;
  uint uVar35;
  uint uVar36;
  int iVar37;
  ushort uVar38;
  ushort uVar39;
  uint uVar40;
  int *piVar41;
  uint uVar42;
  uint uVar43;
  uint uVar44;
  uint uVar45;
  bool bVar46;
  uint local_134;
  int local_12c;
  uint local_128;
  uint local_124;
  uint local_120;
  byte *local_118;
  uint local_110;
  undefined4 *local_10c;
  undefined4 *local_108;
  uint local_d8 [4];
  int local_c8 [7];
  int local_ac;
  int *local_60;
  int *local_5c;
  int local_58;
  int *local_54;
  int local_4c;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  int *local_30;
  uint local_2c;
  
  iVar23 = param_1 + (param_5 & 1) * 2;
  uVar10 = param_5 + 1;
  uVar27 = param_6 + 1 & 1;
  iVar34 = param_1 + (uVar10 & 1) * 2;
  uVar11 = (uint)*(byte *)(iVar34 + uVar27 + 0x9c);
  if ((((*(char *)(iVar23 + (param_6 & 1) + 0x9c) == '\x01') &&
       (*(char *)(iVar23 + uVar27 + 0x9c) == '\x02')) &&
      (*(char *)(iVar34 + (param_6 & 1) + 0x9c) == '\0')) && (uVar11 == 1)) {
    FUN_009927bc(local_c8 + 3,param_1,param_2);
    iVar17 = param_6 + 0x7fffffff;
    iVar34 = *param_4;
    iVar23 = iVar17 * 2;
    iVar19 = iVar23 + 2;
    local_c8[6] = *(uint *)(param_3 + 0x50);
    iVar9 = param_4[1];
    iVar37 = param_4[2];
    iVar33 = param_4[3];
    local_4c = iVar34 + iVar17 * 2;
    local_ac = *(int *)(param_1 + 0x84);
    local_c8[5] = param_7;
    local_c8[3] = iVar9 + iVar17 * 2;
    local_c8[4] = iVar37 + iVar17 * 2;
    local_48 = iVar33 + iVar17 * 2;
    uVar10 = *(uint *)(param_1 + 0x88);
    if ((uint)local_c8[6] < (uint)*(ushort *)(iVar34 + iVar19)) {
      uVar11 = local_ac * ((uint)*(ushort *)(iVar34 + iVar19) - local_c8[6]) + 0x800 >> 0xc;
      if (uVar10 <= uVar11) {
        uVar11 = uVar10;
      }
      local_44 = uVar11 * 3;
    }
    else {
      local_44 = 0;
    }
    uVar27 = (uint)*(ushort *)(iVar34 + iVar23);
    uVar11 = local_ac * ((uint)*(ushort *)(iVar37 + iVar19) - local_c8[6]) + 0x800 >> 0xc;
    if (uVar10 <= uVar11) {
      uVar11 = uVar10;
    }
    uVar11 = uVar11 * 9;
    if ((uint)local_c8[6] < (uint)*(ushort *)(iVar37 + iVar19)) {
      local_44 = local_44 + uVar11;
    }
    if (uVar27 <= (uint)local_c8[6]) {
      uVar11 = 0;
    }
    uVar10 = *(uint *)(param_1 + 0x8c);
    if ((uVar27 > (uint)local_c8[6]) &&
       (uVar11 = local_ac * (uVar27 - local_c8[6]) + 0x800 >> 0xc, uVar10 <= uVar11)) {
      uVar11 = uVar10;
    }
    if ((uint)local_c8[6] < (uint)*(ushort *)(iVar37 + iVar23)) {
      uVar27 = local_ac * ((uint)*(ushort *)(iVar37 + iVar23) - local_c8[6]) + 0x800 >> 0xc;
      if (uVar10 <= uVar27) {
        uVar27 = uVar10;
      }
    }
    else {
      uVar27 = 0;
    }
    uVar44 = local_ac * ((uint)*(ushort *)(iVar9 + iVar19) - local_c8[6]) + 0x800 >> 0xc;
    uVar35 = local_ac * ((uint)*(ushort *)(iVar33 + iVar19) - local_c8[6]) + 0x800 >> 0xc;
    if (uVar10 <= uVar44) {
      uVar44 = uVar10;
    }
    if (uVar10 < uVar35) {
      uVar35 = uVar10;
    }
    if ((uint)local_c8[6] < (uint)*(ushort *)(iVar33 + iVar19)) {
      uVar27 = uVar27 + uVar35;
    }
    if ((uint)local_c8[6] < (uint)*(ushort *)(iVar9 + iVar19)) {
      uVar11 = uVar11 + uVar44 * 9;
    }
    local_40 = uVar27 * 3 + uVar11;
    uVar10 = *(uint *)(param_1 + 0x90);
    if ((uint)local_c8[6] < (uint)*(ushort *)(iVar9 + iVar23)) {
      uVar11 = local_ac * ((uint)*(ushort *)(iVar9 + iVar23) - local_c8[6]) + 0x800 >> 0xc;
      if (uVar10 <= uVar11) {
        uVar11 = uVar10;
      }
      local_3c = uVar11 * 3;
    }
    else {
      local_3c = 0;
    }
    uVar11 = local_ac * ((uint)*(ushort *)(iVar33 + iVar23) - local_c8[6]) + 0x800 >> 0xc;
    if (uVar10 < uVar11) {
      uVar11 = uVar10;
    }
    if ((uint)local_c8[6] < (uint)*(ushort *)(iVar33 + iVar23)) {
      local_3c = local_3c + uVar11;
    }
    if (param_8 == (int *)0x0) {
      local_60 = param_8;
      local_5c = param_8;
      local_30 = param_8;
      local_58 = 0;
    }
    else {
      puVar25 = (undefined4 *)*param_8;
      local_30 = (int *)puVar25[4];
      if (local_30 == (int *)0x0) {
        local_60 = (int *)puVar25[2];
      }
      else {
        local_60 = (int *)0x0;
      }
      local_5c = (int *)*puVar25;
      local_58 = param_8[1];
      param_8 = (int *)param_8[2];
    }
    local_54 = param_8;
    local_2c = param_9;
    FUN_0098c00c(local_c8 + 3,*(undefined4 *)(param_1 + 0x94));
  }
  else {
    iVar23 = *(int *)(param_1 + 0x84);
    uVar35 = *(uint *)(param_3 + 0x50);
    local_d8[0] = 0;
    local_d8[1] = 0;
    piVar18 = &DAT_009a8f6c;
    local_d8[2] = 0;
    uVar40 = uVar10 & 1;
    uVar44 = uVar10;
    while( true ) {
      iVar34 = *piVar18;
      local_d8[uVar11] = local_d8[uVar11] + iVar34;
      piVar7 = &DAT_009a8f6c;
      uVar11 = param_6 + 2;
      do {
        bVar16 = *(byte *)(param_1 + uVar40 * 2 + (uVar11 & 1) + 0x9c);
        piVar7 = piVar7 + 1;
        uVar11 = uVar11 + 1;
        local_d8[bVar16] = *piVar7 * iVar34 + local_d8[bVar16];
      } while (param_6 + 5 != uVar11);
      uVar44 = uVar44 + 1;
      if (uVar44 == param_5 + 5) break;
      uVar40 = uVar44 & 1;
      uVar11 = (uint)*(byte *)(param_1 + uVar40 * 2 + uVar27 + 0x9c);
      piVar18 = piVar18 + 1;
    }
    if (param_8 != (int *)0x0) {
      param_8[3] = 0;
    }
    if (*(int *)(param_1 + 0x94) != 0) {
      local_118 = (byte *)(param_7 + -1);
      local_110 = 0;
      uVar11 = param_6 + 3;
      local_12c = (param_6 - 1) * 2;
      do {
        local_c8[0] = 0;
        local_c8[1] = 0;
        local_c8[2] = 0;
        piVar18 = param_4 + -1;
        piVar7 = &DAT_009a8f6c;
        uVar27 = uVar10;
        do {
          piVar18 = piVar18 + 1;
          piVar41 = &DAT_009a8f6c;
          iVar34 = *piVar7;
          uVar44 = uVar11 - 4;
          puVar13 = (ushort *)(*piVar18 + local_12c);
          do {
            uVar40 = (uint)*(byte *)(param_1 + ((uVar27 & 1) + 0x4e) * 2 + (uVar44 & 1));
            if (uVar35 < *puVar13) {
              uVar20 = *(uint *)(param_1 + (uVar40 + 0x22) * 4);
              uVar8 = (*puVar13 - uVar35) * iVar23 + 0x800 >> 0xc;
              if (uVar8 < uVar20) {
                uVar20 = uVar8;
              }
              iVar19 = iVar34 * *piVar41 * uVar20;
            }
            else {
              iVar19 = 0;
            }
            piVar41 = piVar41 + 1;
            uVar44 = uVar44 + 1;
            local_c8[uVar40] = local_c8[uVar40] + iVar19;
            puVar13 = puVar13 + 1;
          } while (uVar44 != uVar11);
          uVar27 = uVar27 + 1;
          piVar7 = piVar7 + 1;
        } while (uVar27 != param_5 + 5);
        piVar7 = local_c8;
        piVar18 = local_c8 + 3;
        puVar12 = local_d8;
        do {
          puVar14 = puVar12 + 1;
          iVar34 = 0;
          if (*puVar12 != 0) {
            iVar34 = FUN_009a5bf0(*piVar7 + (*puVar12 >> 1));
          }
          piVar7 = piVar7 + 1;
          *piVar18 = iVar34;
          piVar18 = piVar18 + 1;
          puVar12 = puVar14;
        } while (local_d8 + 3 != puVar14);
        bVar46 = param_9 != 0;
        uVar27 = param_9;
        if (bVar46) {
          uVar27 = local_110;
        }
        if (bVar46) {
          piVar41 = (int *)(uVar27 * 3);
          uVar27 = param_9;
        }
        if (bVar46) {
          piVar41 = (int *)(uVar27 + (int)piVar41 * 4);
        }
        if (!bVar46) {
          piVar41 = (int *)0x0;
        }
        lVar4 = (longlong)local_c8[5] * (longlong)*(int *)(param_1 + 0x68) +
                (longlong)local_c8[3] * (longlong)*(int *)(param_1 + 0x60) +
                (longlong)local_c8[4] * (longlong)*(int *)(param_1 + 100) + 0x800;
        local_120 = (uint)lVar4 >> 0xc | (int)((ulonglong)lVar4 >> 0x20) * 0x100000;
        lVar4 = (longlong)*(int *)(param_1 + 0x74) * (longlong)local_c8[5] +
                (longlong)*(int *)(param_1 + 0x6c) * (longlong)local_c8[3] +
                (longlong)local_c8[4] * (longlong)*(int *)(param_1 + 0x70) + 0x800;
        lVar5 = (longlong)*(int *)(param_1 + 0x80) * (longlong)local_c8[5] +
                (longlong)*(int *)(param_1 + 0x78) * (longlong)local_c8[3] +
                (longlong)*(int *)(param_1 + 0x7c) * (longlong)local_c8[4] + 0x800;
        local_124 = (uint)lVar4 >> 0xc | (int)((ulonglong)lVar4 >> 0x20) * 0x100000;
        local_134 = (uint)lVar5 >> 0xc | (int)((ulonglong)lVar5 >> 0x20) * 0x100000;
        if (piVar41 != (int *)0x0) {
          local_124 = local_124 + piVar41[1];
          local_120 = local_120 + *piVar41;
          local_134 = local_134 + piVar41[2];
        }
        if ((int)local_120 < (int)local_124) {
          uVar27 = local_124;
        }
        else {
          uVar27 = local_120;
        }
        if ((int)uVar27 < (int)local_134) {
          uVar27 = local_134;
        }
        uVar44 = local_134;
        uVar40 = local_120;
        uVar8 = local_124;
        if (0 < (int)uVar27) {
          iVar34 = (int)uVar27 >> 0x1f;
          if ((int)uVar27 < 0x80000) {
            iVar19 = uVar27 - 0x7ffff;
            if ((int)local_120 < iVar19) {
              iVar37 = (int)((ulonglong)((longlong)(int)uVar27 * 0xd0a) >> 0x20);
              uVar42 = uVar27 - local_120;
              iVar17 = iVar34 - (((int)local_120 >> 0x1f) + (uint)(uVar27 < local_120));
              bVar46 = (uint)((longlong)(int)uVar27 * 0xd0a) < uVar42 * 0x1000;
              uVar15 = iVar17 * 0x1000 | uVar42 >> 0x14;
              uVar20 = iVar37 - (uVar15 + bVar46);
              if ((int)uVar20 < 0 !=
                  (SBORROW4(iVar37,uVar15) != SBORROW4(iVar37 - uVar15,(uint)bVar46)))
              goto LAB_00992cb8;
            }
            else {
              uVar42 = uVar27 - local_120;
              if ((int)(uVar27 * 0xd0a) < (int)(uVar42 * 0x1000)) {
                iVar17 = (int)uVar42 >> 0x1f;
                uVar20 = local_120;
LAB_00992cb8:
                uVar40 = FUN_00991240(param_2,0,uVar27,uVar20,uVar42,iVar17);
              }
            }
            if ((int)local_124 < iVar19) {
              iVar9 = (int)((ulonglong)((longlong)(int)uVar27 * 0xcd9) >> 0x20);
              uVar20 = uVar27 - local_124;
              iVar17 = iVar34 - (((int)local_124 >> 0x1f) + (uint)(uVar27 < local_124));
              bVar46 = (uint)((longlong)(int)uVar27 * 0xcd9) < uVar20 * 0x1000;
              uVar15 = iVar17 * 0x1000 | uVar20 >> 0x14;
              iVar37 = iVar9 - (uVar15 + bVar46);
              if (iVar37 < 0 != (SBORROW4(iVar9,uVar15) != SBORROW4(iVar9 - uVar15,(uint)bVar46)))
              goto LAB_00992d00;
            }
            else {
              iVar37 = uVar27 * 0x11;
              uVar20 = uVar27 - local_124;
              if ((int)(uVar27 * 0xcd9) < (int)(uVar20 * 0x1000)) {
                iVar17 = (int)uVar20 >> 0x1f;
LAB_00992d00:
                uVar8 = FUN_00991240(param_2,1,uVar27,iVar37,uVar20,iVar17);
              }
            }
            if ((int)local_134 < iVar19) {
              goto LAB_00993294;
            }
            iVar19 = uVar27 * 0xe14;
            uVar20 = uVar27 - local_134;
            if ((int)(uVar20 * 0x1000) <= iVar19) goto LAB_00993308;
            iVar34 = (int)uVar20 >> 0x1f;
          }
          else {
            iVar37 = (int)((ulonglong)((longlong)(int)uVar27 * 0xd0a) >> 0x20);
            uVar20 = uVar27 - local_120;
            iVar17 = iVar34 - (((int)local_120 >> 0x1f) + (uint)(uVar27 < local_120));
            uVar15 = iVar17 * 0x1000 | uVar20 >> 0x14;
            bVar46 = (uint)((longlong)(int)uVar27 * 0xd0a) < uVar20 * 0x1000;
            iVar19 = iVar37 - (uVar15 + bVar46);
            if (iVar19 < 0 != (SBORROW4(iVar37,uVar15) != SBORROW4(iVar37 - uVar15,(uint)bVar46))) {
              uVar40 = FUN_00991240(param_2,0,uVar27,iVar19,uVar20,iVar17);
            }
            iVar37 = (int)((ulonglong)((longlong)(int)uVar27 * 0xcd9) >> 0x20);
            uVar20 = uVar27 - local_124;
            iVar17 = iVar34 - (((int)local_124 >> 0x1f) + (uint)(uVar27 < local_124));
            bVar46 = (uint)((longlong)(int)uVar27 * 0xcd9) < uVar20 * 0x1000;
            uVar15 = iVar17 * 0x1000 | uVar20 >> 0x14;
            iVar19 = iVar37 - (uVar15 + bVar46);
            if (iVar19 < 0 != (SBORROW4(iVar37,uVar15) != SBORROW4(iVar37 - uVar15,(uint)bVar46))) {
              uVar8 = FUN_00991240(param_2,1,uVar27,iVar19,uVar20,iVar17);
            }
LAB_00993294:
            iVar17 = (int)((ulonglong)((longlong)(int)uVar27 * 0xe14) >> 0x20);
            uVar20 = uVar27 - local_134;
            iVar34 = iVar34 - (((int)local_134 >> 0x1f) + (uint)(uVar27 < local_134));
            bVar46 = (uint)((longlong)(int)uVar27 * 0xe14) < uVar20 * 0x1000;
            uVar15 = iVar34 * 0x1000 | uVar20 >> 0x14;
            iVar19 = iVar17 - (uVar15 + bVar46);
            if (iVar19 < 0 == (SBORROW4(iVar17,uVar15) != SBORROW4(iVar17 - uVar15,(uint)bVar46))) {
LAB_00993308:
              goto LAB_00992d60;
            }
          }
          uVar44 = FUN_00991240(param_2,2,uVar27,iVar19,uVar20,iVar34);
        }
LAB_00992d60:
        iVar34 = *param_2;
        uVar27 = iVar34 - 1;
        if ((int)uVar40 < -0x2000) {
          uVar20 = (uint)*(ushort *)param_2[0x92];
          if ((int)uVar8 < -0x2000) goto LAB_009932f8;
LAB_00992db8:
          if ((int)uVar8 < 0x2000) {
            uVar40 = (uint)*(ushort *)((int)param_2 + (uVar8 + 0x2134) * 2);
          }
          else {
            if (0x7ffff < (int)uVar8) {
              puVar13 = (ushort *)(param_2[0x92] + 0x10000);
              goto LAB_00993300;
            }
            puVar13 = (ushort *)(param_2[0x92] + ((int)uVar8 >> 4) * 2);
            uVar40 = (uint)*puVar13;
            uVar40 = uVar40 + ((int)((uVar8 & 0xf) * (puVar13[1] - uVar40) + 8) >> 4);
          }
        }
        else {
          if ((int)uVar40 < 0x2000) {
            uVar20 = (uint)*(ushort *)((int)param_2 + (uVar40 + 0x2134) * 2);
          }
          else if ((int)uVar40 < 0x80000) {
            puVar13 = (ushort *)(param_2[0x92] + ((int)uVar40 >> 4) * 2);
            uVar20 = (uint)*puVar13;
            uVar20 = uVar20 + ((int)((uVar40 & 0xf) * (puVar13[1] - uVar20) + 8) >> 4);
          }
          else {
            uVar20 = (uint)*(ushort *)(param_2[0x92] + 0x10000);
          }
          if (-0x2001 < (int)uVar8) goto LAB_00992db8;
LAB_009932f8:
          puVar13 = (ushort *)param_2[0x92];
LAB_00993300:
          uVar40 = (uint)*puVar13;
        }
        if ((int)uVar44 < -0x2000) {
          puVar13 = (ushort *)param_2[0x92];
LAB_009932e0:
          uVar8 = (uint)*puVar13;
        }
        else if ((int)uVar44 < 0x2000) {
          uVar8 = (uint)*(ushort *)((int)param_2 + (uVar44 + 0x2134) * 2);
        }
        else {
          if (0x7ffff < (int)uVar44) {
            puVar13 = (ushort *)(param_2[0x92] + 0x10000);
            goto LAB_009932e0;
          }
          puVar13 = (ushort *)(param_2[0x92] + ((int)uVar44 >> 4) * 2);
          uVar8 = (uint)*puVar13;
          uVar8 = uVar8 + ((int)((uVar44 & 0xf) * (puVar13[1] - uVar8) + 8) >> 4);
        }
        uVar44 = uVar20 >> 9;
        if (uVar20 >> 9 < uVar27) {
          uVar15 = uVar20 & 0x1ff;
        }
        else {
          uVar15 = 0x200;
        }
        if (uVar27 <= uVar20 >> 9) {
          uVar44 = iVar34 - 2;
        }
        uVar20 = uVar8 >> 9;
        local_10c = (undefined4 *)(uVar8 & 0x1ff);
        if (uVar40 >> 9 < uVar27) {
          uVar8 = uVar40 & 0x1ff;
          iVar19 = (uVar40 >> 9) * iVar34 + uVar44;
          if (uVar20 < uVar27) {
            puVar12 = (uint *)(param_2[uVar20 + 0x11] + iVar19 * 4);
            puVar14 = (uint *)(param_2[uVar20 + 0x12] + iVar19 * 4);
            if (uVar15 <= uVar8) {
              if (uVar8 < local_10c) goto LAB_0099345c;
              local_128 = uVar8;
              goto LAB_00992eac;
            }
            local_128 = uVar15;
            if (uVar8 <= local_10c) {
              uVar27 = puVar14[1];
              if (uVar15 <= local_10c) goto LAB_00993590;
              uVar40 = puVar12[1];
              uVar44 = (uint)local_10c;
              local_10c = (undefined4 *)uVar8;
              goto LAB_00992ec8;
            }
            uVar40 = puVar12[1];
            goto LAB_00993200;
          }
          puVar14 = (uint *)(param_2[iVar34 + 0x10] + iVar19 * 4);
          puVar12 = (uint *)(param_2[iVar34 + 0xf] + iVar19 * 4);
          local_10c = (undefined4 *)0x200;
          if (uVar8 < uVar15) {
LAB_00993590:
            local_128 = (uint)local_10c;
            uVar40 = *puVar14;
            uVar27 = puVar14[1];
            uVar44 = uVar15;
            local_10c = (undefined4 *)uVar8;
          }
          else {
LAB_0099345c:
            uVar27 = puVar14[iVar34];
            uVar40 = *puVar14;
            local_128 = (uint)local_10c;
            uVar44 = uVar8;
            local_10c = (undefined4 *)uVar15;
          }
        }
        else {
          iVar19 = iVar34 * (iVar34 + -2) + uVar44;
          if (uVar20 < uVar27) {
            puVar12 = (uint *)(param_2[uVar20 + 0x11] + iVar19 * 4);
            puVar14 = (uint *)(param_2[uVar20 + 0x12] + iVar19 * 4);
            local_128 = 0x200;
          }
          else {
            local_10c = (undefined4 *)0x200;
            puVar14 = (uint *)(param_2[iVar34 + 0x10] + iVar19 * 4);
            puVar12 = (uint *)(param_2[iVar34 + 0xf] + iVar19 * 4);
            local_128 = 0x200;
          }
LAB_00992eac:
          uVar40 = puVar12[iVar34];
          if (uVar15 < local_10c) {
            uVar27 = puVar14[iVar34];
            uVar44 = (uint)local_10c;
            local_10c = (undefined4 *)uVar15;
          }
          else {
            uVar8 = uVar15;
LAB_00993200:
            uVar27 = puVar12[iVar34 + 1];
            uVar44 = uVar8;
          }
        }
LAB_00992ec8:
        uVar45 = puVar14[iVar34 + 1];
        uVar42 = *puVar12;
        uVar8 = 0xffff;
        uVar20 = (uVar42 & 0x7ff) << 5 | (uVar42 & 0x7ff) >> 6;
        uVar30 = (uVar40 & 0x7ff) << 5 | (uVar40 & 0x7ff) >> 6;
        uVar24 = (uVar42 >> 0xb & 0x7ff) << 5 | (uVar42 & 0x3fffff) >> 0x11;
        uVar36 = (uVar40 >> 0xb & 0x7ff) << 5 | (uVar40 & 0x3fffff) >> 0x11;
        uVar15 = uVar40 >> 0x1a | (uVar40 >> 0x16) << 6;
        uVar43 = uVar42 >> 0x1a | (uVar42 >> 0x16) << 6;
        uVar40 = (uVar27 & 0x7ff) << 5 | (uVar27 & 0x7ff) >> 6;
        uVar31 = (uVar27 >> 0xb & 0x7ff) << 5 | (uVar27 & 0x3fffff) >> 0x11;
        uVar42 = uVar27 >> 0x1a | (uVar27 >> 0x16) << 6;
        uVar27 = (int)((((uVar45 & 0x7ff) << 5 | (uVar45 & 0x7ff) >> 6) - uVar40) * (int)local_10c +
                       uVar44 * (uVar40 - uVar30) + (uVar30 - uVar20) * local_128 + uVar20 * 0x200 +
                      0x100) >> 9;
        uVar40 = (int)((((uVar45 >> 0xb & 0x7ff) << 5 | (uVar45 & 0x3fffff) >> 0x11) - uVar31) *
                       (int)local_10c +
                       uVar44 * (uVar31 - uVar36) + (uVar36 - uVar24) * local_128 + uVar24 * 0x200 +
                      0x100) >> 9;
        uVar20 = uVar45 >> 0x16;
        if (0xfffe < (int)uVar27) {
          uVar20 = uVar8;
        }
        uVar44 = (int)(((uVar45 >> 0x1a | (uVar45 >> 0x16) << 6) - uVar42) * (int)local_10c +
                       uVar44 * (uVar42 - uVar15) + (uVar15 - uVar43) * local_128 + uVar43 * 0x200 +
                      0x100) >> 9;
        if ((int)uVar27 < 0xffff) {
          uVar20 = uVar27;
        }
        if ((int)uVar40 < 0xffff) {
          uVar15 = uVar40;
        }
        else {
          uVar15 = uVar8;
        }
        if ((int)uVar44 < 0xffff) {
          uVar8 = uVar44;
        }
        uVar20 = uVar20 & ~((int)uVar20 >> 0x1f);
        uVar15 = uVar15 & ~((int)uVar15 >> 0x1f);
        uVar8 = uVar8 & ~((int)uVar8 >> 0x1f);
        if ((param_8 != (int *)0x0) && (piVar18 = (int *)*param_8, piVar18[4] == 0)) {
          uVar42 = uVar27;
          if (0x3ff < (int)uVar27) {
            uVar42 = (uVar20 >> 7) + 0x1f8;
          }
          iVar34 = piVar18[1];
          if ((int)uVar27 < 0x400) {
            uVar42 = uVar20 & 0xfffffffe;
          }
          else {
            uVar42 = uVar42 << 1;
          }
          if ((int)uVar40 < 0x400) {
            iVar19 = (uVar15 & 0xfffffffe) + 0x800;
          }
          else {
            iVar19 = ((uVar15 >> 7) + 0x5f8) * 2;
          }
          if ((int)uVar44 < 0x400) {
            uVar27 = uVar8 & 0xfffffffe;
          }
          else {
            uVar27 = (uVar8 >> 7) + 0x9f8;
          }
          if ((int)uVar44 < 0x400) {
            iVar17 = uVar27 + 0x1000;
          }
          else {
            iVar17 = uVar27 << 1;
          }
          uVar28 = *(ushort *)(iVar34 + uVar42) & 0x7ff;
          uVar29 = *(ushort *)(iVar34 + iVar17) & 0x7ff;
          uVar38 = *(ushort *)(iVar34 + iVar19) & 0x7ff;
          iVar34 = (uint)(*(ushort *)(iVar34 + uVar42) >> 0xb) * 0xc +
                   (uint)(*(ushort *)(iVar34 + iVar19) >> 0xb) * 0xcc +
                   (uint)(*(ushort *)(iVar34 + iVar17) >> 0xb) * 0xd8c;
          iVar19 = piVar18[2] + iVar34;
          local_10c = (undefined4 *)(iVar19 + 0xd8c);
          if (uVar38 < uVar28) {
            uVar6 = uVar28;
            if (uVar29 < uVar38) {
              local_10c = (undefined4 *)(iVar19 + 0xc);
              local_108 = (undefined4 *)(iVar19 + 0xd8);
              uVar28 = uVar38;
            }
            else {
              local_108 = (undefined4 *)(iVar19 + 0xd98);
              if (uVar29 < uVar28) {
                local_10c = (undefined4 *)(iVar19 + 0xc);
                uVar28 = uVar29;
                uVar29 = uVar38;
              }
              else {
                uVar6 = uVar29;
                uVar29 = uVar38;
              }
            }
          }
          else {
            uVar39 = uVar38;
            uVar6 = uVar29;
            if (uVar29 <= uVar38) {
              local_10c = (undefined4 *)(iVar19 + 0xcc);
              uVar39 = uVar29;
              uVar6 = uVar38;
              if (uVar29 <= uVar28) {
                local_108 = (undefined4 *)(iVar19 + 0xd8);
                goto LAB_009935dc;
              }
            }
            local_108 = (undefined4 *)(iVar19 + 0xe58);
            uVar29 = uVar28;
            uVar28 = uVar39;
          }
LAB_009935dc:
          sVar22 = 0x800 - uVar6;
          sVar26 = uVar28 - uVar29;
          sVar1 = uVar6 - uVar28;
          uVar21 = *(undefined4 *)(piVar18[2] + iVar34);
          iVar37 = param_8[3];
          sVar2 = *(short *)(param_8[1] + iVar37 * 4);
          iVar34 = (int)(short)((int)(short)((uint)*(undefined4 *)(iVar19 + 0xe64) >> 0x10) *
                                (int)(short)uVar29 +
                                (int)(short)((uint)*local_108 >> 0x10) * (int)sVar26 +
                                (int)(short)((uint)*local_10c >> 0x10) * (int)sVar1 +
                                (int)(short)((uint)uVar21 >> 0x10) * (int)sVar22 >> 0xb) *
                   (int)sVar2;
          iVar17 = (int)(short)((int)(short)((uint)*(undefined4 *)(iVar19 + 0xe68) >> 0x10) *
                                (int)(short)uVar29 +
                                (int)(short)((uint)local_108[1] >> 0x10) * (int)sVar26 +
                                (int)(short)((uint)local_10c[1] >> 0x10) * (int)sVar1 +
                                (int)(short)((uint)*(undefined4 *)(iVar19 + 4) >> 0x10) *
                                (int)sVar22 >> 0xb) * (int)sVar2;
          if (*piVar18 == 0) {
            sVar3 = *(short *)(param_8[1] + iVar37 * 4 + 2);
            iVar34 = (int)(short)((int)(short)*(undefined4 *)(iVar19 + 0xe68) * (int)(short)uVar29 +
                                  (int)(short)local_108[1] * (int)sVar26 +
                                  (int)(short)local_10c[1] * (int)sVar1 +
                                  (int)(short)*(undefined4 *)(iVar19 + 4) * (int)sVar22 >> 0xb) *
                     (int)sVar3 + iVar34;
            iVar17 = (int)(short)((int)(short)((uint)*(undefined4 *)(iVar19 + 0xe6c) >> 0x10) *
                                  (int)(short)uVar29 +
                                  (int)(short)((uint)local_108[2] >> 0x10) * (int)sVar26 +
                                  (int)(short)((uint)local_10c[2] >> 0x10) * (int)sVar1 +
                                  (int)(short)((uint)*(undefined4 *)(iVar19 + 8) >> 0x10) *
                                  (int)sVar22 >> 0xb) * (int)*(short *)(param_8[2] + iVar37 * 2) +
                     (int)(short)((int)(short)*(undefined4 *)(iVar19 + 0xe6c) * (int)(short)uVar29 +
                                  (int)(short)local_108[2] * (int)sVar26 +
                                  (int)(short)local_10c[2] * (int)sVar1 +
                                  (int)(short)*(undefined4 *)(iVar19 + 8) * (int)sVar22 >> 0xb) *
                     (int)sVar3 + iVar17;
          }
          uVar27 = 0xffff;
          uVar20 = uVar20 + ((int)(short)((int)(short)*(undefined4 *)(iVar19 + 0xe64) *
                                          (int)(short)uVar29 +
                                          (int)(short)*local_108 * (int)sVar26 +
                                          (int)(short)*local_10c * (int)sVar1 +
                                          (int)(short)uVar21 * (int)sVar22 >> 0xb) * (int)sVar2 >> 7
                            );
          uVar15 = uVar15 + (iVar34 >> 7);
          uVar8 = uVar8 + (iVar17 >> 7);
          if (0xfffe < (int)uVar20) {
            uVar20 = uVar27;
          }
          if (0xfffe < (int)uVar15) {
            uVar15 = uVar27;
          }
          if (0xfffe < (int)uVar8) {
            uVar8 = uVar27;
          }
          param_8[3] = iVar37 + 1;
          uVar15 = uVar15 & ~((int)uVar15 >> 0x1f);
          uVar20 = uVar20 & ~((int)uVar20 >> 0x1f);
          uVar8 = uVar8 & ~((int)uVar8 >> 0x1f);
        }
        uVar44 = 0xffff;
        uVar27 = uVar20 + (local_120 - 0x80000);
        if (0xfffe < uVar27) {
          uVar27 = uVar44;
        }
        uVar40 = uVar15 + (local_124 - 0x80000);
        if (0x80000 < (int)local_120) {
          uVar20 = uVar27;
        }
        if (0xfffe < uVar40) {
          uVar40 = uVar44;
        }
        uVar27 = uVar8 + (local_134 - 0x80000);
        if (0x80000 < (int)local_124) {
          uVar15 = uVar40;
        }
        if (0xfffe < uVar27) {
          uVar27 = uVar44;
        }
        if (0x80000 < (int)local_134) {
          uVar8 = uVar27;
        }
        local_118[1] = *(byte *)(param_2[0x93] + (uVar20 * 0xfff + 0x8000 >> 0x10));
        local_118[2] = *(byte *)(param_2[0x94] + (uVar15 * 0xfff + 0x8000 >> 0x10));
        local_118[3] = *(byte *)(param_2[0x95] + (uVar8 * 0xfff + 0x8000 >> 0x10));
        if ((param_8 != (int *)0x0) && (iVar34 = *(int *)(*param_8 + 0x10), iVar34 != 0)) {
          iVar19 = 0;
          sVar1 = *(short *)(param_8[1] + param_8[3] * 4);
          param_8[3] = param_8[3] + 1;
          pbVar32 = local_118;
          do {
            pbVar32 = pbVar32 + 1;
            iVar17 = (uint)*pbVar32 +
                     ((int)sVar1 * (int)(short)(ushort)*(byte *)(iVar34 + iVar19 + (uint)*pbVar32) +
                      0x400 >> 0xb);
            if (iVar17 < 0) {
              bVar16 = 0;
            }
            else if (iVar17 < 0x100) {
              bVar16 = (byte)iVar17;
            }
            else {
              bVar16 = 0xff;
            }
            iVar19 = iVar19 + 0x100;
            *pbVar32 = bVar16;
          } while (iVar19 != 0x300);
        }
        local_110 = local_110 + 1;
        local_118 = local_118 + 3;
        local_12c = local_12c + 4;
        uVar11 = uVar11 + 2;
      } while (local_110 < *(uint *)(param_1 + 0x94));
    }
  }
  return;
}


// ===== FUN_00993a88 @ 00993a88

void FUN_00993a88(undefined4 *param_1,int param_2,uint param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined1 *puVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 *puVar9;
  undefined4 *puVar8;
  undefined8 *puVar10;
  int iVar11;
  undefined8 *puVar12;
  undefined8 uVar13;
  undefined8 uVar14;
  undefined8 local_70;
  undefined4 local_68 [2];
  undefined1 auStack_60 [48];
  undefined1 auStack_30 [12];
  
  iVar11 = 0;
  puVar12 = &local_70;
  do {
    uVar3 = *param_1;
    uVar6 = param_1[1];
    uVar1 = param_1[2];
    uVar2 = param_1[3];
    uVar4 = param_1[4];
    uVar7 = param_1[5];
    puVar8 = (undefined4 *)(param_2 + -8);
    puVar10 = puVar12;
    do {
      puVar9 = puVar8 + 2;
      uVar13 = FUN_009a6274(uVar3,uVar6,*puVar9,puVar8[3]);
      uVar14 = FUN_009a6274(uVar1,uVar2,puVar8[8],puVar8[9]);
      uVar13 = FUN_009a5e5c((int)uVar13,(int)((ulonglong)uVar13 >> 0x20),(int)uVar14,
                            (int)((ulonglong)uVar14 >> 0x20));
      uVar14 = FUN_009a6274(uVar4,uVar7,puVar8[0xe],puVar8[0xf]);
      uVar13 = FUN_009a5e5c((int)uVar13,(int)((ulonglong)uVar13 >> 0x20),(int)uVar14,
                            (int)((ulonglong)uVar14 >> 0x20));
      *puVar10 = uVar13;
      puVar8 = puVar9;
      puVar10 = puVar10 + 1;
    } while (puVar9 != (undefined4 *)(param_2 + 0x10));
    iVar11 = iVar11 + 3;
    param_1 = param_1 + 6;
    puVar12 = puVar12 + 3;
  } while (iVar11 != 9);
  if ((param_3 & 3) != 0) {
    FUN_009975a8(param_3,&local_70,0x48);
    return;
  }
  iVar11 = param_3 + 0x10;
  puVar5 = auStack_60;
  do {
    uVar1 = *(undefined4 *)(puVar5 + -0xc);
    *(undefined4 *)(iVar11 + -0x10) = *(undefined4 *)(puVar5 + -0x10);
    *(undefined4 *)(iVar11 + -0xc) = uVar1;
    uVar1 = *(undefined4 *)(puVar5 + -8);
    *(undefined4 *)(iVar11 + -4) = *(undefined4 *)(puVar5 + -4);
    *(undefined4 *)(iVar11 + -8) = uVar1;
    iVar11 = iVar11 + 0x10;
    puVar5 = puVar5 + 0x10;
  } while (iVar11 != param_3 + 0x50);
  FUN_009975a8(param_3 + 0x40,auStack_30,8);
  return;
}


// ===== FUN_00993bd4 @ 00993bd4

undefined4 FUN_00993bd4(undefined4 *param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  undefined4 uVar16;
  undefined4 uVar17;
  undefined4 uVar18;
  undefined4 uVar19;
  undefined4 uVar20;
  int iVar21;
  undefined4 uVar22;
  undefined4 uVar23;
  undefined4 uVar24;
  undefined4 *puVar25;
  undefined8 uVar26;
  undefined8 uVar27;
  undefined8 uVar28;
  undefined8 uVar29;
  undefined8 uVar30;
  undefined4 local_70 [4];
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  
  uVar3 = *param_1;
  uVar5 = param_1[1];
  uVar18 = param_1[0x10];
  uVar20 = param_1[0x11];
  uVar16 = param_1[2];
  uVar17 = param_1[3];
  uVar23 = param_1[4];
  uVar24 = param_1[5];
  uVar7 = param_1[6];
  uVar11 = param_1[7];
  uVar4 = param_1[8];
  uVar6 = param_1[9];
  uVar8 = param_1[10];
  uVar12 = param_1[0xb];
  uVar9 = param_1[0xc];
  uVar13 = param_1[0xd];
  uVar10 = param_1[0xe];
  uVar14 = param_1[0xf];
  uVar26 = FUN_009a6274(uVar4,uVar6,uVar18,uVar20);
  uVar27 = FUN_009a6274(uVar8,uVar12,uVar10,uVar14);
  uVar26 = FUN_009a5e58((int)uVar26,(int)((ulonglong)uVar26 >> 0x20),(int)uVar27,
                        (int)((ulonglong)uVar27 >> 0x20));
  uVar19 = (undefined4)((ulonglong)uVar26 >> 0x20);
  uVar27 = FUN_009a6274(uVar7,uVar11,uVar18,uVar20);
  uVar28 = FUN_009a6274(uVar8,uVar12,uVar9,uVar13);
  uVar27 = FUN_009a5e58((int)uVar27,(int)((ulonglong)uVar27 >> 0x20),(int)uVar28,
                        (int)((ulonglong)uVar28 >> 0x20));
  iVar21 = (int)((ulonglong)uVar27 >> 0x20) + -0x80000000;
  uVar28 = FUN_009a6274(uVar7,uVar11,uVar10,uVar14);
  uVar29 = FUN_009a6274(uVar4,uVar6,uVar9,uVar13);
  uVar28 = FUN_009a5e58((int)uVar28,(int)((ulonglong)uVar28 >> 0x20),(int)uVar29,
                        (int)((ulonglong)uVar29 >> 0x20));
  uVar22 = (undefined4)((ulonglong)uVar28 >> 0x20);
  uVar29 = FUN_009a6274(uVar3,uVar5,(int)uVar26,uVar19);
  uVar30 = FUN_009a6274(uVar16,uVar17,(int)uVar27,iVar21);
  uVar29 = FUN_009a5e5c((int)uVar29,(int)((ulonglong)uVar29 >> 0x20),(int)uVar30,
                        (int)((ulonglong)uVar30 >> 0x20));
  uVar30 = FUN_009a6274(uVar23,uVar24,(int)uVar28,uVar22);
  uVar29 = FUN_009a5e5c((int)uVar29,(int)((ulonglong)uVar29 >> 0x20),(int)uVar30,
                        (int)((ulonglong)uVar30 >> 0x20));
  uVar2 = (undefined4)((ulonglong)uVar29 >> 0x20);
  uVar15 = (undefined4)uVar29;
  iVar1 = FUN_009a683c(uVar15,uVar2,0x9ee75616,0xbcd203af);
  if ((iVar1 == 0) || (iVar1 = FUN_009a67f4(uVar15,uVar2,0x9ee75616,0x3cd203af), iVar1 == 0)) {
    FUN_009a6504((int)uVar26,uVar19,uVar15,uVar2);
    uVar26 = FUN_009a6274(uVar16,uVar17,uVar18,uVar20);
    uVar29 = FUN_009a6274(uVar23,uVar24,uVar10,uVar14);
    uVar26 = FUN_009a5e58((int)uVar26,(int)((ulonglong)uVar26 >> 0x20),(int)uVar29,
                          (int)((ulonglong)uVar29 >> 0x20));
    FUN_009a6504((int)uVar26,(int)((ulonglong)uVar26 >> 0x20) + -0x80000000,uVar15,uVar2);
    uVar26 = FUN_009a6274(uVar16,uVar17,uVar8,uVar12);
    uVar29 = FUN_009a6274(uVar23,uVar24,uVar4,uVar6);
    uVar26 = FUN_009a5e58((int)uVar26,(int)((ulonglong)uVar26 >> 0x20),(int)uVar29,
                          (int)((ulonglong)uVar29 >> 0x20));
    local_60 = FUN_009a6504((int)uVar26,(int)((ulonglong)uVar26 >> 0x20),uVar15,uVar2);
    local_58 = FUN_009a6504((int)uVar27,iVar21,uVar15,uVar2);
    uVar26 = FUN_009a6274(uVar3,uVar5,uVar18,uVar20);
    uVar27 = FUN_009a6274(uVar23,uVar24,uVar9,uVar13);
    uVar26 = FUN_009a5e58((int)uVar26,(int)((ulonglong)uVar26 >> 0x20),(int)uVar27,
                          (int)((ulonglong)uVar27 >> 0x20));
    local_50 = FUN_009a6504((int)uVar26,(int)((ulonglong)uVar26 >> 0x20),uVar15,uVar2);
    uVar26 = FUN_009a6274(uVar3,uVar5,uVar8,uVar12);
    uVar27 = FUN_009a6274(uVar23,uVar24,uVar7,uVar11);
    uVar26 = FUN_009a5e58((int)uVar26,(int)((ulonglong)uVar26 >> 0x20),(int)uVar27,
                          (int)((ulonglong)uVar27 >> 0x20));
    local_48 = FUN_009a6504((int)uVar26,(int)((ulonglong)uVar26 >> 0x20) + -0x80000000,uVar15,uVar2)
    ;
    local_40 = FUN_009a6504((int)uVar28,uVar22,uVar15,uVar2);
    uVar26 = FUN_009a6274(uVar3,uVar5,uVar10,uVar14);
    uVar27 = FUN_009a6274(uVar16,uVar17,uVar9,uVar13);
    uVar26 = FUN_009a5e58((int)uVar26,(int)((ulonglong)uVar26 >> 0x20),(int)uVar27,
                          (int)((ulonglong)uVar27 >> 0x20));
    local_38 = FUN_009a6504((int)uVar26,(int)((ulonglong)uVar26 >> 0x20) + -0x80000000,uVar15,uVar2)
    ;
    uVar26 = FUN_009a6274(uVar3,uVar5,uVar4,uVar6);
    uVar27 = FUN_009a6274(uVar16,uVar17,uVar7,uVar11);
    uVar26 = FUN_009a5e58((int)uVar26,(int)((ulonglong)uVar26 >> 0x20),(int)uVar27,
                          (int)((ulonglong)uVar27 >> 0x20));
    local_30 = FUN_009a6504((int)uVar26,(int)((ulonglong)uVar26 >> 0x20),uVar15,uVar2);
    iVar1 = param_2 + 0x10;
    puVar25 = local_70;
    do {
      puVar25 = puVar25 + 4;
      uVar15 = puVar25[-1];
      uVar19 = puVar25[-4];
      uVar22 = puVar25[-3];
      *(undefined4 *)(iVar1 + -8) = puVar25[-2];
      *(undefined4 *)(iVar1 + -4) = uVar15;
      *(undefined4 *)(iVar1 + -0x10) = uVar19;
      *(undefined4 *)(iVar1 + -0xc) = uVar22;
      iVar1 = iVar1 + 0x10;
    } while (iVar1 != param_2 + 0x50);
    uVar15 = 0;
    *(undefined8 *)(param_2 + 0x40) = local_30;
  }
  else {
    uVar15 = 0xffffffff;
  }
  return uVar15;
}


// ===== FUN_00993bdc @ 00993bdc

undefined4 FUN_00993bdc(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  undefined4 uVar16;
  undefined4 uVar17;
  undefined4 uVar18;
  int iVar19;
  undefined4 uVar20;
  undefined4 uVar21;
  undefined4 uVar22;
  int in_r12;
  undefined4 *puVar23;
  undefined8 uVar24;
  undefined8 uVar25;
  undefined8 uVar26;
  undefined8 uVar27;
  undefined8 uVar28;
  undefined4 local_70 [4];
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  
  uVar16 = *(undefined4 *)(param_1 + 0x40);
  uVar18 = *(undefined4 *)(param_1 + 0x44);
  uVar14 = *(undefined4 *)(param_1 + 8);
  uVar15 = *(undefined4 *)(param_1 + 0xc);
  uVar21 = *(undefined4 *)(in_r12 + 0x10);
  uVar22 = *(undefined4 *)(in_r12 + 0x14);
  uVar5 = *(undefined4 *)(in_r12 + 0x18);
  uVar9 = *(undefined4 *)(in_r12 + 0x1c);
  uVar3 = *(undefined4 *)(param_1 + 0x20);
  uVar4 = *(undefined4 *)(param_1 + 0x24);
  uVar6 = *(undefined4 *)(in_r12 + 0x28);
  uVar10 = *(undefined4 *)(in_r12 + 0x2c);
  uVar7 = *(undefined4 *)(in_r12 + 0x30);
  uVar11 = *(undefined4 *)(in_r12 + 0x34);
  uVar8 = *(undefined4 *)(in_r12 + 0x38);
  uVar12 = *(undefined4 *)(in_r12 + 0x3c);
  uVar24 = FUN_009a6274(uVar3,uVar4,uVar16,uVar18);
  uVar25 = FUN_009a6274(uVar6,uVar10,uVar8,uVar12);
  uVar24 = FUN_009a5e58((int)uVar24,(int)((ulonglong)uVar24 >> 0x20),(int)uVar25,
                        (int)((ulonglong)uVar25 >> 0x20));
  uVar17 = (undefined4)((ulonglong)uVar24 >> 0x20);
  uVar25 = FUN_009a6274(uVar5,uVar9,uVar16,uVar18);
  uVar26 = FUN_009a6274(uVar6,uVar10,uVar7,uVar11);
  uVar25 = FUN_009a5e58((int)uVar25,(int)((ulonglong)uVar25 >> 0x20),(int)uVar26,
                        (int)((ulonglong)uVar26 >> 0x20));
  iVar19 = (int)((ulonglong)uVar25 >> 0x20) + -0x80000000;
  uVar26 = FUN_009a6274(uVar5,uVar9,uVar8,uVar12);
  uVar27 = FUN_009a6274(uVar3,uVar4,uVar7,uVar11);
  uVar26 = FUN_009a5e58((int)uVar26,(int)((ulonglong)uVar26 >> 0x20),(int)uVar27,
                        (int)((ulonglong)uVar27 >> 0x20));
  uVar20 = (undefined4)((ulonglong)uVar26 >> 0x20);
  uVar27 = FUN_009a6274(param_3,param_4,(int)uVar24,uVar17);
  uVar28 = FUN_009a6274(uVar14,uVar15,(int)uVar25,iVar19);
  uVar27 = FUN_009a5e5c((int)uVar27,(int)((ulonglong)uVar27 >> 0x20),(int)uVar28,
                        (int)((ulonglong)uVar28 >> 0x20));
  uVar28 = FUN_009a6274(uVar21,uVar22,(int)uVar26,uVar20);
  uVar27 = FUN_009a5e5c((int)uVar27,(int)((ulonglong)uVar27 >> 0x20),(int)uVar28,
                        (int)((ulonglong)uVar28 >> 0x20));
  uVar2 = (undefined4)((ulonglong)uVar27 >> 0x20);
  uVar13 = (undefined4)uVar27;
  iVar1 = FUN_009a683c(uVar13,uVar2,0x9ee75616,0xbcd203af);
  if ((iVar1 == 0) || (iVar1 = FUN_009a67f4(uVar13,uVar2,0x9ee75616,0x3cd203af), iVar1 == 0)) {
    FUN_009a6504((int)uVar24,uVar17,uVar13,uVar2);
    uVar24 = FUN_009a6274(uVar14,uVar15,uVar16,uVar18);
    uVar27 = FUN_009a6274(uVar21,uVar22,uVar8,uVar12);
    uVar24 = FUN_009a5e58((int)uVar24,(int)((ulonglong)uVar24 >> 0x20),(int)uVar27,
                          (int)((ulonglong)uVar27 >> 0x20));
    FUN_009a6504((int)uVar24,(int)((ulonglong)uVar24 >> 0x20) + -0x80000000,uVar13,uVar2);
    uVar24 = FUN_009a6274(uVar14,uVar15,uVar6,uVar10);
    uVar27 = FUN_009a6274(uVar21,uVar22,uVar3,uVar4);
    uVar24 = FUN_009a5e58((int)uVar24,(int)((ulonglong)uVar24 >> 0x20),(int)uVar27,
                          (int)((ulonglong)uVar27 >> 0x20));
    local_60 = FUN_009a6504((int)uVar24,(int)((ulonglong)uVar24 >> 0x20),uVar13,uVar2);
    local_58 = FUN_009a6504((int)uVar25,iVar19,uVar13,uVar2);
    uVar24 = FUN_009a6274(param_3,param_4,uVar16,uVar18);
    uVar25 = FUN_009a6274(uVar21,uVar22,uVar7,uVar11);
    uVar24 = FUN_009a5e58((int)uVar24,(int)((ulonglong)uVar24 >> 0x20),(int)uVar25,
                          (int)((ulonglong)uVar25 >> 0x20));
    local_50 = FUN_009a6504((int)uVar24,(int)((ulonglong)uVar24 >> 0x20),uVar13,uVar2);
    uVar24 = FUN_009a6274(param_3,param_4,uVar6,uVar10);
    uVar25 = FUN_009a6274(uVar21,uVar22,uVar5,uVar9);
    uVar24 = FUN_009a5e58((int)uVar24,(int)((ulonglong)uVar24 >> 0x20),(int)uVar25,
                          (int)((ulonglong)uVar25 >> 0x20));
    local_48 = FUN_009a6504((int)uVar24,(int)((ulonglong)uVar24 >> 0x20) + -0x80000000,uVar13,uVar2)
    ;
    local_40 = FUN_009a6504((int)uVar26,uVar20,uVar13,uVar2);
    uVar24 = FUN_009a6274(param_3,param_4,uVar8,uVar12);
    uVar25 = FUN_009a6274(uVar14,uVar15,uVar7,uVar11);
    uVar24 = FUN_009a5e58((int)uVar24,(int)((ulonglong)uVar24 >> 0x20),(int)uVar25,
                          (int)((ulonglong)uVar25 >> 0x20));
    local_38 = FUN_009a6504((int)uVar24,(int)((ulonglong)uVar24 >> 0x20) + -0x80000000,uVar13,uVar2)
    ;
    uVar24 = FUN_009a6274(param_3,param_4,uVar3,uVar4);
    uVar25 = FUN_009a6274(uVar14,uVar15,uVar5,uVar9);
    uVar24 = FUN_009a5e58((int)uVar24,(int)((ulonglong)uVar24 >> 0x20),(int)uVar25,
                          (int)((ulonglong)uVar25 >> 0x20));
    local_30 = FUN_009a6504((int)uVar24,(int)((ulonglong)uVar24 >> 0x20),uVar13,uVar2);
    iVar1 = param_2 + 0x10;
    puVar23 = local_70;
    do {
      puVar23 = puVar23 + 4;
      uVar13 = puVar23[-1];
      uVar17 = puVar23[-4];
      uVar20 = puVar23[-3];
      *(undefined4 *)(iVar1 + -8) = puVar23[-2];
      *(undefined4 *)(iVar1 + -4) = uVar13;
      *(undefined4 *)(iVar1 + -0x10) = uVar17;
      *(undefined4 *)(iVar1 + -0xc) = uVar20;
      iVar1 = iVar1 + 0x10;
    } while (iVar1 != param_2 + 0x50);
    uVar13 = 0;
    *(undefined8 *)(param_2 + 0x40) = local_30;
  }
  else {
    uVar13 = 0xffffffff;
  }
  return uVar13;
}


// ===== FUN_00993fe0 @ 00993fe0

void FUN_00993fe0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 local_d0;
  undefined4 uStack_cc;
  undefined4 local_c8;
  undefined4 uStack_c4;
  undefined4 local_c0;
  undefined4 uStack_bc;
  undefined4 local_b8;
  undefined4 uStack_b4;
  undefined4 local_b0;
  undefined4 uStack_ac;
  undefined4 local_a8;
  undefined4 uStack_a4;
  undefined1 auStack_a0 [72];
  undefined8 local_58;
  undefined1 auStack_50 [24];
  undefined8 local_38;
  undefined8 local_18;
  
  FUN_00997590(auStack_50,0,0x38);
  FUN_00993bd4(&DAT_009a8cd0,auStack_a0);
  FUN_00992700(&DAT_009a8cd0,param_1,&local_d0);
  FUN_00992700(&DAT_009a8cd0,param_2,&local_b8);
  local_58 = FUN_009a6504(local_b8,uStack_b4,local_d0,uStack_cc);
  local_38 = FUN_009a6504(local_b0,uStack_ac,local_c8,uStack_c4);
  local_18 = FUN_009a6504(local_a8,uStack_a4,local_c0,uStack_bc);
  FUN_00993a88(&local_58,&DAT_009a8cd0,param_3);
  FUN_00993a88(auStack_a0,param_3,param_3);
  return;
}


// ===== FUN_00994094 @ 00994094

int FUN_00994094(int param_1)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  int iVar4;
  
  pcVar3 = "LTCUBE2";
  pcVar2 = (char *)(param_1 + -1);
  do {
    cVar1 = *pcVar3;
    pcVar2 = pcVar2 + 1;
    pcVar3 = pcVar3 + 1;
    if (*pcVar2 != cVar1) {
      return 0;
    }
  } while (pcVar2 != (char *)(param_1 + 7));
  iVar4 = *(int *)(param_1 + 8);
  if ((0x7f < iVar4 - 2U) || (*(int *)(param_1 + 0xc) != 8000)) {
    return 0;
  }
  if (*(int *)(param_1 + 0x10) != 0x7a12) {
    iVar4 = 0;
  }
  return iVar4;
}


// ===== FUN_00994150 @ 00994150

undefined4 FUN_00994150(int *param_1,int param_2,int param_3,short *param_4)

{
  ushort uVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  short sVar5;
  undefined4 uVar6;
  uint *puVar7;
  short *psVar8;
  uint uVar9;
  int *piVar10;
  int *piVar11;
  undefined1 *puVar12;
  uint *puVar13;
  short *psVar14;
  uint *puVar15;
  int *piVar16;
  short *psVar17;
  
  if (((uint)param_1 & 3) == 0) {
    piVar2 = param_1 + 4;
    do {
      piVar2[-4] = 0;
      piVar2[-3] = 0;
      piVar2[-2] = 0;
      piVar2[-1] = 0;
      piVar2 = piVar2 + 4;
    } while (piVar2 != param_1 + 0x209c);
    uVar6 = 8;
    piVar2 = param_1 + 0x2098;
  }
  else {
    uVar6 = 0x8268;
    piVar2 = param_1;
  }
  FUN_00997590(piVar2,0,uVar6);
  iVar3 = FUN_00994094(param_2);
  if ((iVar3 != 0) && (((uint)param_4 & 1) == 0)) {
    puVar15 = (uint *)(param_3 + -4);
    puVar7 = (uint *)(param_1 + 0x10);
    puVar13 = puVar15 + iVar3;
    while( true ) {
      puVar15 = puVar15 + 1;
      uVar4 = *puVar15;
      if ((uVar4 == 0) || ((uVar4 & 3) != 0)) break;
      puVar7 = puVar7 + 1;
      *puVar7 = uVar4;
      if (puVar15 == puVar13) {
        piVar10 = (int *)(param_2 + 0x14);
        piVar2 = param_1 + 1;
        *param_1 = iVar3;
        if ((((uint)piVar2 | (uint)piVar10) & 3) == 0) {
          iVar3 = param_2 + 0x24;
          piVar2 = param_1 + 5;
          do {
            piVar2[-4] = *(int *)(iVar3 + -0x10);
            piVar10 = piVar2 + 4;
            piVar2[-3] = *(int *)(iVar3 + -0xc);
            piVar2[-2] = *(int *)(iVar3 + -8);
            piVar2[-1] = *(int *)(iVar3 + -4);
            iVar3 = iVar3 + 0x10;
            piVar2 = piVar10;
          } while (param_1 + 0x11 != piVar10);
          piVar11 = param_1 + 0xc;
          piVar10 = (int *)(param_2 + 0x50);
          piVar2 = (int *)(param_2 + 0x44);
          do {
            piVar16 = piVar2 + 1;
            piVar11 = piVar11 + 1;
            *piVar11 = *piVar2;
            piVar2 = piVar16;
          } while (piVar16 != piVar10);
          iVar3 = 2;
          piVar2 = param_1 + 0x10;
        }
        else {
          iVar3 = 0x3e;
        }
        puVar12 = (undefined1 *)((int)piVar2 + -1);
        piVar2 = piVar10;
        do {
          piVar11 = (int *)((int)piVar2 + 1);
          puVar12 = puVar12 + 1;
          *puVar12 = (char)*piVar2;
          piVar2 = piVar11;
        } while ((int *)((int)piVar10 + iVar3 + 1) != piVar11);
        psVar14 = param_4 + 0x8001;
        param_1[0x93] = (int)psVar14;
        param_1[0x95] = (int)psVar14;
        param_1[0x94] = (int)psVar14;
        param_1[0x98] = (int)(param_4 + 0x9001);
        uVar4 = 0;
        psVar17 = param_4 + 0x8801;
        param_1[0x97] = (int)(param_4 + 0x8c01);
        param_1[0x92] = (int)param_4;
        param_1[0x96] = (int)psVar17;
        param_1[0x99] = (int)(param_4 + 0x9401);
        psVar14 = (short *)((int)param_1 + 0x266);
        do {
          iVar3 = (int)uVar4 >> 4;
          psVar8 = psVar17 + iVar3;
          if (iVar3 == 0x3ff) {
            psVar8 = (short *)0x2000;
          }
          if (iVar3 != 0x3ff) {
            psVar8 = (short *)(uint)(ushort)psVar8[1];
          }
          uVar9 = (uint)(ushort)psVar17[iVar3] +
                  ((int)((uVar4 & 0xf) * ((int)psVar8 - (uint)(ushort)psVar17[iVar3]) + 8) >> 4);
          if ((int)uVar9 < 1) {
            sVar5 = *param_4;
          }
          else {
            uVar1 = param_4[(int)uVar9 >> 4];
            sVar5 = uVar1 + (short)((int)(((uint)(ushort)(param_4 + ((int)uVar9 >> 4))[1] -
                                          (uint)uVar1) * (uVar9 & 0xf) + 8) >> 4);
          }
          uVar4 = uVar4 + 1;
          psVar14 = psVar14 + 1;
          *psVar14 = sVar5;
        } while (uVar4 != 0x4000);
        return 0;
      }
    }
  }
  return 0xfffffff6;
}


// ===== FUN_00994378 @ 00994378

undefined4 FUN_00994378(uint *param_1,uint param_2,int param_3)

{
  char cVar1;
  byte bVar2;
  uint uVar3;
  char *pcVar4;
  char *pcVar5;
  uint uVar6;
  
  if (((uint)param_1 & 3) == 0) {
    *param_1 = 0;
    param_1[1] = 0;
    param_1[2] = 0;
    param_1[3] = 0;
    param_1[4] = 0;
  }
  else {
    FUN_00997590(param_1,0,0x14);
  }
  if (param_3 == 0xfe58) {
    pcVar5 = "LTGRAIN4";
    pcVar4 = (char *)(param_2 - 1);
    do {
      cVar1 = *pcVar5;
      pcVar4 = pcVar4 + 1;
      pcVar5 = pcVar5 + 1;
      if (*pcVar4 != cVar1) {
        return 0xfffffff6;
      }
    } while ((char *)(param_2 + 7) != pcVar4);
    if ((param_2 & 3) == 0) {
      bVar2 = *(byte *)(param_2 + 8);
      *param_1 = bVar2 & 1;
      if ((bVar2 & 2) == 0) {
        uVar3 = param_2;
        do {
          uVar6 = uVar3;
          if (0x7fff < *(ushort *)(uVar6 + 0xc)) {
            return 0xfffffff6;
          }
          uVar3 = uVar6 + 2;
        } while (uVar6 + 2 != param_2 + 0x1800);
        param_1[1] = param_2 + 0xc;
        param_1[2] = uVar6 + 0xe;
      }
      else {
        if ((bVar2 & 1) == 0) {
          return 0xfffffff6;
        }
        param_1[3] = param_2 + 0xc;
        param_1[4] = param_2 + 0xf0c;
      }
      return 0;
    }
  }
  return 0xfffffff6;
}


// ===== FUN_0099437c @ 0099437c

undefined4 FUN_0099437c(uint *param_1,uint param_2,int param_3,uint param_4)

{
  char cVar1;
  byte bVar2;
  uint uVar3;
  char *pcVar4;
  char *pcVar5;
  uint uVar6;
  bool in_ZR;
  
  if (in_ZR) {
    *param_1 = param_4;
    param_1[1] = param_4;
    param_1[2] = param_4;
    param_1[3] = param_4;
    param_1[4] = param_4;
  }
  else {
    FUN_00997590(param_1,0,0x14);
  }
  if (param_3 == 0xfe58) {
    pcVar5 = "LTGRAIN4";
    pcVar4 = (char *)(param_2 - 1);
    do {
      cVar1 = *pcVar5;
      pcVar4 = pcVar4 + 1;
      pcVar5 = pcVar5 + 1;
      if (*pcVar4 != cVar1) {
        return 0xfffffff6;
      }
    } while ((char *)(param_2 + 7) != pcVar4);
    if ((param_2 & 3) == 0) {
      bVar2 = *(byte *)(param_2 + 8);
      *param_1 = bVar2 & 1;
      if ((bVar2 & 2) == 0) {
        uVar3 = param_2;
        do {
          uVar6 = uVar3;
          if (0x7fff < *(ushort *)(uVar6 + 0xc)) {
            return 0xfffffff6;
          }
          uVar3 = uVar6 + 2;
        } while (uVar6 + 2 != param_2 + 0x1800);
        param_1[1] = param_2 + 0xc;
        param_1[2] = uVar6 + 0xe;
      }
      else {
        if ((bVar2 & 1) == 0) {
          return 0xfffffff6;
        }
        param_1[3] = param_2 + 0xc;
        param_1[4] = param_2 + 0xf0c;
      }
      return 0;
    }
  }
  return 0xfffffff6;
}


// ===== FUN_00994488 @ 00994488

void FUN_00994488(int param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0xc);
  if (iVar2 != 0) {
    if (param_2 < 0xc) {
      iVar1 = param_2 * 0x300;
    }
    else {
      iVar1 = 0xf00;
    }
    iVar2 = iVar2 + iVar1;
  }
  *(int *)(param_1 + 0x10) = iVar2;
  return;
}


// ===== FUN_009944b0 @ 009944b0

undefined4 FUN_009944b0(undefined8 *param_1,char *param_2,undefined4 *param_3)

{
  char cVar1;
  char cVar2;
  short sVar3;
  short sVar4;
  undefined8 *puVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  char *extraout_r1;
  char *pcVar9;
  undefined4 uVar10;
  uint uVar11;
  char *pcVar12;
  undefined4 uVar13;
  int iVar14;
  undefined4 uVar15;
  undefined8 *puVar16;
  undefined4 *puVar17;
  undefined4 uVar18;
  undefined4 *puVar19;
  undefined4 *puVar20;
  undefined1 uVar21;
  uint uVar22;
  int iVar23;
  bool bVar24;
  undefined8 uVar25;
  undefined8 uVar26;
  undefined8 uVar27;
  undefined8 uVar28;
  undefined8 uVar29;
  undefined4 local_1a8;
  undefined4 uStack_1a4;
  undefined4 local_1a0;
  undefined4 uStack_19c;
  undefined4 local_198;
  undefined4 uStack_194;
  undefined8 local_190;
  undefined4 local_188;
  undefined4 uStack_184;
  undefined8 local_180;
  undefined4 local_178;
  undefined4 uStack_174;
  undefined4 local_170;
  undefined4 uStack_16c;
  undefined4 local_168;
  undefined4 uStack_164;
  undefined4 local_160;
  undefined4 uStack_15c;
  undefined4 local_158;
  undefined4 uStack_154;
  undefined4 local_150;
  undefined4 uStack_14c;
  undefined1 auStack_148 [72];
  undefined1 auStack_100 [72];
  undefined1 auStack_b8 [64];
  undefined4 auStack_78 [2];
  undefined4 local_70 [19];
  
  if (((uint)param_1 & 3) == 0) {
    puVar5 = param_1 + 2;
    do {
      *(undefined4 *)(puVar5 + -2) = 0;
      *(undefined4 *)((int)puVar5 + -0xc) = 0;
      *(undefined4 *)(puVar5 + -1) = 0;
      *(undefined4 *)((int)puVar5 + -4) = 0;
      puVar5 = puVar5 + 2;
    } while (puVar5 != param_1 + 0x16);
    uVar10 = 8;
    puVar5 = param_1 + 0x14;
  }
  else {
    uVar10 = 0xa8;
    puVar5 = param_1;
  }
  FUN_00997590(puVar5,0,uVar10);
  sVar3 = *(short *)(param_2 + 0x38);
  if (((sVar3 != 0) && (*(short *)(param_2 + 0x3a) != 0)) &&
     (sVar4 = *(short *)(param_2 + 0x3e), sVar4 != 0)) {
    cVar1 = *param_2;
    bVar24 = cVar1 != '\0';
    pcVar9 = extraout_r1;
    if (bVar24) {
      pcVar9 = param_2;
    }
    pcVar12 = (char *)*param_3;
    while (bVar24) {
      cVar2 = *pcVar12;
      pcVar12 = pcVar12 + 1;
      if (cVar2 != cVar1) {
        return 0xfffffff5;
      }
      pcVar9 = pcVar9 + 1;
      cVar1 = *pcVar9;
      bVar24 = cVar1 != '\0';
    }
    if (*pcVar12 == '\0') {
      *(undefined4 **)(param_1 + 0x14) = param_3;
      uVar25 = FUN_009a616c();
      uVar10 = (undefined4)((ulonglong)uVar25 >> 0x20);
      uVar26 = FUN_009a6190(sVar3);
      uVar26 = FUN_009a6504((int)uVar25,uVar10,(int)uVar26,(int)((ulonglong)uVar26 >> 0x20));
      *param_1 = uVar26;
      uVar26 = 0x3ff0000000000000;
      *(undefined4 *)(param_1 + 1) = 0;
      *(undefined4 *)((int)param_1 + 0xc) = 0x3ff00000;
      uVar27 = FUN_009a6190(sVar4);
      uVar25 = FUN_009a6504((int)uVar25,uVar10,(int)uVar27,(int)((ulonglong)uVar27 >> 0x20));
      param_1[2] = uVar25;
      iVar6 = FUN_00993bd4(param_3 + 2,auStack_148);
      if (iVar6 == 0) {
        FUN_00992700(auStack_148,param_1,&local_1a8);
        uVar25 = FUN_009a5e5c(local_1a8,uStack_1a4);
        uVar25 = FUN_009a5e5c((int)uVar25,(int)((ulonglong)uVar25 >> 0x20),local_198,uStack_194);
        uVar13 = (undefined4)((ulonglong)uVar25 >> 0x20);
        uVar10 = (undefined4)uVar25;
        iVar6 = FUN_009a683c(uVar10,uVar13,0,0);
        if (iVar6 != 0) {
          uVar25 = FUN_009a6504(local_1a8,uStack_1a4,uVar10,uVar13);
          uVar7 = (undefined4)((ulonglong)uVar25 >> 0x20);
          uVar27 = FUN_009a6504(local_1a0,uStack_19c,uVar10,uVar13);
          uVar13 = (undefined4)((ulonglong)uVar27 >> 0x20);
          uVar10 = (undefined4)uVar27;
          local_190 = FUN_009a6504((int)uVar25,uVar7,uVar10,uVar13);
          local_188 = 0;
          uStack_184 = 0x3ff00000;
          uVar25 = FUN_009a5e58(0,0x3ff00000,(int)uVar25,uVar7);
          uVar25 = FUN_009a5e58((int)uVar25,(int)((ulonglong)uVar25 >> 0x20),uVar10,uVar13);
          local_180 = FUN_009a6504((int)uVar25,(int)((ulonglong)uVar25 >> 0x20),uVar10,uVar13);
          local_178 = 0x9b3e0ddb;
          uStack_174 = 0x3feedb82;
          local_168 = 0xc471f7dc;
          uStack_164 = 0x3fea6741;
          local_160 = 0x8c5f3dc7;
          uStack_15c = 0x3fee6a22;
          local_170 = 0;
          uStack_16c = 0x3ff00000;
          local_158 = 0;
          uStack_154 = 0x3ff00000;
          local_150 = 0xd1ef8103;
          uStack_14c = 0x3ff16cc7;
          FUN_00993fe0(&local_190,&local_178,auStack_100);
          FUN_00993a88(auStack_100,auStack_148,local_70);
          FUN_00993fe0(&local_178,&local_160,auStack_b8);
          FUN_00993a88(auStack_b8,local_70);
          FUN_00993a88(&DAT_009a8d18,local_70);
          uVar25 = FUN_009a5e5c(param_3[0x1a],param_3[0x1b],0x56041893,0x3fee2d0e);
          iVar6 = FUN_009a6854();
          uVar27 = FUN_009a6190();
          uVar27 = FUN_009a5e58((int)uVar25,(int)((ulonglong)uVar25 >> 0x20),(int)uVar27,
                                (int)((ulonglong)uVar27 >> 0x20));
          uVar25 = 0x3ff0000000000000;
          if (iVar6 < 1) {
            for (; uVar26 = uVar25, iVar6 != 0; iVar6 = iVar6 + 1) {
              uVar25 = FUN_009a6274((int)uVar26,(int)((ulonglong)uVar26 >> 0x20),0,0x3fe00000);
            }
          }
          else {
            do {
              uVar10 = (undefined4)((ulonglong)uVar26 >> 0x20);
              uVar26 = FUN_009a5e5c((int)uVar26,uVar10,(int)uVar26,uVar10);
              iVar6 = iVar6 + -1;
            } while (iVar6 != 0);
          }
          uVar28 = FUN_009a6274((int)uVar27,(int)((ulonglong)uVar27 >> 0x20),0xfefa39ef,0x3fe62e42);
          uVar27 = 0x3ff0000000000000;
          uVar25 = 0x3ff0000000000000;
          iVar6 = 1;
          do {
            uVar29 = FUN_009a6190(iVar6);
            uVar29 = FUN_009a6504((int)uVar28,(int)((ulonglong)uVar28 >> 0x20),(int)uVar29,
                                  (int)((ulonglong)uVar29 >> 0x20));
            uVar25 = FUN_009a6274((int)uVar25,(int)((ulonglong)uVar25 >> 0x20),(int)uVar29,
                                  (int)((ulonglong)uVar29 >> 0x20));
            uVar27 = FUN_009a5e5c((int)uVar27,(int)((ulonglong)uVar27 >> 0x20),(int)uVar25,
                                  (int)((ulonglong)uVar25 >> 0x20));
            iVar6 = iVar6 + 1;
          } while (iVar6 != 0x1e);
          uVar26 = FUN_009a6274((int)uVar27,(int)((ulonglong)uVar27 >> 0x20),(int)uVar26,
                                (int)((ulonglong)uVar26 >> 0x20));
          puVar17 = (undefined4 *)((int)param_1 + 0x5c);
          puVar5 = param_1 + 2;
          puVar19 = auStack_78;
          do {
            while( true ) {
              puVar20 = puVar19 + 2;
              uVar25 = FUN_009a6274((int)uVar26,(int)((ulonglong)uVar26 >> 0x20),*puVar20,puVar19[3]
                                   );
              puVar5 = puVar5 + 1;
              *puVar5 = uVar25;
              uVar25 = FUN_009a6274((int)uVar25,(int)((ulonglong)uVar25 >> 0x20),0,0x40b00000);
              uVar10 = (undefined4)((ulonglong)uVar25 >> 0x20);
              iVar6 = FUN_009a67f4((int)uVar25,uVar10,0,0);
              puVar19 = puVar20;
              if (iVar6 == 0) break;
              FUN_009a5e58();
              uVar10 = FUN_009a6854();
              puVar17 = puVar17 + 1;
              *puVar17 = uVar10;
              if (puVar5 == param_1 + 0xb) goto LAB_00994914;
            }
            FUN_009a5e5c((int)uVar25,uVar10,0,0x3fe00000);
            uVar10 = FUN_009a6854();
            puVar17 = puVar17 + 1;
            *puVar17 = uVar10;
          } while (puVar5 != param_1 + 0xb);
LAB_00994914:
          if ((uint)param_3[0x14] < (uint)param_3[0x15]) {
            uVar7 = FUN_009a69d8(((uint)(param_3[0x15] - param_3[0x14]) >> 1) + 0x10000000,0);
            uVar10 = *(undefined4 *)param_1;
            uVar13 = *(undefined4 *)((int)param_1 + 4);
            uVar15 = *(undefined4 *)(param_1 + 1);
            uVar18 = *(undefined4 *)((int)param_1 + 0xc);
            *(undefined4 *)((int)param_1 + 0x84) = uVar7;
            iVar6 = FUN_009a67f4(uVar10,uVar13,uVar15,uVar18);
            if (iVar6 != 0) {
              uVar13 = uVar18;
              uVar10 = uVar15;
            }
            uVar7 = *(undefined4 *)(param_1 + 2);
            uVar15 = *(undefined4 *)((int)param_1 + 0x14);
            iVar6 = FUN_009a67f4(uVar10,uVar13,uVar7,uVar15);
            if (iVar6 != 0) {
              uVar13 = uVar15;
              uVar10 = uVar7;
            }
            puVar19 = (undefined4 *)((int)param_1 + 0x84);
            puVar5 = param_1 + -1;
            do {
              puVar16 = puVar5 + 1;
              uVar26 = FUN_009a6504(*(undefined4 *)puVar16,*(undefined4 *)((int)puVar5 + 0xc),uVar10
                                    ,uVar13);
              uVar26 = FUN_009a6274((int)uVar26,(int)((ulonglong)uVar26 >> 0x20),0,0x40f00000);
              FUN_009a5e5c((int)uVar26,(int)((ulonglong)uVar26 >> 0x20),0,0x3fe00000);
              uVar7 = FUN_009a68b0();
              puVar19 = puVar19 + 1;
              *puVar19 = uVar7;
              puVar5 = puVar16;
            } while (param_1 + 2 != puVar16);
            iVar6 = 0;
            uVar11 = param_3[0x16];
            iVar14 = param_3[0x17];
            iVar23 = param_3[0x18];
            while( true ) {
              iVar8 = 0;
              while( true ) {
                uVar22 = uVar11 >> (((iVar23 + iVar6 + *(int *)(param_2 + 0x2c)) * 2 & 0xeU |
                                    iVar14 + iVar8 + *(int *)(param_2 + 0x28) & 1U) << 1) & 3;
                uVar21 = (undefined1)uVar22;
                if (uVar22 == 3) {
                  uVar21 = 1;
                }
                *(undefined1 *)
                 ((int)param_1 +
                 (iVar8 + *(int *)(param_2 + 0x28) & 1U) +
                 (iVar6 + *(int *)(param_2 + 0x2c) & 1U) * 2 + 0x9c) = uVar21;
                if (iVar8 == 1) break;
                iVar8 = 1;
              }
              if (iVar6 == 1) break;
              iVar6 = 1;
            }
            uVar11 = *(uint *)(param_2 + 0x30) >> 1;
            *(uint *)((int)param_1 + 0x94) = uVar11;
            uVar22 = *(uint *)(param_2 + 0x34) >> 1;
            *(uint *)(param_1 + 0x13) = uVar22;
            if (((0x887 < uVar11 - 1 || uVar22 == 0) || (0x1180 < *(uint *)(param_2 + 0x20))) ||
               ((*(int *)(param_2 + 0x28) == 0 ||
                ((*(int *)(param_2 + 0x2c) == 0 ||
                 (*(uint *)(param_2 + 0x20) < *(int *)(param_2 + 0x28) + 1 + uVar11 * 2)))))) {
              return 0xfffffff4;
            }
            if (*(uint *)(param_2 + 0x24) < *(int *)(param_2 + 0x2c) + 1 + uVar22 * 2) {
              uVar10 = 0xfffffff4;
            }
            else {
              uVar10 = 0;
            }
            return uVar10;
          }
        }
      }
    }
  }
  return 0xfffffff5;
}


// ===== FUN_00994b88 @ 00994b88

void FUN_00994b88(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined8 *puVar5;
  undefined4 *puVar6;
  undefined8 uVar7;
  undefined8 uStack_70;
  undefined4 local_68 [18];
  
  puVar5 = &uStack_70;
  puVar3 = (undefined4 *)(param_2 + -4);
  do {
    puVar3 = puVar3 + 1;
    uVar7 = FUN_009a6190(*puVar3);
    uVar7 = FUN_009a6274((int)uVar7,(int)((ulonglong)uVar7 >> 0x20),0,0x3f300000);
    puVar5 = puVar5 + 1;
    *puVar5 = uVar7;
  } while (puVar3 != (undefined4 *)(param_2 + 0x20));
  puVar6 = (undefined4 *)(param_1 + 0x5c);
  FUN_00993a88(local_68,param_1 + 0x18);
  puVar3 = (undefined4 *)(param_1 + 0x10);
  do {
    while( true ) {
      puVar4 = puVar3 + 2;
      uVar7 = FUN_009a6274(*puVar4,puVar3[3],0,0x40b00000);
      uVar2 = (undefined4)((ulonglong)uVar7 >> 0x20);
      iVar1 = FUN_009a67f4((int)uVar7,uVar2,0,0);
      puVar3 = puVar4;
      if (iVar1 != 0) break;
      FUN_009a5e5c((int)uVar7,uVar2,0,0x3fe00000);
      uVar2 = FUN_009a6854();
      puVar6 = puVar6 + 1;
      *puVar6 = uVar2;
      if (puVar4 == (undefined4 *)(param_1 + 0x58)) {
        return;
      }
    }
    FUN_009a5e58();
    uVar2 = FUN_009a6854();
    puVar6 = puVar6 + 1;
    *puVar6 = uVar2;
  } while (puVar4 != (undefined4 *)(param_1 + 0x58));
  return;
}


// ===== FUN_00994c68 @ 00994c68

uint FUN_00994c68(undefined4 param_1,int param_2,uint param_3,uint param_4)

{
  longlong lVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  bool bVar6;
  
  if (((int)param_4 < 0x80000) && ((int)(param_4 - 0x7ffff) <= (int)param_3)) {
    uVar4 = param_4 - param_3;
    if ((int)(param_4 * *(int *)(&DAT_009a8cc4 + param_2 * 4)) < (int)(uVar4 * 0x1000)) {
      iVar5 = (int)uVar4 >> 0x1f;
      goto LAB_00994ce8;
    }
  }
  else {
    lVar1 = (longlong)(int)param_4 * (longlong)*(int *)(&DAT_009a8cc4 + param_2 * 4);
    iVar2 = (int)((ulonglong)lVar1 >> 0x20);
    uVar4 = param_4 - param_3;
    iVar5 = ((int)param_4 >> 0x1f) - (((int)param_3 >> 0x1f) + (uint)(param_4 < param_3));
    bVar6 = (uint)lVar1 < uVar4 * 0x1000;
    uVar3 = iVar5 * 0x1000 | uVar4 >> 0x14;
    if ((int)(iVar2 - (uVar3 + bVar6)) < 0 !=
        (SBORROW4(iVar2,uVar3) != SBORROW4(iVar2 - uVar3,(uint)bVar6))) {
LAB_00994ce8:
      uVar3 = FUN_00991240(param_1,param_2,param_4,param_4,uVar4,iVar5);
      return uVar3;
    }
  }
  return param_3;
}


// ===== FUN_00994d0c @ 00994d0c

char * FUN_00994d0c(char *param_1)

{
  char *pcVar1;
  
  pcVar1 = "D250NX";
  while( true ) {
    while (((*pcVar1 != *param_1 || (pcVar1[1] != param_1[1])) || (pcVar1[2] != param_1[2]))) {
      pcVar1 = pcVar1 + 0x34;
      if (pcVar1 == "\x11") {
        return (char *)0x0;
      }
    }
    if (pcVar1[3] == param_1[3]) break;
    pcVar1 = pcVar1 + 0x34;
    if (pcVar1 == "\x11") {
      return (char *)0x0;
    }
  }
  return pcVar1;
}


// ===== FUN_00994d88 @ 00994d88

void FUN_00994d88(int param_1,int param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)(param_2 + -4);
  puVar1 = (undefined4 *)(param_1 + -4);
  do {
    puVar2 = puVar2 + 1;
    puVar1 = puVar1 + 1;
    *puVar1 = *puVar2;
  } while (puVar2 != (undefined4 *)(param_2 + 0x34));
  *(undefined4 *)(param_1 + 0x38) = 0;
  return;
}


// ===== FUN_00994db0 @ 00994db0

void FUN_00994db0(int *param_1,int param_2,int param_3,uint param_4)

{
  longlong lVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  uint uVar8;
  int *piVar9;
  
  iVar7 = 0;
  do {
    uVar8 = 0;
    do {
      while (uVar2 = *(uint *)(param_2 + (iVar7 + (uVar8 >> 5)) * 4),
            iVar3 = uVar2 + (uVar8 & 0x1f) * 0x2d0, (uVar2 & 3) == 0) {
        iVar5 = iVar3 + 0x10;
        do {
          *(undefined4 *)(iVar5 + -0x10) = 0;
          *(undefined4 *)(iVar5 + -0xc) = 0;
          *(undefined4 *)(iVar5 + -8) = 0;
          *(undefined4 *)(iVar5 + -4) = 0;
          iVar5 = iVar5 + 0x10;
        } while (iVar5 != iVar3 + 0x2e0);
        uVar8 = uVar8 + 1;
        if (uVar8 == 0xd5) goto LAB_00994e20;
      }
      uVar8 = uVar8 + 1;
      FUN_00997590(iVar3,0,0x2d0);
    } while (uVar8 != 0xd5);
LAB_00994e20:
    if (iVar7 != 0) {
      *(undefined4 *)(param_2 + 0x38) = 0;
      if ((param_4 & 3) == 0) {
        iVar7 = param_4 + 0x10;
        do {
          *(undefined4 *)(iVar7 + -0x10) = 0;
          *(undefined4 *)(iVar7 + -0xc) = 0;
          *(undefined4 *)(iVar7 + -8) = 0;
          *(undefined4 *)(iVar7 + -4) = 0;
          iVar7 = iVar7 + 0x10;
        } while (iVar7 != param_4 + 0x4100);
        uVar4 = 8;
        uVar8 = param_4 + 0x40f0;
      }
      else {
        uVar4 = 0x40f8;
        uVar8 = param_4;
      }
      FUN_00997590(uVar8,0,uVar4);
      iVar3 = *param_1;
      param_1[0x2073] = param_2;
      param_1[0x207f] = param_4;
      uVar2 = *(uint *)(iVar3 + 0x8c);
      param_1[0x2074] = param_3;
      lVar1 = (ulonglong)uVar2 * 0xf852;
      uVar8 = (uint)lVar1 >> 0x10 | (int)((ulonglong)lVar1 >> 0x20) << 0x10;
      param_1[0x2080] = param_4 + 0x2d00;
      param_1[0x2076] = uVar8;
      param_1[0x2083] = -1;
      param_1[0x2081] = 0;
      param_1[0x2075] = -1;
      param_1[0x2077] = -1;
      iVar7 = 0;
      if (uVar2 != uVar8) {
        iVar7 = FUN_009a5bf0(0x1000000);
      }
      param_1[0x2078] = iVar7;
      piVar6 = param_1 + 0x2078;
      do {
        iVar7 = iVar3 + 0x5c;
        piVar9 = piVar6;
        do {
          iVar5 = iVar7 + 4;
          piVar9 = piVar9 + 1;
          *piVar9 = *(int *)(iVar7 + 0x1c) * *(int *)(param_3 + 0xc) +
                    *(int *)(param_3 + 4) * *(int *)(iVar7 + 4) +
                    *(int *)(iVar7 + 0x10) * *(int *)(param_3 + 8);
          iVar7 = iVar5;
        } while (iVar5 != iVar3 + 0x68);
        piVar6 = piVar6 + 3;
        param_3 = param_3 + 0xc;
      } while (piVar6 != param_1 + 0x207e);
      return;
    }
    iVar7 = 7;
  } while( true );
}


// ===== FUN_00994f70 @ 00994f70

void FUN_00994f70(undefined4 *param_1,int param_2,undefined4 param_3,undefined4 param_4,int param_5,
                 undefined4 param_6)

{
  ushort *puVar1;
  ushort *puVar2;
  ushort *puVar3;
  ushort *puVar4;
  ushort uVar5;
  ushort uVar6;
  longlong lVar7;
  bool bVar8;
  undefined2 uVar9;
  int iVar10;
  uint uVar11;
  uint *puVar12;
  ushort *puVar13;
  ushort *puVar14;
  int *piVar15;
  uint uVar16;
  uint uVar17;
  undefined4 uVar18;
  ushort *puVar19;
  int iVar20;
  uint uVar21;
  int iVar22;
  ushort *puVar23;
  uint *puVar24;
  int iVar25;
  short *psVar26;
  uint *puVar27;
  uint uVar28;
  int iVar29;
  int iVar30;
  undefined2 *puVar31;
  uint *puVar32;
  int *piVar33;
  ushort *puVar34;
  ushort *puVar35;
  int iVar36;
  uint uVar37;
  undefined2 *puVar38;
  short *psVar39;
  int iVar40;
  ushort *puVar41;
  int iVar42;
  undefined2 *local_1160;
  undefined2 *local_115c;
  uint local_1154;
  uint *local_1150;
  int local_1140;
  int local_1118;
  uint auStack_1114 [363];
  undefined8 local_b68 [359];
  uint auStack_30 [3];
  
  param_1[1] = param_2;
  param_1[2] = param_4;
  param_1[3] = param_5;
  *param_1 = param_3;
  iVar20 = param_1[10];
  param_1[0xe] = 0xffffffff;
  param_1[0xf] = 0xffffffff;
  param_1[4] = param_6;
  param_1[0xb] = iVar20 + 0x6660;
  param_1[0xc] = iVar20 + 0x7740;
  param_1[0xd] = iVar20 + 0x8820;
  param_1[0x10] = 0;
  param_1[0x11] = 0;
  param_1[5] = iVar20 + 0x9900;
  if (param_5 != 0) {
    iVar25 = 0xb400;
    puVar32 = (uint *)(iVar20 + 0x98fc);
    do {
      iVar10 = FUN_009a5bf0(iVar25,param_5);
      uVar11 = iVar10 - 0x80U;
      if (0x166ff < (int)(iVar10 - 0x80U)) {
        uVar11 = 0x16700;
      }
      uVar11 = uVar11 & ~((int)uVar11 >> 0x1f);
      uVar16 = uVar11 >> 8;
      if (0x165 < uVar16) {
        uVar16 = 0x166;
      }
      puVar32 = puVar32 + 1;
      *puVar32 = uVar11 + uVar16 * -0x100 | uVar16 << 9;
      iVar25 = iVar25 + 0x16800;
    } while ((uint *)(iVar20 + param_5 * 4 + 0x98fc) != puVar32);
  }
  if (*(int *)(param_2 + 0x38) != 0) {
    return;
  }
  puVar32 = (uint *)&DAT_009a9274;
  piVar15 = &local_1118;
  iVar20 = 0;
LAB_00995074:
  bVar8 = false;
  puVar12 = puVar32;
  piVar33 = piVar15;
  do {
    psVar26 = (short *)((int)puVar12 + -2);
    puVar12 = (uint *)((int)puVar12 + 0x46);
    iVar25 = 0x11;
    puVar27 = puVar12;
    do {
      psVar26 = psVar26 + 1;
      if ((*psVar26 != 0) || (puVar27 = (uint *)((int)puVar27 + -2), *(short *)puVar27 != 0)) break;
      iVar25 = iVar25 + -1;
    } while (iVar25 != 0);
    *piVar33 = iVar25;
    if (bVar8) break;
    bVar8 = true;
    piVar33 = piVar33 + 1;
  } while( true );
  piVar15 = piVar15 + 2;
  puVar32 = puVar32 + 0x23;
  if (iVar20 == 0x8c) goto LAB_009951b0;
  iVar20 = 0x8c;
  goto LAB_00995074;
LAB_009951b0:
  iVar25 = param_1[9];
  iVar20 = param_1[8];
  local_1140 = 0;
LAB_009951ec:
  uVar11 = 1;
  puVar38 = (undefined2 *)(iVar20 + -2);
  do {
    puVar32 = (uint *)(*(int *)(param_2 + (local_1140 + (uVar11 - 1 >> 5)) * 4) +
                      (uVar11 - 1 & 0x1f) * 0x2d0);
    if (uVar11 == 0xd5) {
      puVar12 = puVar32;
    }
    iVar10 = 0;
    puVar31 = puVar38;
    if (uVar11 != 0xd5) {
      puVar12 = (uint *)(*(int *)(param_2 + (local_1140 + (uVar11 >> 5)) * 4) +
                        (uVar11 & 0x1f) * 0x2d0);
    }
    do {
      puVar34 = (ushort *)((int)puVar32 + iVar10);
      iVar22 = iVar10 + 2;
      puVar23 = (ushort *)((int)puVar12 + iVar10);
      iVar29 = iVar10 + 2;
      iVar10 = iVar10 + 4;
      puVar31[1] = (short)((uint)*(ushort *)((int)puVar32 + iVar22) + (uint)*puVar34 + 2 +
                           (uint)*puVar23 + (uint)*(ushort *)((int)puVar12 + iVar29) >> 2);
      puVar31 = puVar31 + 1;
    } while (iVar10 != 0x2d0);
    uVar11 = uVar11 + 2;
    puVar38 = puVar38 + 0xb4;
  } while (uVar11 != 0xd7);
  iVar10 = 9;
  psVar39 = (short *)&UNK_009a924c;
  psVar26 = &DAT_009a9274;
  do {
    psVar39 = psVar39 + 1;
    if ((*psVar39 != 0) || (psVar26 = psVar26 + -1, *psVar26 != 0)) break;
    iVar10 = iVar10 + -1;
  } while (iVar10 != 0);
  puVar34 = (ushort *)0x0;
  puVar38 = (undefined2 *)(iVar25 + -2);
  do {
    iVar22 = 0;
    puVar23 = puVar34;
    puVar31 = puVar38;
    puVar35 = puVar34;
    do {
      iVar29 = iVar22;
      if (8 < iVar22) {
        iVar29 = 9;
      }
      puVar13 = (ushort *)(&UNK_009a9238 + iVar29 * -2);
      if (iVar22 < 0xab) {
        puVar35 = (ushort *)0x9;
      }
      uVar11 = 0;
      if (0xaa < iVar22) {
        puVar35 = (ushort *)(0xb3 - iVar22);
      }
      puVar14 = puVar13;
      do {
        puVar14 = puVar14 + 1;
        uVar11 = uVar11 + *puVar14;
      } while (&DAT_009a923a + (int)puVar35 != puVar14);
      uVar16 = 0;
      puVar35 = (ushort *)(iVar20 + 2 + ((int)puVar23 + (int)puVar35) * 2);
      puVar14 = (ushort *)(iVar20 + ((int)puVar23 - iVar29) * 2);
      do {
        puVar19 = puVar14 + 1;
        puVar13 = puVar13 + 1;
        uVar16 = (uint)*puVar14 * (uint)*puVar13 + uVar16;
        puVar14 = puVar19;
      } while (puVar35 != puVar19);
      if (uVar11 == 0x8000) {
        uVar9 = (undefined2)(uVar16 + 0x4000 >> 0xf);
      }
      else {
        uVar9 = FUN_009a69d8((uVar11 >> 1) + uVar16,CARRY4(uVar11 >> 1,uVar16));
      }
      iVar22 = iVar22 + 1;
      puVar31 = puVar31 + 1;
      *puVar31 = uVar9;
      puVar23 = (ushort *)((int)puVar23 + 1);
    } while (iVar22 != 0xb4);
    puVar34 = puVar34 + 0x5a;
    puVar38 = puVar38 + 0xb4;
  } while (puVar34 != (ushort *)0x4b3c);
  iVar22 = 0;
  local_1160 = (undefined2 *)(iVar20 + -2);
  do {
    if (iVar10 < iVar22) {
      iVar29 = iVar10;
    }
    else {
      iVar29 = iVar22;
    }
    iVar36 = iVar10;
    if (0x6a < (uint)(iVar10 + iVar22)) {
      iVar36 = 0x6a - iVar22;
    }
    uVar11 = 0;
    puVar34 = (ushort *)(&DAT_009a925e + iVar29 * -2);
    do {
      puVar34 = puVar34 + 1;
      uVar11 = uVar11 + *puVar34;
    } while (&DAT_009a9260 + iVar36 != puVar34);
    puVar34 = (ushort *)(iVar25 + (iVar22 - iVar29) * 0x168);
    puVar38 = local_1160;
    do {
      uVar16 = 0;
      puVar23 = (ushort *)(&DAT_009a925e + iVar29 * -2);
      puVar35 = puVar34;
      do {
        puVar23 = puVar23 + 1;
        uVar16 = (uint)*puVar35 * (uint)*puVar23 + uVar16;
        puVar35 = puVar35 + 0xb4;
      } while (&DAT_009a9260 + iVar36 != puVar23);
      if (uVar11 == 0x8000) {
        uVar9 = (undefined2)(uVar16 + 0x4000 >> 0xf);
      }
      else {
        uVar9 = FUN_009a69d8((uVar11 >> 1) + uVar16,CARRY4(uVar11 >> 1,uVar16),uVar11,0);
      }
      puVar34 = puVar34 + 1;
      puVar38 = puVar38 + 1;
      *puVar38 = uVar9;
    } while ((ushort *)(iVar25 + 0x168 + (iVar22 - iVar29) * 0x168) != puVar34);
    iVar22 = iVar22 + 1;
    local_1160 = local_1160 + 0xb4;
  } while (iVar22 != 0x6b);
  local_1154 = 0;
  uVar11 = 0xffffffff;
LAB_009954d8:
  if ((int)uVar11 <= (int)(local_1154 + 0x10)) {
    while ((int)uVar11 < 0xd4) {
      uVar11 = uVar11 + 1;
      iVar10 = *(int *)(param_2 + (local_1140 + (uVar11 >> 5)) * 4) + (uVar11 & 0x1f) * 0x2d0;
      piVar33 = param_1 + 5;
      puVar38 = &DAT_009a9274;
      piVar15 = &local_1118;
      do {
        iVar29 = 0;
        piVar33 = piVar33 + 1;
        iVar22 = *piVar15;
        puVar34 = puVar38 + 0x11;
        iVar36 = *piVar33 + ((int)uVar11 % 0x23) * 0x2d0;
LAB_00995580:
        iVar30 = iVar29;
        if ((iVar22 != iVar29) || (iVar29 = 0x168 - iVar22, iVar29 <= iVar22)) goto LAB_00995594;
        iVar30 = iVar10 + -2;
        iVar42 = iVar30 + iVar22 * 2;
        iVar40 = (uint)*(ushort *)(iVar42 + 2) * (uint)(ushort)puVar38[0x11];
        puVar23 = (ushort *)(iVar30 + iVar29 * 2);
        puVar35 = (ushort *)(iVar42 + 2);
        puVar31 = (undefined2 *)(iVar36 + -2 + iVar22 * 2);
        if (0 < iVar22) {
          puVar13 = puVar34 + iVar22;
          do {
            uVar16 = ((uint)((int)puVar13 + (-2 - (int)puVar34)) >> 1) + 1 & 3;
            puVar14 = puVar35;
            puVar19 = puVar35;
            puVar41 = puVar34;
            if (uVar16 == 0) {
LAB_009958b4:
              do {
                puVar1 = puVar41 + 1;
                puVar2 = puVar41 + 2;
                puVar3 = puVar41 + 3;
                puVar4 = puVar41 + 4;
                puVar41 = puVar41 + 4;
                iVar40 = (uint)*puVar4 * ((uint)puVar14[-4] + (uint)puVar19[4]) +
                         (uint)*puVar3 * ((uint)puVar14[-3] + (uint)puVar19[3]) +
                         (uint)*puVar2 * ((uint)puVar14[-2] + (uint)puVar19[2]) +
                         (uint)*puVar1 * ((uint)puVar14[-1] + (uint)puVar19[1]) + iVar40;
                puVar19 = puVar19 + 4;
                puVar14 = puVar14 + -4;
              } while (puVar41 != puVar13);
            }
            else {
              if (uVar16 != 1) {
                if (uVar16 != 2) {
                  iVar40 = (uint)(ushort)puVar38[0x12] * ((uint)puVar35[-1] + (uint)puVar35[1]) +
                           iVar40;
                  puVar14 = puVar35 + -1;
                  puVar41 = puVar38 + 0x12;
                  puVar19 = puVar35 + 1;
                }
                puVar14 = puVar14 + -1;
                puVar19 = puVar19 + 1;
                puVar41 = puVar41 + 1;
                iVar40 = (uint)*puVar41 * ((uint)*puVar14 + (uint)*puVar19) + iVar40;
              }
              puVar41 = puVar41 + 1;
              puVar14 = puVar14 + -1;
              puVar19 = puVar19 + 1;
              iVar40 = (uint)*puVar41 * ((uint)*puVar14 + (uint)*puVar19) + iVar40;
              if (puVar41 != puVar13) goto LAB_009958b4;
            }
            puVar31 = puVar31 + 1;
            *puVar31 = (short)(iVar40 + 0x4000U >> 0xf);
            if (puVar23 == puVar35) goto LAB_00995948;
            puVar35 = puVar35 + 1;
            iVar40 = (uint)(ushort)puVar38[0x11] * (uint)*puVar35;
          } while( true );
        }
        while( true ) {
          puVar31 = puVar31 + 1;
          *puVar31 = (short)(iVar40 + 0x4000U >> 0xf);
          if (puVar23 == puVar35) break;
          puVar35 = puVar35 + 1;
          iVar40 = (uint)(ushort)puVar38[0x11] * (uint)*puVar35;
        }
LAB_00995644:
        piVar15 = piVar15 + 2;
        puVar38 = puVar38 + 0x46;
      } while (piVar33 != param_1 + 7);
      if (uVar11 == local_1154 + 0x11) break;
    }
  }
  iVar10 = (int)local_1154 >> 1;
  puVar27 = auStack_1114 + 0x169;
  uVar16 = 0;
  puVar32 = puVar27;
  do {
    uVar17 = (int)uVar16 >> 1;
    iVar22 = iVar10;
    iVar29 = iVar10;
    if ((uVar16 & 1) == 0) {
      uVar17 = uVar17 - 1;
      if ((local_1154 & 1) != 0) {
        iVar36 = 3;
        iVar30 = 1;
        iVar22 = iVar10 + 1;
        goto LAB_009956c4;
      }
      iVar30 = 1;
      iVar36 = 3;
      iVar29 = iVar10 + -1;
      iVar40 = 1;
      iVar42 = 3;
    }
    else if ((local_1154 & 1) == 0) {
      iVar36 = 1;
      iVar30 = 3;
      iVar29 = iVar10 + -1;
LAB_009956c4:
      iVar40 = iVar36;
      iVar42 = iVar30;
    }
    else {
      iVar42 = 1;
      iVar30 = 3;
      iVar36 = 1;
      iVar40 = 3;
      iVar22 = iVar10 + 1;
    }
    uVar37 = uVar17;
    if (0xb1 < (int)uVar17) {
      uVar37 = 0xb2;
    }
    iVar29 = (int)(short)((ushort)iVar29 & ~(ushort)(iVar29 >> 0x1f));
    uVar17 = uVar17 & ~((int)uVar17 >> 0x1f);
    puVar32 = puVar32 + 2;
    uVar16 = uVar16 + 1;
    *(longlong *)puVar32 =
         (longlong)
         (int)(iVar42 * (iVar36 * (uint)*(ushort *)
                                         (iVar20 + (uVar37 + 1 + (short)iVar22 * 0xb4) * 2) +
                        iVar30 * (uint)*(ushort *)(iVar20 + (uVar17 + (short)iVar22 * 0xb4) * 2)) +
               iVar40 * (iVar36 * (uint)*(ushort *)(iVar20 + (uVar37 + 1 + iVar29 * 0xb4) * 2) +
                        iVar30 * (uint)*(ushort *)(iVar20 + (uVar17 + iVar29 * 0xb4) * 2)) + 8 >> 4)
         * 0x38e4;
  } while (puVar32 != auStack_30);
  local_115c = &DAT_009a92ba;
  local_1160 = (undefined2 *)0x0;
  local_1150 = &DAT_009a9418;
  do {
    uVar16 = auStack_1114[(int)local_1160 * 2];
    if ((int)uVar16 < (int)local_1154) {
      uVar17 = uVar16;
    }
    else {
      uVar17 = local_1154;
    }
    iVar10 = -uVar17;
    if ((int)(uVar16 + local_1154) < 0xd5) {
      if (iVar10 <= (int)uVar16) goto LAB_00995a28;
      FUN_00997590(auStack_1114 + 3,0,0x5a0);
      uVar37 = 0;
    }
    else {
      uVar16 = 0xd4 - local_1154;
LAB_00995a28:
      uVar37 = 0;
      puVar34 = local_115c + (0x10 - uVar17);
      do {
        puVar34 = puVar34 + 1;
        uVar37 = uVar37 + *puVar34;
      } while (local_115c + uVar16 + 0x11 != puVar34);
      FUN_00997590(auStack_1114 + 3,0,0x5a0);
      puVar34 = local_115c + (0x11 - uVar17);
      iVar22 = local_1154 - uVar17;
      do {
        if (iVar10 < 0) {
          if (-uVar16 != iVar10 && (int)uVar16 <= -iVar10) {
            iVar29 = param_1[(int)local_1160 + 6] + iVar22 * 0x2d0 + (iVar22 / 0x23) * -0x6270;
            uVar28 = (uint)*puVar34;
            goto LAB_00995ca4;
          }
        }
        else {
          uVar28 = (uint)*puVar34;
          iVar29 = param_1[(int)local_1160 + 6] + (iVar22 % 0x23) * 0x2d0;
          if ((int)uVar17 < iVar10 || iVar10 == 0) {
LAB_00995ca4:
            puVar23 = (ushort *)(iVar29 + -2);
            puVar32 = auStack_1114 + 2;
            do {
              puVar32 = puVar32 + 1;
              puVar23 = puVar23 + 1;
              *puVar32 = uVar28 * *puVar23 + *puVar32;
            } while (auStack_1114 + 0x16a != puVar32);
          }
          else {
            puVar23 = (ushort *)
                      (param_1[(int)local_1160 + 6] + -2 +
                      ((int)(local_1154 - iVar10) % 0x23) * 0x2d0);
            puVar32 = auStack_1114 + 2;
            puVar35 = (ushort *)(iVar29 + -2);
            do {
              puVar12 = puVar32 + 4;
              uVar5 = puVar23[2];
              puVar32[1] = uVar28 * ((uint)puVar35[1] + (uint)puVar23[1]) + puVar32[1];
              uVar6 = puVar23[3];
              puVar32[2] = uVar28 * ((uint)puVar35[2] + (uint)uVar5) + puVar32[2];
              uVar5 = puVar23[4];
              puVar32[3] = uVar28 * ((uint)puVar35[3] + (uint)uVar6) + puVar32[3];
              *puVar12 = uVar28 * ((uint)puVar35[4] + (uint)uVar5) + *puVar12;
              puVar23 = puVar23 + 4;
              puVar32 = puVar12;
              puVar35 = puVar35 + 4;
            } while (auStack_1114 + 0x16a != puVar12);
          }
        }
        iVar10 = iVar10 + 1;
        puVar34 = puVar34 + 1;
        iVar22 = iVar22 + 1;
      } while (iVar10 != uVar16 + 1);
    }
    uVar16 = *local_1150;
    puVar12 = auStack_1114 + 2;
    puVar32 = puVar27;
    do {
      puVar12 = puVar12 + 1;
      uVar17 = *puVar12;
      if (uVar37 == 0x8000) {
        uVar17 = uVar17 + 0x4000 >> 0xf | (uint)(0xffffbfff < uVar17) << 0x11;
      }
      else {
        uVar17 = FUN_009a69d8((uVar37 >> 1) + uVar17,CARRY4(uVar37 >> 1,uVar17),uVar37,0);
      }
      lVar7 = (ulonglong)uVar17 * (ulonglong)uVar16;
      uVar28 = (uint)lVar7;
      puVar24 = puVar32 + 2;
      uVar21 = *puVar24;
      *puVar24 = uVar21 + uVar28;
      puVar32[3] = uVar17 * ((int)uVar16 >> 0x1f) + (int)((ulonglong)lVar7 >> 0x20) + puVar32[3] +
                   (uint)CARRY4(uVar21,uVar28);
      puVar32 = puVar24;
    } while (puVar12 != auStack_1114 + 0x16a);
    local_115c = local_115c + 0x46;
    if (local_1160 == (undefined2 *)0x1) goto code_r0x009950ec;
    local_1160 = (undefined2 *)0x1;
    local_1150 = local_1150 + 1;
  } while( true );
LAB_00995948:
  iVar30 = iVar29;
LAB_00995594:
  if (iVar30 < iVar22) {
    iVar29 = iVar30;
  }
  else {
    iVar29 = iVar22;
  }
  iVar40 = iVar22;
  if (0x167 < iVar30 + iVar22) {
    iVar40 = 0x164 - iVar30;
  }
  if (0x167 < iVar30 + iVar22) {
    iVar40 = iVar40 + 3;
  }
  if (-iVar40 == iVar29 || -iVar29 < iVar40) {
    puVar35 = puVar38 + (0x10 - iVar29);
    uVar16 = 0;
    puVar23 = puVar35;
    do {
      puVar23 = puVar23 + 1;
      uVar16 = uVar16 + *puVar23;
    } while (puVar23 != puVar34 + iVar40);
    uVar17 = 0;
    puVar23 = (ushort *)(iVar10 + (iVar30 - iVar29) * 2);
    do {
      puVar35 = puVar35 + 1;
      uVar17 = (uint)*puVar23 * (uint)*puVar35 + uVar17;
      puVar23 = puVar23 + 1;
    } while (puVar35 != puVar34 + iVar40);
    if (uVar16 == 0x8000) {
      uVar9 = (undefined2)(uVar17 + 0x4000 >> 0xf);
      goto LAB_00995628;
    }
    iVar29 = (uVar16 >> 1) + uVar17;
    if (CARRY4(uVar16 >> 1,uVar17)) {
      uVar18 = 1;
    }
    else {
      uVar18 = 0;
    }
  }
  else {
    uVar16 = 0;
    iVar29 = 0;
    uVar18 = 0;
  }
  uVar9 = FUN_009a69d8(iVar29,uVar18,uVar16,0);
LAB_00995628:
  iVar29 = iVar30 + 1;
  *(undefined2 *)(iVar36 + iVar30 * 2) = uVar9;
  if (iVar29 == 0x168) goto LAB_00995644;
  goto LAB_00995580;
code_r0x009950ec:
  puVar38 = (undefined2 *)
            (*(int *)(param_2 + (local_1140 + (local_1154 >> 5)) * 4) +
            (local_1154 & 0x1f) * 0x2d0 + -2);
  do {
    puVar32 = puVar27 + 2;
    iVar22 = puVar27[3] + (uint)(0xffffbfff < *puVar32);
    iVar10 = iVar22 >> 0xf;
    uVar16 = *puVar32 + 0x4000 >> 0xf | iVar22 * 0x20000;
    if (iVar10 < 0) {
      uVar16 = 0;
    }
    else if ((int)(uint)(uVar16 < 0x10000) <= iVar10) {
      uVar16 = 0xffff;
    }
    puVar12 = auStack_30;
    puVar38 = puVar38 + 1;
    *puVar38 = (short)uVar16;
    puVar27 = puVar32;
  } while (puVar12 != puVar32);
  local_1154 = local_1154 + 1;
  if (local_1154 == 0xd5) goto code_r0x0099517c;
  goto LAB_009954d8;
code_r0x0099517c:
  if (local_1140 != 0) {
    *(undefined4 *)(param_2 + 0x38) = 1;
    return;
  }
  local_1140 = 7;
  goto LAB_009951ec;
}


// ===== FUN_00994f74 @ 00994f74

void FUN_00994f74(int param_1,int param_2,undefined4 param_3,undefined4 param_4,int param_5,
                 undefined4 param_6)

{
  ushort *puVar1;
  ushort *puVar2;
  ushort *puVar3;
  ushort *puVar4;
  ushort uVar5;
  ushort uVar6;
  longlong lVar7;
  bool bVar8;
  undefined2 uVar9;
  int iVar10;
  uint uVar11;
  uint *puVar12;
  ushort *puVar13;
  ushort *puVar14;
  int *piVar15;
  uint uVar16;
  uint uVar17;
  undefined4 uVar18;
  ushort *puVar19;
  int iVar20;
  uint uVar21;
  int iVar22;
  ushort *puVar23;
  uint *puVar24;
  int iVar25;
  short *psVar26;
  uint *puVar27;
  uint uVar28;
  int iVar29;
  int iVar30;
  undefined2 *puVar31;
  uint *puVar32;
  ushort *puVar33;
  ushort *puVar34;
  int iVar35;
  uint uVar36;
  undefined2 *puVar37;
  undefined4 *in_r12;
  short *psVar38;
  int *piVar39;
  int iVar40;
  ushort *puVar41;
  int iVar42;
  undefined2 *local_1160;
  undefined2 *local_115c;
  uint local_1154;
  uint *local_1150;
  int local_1140;
  int local_1118;
  uint auStack_1114 [363];
  undefined8 local_b68 [359];
  uint auStack_30 [3];
  
  in_r12[1] = param_2;
  in_r12[2] = param_4;
  in_r12[3] = param_5;
  *in_r12 = param_3;
  iVar20 = in_r12[10];
  in_r12[0xe] = 0xffffffff;
  in_r12[0xf] = 0xffffffff;
  in_r12[4] = param_6;
  in_r12[0xb] = iVar20 + 0x6660;
  in_r12[0xc] = iVar20 + 0x7740;
  in_r12[0xd] = iVar20 + 0x8820;
  in_r12[0x10] = 0;
  in_r12[0x11] = 0;
  in_r12[5] = iVar20 + 0x9900;
  if (param_5 != 0) {
    iVar25 = 0xb400;
    puVar32 = (uint *)(iVar20 + 0x98fc);
    do {
      iVar10 = FUN_009a5bf0(iVar25,param_5);
      uVar11 = iVar10 - 0x80U;
      if (0x166ff < (int)(iVar10 - 0x80U)) {
        uVar11 = 0x16700;
      }
      uVar11 = uVar11 & ~((int)uVar11 >> 0x1f);
      uVar16 = uVar11 >> 8;
      if (0x165 < uVar16) {
        uVar16 = 0x166;
      }
      puVar32 = puVar32 + 1;
      *puVar32 = uVar11 + uVar16 * -0x100 | uVar16 << 9;
      iVar25 = iVar25 + 0x16800;
    } while ((uint *)(iVar20 + param_5 * 4 + 0x98fc) != puVar32);
  }
  if (*(int *)(param_2 + 0x38) != 0) {
    return;
  }
  puVar32 = (uint *)&DAT_009a9274;
  piVar15 = &local_1118;
  iVar20 = 0;
LAB_00995074:
  bVar8 = false;
  puVar12 = puVar32;
  piVar39 = piVar15;
  do {
    psVar26 = (short *)((int)puVar12 + -2);
    puVar12 = (uint *)((int)puVar12 + 0x46);
    iVar25 = 0x11;
    puVar27 = puVar12;
    do {
      psVar26 = psVar26 + 1;
      if ((*psVar26 != 0) || (puVar27 = (uint *)((int)puVar27 + -2), *(short *)puVar27 != 0)) break;
      iVar25 = iVar25 + -1;
    } while (iVar25 != 0);
    *piVar39 = iVar25;
    if (bVar8) break;
    bVar8 = true;
    piVar39 = piVar39 + 1;
  } while( true );
  piVar15 = piVar15 + 2;
  puVar32 = puVar32 + 0x23;
  if (iVar20 == 0x8c) goto LAB_009951b0;
  iVar20 = 0x8c;
  goto LAB_00995074;
LAB_009951b0:
  iVar25 = *(int *)(param_1 + 0x24);
  iVar20 = *(int *)(param_1 + 0x20);
  local_1140 = 0;
LAB_009951ec:
  uVar11 = 1;
  puVar37 = (undefined2 *)(iVar20 + -2);
  do {
    puVar32 = (uint *)(*(int *)(param_2 + (local_1140 + (uVar11 - 1 >> 5)) * 4) +
                      (uVar11 - 1 & 0x1f) * 0x2d0);
    if (uVar11 == 0xd5) {
      puVar12 = puVar32;
    }
    iVar10 = 0;
    puVar31 = puVar37;
    if (uVar11 != 0xd5) {
      puVar12 = (uint *)(*(int *)(param_2 + (local_1140 + (uVar11 >> 5)) * 4) +
                        (uVar11 & 0x1f) * 0x2d0);
    }
    do {
      puVar33 = (ushort *)((int)puVar32 + iVar10);
      iVar22 = iVar10 + 2;
      puVar23 = (ushort *)((int)puVar12 + iVar10);
      iVar29 = iVar10 + 2;
      iVar10 = iVar10 + 4;
      puVar31[1] = (short)((uint)*(ushort *)((int)puVar32 + iVar22) + (uint)*puVar33 + 2 +
                           (uint)*puVar23 + (uint)*(ushort *)((int)puVar12 + iVar29) >> 2);
      puVar31 = puVar31 + 1;
    } while (iVar10 != 0x2d0);
    uVar11 = uVar11 + 2;
    puVar37 = puVar37 + 0xb4;
  } while (uVar11 != 0xd7);
  iVar10 = 9;
  psVar38 = (short *)&UNK_009a924c;
  psVar26 = &DAT_009a9274;
  do {
    psVar38 = psVar38 + 1;
    if ((*psVar38 != 0) || (psVar26 = psVar26 + -1, *psVar26 != 0)) break;
    iVar10 = iVar10 + -1;
  } while (iVar10 != 0);
  puVar33 = (ushort *)0x0;
  puVar37 = (undefined2 *)(iVar25 + -2);
  do {
    iVar22 = 0;
    puVar23 = puVar33;
    puVar31 = puVar37;
    puVar34 = puVar33;
    do {
      iVar29 = iVar22;
      if (8 < iVar22) {
        iVar29 = 9;
      }
      puVar13 = (ushort *)(&UNK_009a9238 + iVar29 * -2);
      if (iVar22 < 0xab) {
        puVar34 = (ushort *)0x9;
      }
      uVar11 = 0;
      if (0xaa < iVar22) {
        puVar34 = (ushort *)(0xb3 - iVar22);
      }
      puVar14 = puVar13;
      do {
        puVar14 = puVar14 + 1;
        uVar11 = uVar11 + *puVar14;
      } while (&DAT_009a923a + (int)puVar34 != puVar14);
      uVar16 = 0;
      puVar34 = (ushort *)(iVar20 + 2 + ((int)puVar23 + (int)puVar34) * 2);
      puVar14 = (ushort *)(iVar20 + ((int)puVar23 - iVar29) * 2);
      do {
        puVar19 = puVar14 + 1;
        puVar13 = puVar13 + 1;
        uVar16 = (uint)*puVar14 * (uint)*puVar13 + uVar16;
        puVar14 = puVar19;
      } while (puVar34 != puVar19);
      if (uVar11 == 0x8000) {
        uVar9 = (undefined2)(uVar16 + 0x4000 >> 0xf);
      }
      else {
        uVar9 = FUN_009a69d8((uVar11 >> 1) + uVar16,CARRY4(uVar11 >> 1,uVar16));
      }
      iVar22 = iVar22 + 1;
      puVar31 = puVar31 + 1;
      *puVar31 = uVar9;
      puVar23 = (ushort *)((int)puVar23 + 1);
    } while (iVar22 != 0xb4);
    puVar33 = puVar33 + 0x5a;
    puVar37 = puVar37 + 0xb4;
  } while (puVar33 != (ushort *)0x4b3c);
  iVar22 = 0;
  local_1160 = (undefined2 *)(iVar20 + -2);
  do {
    if (iVar10 < iVar22) {
      iVar29 = iVar10;
    }
    else {
      iVar29 = iVar22;
    }
    iVar35 = iVar10;
    if (0x6a < (uint)(iVar10 + iVar22)) {
      iVar35 = 0x6a - iVar22;
    }
    uVar11 = 0;
    puVar33 = (ushort *)(&DAT_009a925e + iVar29 * -2);
    do {
      puVar33 = puVar33 + 1;
      uVar11 = uVar11 + *puVar33;
    } while (&DAT_009a9260 + iVar35 != puVar33);
    puVar33 = (ushort *)(iVar25 + (iVar22 - iVar29) * 0x168);
    puVar37 = local_1160;
    do {
      uVar16 = 0;
      puVar23 = (ushort *)(&DAT_009a925e + iVar29 * -2);
      puVar34 = puVar33;
      do {
        puVar23 = puVar23 + 1;
        uVar16 = (uint)*puVar34 * (uint)*puVar23 + uVar16;
        puVar34 = puVar34 + 0xb4;
      } while (&DAT_009a9260 + iVar35 != puVar23);
      if (uVar11 == 0x8000) {
        uVar9 = (undefined2)(uVar16 + 0x4000 >> 0xf);
      }
      else {
        uVar9 = FUN_009a69d8((uVar11 >> 1) + uVar16,CARRY4(uVar11 >> 1,uVar16),uVar11,0);
      }
      puVar33 = puVar33 + 1;
      puVar37 = puVar37 + 1;
      *puVar37 = uVar9;
    } while ((ushort *)(iVar25 + 0x168 + (iVar22 - iVar29) * 0x168) != puVar33);
    iVar22 = iVar22 + 1;
    local_1160 = local_1160 + 0xb4;
  } while (iVar22 != 0x6b);
  local_1154 = 0;
  uVar11 = 0xffffffff;
LAB_009954d8:
  if ((int)uVar11 <= (int)(local_1154 + 0x10)) {
    while ((int)uVar11 < 0xd4) {
      uVar11 = uVar11 + 1;
      iVar10 = *(int *)(param_2 + (local_1140 + (uVar11 >> 5)) * 4) + (uVar11 & 0x1f) * 0x2d0;
      piVar39 = (int *)(param_1 + 0x14);
      puVar37 = &DAT_009a9274;
      piVar15 = &local_1118;
      do {
        iVar29 = 0;
        piVar39 = piVar39 + 1;
        iVar22 = *piVar15;
        puVar33 = puVar37 + 0x11;
        iVar35 = *piVar39 + ((int)uVar11 % 0x23) * 0x2d0;
LAB_00995580:
        iVar30 = iVar29;
        if ((iVar22 != iVar29) || (iVar29 = 0x168 - iVar22, iVar29 <= iVar22)) goto LAB_00995594;
        iVar30 = iVar10 + -2;
        iVar42 = iVar30 + iVar22 * 2;
        iVar40 = (uint)*(ushort *)(iVar42 + 2) * (uint)(ushort)puVar37[0x11];
        puVar23 = (ushort *)(iVar30 + iVar29 * 2);
        puVar34 = (ushort *)(iVar42 + 2);
        puVar31 = (undefined2 *)(iVar35 + -2 + iVar22 * 2);
        if (0 < iVar22) {
          puVar13 = puVar33 + iVar22;
          do {
            uVar16 = ((uint)((int)puVar13 + (-2 - (int)puVar33)) >> 1) + 1 & 3;
            puVar14 = puVar34;
            puVar19 = puVar34;
            puVar41 = puVar33;
            if (uVar16 == 0) {
LAB_009958b4:
              do {
                puVar1 = puVar41 + 1;
                puVar2 = puVar41 + 2;
                puVar3 = puVar41 + 3;
                puVar4 = puVar41 + 4;
                puVar41 = puVar41 + 4;
                iVar40 = (uint)*puVar4 * ((uint)puVar14[-4] + (uint)puVar19[4]) +
                         (uint)*puVar3 * ((uint)puVar14[-3] + (uint)puVar19[3]) +
                         (uint)*puVar2 * ((uint)puVar14[-2] + (uint)puVar19[2]) +
                         (uint)*puVar1 * ((uint)puVar14[-1] + (uint)puVar19[1]) + iVar40;
                puVar19 = puVar19 + 4;
                puVar14 = puVar14 + -4;
              } while (puVar41 != puVar13);
            }
            else {
              if (uVar16 != 1) {
                if (uVar16 != 2) {
                  iVar40 = (uint)(ushort)puVar37[0x12] * ((uint)puVar34[-1] + (uint)puVar34[1]) +
                           iVar40;
                  puVar14 = puVar34 + -1;
                  puVar41 = puVar37 + 0x12;
                  puVar19 = puVar34 + 1;
                }
                puVar14 = puVar14 + -1;
                puVar19 = puVar19 + 1;
                puVar41 = puVar41 + 1;
                iVar40 = (uint)*puVar41 * ((uint)*puVar14 + (uint)*puVar19) + iVar40;
              }
              puVar41 = puVar41 + 1;
              puVar14 = puVar14 + -1;
              puVar19 = puVar19 + 1;
              iVar40 = (uint)*puVar41 * ((uint)*puVar14 + (uint)*puVar19) + iVar40;
              if (puVar41 != puVar13) goto LAB_009958b4;
            }
            puVar31 = puVar31 + 1;
            *puVar31 = (short)(iVar40 + 0x4000U >> 0xf);
            if (puVar23 == puVar34) goto LAB_00995948;
            puVar34 = puVar34 + 1;
            iVar40 = (uint)(ushort)puVar37[0x11] * (uint)*puVar34;
          } while( true );
        }
        while( true ) {
          puVar31 = puVar31 + 1;
          *puVar31 = (short)(iVar40 + 0x4000U >> 0xf);
          if (puVar23 == puVar34) break;
          puVar34 = puVar34 + 1;
          iVar40 = (uint)(ushort)puVar37[0x11] * (uint)*puVar34;
        }
LAB_00995644:
        piVar15 = piVar15 + 2;
        puVar37 = puVar37 + 0x46;
      } while (piVar39 != (int *)(param_1 + 0x1c));
      if (uVar11 == local_1154 + 0x11) break;
    }
  }
  iVar10 = (int)local_1154 >> 1;
  puVar27 = auStack_1114 + 0x169;
  uVar16 = 0;
  puVar32 = puVar27;
  do {
    uVar17 = (int)uVar16 >> 1;
    iVar22 = iVar10;
    iVar29 = iVar10;
    if ((uVar16 & 1) == 0) {
      uVar17 = uVar17 - 1;
      if ((local_1154 & 1) != 0) {
        iVar35 = 3;
        iVar30 = 1;
        iVar22 = iVar10 + 1;
        goto LAB_009956c4;
      }
      iVar30 = 1;
      iVar35 = 3;
      iVar29 = iVar10 + -1;
      iVar40 = 1;
      iVar42 = 3;
    }
    else if ((local_1154 & 1) == 0) {
      iVar35 = 1;
      iVar30 = 3;
      iVar29 = iVar10 + -1;
LAB_009956c4:
      iVar40 = iVar35;
      iVar42 = iVar30;
    }
    else {
      iVar42 = 1;
      iVar30 = 3;
      iVar35 = 1;
      iVar40 = 3;
      iVar22 = iVar10 + 1;
    }
    uVar36 = uVar17;
    if (0xb1 < (int)uVar17) {
      uVar36 = 0xb2;
    }
    iVar29 = (int)(short)((ushort)iVar29 & ~(ushort)(iVar29 >> 0x1f));
    uVar17 = uVar17 & ~((int)uVar17 >> 0x1f);
    puVar32 = puVar32 + 2;
    uVar16 = uVar16 + 1;
    *(longlong *)puVar32 =
         (longlong)
         (int)(iVar42 * (iVar35 * (uint)*(ushort *)
                                         (iVar20 + (uVar36 + 1 + (short)iVar22 * 0xb4) * 2) +
                        iVar30 * (uint)*(ushort *)(iVar20 + (uVar17 + (short)iVar22 * 0xb4) * 2)) +
               iVar40 * (iVar35 * (uint)*(ushort *)(iVar20 + (uVar36 + 1 + iVar29 * 0xb4) * 2) +
                        iVar30 * (uint)*(ushort *)(iVar20 + (uVar17 + iVar29 * 0xb4) * 2)) + 8 >> 4)
         * 0x38e4;
  } while (puVar32 != auStack_30);
  local_115c = &DAT_009a92ba;
  local_1160 = (undefined2 *)0x0;
  local_1150 = &DAT_009a9418;
  do {
    uVar16 = auStack_1114[(int)local_1160 * 2];
    if ((int)uVar16 < (int)local_1154) {
      uVar17 = uVar16;
    }
    else {
      uVar17 = local_1154;
    }
    iVar10 = -uVar17;
    if ((int)(uVar16 + local_1154) < 0xd5) {
      if (iVar10 <= (int)uVar16) goto LAB_00995a28;
      FUN_00997590(auStack_1114 + 3,0,0x5a0);
      uVar36 = 0;
    }
    else {
      uVar16 = 0xd4 - local_1154;
LAB_00995a28:
      uVar36 = 0;
      puVar33 = local_115c + (0x10 - uVar17);
      do {
        puVar33 = puVar33 + 1;
        uVar36 = uVar36 + *puVar33;
      } while (local_115c + uVar16 + 0x11 != puVar33);
      FUN_00997590(auStack_1114 + 3,0,0x5a0);
      puVar33 = local_115c + (0x11 - uVar17);
      iVar22 = local_1154 - uVar17;
      do {
        if (iVar10 < 0) {
          if (-uVar16 != iVar10 && (int)uVar16 <= -iVar10) {
            iVar29 = *(int *)(param_1 + 0x18 + (int)local_1160 * 4) +
                     iVar22 * 0x2d0 + (iVar22 / 0x23) * -0x6270;
            uVar28 = (uint)*puVar33;
            goto LAB_00995ca4;
          }
        }
        else {
          iVar35 = *(int *)(param_1 + 0x18 + (int)local_1160 * 4);
          uVar28 = (uint)*puVar33;
          iVar29 = iVar35 + (iVar22 % 0x23) * 0x2d0;
          if ((int)uVar17 < iVar10 || iVar10 == 0) {
LAB_00995ca4:
            puVar23 = (ushort *)(iVar29 + -2);
            puVar32 = auStack_1114 + 2;
            do {
              puVar32 = puVar32 + 1;
              puVar23 = puVar23 + 1;
              *puVar32 = uVar28 * *puVar23 + *puVar32;
            } while (auStack_1114 + 0x16a != puVar32);
          }
          else {
            puVar23 = (ushort *)(iVar35 + -2 + ((int)(local_1154 - iVar10) % 0x23) * 0x2d0);
            puVar32 = auStack_1114 + 2;
            puVar34 = (ushort *)(iVar29 + -2);
            do {
              puVar12 = puVar32 + 4;
              uVar5 = puVar23[2];
              puVar32[1] = uVar28 * ((uint)puVar34[1] + (uint)puVar23[1]) + puVar32[1];
              uVar6 = puVar23[3];
              puVar32[2] = uVar28 * ((uint)puVar34[2] + (uint)uVar5) + puVar32[2];
              uVar5 = puVar23[4];
              puVar32[3] = uVar28 * ((uint)puVar34[3] + (uint)uVar6) + puVar32[3];
              *puVar12 = uVar28 * ((uint)puVar34[4] + (uint)uVar5) + *puVar12;
              puVar23 = puVar23 + 4;
              puVar32 = puVar12;
              puVar34 = puVar34 + 4;
            } while (auStack_1114 + 0x16a != puVar12);
          }
        }
        iVar10 = iVar10 + 1;
        puVar33 = puVar33 + 1;
        iVar22 = iVar22 + 1;
      } while (iVar10 != uVar16 + 1);
    }
    uVar16 = *local_1150;
    puVar12 = auStack_1114 + 2;
    puVar32 = puVar27;
    do {
      puVar12 = puVar12 + 1;
      uVar17 = *puVar12;
      if (uVar36 == 0x8000) {
        uVar17 = uVar17 + 0x4000 >> 0xf | (uint)(0xffffbfff < uVar17) << 0x11;
      }
      else {
        uVar17 = FUN_009a69d8((uVar36 >> 1) + uVar17,CARRY4(uVar36 >> 1,uVar17),uVar36,0);
      }
      lVar7 = (ulonglong)uVar17 * (ulonglong)uVar16;
      uVar28 = (uint)lVar7;
      puVar24 = puVar32 + 2;
      uVar21 = *puVar24;
      *puVar24 = uVar21 + uVar28;
      puVar32[3] = uVar17 * ((int)uVar16 >> 0x1f) + (int)((ulonglong)lVar7 >> 0x20) + puVar32[3] +
                   (uint)CARRY4(uVar21,uVar28);
      puVar32 = puVar24;
    } while (puVar12 != auStack_1114 + 0x16a);
    local_115c = local_115c + 0x46;
    if (local_1160 == (undefined2 *)0x1) goto code_r0x009950ec;
    local_1160 = (undefined2 *)0x1;
    local_1150 = local_1150 + 1;
  } while( true );
LAB_00995948:
  iVar30 = iVar29;
LAB_00995594:
  if (iVar30 < iVar22) {
    iVar29 = iVar30;
  }
  else {
    iVar29 = iVar22;
  }
  iVar40 = iVar22;
  if (0x167 < iVar30 + iVar22) {
    iVar40 = 0x164 - iVar30;
  }
  if (0x167 < iVar30 + iVar22) {
    iVar40 = iVar40 + 3;
  }
  if (-iVar40 == iVar29 || -iVar29 < iVar40) {
    puVar34 = puVar37 + (0x10 - iVar29);
    uVar16 = 0;
    puVar23 = puVar34;
    do {
      puVar23 = puVar23 + 1;
      uVar16 = uVar16 + *puVar23;
    } while (puVar23 != puVar33 + iVar40);
    uVar17 = 0;
    puVar23 = (ushort *)(iVar10 + (iVar30 - iVar29) * 2);
    do {
      puVar34 = puVar34 + 1;
      uVar17 = (uint)*puVar23 * (uint)*puVar34 + uVar17;
      puVar23 = puVar23 + 1;
    } while (puVar34 != puVar33 + iVar40);
    if (uVar16 == 0x8000) {
      uVar9 = (undefined2)(uVar17 + 0x4000 >> 0xf);
      goto LAB_00995628;
    }
    iVar29 = (uVar16 >> 1) + uVar17;
    if (CARRY4(uVar16 >> 1,uVar17)) {
      uVar18 = 1;
    }
    else {
      uVar18 = 0;
    }
  }
  else {
    uVar16 = 0;
    iVar29 = 0;
    uVar18 = 0;
  }
  uVar9 = FUN_009a69d8(iVar29,uVar18,uVar16,0);
LAB_00995628:
  iVar29 = iVar30 + 1;
  *(undefined2 *)(iVar35 + iVar30 * 2) = uVar9;
  if (iVar29 == 0x168) goto LAB_00995644;
  goto LAB_00995580;
code_r0x009950ec:
  puVar37 = (undefined2 *)
            (*(int *)(param_2 + (local_1140 + (local_1154 >> 5)) * 4) +
            (local_1154 & 0x1f) * 0x2d0 + -2);
  do {
    puVar32 = puVar27 + 2;
    iVar22 = puVar27[3] + (uint)(0xffffbfff < *puVar32);
    iVar10 = iVar22 >> 0xf;
    uVar16 = *puVar32 + 0x4000 >> 0xf | iVar22 * 0x20000;
    if (iVar10 < 0) {
      uVar16 = 0;
    }
    else if ((int)(uint)(uVar16 < 0x10000) <= iVar10) {
      uVar16 = 0xffff;
    }
    puVar12 = auStack_30;
    puVar37 = puVar37 + 1;
    *puVar37 = (short)uVar16;
    puVar27 = puVar32;
  } while (puVar12 != puVar32);
  local_1154 = local_1154 + 1;
  if (local_1154 == 0xd5) goto code_r0x0099517c;
  goto LAB_009954d8;
code_r0x0099517c:
  if (local_1140 != 0) {
    *(undefined4 *)(param_2 + 0x38) = 1;
    return;
  }
  local_1140 = 7;
  goto LAB_009951ec;
}


// ===== FUN_00995d2c @ 00995d2c

void FUN_00995d2c(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = param_1;
  do {
    iVar2 = iVar1 + 0xc;
    FUN_009917d8(iVar1,param_2);
    param_2 = param_2 + 6;
    iVar1 = iVar2;
  } while (iVar2 != param_1 + 0x870);
  return;
}


// ===== FUN_00995d5c @ 00995d5c

int * FUN_00995d5c(int *param_1,uint param_2)

{
  int *piVar1;
  int iVar2;
  uint *puVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  int *piVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  uint uVar16;
  int iVar17;
  int iVar18;
  int iVar19;
  uint uVar20;
  int *piVar21;
  uint *puVar22;
  uint uVar23;
  uint local_30;
  int local_2c;
  uint uStack_28;
  
  if (((param_2 & 1) != 0) && (param_1[0xf] == param_2 - 1)) {
    return (int *)param_1[10];
  }
  param_1[0xf] = param_2;
  iVar2 = FUN_009a5bf0(param_2 * 0xd500 + 0x6a80,param_1[4]);
  uVar16 = iVar2 - 0x80U & ~((int)(iVar2 - 0x80U) >> 0x1f);
  if (0xd3ff < (int)uVar16) {
    uVar16 = 0xd400;
  }
  uVar20 = uVar16 >> 8;
  if (0xd2 < uVar20) {
    uVar20 = 0xd3;
  }
  if (param_1[0xe] != uVar20) {
    uVar10 = uVar20 >> 5;
    uVar23 = uVar20 + 1 >> 5;
    if ((code *)param_1[0x10] != (code *)0x0) {
      (*(code *)param_1[0x10])(param_1[0x11],uVar10);
      (*(code *)param_1[0x10])(param_1[0x11],uVar23);
    }
    iVar2 = param_1[1];
    iVar14 = 0x100;
    piVar7 = param_1 + 0xb;
    iVar8 = *param_1;
    while( true ) {
      iVar17 = 0;
      uVar11 = 0;
      piVar7 = piVar7 + 1;
      iVar18 = *piVar7;
      do {
        uVar4 = 0x166;
        if (uVar11 < 0x166) {
          uVar4 = uVar11;
        }
        iVar6 = (uint)(uVar11 == 0x167) * 0x100;
        iVar19 = param_1[2];
        iVar13 = (uVar20 & 0x1f) * 0x2d0 + uVar4 * 2;
        iVar5 = (uVar20 + 1 & 0x1f) * 0x2d0 + uVar4 * 2;
        iVar9 = (uint)(uVar11 == 0x167) * -0x100 + 0x100;
        piVar12 = (int *)(iVar2 + uVar10 * 4);
        puVar3 = &local_30;
        do {
          iVar15 = *piVar12;
          piVar21 = piVar12 + (uVar23 - uVar10);
          piVar12 = piVar12 + 7;
          uVar4 = iVar14 * (iVar9 * (uint)*(ushort *)(iVar15 + iVar13) +
                            iVar6 * (uint)*(ushort *)(iVar15 + iVar13 + 2) >> 8) +
                  (iVar9 * (uint)*(ushort *)(*piVar21 + iVar5) +
                   iVar6 * (uint)*(ushort *)(*piVar21 + iVar5 + 2) >> 8) * (0x100 - iVar14) + 0x80
                  >> 8;
          if (0x7ffe < uVar4) {
            uVar4 = 0x7fff;
          }
          puVar22 = puVar3 + 1;
          *puVar3 = iVar19 * uVar4 + 0x80 >> 8;
          puVar3 = puVar22;
        } while (&uStack_28 != puVar22);
        iVar6 = iVar8;
        piVar12 = (int *)(iVar18 + iVar17);
        do {
          piVar21 = (int *)(iVar6 + 0x20);
          piVar1 = (int *)(iVar6 + 0x1c);
          iVar6 = iVar6 + 8;
          *piVar12 = (int)(*piVar1 * local_30 + local_2c * *piVar21 + 0x100) >> 9;
          piVar12 = piVar12 + 1;
        } while (iVar8 + 0x18 != iVar6);
        uVar11 = uVar11 + 1;
        iVar17 = iVar17 + 0xc;
      } while (uVar11 != 0x168);
      if (iVar14 == 0) break;
      iVar14 = 0;
    }
    param_1[0xe] = uVar20;
  }
  iVar8 = param_1[0xc];
  iVar2 = param_1[0xb];
  piVar12 = (int *)(iVar8 + -4);
  piVar7 = (int *)(param_1[0xd] + -4);
  piVar21 = (int *)(iVar2 + -4);
  do {
    piVar12 = piVar12 + 1;
    piVar7 = piVar7 + 1;
    piVar21 = piVar21 + 1;
    *piVar21 = *piVar12 + ((int)((uVar16 + uVar20 * -0x100) * (*piVar7 - *piVar12) + 0x80) >> 8);
  } while ((int *)(iVar8 + 0x10dc) != piVar12);
  uVar16 = param_1[3];
  piVar7 = (int *)param_1[10];
  if (uVar16 != 0) {
    uVar20 = 0;
    iVar8 = param_1[5];
    piVar12 = piVar7;
    do {
      uVar23 = uVar20 + 1;
      iVar14 = uVar20 * 4;
      uVar10 = uVar20;
      iVar17 = iVar8;
      if (uVar16 <= uVar23) {
        iVar17 = 0xc;
        uVar10 = uVar23;
      }
      uVar11 = *(uint *)(iVar8 + uVar20 * 4) >> 9;
      uVar20 = uVar10;
      if (uVar16 <= uVar23) {
LAB_0099608c:
        iVar13 = iVar2 + uVar11 * 0xc;
        iVar19 = *(int *)(iVar2 + uVar11 * 0xc);
        iVar6 = *(int *)(iVar13 + 0xc);
        iVar9 = *(int *)(iVar13 + 4);
        iVar5 = *(int *)(iVar13 + 0x10);
        iVar18 = *(int *)(iVar13 + 8);
        iVar13 = *(int *)(iVar13 + 0x14);
        puVar3 = (uint *)(iVar14 + iVar8 + -4);
        piVar21 = piVar12;
        do {
          puVar3 = puVar3 + 1;
          uVar16 = *puVar3 & 0x1ff;
          *piVar21 = (int)(uVar16 * (iVar6 - iVar19) + iVar19 * 0x100 + 0x80) >> 8;
          piVar21[1] = (int)(uVar16 * (iVar5 - iVar9) + iVar9 * 0x100 + 0x80) >> 8;
          piVar21[2] = (int)((iVar13 - iVar18) * uVar16 + iVar18 * 0x100 + 0x80) >> 8;
          piVar21 = piVar21 + 3;
        } while (puVar3 != (uint *)(iVar8 + -4 + uVar23 * 4));
        uVar16 = param_1[3];
      }
      else {
        puVar3 = (uint *)(iVar8 + iVar14);
        do {
          puVar3 = puVar3 + 1;
          uVar20 = uVar23;
          if (uVar11 != *puVar3 >> 9) break;
          uVar23 = uVar23 + 1;
          uVar20 = uVar23;
        } while (uVar23 < uVar16);
        iVar17 = (uVar20 - uVar10) * 0xc;
        uVar23 = uVar20;
        if (uVar10 < uVar20) goto LAB_0099608c;
      }
      piVar12 = (int *)((int)piVar12 + iVar17);
    } while (uVar23 < uVar16);
  }
  return piVar7;
}


// ===== FUN_00995d74 @ 00995d74

int * FUN_00995d74(int *param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  uint *puVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  int *piVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  uint uVar16;
  int iVar17;
  int iVar18;
  int iVar19;
  uint uVar20;
  int *piVar21;
  uint *puVar22;
  uint uVar23;
  uint local_30;
  int local_2c;
  uint uStack_28;
  
  param_1[0xf] = param_2;
  iVar2 = FUN_009a5bf0(param_2 * 0xd500 + 0x6a80,param_1[4]);
  uVar16 = iVar2 - 0x80U & ~((int)(iVar2 - 0x80U) >> 0x1f);
  if (0xd3ff < (int)uVar16) {
    uVar16 = 0xd400;
  }
  uVar20 = uVar16 >> 8;
  if (0xd2 < uVar20) {
    uVar20 = 0xd3;
  }
  if (param_1[0xe] != uVar20) {
    uVar10 = uVar20 >> 5;
    uVar23 = uVar20 + 1 >> 5;
    if ((code *)param_1[0x10] != (code *)0x0) {
      (*(code *)param_1[0x10])(param_1[0x11],uVar10);
      (*(code *)param_1[0x10])(param_1[0x11],uVar23);
    }
    iVar2 = param_1[1];
    iVar14 = 0x100;
    piVar7 = param_1 + 0xb;
    iVar8 = *param_1;
    while( true ) {
      iVar17 = 0;
      uVar11 = 0;
      piVar7 = piVar7 + 1;
      iVar18 = *piVar7;
      do {
        uVar4 = 0x166;
        if (uVar11 < 0x166) {
          uVar4 = uVar11;
        }
        iVar6 = (uint)(uVar11 == 0x167) * 0x100;
        iVar19 = param_1[2];
        iVar13 = (uVar20 & 0x1f) * 0x2d0 + uVar4 * 2;
        iVar5 = (uVar20 + 1 & 0x1f) * 0x2d0 + uVar4 * 2;
        iVar9 = (uint)(uVar11 == 0x167) * -0x100 + 0x100;
        piVar12 = (int *)(iVar2 + uVar10 * 4);
        puVar3 = &local_30;
        do {
          iVar15 = *piVar12;
          piVar21 = piVar12 + (uVar23 - uVar10);
          piVar12 = piVar12 + 7;
          uVar4 = iVar14 * (iVar9 * (uint)*(ushort *)(iVar15 + iVar13) +
                            iVar6 * (uint)*(ushort *)(iVar15 + iVar13 + 2) >> 8) +
                  (iVar9 * (uint)*(ushort *)(*piVar21 + iVar5) +
                   iVar6 * (uint)*(ushort *)(*piVar21 + iVar5 + 2) >> 8) * (0x100 - iVar14) + 0x80
                  >> 8;
          if (0x7ffe < uVar4) {
            uVar4 = 0x7fff;
          }
          puVar22 = puVar3 + 1;
          *puVar3 = iVar19 * uVar4 + 0x80 >> 8;
          puVar3 = puVar22;
        } while (&uStack_28 != puVar22);
        iVar6 = iVar8;
        piVar12 = (int *)(iVar18 + iVar17);
        do {
          piVar21 = (int *)(iVar6 + 0x20);
          piVar1 = (int *)(iVar6 + 0x1c);
          iVar6 = iVar6 + 8;
          *piVar12 = (int)(*piVar1 * local_30 + local_2c * *piVar21 + 0x100) >> 9;
          piVar12 = piVar12 + 1;
        } while (iVar8 + 0x18 != iVar6);
        uVar11 = uVar11 + 1;
        iVar17 = iVar17 + 0xc;
      } while (uVar11 != 0x168);
      if (iVar14 == 0) break;
      iVar14 = 0;
    }
    param_1[0xe] = uVar20;
  }
  iVar8 = param_1[0xc];
  iVar2 = param_1[0xb];
  piVar12 = (int *)(iVar8 + -4);
  piVar7 = (int *)(param_1[0xd] + -4);
  piVar21 = (int *)(iVar2 + -4);
  do {
    piVar12 = piVar12 + 1;
    piVar7 = piVar7 + 1;
    piVar21 = piVar21 + 1;
    *piVar21 = *piVar12 + ((int)((uVar16 + uVar20 * -0x100) * (*piVar7 - *piVar12) + 0x80) >> 8);
  } while ((int *)(iVar8 + 0x10dc) != piVar12);
  uVar16 = param_1[3];
  piVar7 = (int *)param_1[10];
  if (uVar16 != 0) {
    uVar20 = 0;
    iVar8 = param_1[5];
    piVar12 = piVar7;
    do {
      uVar23 = uVar20 + 1;
      iVar14 = uVar20 * 4;
      uVar10 = uVar20;
      iVar17 = iVar8;
      if (uVar16 <= uVar23) {
        iVar17 = 0xc;
        uVar10 = uVar23;
      }
      uVar11 = *(uint *)(iVar8 + uVar20 * 4) >> 9;
      uVar20 = uVar10;
      if (uVar16 <= uVar23) {
LAB_0099608c:
        iVar13 = iVar2 + uVar11 * 0xc;
        iVar19 = *(int *)(iVar2 + uVar11 * 0xc);
        iVar6 = *(int *)(iVar13 + 0xc);
        iVar9 = *(int *)(iVar13 + 4);
        iVar5 = *(int *)(iVar13 + 0x10);
        iVar18 = *(int *)(iVar13 + 8);
        iVar13 = *(int *)(iVar13 + 0x14);
        puVar3 = (uint *)(iVar14 + iVar8 + -4);
        piVar21 = piVar12;
        do {
          puVar3 = puVar3 + 1;
          uVar16 = *puVar3 & 0x1ff;
          *piVar21 = (int)(uVar16 * (iVar6 - iVar19) + iVar19 * 0x100 + 0x80) >> 8;
          piVar21[1] = (int)(uVar16 * (iVar5 - iVar9) + iVar9 * 0x100 + 0x80) >> 8;
          piVar21[2] = (int)((iVar13 - iVar18) * uVar16 + iVar18 * 0x100 + 0x80) >> 8;
          piVar21 = piVar21 + 3;
        } while (puVar3 != (uint *)(iVar8 + -4 + uVar23 * 4));
        uVar16 = param_1[3];
      }
      else {
        puVar3 = (uint *)(iVar8 + iVar14);
        do {
          puVar3 = puVar3 + 1;
          uVar20 = uVar23;
          if (uVar11 != *puVar3 >> 9) break;
          uVar23 = uVar23 + 1;
          uVar20 = uVar23;
        } while (uVar23 < uVar16);
        iVar17 = (uVar20 - uVar10) * 0xc;
        uVar23 = uVar20;
        if (uVar10 < uVar20) goto LAB_0099608c;
      }
      piVar12 = (int *)((int)piVar12 + iVar17);
    } while (uVar23 < uVar16);
  }
  return piVar7;
}


// ===== FUN_00996174 @ 00996174

void FUN_00996174(int *param_1,int param_2,int param_3,int param_4,int param_5,int param_6)

{
  int *piVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  short *psVar9;
  uint uVar10;
  uint *puVar11;
  uint uVar12;
  uint uVar13;
  int iVar14;
  bool bVar15;
  undefined8 uVar16;
  
  if (((uint)param_1 & 3) == 0) {
    piVar1 = param_1 + 4;
    do {
      piVar1[-4] = 0;
      piVar1[-3] = 0;
      piVar1[-2] = 0;
      piVar1[-1] = 0;
      piVar1 = piVar1 + 4;
    } while (piVar1 != param_1 + 0x2088);
    uVar4 = 8;
    piVar1 = param_1 + 0x2084;
  }
  else {
    uVar4 = 0x8218;
    piVar1 = param_1;
  }
  FUN_00997590(piVar1,0,uVar4);
  uVar5 = 0;
  iVar8 = *(int *)(param_3 + 0xa0);
  puVar11 = (uint *)(param_6 + -4);
  *param_1 = param_3;
  param_1[1] = param_4;
  param_1[2] = param_5;
  param_1[0x16e] = param_6;
  do {
    uVar13 = *(uint *)(iVar8 + 0x50);
    if (uVar13 < uVar5) {
      iVar14 = uVar5 - uVar13;
    }
    else {
      iVar14 = 0;
    }
    uVar5 = uVar5 + 1;
    puVar11 = puVar11 + 1;
    *puVar11 = *(int *)(param_3 + 0x84) * iVar14 + 0x800U >> 0xc;
  } while (uVar5 != 0x1000);
  iVar8 = 0x100;
  uVar5 = 0;
  FUN_009927bc(param_1 + 0x204e,param_3,param_4);
  param_1[3] = *(int *)(param_2 + 0x28);
  piVar1 = param_1 + 0x1e4e;
  param_1[4] = *(int *)(param_2 + 0x2c);
  do {
    uVar16 = FUN_009a69d8(uVar5,iVar8,uVar5 + 1,iVar8 - ((uVar5 != 0xffffffff) + 0xff));
    bVar15 = 0xfffffffe < uVar5;
    uVar5 = uVar5 + 1;
    iVar8 = iVar8 + (uint)bVar15;
    piVar1 = piVar1 + 2;
    *(undefined8 *)piVar1 = uVar16;
  } while (iVar8 != 0x100 || uVar5 != 0xff);
  uVar13 = 0;
  uVar5 = 0;
  iVar8 = 0;
  uVar12 = *(uint *)(param_3 + 0x94);
  psVar9 = (short *)((int)param_1 + 0x16);
  param_1[5] = uVar12;
  uVar4 = *(undefined4 *)(param_2 + 0x28);
  do {
    if (uVar13 < uVar12) {
      iVar8 = (iVar8 + uVar13) * 0xf0;
      do {
        uVar2 = FUN_009a5bf0(iVar8,uVar12);
        iVar8 = iVar8 + 0x2d0;
        if (uVar5 < uVar2) {
          iVar8 = uVar13 << 1;
          goto LAB_009962ec;
        }
        uVar13 = uVar13 + 1;
      } while (uVar12 != uVar13);
      iVar8 = uVar12 << 1;
    }
LAB_009962ec:
    uVar5 = uVar5 + 1;
    psVar9 = psVar9 + 1;
    *psVar9 = (short)uVar4 + (short)iVar8;
  } while (uVar5 != 0x2d0);
  uVar5 = *(uint *)(param_2 + 0xc4);
  if (1 < uVar5) {
    uVar13 = 1;
    puVar11 = (uint *)(param_2 + 0xd0);
    do {
      uVar2 = param_1[0xcb6];
      if (1 < uVar2) break;
      puVar11 = puVar11 + 1;
      uVar7 = *puVar11;
      uVar10 = *(uint *)(param_2 + 0x28);
      uVar3 = (uVar7 - 1) - uVar10;
      if ((uVar10 <= uVar7 - 1) && (uVar7 < uVar10 + uVar12 * 2)) {
        iVar8 = FUN_009a5bf0(((uVar3 & 0xfffffffe) + (uVar3 >> 1)) * 0xf0,uVar12);
        iVar14 = FUN_009a5bf0(((uVar7 - uVar10 & 0xfffffffe) + (uVar7 - uVar10 >> 1)) * 0xf0,uVar12)
        ;
        if (iVar14 == iVar8) {
          param_1[0xcb6] = uVar2 + 1;
          uVar5 = *(uint *)(param_2 + 0xc4);
          *(short *)((int)param_1 + (uVar2 + 0x196c) * 2 + 4) = (short)iVar14;
        }
      }
      uVar13 = uVar13 + 1;
    } while (uVar13 < uVar5);
  }
  param_1[0x16f] = -1;
  if (param_5 != 0) {
    iVar8 = param_5 + 0x438;
    do {
      iVar14 = iVar8 + -0x438;
      do {
        iVar6 = iVar14 + 6;
        FUN_009917d8(0,iVar14);
        iVar14 = iVar6;
      } while (iVar8 != iVar6);
      iVar8 = iVar8 + 0x438;
    } while (iVar8 != param_5 + 0x3f8b8);
  }
  return;
}


// ===== FUN_00996450 @ 00996450

void FUN_00996450(int *param_1,uint param_2,uint param_3,int param_4,int param_5)

{
  ushort uVar1;
  undefined2 uVar2;
  int iVar3;
  ushort *puVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  int local_80;
  ushort *local_5c;
  int local_58;
  int local_54;
  int local_50;
  int local_4c;
  uint local_48;
  uint local_44;
  int local_40;
  uint local_3c;
  uint local_38;
  uint local_34;
  int local_30;
  undefined *local_2c;
  
  uVar10 = param_1[4];
  if (param_2 < uVar10) {
    return;
  }
  iVar7 = *param_1;
  if (uVar10 + *(int *)(iVar7 + 0x98) * 2 <= param_2) {
    return;
  }
  uVar6 = param_1[3];
  uVar9 = uVar6 + *(int *)(iVar7 + 0x94) * 2;
  if (uVar6 < param_3) {
    uVar14 = param_3;
  }
  else {
    uVar14 = uVar6;
  }
  if (param_3 + param_5 <= uVar9) {
    uVar9 = param_3 + param_5;
  }
  if (uVar9 <= uVar14) {
    return;
  }
  iVar3 = FUN_009a5bf0((param_2 - uVar10 >> 1) * 0xd5,*(int *)(iVar7 + 0x98));
  uVar10 = uVar14 - uVar6;
  if ((param_1[0x16f] == iVar3) && (param_1[0x170] == param_3)) {
    uVar1 = *(ushort *)(param_1 + 0x173);
  }
  else {
    FUN_00991d5c(param_1);
    param_1[0x16f] = iVar3;
    iVar3 = param_1[5];
    param_1[0x170] = param_3;
    param_1[0x171] = uVar14;
    param_1[0x172] = uVar9;
    uVar1 = FUN_009a5bf0(((uVar10 & 0xfffffffe) + (uVar10 >> 1)) * 0xf0,iVar3);
    uVar11 = (uVar9 - uVar6) - 1;
    *(ushort *)(param_1 + 0x173) = uVar1;
    uVar2 = FUN_009a5bf0(((uVar11 & 0xfffffffe) + (uVar11 >> 1)) * 0xf0,iVar3);
    *(undefined2 *)((int)param_1 + 0x5ce) = uVar2;
    param_1[0x174] = 0;
    param_1[0x175] = 0;
  }
  uVar8 = (uint)uVar1;
  param_2 = param_2 & 1;
  local_58 = param_4 + ((uVar9 - param_3) - (uVar9 - uVar6 & 1)) * 2;
  uVar11 = -param_2;
  param_1[param_2 + 0x174] = param_1[param_2 + 0x174] + 1;
  iVar3 = iVar7 + (param_2 + 0x4e) * 2;
  uVar13 = (uint)*(byte *)(iVar3 + (uVar6 & 1));
  uVar6 = (uint)*(byte *)(iVar3 + (uVar6 + 1 & 1));
  local_50 = (int)param_1 + (uVar11 & 0x1680) + 0x5d8 + uVar8 * 8;
  uVar12 = *(uint *)(iVar7 + (uVar13 + 0x22) * 4);
  uVar13 = param_1[uVar13 + 0x2075];
  local_44 = *(uint *)(iVar7 + (uVar6 + 0x22) * 4);
  local_34 = param_1[uVar6 + 0x2075];
  local_80 = (int)param_1 + uVar8 * 2 + 0x18;
  iVar7 = (uVar14 - param_3) * 2;
  iVar3 = param_1[0x16e];
  puVar4 = (ushort *)(param_4 + (uVar14 - param_3) * 2);
  local_5c = puVar4;
  if (param_1[0x2073] == 0) {
    uVar6 = 0;
    if ((uVar10 & 1) == 0) goto LAB_009966ac;
    uVar14 = *(uint *)(iVar3 + (uint)*(ushort *)(param_4 + iVar7) * 4);
    uVar10 = local_44;
    if (uVar14 < local_44) {
      uVar10 = uVar14;
    }
    *(uint *)(local_50 + 4) = *(int *)(local_50 + 4) + uVar10;
    uVar10 = uVar6;
LAB_009968dc:
    local_5c = puVar4 + 1;
    if (param_3 + ((int)local_5c - param_4 >> 1) !=
        (uint)*(ushort *)((int)param_1 + uVar8 * 2 + 0x18)) goto LAB_009966ac;
    if (uVar10 == 0) {
      uVar6 = 0;
      local_50 = local_50 + 8;
      local_80 = local_80 + 2;
      goto LAB_009966ac;
    }
  }
  else {
    uVar6 = param_1[0x207f] + ((uVar11 & 0x2d0) + uVar8) * 8;
    if ((uVar10 & 1) == 0) goto LAB_009966ac;
    uVar14 = *(uint *)(iVar3 + (uint)*(ushort *)(param_4 + iVar7) * 4);
    if (local_44 < uVar14) {
      uVar14 = local_44;
    }
    uVar10 = (uint)(uVar6 != 0);
    if (uVar14 < local_34) {
      uVar5 = 0;
    }
    else {
      uVar5 = uVar10;
    }
    *(uint *)(local_50 + 4) = *(int *)(local_50 + 4) + uVar14;
    if (uVar5 == 0) goto LAB_009968dc;
    uVar1 = *(ushort *)((int)param_1 + uVar8 * 2 + 0x18);
    uVar10 = param_1[0x2078] * (uVar14 - param_1[0x2076]) >> 0x10;
    if (0xff < uVar10) {
      uVar10 = 0x100;
    }
    *(uint *)(uVar6 + 4) =
         *(int *)(uVar6 + 4) + (uVar14 * *(ushort *)(&DAT_009a8d68 + uVar10 * 2) >> 8);
    local_5c = puVar4 + 1;
    if (param_3 + ((int)(puVar4 + 1) - param_4 >> 1) != (uint)uVar1) goto LAB_009966ac;
  }
  local_80 = local_80 + 2;
  uVar6 = uVar6 + 8;
  local_5c = puVar4 + 1;
  local_50 = local_50 + 8;
LAB_009966ac:
  local_30 = param_1[0x2078];
  local_40 = param_4 + param_3 * -2;
  local_54 = local_80;
  local_2c = &DAT_009a8d68;
  local_4c = iVar3;
  local_48 = uVar12;
  local_3c = uVar6;
  local_38 = uVar13;
  if (uVar6 == 0) {
    FUN_0098cf04(&local_5c);
  }
  else {
    FUN_00982280();
  }
  if (local_5c < (ushort *)(param_4 + (uVar9 - param_3) * 2)) {
    uVar10 = *(uint *)(iVar3 + (uint)*local_5c * 4);
    if (uVar12 < uVar10) {
      uVar10 = uVar12;
    }
    uVar9 = (uint)*(ushort *)((int)param_1 + 0x5ce);
    iVar7 = (uVar11 & 0x2d0) + uVar9;
    param_1[iVar7 * 2 + 0x176] = param_1[iVar7 * 2 + 0x176] + uVar10;
    if (uVar13 <= uVar10 && uVar6 != 0) {
      uVar6 = param_1[0x2078] * (uVar10 - param_1[0x2076]) >> 0x10;
      if (0xff < uVar6) {
        uVar6 = 0x100;
      }
      iVar7 = param_1[0x207f] + (uVar11 & 0x1680);
      *(uint *)(iVar7 + uVar9 * 8) =
           *(int *)(iVar7 + uVar9 * 8) + (uVar10 * *(ushort *)(&DAT_009a8d68 + uVar6 * 2) >> 8);
    }
  }
  if (((code *)param_1[0x2084] != (code *)0x0) &&
     (iVar7 = param_1[0x1e4d], param_1[0x1e4d] = iVar7 + 1U, (iVar7 + 1U & 0x3f) == 0)) {
    (*(code *)param_1[0x2084])(param_1[0x2085]);
  }
  return;
}


// ===== FUN_0099645c @ 0099645c

void FUN_0099645c(int *param_1,uint param_2,uint param_3,int param_4,int param_5)

{
  ushort uVar1;
  undefined2 uVar2;
  int iVar3;
  ushort *puVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  int in_r12;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  int local_80;
  ushort *local_5c;
  int local_58;
  int local_54;
  int local_50;
  int local_4c;
  uint local_48;
  uint local_44;
  int local_40;
  uint local_3c;
  uint local_38;
  uint local_34;
  int local_30;
  undefined *local_2c;
  
  iVar8 = *param_1;
  if ((uint)(in_r12 + *(int *)(iVar8 + 0x98) * 2) <= param_2) {
    return;
  }
  uVar6 = param_1[3];
  uVar10 = uVar6 + *(int *)(iVar8 + 0x94) * 2;
  if (uVar6 < param_3) {
    uVar14 = param_3;
  }
  else {
    uVar14 = uVar6;
  }
  if (param_3 + param_5 <= uVar10) {
    uVar10 = param_3 + param_5;
  }
  if (uVar10 <= uVar14) {
    return;
  }
  iVar3 = FUN_009a5bf0((param_2 - in_r12 >> 1) * 0xd5,*(int *)(iVar8 + 0x98));
  uVar7 = uVar14 - uVar6;
  if ((param_1[0x16f] == iVar3) && (param_1[0x170] == param_3)) {
    uVar1 = *(ushort *)(param_1 + 0x173);
  }
  else {
    FUN_00991d5c(param_1);
    param_1[0x16f] = iVar3;
    iVar3 = param_1[5];
    param_1[0x170] = param_3;
    param_1[0x171] = uVar14;
    param_1[0x172] = uVar10;
    uVar1 = FUN_009a5bf0(((uVar7 & 0xfffffffe) + (uVar7 >> 1)) * 0xf0,iVar3);
    uVar11 = (uVar10 - uVar6) - 1;
    *(ushort *)(param_1 + 0x173) = uVar1;
    uVar2 = FUN_009a5bf0(((uVar11 & 0xfffffffe) + (uVar11 >> 1)) * 0xf0,iVar3);
    *(undefined2 *)((int)param_1 + 0x5ce) = uVar2;
    param_1[0x174] = 0;
    param_1[0x175] = 0;
  }
  uVar9 = (uint)uVar1;
  param_2 = param_2 & 1;
  local_58 = param_4 + ((uVar10 - param_3) - (uVar10 - uVar6 & 1)) * 2;
  uVar11 = -param_2;
  param_1[param_2 + 0x174] = param_1[param_2 + 0x174] + 1;
  iVar3 = iVar8 + (param_2 + 0x4e) * 2;
  uVar13 = (uint)*(byte *)(iVar3 + (uVar6 & 1));
  uVar6 = (uint)*(byte *)(iVar3 + (uVar6 + 1 & 1));
  local_50 = (int)param_1 + (uVar11 & 0x1680) + 0x5d8 + uVar9 * 8;
  uVar12 = *(uint *)(iVar8 + (uVar13 + 0x22) * 4);
  uVar13 = param_1[uVar13 + 0x2075];
  local_44 = *(uint *)(iVar8 + (uVar6 + 0x22) * 4);
  local_34 = param_1[uVar6 + 0x2075];
  local_80 = (int)param_1 + uVar9 * 2 + 0x18;
  iVar8 = (uVar14 - param_3) * 2;
  iVar3 = param_1[0x16e];
  puVar4 = (ushort *)(param_4 + (uVar14 - param_3) * 2);
  local_5c = puVar4;
  if (param_1[0x2073] == 0) {
    uVar6 = 0;
    if ((uVar7 & 1) == 0) goto LAB_009966ac;
    uVar7 = *(uint *)(iVar3 + (uint)*(ushort *)(param_4 + iVar8) * 4);
    uVar14 = local_44;
    if (uVar7 < local_44) {
      uVar14 = uVar7;
    }
    *(uint *)(local_50 + 4) = *(int *)(local_50 + 4) + uVar14;
    uVar14 = uVar6;
LAB_009968dc:
    local_5c = puVar4 + 1;
    if (param_3 + ((int)local_5c - param_4 >> 1) !=
        (uint)*(ushort *)((int)param_1 + uVar9 * 2 + 0x18)) goto LAB_009966ac;
    if (uVar14 == 0) {
      uVar6 = 0;
      local_50 = local_50 + 8;
      local_80 = local_80 + 2;
      goto LAB_009966ac;
    }
  }
  else {
    uVar6 = param_1[0x207f] + ((uVar11 & 0x2d0) + uVar9) * 8;
    if ((uVar7 & 1) == 0) goto LAB_009966ac;
    uVar7 = *(uint *)(iVar3 + (uint)*(ushort *)(param_4 + iVar8) * 4);
    if (local_44 < uVar7) {
      uVar7 = local_44;
    }
    uVar14 = (uint)(uVar6 != 0);
    if (uVar7 < local_34) {
      uVar5 = 0;
    }
    else {
      uVar5 = uVar14;
    }
    *(uint *)(local_50 + 4) = *(int *)(local_50 + 4) + uVar7;
    if (uVar5 == 0) goto LAB_009968dc;
    uVar1 = *(ushort *)((int)param_1 + uVar9 * 2 + 0x18);
    uVar14 = param_1[0x2078] * (uVar7 - param_1[0x2076]) >> 0x10;
    if (0xff < uVar14) {
      uVar14 = 0x100;
    }
    *(uint *)(uVar6 + 4) =
         *(int *)(uVar6 + 4) + (uVar7 * *(ushort *)(&DAT_009a8d68 + uVar14 * 2) >> 8);
    local_5c = puVar4 + 1;
    if (param_3 + ((int)(puVar4 + 1) - param_4 >> 1) != (uint)uVar1) goto LAB_009966ac;
  }
  local_80 = local_80 + 2;
  uVar6 = uVar6 + 8;
  local_5c = puVar4 + 1;
  local_50 = local_50 + 8;
LAB_009966ac:
  local_30 = param_1[0x2078];
  local_40 = param_4 + param_3 * -2;
  local_54 = local_80;
  local_2c = &DAT_009a8d68;
  local_4c = iVar3;
  local_48 = uVar12;
  local_3c = uVar6;
  local_38 = uVar13;
  if (uVar6 == 0) {
    FUN_0098cf04(&local_5c);
  }
  else {
    FUN_00982280();
  }
  if (local_5c < (ushort *)(param_4 + (uVar10 - param_3) * 2)) {
    uVar10 = *(uint *)(iVar3 + (uint)*local_5c * 4);
    if (uVar12 < uVar10) {
      uVar10 = uVar12;
    }
    uVar14 = (uint)*(ushort *)((int)param_1 + 0x5ce);
    iVar8 = (uVar11 & 0x2d0) + uVar14;
    param_1[iVar8 * 2 + 0x176] = param_1[iVar8 * 2 + 0x176] + uVar10;
    if (uVar13 <= uVar10 && uVar6 != 0) {
      uVar6 = param_1[0x2078] * (uVar10 - param_1[0x2076]) >> 0x10;
      if (0xff < uVar6) {
        uVar6 = 0x100;
      }
      iVar8 = param_1[0x207f] + (uVar11 & 0x1680);
      *(uint *)(iVar8 + uVar14 * 8) =
           *(int *)(iVar8 + uVar14 * 8) + (uVar10 * *(ushort *)(&DAT_009a8d68 + uVar6 * 2) >> 8);
    }
  }
  if (((code *)param_1[0x2084] != (code *)0x0) &&
     (iVar8 = param_1[0x1e4d], param_1[0x1e4d] = iVar8 + 1U, (iVar8 + 1U & 0x3f) == 0)) {
    (*(code *)param_1[0x2084])(param_1[0x2085]);
  }
  return;
}


// ===== thunk_FUN_00991d5c @ 0099693c

void thunk_FUN_00991d5c(int *param_1)

{
  short sVar1;
  short sVar2;
  char cVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  short *psVar11;
  uint uVar12;
  uint uVar13;
  undefined1 uVar14;
  uint uVar15;
  ushort *puVar16;
  int iVar17;
  int iVar18;
  int *piVar19;
  int *piVar20;
  int iVar21;
  uint uVar22;
  int iVar23;
  int iVar24;
  bool bVar25;
  int iStack_8c;
  undefined1 *puStack_74;
  int iStack_70;
  int *piStack_68;
  int iStack_5c;
  short *psStack_58;
  int *piStack_54;
  short asStack_48 [4];
  int aiStack_40 [7];
  
  iVar8 = param_1[0x16f];
  if (iVar8 < 0) {
    return;
  }
  uVar12 = (uint)*(ushort *)(param_1 + 0x173);
  if (uVar12 <= *(ushort *)((int)param_1 + 0x5ce)) {
    uVar6 = param_1[3];
    puStack_74 = (undefined1 *)((int)param_1 + uVar12 + 0x5aed);
    uVar15 = uVar6 + 1 & 1;
    iVar21 = 1 - uVar6;
    iVar17 = *param_1;
    puVar16 = (ushort *)((int)param_1 + uVar12 * 2 + 0x16);
    uVar9 = uVar6 & 1;
    if (uVar12 != 0) goto LAB_00991fec;
    do {
      iStack_5c = iVar17 + uVar15;
      puVar16 = puVar16 + 1;
      if (uVar6 < (uint)param_1[0x171]) {
        uVar6 = param_1[0x171];
      }
      uVar22 = (uint)*puVar16;
      if ((uint)param_1[0x172] <= (uint)*puVar16) {
        uVar22 = param_1[0x172];
      }
      iVar10 = 0;
      uVar13 = iVar21 + uVar22;
      iVar18 = param_1[0x2073];
      piVar20 = param_1 + 0x173;
      aiStack_40[0] = 0;
      piVar19 = param_1 + uVar12 * 2;
      aiStack_40[1] = 0;
      aiStack_40[2] = 0;
      aiStack_40[3] = 0;
      aiStack_40[4] = 0;
      aiStack_40[5] = 0;
      asStack_48[0] = 0;
      asStack_48[1] = 0;
      asStack_48[2] = 0;
      sVar2 = (short)(iVar21 + uVar6 >> 1);
      while( true ) {
        piStack_54 = aiStack_40;
        psStack_58 = asStack_48;
        piStack_68 = aiStack_40 + 3;
        iStack_70 = uVar9 + 0x9c;
        uVar7 = (uint)*(byte *)((iStack_5c - uVar15) + iStack_70);
        piVar20 = piVar20 + 1;
        iVar23 = *piVar20;
        uVar4 = (uint)*(byte *)(iStack_5c + 0x9c);
        asStack_48[uVar7] = (short)iVar23 * ((short)(uVar13 >> 1) - sVar2) + asStack_48[uVar7];
        iStack_5c = iStack_5c + 2;
        aiStack_40[uVar7] = aiStack_40[uVar7] + piVar19[0x176];
        sVar1 = asStack_48[uVar4];
        piVar19[0x176] = 0;
        iVar5 = aiStack_40[uVar4];
        asStack_48[uVar4] =
             (short)iVar23 * ((((short)uVar22 - (short)(uVar13 >> 1)) - (short)uVar6) + sVar2) +
             sVar1;
        iVar23 = piVar19[0x177];
        piVar19[0x177] = 0;
        piVar19 = piVar19 + 0x5a0;
        aiStack_40[uVar4] = iVar5 + iVar23;
        if (iVar18 != 0) {
          iVar5 = param_1[0x207f] + iVar10;
          aiStack_40[uVar7 + 3] = aiStack_40[uVar7 + 3] + *(int *)(iVar5 + uVar12 * 8);
          iVar23 = iVar5 + uVar12 * 8;
          iVar24 = *(int *)(iVar23 + 4);
          *(undefined4 *)(iVar23 + 4) = 0;
          *(undefined4 *)(iVar5 + uVar12 * 8) = 0;
          aiStack_40[uVar4 + 3] = aiStack_40[uVar4 + 3] + iVar24;
        }
        if (iVar10 == 0x1680) break;
        iVar10 = 0x1680;
      }
      iVar10 = 0;
      puStack_74 = puStack_74 + 1;
      *puStack_74 = 0;
      iVar5 = param_1[0xcb6];
      if (iVar5 == 0) {
LAB_00991fb4:
        piVar20 = piStack_68;
LAB_00991fc8:
        FUN_009919e0(param_1,iVar8,uVar12,piStack_54,psStack_58,piVar20);
      }
      else {
        if (*(ushort *)(param_1 + 0xcb7) != uVar12) {
          if (iVar5 == 1) goto LAB_00991fb4;
          if (*(ushort *)((int)param_1 + 0x32de) == uVar12) {
            iVar10 = 1;
          }
          else {
            if (iVar5 == 2) goto LAB_00991fb4;
            iVar10 = 2;
          }
        }
        iVar5 = 0;
        psVar11 = (short *)((int)param_1 + iVar10 * 6 + iVar8 * 0xc + 0x46d6);
        piVar20 = piStack_68;
        do {
          *(int *)((-0x5acc - (int)param_1) + (int)psVar11 * 2) =
               *(int *)((-0x5acc - (int)param_1) + (int)psVar11 * 2) + *piStack_54;
          psVar11 = psVar11 + 1;
          *psVar11 = *psStack_58 + *psVar11;
          if (iVar18 != 0) {
            iVar23 = iVar10 * 3 + iVar5;
            iVar24 = param_1[0x2080] + iVar8 * 0x18;
            *(int *)(iVar24 + iVar23 * 4) = *(int *)(iVar24 + iVar23 * 4) + *piVar20;
          }
          iVar5 = iVar5 + 1;
          piVar20 = piVar20 + 1;
          psStack_58 = psStack_58 + 1;
          piStack_54 = piStack_54 + 1;
        } while (iVar5 != 3);
        iVar5 = iVar10 + iVar8 * 2;
        piVar20 = (int *)((int)param_1 + iVar5 + 0x5000);
        cVar3 = *(char *)((int)param_1 + iVar5 + 0x50d4) + '\x01';
        *(char *)((int)param_1 + iVar5 + 0x50d4) = cVar3;
        if (cVar3 == '\x02') {
          bVar25 = iVar18 == 0;
          if (!bVar25) {
            piVar20 = (int *)param_1[0x2080];
          }
          if (bVar25) {
            piVar20 = piStack_68;
          }
          psStack_58 = (short *)((int)param_1 + iVar8 * 0xc + 0x46d8 + iVar10 * 6);
          if (!bVar25) {
            piVar20 = piVar20 + iVar10 * 3 + iVar8 * 6;
          }
          piStack_54 = param_1 + iVar10 * 3 + iVar8 * 6 + 0xcb8;
          goto LAB_00991fc8;
        }
      }
      uVar12 = uVar12 + 1;
      if (*(ushort *)((int)param_1 + 0x5ce) < uVar12) goto LAB_00992134;
LAB_00991fec:
      uVar6 = (uint)*puVar16;
    } while( true );
  }
LAB_0099213c:
  iVar17 = param_1[2];
  if (iVar17 != 0) {
    uVar12 = uVar12 >> 2;
    iStack_8c = (int)param_1 + uVar12 * 0xc + 0x527e;
    iVar21 = iVar8 * 2;
    iVar10 = iVar8 * 0x438 + 0x36d8 + uVar12 * 6;
    do {
      if (*(ushort *)((int)param_1 + 0x5ce) >> 2 < uVar12) break;
      uVar15 = 0;
      uVar9 = 0;
      uVar6 = uVar12 << 2;
      do {
        if ((uVar6 <= *(ushort *)((int)param_1 + 0x5ce) && *(ushort *)(param_1 + 0x173) <= uVar6) &&
           (*(char *)((int)param_1 + uVar6 + 0x5aee) != '\0')) {
          uVar9 = uVar9 | 1 << (uVar15 & 0xff);
        }
        uVar15 = uVar15 + 1;
        uVar6 = uVar6 + 1;
      } while (uVar15 != 4);
      if (uVar9 == 0xf) {
        FUN_009917d8(iStack_8c,iVar17 + iVar10);
LAB_00992378:
        iVar17 = param_1[2];
      }
      else {
        uVar6 = (uint)*(byte *)((int)param_1 + iVar8 + 0x785e);
        if (uVar6 == 0) {
          uVar14 = 1;
LAB_00992284:
          *(undefined1 *)((int)param_1 + iVar8 + 0x785e) = uVar14;
          *(short *)((int)param_1 + (iVar21 + uVar6) * 0x10 + 0x5dbe) = (short)uVar12;
          *(undefined1 *)(param_1 + (iVar21 + uVar6) * 4 + 6000) = 0;
LAB_009922a8:
          iVar18 = (int)param_1 + (uVar6 + iVar21) * 0x10 + 0x5dc1;
          uVar15 = 0;
          do {
            if ((uVar9 & 1 << (uVar15 & 0xff)) != 0) {
              iVar18 = FUN_009975a8(iVar18,uVar12 * 0xc + iVar8 * -0x20 + uVar6 * -0x10 + -0xb43 +
                                           iVar18,3);
            }
            uVar15 = uVar15 + 1;
            iVar18 = iVar18 + 3;
          } while (uVar15 != 4);
          iVar18 = iVar21 + uVar6;
          uVar9 = (uint)*(byte *)(param_1 + iVar18 * 4 + 6000) | uVar9 & 0xff;
          *(char *)(param_1 + iVar18 * 4 + 6000) = (char)uVar9;
          if (uVar9 == 0xf) {
            FUN_009917d8((int)param_1 + (uVar6 + iVar21) * 0x10 + 0x5dc1,iVar17 + iVar10);
            *(undefined1 *)(param_1 + iVar18 * 4 + 6000) = 0xff;
            goto LAB_00992378;
          }
          iVar17 = param_1[2];
        }
        else {
          if (*(ushort *)((int)param_1 + iVar8 * 0x20 + 0x5dbe) == uVar12) {
            uVar6 = 0;
            goto LAB_009922a8;
          }
          if (uVar6 == 1) {
            uVar14 = 2;
            goto LAB_00992284;
          }
          if (*(ushort *)((int)param_1 + iVar8 * 0x20 + 0x5dce) == uVar12) {
            uVar6 = 1;
            goto LAB_009922a8;
          }
          if (uVar6 != 2) {
            uVar6 = 2;
            goto LAB_009922a8;
          }
        }
      }
      iStack_8c = iStack_8c + 0xc;
      uVar12 = uVar12 + 1;
      iVar10 = iVar10 + 6;
    } while (iVar17 != 0);
  }
  param_1[0x16f] = -1;
  return;
LAB_00992134:
  uVar12 = (uint)*(ushort *)(param_1 + 0x173);
  goto LAB_0099213c;
}


// ===== FUN_00996940 @ 00996940

uint FUN_00996940(undefined4 param_1,uint param_2,char *param_3,int param_4,char *param_5)

{
  char cVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int *unaff_r6;
  uint *puVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  undefined4 local_168;
  uint local_164;
  uint local_160;
  int local_15c;
  int local_158 [2];
  char *local_150;
  uint local_14c [31];
  char *local_d0;
  int local_cc [42];
  
  if (0x3f < param_2) {
    local_168 = param_1;
    local_164 = param_2;
    FUN_009975a8(param_1,&DAT_009a9424,0xe);
    if ((param_5 == (char *)0x0) || (*param_5 == '\0')) {
      iVar3 = 2;
      iVar7 = 1;
      iVar9 = 0;
    }
    else {
      local_158[1] = FUN_009975c4(param_5 + 1);
      local_150 = param_5;
      iVar7 = 2;
      iVar3 = 3;
      iVar9 = 1;
      local_158[1] = local_158[1] + 2;
      local_158[0] = 0x2010e;
      local_14c[0] = 0;
    }
    cVar1 = *param_3;
    if (cVar1 == '\0') {
      unaff_r6 = local_158;
    }
    local_158[iVar9 * 4] = 0x2010f;
    local_158[iVar9 * 4 + 1] = 6;
    local_158[iVar9 * 4 + 2] = (int)"Canon";
    local_14c[iVar9 * 4] = 0;
    iVar2 = iVar3;
    if (cVar1 != '\0') {
      iVar2 = FUN_009975c4(param_3 + 1);
      unaff_r6 = local_158;
      unaff_r6[iVar7 * 4] = 0x20110;
      local_158[iVar7 * 4 + 1] = iVar2 + 2;
      local_14c[iVar7 * 4] = 0;
      local_158[iVar7 * 4 + 2] = (int)param_3;
      iVar2 = iVar9 + 3;
      iVar7 = iVar3;
    }
    uVar11 = (uint)*(ushort *)(param_3 + 0x42);
    if (7 < uVar11 - 1) {
      uVar11 = 1;
    }
    unaff_r6[iVar7 * 4] = 0x30112;
    cVar1 = param_3[0x48];
    local_158[iVar7 * 4 + 1] = 1;
    local_14c[iVar7 * 4] = uVar11;
    local_158[iVar7 * 4 + 2] = 0;
    iVar9 = iVar7 + 2;
    local_158[iVar2 * 4] = 0x20131;
    local_158[iVar2 * 4 + 1] = 7;
    local_158[iVar2 * 4 + 2] = (int)"Ritual";
    local_14c[iVar2 * 4] = 0;
    iVar3 = iVar9;
    if (cVar1 != '\0') {
      iVar2 = FUN_009975c4(param_3 + 0x49);
      unaff_r6[iVar9 * 4] = 0x20132;
      local_14c[iVar9 * 4] = 0;
      iVar3 = iVar7 + 3;
      local_158[iVar9 * 4 + 1] = iVar2 + 2;
      local_158[iVar9 * 4 + 2] = (int)(param_3 + 0x48);
    }
    uVar11 = 1;
    iVar7 = iVar3 + 1;
    local_160 = 0xe;
    local_158[iVar3 * 4] = 0x30213;
    local_158[iVar3 * 4 + 1] = 1;
    local_158[iVar3 * 4 + 2] = 0;
    local_14c[iVar3 * 4] = 1;
    local_158[iVar7 * 4] = 0x48769;
    local_158[iVar7 * 4 + 1] = 1;
    local_158[iVar7 * 4 + 2] = 0;
    local_14c[iVar7 * 4] = 0;
    local_15c = 1;
    FUN_00992474(&local_168,unaff_r6,iVar3 + 2);
    FUN_009923fc(&local_168,iVar7 * 0xc + 0x18,local_160 - 6);
    if (*(int *)(param_3 + 0x90) == 0) {
      uVar4 = 2;
    }
    else {
      local_14c[0x1e] = 1;
      local_14c[0x1d] = 0x5829a;
      uVar4 = 3;
      uVar11 = 2;
      local_d0 = param_3 + 0x8c;
      local_cc[0] = 0;
    }
    uVar10 = (uint)(*(int *)(param_3 + 0x90) != 0);
    uVar5 = uVar4;
    uVar8 = uVar11;
    if (*(int *)(param_3 + 0x98) != 0) {
      local_14c[uVar10 * 4 + 0x1d] = 0x5829d;
      local_14c[uVar10 * 4 + 0x1e] = 1;
      local_cc[uVar10 * 4] = 0;
      local_14c[uVar10 * 4 + 0x1f] = (uint)(param_3 + 0x94);
      uVar5 = uVar10 + 3;
      uVar8 = uVar4;
      uVar10 = uVar11;
    }
    puVar6 = local_14c + 0x1d;
    iVar7 = *(int *)(param_3 + 0xa4);
    uVar11 = uVar5;
    uVar4 = uVar8;
    if (iVar7 != 0) {
      uVar11 = uVar10 + 3;
      puVar6[uVar10 * 4] = 0x38827;
      local_cc[uVar10 * 4] = iVar7;
      local_14c[uVar10 * 4 + 0x1e] = 1;
      local_14c[uVar10 * 4 + 0x1f] = 0;
      uVar4 = uVar5;
      uVar10 = uVar8;
    }
    cVar1 = param_3[0x48];
    local_14c[uVar10 * 4 + 0x1d] = 0x79000;
    local_14c[uVar10 * 4 + 0x1e] = 4;
    local_14c[uVar10 * 4 + 0x1f] = (uint)&DAT_009a8cb9;
    local_cc[uVar10 * 4] = 0;
    uVar5 = uVar11;
    if (cVar1 != '\0') {
      iVar7 = FUN_009975c4(param_3 + 0x49);
      puVar6[uVar4 * 4] = 0x29003;
      local_14c[uVar4 * 4 + 0x1e] = iVar7 + 2;
      uVar5 = uVar10 + 3;
      local_cc[uVar4 * 4] = 0;
      local_14c[uVar4 * 4 + 0x1f] = (uint)(param_3 + 0x48);
      uVar4 = uVar11;
    }
    iVar7 = *(int *)(param_3 + 0xa0);
    local_14c[uVar4 * 4 + 0x1d] = 0x79101;
    local_14c[uVar4 * 4 + 0x1e] = 4;
    local_14c[uVar4 * 4 + 0x1f] = (uint)&DAT_009a8cbd;
    local_cc[uVar4 * 4] = 0;
    uVar11 = uVar5;
    if (iVar7 != 0) {
      puVar6[uVar5 * 4] = 0x5920a;
      uVar11 = uVar4 + 2;
      local_14c[uVar5 * 4 + 0x1e] = 1;
      local_cc[uVar5 * 4] = 0;
      local_14c[uVar5 * 4 + 0x1f] = (uint)(param_3 + 0x9c);
    }
    iVar7 = *(int *)(param_4 + 0x94);
    local_14c[uVar11 * 4 + 0x1d] = 0x3a001;
    local_14c[uVar11 * 4 + 0x1e] = 1;
    local_14c[uVar11 * 4 + 0x1f] = 0;
    local_cc[uVar11 * 4] = 1;
    iVar2 = uVar11 + 1;
    iVar3 = *(int *)(param_4 + 0x98);
    puVar6[iVar2 * 4] = 0x4a002;
    iVar9 = uVar11 + 2;
    local_cc[iVar2 * 4] = iVar7;
    local_14c[iVar2 * 4 + 0x1e] = 1;
    local_14c[iVar2 * 4 + 0x1f] = 0;
    puVar6[iVar9 * 4] = 0x4a003;
    cVar1 = param_3[0x5c];
    iVar7 = uVar11 + 3;
    local_14c[iVar9 * 4 + 0x1e] = 1;
    local_cc[iVar9 * 4] = iVar3;
    local_14c[iVar9 * 4 + 0x1f] = 0;
    if (cVar1 != '\0') {
      iVar3 = FUN_009975c4(param_3 + 0x5d);
      puVar6[iVar7 * 4] = 0x2a434;
      local_cc[iVar7 * 4] = 0;
      local_14c[iVar7 * 4 + 0x1e] = iVar3 + 2;
      local_14c[iVar7 * 4 + 0x1f] = (uint)(param_3 + 0x5c);
      iVar7 = uVar11 + 4;
    }
    FUN_00992474(&local_168,puVar6,iVar7);
    if (local_15c != 0) {
      if (param_2 < local_160) {
        local_160 = 0;
      }
      return local_160;
    }
  }
  return 0;
}


// ===== FUN_00996db4 @ 00996db4

undefined4
FUN_00996db4(int param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5,
            undefined4 param_6,undefined4 param_7)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  undefined4 *puVar11;
  undefined4 uVar12;
  uint uVar13;
  uint uVar14;
  undefined4 *puVar15;
  uint uVar16;
  code *pcVar17;
  undefined1 *puVar18;
  undefined4 *puVar19;
  int *piVar20;
  int iVar21;
  uint uVar22;
  uint uVar23;
  uint uVar24;
  int iVar25;
  uint uVar26;
  undefined4 *puVar27;
  undefined4 *puVar28;
  int *piVar29;
  int local_17c;
  int local_178;
  int local_174;
  int local_170;
  int **local_16c;
  undefined4 local_150;
  undefined4 local_128;
  int local_110;
  int local_10c;
  int local_108;
  int local_104;
  int *local_100;
  int local_fc;
  int local_f8;
  undefined4 local_f4;
  int aiStack_f0 [8];
  undefined4 local_d0 [3];
  undefined4 local_c4;
  undefined1 auStack_c0 [68];
  undefined1 auStack_7c [8];
  undefined4 local_74;
  
  iVar8 = *(int *)(param_1 + 0x17c24);
  uVar12 = *(undefined4 *)(param_3 + 0xa0);
  if ((iVar8 == 0) &&
     (iVar25 = FUN_00997e60(param_1 + 0x15980,param_5,param_6,*(undefined4 *)(param_3 + 0x94),
                            *(undefined4 *)(param_3 + 0x98),param_7,
                            *(undefined4 *)(param_1 + 0x17c14),*(undefined4 *)(param_1 + 0x17c18)),
     iVar25 != 0)) {
LAB_00997230:
    uVar12 = 0xfffffff3;
  }
  else {
    local_100 = *(int **)(param_1 + 0x17c28);
    local_fc = param_1 + 0x1af78;
    local_f8 = param_1 + 0x1d1a8;
    iVar25 = *(int *)(param_2 + 0x2c);
    local_f4 = 0;
    if (local_100 == (int *)0x0) {
      local_150 = 3;
      local_16c = (int **)0x0;
    }
    else {
      if (*local_100 == 0) {
        local_150 = 3;
      }
      else {
        local_150 = 1;
      }
      local_16c = &local_100;
    }
    piVar20 = *(int **)(param_1 + 0x1e2c0);
    if ((piVar20 == (int *)0x0) || (*piVar20 == 0 || iVar8 == 0)) {
      do {
        if (iVar25 - 1U <= *(uint *)(param_2 + 0x7eb4)) {
          uVar26 = 0;
          goto LAB_00996f04;
        }
        iVar3 = FUN_00990e24(param_2,param_1);
      } while (iVar3 == 0);
    }
    else {
      uVar26 = *(uint *)(param_2 + 0x7eb4);
      if (piVar20[3] == uVar26) {
        uVar16 = piVar20[2];
        while (uVar26 < uVar16) {
          iVar25 = FUN_00990e24(param_2,param_1);
          if (iVar25 != 0) goto LAB_00996eac;
          uVar26 = *(uint *)(param_2 + 0x7eb4);
        }
        uVar26 = piVar20[1];
LAB_00996f04:
        iVar25 = FUN_00990e24(param_2,param_1);
        if (iVar25 == 0) {
          local_170 = param_1 + 0x2300;
          iVar25 = FUN_00990e24(param_2);
          if (iVar25 == 0) {
            *(undefined4 *)(param_1 + 0x17c10) = 0;
            *(undefined4 *)(param_1 + 0x17c08) = 0;
            *(undefined4 *)(param_1 + 0x17c0c) = 0;
            if (local_16c != (int **)0x0) {
              uVar16 = uVar26 - 2;
              do {
                uVar13 = uVar16 + 1;
                FUN_009912ec(param_1,*(undefined4 *)(param_3 + 0x94),uVar16,local_150);
                uVar16 = uVar13;
              } while (uVar26 != uVar13);
            }
            FUN_00997590(local_d0,0,0x54);
            FUN_00997590(auStack_7c,0,0x54);
            uVar16 = *(uint *)(param_3 + 0x98);
            if (uVar16 <= uVar26) {
LAB_00997560:
              if (iVar8 != 0) {
                return 0;
              }
              iVar8 = FUN_00998c8c(param_1 + 0x15980);
              if (iVar8 == 0) {
                return 0;
              }
              return 0xfffffff3;
            }
            local_128 = 0;
            local_17c = param_1 + 0x4600;
            local_178 = param_1 + 0x6900;
            local_174 = param_1;
            do {
              iVar3 = local_178;
              iVar25 = local_17c;
              uVar13 = uVar16 - uVar26;
              if (7 < uVar13) {
                uVar13 = 8;
              }
              pcVar17 = *(code **)(param_1 + 0x17c00);
              if (uVar16 == uVar26) {
                local_178 = local_170;
                local_17c = local_174;
                local_170 = iVar3;
                local_174 = iVar25;
              }
              else {
                uVar22 = 0;
                iVar25 = param_1 + 0x8c00;
                uVar16 = uVar26;
                while( true ) {
                  iVar7 = local_170;
                  iVar5 = local_174;
                  iVar21 = *(int *)(param_2 + 0x2c);
                  iVar3 = 0;
                  if (pcVar17 != (code *)0x0) {
                    iVar3 = (*pcVar17)(*(undefined4 *)(param_1 + 0x17c04));
                  }
                  if (*(int *)(param_1 + 0x1e2c4) != 0) {
                    iVar4 = FUN_00990d90(param_2);
                    if (iVar4 != 0) {
                      FUN_00990b2c(param_2,auStack_c0);
                      local_d0[0] = 1;
                      local_c4 = *(undefined4 *)(param_2 + 0x7eb4);
                    }
                    if (uVar13 - 1 == uVar22) {
                      FUN_009975a8(auStack_7c,local_d0,0x54);
                      local_128 = *(undefined4 *)(param_2 + 0x7eb4);
                    }
                  }
                  iVar4 = FUN_00990e24(param_2,local_17c);
                  if ((iVar4 != 0) || (iVar4 = FUN_00990e24(param_2,local_178), iVar4 != 0))
                  goto LAB_00996eac;
                  iVar4 = 0;
                  if (*(code **)(param_1 + 0x17c00) != (code *)0x0) {
                    iVar4 = (**(code **)(param_1 + 0x17c00))(*(undefined4 *)(param_1 + 0x17c04));
                  }
                  *(int *)(param_1 + 0x17c08) = (*(int *)(param_1 + 0x17c08) - iVar3) + iVar4;
                  if (local_16c != (int **)0x0) {
                    FUN_009912ec(param_1,*(undefined4 *)(param_3 + 0x94),uVar16,local_150);
                  }
                  uVar2 = 0;
                  if (*(int *)(param_1 + 0x1e2c8) != 0) {
                    uVar2 = FUN_00995d5c(*(int *)(param_1 + 0x1e2c8),uVar16);
                  }
                  local_110 = local_174;
                  local_104 = local_178;
                  local_10c = local_170;
                  local_108 = local_17c;
                  FUN_009928e8(param_3,param_4,uVar12,&local_110,iVar21 + uVar16 * 2,
                               *(undefined4 *)(param_2 + 0x28),iVar25,local_16c,uVar2);
                  if (*(code **)(param_1 + 0x17c00) == (code *)0x0) {
                    iVar3 = 0;
                    pcVar17 = (code *)0x0;
                  }
                  else {
                    iVar3 = (**(code **)(param_1 + 0x17c00))(*(undefined4 *)(param_1 + 0x17c04));
                    pcVar17 = *(code **)(param_1 + 0x17c00);
                  }
                  uVar22 = uVar22 + 1;
                  iVar25 = iVar25 + 0x1998;
                  uVar16 = uVar16 + 1;
                  *(int *)(param_1 + 0x17c0c) = (*(int *)(param_1 + 0x17c0c) - iVar4) + iVar3;
                  if (uVar13 == uVar22) break;
                  local_170 = local_178;
                  local_174 = local_17c;
                  local_178 = iVar7;
                  local_17c = iVar5;
                }
              }
              iVar3 = local_170;
              iVar25 = local_174;
              if (pcVar17 == (code *)0x0) {
                iVar5 = 0;
              }
              else {
                iVar5 = (*pcVar17)(*(undefined4 *)(param_1 + 0x17c04));
              }
              pcVar17 = *(code **)(param_1 + 0x17c1c);
              if (pcVar17 != (code *)0x0) {
                iVar7 = param_1 + 0x8c00;
                piVar20 = aiStack_f0;
                do {
                  piVar29 = piVar20 + 1;
                  *piVar20 = iVar7;
                  iVar7 = iVar7 + 0x1998;
                  piVar20 = piVar29;
                } while (piVar29 != aiStack_f0 + uVar13);
                (*pcVar17)(*(undefined4 *)(param_1 + 0x17c20),aiStack_f0,uVar13,
                           *(undefined4 *)(param_3 + 0x94));
              }
              if ((iVar8 == 0) && (uVar16 = *(uint *)(param_3 + 0x94), uVar16 != 0)) {
                puVar19 = (undefined4 *)(param_1 + 0x8c00 + uVar13 * 0x1998);
                uVar22 = 0;
                do {
                  uVar16 = uVar16 - uVar22;
                  uVar14 = uVar16;
                  if (7 < uVar16) {
                    uVar14 = 8;
                  }
                  uVar1 = uVar14 * 3;
                  puVar28 = (undefined4 *)(param_1 + 0x158c0);
                  uVar24 = uVar1 - 0x10;
                  puVar9 = puVar19 + uVar13 * -0x666;
                  do {
                    puVar27 = puVar9;
                    puVar9 = puVar28;
                    puVar10 = puVar27;
                    if ((((uint)puVar27 | (uint)puVar28) & 3) == 0) {
                      if (uVar1 < 0x10) {
                        if (uVar16 != 1) {
                          uVar6 = uVar1;
                          goto LAB_0099736c;
                        }
                        iVar7 = 2;
                        goto LAB_009973b0;
                      }
                      *puVar28 = *puVar27;
                      puVar28[1] = puVar27[1];
                      puVar10 = puVar27 + 4;
                      puVar28[2] = puVar27[2];
                      puVar9 = puVar28 + 4;
                      puVar28[3] = puVar27[3];
                      uVar6 = uVar24;
                      if (3 < uVar24) {
LAB_0099736c:
                        uVar23 = uVar6 & 0xfffffffc;
                        puVar15 = puVar9 + -1;
                        puVar11 = puVar10;
                        do {
                          puVar15 = puVar15 + 1;
                          *puVar15 = *puVar11;
                          puVar11 = puVar11 + 1;
                        } while ((undefined4 *)((int)puVar9 + (uVar23 - 4)) != puVar15);
                        puVar10 = (undefined4 *)((int)puVar10 + uVar23);
                        puVar9 = (undefined4 *)((int)puVar9 + uVar23);
                        uVar6 = uVar6 & 3;
                      }
                      if (uVar6 != 0) {
                        iVar7 = uVar6 - 1;
                        goto LAB_009973b0;
                      }
                    }
                    else {
                      iVar7 = uVar1 - 1;
LAB_009973b0:
                      puVar18 = (undefined1 *)((int)puVar9 + -1);
                      puVar9 = puVar10;
                      do {
                        puVar11 = (undefined4 *)((int)puVar9 + 1);
                        puVar18 = puVar18 + 1;
                        *puVar18 = *(undefined1 *)puVar9;
                        puVar9 = puVar11;
                      } while (puVar11 != (undefined4 *)((int)puVar10 + iVar7 + 1));
                    }
                    puVar28 = (undefined4 *)((int)puVar28 + uVar1);
                    puVar9 = puVar27 + 0x666;
                  } while (puVar19 != puVar27 + 0x666);
                  iVar7 = FUN_00998648(param_1 + 0x15980,param_1 + 0x158c0,uVar14 * uVar13 * 3);
                  if (iVar7 != 0) goto LAB_00997230;
                  uVar22 = uVar22 + 8;
                  uVar16 = *(uint *)(param_3 + 0x94);
                  puVar19 = puVar27 + 0x66c;
                } while (uVar22 < uVar16);
              }
              iVar7 = 0;
              if (*(code **)(param_1 + 0x17c00) != (code *)0x0) {
                iVar7 = (**(code **)(param_1 + 0x17c00))(*(undefined4 *)(param_1 + 0x17c04));
              }
              *(int *)(param_1 + 0x17c10) = (*(int *)(param_1 + 0x17c10) - iVar5) + iVar7;
              if (*(int *)(param_1 + 0x1e2c4) != 0) {
                local_74 = local_128;
                iVar5 = FUN_009975a8(*(int *)(param_1 + 0x1e2c4),auStack_7c,0x54);
                *(uint *)(iVar5 + 4) = uVar26 + 8;
              }
              if ((*(code **)(param_1 + 0x17bf8) != (code *)0x0) &&
                 (iVar5 = (**(code **)(param_1 + 0x17bf8))(*(undefined4 *)(param_1 + 0x17bfc)),
                 iVar5 != 0)) {
                return 0xfffffff2;
              }
              uVar26 = uVar26 + 8;
              uVar16 = *(uint *)(param_3 + 0x98);
              if (uVar16 <= uVar26) goto LAB_00997560;
              local_170 = local_178;
              local_174 = local_17c;
              local_178 = iVar3;
              local_17c = iVar25;
            } while( true );
          }
        }
      }
    }
LAB_00996eac:
    uVar12 = 0xfffffff5;
  }
  return uVar12;
}


// ===== FUN_00997590 @ 00997590

void FUN_00997590(undefined1 *param_1,undefined1 param_2,int param_3)

{
  undefined1 *puVar1;
  
  puVar1 = param_1 + param_3;
  for (; param_1 != puVar1; param_1 = param_1 + 1) {
    *param_1 = param_2;
  }
  return;
}


// ===== FUN_009975a8 @ 009975a8

void FUN_009975a8(int param_1,undefined1 *param_2,int param_3)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  
  puVar2 = (undefined1 *)(param_1 + -1);
  puVar1 = param_2 + param_3;
  for (; param_2 != puVar1; param_2 = param_2 + 1) {
    puVar2 = puVar2 + 1;
    *puVar2 = *param_2;
  }
  return;
}


// ===== FUN_009975c4 @ 009975c4

int FUN_009975c4(char *param_1)

{
  char *pcVar1;
  char *pcVar2;
  
  pcVar1 = param_1;
  do {
    pcVar2 = pcVar1;
    pcVar1 = pcVar2 + 1;
  } while (*pcVar2 != '\0');
  return (int)pcVar2 - (int)param_1;
}


// ===== FUN_009975e4 @ 009975e4

void FUN_009975e4(int param_1,int param_2,int param_3,int param_4)

{
  byte bVar1;
  uint uVar2;
  byte *pbVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  byte *pbVar8;
  
  iVar5 = 0;
  FUN_00997590(param_1 + param_2 * 0x200,0,0x200,param_4,param_4);
  FUN_00997590(param_1 + (param_2 + 8) * 0x100,0,0x100);
  iVar6 = 1;
  iVar7 = 0;
  pbVar8 = (byte *)(param_3 + -1);
  do {
    pbVar8 = pbVar8 + 1;
    if (*pbVar8 != 0) {
      pbVar3 = (byte *)(param_4 + -1 + iVar5);
      uVar2 = 0;
      do {
        uVar4 = uVar2;
        pbVar3 = pbVar3 + 1;
        bVar1 = *pbVar3;
        *(short *)(param_1 + ((uint)bVar1 + param_2 * 0x100) * 2) = (short)iVar7 + (short)uVar4;
        *(char *)(param_1 + param_2 * 0x100 + (uint)bVar1 + 0x800) = (char)iVar6;
        uVar2 = uVar4 + 1;
      } while (uVar4 + 1 < (uint)*pbVar8);
      iVar5 = iVar5 + 1 + uVar4;
      iVar7 = uVar4 + iVar7 + 1;
    }
    iVar6 = iVar6 + 1;
    iVar7 = iVar7 << 1;
  } while (iVar6 != 0x11);
  return;
}


// ===== FUN_0099769c @ 0099769c

void FUN_0099769c(int *param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  
  iVar12 = *param_1 + param_1[param_2 * 7];
  iVar4 = *param_1 - param_1[param_2 * 7];
  iVar8 = param_1[param_2] + param_1[param_2 * 6];
  iVar7 = param_1[param_2] - param_1[param_2 * 6];
  iVar5 = param_1[param_2 * 2] + param_1[param_2 * 5];
  iVar13 = param_1[param_2 * 2] - param_1[param_2 * 5];
  iVar1 = param_1[param_2 * 3] + param_1[param_2 * 4];
  iVar3 = param_1[param_2 * 3] - param_1[param_2 * 4];
  iVar6 = iVar12 + iVar1;
  iVar12 = iVar12 - iVar1;
  iVar2 = iVar8 + iVar5;
  iVar8 = iVar8 - iVar5;
  iVar1 = iVar6 + iVar2;
  iVar6 = iVar6 - iVar2;
  if (param_3 == 0) {
    iVar6 = iVar6 * 4;
    iVar5 = 0x400;
    iVar2 = 0xb;
    iVar1 = iVar1 * 4;
  }
  else {
    iVar6 = iVar6 + 2 >> 2;
    iVar5 = 0x4000;
    iVar2 = 0xf;
    iVar1 = iVar1 + 2 >> 2;
  }
  *param_1 = iVar1;
  param_1[param_2 * 4] = iVar6;
  iVar10 = (iVar7 + iVar13) * -0x5203;
  iVar1 = (iVar7 + iVar3 + iVar4 + iVar13) * 0x25a1;
  iVar9 = (iVar7 + iVar3) * -0x3ec5 + iVar1;
  iVar1 = (iVar4 + iVar13) * -0xc7c + iVar1;
  iVar6 = (iVar12 + iVar8) * 0x1151;
  iVar11 = (iVar4 + iVar3) * -0x1ccd;
  param_1[param_2 * 2] = iVar6 + iVar12 * 0x187e + iVar5 >> iVar2;
  param_1[param_2 * 6] = iVar8 * -0x3b21 + iVar6 + iVar5 >> iVar2;
  param_1[param_2 * 7] = iVar11 + iVar3 * 0x98e + iVar9 + iVar5 >> iVar2;
  param_1[param_2 * 5] = iVar13 * 0x41b3 + iVar10 + iVar1 + iVar5 >> iVar2;
  param_1[param_2 * 3] = iVar7 * 0x6254 + iVar10 + iVar9 + iVar5 >> iVar2;
  param_1[param_2] = iVar4 * 0x300b + iVar11 + iVar1 + iVar5 >> iVar2;
  return;
}


// ===== FUN_00997904 @ 00997904

undefined4 FUN_00997904(int param_1)

{
  int iVar1;
  uint uVar2;
  
  if (*(int *)(param_1 + 0x2270) != 0) {
    iVar1 = (**(code **)(param_1 + 0x2240))(*(undefined4 *)(param_1 + 0x2244),param_1 + 0x1240);
    if (iVar1 != 0) {
      *(undefined1 *)(param_1 + 0x2275) = 3;
      *(undefined1 *)(param_1 + 0x2276) = 0xfc;
      return 0;
    }
    uVar2 = *(uint *)(param_1 + 0x2248);
    *(uint *)(param_1 + 0x2248) = uVar2 + *(uint *)(param_1 + 0x2270);
    *(uint *)(param_1 + 0x224c) =
         *(int *)(param_1 + 0x224c) + (uint)CARRY4(uVar2,*(uint *)(param_1 + 0x2270));
    *(undefined4 *)(param_1 + 0x2270) = 0;
  }
  return 1;
}


// ===== FUN_00997988 @ 00997988

undefined4 FUN_00997988(int param_1,undefined1 param_2)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = *(int *)(param_1 + 0x2270);
  uVar2 = iVar1 + 1;
  *(uint *)(param_1 + 0x2270) = uVar2;
  *(undefined1 *)(param_1 + iVar1 + 0x1240) = param_2;
  if (uVar2 < 0x1000) {
    return 1;
  }
  if (*(int *)(param_1 + 0x2270) != 0) {
    iVar1 = (**(code **)(param_1 + 0x2240))(*(undefined4 *)(param_1 + 0x2244),param_1 + 0x1240);
    if (iVar1 != 0) {
      *(undefined1 *)(param_1 + 0x2275) = 3;
      *(undefined1 *)(param_1 + 0x2276) = 0xfc;
      return 0;
    }
    uVar2 = *(uint *)(param_1 + 0x2248);
    *(uint *)(param_1 + 0x2248) = uVar2 + *(uint *)(param_1 + 0x2270);
    *(uint *)(param_1 + 0x224c) =
         *(int *)(param_1 + 0x224c) + (uint)CARRY4(uVar2,*(uint *)(param_1 + 0x2270));
    *(undefined4 *)(param_1 + 0x2270) = 0;
  }
  return 1;
}


// ===== FUN_009979b8 @ 009979b8

int FUN_009979b8(int param_1,undefined1 param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  if (*(char *)(param_1 + 0x2275) != '\x01') {
    return 0;
  }
  iVar1 = *(int *)(param_1 + 0x2270);
  uVar3 = iVar1 + 1;
  *(uint *)(param_1 + 0x2270) = uVar3;
  *(undefined1 *)(param_1 + iVar1 + 0x1240) = 0xff;
  iVar1 = param_1;
  if (0xfff < uVar3) {
    iVar1 = FUN_00997904();
    if (iVar1 == 0) {
      return 0;
    }
    if (*(char *)(param_1 + 0x2275) != '\x01') {
      return 0;
    }
    uVar3 = *(uint *)(param_1 + 0x2270);
  }
  uVar2 = uVar3 + 1;
  *(uint *)(param_1 + 0x2270) = uVar2;
  if (uVar2 < 0x1000) {
    iVar1 = 1;
  }
  *(undefined1 *)(param_1 + uVar3 + 0x1240) = param_2;
  if (uVar2 < 0x1000) {
    return iVar1;
  }
  if (*(int *)(param_1 + 0x2270) != 0) {
    iVar1 = (**(code **)(param_1 + 0x2240))(*(undefined4 *)(param_1 + 0x2244),param_1 + 0x1240);
    if (iVar1 != 0) {
      *(undefined1 *)(param_1 + 0x2275) = 3;
      *(undefined1 *)(param_1 + 0x2276) = 0xfc;
      return 0;
    }
    uVar3 = *(uint *)(param_1 + 0x2248);
    *(uint *)(param_1 + 0x2248) = uVar3 + *(uint *)(param_1 + 0x2270);
    *(uint *)(param_1 + 0x224c) =
         *(int *)(param_1 + 0x224c) + (uint)CARRY4(uVar3,*(uint *)(param_1 + 0x2270));
    *(undefined4 *)(param_1 + 0x2270) = 0;
  }
  return 1;
}


// ===== FUN_009979cc @ 009979cc

int FUN_009979cc(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  undefined1 in_r12;
  uint uVar3;
  
  iVar1 = *(int *)(param_2 + 0x270);
  uVar3 = iVar1 + 1;
  *(uint *)(param_2 + 0x270) = uVar3;
  *(undefined1 *)(param_1 + iVar1 + 0x1240) = 0xff;
  iVar1 = param_1;
  if (0xfff < uVar3) {
    iVar1 = FUN_00997904();
    if (iVar1 == 0) {
      return 0;
    }
    if (*(char *)(param_2 + 0x275) != '\x01') {
      return 0;
    }
    uVar3 = *(uint *)(param_2 + 0x270);
  }
  uVar2 = uVar3 + 1;
  *(uint *)(param_2 + 0x270) = uVar2;
  if (uVar2 < 0x1000) {
    iVar1 = 1;
  }
  *(undefined1 *)(param_1 + uVar3 + 0x1240) = in_r12;
  if (uVar2 < 0x1000) {
    return iVar1;
  }
  if (*(int *)(param_1 + 0x2270) != 0) {
    iVar1 = (**(code **)(param_1 + 0x2240))(*(undefined4 *)(param_1 + 0x2244),param_1 + 0x1240);
    if (iVar1 != 0) {
      *(undefined1 *)(param_1 + 0x2275) = 3;
      *(undefined1 *)(param_1 + 0x2276) = 0xfc;
      return 0;
    }
    uVar3 = *(uint *)(param_1 + 0x2248);
    *(uint *)(param_1 + 0x2248) = uVar3 + *(uint *)(param_1 + 0x2270);
    *(uint *)(param_1 + 0x224c) =
         *(int *)(param_1 + 0x224c) + (uint)CARRY4(uVar3,*(uint *)(param_1 + 0x2270));
    *(undefined4 *)(param_1 + 0x2270) = 0;
  }
  return 1;
}


// ===== FUN_00997a70 @ 00997a70

uint FUN_00997a70(int param_1,undefined4 param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  bool bVar4;
  
  if (*(char *)(param_1 + 0x2275) != '\x01') {
    return 0;
  }
  iVar2 = *(int *)(param_1 + 0x2270);
  uVar3 = iVar2 + 1;
  *(uint *)(param_1 + 0x2270) = uVar3;
  *(char *)(param_1 + iVar2 + 0x1240) = (char)((uint)param_2 >> 8);
  if (0xfff < uVar3) {
    iVar2 = FUN_00997904();
    if (iVar2 == 0) {
      return 0;
    }
    if (*(char *)(param_1 + 0x2275) != '\x01') {
      return 0;
    }
    uVar3 = *(uint *)(param_1 + 0x2270);
  }
  uVar1 = uVar3 + 1;
  bVar4 = uVar1 < 0x1000;
  *(uint *)(param_1 + 0x2270) = uVar1;
  if (bVar4) {
    uVar1 = 1;
  }
  *(char *)(param_1 + uVar3 + 0x1240) = (char)param_2;
  if (bVar4) {
    return uVar1;
  }
  if (*(int *)(param_1 + 0x2270) != 0) {
    iVar2 = (**(code **)(param_1 + 0x2240))(*(undefined4 *)(param_1 + 0x2244),param_1 + 0x1240);
    if (iVar2 != 0) {
      *(undefined1 *)(param_1 + 0x2275) = 3;
      *(undefined1 *)(param_1 + 0x2276) = 0xfc;
      return 0;
    }
    uVar3 = *(uint *)(param_1 + 0x2248);
    *(uint *)(param_1 + 0x2248) = uVar3 + *(uint *)(param_1 + 0x2270);
    *(uint *)(param_1 + 0x224c) =
         *(int *)(param_1 + 0x224c) + (uint)CARRY4(uVar3,*(uint *)(param_1 + 0x2270));
    *(undefined4 *)(param_1 + 0x2270) = 0;
  }
  return 1;
}


// ===== FUN_00997a84 @ 00997a84

uint FUN_00997a84(int param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  undefined4 in_r12;
  uint uVar3;
  bool bVar4;
  
  iVar2 = *(int *)(param_2 + 0x270);
  uVar3 = iVar2 + 1;
  *(uint *)(param_2 + 0x270) = uVar3;
  *(char *)(param_1 + iVar2 + 0x1240) = (char)((uint)in_r12 >> 8);
  if (0xfff < uVar3) {
    iVar2 = FUN_00997904();
    if (iVar2 == 0) {
      return 0;
    }
    if (*(char *)(param_2 + 0x275) != '\x01') {
      return 0;
    }
    uVar3 = *(uint *)(param_2 + 0x270);
  }
  uVar1 = uVar3 + 1;
  bVar4 = uVar1 < 0x1000;
  *(uint *)(param_2 + 0x270) = uVar1;
  if (bVar4) {
    uVar1 = 1;
  }
  *(char *)(param_1 + uVar3 + 0x1240) = (char)in_r12;
  if (bVar4) {
    return uVar1;
  }
  if (*(int *)(param_1 + 0x2270) != 0) {
    iVar2 = (**(code **)(param_1 + 0x2240))(*(undefined4 *)(param_1 + 0x2244),param_1 + 0x1240);
    if (iVar2 != 0) {
      *(undefined1 *)(param_1 + 0x2275) = 3;
      *(undefined1 *)(param_1 + 0x2276) = 0xfc;
      return 0;
    }
    uVar3 = *(uint *)(param_1 + 0x2248);
    *(uint *)(param_1 + 0x2248) = uVar3 + *(uint *)(param_1 + 0x2270);
    *(uint *)(param_1 + 0x224c) =
         *(int *)(param_1 + 0x224c) + (uint)CARRY4(uVar3,*(uint *)(param_1 + 0x2270));
    *(undefined4 *)(param_1 + 0x2270) = 0;
  }
  return 1;
}


// ===== FUN_00997b2c @ 00997b2c

undefined4 FUN_00997b2c(int param_1,uint param_2,byte param_3)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  byte bVar4;
  uint uVar5;
  
  bVar4 = *(char *)(param_1 + 0x2274) + param_3;
  uVar2 = param_2 & ~(-1 << (uint)param_3) | *(int *)(param_1 + 0x226c) << (uint)param_3;
  *(byte *)(param_1 + 0x2274) = bVar4;
  *(uint *)(param_1 + 0x226c) = uVar2;
  do {
    uVar5 = (uint)bVar4;
    uVar1 = uVar2 >> (uVar5 - 8 & 0xff);
    if (uVar5 < 8) {
      *(uint *)(param_1 + 0x226c) = uVar2 & ~(-1 << uVar5);
      return 1;
    }
    *(char *)(param_1 + 0x2274) = (char)(uVar5 - 8);
    if (*(char *)(param_1 + 0x2275) != '\x01') {
      return 0;
    }
    iVar3 = *(int *)(param_1 + 0x2270);
    uVar2 = iVar3 + 1;
    *(uint *)(param_1 + 0x2270) = uVar2;
    *(char *)(param_1 + iVar3 + 0x1240) = (char)uVar1;
    if ((0xfff < uVar2) && (iVar3 = FUN_00997904(param_1), iVar3 == 0)) {
      return 0;
    }
    if ((uVar1 & 0xff) == 0xff) {
      if (*(char *)(param_1 + 0x2275) != '\x01') {
        return 0;
      }
      iVar3 = *(int *)(param_1 + 0x2270);
      uVar2 = iVar3 + 1;
      *(uint *)(param_1 + 0x2270) = uVar2;
      *(undefined1 *)(param_1 + iVar3 + 0x1240) = 0;
      if ((0xfff < uVar2) && (iVar3 = FUN_00997904(param_1), iVar3 == 0)) {
        return 0;
      }
    }
    bVar4 = *(byte *)(param_1 + 0x2274);
    uVar2 = *(uint *)(param_1 + 0x226c);
  } while( true );
}


// ===== FUN_00997c4c @ 00997c4c

int FUN_00997c4c(int param_1,undefined1 param_2,int param_3,int param_4,int param_5)

{
  undefined1 uVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  int iVar7;
  
  if (*(char *)(param_1 + 0x2275) == '\x01') {
    iVar7 = *(int *)(param_1 + 0x2270);
    uVar4 = iVar7 + 1;
    *(uint *)(param_1 + 0x2270) = uVar4;
    *(undefined1 *)(param_1 + iVar7 + 0x1240) = 0xff;
    if (0xfff < uVar4) {
      iVar7 = FUN_00997904();
      if (iVar7 == 0) {
        return 0;
      }
      if (*(char *)(param_1 + 0x2275) != '\x01') {
        return 0;
      }
      uVar4 = *(uint *)(param_1 + 0x2270);
    }
    *(uint *)(param_1 + 0x2270) = uVar4 + 1;
    *(undefined1 *)(param_1 + uVar4 + 0x1240) = 0xc4;
    if ((0xfff < uVar4 + 1) && (iVar7 = FUN_00997904(param_1), iVar7 == 0)) {
      return 0;
    }
    iVar7 = FUN_00997a70(param_1,param_5 + 0x13);
    if (iVar7 == 0) {
      return 0;
    }
    if (*(char *)(param_1 + 0x2275) == '\x01') {
      iVar3 = *(int *)(param_1 + 0x2270);
      uVar4 = iVar3 + 1;
      *(uint *)(param_1 + 0x2270) = uVar4;
      *(undefined1 *)(param_1 + iVar3 + 0x1240) = param_2;
      cVar2 = '\x01';
      if (0xfff < uVar4) {
        iVar3 = FUN_00997904(param_1);
        if (iVar3 == 0) {
          return 0;
        }
        cVar2 = *(char *)(param_1 + 0x2275);
      }
      puVar5 = (undefined1 *)(param_3 + -1);
      do {
        if (cVar2 != '\x01') {
          return 0;
        }
        while( true ) {
          iVar3 = *(int *)(param_1 + 0x2270);
          puVar5 = puVar5 + 1;
          uVar1 = *puVar5;
          uVar4 = iVar3 + 1;
          *(uint *)(param_1 + 0x2270) = uVar4;
          *(undefined1 *)(param_1 + iVar3 + 0x1240) = uVar1;
          if (0xfff < uVar4) break;
          cVar2 = '\x01';
          if ((undefined1 *)(param_3 + 0xf) == puVar5) goto LAB_00997d78;
        }
        iVar3 = FUN_00997904(param_1);
        if (iVar3 == 0) {
          return 0;
        }
        cVar2 = *(char *)(param_1 + 0x2275);
      } while ((undefined1 *)(param_3 + 0xf) != puVar5);
LAB_00997d78:
      puVar5 = (undefined1 *)(param_4 + -1);
      puVar6 = puVar5 + param_5;
      while (cVar2 == '\x01') {
        iVar3 = *(int *)(param_1 + 0x2270);
        puVar5 = puVar5 + 1;
        uVar1 = *puVar5;
        uVar4 = iVar3 + 1;
        *(uint *)(param_1 + 0x2270) = uVar4;
        *(undefined1 *)(param_1 + iVar3 + 0x1240) = uVar1;
        if ((0xfff < uVar4) && (iVar3 = FUN_00997904(param_1), iVar3 == 0)) {
          return 0;
        }
        if (puVar5 == puVar6) {
          return iVar7;
        }
        cVar2 = *(char *)(param_1 + 0x2275);
      }
    }
  }
  return 0;
}


// ===== FUN_00997e60 @ 00997e60

int FUN_00997e60(int param_1,int param_2,undefined4 param_3,int param_4,int param_5,uint param_6,
                int param_7,int param_8)

{
  longlong lVar1;
  undefined4 uVar2;
  int iVar3;
  char cVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  undefined1 uVar8;
  uint uVar9;
  undefined *puVar10;
  byte *pbVar11;
  undefined *puVar12;
  undefined1 *puVar13;
  undefined4 *puVar14;
  uint uVar15;
  byte *pbVar16;
  uint uVar17;
  undefined1 *local_40;
  undefined4 *local_3c;
  undefined *local_38;
  int local_34;
  undefined *local_30;
  undefined *local_2c;
  
  if ((param_1 != 0) && ((param_7 == 0 || (param_8 - 8U < 0xfff6)))) {
    *(undefined1 *)(param_1 + 0x2276) = 0xff;
    uVar15 = 3;
    *(undefined1 *)(param_1 + 0x2275) = 3;
    *(undefined4 *)(param_1 + 0x2248) = 0;
    *(undefined4 *)(param_1 + 0x224c) = 0;
    if ((param_4 - 1U < 0xffff && param_2 != 0) && ((param_5 - 1U < 0xffff && (param_6 - 1 < 100))))
    {
      *(undefined4 *)(param_1 + 0x2244) = param_3;
      *(int *)(param_1 + 0x2250) = param_4;
      uVar17 = param_6;
      if (0x31 < param_6) {
        uVar17 = 100 - param_6;
      }
      *(int *)(param_1 + 0x2240) = param_2;
      *(int *)(param_1 + 0x2254) = param_5;
      *(undefined4 *)(param_1 + 0x225c) = 0;
      *(undefined4 *)(param_1 + 0x2258) = 0;
      *(undefined4 *)(param_1 + 0x2260) = 0;
      *(undefined4 *)(param_1 + 0x2264) = 0;
      *(undefined4 *)(param_1 + 0x2268) = 0;
      *(undefined4 *)(param_1 + 0x226c) = 0;
      *(undefined4 *)(param_1 + 0x2270) = 0;
      *(undefined1 *)(param_1 + 0x2276) = 0;
      if (0x31 < param_6) {
        uVar15 = uVar17 << 1;
      }
      *(undefined2 *)(param_1 + 0x2274) = 0x100;
      if (param_6 < 0x32) {
        uVar5 = 1;
        do {
          uVar17 = uVar17 * 2;
          uVar5 = uVar5 * 2;
        } while (uVar17 < 0x9c5);
        if (uVar5 == 0) {
          uVar15 = 0;
        }
        else {
          uVar15 = 0;
          uVar6 = 5000;
          do {
            if (uVar17 <= uVar6) {
              uVar6 = uVar6 - uVar17;
              uVar15 = uVar15 | uVar5;
            }
            uVar5 = uVar5 >> 1;
            uVar17 = uVar17 >> 1;
          } while (uVar5 != 0);
        }
      }
      local_38 = &DAT_009a9622;
      local_30 = &DAT_009a9622;
      local_3c = (undefined4 *)(param_1 + 0xf7c);
      local_40 = (undefined1 *)(param_1 + 0xbff);
      pbVar16 = &UNK_009a9681;
      local_2c = &DAT_009a94b2;
      local_34 = 0;
      do {
        pbVar11 = pbVar16 + -0x40;
        puVar13 = local_40;
        puVar14 = local_3c;
        do {
          pbVar11 = pbVar11 + 1;
          uVar17 = uVar15 * *pbVar11 + 0x32;
          if (uVar17 < 200) {
            uVar5 = 100;
            uVar6 = 1;
LAB_00997fc8:
            uVar9 = 0;
            do {
              if (uVar5 <= uVar17) {
                uVar17 = uVar17 - uVar5;
                uVar9 = uVar9 | uVar6;
              }
              uVar6 = uVar6 >> 1;
              uVar5 = uVar5 >> 1;
            } while (uVar6 != 0);
            if (uVar9 == 0) goto LAB_0099809c;
            if (0xfe < uVar9) {
              uVar9 = 0xff;
            }
            lVar1 = (ulonglong)uVar9 * 8 + 0xffffffff;
            uVar8 = (undefined1)uVar9;
            uVar2 = FUN_009a69d8((int)lVar1,(int)((ulonglong)lVar1 >> 0x20),uVar9 << 3);
          }
          else {
            uVar6 = 1;
            uVar5 = 100;
            do {
              uVar5 = uVar5 * 2;
              uVar6 = uVar6 * 2;
            } while (uVar5 <= uVar17 >> 1);
            if (uVar6 != 0) goto LAB_00997fc8;
LAB_0099809c:
            uVar2 = 0x20000000;
            uVar8 = 1;
          }
          puVar13 = puVar13 + 1;
          *puVar13 = uVar8;
          puVar14 = puVar14 + 1;
          *puVar14 = uVar2;
        } while (pbVar11 != pbVar16);
        FUN_009975e4(param_1,local_34,local_30,&DAT_009a9616);
        puVar10 = &DAT_009a95f6;
        FUN_009975e4(param_1,local_34 + 2,&DAT_009a95f6 + local_34 * 0x10,local_2c);
        local_30 = local_30 + 0x10;
        local_2c = local_2c + 0xa2;
        local_40 = local_40 + 0x40;
        pbVar16 = pbVar16 + 0x40;
        local_3c = local_3c + 0x40;
        if (local_34 == 1) goto LAB_009980b4;
        local_34 = 1;
      } while( true );
    }
  }
  return -1;
LAB_009980b4:
  iVar3 = FUN_009979b8(param_1,0xd8);
  if (iVar3 != 0) {
    if (param_7 == 0) {
      iVar3 = FUN_009979b8(param_1,0xe0);
      if ((iVar3 == 0) || (iVar3 = FUN_00997a70(param_1,0x10), iVar3 == 0)) goto LAB_00998168;
      puVar12 = (undefined *)((int)&DAT_009a94a0 + 3);
      do {
        if (*(char *)(param_1 + 0x2275) != '\x01') goto LAB_00998168;
        iVar3 = *(int *)(param_1 + 0x2270);
        uVar15 = iVar3 + 1;
        puVar12 = puVar12 + 1;
        uVar8 = *puVar12;
        *(uint *)(param_1 + 0x2270) = uVar15;
        *(undefined1 *)(param_1 + iVar3 + 0x1240) = uVar8;
        if ((0xfff < uVar15) && (iVar3 = FUN_00997904(), iVar3 == 0)) goto LAB_00998168;
      } while (puVar12 != &UNK_009a94b1);
    }
    else {
      iVar3 = FUN_009979b8(param_1,0xe1);
      if ((iVar3 == 0) || (iVar3 = FUN_00997a70(param_1,param_8 + 2), iVar3 == 0))
      goto LAB_00998168;
      if (param_8 != 0) {
        puVar13 = (undefined1 *)(param_7 + -1);
        cVar4 = *(char *)(param_1 + 0x2275);
        while (cVar4 == '\x01') {
          iVar3 = *(int *)(param_1 + 0x2270);
          uVar15 = iVar3 + 1;
          puVar13 = puVar13 + 1;
          uVar8 = *puVar13;
          *(uint *)(param_1 + 0x2270) = uVar15;
          *(undefined1 *)(param_1 + iVar3 + 0x1240) = uVar8;
          if ((0xfff < uVar15) && (iVar3 = FUN_00997904(), iVar3 == 0)) break;
          if ((undefined1 *)(param_8 + -1 + param_7) == puVar13) goto LAB_0099822c;
          cVar4 = *(char *)(param_1 + 0x2275);
        }
        goto LAB_00998168;
      }
    }
LAB_0099822c:
    iVar3 = FUN_009979b8(param_1,0xdb);
    if ((iVar3 != 0) && (iVar3 = FUN_00997a70(param_1,0x84), iVar3 != 0)) {
      iVar3 = 0;
      while (*(char *)(param_1 + 0x2275) == '\x01') {
        iVar7 = *(int *)(param_1 + 0x2270);
        uVar15 = iVar7 + 1;
        *(uint *)(param_1 + 0x2270) = uVar15;
        *(char *)(param_1 + iVar7 + 0x1240) = (char)iVar3;
        cVar4 = '\x01';
        if (0xfff < uVar15) {
          iVar7 = FUN_00997904();
          if (iVar7 == 0) break;
          cVar4 = *(char *)(param_1 + 0x2275);
        }
        pbVar16 = &UNK_009a9701;
        while( true ) {
          if (cVar4 != '\x01') goto LAB_00998168;
          pbVar16 = pbVar16 + 1;
          uVar8 = *(undefined1 *)(param_1 + iVar3 * 0x40 + (uint)*pbVar16 + 0xc00);
          iVar7 = *(int *)(param_1 + 0x2270);
          uVar15 = iVar7 + 1;
          *(uint *)(param_1 + 0x2270) = uVar15;
          *(undefined1 *)(param_1 + iVar7 + 0x1240) = uVar8;
          if ((0xfff < uVar15) && (iVar7 = FUN_00997904(), iVar7 == 0)) goto LAB_00998168;
          if (pbVar16 == &UNK_009a9741) break;
          cVar4 = *(char *)(param_1 + 0x2275);
        }
        if (iVar3 == 1) {
          iVar3 = FUN_009979b8(param_1,0xc0);
          if (((iVar3 != 0) && (iVar3 = FUN_00997a70(param_1,0x11), iVar3 != 0)) &&
             (*(char *)(param_1 + 0x2275) == '\x01')) {
            iVar3 = *(int *)(param_1 + 0x2270);
            uVar15 = iVar3 + 1;
            *(uint *)(param_1 + 0x2270) = uVar15;
            *(undefined1 *)(param_1 + iVar3 + 0x1240) = 8;
            if ((((uVar15 < 0x1000) || (iVar3 = FUN_00997904(param_1), iVar3 != 0)) &&
                ((iVar3 = FUN_00997a70(param_1,*(undefined4 *)(param_1 + 0x2254)), iVar3 != 0 &&
                 ((iVar3 = FUN_00997a70(param_1,*(undefined4 *)(param_1 + 0x2250)), iVar3 != 0 &&
                  (*(char *)(param_1 + 0x2275) == '\x01')))))) &&
               (iVar3 = FUN_00997988(param_1,3), iVar3 != 0)) {
              uVar15 = 0;
              goto LAB_009983bc;
            }
          }
          break;
        }
        iVar3 = 1;
      }
    }
  }
  goto LAB_00998168;
  while (uVar15 = uVar17, uVar17 != 3) {
LAB_009983bc:
    uVar17 = uVar15 + 1;
    if (((((*(char *)(param_1 + 0x2275) != '\x01') ||
          (iVar3 = FUN_00997988(param_1,uVar17 & 0xff), iVar3 == 0)) ||
         (*(char *)(param_1 + 0x2275) != '\x01')) ||
        ((iVar3 = FUN_00997988(param_1,0x11), iVar3 == 0 || (*(char *)(param_1 + 0x2275) != '\x01'))
        )) || (iVar3 = FUN_00997988(param_1,uVar15 != 0), iVar3 == 0)) goto LAB_00998168;
  }
  iVar3 = 0;
  while( true ) {
    iVar7 = FUN_00997c4c(param_1,iVar3,local_38,&DAT_009a9616,0xc);
    if ((iVar7 == 0) ||
       (iVar7 = FUN_00997c4c(param_1,iVar3 + 0x10,puVar10,&DAT_009a94b2 + (-iVar3 & 0xa2),0xa2),
       iVar7 == 0)) goto LAB_00998168;
    local_38 = local_38 + 0x10;
    puVar10 = puVar10 + 0x10;
    if (iVar3 == 1) break;
    iVar3 = 1;
  }
  iVar3 = FUN_009979b8(param_1,0xda);
  if ((((iVar3 != 0) && (iVar3 = FUN_00997a70(param_1,0xc), iVar3 != 0)) &&
      (*(char *)(param_1 + 0x2275) == '\x01')) && (iVar3 = FUN_00997988(param_1,3), iVar3 != 0)) {
    uVar15 = 0;
    goto LAB_009984f8;
  }
  goto LAB_00998168;
  while( true ) {
    if (uVar15 == 0) {
      uVar2 = 0;
    }
    else {
      uVar2 = 0x11;
    }
    if ((*(char *)(param_1 + 0x2275) != '\x01') || (iVar3 = FUN_00997988(param_1,uVar2), iVar3 == 0)
       ) goto LAB_00998168;
    uVar15 = uVar17;
    if (uVar17 == 3) break;
LAB_009984f8:
    uVar17 = uVar15 + 1;
    if ((*(char *)(param_1 + 0x2275) != '\x01') ||
       (iVar3 = FUN_00997988(param_1,uVar17 & 0xff), iVar3 == 0)) goto LAB_00998168;
  }
  if ((((*(char *)(param_1 + 0x2275) == '\x01') && (iVar3 = FUN_00997988(param_1,0), iVar3 != 0)) &&
      (*(char *)(param_1 + 0x2275) == '\x01')) &&
     (((iVar3 = FUN_00997988(param_1,0x3f), iVar3 != 0 && (*(char *)(param_1 + 0x2275) == '\x01'))
      && (iVar3 = FUN_00997988(param_1,0), iVar3 != 0)))) {
    return 0;
  }
LAB_00998168:
  return (int)*(char *)(param_1 + 0x2276);
}


// ===== FUN_00998648 @ 00998648

int FUN_00998648(int param_1,int param_2,uint param_3,uint param_4)

{
  uint uVar1;
  byte *pbVar2;
  short sVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  short sVar7;
  uint uVar8;
  int *piVar9;
  int iVar10;
  short *psVar11;
  short *psVar12;
  int *piVar13;
  uint uVar14;
  short *psVar15;
  int iVar16;
  uint uVar17;
  uint uVar18;
  uint *puVar19;
  int iVar20;
  byte *pbVar21;
  bool bVar22;
  bool bVar23;
  uint local_60;
  short *local_5c;
  int *local_58;
  
  if (param_1 == 0) {
    return -1;
  }
  if (*(char *)(param_1 + 0x2275) == '\x03') {
LAB_00998b00:
    return (int)*(char *)(param_1 + 0x2276);
  }
  if (*(char *)(param_1 + 0x2275) == '\x01') {
    if (*(uint *)(param_1 + 0x225c) < *(uint *)(param_1 + 0x2254)) {
      if (param_2 == 0) {
LAB_00998c5c:
        *(undefined1 *)(param_1 + 0x2275) = 3;
        *(undefined1 *)(param_1 + 0x2276) = 0xff;
        return -1;
      }
      uVar17 = *(int *)(param_1 + 0x2250) - *(int *)(param_1 + 0x2258);
      if (7 < uVar17) {
        uVar17 = 8;
      }
      uVar14 = uVar17 * 3;
      bVar23 = param_4 <= uVar14;
      bVar22 = uVar14 == param_4;
      if (!bVar23 || bVar22) {
        bVar23 = 0xfff < param_4;
        bVar22 = param_4 == 0x1000;
      }
      if (bVar23 && !bVar22) goto LAB_00998c5c;
      uVar4 = *(uint *)(param_1 + 0x2254) - *(uint *)(param_1 + 0x225c);
      if (7 < uVar4) {
        uVar4 = 8;
      }
      iVar20 = (uVar4 - 1) * param_4;
      if (param_3 < uVar14 + iVar20) goto LAB_00998c5c;
      local_5c = (short *)(param_1 + 0xd00);
      local_60 = 0;
      local_58 = (int *)0x0;
      do {
        uVar14 = 0;
        piVar9 = (int *)iVar20;
        if (local_60 < uVar4) {
          piVar9 = local_58;
        }
        psVar11 = local_5c;
        do {
          uVar1 = uVar17 - 1;
          if (uVar14 < uVar17) {
            uVar1 = uVar14;
          }
          iVar10 = uVar1 * 3 + (int)piVar9;
          uVar5 = (uint)*(byte *)(param_2 + iVar10);
          iVar10 = param_2 + iVar10;
          uVar18 = (uint)*(byte *)(iVar10 + 2);
          uVar1 = (uint)*(byte *)(iVar10 + 1);
          iVar10 = uVar5 * -0x2b33 + uVar1 * -0x54cd + uVar18 * 0x8000;
          uVar6 = iVar10 + 0x807fff;
          if (-1 < iVar10) {
            uVar6 = iVar10 + 0x808000;
          }
          sVar3 = (short)(uVar6 >> 0x10);
          iVar10 = uVar1 * -0x6b2f + uVar5 * 0x8000 + uVar18 * -0x14d1;
          uVar8 = iVar10 + 0x807fff;
          if (0xfe < uVar6 >> 0x10) {
            sVar3 = 0xff;
          }
          if (-1 < iVar10) {
            uVar8 = iVar10 + 0x808000;
          }
          sVar7 = (short)(uVar8 >> 0x10);
          if (0xfe < uVar8 >> 0x10) {
            sVar7 = 0xff;
          }
          uVar14 = uVar14 + 1;
          *psVar11 = (short)(uVar1 * 0x9646 + uVar5 * 0x4c8b + uVar18 * 0x1d2f + 0x8000 >> 0x10) +
                     -0x80;
          psVar11[0x40] = sVar3 + -0x80;
          psVar11[0x80] = sVar7 + -0x80;
          psVar11 = psVar11 + 1;
        } while (uVar14 != 8);
        local_60 = local_60 + 1;
        local_5c = local_5c + 8;
        local_58 = (int *)((int)local_58 + param_4);
      } while (local_60 != 8);
      local_60 = 0;
      local_58 = (int *)(param_1 + 0x225c);
      psVar11 = (short *)(param_1 + 0xc80);
      psVar15 = (short *)(param_1 + 0xd7e);
      while( true ) {
        piVar13 = (int *)(param_1 + 0xe7c);
        uVar17 = (uint)(local_60 != 0);
        psVar12 = psVar15 + -0x40;
        piVar9 = piVar13;
        do {
          psVar12 = psVar12 + 1;
          piVar9 = piVar9 + 1;
          *piVar9 = (int)*psVar12;
        } while (psVar15 != psVar12);
        iVar20 = param_1 + 0xe80;
        do {
          iVar16 = iVar20 + 0x20;
          FUN_0099769c(iVar20,1,0);
          iVar10 = param_1 + 0xe80;
          iVar20 = iVar16;
        } while (iVar16 != param_1 + 0xf80);
        do {
          iVar20 = iVar10 + 4;
          FUN_0099769c(iVar10,8,1);
          iVar10 = iVar20;
        } while (iVar20 != param_1 + 0xea0);
        uVar4 = 0;
        uVar14 = 0;
        pbVar21 = (byte *)0x9a96c2;
        pbVar2 = (byte *)(param_1 + 0xbff + uVar17 * 0x40);
        puVar19 = (uint *)((int *)(param_1 + 0xf7c) + uVar17 * 0x40);
        while( true ) {
          piVar13 = piVar13 + 1;
          iVar20 = *piVar13;
          pbVar2 = pbVar2 + 1;
          puVar19 = puVar19 + 1;
          if (iVar20 < 0) {
            iVar10 = (int)((ulonglong)*puVar19 * (ulonglong)((uint)*pbVar2 * 4 - iVar20) >> 0x20);
            iVar20 = -iVar10;
          }
          else {
            iVar20 = (int)((ulonglong)*puVar19 * (ulonglong)(iVar20 + (uint)*pbVar2 * 4) >> 0x20);
            iVar10 = iVar20;
          }
          if (iVar10 != 0 && uVar14 < uVar4) {
            uVar14 = uVar4;
          }
          *(short *)(param_1 + (uVar4 + 0x640) * 2) = (short)iVar20;
          if (piVar13 == (int *)(param_1 + 0xf7c)) break;
          pbVar21 = pbVar21 + 1;
          uVar4 = (uint)*pbVar21;
        }
        uVar4 = (int)*psVar11 - local_58[1];
        if (uVar4 != 0) break;
        uVar1 = (uint)*(byte *)(param_1 + (uVar17 + 8) * 0x100);
        if (uVar1 == 0) goto LAB_009989d8;
        uVar5 = (uint)*(ushort *)(param_1 + uVar17 * 0x200);
LAB_00998a18:
        iVar20 = FUN_00997b2c(param_1,uVar5,uVar1);
        if (iVar20 == 0) goto LAB_00998b00;
        local_58 = local_58 + 1;
        *local_58 = (int)*psVar11;
        if (uVar14 == 0) {
LAB_00998ad0:
          if (*(char *)(param_1 + (uVar17 + 10) * 0x100) == '\0') goto LAB_009989d8;
          iVar20 = FUN_00997b2c(param_1,*(undefined2 *)(param_1 + (uVar17 + 2) * 0x200));
          if (iVar20 == 0) goto LAB_00998b00;
        }
        else {
          uVar4 = 0;
          psVar12 = psVar11;
          do {
            psVar12 = psVar12 + 1;
            uVar1 = (uint)*psVar12;
            if (uVar1 == 0) {
              uVar4 = uVar4 + 1;
            }
            else {
              iVar20 = LZCOUNT((uVar1 ^ (int)uVar1 >> 0x1f) - ((int)uVar1 >> 0x1f) & 0xffff);
              if (10 < iVar20 - 0x16U) goto LAB_009989d8;
              iVar10 = (uVar17 + 2) * 0x100;
              if (0xf < uVar4) {
                do {
                  if (*(char *)(param_1 + iVar10 + 0x8f0) == '\0') goto LAB_009989d8;
                  iVar16 = FUN_00997b2c(param_1,*(undefined2 *)
                                                 (param_1 + (uVar17 + 2) * 0x200 + 0x1e0));
                  uVar4 = uVar4 - 0x10;
                  if (iVar16 == 0) goto LAB_00998b00;
                } while (0xf < uVar4);
              }
              uVar5 = 0x20 - iVar20;
              uVar4 = uVar5 | uVar4 << 4;
              if (*(char *)(param_1 + iVar10 + uVar4 + 0x800) == '\0') goto LAB_009989d8;
              iVar20 = FUN_00997b2c(param_1,*(undefined2 *)(param_1 + (iVar10 + uVar4) * 2));
              if (iVar20 == 0) goto LAB_00998b00;
              uVar4 = (uVar1 - 1) + (1 << (uVar5 & 0xff));
              if (-1 < (int)uVar1) {
                uVar4 = uVar1;
              }
              iVar20 = FUN_00997b2c(param_1,uVar4);
              if (iVar20 == 0) goto LAB_00998b00;
              uVar4 = 0;
            }
          } while (psVar11 + uVar14 != psVar12);
          if (uVar14 != 0x3f) goto LAB_00998ad0;
        }
        psVar15 = psVar15 + 0x40;
        local_60 = local_60 + 1;
        if (local_60 == 3) {
          uVar17 = *(int *)(param_1 + 0x2258) + 8;
          if (uVar17 < *(uint *)(param_1 + 0x2250)) {
            *(uint *)(param_1 + 0x2258) = uVar17;
          }
          else {
            *(undefined4 *)(param_1 + 0x2258) = 0;
            *(int *)(param_1 + 0x225c) = *(int *)(param_1 + 0x225c) + 8;
          }
          return 0;
        }
      }
      iVar20 = LZCOUNT((uVar4 ^ (int)uVar4 >> 0x1f) - ((int)uVar4 >> 0x1f));
      if ((iVar20 - 0x15U < 0xc) &&
         (uVar1 = 0x20 - iVar20, *(char *)(param_1 + uVar17 * 0x100 + uVar1 + 0x800) != '\0')) {
        iVar20 = FUN_00997b2c(param_1,*(undefined2 *)(param_1 + (uVar1 + uVar17 * 0x100) * 2));
        if (iVar20 != 0) {
          uVar5 = (uVar4 - 1) + (1 << (uVar1 & 0xff));
          if (-1 < (int)uVar4) {
            uVar5 = uVar4;
          }
          goto LAB_00998a18;
        }
        goto LAB_00998b00;
      }
LAB_009989d8:
      iVar20 = -5;
      goto LAB_009989dc;
    }
  }
  iVar20 = -2;
LAB_009989dc:
  *(undefined1 *)(param_1 + 0x2275) = 3;
  *(char *)(param_1 + 0x2276) = (char)iVar20;
  return iVar20;
}


// ===== FUN_00998c8c @ 00998c8c

int FUN_00998c8c(int param_1)

{
  int iVar1;
  uint uVar2;
  
  if (param_1 == 0) {
    return -1;
  }
  if (*(char *)(param_1 + 0x2275) != '\x03') {
    if ((*(char *)(param_1 + 0x2275) != '\x01') ||
       (*(uint *)(param_1 + 0x225c) < *(uint *)(param_1 + 0x2254))) {
      *(undefined1 *)(param_1 + 0x2275) = 3;
      *(undefined1 *)(param_1 + 0x2276) = 0xfe;
      return -2;
    }
    if (((*(char *)(param_1 + 0x2274) == '\0') || (*(char *)(param_1 + 0x2274) == '\b')) ||
       ((iVar1 = FUN_00997b2c(param_1,0x7f), iVar1 != 0 && (*(char *)(param_1 + 0x2275) == '\x01')))
       ) {
      iVar1 = *(int *)(param_1 + 0x2270);
      uVar2 = iVar1 + 1;
      *(uint *)(param_1 + 0x2270) = uVar2;
      *(undefined1 *)(param_1 + iVar1 + 0x1240) = 0xff;
      if (0xfff < uVar2) {
        iVar1 = FUN_00997904(param_1);
        if ((iVar1 == 0) || (*(char *)(param_1 + 0x2275) != '\x01')) goto LAB_00998cfc;
        uVar2 = *(uint *)(param_1 + 0x2270);
      }
      *(uint *)(param_1 + 0x2270) = uVar2 + 1;
      *(undefined1 *)(param_1 + uVar2 + 0x1240) = 0xd9;
      if (((uVar2 + 1 < 0x1000) || (iVar1 = FUN_00997904(param_1), iVar1 != 0)) &&
         (iVar1 = FUN_00997904(param_1), iVar1 != 0)) {
        *(undefined1 *)(param_1 + 0x2275) = 2;
        return 0;
      }
    }
  }
LAB_00998cfc:
  return (int)*(char *)(param_1 + 0x2276);
}


// ===== FUN_00998de4 @ 00998de4

void FUN_00998de4(int param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  uVar1 = *(uint *)(param_1 + 0x28);
  uVar3 = (-0x500 - param_2) + *(int *)(param_1 + 0x3c);
  if (uVar3 < uVar1) {
  }
  else {
    uVar3 = uVar1;
  }
  if (uVar3 != 0) {
    if (*(int *)(param_1 + 0x2c) != 0) goto LAB_00998e28;
    iVar2 = (**(code **)(param_1 + 0x30))
                      (*(undefined4 *)(param_1 + 0x34),*(int *)(param_1 + 0x38) + param_2);
    if (iVar2 != 0) {
      uVar1 = *(uint *)(param_1 + 0x28);
      *(undefined4 *)(param_1 + 0x2c) = 1;
      goto LAB_00998e28;
    }
    uVar1 = *(uint *)(param_1 + 0x28);
  }
  if (*(int *)(param_1 + 0x2c) == 0) {
    param_2 = param_2 + uVar3;
    uVar1 = uVar1 - uVar3;
  }
LAB_00998e28:
  *(uint *)(param_1 + 0x28) = uVar1;
  iVar2 = param_2;
  do {
    *(undefined1 *)(*(int *)(param_1 + 0x38) + iVar2) = 0;
    iVar2 = iVar2 + 1;
  } while (param_2 + 0x500 != iVar2);
  *(int *)(param_1 + 4) = *(int *)(param_1 + 0x38) + param_2;
  return;
}


// ===== FUN_00998eb0 @ 00998eb0

void FUN_00998eb0(int *param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  uint uVar6;
  
  iVar3 = *param_1;
  uVar2 = param_1[1] - iVar3;
  if (0x4ff < uVar2) {
    return;
  }
  if (param_1[10] == 0) {
    return;
  }
  if (param_1[0xb] != 0) {
    return;
  }
  if (uVar2 == 0) {
    *param_1 = param_1[0xe];
  }
  else {
    puVar4 = (undefined1 *)(iVar3 + -1);
    do {
      puVar5 = puVar4 + 1;
      puVar4[param_1[0xe] + (1 - iVar3)] = *puVar5;
      puVar4 = puVar5;
    } while (puVar5 != (undefined1 *)(iVar3 + -1) + uVar2);
    *param_1 = param_1[0xe];
  }
  uVar1 = param_1[10];
  uVar6 = (-0x500 - uVar2) + param_1[0xf];
  if (uVar6 < uVar1) {
  }
  else {
    uVar6 = uVar1;
  }
  if (uVar6 != 0) {
    if (param_1[0xb] != 0) goto LAB_00998e28;
    iVar3 = (*(code *)param_1[0xc])(param_1[0xd],param_1[0xe] + uVar2);
    if (iVar3 != 0) {
      uVar1 = param_1[10];
      param_1[0xb] = 1;
      goto LAB_00998e28;
    }
    uVar1 = param_1[10];
  }
  if (param_1[0xb] == 0) {
    uVar2 = uVar2 + uVar6;
    uVar1 = uVar1 - uVar6;
  }
LAB_00998e28:
  param_1[10] = uVar1;
  uVar6 = uVar2;
  do {
    *(undefined1 *)(param_1[0xe] + uVar6) = 0;
    uVar6 = uVar6 + 1;
  } while (uVar2 + 0x500 != uVar6);
  param_1[1] = param_1[0xe] + uVar2;
  return;
}


// ===== FUN_00998ee8 @ 00998ee8

void FUN_00998ee8(undefined4 *param_1,int param_2,int param_3,undefined1 *param_4)

{
  uint uVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  uint uVar5;
  
  puVar3 = param_4;
  do {
    puVar4 = puVar3 + 1;
    puVar3[param_1[0xe] + (1 - param_3)] = *puVar4;
    puVar3 = puVar4;
  } while (puVar4 != param_4 + param_2);
  *param_1 = param_1[0xe];
  uVar1 = param_1[10];
  uVar5 = (-0x500 - param_2) + param_1[0xf];
  if (uVar5 < uVar1) {
  }
  else {
    uVar5 = uVar1;
  }
  if (uVar5 != 0) {
    if (param_1[0xb] != 0) goto LAB_00998e28;
    iVar2 = (*(code *)param_1[0xc])(param_1[0xd],param_1[0xe] + param_2);
    if (iVar2 != 0) {
      uVar1 = param_1[10];
      param_1[0xb] = 1;
      goto LAB_00998e28;
    }
    uVar1 = param_1[10];
  }
  if (param_1[0xb] == 0) {
    param_2 = param_2 + uVar5;
    uVar1 = uVar1 - uVar5;
  }
LAB_00998e28:
  param_1[10] = uVar1;
  iVar2 = param_2;
  do {
    *(undefined1 *)(param_1[0xe] + iVar2) = 0;
    iVar2 = iVar2 + 1;
  } while (param_2 + 0x500 != iVar2);
  param_1[1] = param_1[0xe] + param_2;
  return;
}


// ===== FUN_00998f28 @ 00998f28

int FUN_00998f28(undefined4 *param_1,uint param_2)

{
  ushort uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  
  uVar3 = param_2 & 0xf;
  uVar2 = param_2 >> 4;
  if (param_2 < 0x100000) {
    uVar1 = *(ushort *)*param_1;
    *param_1 = (ushort *)*param_1 + 1;
    uVar2 = (uint)uVar1 | uVar2 << 0x10;
  }
  if (uVar3 == 0) {
    iVar4 = 0x28;
  }
  else {
    uVar5 = uVar2 & ~(-1 << uVar3);
    uVar2 = uVar2 >> uVar3;
    iVar4 = uVar5 + (1 << uVar3) + 0x27;
    if (uVar2 < 0x10000) {
      uVar1 = *(ushort *)*param_1;
      *param_1 = (ushort *)*param_1 + 1;
      uVar2 = (uint)uVar1 | uVar2 << 0x10;
    }
  }
  param_1[2] = uVar2;
  return iVar4;
}


// ===== FUN_00998f98 @ 00998f98

undefined4
FUN_00998f98(undefined4 *param_1,uint param_2,undefined4 param_3,undefined4 param_4,char *param_5,
            uint param_6)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  ushort *puVar6;
  uint uVar7;
  uint uVar8;
  char *pcVar9;
  undefined2 *puVar10;
  undefined1 *puVar11;
  int iVar12;
  uint uVar13;
  uint uVar14;
  undefined1 *puVar15;
  char *pcVar16;
  byte *pbVar17;
  uint uVar18;
  uint uVar19;
  undefined2 *puVar20;
  int iVar21;
  uint uVar22;
  undefined1 *local_54;
  undefined2 *local_50;
  
  param_1[0xc] = param_3;
  param_1[0xd] = param_4;
  param_1[0xf] = param_6 & 0xfffffffc;
  param_1[0xe] = param_5;
  param_1[0xb] = 0;
  if (0x17 < param_2) {
    uVar7 = param_2 & 1;
    if ((param_6 & 0xfffffffc) < 0x1500) {
      uVar7 = 1;
    }
    if (uVar7 == 0) {
      param_1[10] = param_2;
      *param_1 = param_5;
      FUN_00998de4(param_1,0);
      if (param_1[0xb] != 0) {
        return 0xfffffffe;
      }
      if ((((*param_5 == 'L') && (param_5[1] == 'T')) && (param_5[2] == 'Z')) && (param_5[3] == '1')
         ) {
        bVar1 = param_5[4];
        param_1[3] = (uint)bVar1;
        bVar2 = param_5[5];
        uVar7 = bVar2 & 0xffffffea;
        if ((((bVar2 & 0xea) == 0) &&
            (param_1[4] = bVar2 & 1 | (uint)(bVar2 >> 4) << 2 | bVar2 >> 1 & 2, bVar1 - 2 < 0x40))
           && ((param_5[6] == '\n' && (param_5[7] == '\n')))) {
          iVar4 = 0;
          param_1[7] = *(undefined4 *)(param_5 + 8);
          uVar18 = param_1[1] - (int)param_5;
          param_1[8] = *(undefined4 *)(param_5 + 0xc);
          uVar14 = *(uint *)(param_5 + 0x10);
          iVar21 = 0;
          uVar19 = 0x14;
          puVar15 = (undefined1 *)((int)param_1 + 0xa57);
          puVar20 = (undefined2 *)((int)param_1 + 0x3e);
          do {
            iVar21 = iVar21 + 1;
            iVar12 = iVar4;
            local_54 = puVar15;
            local_50 = puVar20;
            do {
              if (uVar18 <= uVar19) {
                return 0xffffffff;
              }
              uVar22 = (uint)(byte)param_5[uVar19];
              uVar8 = uVar22 - 1;
              if (0x28 < uVar8) {
                return 0xffffffff;
              }
              uVar13 = uVar19 + 1;
              if (uVar18 < uVar13 + uVar22 * 2) {
                return 0xffffffff;
              }
              iVar5 = 0;
              pcVar9 = param_5 + uVar19;
              pcVar16 = pcVar9 + uVar22 * 2;
              puVar10 = local_50;
              do {
                puVar10 = puVar10 + 1;
                *puVar10 = (short)iVar5;
                puVar6 = (ushort *)(pcVar9 + 1);
                pcVar9 = pcVar9 + 2;
                iVar5 = iVar5 + (uint)*puVar6;
              } while (pcVar16 != pcVar9);
              if (iVar5 != 0x400) {
                return 0xffffffff;
              }
              puVar10 = (undefined2 *)((int)param_1 + 0x3e) + uVar22 + iVar12;
              uVar19 = uVar19 + 3 + uVar8 * 2;
              do {
                puVar10 = puVar10 + 1;
                *puVar10 = 0x400;
              } while (puVar10 != (undefined2 *)((int)param_1 + iVar12 * 2 + 0x92));
              uVar22 = 0;
              iVar5 = 0;
              puVar11 = local_54;
              do {
                puVar6 = (ushort *)((int)param_1 + iVar5 * 2 + iVar12 * 2 + 0x40);
                iVar3 = iVar5;
                do {
                  iVar5 = iVar3;
                  puVar6 = puVar6 + 1;
                  iVar3 = iVar5 + 1;
                } while (*puVar6 <= uVar22);
                uVar22 = uVar22 + 0x10;
                puVar11 = puVar11 + 1;
                *puVar11 = (char)iVar5;
              } while (uVar22 != 0x400);
              iVar12 = iVar12 + 0x2a;
              local_54 = local_54 + 0x40;
              local_50 = local_50 + 0x2a;
            } while (iVar12 != iVar21 * 0x1a4);
            iVar4 = iVar4 + 0x1a4;
            puVar15 = puVar15 + 0x280;
            puVar20 = puVar20 + 0x1a4;
          } while (iVar21 != 3);
          if (uVar14 + uVar19 == param_2) {
            uVar22 = uVar13 & 1;
            if (uVar14 < 4) {
              uVar22 = 1;
            }
            if ((uVar22 == 0) && (uVar14 = uVar13 + uVar8 * 2 + 6, uVar14 <= uVar18)) {
              param_1[2] = *(undefined4 *)(param_5 + uVar19);
              *param_1 = param_5 + uVar14;
              puVar15 = (undefined1 *)((int)param_1 + 0xa17);
              uVar14 = 0;
              do {
                if (uVar7 < 9) {
                  pbVar17 = &DAT_009a975c + uVar7;
                  do {
                    bVar1 = *pbVar17;
                    pbVar17 = pbVar17 + 1;
                    if (uVar14 < bVar1) break;
                    uVar7 = uVar7 + 1;
                  } while (uVar7 != 9);
                }
                uVar14 = uVar14 + 1;
                puVar15 = puVar15 + 1;
                *puVar15 = (char)uVar7;
                if (uVar14 == 0x40) {
                  param_1[6] = 0;
                  param_1[5] = 0;
                  param_1[9] = 0;
                  return 0;
                }
              } while( true );
            }
          }
        }
      }
    }
  }
  return 0xffffffff;
}


// ===== FUN_00998f9c @ 00998f9c

undefined4
FUN_00998f9c(undefined4 *param_1,uint param_2,undefined4 param_3,undefined4 param_4,char *param_5,
            uint param_6)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  ushort *puVar6;
  uint uVar7;
  uint uVar8;
  char *pcVar9;
  undefined2 *puVar10;
  undefined1 *puVar11;
  int iVar12;
  uint uVar13;
  uint uVar14;
  undefined1 *puVar15;
  char *pcVar16;
  byte *pbVar17;
  uint uVar18;
  uint uVar19;
  uint in_r12;
  undefined2 *puVar20;
  int iVar21;
  uint uVar22;
  undefined1 *local_54;
  undefined2 *local_50;
  
  param_1[0xc] = param_3;
  param_1[0xd] = param_4;
  param_1[0xf] = param_6 & 0xfffffffc;
  param_1[0xe] = param_5;
  param_1[0xb] = in_r12;
  if (0x17 < param_2) {
    uVar7 = param_2 & 1;
    if ((param_6 & 0xfffffffc) < 0x1500) {
      uVar7 = 1;
    }
    if (uVar7 == in_r12) {
      param_1[10] = param_2;
      *param_1 = param_5;
      FUN_00998de4(param_1,uVar7);
      if (param_1[0xb] != 0) {
        return 0xfffffffe;
      }
      if ((((*param_5 == 'L') && (param_5[1] == 'T')) && (param_5[2] == 'Z')) && (param_5[3] == '1')
         ) {
        bVar1 = param_5[4];
        param_1[3] = (uint)bVar1;
        bVar2 = param_5[5];
        uVar7 = bVar2 & 0xffffffea;
        if ((((bVar2 & 0xea) == 0) &&
            (param_1[4] = bVar2 & 1 | (uint)(bVar2 >> 4) << 2 | bVar2 >> 1 & 2, bVar1 - 2 < 0x40))
           && ((param_5[6] == '\n' && (param_5[7] == '\n')))) {
          iVar4 = 0;
          param_1[7] = *(undefined4 *)(param_5 + 8);
          uVar18 = param_1[1] - (int)param_5;
          param_1[8] = *(undefined4 *)(param_5 + 0xc);
          uVar14 = *(uint *)(param_5 + 0x10);
          iVar21 = 0;
          uVar19 = 0x14;
          puVar15 = (undefined1 *)((int)param_1 + 0xa57);
          puVar20 = (undefined2 *)((int)param_1 + 0x3e);
          do {
            iVar21 = iVar21 + 1;
            iVar12 = iVar4;
            local_54 = puVar15;
            local_50 = puVar20;
            do {
              if (uVar18 <= uVar19) {
                return 0xffffffff;
              }
              uVar22 = (uint)(byte)param_5[uVar19];
              uVar8 = uVar22 - 1;
              if (0x28 < uVar8) {
                return 0xffffffff;
              }
              uVar13 = uVar19 + 1;
              if (uVar18 < uVar13 + uVar22 * 2) {
                return 0xffffffff;
              }
              iVar5 = 0;
              pcVar9 = param_5 + uVar19;
              pcVar16 = pcVar9 + uVar22 * 2;
              puVar10 = local_50;
              do {
                puVar10 = puVar10 + 1;
                *puVar10 = (short)iVar5;
                puVar6 = (ushort *)(pcVar9 + 1);
                pcVar9 = pcVar9 + 2;
                iVar5 = iVar5 + (uint)*puVar6;
              } while (pcVar16 != pcVar9);
              if (iVar5 != 0x400) {
                return 0xffffffff;
              }
              puVar10 = (undefined2 *)((int)param_1 + 0x3e) + uVar22 + iVar12;
              uVar19 = uVar19 + 3 + uVar8 * 2;
              do {
                puVar10 = puVar10 + 1;
                *puVar10 = 0x400;
              } while (puVar10 != (undefined2 *)((int)param_1 + iVar12 * 2 + 0x92));
              uVar22 = 0;
              iVar5 = 0;
              puVar11 = local_54;
              do {
                puVar6 = (ushort *)((int)param_1 + iVar5 * 2 + iVar12 * 2 + 0x40);
                iVar3 = iVar5;
                do {
                  iVar5 = iVar3;
                  puVar6 = puVar6 + 1;
                  iVar3 = iVar5 + 1;
                } while (*puVar6 <= uVar22);
                uVar22 = uVar22 + 0x10;
                puVar11 = puVar11 + 1;
                *puVar11 = (char)iVar5;
              } while (uVar22 != 0x400);
              iVar12 = iVar12 + 0x2a;
              local_54 = local_54 + 0x40;
              local_50 = local_50 + 0x2a;
            } while (iVar12 != iVar21 * 0x1a4);
            iVar4 = iVar4 + 0x1a4;
            puVar15 = puVar15 + 0x280;
            puVar20 = puVar20 + 0x1a4;
          } while (iVar21 != 3);
          if (uVar14 + uVar19 == param_2) {
            uVar22 = uVar13 & 1;
            if (uVar14 < 4) {
              uVar22 = 1;
            }
            if ((uVar22 == 0) && (uVar14 = uVar13 + uVar8 * 2 + 6, uVar14 <= uVar18)) {
              param_1[2] = *(undefined4 *)(param_5 + uVar19);
              *param_1 = param_5 + uVar14;
              puVar15 = (undefined1 *)((int)param_1 + 0xa17);
              uVar14 = 0;
              do {
                if (uVar7 < 9) {
                  pbVar17 = &DAT_009a975c + uVar7;
                  do {
                    bVar1 = *pbVar17;
                    pbVar17 = pbVar17 + 1;
                    if (uVar14 < bVar1) break;
                    uVar7 = uVar7 + 1;
                  } while (uVar7 != 9);
                }
                uVar14 = uVar14 + 1;
                puVar15 = puVar15 + 1;
                *puVar15 = (char)uVar7;
                if (uVar14 == 0x40) {
                  param_1[6] = 0;
                  param_1[5] = 0;
                  param_1[9] = 0;
                  return 0;
                }
              } while( true );
            }
          }
        }
      }
    }
  }
  return 0xffffffff;
}


// ===== FUN_00999358 @ 00999358

void FUN_00999358(undefined4 *param_1,undefined4 *param_2,int param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  byte *pbVar5;
  uint uVar6;
  uint *puVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  undefined4 *puVar11;
  byte *pbVar12;
  byte *pbVar13;
  uint uVar14;
  ushort *puVar15;
  uint *puVar16;
  undefined4 *puVar17;
  int iVar18;
  byte *pbVar19;
  ushort *puVar20;
  ushort *puVar21;
  int iVar22;
  uint uVar23;
  int iVar24;
  uint *puVar25;
  byte *pbVar26;
  int iVar27;
  uint uVar28;
  uint uVar29;
  byte *pbVar30;
  uint uVar31;
  uint *puVar32;
  byte *pbVar33;
  byte *pbVar34;
  undefined1 *puVar35;
  int iVar36;
  byte *pbVar37;
  uint uVar38;
  int local_c4;
  byte *local_c0;
  byte *local_bc;
  byte *local_b8;
  uint *local_b4;
  uint *local_b0;
  uint local_ac;
  int local_a8;
  uint *local_a4;
  byte *local_a0;
  byte *local_9c;
  byte *local_98;
  int local_94;
  uint *local_90;
  uint *local_88;
  uint *local_54;
  int local_4c;
  int local_40;
  undefined4 *local_3c;
  
  local_94 = param_1[5];
  uVar8 = param_1[3];
  local_a8 = param_1[6];
  if (param_3 == 0) {
    if (uVar8 != 0) {
      FUN_00998eb0();
      local_88 = (uint *)((int)param_1 + 0x12a1);
      puVar11 = param_1 + 0x476;
      iVar36 = (int)local_88;
      if (uVar8 == 0xfffffffe) {
        do {
          iVar36 = iVar36 + 0x43;
        } while (iVar36 != (int)param_1 + 0x136a);
      }
      else {
        do {
          iVar36 = FUN_00997590(iVar36,0,uVar8 + 2);
          iVar36 = iVar36 + 0x43;
        } while (iVar36 != (int)param_1 + 0x136a);
      }
      uVar6 = 0;
      local_3c = (undefined4 *)0x0;
LAB_00999b88:
      puVar17 = param_2;
      *(undefined1 *)puVar11 = 0;
      *(undefined1 *)((int)puVar11 + 0x43) = 0;
      *(undefined1 *)((int)puVar11 + 0x86) = 0;
      puVar7 = puVar17 + -1;
      if (local_3c == (undefined4 *)0x0) {
        local_a0 = (byte *)local_3c;
      }
      else {
        local_a0 = (byte *)*local_3c;
      }
      local_a4 = (uint *)0x0;
      local_ac = 0;
      local_b8 = (byte *)0x0;
      puVar16 = local_3c + -1;
      do {
        uVar9 = 0;
        uVar28 = (int)local_b8 + 1;
        local_c4 = 0;
        pbVar13 = (byte *)((int)puVar11 + (int)local_b8);
        local_b4 = &DAT_009a9750;
        local_b0 = &DAT_009a9744;
        pbVar12 = (byte *)((int)local_88 + (int)local_b8);
        local_bc = (byte *)0x0;
        do {
          uVar14 = *local_b0;
          uVar10 = *local_b4;
          uVar3 = uVar14 & (uint)local_a4 >> (uVar10 & 0xff);
          uVar4 = uVar14 & (uint)local_a0 >> (uVar10 & 0xff);
          iVar36 = (uVar3 + uVar4) - (uVar14 & local_ac >> (uVar10 & 0xff));
          uVar23 = (uint)*pbVar13 + (uint)*pbVar12 + (uint)pbVar12[uVar28 - (int)local_b8] +
                   (uint)pbVar12[2];
          if (((uint)param_1[4] >> (uVar9 & 0xff) & 1) != 0) {
            iVar36 = (int)((uVar3 + iVar36 + uVar4) * 0x5556) >> 0x10;
          }
          if (uVar23 < 0x40) {
            iVar27 = (int)param_1 + uVar23;
          }
          else {
            iVar27 = (int)param_1 + 0x3f;
          }
          uVar3 = param_1[2] & 0x3ff;
          puVar15 = (ushort *)
                    ((int)param_1 + local_c4 + 0x40 + (uint)*(byte *)(iVar27 + 0xa18) * 0x54);
          puVar20 = puVar15;
          uVar23 = 0;
          do {
            uVar4 = uVar23;
            puVar20 = puVar20 + 1;
            uVar23 = uVar4 + 1;
          } while (*puVar20 <= uVar3);
          uVar23 = (uint)puVar15[uVar4];
          uVar3 = ((uint)param_1[2] >> 10) * (*puVar20 - uVar23) + (uVar3 - uVar23);
          if (uVar3 < 0x10000) {
            uVar3 = (uint)*(ushort *)*param_1 | uVar3 * 0x10000;
            *param_1 = (ushort *)*param_1 + 1;
          }
          if (uVar4 == 0x28) {
            uVar23 = uVar3 & 0xf;
            uVar3 = uVar3 >> 4;
            if (uVar3 < 0x10000) {
              uVar3 = (uint)*(ushort *)*param_1 | uVar3 << 0x10;
              *param_1 = (ushort *)*param_1 + 1;
            }
            if (uVar23 != 0) {
              uVar4 = (uVar3 & ~(-1 << uVar23)) + (1 << uVar23) + 0x27;
              uVar3 = uVar3 >> uVar23;
              uVar23 = 0;
              if ((uVar4 & 1) != 0) {
                uVar23 = 0xffffffff;
              }
              uVar23 = uVar23 ^ uVar4 >> 1;
              if (uVar3 < 0x10000) {
                uVar3 = (uint)*(ushort *)*param_1 | uVar3 << 0x10;
                *param_1 = (ushort *)*param_1 + 1;
              }
              goto LAB_00999d48;
            }
            uVar23 = 0x14;
            local_bc = (byte *)((uint)local_bc | (iVar36 + 0x14U & uVar14) << (uVar10 & 0xff));
          }
          else {
            uVar23 = 0;
            if ((uVar4 & 1) != 0) {
              uVar23 = 0xffffffff;
            }
            uVar23 = uVar23 ^ uVar4 >> 1;
LAB_00999d48:
            local_bc = (byte *)((uint)local_bc | (iVar36 + uVar23 & uVar14) << (uVar10 & 0xff));
            if ((int)uVar23 < 0) {
              uVar23 = -uVar23;
            }
          }
          if (0xfe < uVar23) {
            uVar23 = 0xff;
          }
          param_1[2] = uVar3;
          uVar9 = uVar9 + 1;
          local_c4 = local_c4 + 0x348;
          pbVar12 = pbVar12 + 0x43;
          pbVar13[uVar28 - (int)local_b8] = (byte)uVar23;
          pbVar13 = pbVar13 + 0x43;
          local_b4 = local_b4 + 1;
          local_b0 = local_b0 + 1;
        } while (uVar9 != 3);
        local_94 = local_94 + (int)local_bc;
        local_a8 = local_a8 + local_94;
        puVar7 = puVar7 + 1;
        *puVar7 = (uint)local_bc;
        if (uVar8 == uVar28) goto LAB_00999e9c;
        if (local_3c == (undefined4 *)0x0) {
          local_ac = 0;
          local_a0 = (byte *)local_3c;
        }
        else {
          local_a0 = (byte *)puVar16[2];
          local_ac = puVar16[1];
        }
        local_a4 = (uint *)local_bc;
        puVar16 = puVar16 + 1;
        local_b8 = (byte *)uVar28;
      } while( true );
    }
  }
  else if (uVar8 != 0) {
    uVar28 = 0;
    local_54 = param_2 + -1;
    uVar6 = param_1[4];
    iVar36 = uVar8 + 1;
    local_40 = param_3 + uVar8 * -4;
    local_4c = 0;
LAB_00999428:
    FUN_00998eb0(param_1);
    uVar9 = 0;
    if ((uVar28 & 1) != 0) {
      uVar9 = 0xffffffff;
    }
    uVar3 = 0;
    if ((~uVar28 & 1) != 0) {
      uVar3 = 0xffffffff;
    }
    uVar9 = uVar9 & 0xc9;
    uVar3 = uVar3 & 0xc9;
    pbVar12 = (byte *)((int)param_1 + uVar9 + 0x11d8);
    pbVar19 = (byte *)((int)param_1 + uVar9 + 0x121b);
    local_98 = (byte *)((int)param_1 + uVar3 + 0x11d8);
    pbVar13 = (byte *)((int)param_1 + uVar9 + 0x125e);
    local_9c = (byte *)((int)param_1 + uVar3 + 0x121b);
    local_a0 = (byte *)((int)param_1 + uVar3 + 0x125e);
    if (uVar28 == 0) {
      if (uVar8 != 0xfffffffe) {
        iVar27 = uVar8 + 2;
        FUN_00997590(local_98,0,iVar27);
        FUN_00997590(local_9c,0,iVar27);
        FUN_00997590(local_a0,0,iVar27);
      }
      iVar27 = 0;
      local_88 = (uint *)0x0;
    }
    else {
      local_88 = local_54 + (1 - uVar8);
      iVar27 = local_40;
    }
    *(undefined1 *)((int)param_1 + uVar9 + 0x125e) = 0;
    *(undefined1 *)((int)param_1 + uVar9 + 0x121b) = 0;
    *(undefined1 *)((int)param_1 + uVar9 + 0x11d8) = 0;
    iVar18 = 0;
    uVar9 = param_1[2];
    local_a4 = local_54;
    uVar3 = 0;
    puVar20 = (ushort *)*param_1;
    local_ac = 0;
    puVar7 = (uint *)0x0;
    local_c0 = pbVar13;
    local_bc = pbVar19;
    local_b8 = pbVar12;
    if (local_88 == (uint *)0x0) goto LAB_00999990;
    do {
      puVar16 = (uint *)local_88[iVar18];
      local_90 = (uint *)((uint)puVar16 >> 0x16);
      puVar25 = (uint *)((uint)puVar16 >> 0xb & 0x7ff);
      puVar32 = (uint *)((uint)puVar16 & 0x7ff);
      while( true ) {
        uVar23 = *(uint *)(param_3 + local_4c * 4 + iVar18 * 4);
        if (iVar27 == 0) {
          uVar10 = 0;
        }
        else {
          uVar10 = *(uint *)(iVar27 + iVar18 * 4);
        }
        if ((uVar6 & 1) == 0) {
          iVar24 = (int)puVar32 + ((uVar3 & 0x7ff) - ((uint)puVar7 & 0x7ff));
        }
        else {
          iVar24 = (int)((((((int)puVar32 + (uVar23 & 0x7ff) + (uVar3 & 0x7ff)) * 2 -
                           ((uint)puVar7 & 0x7ff)) - (local_ac & 0x7ff)) - (uVar10 & 0x7ff)) *
                        0x5556) >> 0x10;
        }
        pbVar33 = local_b8 + 1;
        pbVar37 = local_98 + 1;
        uVar14 = (uint)*local_b8 + (uint)*local_98 + (uint)*pbVar37 + (uint)local_98[2];
        if (0x3e < uVar14) {
          uVar14 = 0x3f;
        }
        uVar29 = (uint)*(byte *)((int)param_1 + uVar14 + 0xa18);
        uVar14 = uVar9 & 0x3ff;
        uVar4 = (uint)*(byte *)((int)param_1 + (uVar14 >> 4) + uVar29 * 0x40 + 0xa58);
        iVar22 = uVar29 * 0x54;
        iVar1 = iVar22 + 0x40;
        uVar29 = (uint)*(ushort *)((int)param_1 + (uVar4 + 1) * 2 + iVar1);
        iVar18 = iVar18 + 1;
        if (uVar14 < uVar29) {
          uVar38 = (uint)*(ushort *)((int)param_1 + uVar4 * 2 + iVar1);
        }
        else {
          puVar15 = (ushort *)((int)param_1 + uVar4 * 2 + iVar22 + 0x42);
          uVar38 = uVar29;
          uVar4 = uVar4 + 1;
          while( true ) {
            puVar15 = puVar15 + 1;
            uVar29 = (uint)*puVar15;
            if (uVar14 < uVar29) break;
            uVar4 = uVar4 + 1;
            uVar38 = uVar29;
          }
        }
        uVar9 = (uVar29 - uVar38) * (uVar9 >> 10) + (uVar14 - uVar38);
        puVar15 = puVar20;
        if (uVar9 < 0x10000) {
          puVar15 = puVar20 + 1;
          uVar9 = (uint)*puVar20 | uVar9 * 0x10000;
        }
        if (uVar4 == 0x28) {
          *param_1 = puVar15;
          uVar4 = FUN_00998f28();
          uVar9 = param_1[2];
          puVar15 = (ushort *)*param_1;
        }
        uVar14 = 0;
        if ((uVar4 & 1) != 0) {
          uVar14 = 0xffffffff;
        }
        uVar14 = uVar14 ^ uVar4 >> 1;
        uVar4 = iVar24 + uVar14;
        if ((int)uVar14 < 0) {
          uVar14 = -uVar14;
        }
        if (0xfe < uVar14) {
          uVar14 = 0xff;
        }
        uVar29 = uVar3 >> 0xb & 0x7ff;
        uVar38 = (uint)puVar7 >> 0xb & 0x7ff;
        *pbVar33 = (byte)uVar14;
        if ((uVar6 & 2) == 0) {
          iVar24 = (int)puVar25 + (uVar29 - uVar38);
        }
        else {
          iVar24 = (int)((((((int)(((int)puVar25 + (uVar23 >> 0xb & 0x7ff) + uVar29) * 0x10000) >>
                            0x10) * 2 - uVar38) - (local_ac >> 0xb & 0x7ff)) -
                         (uVar10 >> 0xb & 0x7ff)) * 0x5556) >> 0x10;
        }
        pbVar30 = local_bc + 1;
        pbVar5 = local_9c + 1;
        uVar14 = (uint)*local_bc + (uint)*local_9c + (uint)*pbVar5 + (uint)local_9c[2];
        if (0x3e < uVar14) {
          uVar14 = 0x3f;
        }
        uVar38 = (uint)*(byte *)((int)param_1 + uVar14 + 0xa18);
        uVar14 = uVar9 & 0x3ff;
        uVar29 = (uint)*(byte *)((int)param_1 + (uVar14 >> 4) + uVar38 * 0x40 + 0xcd8);
        iVar22 = uVar38 * 0x54;
        iVar1 = iVar22 + 0x388;
        uVar38 = (uint)*(ushort *)((int)param_1 + (uVar29 + 1) * 2 + iVar1);
        if (uVar14 < uVar38) {
          uVar31 = (uint)*(ushort *)((int)param_1 + uVar29 * 2 + iVar1);
        }
        else {
          puVar20 = (ushort *)((int)param_1 + uVar29 * 2 + iVar22 + 0x38a);
          uVar31 = uVar38;
          uVar29 = uVar29 + 1;
          while( true ) {
            puVar20 = puVar20 + 1;
            uVar38 = (uint)*puVar20;
            if (uVar14 < uVar38) break;
            uVar29 = uVar29 + 1;
            uVar31 = uVar38;
          }
        }
        uVar9 = (uVar38 - uVar31) * (uVar9 >> 10) + (uVar14 - uVar31);
        puVar21 = puVar15;
        if (uVar9 < 0x10000) {
          puVar21 = puVar15 + 1;
          uVar9 = (uint)*puVar15 | uVar9 * 0x10000;
        }
        if (uVar29 == 0x28) {
          *param_1 = puVar21;
          uVar29 = FUN_00998f28();
          uVar9 = param_1[2];
          puVar21 = (ushort *)*param_1;
        }
        uVar14 = 0;
        if ((uVar29 & 1) != 0) {
          uVar14 = 0xffffffff;
        }
        uVar14 = uVar14 ^ uVar29 >> 1;
        iVar24 = iVar24 + uVar14;
        if ((int)uVar14 < 0) {
          uVar14 = -uVar14;
        }
        if (0xfe < uVar14) {
          uVar14 = 0xff;
        }
        *pbVar30 = (byte)uVar14;
        if ((uVar6 & 4) == 0) {
          iVar22 = (int)local_90 + ((uVar3 >> 0x16) - ((uint)puVar7 >> 0x16));
        }
        else {
          iVar22 = (int)((((((int)local_90 + (uVar23 >> 0x16) + (uVar3 >> 0x16)) * 2 -
                           ((uint)puVar7 >> 0x16)) - (local_ac >> 0x16)) - (uVar10 >> 0x16)) *
                        0x5556) >> 0x10;
        }
        pbVar34 = local_c0 + 1;
        pbVar26 = local_a0 + 1;
        uVar3 = (uint)*local_c0 + (uint)*local_a0 + (uint)*pbVar26 + (uint)local_a0[2];
        if (0x3e < uVar3) {
          uVar3 = 0x3f;
        }
        uVar14 = (uint)*(byte *)((int)param_1 + uVar3 + 0xa18);
        uVar3 = uVar9 & 0x3ff;
        uVar10 = (uint)*(byte *)((int)param_1 + (uVar3 >> 4) + uVar14 * 0x40 + 0xf58);
        iVar1 = uVar14 * 0x54;
        iVar2 = iVar1 + 0x6d0;
        uVar14 = (uint)*(ushort *)((int)param_1 + (uVar10 + 1) * 2 + iVar2);
        if (uVar3 < uVar14) {
          uVar29 = (uint)*(ushort *)((int)param_1 + uVar10 * 2 + iVar2);
        }
        else {
          puVar20 = (ushort *)((int)param_1 + uVar10 * 2 + iVar1 + 0x6d2);
          uVar29 = uVar14;
          uVar10 = uVar10 + 1;
          while( true ) {
            puVar20 = puVar20 + 1;
            uVar14 = (uint)*puVar20;
            if (uVar3 < uVar14) break;
            uVar10 = uVar10 + 1;
            uVar29 = uVar14;
          }
        }
        uVar9 = (uVar14 - uVar29) * (uVar9 >> 10) + (uVar3 - uVar29);
        puVar20 = puVar21;
        if (uVar9 < 0x10000) {
          puVar20 = puVar21 + 1;
          uVar9 = (uint)*puVar21 | uVar9 * 0x10000;
        }
        if (uVar10 == 0x28) {
          *param_1 = puVar20;
          uVar10 = FUN_00998f28(param_1);
          uVar9 = param_1[2];
          puVar20 = (ushort *)*param_1;
        }
        uVar14 = 0;
        if ((uVar10 & 1) != 0) {
          uVar14 = 0xffffffff;
        }
        uVar14 = uVar14 ^ uVar10 >> 1;
        iVar22 = iVar22 + uVar14;
        if ((int)uVar14 < 0) {
          uVar14 = -uVar14;
        }
        if (0xfe < uVar14) {
          uVar14 = 0xff;
        }
        uVar3 = iVar24 * 0x800 & 0x3ff800U | uVar4 & 0x7ff | iVar22 * 0x400000;
        *pbVar34 = (byte)uVar14;
        local_94 = local_94 + uVar3;
        local_a8 = local_a8 + local_94;
        local_a4 = local_a4 + 1;
        *local_a4 = uVar3;
        if (pbVar34 == pbVar13 + uVar8) {
          uVar28 = uVar28 + 1;
          local_4c = local_4c + uVar8;
          pbVar13[iVar36] = 0;
          local_54 = local_54 + uVar8;
          local_40 = local_40 + uVar8 * 4;
          pbVar19[iVar36] = 0;
          pbVar12[iVar36] = 0;
          param_1[2] = uVar9;
          *param_1 = puVar20;
          if (uVar8 == uVar28) goto LAB_00999a68;
          goto LAB_00999428;
        }
        puVar7 = puVar16;
        local_c0 = pbVar34;
        local_bc = pbVar30;
        local_b8 = pbVar33;
        local_ac = uVar23;
        local_a0 = pbVar26;
        local_9c = pbVar5;
        local_98 = pbVar37;
        if (local_88 != (uint *)0x0) break;
LAB_00999990:
        local_90 = local_88;
        puVar16 = local_88;
        puVar25 = local_88;
        puVar32 = local_88;
      }
    } while( true );
  }
LAB_00999a68:
  param_1[5] = local_94;
  param_1[6] = local_a8;
  param_1[9] = param_1[9] + 1;
  return;
LAB_00999e9c:
  uVar6 = uVar6 + 1;
  puVar35 = (undefined1 *)((int)puVar11 + uVar8 + 1);
  *puVar35 = 0;
  puVar35[0x43] = 0;
  puVar35[0x86] = 0;
  if (uVar8 == uVar6) goto LAB_00999a68;
  FUN_00998eb0(param_1);
  uVar28 = 0;
  if ((~uVar6 & 1) != 0) {
    uVar28 = 0xffffffff;
  }
  uVar9 = 0;
  if ((uVar6 & 1) != 0) {
    uVar9 = 0xffffffff;
  }
  local_88 = (uint *)((int)param_1 + (uVar28 & 0xc9) + 0x11d8);
  puVar11 = (undefined4 *)((int)param_1 + (uVar9 & 0xc9) + 0x11d8);
  param_2 = puVar17 + uVar8;
  local_3c = puVar17;
  goto LAB_00999b88;
}


// ===== FUN_00999f44 @ 00999f44

undefined4 FUN_00999f44(int *param_1)

{
  undefined4 uVar1;
  
  if ((((param_1[0xb] != 0) || (param_1[10] != 0)) || (*param_1 != param_1[1])) ||
     (((param_1[2] != 0x10000 || (param_1[5] != param_1[7])) || (param_1[6] != param_1[8])))) {
    return 0xffffffff;
  }
  uVar1 = 0;
  if (param_1[9] != param_1[3]) {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}


// ===== FUN_00999fb0 @ 00999fb0

void FUN_00999fb0(int param_1,int param_2,int param_3,int param_4)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  uint *puVar4;
  uint *puVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  bool bVar10;
  
  if (param_3 == 0) {
    return;
  }
  puVar1 = (uint *)(param_1 + -4);
  puVar4 = (uint *)(param_2 + -4);
  puVar5 = puVar1 + param_3;
  do {
    puVar1 = puVar1 + 1;
    uVar2 = *puVar1;
    puVar4 = puVar4 + 1;
    uVar3 = *puVar4;
    iVar8 = param_4 * ((uVar3 & 0x7ff) - (uVar2 & 0x7ff));
    bVar10 = -1 < iVar8;
    if (bVar10) {
      iVar8 = iVar8 + 0x8000 >> 0x10;
    }
    else {
      iVar8 = 0x8000 - iVar8;
    }
    uVar6 = uVar2 >> 0xb & 0x7ff;
    if (!bVar10) {
      iVar8 = iVar8 >> 0x10;
    }
    if (!bVar10) {
      iVar8 = -iVar8;
    }
    iVar9 = param_4 * ((uVar3 >> 0xb & 0x7ff) - uVar6);
    bVar10 = iVar9 < 0;
    iVar7 = iVar9 + 0x8000;
    if (bVar10) {
      iVar9 = 0x8000 - iVar9 >> 0x10;
    }
    if (bVar10) {
      iVar7 = -iVar9;
    }
    else {
      iVar7 = iVar7 >> 0x10;
    }
    iVar9 = param_4 * ((uVar3 >> 0x16) - (uVar2 >> 0x16));
    if (iVar9 < 0) {
      iVar9 = -(0x8000 - iVar9 >> 0x10);
    }
    else {
      iVar9 = iVar9 + 0x8000 >> 0x10;
    }
    *puVar1 = iVar8 + (uVar2 & 0x7ff) | (iVar7 + uVar6) * 0x800 |
              (iVar9 + (uVar2 >> 0x16)) * 0x400000;
  } while (puVar1 != puVar5);
  return;
}


// ===== FUN_00999fb8 @ 00999fb8

void FUN_00999fb8(int param_1,int param_2,int param_3,int param_4)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  uint *puVar4;
  uint *puVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  bool bVar10;
  
  puVar1 = (uint *)(param_1 + -4);
  puVar4 = (uint *)(param_2 + -4);
  puVar5 = puVar1 + param_3;
  do {
    puVar1 = puVar1 + 1;
    uVar2 = *puVar1;
    puVar4 = puVar4 + 1;
    uVar3 = *puVar4;
    iVar8 = param_4 * ((uVar3 & 0x7ff) - (uVar2 & 0x7ff));
    bVar10 = -1 < iVar8;
    if (bVar10) {
      iVar8 = iVar8 + 0x8000 >> 0x10;
    }
    else {
      iVar8 = 0x8000 - iVar8;
    }
    uVar6 = uVar2 >> 0xb & 0x7ff;
    if (!bVar10) {
      iVar8 = iVar8 >> 0x10;
    }
    if (!bVar10) {
      iVar8 = -iVar8;
    }
    iVar9 = param_4 * ((uVar3 >> 0xb & 0x7ff) - uVar6);
    bVar10 = iVar9 < 0;
    iVar7 = iVar9 + 0x8000;
    if (bVar10) {
      iVar9 = 0x8000 - iVar9 >> 0x10;
    }
    if (bVar10) {
      iVar7 = -iVar9;
    }
    else {
      iVar7 = iVar7 >> 0x10;
    }
    iVar9 = param_4 * ((uVar3 >> 0x16) - (uVar2 >> 0x16));
    if (iVar9 < 0) {
      iVar9 = -(0x8000 - iVar9 >> 0x10);
    }
    else {
      iVar9 = iVar9 + 0x8000 >> 0x10;
    }
    *puVar1 = iVar8 + (uVar2 & 0x7ff) | (iVar7 + uVar6) * 0x800 |
              (iVar9 + (uVar2 >> 0x16)) * 0x400000;
  } while (puVar1 != puVar5);
  return;
}


// ===== FUN_0099a064 @ 0099a064

int FUN_0099a064(int param_1,int param_2,int param_3)

{
  int iVar1;
  
  iVar1 = (param_1 * 0x59 + param_2) * 2;
  if (param_3 == 0) {
    return (*(ushort *)(&DAT_009ae012 + iVar1) + 0x8000) * 0x40;
  }
  return (*(ushort *)(&DAT_009aa7c0 + iVar1) + 0x22000) * 0x20;
}


// ===== FUN_0099a0b0 @ 0099a0b0

int FUN_0099a0b0(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_1 << LZCOUNT(param_1);
  uVar2 = uVar1 >> 0x17 & 0xff;
  return *(int *)(&DAT_009b1864 + uVar2 * 4) +
         ((*(int *)(&DAT_009b1864 + (uVar2 + 1) * 4) - *(int *)(&DAT_009b1864 + uVar2 * 4)) *
          (uVar1 & 0x7fffff) + 0x400000 >> 0x17) + (0x1f - LZCOUNT(param_1)) * 0x10000;
}


// ===== FUN_0099a0f8 @ 0099a0f8

undefined4 FUN_0099a0f8(ushort *param_1,uint *param_2)

{
  int *piVar1;
  int *piVar2;
  ushort uVar3;
  ushort uVar4;
  longlong lVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  undefined4 *puVar18;
  uint *puVar19;
  int *piVar20;
  uint uVar21;
  uint uVar22;
  uint uVar23;
  uint *puVar24;
  uint uVar25;
  uint uVar26;
  uint *puVar27;
  bool bVar28;
  bool bVar29;
  bool bVar30;
  longlong lVar31;
  ulonglong uVar32;
  ulonglong uVar33;
  int *local_6c;
  uint *local_68;
  int local_64;
  int local_5c;
  uint local_50 [4];
  uint local_40 [5];
  uint local_2c;
  
  uVar3 = *param_1;
  if ((((uVar3 != 0) && (param_1[1] != 0)) && (param_1[2] != 0)) && (uVar4 = param_1[3], uVar4 != 0)
     ) {
    iVar6 = FUN_0099a0b0((uint)param_1[1] + (uint)param_1[2]);
    iVar7 = FUN_0099a0b0((uint)uVar3 << 1);
    iVar8 = FUN_0099a0b0((uint)uVar4 << 1);
    uVar16 = (iVar8 - iVar6) + 0x4000;
    uVar17 = (iVar7 - iVar6) + 0x8000;
    bVar30 = 0x27fff < uVar17;
    bVar28 = uVar17 == 0x28000;
    if (uVar17 < 0x28001) {
      bVar30 = 0x2bfff < uVar16;
      bVar28 = uVar16 == 0x2c000;
    }
    if (0x27fff < (int)uVar17) {
      uVar17 = 0x28000;
    }
    if (0x2bfff < (int)uVar16) {
      uVar16 = 0x2c000;
    }
    uVar17 = uVar17 & ~((int)uVar17 >> 0x1f);
    iVar6 = (int)uVar17 >> 0xb;
    uVar16 = uVar16 & ~((int)uVar16 >> 0x1f);
    iVar7 = (int)uVar16 >> 0xb;
    if (iVar6 == 0x50) {
      uVar17 = 0x800;
      iVar6 = 0x4f;
    }
    else {
      uVar17 = uVar17 & 0x7ff;
    }
    bVar29 = iVar7 == 0x58;
    if (bVar29) {
      uVar16 = 0x800;
      iVar7 = 0x57;
    }
    iVar8 = 0;
    if (!bVar29) {
      uVar16 = uVar16 & 0x7ff;
    }
    param_2[0x14] = (uint)(bVar30 && !bVar28);
    lVar31 = (longlong)(int)uVar16 * (longlong)(int)uVar17;
    while( true ) {
      local_5c = (int)lVar31;
      iVar9 = FUN_0099a064(iVar6,iVar7,iVar8,(int)((ulonglong)lVar31 >> 0x20));
      iVar10 = FUN_0099a064(iVar6 + 1,iVar7,iVar8);
      iVar11 = FUN_0099a064(iVar6,iVar7 + 1,iVar8);
      iVar12 = FUN_0099a064(iVar6 + 1,iVar7 + 1,iVar8);
      lVar5 = (longlong)local_5c * (longlong)iVar12 +
              (longlong)(int)(uVar16 * (0x800 - uVar17)) * (longlong)iVar11 +
              (longlong)(int)((0x800 - uVar17) * (0x800 - uVar16)) * (longlong)iVar9 +
              (longlong)iVar10 * (longlong)(int)(uVar17 * (0x800 - uVar16)) + 0x200000;
      iVar9 = (int)((ulonglong)lVar5 >> 0x20);
      lVar31 = CONCAT44(local_50,local_5c);
      local_50[iVar8 * 2] = (uint)lVar5 >> 0x16 | iVar9 * 0x400;
      local_50[iVar8 * 2 + 1] = iVar9 >> 0x16;
      if (iVar8 == 1) break;
      iVar8 = 1;
    }
    puVar18 = &DAT_009a97b0;
    *param_2 = local_50[0];
    param_2[2] = local_50[2];
    param_2[1] = local_50[1];
    param_2[3] = local_50[3];
    iVar6 = 1;
    uVar17 = 0;
    uVar16 = 0;
    while( true ) {
      uVar13 = puVar18[6];
      uVar14 = puVar18[9];
      uVar21 = puVar18[7];
      lVar31 = (ulonglong)uVar14 * (ulonglong)(uVar13 - local_50[0]);
      uVar15 = (uint)lVar31;
      uVar25 = puVar18[8];
      lVar5 = (ulonglong)uVar25 * (ulonglong)(local_50[2] - uVar21);
      uVar26 = (uint)lVar5;
      iVar7 = uVar14 * (((int)uVar13 >> 0x1f) - (local_50[1] + (uVar13 < local_50[0]))) +
              (uVar13 - local_50[0]) * ((int)uVar14 >> 0x1f) + (int)((ulonglong)lVar31 >> 0x20) +
              uVar25 * (local_50[3] - (((int)uVar21 >> 0x1f) + (uint)(local_50[2] < uVar21))) +
              (local_50[2] - uVar21) * ((int)uVar25 >> 0x1f) + (int)((ulonglong)lVar5 >> 0x20) +
              (uint)CARRY4(uVar15,uVar26);
      uVar14 = uVar15 + uVar26 >> 0x10 | iVar7 * 0x10000;
      uVar13 = iVar7 >> 0x10;
      if (iVar6 == 0x1e || (int)uVar13 < (int)(uint)(uVar14 == 0)) break;
      puVar18 = puVar18 + 5;
      iVar6 = iVar6 + 1;
      uVar17 = uVar14;
      uVar16 = uVar13;
    }
    if (iVar6 == 1) {
      lVar31 = 0;
    }
    else {
      if ((int)(uint)(uVar14 == 0) <= (int)uVar13) {
        uVar13 = 0;
        uVar14 = uVar13;
      }
      uVar15 = uVar17 - uVar14;
      uVar16 = uVar16 - (uVar13 + (uVar17 < uVar14));
      lVar31 = CONCAT44(uVar16,uVar15);
      if (uVar15 != 0 || uVar16 != 0) {
        uVar21 = (uVar13 + (uVar14 != 0)) * -0x10000 | -uVar14 >> 0x10;
        uVar17 = (int)uVar21 >> 0x1f;
        uVar14 = uVar17 ^ uVar14 * -0x10000;
        uVar25 = uVar14 - uVar17;
        uVar13 = uVar15 >> 1 | uVar16 * -0x80000000;
        lVar31 = FUN_009a69d8(uVar25 + uVar13,
                              ((uVar21 ^ uVar17) - (uVar17 + (uVar14 < uVar17))) + (uVar16 >> 1) +
                              (uint)CARRY4(uVar25,uVar13));
        if ((int)(uVar16 ^ uVar21) < 0) {
          lVar31 = CONCAT44(-((int)((ulonglong)lVar31 >> 0x20) + (uint)((int)lVar31 != 0)),
                            -(int)lVar31);
        }
      }
    }
    uVar16 = (&DAT_009a97b0)[iVar6 * 5];
    uVar17 = 0x10000 - (uint)lVar31;
    lVar5 = (ulonglong)uVar17 * (ulonglong)uVar16;
    lVar31 = lVar31 * (int)(&DAT_009a97b0)[(iVar6 + -1) * 5] +
             CONCAT44(uVar17 * ((int)uVar16 >> 0x1f) +
                      uVar16 * -((int)((ulonglong)lVar31 >> 0x20) + (uint)(0x10000 < (uint)lVar31))
                      + (int)((ulonglong)lVar5 >> 0x20),(int)lVar5);
    uVar17 = (uint)lVar31;
    uVar16 = (uint)((ulonglong)lVar31 >> 0x20);
    if ((int)(uint)(uVar17 == 0) <= (int)uVar16) {
      uVar13 = uVar17 >> 1 | uVar16 * -0x80000000;
      *(longlong *)(param_2 + 4) = lVar31;
      uVar13 = FUN_009a69d8(uVar13 + 0x42400000,(uVar16 >> 1) + 0xf + (uint)(0xbdbfffff < uVar13),
                            uVar17,uVar16);
      param_2[6] = uVar13;
      iVar6 = FUN_009a6904((int)(lVar31 + 0x4e200000),
                           (int)((ulonglong)(lVar31 + 0x4e200000) >> 0x20),uVar17 * 2,
                           uVar16 * 2 + (uint)CARRY4(uVar17,uVar17));
      param_2[7] = iVar6 * 100;
      uVar22 = local_50[1] * 0x3000000 + (int)((ulonglong)local_50[0] * 0x3000000 >> 0x20);
      uVar23 = local_50[3] * 2 + (uint)CARRY4(local_50[2],local_50[2]);
      uVar13 = (int)uVar23 >> 0x1f;
      uVar14 = local_50[2] * 2 ^ uVar13;
      uVar25 = uVar14 - uVar13;
      uVar26 = (uVar23 ^ uVar13) - (uVar13 + (uVar14 < uVar13));
      uVar21 = uVar25 >> 1 | uVar26 * -0x80000000;
      uVar13 = (int)uVar22 >> 0x1f;
      uVar14 = (uint)((ulonglong)local_50[0] * 0x3000000) ^ uVar13;
      uVar15 = uVar14 - uVar13;
      uVar32 = FUN_009a69d8(uVar15 + uVar21,
                            ((uVar22 ^ uVar13) - (uVar13 + (uVar14 < uVar13))) + (uVar26 >> 1) +
                            (uint)CARRY4(uVar15,uVar21));
      if ((int)(uVar22 ^ uVar23) < 0) {
        uVar32 = CONCAT44(-((int)(uVar32 >> 0x20) + (uint)((int)uVar32 != 0)),-(int)uVar32);
      }
      local_64 = (int)(uVar32 >> 0x20);
      uVar13 = (uint)((ulonglong)local_50[2] * 0xfffffff6);
      uVar14 = (0x4000000 - local_50[0]) + uVar13;
      uVar22 = ((((local_50[3] * -10 - local_50[2]) +
                 (int)((ulonglong)local_50[2] * 0xfffffff6 >> 0x20)) -
                (local_50[1] + (0x4000000 < local_50[0]))) +
               (uint)CARRY4(0x4000000 - local_50[0],uVar13)) * 0x1000000 | uVar14 >> 8;
      uVar13 = (int)uVar22 >> 0x1f;
      uVar14 = uVar13 ^ uVar14 * 0x1000000;
      uVar15 = uVar14 - uVar13;
      uVar33 = FUN_009a69d8(uVar15 + uVar21,
                            (uVar26 >> 1) + ((uVar13 ^ uVar22) - (uVar13 + (uVar14 < uVar13))) +
                            (uint)CARRY4(uVar15,uVar21),uVar25,uVar26);
      if ((int)(uVar23 ^ uVar22) < 0) {
        uVar33 = CONCAT44(-((int)(uVar33 >> 0x20) + (uint)((int)uVar33 != 0)),-(int)uVar33);
      }
      lVar31 = (uVar32 & 0xffffffff) * 0x66bacf;
      uVar13 = (uint)lVar31;
      lVar31 = uVar33 * -0xd2c8c +
               CONCAT44(local_64 * 0x66bacf + (int)((ulonglong)lVar31 >> 0x20) + 0xa671 +
                        (uint)(0x42ffffff < uVar13),uVar13 + 0xbd000000);
      uVar14 = (uint)((ulonglong)lVar31 >> 0x20);
      uVar13 = (int)uVar14 >> 0x1f;
      uVar15 = (uint)lVar31 ^ uVar13;
      uVar21 = uVar15 - uVar13;
      local_40[1] = ((uVar14 ^ uVar13) - (uVar13 + (uVar15 < uVar13))) + (uint)(0xff7fffff < uVar21)
      ;
      local_40[0] = uVar21 + 0x800000 >> 0x18 | local_40[1] * 0x100;
      local_40[1] = local_40[1] >> 0x18;
      if (lVar31 < 0) {
        bVar28 = local_40[0] != 0;
        local_40[0] = -local_40[0];
        local_40[1] = -(local_40[1] + bVar28);
      }
      lVar31 = uVar32 * -0x401190 + 0x134547a000000 + uVar33 * 0xbbd16;
      uVar21 = (uint)((ulonglong)lVar31 >> 0x20);
      uVar13 = (int)uVar21 >> 0x1f;
      uVar14 = (uint)lVar31 ^ uVar13;
      uVar15 = uVar14 - uVar13;
      local_40[3] = ((uVar21 ^ uVar13) - (uVar13 + (uVar14 < uVar13))) + (uint)(0xff7fffff < uVar15)
      ;
      local_40[2] = uVar15 + 0x800000 >> 0x18 | local_40[3] * 0x100;
      local_40[3] = local_40[3] >> 0x18;
      if (lVar31 < 0) {
        bVar28 = local_40[2] != 0;
        local_40[2] = -local_40[2];
        local_40[3] = -(local_40[3] + bVar28);
      }
      lVar31 = (uVar33 & 0xffffffff) * 0xf40022;
      lVar31 = uVar32 * -0x8840 + 0xc881e000000 +
               CONCAT44((int)(uVar33 >> 0x20) * 0xf40022 + (int)((ulonglong)lVar31 >> 0x20),
                        (int)lVar31);
      uVar14 = (uint)((ulonglong)lVar31 >> 0x20);
      uVar13 = (int)uVar14 >> 0x1f;
      uVar15 = (uint)lVar31 ^ uVar13;
      uVar21 = uVar15 - uVar13;
      local_2c = ((uVar14 ^ uVar13) - (uVar13 + (uVar15 < uVar13))) + (uint)(0xff7fffff < uVar21);
      local_40[4] = uVar21 + 0x800000 >> 0x18 | local_2c * 0x100;
      local_2c = local_2c >> 0x18;
      if (lVar31 < 0) {
        bVar28 = local_40[4] != 0;
        local_40[4] = -local_40[4];
        local_2c = -(local_2c + bVar28);
      }
      uVar13 = uVar17 - 0x280000;
      iVar7 = uVar16 - (uVar17 < 0x280000);
      bVar28 = uVar13 < 0x2440000;
      iVar6 = iVar7;
      if ((int)(uint)bVar28 <= iVar7) {
        iVar6 = 0;
        uVar13 = 0x243ffff;
      }
      if ((iVar7 < (int)(uint)bVar28) && (iVar6 < 0)) {
        uVar13 = 0;
        iVar6 = 0;
      }
      uVar17 = uVar13 >> 0x11 | iVar6 << 0xf;
      iVar6 = uVar17 + 1;
      puVar24 = local_50 + 4;
      puVar27 = param_2 + 10;
      puVar19 = param_2 + 7;
      piVar20 = (int *)(&UNK_009a9a1c + iVar6 * 0xc);
      do {
        lVar31 = (longlong)(int)(0x20000 - (uVar13 & 0x1ffff)) *
                 (longlong)piVar20[iVar6 * -3 + uVar17 * 3] +
                 (longlong)(int)(uVar13 & 0x1ffff) * (longlong)*piVar20;
        uVar21 = (uint)((ulonglong)lVar31 >> 0x20);
        uVar16 = (int)uVar21 >> 0x1f;
        uVar14 = (uint)lVar31 ^ uVar16;
        uVar15 = uVar14 - uVar16;
        uVar16 = ((uVar21 ^ uVar16) - (uVar16 + (uVar14 < uVar16))) + (uint)(0xfffeffff < uVar15);
        uVar14 = uVar15 + 0x10000 >> 0x11 | uVar16 * 0x8000;
        uVar16 = uVar16 >> 0x11;
        if (lVar31 < 0) {
          bVar28 = uVar14 != 0;
          uVar14 = -uVar14;
          uVar16 = -(uVar16 + bVar28);
        }
        lVar31 = (ulonglong)*puVar24 * (ulonglong)uVar14;
        uVar14 = uVar14 * puVar24[1] + *puVar24 * uVar16 + (int)((ulonglong)lVar31 >> 0x20);
        uVar16 = (int)uVar14 >> 0x1f;
        puVar24 = puVar24 + 2;
        uVar16 = ((uVar14 ^ uVar16) - (uVar16 + (((uint)lVar31 ^ uVar16) < uVar16))) + 2 >> 2;
        if ((int)uVar14 < 0) {
          uVar16 = -uVar16;
        }
        puVar19 = puVar19 + 1;
        *puVar19 = uVar16;
        piVar20 = piVar20 + 1;
      } while (puVar27 != puVar19);
      iVar6 = 0;
      piVar20 = &DAT_009a9768;
      do {
        iVar7 = 0;
        puVar18 = &DAT_009a978c;
        local_68 = puVar27;
        do {
          iVar8 = 0;
          puVar19 = param_2 + 7;
          uVar16 = 0;
          uVar17 = 0;
          local_6c = piVar20;
          do {
            piVar1 = puVar18 + iVar8;
            puVar19 = puVar19 + 1;
            uVar32 = (longlong)*local_6c * (longlong)(int)*puVar19;
            piVar2 = puVar18 + iVar8;
            puVar24 = puVar18 + iVar8;
            iVar8 = iVar8 + 3;
            lVar31 = (ulonglong)*puVar24 * (uVar32 & 0xffffffff);
            uVar13 = (uint)lVar31;
            bVar28 = CARRY4(uVar13,uVar16);
            uVar16 = uVar13 + uVar16;
            uVar17 = (int)(uVar32 >> 0x20) * *piVar1 + (int)uVar32 * (*piVar2 >> 0x1f) +
                     (int)((ulonglong)lVar31 >> 0x20) + uVar17 + (uint)bVar28;
            local_6c = local_6c + 1;
          } while (iVar8 != 9);
          uVar13 = (int)uVar17 >> 0x1f;
          uVar14 = (uVar16 ^ uVar13) - uVar13;
          uVar16 = uVar14 + 0x20000000 >> 0x1e |
                   (((uVar17 ^ uVar13) - (uVar13 + ((uVar16 ^ uVar13) < uVar13))) +
                   (uint)(0xdfffffff < uVar14)) * 4;
          if ((int)uVar17 < 0) {
            uVar16 = -uVar16;
          }
          iVar7 = iVar7 + 1;
          local_68 = local_68 + 1;
          *local_68 = uVar16;
          puVar18 = puVar18 + 1;
        } while (iVar7 != 3);
        iVar6 = iVar6 + 3;
        piVar20 = piVar20 + 3;
        puVar27 = puVar27 + 3;
      } while (iVar6 != 9);
      return 0;
    }
  }
  return 0xffffffff;
}


// ===== FUN_0099a944 @ 0099a944

undefined4 FUN_0099a944(void)

{
  undefined4 uVar1;
  
  uVar1 = (*(code *)&SUB_ff81138c)();
  FUN_009a3590();
  return uVar1;
}


// ===== FUN_0099a998 @ 0099a998

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0099a998(undefined1 *param_1,uint param_2)

{
  char *pcVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined *puVar5;
  undefined1 *puVar6;
  bool bVar7;
  
  for (iVar4 = 0; param_1[iVar4] != '\0'; iVar4 = iVar4 + 1) {
  }
  if (0x1000 < (uint)(iVar4 + 0xc + _DAT_009ef060)) {
    if (_DAT_009ef05c == (code *)0x0) goto LAB_0099aa78;
    (*_DAT_009ef05c)();
  }
  if ((uint)(_DAT_009ef060 + iVar4 + 0xc) < 0x1001) {
    iVar2 = 0;
    puVar6 = param_1 + iVar4;
    puVar5 = &UNK_009ef080 + _DAT_009ef060;
    for (; puVar6 != param_1; param_1 = param_1 + 1) {
      *puVar5 = *param_1;
      iVar2 = 1;
      puVar5 = puVar5 + 1;
    }
    iVar4 = iVar4 * iVar2 + _DAT_009ef060;
    (&UNK_009ef080)[iVar4] = 0x20;
    (&UNK_009ef081)[iVar4] = 0x30;
    (&UNK_009ef082)[iVar4] = 0x78;
    pcVar1 = &UNK_009ef082 + iVar4;
    uVar3 = 0x1c;
    do {
      bVar7 = uVar3 != 0;
      pcVar1 = pcVar1 + 1;
      *pcVar1 = "0123456789abcdef"[param_2 >> (uVar3 & 0xff) & 0xf];
      uVar3 = uVar3 - 4;
    } while (bVar7);
    _DAT_009ef060 = iVar4 + 0xc;
    (&UNK_009ef08b)[iVar4] = 10;
    return;
  }
LAB_0099aa78:
  _DAT_009ef058 = _DAT_009ef058 + 1;
  return;
}


// ===== FUN_0099aab4 @ 0099aab4

void FUN_0099aab4(char *param_1,int param_2)

{
  char *pcVar1;
  
  pcVar1 = (char *)(param_2 + -1);
  while( true ) {
    pcVar1 = pcVar1 + 1;
    if (*pcVar1 == '\0') break;
    *param_1 = *pcVar1;
    param_1 = param_1 + 1;
  }
  *param_1 = '\0';
  return;
}


// ===== FUN_0099aad4 @ 0099aad4

void FUN_0099aad4(int param_1,int param_2)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  
  puVar1 = (undefined1 *)((int)&DAT_009b2254 + param_2 * 0xc + 3);
  puVar2 = (undefined1 *)(param_1 + -1);
  do {
    puVar1 = puVar1 + 1;
    puVar2 = puVar2 + 1;
    *puVar2 = *puVar1;
  } while (puVar2 != (undefined1 *)(param_1 + 3));
  *(undefined1 *)(param_1 + 4) = 0;
  return;
}


// ===== FUN_0099ab08 @ 0099ab08

bool FUN_0099ab08(uint param_1)

{
  if (param_1 / 10000 - 100 < 900) {
    return param_1 % 10000 - 1 < 9999;
  }
  return false;
}


// ===== FUN_0099ab58 @ 0099ab58

char * FUN_0099ab58(char *param_1,uint param_2,int param_3)

{
  char extraout_r1;
  char *pcVar1;
  
  pcVar1 = param_1 + param_3;
  do {
    FUN_009a5ce4(param_2,10);
    pcVar1 = pcVar1 + -1;
    *pcVar1 = extraout_r1 + '0';
    param_2 = param_2 / 10;
  } while (pcVar1 != param_1);
  return param_1 + param_3;
}


// ===== FUN_0099aba0 @ 0099aba0

undefined4 FUN_0099aba0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 local_c;
  undefined4 uStack_8;
  
  local_c = 0;
  uStack_8 = param_3;
  (*(code *)&SUB_ffb1ff74)(&local_c);
  return local_c;
}


// ===== FUN_0099aba4 @ 0099aba4

undefined4 FUN_0099aba4(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 local_c;
  undefined4 uStack_8;
  
  local_c = param_4;
  uStack_8 = param_3;
  (*(code *)&SUB_ffb1ff74)(&local_c);
  return local_c;
}


// ===== FUN_0099abc8 @ 0099abc8

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0099abc8(int param_1,uint param_2,uint param_3,uint param_4)

{
  uint uVar1;
  undefined4 uVar2;
  
  uVar1 = _DAT_009eca48;
  uVar2 = FUN_0099aba0();
  *(undefined4 *)(&UNK_009eca4c + (uVar1 & 0x3f) * 8) = uVar2;
  *(uint *)(&UNK_009eca50 + (uVar1 & 0x3f) * 8) =
       (param_3 & 0x7f) << 7 | param_4 & 0x7f | param_1 << 0x1c | (param_2 & 0x3fff) << 0xe;
  _DAT_009eca48 = _DAT_009eca48 + 1;
  return;
}


// ===== FUN_0099ac40 @ 0099ac40

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0099ac40(void)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  iVar2 = 2;
  piVar3 = (int *)&DAT_009ecd34;
  while( true ) {
    if (*piVar3 == 0) {
      iVar1 = (*(code *)&SUB_ffb2a56c)(0x3f4c0);
      *piVar3 = iVar1;
    }
    if (iVar2 == 1) break;
    iVar2 = 1;
    piVar3 = piVar3 + 1;
  }
  if ((_DAT_009ecd34 == 0) || (_DAT_009ecd38 == 0)) {
    if ((_DAT_009eca44 != 0) && (_DAT_009eca40 == 0)) {
      _DAT_009eca3c = _DAT_009eca3c + 1;
    }
    _DAT_009eca40 = 0;
  }
  else {
    _DAT_009eca40 = 1;
  }
  _DAT_009eca40 = _DAT_009eca40 ^ 1;
  if (_DAT_009eca44 == 0) {
    _DAT_009eca40 = 0;
  }
  return;
}


// ===== FUN_0099acfc @ 0099acfc

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0099acfc(int param_1)

{
  int iVar1;
  
  iVar1 = (*(code *)&SUB_ffb0d9fc)(*(undefined4 *)(&DAT_009ecd34 + param_1 * 4),0,0,0x2d0,0xf0,0,0);
  FUN_0099abc8(6,*(undefined4 *)(&DAT_009ecd2c + param_1 * 4),param_1);
  if (iVar1 == 0) {
    (*(code *)&SUB_ffb0e070)();
    _DAT_009ec91c = _DAT_009ec91c + 1;
    DAT_009b4a78 = param_1;
  }
  else {
    _DAT_009ec920 = _DAT_009ec920 + 1;
  }
  return;
}


// ===== FUN_0099ad04 @ 0099ad04

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0099ad04(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = (*(code *)&SUB_ffb0d9fc)
                    (*(undefined4 *)(&DAT_009ecd34 + param_1 * 4),param_3,param_3,0x2d0,param_4,
                     param_3,param_3);
  FUN_0099abc8(6,*(undefined4 *)(&DAT_009ecd2c + param_1 * 4),param_1);
  if (iVar1 == 0) {
    (*(code *)&SUB_ffb0e070)();
    _DAT_009ec91c = _DAT_009ec91c + 1;
    DAT_009b4a78 = param_1;
  }
  else {
    _DAT_009ec920 = _DAT_009ec920 + 1;
  }
  return;
}


// ===== FUN_0099ae24 @ 0099ae24

void FUN_0099ae24(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  undefined4 uVar1;
  char *pcVar2;
  char *pcVar3;
  
  uVar1 = FUN_0099aab4();
  pcVar2 = (char *)FUN_0099ab58(uVar1,param_3,4);
  pcVar3 = (char *)(param_4 + -1);
  while( true ) {
    pcVar3 = pcVar3 + 1;
    if (*pcVar3 == '\0') break;
    *pcVar2 = *pcVar3;
    pcVar2 = pcVar2 + 1;
  }
  *pcVar2 = '\0';
  return;
}


// ===== FUN_0099ae48 @ 0099ae48

int FUN_0099ae48(uint param_1)

{
  int extraout_r1;
  int extraout_r1_00;
  
  FUN_009a5ce4(param_1,10000);
  if (extraout_r1 != 9999) {
    return param_1 + 1;
  }
  if (param_1 < 0x986f70) {
    FUN_009a5e2c(param_1,10000);
    return (param_1 - extraout_r1_00) + 0x2711;
  }
  return 0;
}


// ===== FUN_0099aea8 @ 0099aea8

void FUN_0099aea8(int param_1,uint param_2,uint param_3)

{
  uint uVar1;
  undefined1 *puVar2;
  uint uVar3;
  
  uVar3 = 0;
  puVar2 = (undefined1 *)(param_1 + -1);
  do {
    puVar2[1] = (char)((int)(param_2 & 0xffffff) >> (uVar3 & 0xff));
    uVar1 = uVar3 & 0xff;
    uVar3 = uVar3 + 8;
    puVar2[5] = (char)((param_2 >> 0x18 | (param_3 & 0xf) << 8 | (param_3 & 0x3f0) << 8) >> uVar1);
    puVar2 = puVar2 + 1;
  } while (uVar3 != 0x20);
  return;
}


// ===== FUN_0099af00 @ 0099af00

void FUN_0099af00(undefined4 *param_1,undefined4 param_2)

{
  *param_1 = param_2;
  return;
}


// ===== FUN_0099af08 @ 0099af08

undefined4 FUN_0099af08(undefined4 *param_1)

{
  return *param_1;
}


// ===== FUN_0099af10 @ 0099af10

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0099af10(uint param_1)

{
  int iVar1;
  
  iVar1 = 0;
  do {
    if (_DAT_009ece38 == iVar1) {
      return 0;
    }
    iVar1 = iVar1 + 1;
  } while ((*(uint *)(&DAT_009ece40 + iVar1 * 8) & 0xffffff) != param_1);
  return 1;
}


// ===== FUN_0099af54 @ 0099af54

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_0099af54(int param_1)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)&DAT_009ea644;
  iVar2 = 0;
  while ((_DAT_009ea628 != iVar2 && (piVar1 = piVar1 + 1, *piVar1 != param_1))) {
    iVar2 = iVar2 + 1;
  }
  return iVar2;
}


// ===== FUN_0099af90 @ 0099af90

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool FUN_0099af90(int param_1)

{
  uint uVar1;
  
  if (param_1 == 0) {
    return false;
  }
  uVar1 = FUN_0099af54();
  return uVar1 < _DAT_009ea628;
}


// ===== FUN_0099af98 @ 0099af98

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool FUN_0099af98(void)

{
  uint uVar1;
  
  uVar1 = FUN_0099af54();
  return uVar1 < _DAT_009ea628;
}


// ===== FUN_0099afc4 @ 0099afc4

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0099afc4(void)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint *puVar5;
  uint *puVar6;
  
  puVar6 = (uint *)&DAT_009ea644;
  iVar4 = 0;
  uVar1 = 0;
  do {
    if (_DAT_009ea628 == iVar4) {
      return;
    }
    puVar6 = puVar6 + 1;
    uVar2 = *puVar6;
    if (uVar1 < uVar2) {
      puVar5 = (uint *)&DAT_009ea418;
      for (iVar3 = 0; (iVar3 != _DAT_009ea414 && (iVar3 != 0x40)); iVar3 = iVar3 + 1) {
        if (uVar2 == *puVar5) goto LAB_0099b000;
        puVar5 = puVar5 + 1;
      }
      uVar1 = uVar2;
    }
LAB_0099b000:
    iVar4 = iVar4 + 1;
  } while( true );
}


// ===== FUN_0099afc8 @ 0099afc8

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0099afc8(void)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int *in_r3;
  int iVar4;
  uint *puVar5;
  uint *puVar6;
  
  puVar6 = (uint *)&DAT_009ea644;
  iVar4 = 0;
  uVar1 = 0;
  do {
    if (*in_r3 == iVar4) {
      return;
    }
    puVar6 = puVar6 + 1;
    uVar2 = *puVar6;
    if (uVar1 < uVar2) {
      puVar5 = (uint *)&DAT_009ea418;
      for (iVar3 = 0; (iVar3 != _DAT_009ea414 && (iVar3 != 0x40)); iVar3 = iVar3 + 1) {
        if (uVar2 == *puVar5) goto LAB_0099b000;
        puVar5 = puVar5 + 1;
      }
      uVar1 = uVar2;
    }
LAB_0099b000:
    iVar4 = iVar4 + 1;
  } while( true );
}


// ===== FUN_0099b044 @ 0099b044

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_0099b044(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  
  iVar1 = _DAT_009ea414;
  iVar4 = _DAT_009ea628;
  puVar5 = (undefined4 *)&DAT_009ea418;
  for (iVar3 = 0; (iVar1 != iVar3 && (iVar3 != 0x40)); iVar3 = iVar3 + 1) {
    iVar2 = FUN_0099af90(*puVar5);
    iVar4 = iVar4 - iVar2;
    puVar5 = puVar5 + 1;
  }
  return iVar4;
}


// ===== FUN_0099b098 @ 0099b098

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0099b098(int param_1)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)&DAT_009ea51c;
  for (iVar2 = 0; (_DAT_009ea518 != iVar2 && (iVar2 != 0x40)); iVar2 = iVar2 + 1) {
    if (*piVar1 == param_1) {
      return 1;
    }
    piVar1 = piVar1 + 1;
  }
  return 0;
}


// ===== FUN_0099b0e4 @ 0099b0e4

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0099b0e4(int param_1)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)&DAT_009ecdb0;
  iVar2 = 0;
  while( true ) {
    if (_DAT_009ecdac == iVar2) {
      return 0;
    }
    if (*piVar1 == param_1) break;
    piVar1 = piVar1 + 1;
    iVar2 = iVar2 + 1;
  }
  return 1;
}


// ===== FUN_0099b128 @ 0099b128

uint FUN_0099b128(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  uint *local_10;
  uint local_c;
  undefined4 uStack_8;
  
  local_10 = (uint *)0x0;
  local_c = 0;
  uStack_8 = param_3;
  iVar1 = (*(code *)&SUB_ffab3e24)(param_1,&local_10,&local_c);
  if ((iVar1 == 0) && (local_10 != (uint *)0x0)) {
    if (3 < local_c) {
      return *local_10;
    }
    if (1 < local_c) {
      return (uint)(ushort)*local_10;
    }
  }
  return 0xffffffff;
}


// ===== FUN_0099b12c @ 0099b12c

uint FUN_0099b12c(undefined4 param_1,undefined4 param_2,undefined4 param_3,uint *param_4)

{
  int iVar1;
  uint *local_10;
  uint *local_c;
  undefined4 uStack_8;
  
  local_10 = param_4;
  local_c = param_4;
  uStack_8 = param_3;
  iVar1 = (*(code *)&SUB_ffab3e24)(param_1,&local_10,&local_c);
  if ((iVar1 == 0) && (local_10 != (uint *)0x0)) {
    if ((uint *)0x3 < local_c) {
      return *local_10;
    }
    if ((uint *)0x1 < local_c) {
      return (uint)(ushort)*local_10;
    }
  }
  return 0xffffffff;
}


// ===== FUN_0099b18c @ 0099b18c

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0099b18c(uint param_1,uint param_2)

{
  _DAT_009e988c = 0;
  _DAT_009e9894 = _DAT_009e9894 + 1;
  _DAT_009e9890 = param_2 >> 10 & 0xffff | (param_1 >> 10) << 0x10;
  return;
}


// ===== FUN_0099b1d4 @ 0099b1d4

uint FUN_0099b1d4(uint param_1)

{
  return *(uint *)(param_1 & 0xffffffc | 0x10000000) >> ((param_1 & 3) << 3) & 0xff;
}


// ===== FUN_0099b1f4 @ 0099b1f4

bool FUN_0099b1f4(int param_1,uint param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  if (param_1 == 0 || param_2 < 0x10) {
    return false;
  }
  iVar1 = FUN_0099b1d4(param_1,param_2,param_1);
  if (iVar1 == 0xff) {
    uVar2 = FUN_0099b1d4(param_1 + 1);
    if ((int)uVar2 == 0xd8) {
      param_1 = param_1 + (int)((ulonglong)uVar2 >> 0x20);
      iVar1 = FUN_0099b1d4(param_1 + -2);
      if (iVar1 == 0xff) {
        iVar1 = FUN_0099b1d4(param_1 + -1);
        return iVar1 == 0xd9;
      }
    }
  }
  return false;
}


// ===== FUN_0099b210 @ 0099b210

bool FUN_0099b210(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  iVar1 = FUN_0099b1d4(param_1,param_2,param_1);
  if ((iVar1 == 0xff) && (uVar2 = FUN_0099b1d4(param_1 + 1), (int)uVar2 == 0xd8)) {
    param_1 = param_1 + (int)((ulonglong)uVar2 >> 0x20);
    iVar1 = FUN_0099b1d4(param_1 + -2);
    if (iVar1 == 0xff) {
      iVar1 = FUN_0099b1d4(param_1 + -1);
      return iVar1 == 0xd9;
    }
  }
  return false;
}


// ===== FUN_0099b260 @ 0099b260

bool FUN_0099b260(uint param_1,uint param_2)

{
  if ((param_2 < 0x1000 || param_1 == 0) || (*(int *)(param_1 & 0xffffffc | 0x10000000) != 0x2a4949)
     ) {
    return false;
  }
  return (*(uint *)(param_1 + 8 & 0xffffffc | 0x10000000) & 0xffff) == 0x5243;
}


// ===== FUN_0099b2cc @ 0099b2cc

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool FUN_0099b2cc(void)

{
  uint uVar1;
  uint uVar2;
  int extraout_r1;
  int iVar3;
  int iVar4;
  undefined8 uVar5;
  
  uVar1 = _DAT_009e97dc;
  if (((((*(int *)(_DAT_009e97dc & 0xffffffc | 0x10000000) != -0x74d628) ||
        (_DAT_009e97e0 != *(int *)(_DAT_009e97dc + 4 & 0xffffffc | 0x10000000))) ||
       (iVar4 = *(int *)(_DAT_009e97dc + 0xc & 0xffffffc | 0x10000000),
       FUN_009a5ce4(_DAT_009e97e4,10000), uVar2 = _DAT_009e9808, iVar3 = _DAT_009e9804,
       extraout_r1 != iVar4)) ||
      ((_DAT_009e97fc != *(int *)(uVar1 + 0x16c & 0xffffffc | 0x10000000) ||
       (_DAT_009e9800 != *(int *)(uVar1 + 0x170 & 0xffffffc | 0x10000000))))) ||
     ((_DAT_009e9804 != *(int *)(uVar1 + 0x154 & 0xffffffc | 0x10000000) ||
      ((_DAT_009e9808 != *(uint *)(uVar1 + 0x158 & 0xffffffc | 0x10000000) ||
       (iVar4 = FUN_0099b260(), iVar4 == 0)))))) {
    return false;
  }
  if (iVar3 == 0 || uVar2 < 0x10) {
    return false;
  }
  iVar4 = FUN_0099b1d4(iVar3,uVar2,iVar3);
  if (iVar4 == 0xff) {
    uVar5 = FUN_0099b1d4(iVar3 + 1);
    if ((int)uVar5 == 0xd8) {
      iVar3 = iVar3 + (int)((ulonglong)uVar5 >> 0x20);
      iVar4 = FUN_0099b1d4(iVar3 + -2);
      if (iVar4 == 0xff) {
        iVar3 = FUN_0099b1d4(iVar3 + -1);
        return iVar3 == 0xd9;
      }
    }
  }
  return false;
}


// ===== FUN_0099b3d0 @ 0099b3d0

undefined4 * FUN_0099b3d0(undefined4 *param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  char cStack_1b;
  
  uVar3 = param_2 & 0xff;
  uVar1 = FUN_0099aab4(param_3,"A:/LATENT/",param_3,param_4,param_1);
  uVar1 = FUN_0099aad4(uVar1,uVar3);
  FUN_0099aab4(uVar1,&DAT_009a6c0f);
  uVar1 = FUN_0099aab4(param_4,"A:/LATENT/");
  uVar1 = FUN_0099aad4(uVar1,uVar3);
  uVar2 = param_2 >> 0x10 & 0xff;
  FUN_0099aab4(uVar1,"/GRAIN.LTG");
  cStack_1b = (char)(param_2 >> 8);
  if ((uVar2 < 0xd) && (((int)(uint)*(ushort *)(&DAT_009b1de0 + uVar3 * 0xc) >> uVar2 & 1U) != 0)) {
    param_2 = param_2 >> 0x18;
  }
  else {
    param_2 = 0xffffffff;
  }
  *param_1 = param_3;
  param_1[1] = param_4;
  param_1[2] = (int)cStack_1b;
  param_1[3] = uVar2;
  param_1[4] = param_2;
  return param_1;
}


// ===== FUN_0099b4a8 @ 0099b4a8

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0099b4a8(void)

{
  int iVar1;
  uint uVar2;
  
  _DAT_009ecd08 = _DAT_009ecd08 + 1;
  uVar2 = _DAT_009e70d4 & 0x1f;
  _DAT_009e70d4 = _DAT_009e70d4 + 1;
  *(undefined4 *)(&UNK_009e70d8 + uVar2 * 0x10) = 4;
  iVar1 = uVar2 * 0x10;
  *(undefined4 *)(&UNK_009e70e0 + iVar1) = 0x4c544e4e;
  *(undefined4 *)(&UNK_009e70dc + iVar1) = 4;
  *(undefined4 *)(&UNK_009e70e4 + iVar1) = 0;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0099b4c4 @ 0099b4c4

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0099b4c4(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = (_DAT_009ecd68 & 7) * 8;
  *(undefined4 *)(&UNK_009ecd6c + iVar1) = param_1;
  *(undefined4 *)(&UNK_009ecd70 + iVar1) = param_2;
  _DAT_009ecd68 = _DAT_009ecd68 + 1;
  uVar2 = _DAT_009e70d4 & 0x1f;
  _DAT_009e70d4 = _DAT_009e70d4 + 1;
  *(undefined4 *)(&UNK_009e70d8 + uVar2 * 0x10) = 4;
  iVar1 = uVar2 * 0x10;
  *(undefined4 *)(&UNK_009e70e0 + iVar1) = 0x4c544e4e;
  *(undefined4 *)(&UNK_009e70dc + iVar1) = 3;
  *(undefined4 *)(&UNK_009e70e4 + iVar1) = 0;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0099b508 @ 0099b508

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0099b508(int param_1)

{
  int iVar1;
  uint uVar2;
  
  *(int *)(&UNK_009ecca0 + (_DAT_009ecc9c & 7) * 4) = param_1;
  _DAT_009ecc9c = _DAT_009ecc9c + 1;
  uVar2 = _DAT_009e70d4 & 0x1f;
  _DAT_009e70d4 = _DAT_009e70d4 + 1;
  *(undefined4 *)(&UNK_009e70d8 + uVar2 * 0x10) = 4;
  iVar1 = uVar2 * 0x10;
  *(undefined4 *)(&UNK_009e70e0 + iVar1) = 0x4c544e4e;
  *(uint *)(&UNK_009e70dc + iVar1) = param_1 << 8 | 6;
  *(undefined4 *)(&UNK_009e70e4 + iVar1) = 0;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0099b53c @ 0099b53c

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0099b53c(undefined4 param_1,uint param_2)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  
  uVar3 = _DAT_009eca48;
  _DAT_009ecc8c = param_2;
  if ((_DAT_009ecd34 == 0) || (param_2 != _DAT_009ecd2c)) {
    if ((_DAT_009ecd38 == 0) || (param_2 != _DAT_009ecd30)) {
      if ((_DAT_009ecd28 == param_2) && (_DAT_009ecd20 != _DAT_009ecd1c)) {
        uVar2 = FUN_0099aba0();
        *(undefined4 *)(&UNK_009eca4c + (uVar3 & 0x3f) * 8) = uVar2;
        *(uint *)(&UNK_009eca50 + (uVar3 & 0x3f) * 8) = (param_2 & 0x3fff) << 0xe | 0x30000000;
        _DAT_009eca48 = _DAT_009eca48 + 1;
        return;
      }
      _DAT_009ecc60 = FUN_0099aba0();
      uVar3 = (uint)(DAT_009b4a78 == 0);
      if (DAT_009b4a74 == uVar3) {
        FUN_0099abc8(2,param_2,DAT_009b4a74,0);
        _DAT_009ecc64 = param_2;
        if (_DAT_009ecc6c != _DAT_009ecc74) {
          _DAT_009ecc68 = 1;
        }
        return;
      }
      if (*(int *)(&DAT_009ecd34 + uVar3 * 4) == 0) {
        FUN_0099ac40();
      }
      FUN_0099abc8(2,param_2,uVar3,*(int *)(&DAT_009ecd34 + uVar3 * 4) != 0);
      if (*(int *)(&DAT_009ecd34 + uVar3 * 4) == 0) {
        return;
      }
      *(undefined4 *)(&DAT_009ecd2c + uVar3 * 4) = 0;
      _DAT_009ecd28 = param_2;
      _DAT_009ecd24 = uVar3;
      _DAT_009ecd20 = _DAT_009ecd20 + 1;
      return;
    }
    _DAT_009ecc94 = 1;
  }
  else {
    _DAT_009ecc94 = 0;
  }
  _DAT_009ecc98 = param_2;
  FUN_0099abc8(1,param_2,_DAT_009ecc94,DAT_009b4a78);
  uVar3 = _DAT_009e70d4 & 0x1f;
  _DAT_009e70d4 = _DAT_009e70d4 + 1;
  *(undefined4 *)(&UNK_009e70d8 + uVar3 * 0x10) = 4;
  iVar1 = uVar3 * 0x10;
  *(undefined4 *)(&UNK_009e70e0 + iVar1) = 0x4c544e4e;
  *(uint *)(&UNK_009e70dc + iVar1) = param_2 << 8 | 5;
  *(undefined4 *)(&UNK_009e70e4 + iVar1) = 0;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0099b714 @ 0099b714

/* WARNING: Removing unreachable block (ram,0x0098a94c) */

uint FUN_0099b714(uint param_1)

{
  char cVar1;
  uint3 uVar2;
  undefined4 uVar3;
  byte bVar4;
  uint uVar5;
  byte bVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  undefined8 uVar10;
  
  cVar1 = (char)(param_1 >> 8) + -6;
  bVar4 = (byte)(param_1 >> 0x18);
  bVar6 = (byte)(param_1 >> 0x10);
  uVar2 = CONCAT12(bVar6,CONCAT11(cVar1,(char)param_1));
  uVar3 = CONCAT13(bVar4,uVar2);
  uVar7 = uVar2 & 0xff;
  if (0x50 < uVar7) {
    return 0x5000000;
  }
  iVar8 = uVar7 * 0xc;
  uVar9 = (int)(char)(&DAT_009b1ddc)[iVar8];
  if ((int)(char)(&DAT_009b1ddc)[iVar8] < (int)cVar1) {
    uVar9 = (int)cVar1;
  }
  if ((int)(char)(&UNK_009b1ddd)[iVar8] <= (int)uVar9) {
    uVar9 = (int)(char)(&UNK_009b1ddd)[iVar8];
  }
  uVar9 = uVar9 & 0xff;
  if ((byte)(&DAT_009b1dde)[iVar8] <= bVar6) {
    bVar6 = (&UNK_009b1ddf)[iVar8];
  }
  uVar10 = FUN_0098a850(&DAT_009b1ddc + iVar8,bVar6,uVar7,uVar9,&DAT_009b1ddc,uVar3,uVar3,
                        param_1 >> 0x10);
  uVar5 = (uint)uVar10 ^ 1;
  if (0xb < bVar4) {
    uVar5 = uVar5 | 1;
  }
  if ((uVar5 & 1) != 0) {
    bVar4 = 5;
  }
  return uVar7 | uVar9 << 8 | (int)((ulonglong)uVar10 >> 0x20) << 0x10 | (uint)bVar4 << 0x18;
}


// ===== FUN_0099b750 @ 0099b750

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0099b750(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  FUN_0099ab58(&UNK_009e7440,_DAT_009ec648,7);
  iVar1 = FUN_009828c0("A:/LATENT/LAST.TXT");
  if (iVar1 < 0) {
    return 0xffffffff;
  }
  iVar2 = FUN_009829b8(iVar1,&UNK_009e7440,7);
  iVar1 = FUN_00982a90(iVar1,1);
  if (iVar1 == 0 && iVar2 == 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = 0xffffffff;
  }
  return uVar3;
}


// ===== FUN_0099b788 @ 0099b788

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0099b788(void)

{
  undefined4 uVar2;
  int iVar1;
  int iVar3;
  int iVar4;
  undefined4 unaff_r4;
  undefined *puVar5;
  bool bVar6;
  undefined4 unaff_r5;
  undefined4 unaff_r6;
  int iVar7;
  undefined4 unaff_r7;
  undefined4 unaff_r8;
  
  iVar4 = _DAT_009e7584;
  _DAT_009e75a0 = 0x3447544c;
  puVar5 = &DAT_009e75a0;
  FUN_0099af00(&UNK_009e75a4,_DAT_009e7584);
  for (iVar7 = 0; iVar4 != iVar7; iVar7 = iVar7 + 1) {
    puVar5 = puVar5 + 8;
    FUN_0099aea8(puVar5,*(undefined4 *)(&DAT_009e85a8 + iVar7 * 8),
                 *(undefined4 *)(&DAT_009e85ac + iVar7 * 8));
  }
  iVar4 = (iVar4 + 1) * 8;
  iVar7 = iRam009b49a0 + 1;
  _DAT_009b4b40 = 0x4352544c;
  _DAT_009b4b44 = iVar7;
  _DAT_009b4b48 = iVar4;
  _DAT_009b4b4c =
       FUN_00982ce4(&DAT_009e75a0,iVar4,iVar4,0x4352544c,unaff_r4,unaff_r5,unaff_r6,unaff_r7,
                    unaff_r8);
  uVar2 = uRam009b4998;
  if (bRam009b49a4 == 0) {
    uVar2 = _DAT_009b4994;
  }
  iVar1 = FUN_009828c0(uVar2);
  if (iVar1 < 0) {
    bVar6 = false;
  }
  else {
    iVar3 = FUN_009829b8(iVar1,&DAT_009b4b40,0x10);
    if (iVar3 == 0) {
      if (iVar4 == 0) {
        bVar6 = true;
      }
      else {
        iVar4 = FUN_009829b8(iVar1,&DAT_009e75a0,iVar4);
        bVar6 = iVar4 == 0;
      }
    }
    else {
      bVar6 = false;
    }
    iVar4 = FUN_00982a90(iVar1,1);
    if (iVar4 != 0) {
      bVar6 = false;
    }
  }
  iRam009b49a8 = iRam009b49a8 + 1;
  if (bVar6) {
    iRam009b49a0 = iVar7;
    bRam009b49a4 = bRam009b49a4 ^ 1;
    return 0;
  }
  iRam009b49ac = iRam009b49ac + 1;
  return 0xffffffff;
}


// ===== FUN_0099b790 @ 0099b790

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
FUN_0099b790(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar2;
  int iVar1;
  int iVar3;
  int iVar4;
  undefined4 unaff_r4;
  undefined *puVar5;
  bool bVar6;
  undefined4 unaff_r5;
  undefined4 unaff_r6;
  int iVar7;
  undefined4 unaff_r7;
  undefined4 unaff_r8;
  
  *param_1 = param_4;
  iVar4 = _DAT_009e7584;
  puVar5 = &DAT_009e75a0;
  FUN_0099af00(param_1 + 1,_DAT_009e7584);
  for (iVar7 = 0; iVar4 != iVar7; iVar7 = iVar7 + 1) {
    puVar5 = puVar5 + 8;
    FUN_0099aea8(puVar5,*(undefined4 *)(&DAT_009e85a8 + iVar7 * 8),
                 *(undefined4 *)(&DAT_009e85ac + iVar7 * 8));
  }
  iVar4 = (iVar4 + 1) * 8;
  iVar7 = iRam009b49a0 + 1;
  _DAT_009b4b40 = 0x4352544c;
  _DAT_009b4b44 = iVar7;
  _DAT_009b4b48 = iVar4;
  _DAT_009b4b4c =
       FUN_00982ce4(&DAT_009e75a0,iVar4,iVar4,0x4352544c,unaff_r4,unaff_r5,unaff_r6,unaff_r7,
                    unaff_r8);
  uVar2 = uRam009b4998;
  if (bRam009b49a4 == 0) {
    uVar2 = _DAT_009b4994;
  }
  iVar1 = FUN_009828c0(uVar2);
  if (iVar1 < 0) {
    bVar6 = false;
  }
  else {
    iVar3 = FUN_009829b8(iVar1,&DAT_009b4b40,0x10);
    if (iVar3 == 0) {
      if (iVar4 == 0) {
        bVar6 = true;
      }
      else {
        iVar4 = FUN_009829b8(iVar1,&DAT_009e75a0,iVar4);
        bVar6 = iVar4 == 0;
      }
    }
    else {
      bVar6 = false;
    }
    iVar4 = FUN_00982a90(iVar1,1);
    if (iVar4 != 0) {
      bVar6 = false;
    }
  }
  iRam009b49a8 = iRam009b49a8 + 1;
  if (bVar6) {
    iRam009b49a0 = iVar7;
    bRam009b49a4 = bRam009b49a4 ^ 1;
    return 0;
  }
  iRam009b49ac = iRam009b49ac + 1;
  return 0xffffffff;
}


// ===== FUN_0099b804 @ 0099b804

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0099b804(void)

{
  int iVar1;
  
  _DAT_009ea624 = 0;
  _DAT_009ea640 = 0x324f544c;
  _DAT_009ea644 = _DAT_009ea628;
  iVar1 = FUN_00982e28(&PTR_s_A__LATENT_OWED_A_009b4a0c,&DAT_009ea640,(_DAT_009ea628 + 2) * 4);
  if (iVar1 != 0) {
    _DAT_009ea624 = 1;
  }
  return;
}


// ===== FUN_0099b808 @ 0099b808

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0099b808(void)

{
  int iVar1;
  undefined4 in_r3;
  
  _DAT_009ea640 = 0x324f544c;
  _DAT_009ea644 = _DAT_009ea628;
  _DAT_009ea624 = in_r3;
  iVar1 = FUN_00982e28(&PTR_s_A__LATENT_OWED_A_009b4a0c,&DAT_009ea640,(_DAT_009ea628 + 2) * 4);
  if (iVar1 != 0) {
    _DAT_009ea624 = 1;
  }
  return;
}


// ===== FUN_0099b860 @ 0099b860

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0099b860(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined *puVar5;
  undefined4 uVar6;
  bool bVar7;
  undefined4 *puVar8;
  
  iVar3 = _DAT_009e95ac;
  iVar4 = 0;
  puVar8 = (undefined4 *)&DAT_009e95b0;
  puVar5 = &DAT_009e95e0;
  if (_DAT_009e95ac != 0) {
    do {
      uVar6 = *puVar8;
      iVar4 = iVar4 + 1;
      *puVar5 = (char)uVar6;
      puVar5[1] = (char)((uint)uVar6 >> 8);
      puVar5[2] = (char)((uint)uVar6 >> 0x10);
      puVar5[3] = (char)((uint)uVar6 >> 0x18);
      puVar5 = puVar5 + 4;
      puVar8 = puVar8 + 1;
    } while (iVar3 != iVar4);
  }
  iVar3 = iVar3 * 4;
  iVar4 = iRam009b49bc + 1;
  _DAT_009b4b40 = 0x4352544c;
  _DAT_009b4b44 = iVar4;
  _DAT_009b4b48 = iVar3;
  _DAT_009b4b4c = FUN_00982ce4(&DAT_009e95e0,iVar3);
  uVar6 = uRam009b49b4;
  if (bRam009b49c0 == 0) {
    uVar6 = _DAT_009b49b0;
  }
  iVar1 = FUN_009828c0(uVar6);
  if (iVar1 < 0) {
    bVar7 = false;
  }
  else {
    iVar2 = FUN_009829b8(iVar1,&DAT_009b4b40,0x10);
    if (iVar2 == 0) {
      if (iVar3 == 0) {
        bVar7 = true;
      }
      else {
        iVar3 = FUN_009829b8(iVar1,&DAT_009e95e0,iVar3);
        bVar7 = iVar3 == 0;
      }
    }
    else {
      bVar7 = false;
    }
    iVar3 = FUN_00982a90(iVar1,1);
    if (iVar3 != 0) {
      bVar7 = false;
    }
  }
  iRam009b49c4 = iRam009b49c4 + 1;
  if (bVar7) {
    iRam009b49bc = iVar4;
    bRam009b49c0 = bRam009b49c0 ^ 1;
    return 0;
  }
  iRam009b49c8 = iRam009b49c8 + 1;
  return 0xffffffff;
}


// ===== FUN_0099b8e0 @ 0099b8e0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0099b8e0(void)

{
  int iVar1;
  int iVar2;
  undefined *puVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  
  iVar2 = _DAT_009ecdac;
  puVar3 = &DAT_009e9980;
  puVar5 = (undefined4 *)&DAT_009ecdb0;
  for (iVar1 = 0; iVar2 != iVar1; iVar1 = iVar1 + 1) {
    uVar4 = *puVar5;
    *puVar3 = (char)uVar4;
    puVar3[1] = (char)((uint)uVar4 >> 8);
    puVar3[2] = (char)((uint)uVar4 >> 0x10);
    puVar3[3] = (char)((uint)uVar4 >> 0x18);
    puVar3 = puVar3 + 4;
    puVar5 = puVar5 + 1;
  }
  iVar2 = FUN_00982e28(&DAT_009b49f0,&DAT_009e9980,iVar2 << 2);
  _DAT_009e9a00 = (uint)(iVar2 != 0);
  return;
}


// ===== FUN_0099b8e4 @ 0099b8e4

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0099b8e4(int param_1)

{
  int iVar1;
  undefined *puVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  
  iVar1 = _DAT_009ecdac;
  puVar2 = &DAT_009e9980;
  puVar4 = (undefined4 *)&DAT_009ecdb0;
  for (; iVar1 != param_1; param_1 = param_1 + 1) {
    uVar3 = *puVar4;
    *puVar2 = (char)uVar3;
    puVar2[1] = (char)((uint)uVar3 >> 8);
    puVar2[2] = (char)((uint)uVar3 >> 0x10);
    puVar2[3] = (char)((uint)uVar3 >> 0x18);
    puVar2 = puVar2 + 4;
    puVar4 = puVar4 + 1;
  }
  iVar1 = FUN_00982e28(&DAT_009b49f0,&DAT_009e9980,iVar1 << 2);
  _DAT_009e9a00 = (uint)(iVar1 != 0);
  return;
}


// ===== FUN_0099b960 @ 0099b960

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0099b960(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined *puVar3;
  int *piVar4;
  undefined *puVar5;
  uint uVar6;
  undefined4 unaff_r4;
  uint *puVar7;
  undefined4 in_lr;
  
  iVar2 = FUN_0099b0e4();
  if (iVar2 == param_2) {
    return;
  }
  if (param_2 == 0) {
    piVar4 = (int *)&DAT_009ecdb0;
    for (iVar2 = 0; iVar2 != _DAT_009ecdac; iVar2 = iVar2 + 1) {
      if (*piVar4 == param_1) {
        _DAT_009ecdac = _DAT_009ecdac + -1;
        *(undefined4 *)(&DAT_009ecdb0 + iVar2 * 4) =
             *(undefined4 *)(&DAT_009ecdb0 + _DAT_009ecdac * 4);
        break;
      }
      piVar4 = piVar4 + 1;
    }
  }
  else {
    if (_DAT_009ecdac == 0x20) {
      return;
    }
    iVar2 = _DAT_009ecdac * 4;
    _DAT_009ecdac = _DAT_009ecdac + 1;
    *(int *)(&DAT_009ecdb0 + iVar2) = param_1;
  }
  iVar2 = _DAT_009ecdac;
  puVar5 = &DAT_009ecdac;
  puVar3 = &DAT_009e9980;
  puVar7 = (uint *)&DAT_009ecdb0;
  for (iVar1 = 0; iVar2 != iVar1; iVar1 = iVar1 + 1) {
    uVar6 = *puVar7;
    *puVar3 = (char)uVar6;
    puVar3[1] = (char)(uVar6 >> 8);
    puVar5 = (undefined *)(uVar6 >> 0x18);
    puVar3[2] = (char)(uVar6 >> 0x10);
    puVar3[3] = (char)(uVar6 >> 0x18);
    puVar3 = puVar3 + 4;
    puVar7 = puVar7 + 1;
  }
  iVar2 = FUN_00982e28(&DAT_009b49f0,&DAT_009e9980,iVar2 << 2,puVar5,unaff_r4,in_lr);
  _DAT_009e9a00 = (uint)(iVar2 != 0);
  return;
}


// ===== FUN_0099b9f0 @ 0099b9f0

/* WARNING: Removing unreachable block (ram,0x00982ea0) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0099b9f0(void)

{
  undefined4 uVar2;
  int iVar1;
  int iVar3;
  undefined4 unaff_r4;
  bool bVar4;
  int iVar5;
  
  FUN_009975a8(&UNK_009e9600,&DAT_009b582c,0x60);
  FUN_009975a8(&UNK_009e9660,&DAT_009b588c);
  iVar5 = iRam009b49d8 + 1;
  _DAT_009b4b40 = 0x4352544c;
  _DAT_009b4b48 = 0xc0;
  _DAT_009b4b44 = iVar5;
  _DAT_009b4b4c = FUN_00982ce4(&UNK_009e9600,0xc0,0xc0,0x4352544c,unaff_r4);
  uVar2 = uRam009b49d0;
  if (bRam009b49dc == 0) {
    uVar2 = _DAT_009b49cc;
  }
  iVar1 = FUN_009828c0(uVar2);
  if (iVar1 < 0) {
    bVar4 = false;
  }
  else {
    iVar3 = FUN_009829b8(iVar1,&DAT_009b4b40,0x10);
    if (iVar3 == 0) {
      iVar3 = FUN_009829b8(iVar1,&UNK_009e9600,0xc0);
      bVar4 = iVar3 == 0;
    }
    else {
      bVar4 = false;
    }
    iVar1 = FUN_00982a90(iVar1,1);
    if (iVar1 != 0) {
      bVar4 = false;
    }
  }
  iRam009b49e0 = iRam009b49e0 + 1;
  if (bVar4) {
    iRam009b49d8 = iVar5;
    bRam009b49dc = bRam009b49dc ^ 1;
    return 0;
  }
  iRam009b49e4 = iRam009b49e4 + 1;
  return 0xffffffff;
}


// ===== FUN_0099ba3c @ 0099ba3c

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0099ba3c(void)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  iVar3 = 2;
  piVar2 = (int *)&DAT_009e750c;
  while( true ) {
    if ((-1 < *piVar2) && (iVar1 = FUN_009829b8(*piVar2,&UNK_009ef080,_DAT_009ef060), iVar1 != 0)) {
      FUN_00982a90(*piVar2,0);
      *piVar2 = -1;
      _DAT_009e7508 = _DAT_009e7508 + 1;
    }
    if (iVar3 == 1) break;
    iVar3 = 1;
    piVar2 = piVar2 + 1;
  }
  _DAT_009ef060 = 0;
  return;
}


// ===== FUN_0099bac0 @ 0099bac0

bool FUN_0099bac0(undefined4 param_1,uint param_2)

{
  int iVar1;
  
  if (param_2 < 0x51) {
    iVar1 = FUN_00994d0c(&DAT_009b2258 + param_2 * 0xc);
    return iVar1 != 0;
  }
  return false;
}


// ===== FUN_0099bad0 @ 0099bad0

bool FUN_0099bad0(int param_1,int param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  
  iVar1 = FUN_00994d0c(param_2 * param_1 + param_4);
  return iVar1 != 0;
}


// ===== FUN_0099bb08 @ 0099bb08

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0099bb08(int *param_1)

{
  uint uVar1;
  int in_r12;
  undefined *puVar2;
  
  if ((in_r12 == 0) && (uVar1 = param_1[1] - 0x17, uVar1 < 0x30)) {
    if (_DAT_00001bc4 == 4) {
      puVar2 = &DAT_009ec760;
    }
    else {
      puVar2 = &DAT_009ec6a0;
    }
    *(int *)(puVar2 + uVar1 * 4) = *(int *)(puVar2 + uVar1 * 4) + 1;
  }
  FUN_00982520();
  if (*param_1 != 0) {
    return;
  }
  if ((uint)param_1[1] < 0x17) {
    return;
  }
  _DAT_009edea0 = FUN_0098a868(&UNK_009ede50,param_1[1] == 0x17);
  return;
}


// ===== FUN_0099bb90 @ 0099bb90

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0099bb90(undefined4 param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  
  if (_DAT_009eca44 != 0) {
    FUN_009a4328(&UNK_009f0080);
    _DAT_009eca44 = 0;
  }
  uVar2 = *(uint *)(param_2 + 8);
  if (((uVar2 == 0) || ((uVar2 & 3) != 0)) || (iVar1 = FUN_009a3f6c(&UNK_009f0080), iVar1 != 0)) {
    _DAT_009ec914 = _DAT_009ec914 + 1;
                    /* WARNING: Read-only address (ram,0x009faa90) is written */
                    /* WARNING: Read-only address (ram,0x009faa94) is written */
    return 0xffffffff;
  }
  if (*(int *)(param_2 + 0x7c) == -0x7a64a8) {
    _DAT_009ec908 = *(uint *)(uVar2 + 0x14) & 0xffff | *(int *)(uVar2 + 0x10) << 0x10;
    *(undefined4 *)(uVar2 + 0x10) = 0;
    _DAT_009ec90c = *(uint *)(uVar2 + 0x1c) & 0xffff | *(int *)(uVar2 + 0x18) << 0x10;
    *(undefined4 *)(uVar2 + 0x14) = 0;
    *(undefined4 *)(uVar2 + 0x18) = _DAT_009faa90;
    *(undefined4 *)(uVar2 + 0x1c) = _DAT_009faa94;
    _DAT_009ec904 = _DAT_009ec904 + 1;
  }
  _DAT_009eca34 = *(undefined4 *)(param_2 + 0x7c);
  _DAT_009eca44 = param_2;
  *(code **)(param_2 + 0x7c) = FUN_0099caac;
  *(undefined1 **)(uVar2 + 0x20) = &LAB_009a4324;
  *(undefined **)(uVar2 + 0x24) = &UNK_009f0080;
  DAT_009b4a78 = 2;
  _DAT_009ecd2c = 0;
  _DAT_009ecd30 = 0;
  FUN_0099ac40();
  _DAT_009eca30 = FUN_0099aba0();
  _DAT_009eca30 = _DAT_009eca30 + 0x9c4;
  _DAT_009ec910 = _DAT_009ec910 + 1;
  (*(code *)&SUB_ff86eb28)();
  _DAT_009ec900 = _DAT_009ec900 + 1;
  return 0;
}


// ===== FUN_0099bd2c @ 0099bd2c

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0099bd2c(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint *puVar4;
  uint *puVar5;
  undefined8 uVar6;
  
  uVar6 = FUN_0099ab08();
  iVar3 = (int)((ulonglong)uVar6 >> 0x20);
  if ((int)uVar6 == 0) {
    return;
  }
  iVar1 = FUN_0099af90(param_1);
  iVar2 = _DAT_009ea628;
  if (iVar1 == iVar3) {
    return;
  }
  if (iVar3 == 0) {
    _DAT_009ea628 = _DAT_009ea628 + -1;
    iVar3 = FUN_0099af54(param_1);
    *(undefined4 *)(&DAT_009ea640 + (iVar3 + 2) * 4) =
         *(undefined4 *)(&DAT_009ea640 + (iVar2 + 1) * 4);
  }
  else {
    if (_DAT_009ea628 == 0x800) {
      iVar2 = 0;
      iVar3 = 1;
      puVar5 = (uint *)&DAT_009ea64c;
      do {
        puVar4 = (uint *)(&DAT_009ea640 + (iVar2 + 2) * 4);
        if (*puVar5 < *(uint *)(&DAT_009ea640 + (iVar2 + 2) * 4)) {
          puVar4 = puVar5;
          iVar2 = iVar3;
        }
        iVar3 = iVar3 + 1;
        puVar5 = puVar5 + 1;
      } while (iVar3 != 0x800);
      _DAT_009ea628 = 0x7ff;
      *puVar4 = _DAT_009ec644;
      _DAT_009ea61c = _DAT_009ea61c + 1;
    }
    iVar3 = _DAT_009ea628 + 2;
    _DAT_009ea628 = _DAT_009ea628 + 1;
    *(undefined4 *)(&DAT_009ea640 + iVar3 * 4) = param_1;
  }
  _DAT_009ea624 = 1;
  return;
}


// ===== FUN_0099be28 @ 0099be28

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0099be28(int *param_1)

{
  uint uVar1;
  int iVar2;
  
  _DAT_009e9968 = _DAT_009e9968 + 1;
  uVar1 = FUN_0099b128(0x2010002);
  if (9999 < uVar1) {
    _DAT_009e9964 = _DAT_009e9964 + 1;
    return 0;
  }
  iVar2 = FUN_0099b128(0x2010000);
  if (899 < iVar2 - 100U) {
    iVar2 = 100;
    _DAT_009e9960 = _DAT_009e9960 + 1;
  }
  *param_1 = iVar2 * 10000 + uVar1;
  return 1;
}


// ===== FUN_0099be2c @ 0099be2c

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0099be2c(int *param_1,undefined4 param_2,int *param_3)

{
  uint uVar1;
  int iVar2;
  
  *param_3 = *param_3 + 1;
  uVar1 = FUN_0099b128(0x2010002);
  if (9999 < uVar1) {
    _DAT_009e9964 = _DAT_009e9964 + 1;
    return 0;
  }
  iVar2 = FUN_0099b128(0x2010000);
  if (899 < iVar2 - 100U) {
    iVar2 = 100;
    _DAT_009e9960 = _DAT_009e9960 + 1;
  }
  *param_1 = iVar2 * 10000 + uVar1;
  return 1;
}


// ===== FUN_0099bed0 @ 0099bed0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0099bed0(undefined4 param_1,undefined4 param_2,int *param_3,uint *param_4)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  
  iVar4 = *param_3;
  for (uVar2 = *param_4; _DAT_009ecce4 != uVar2; uVar2 = uVar2 + 1) {
    if (*(int *)(&UNK_009ecce8 + (uVar2 & 7) * 4) == iVar4) {
      return 1;
    }
  }
  iVar1 = FUN_0099afc4();
  if ((iVar1 == 0) && (_DAT_009eca40 == 0)) {
    if ((_DAT_009e9708 == 0) || (iVar1 = FUN_0099b0e4(iVar4), iVar1 != 0)) {
      return 0;
    }
    if (_DAT_009e9700 == _DAT_009eccc0) {
      piVar3 = (int *)&DAT_009ecdb0;
      iVar1 = 0;
      while( true ) {
        if (iVar1 == _DAT_009ecdac) {
          return 0;
        }
        if (iVar4 != *piVar3) break;
        piVar3 = piVar3 + 1;
        iVar1 = iVar1 + 1;
      }
    }
  }
  return 1;
}


// ===== FUN_0099bfc0 @ 0099bfc0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0099bfc0(void)

{
  int iVar1;
  int *piVar2;
  
  if ((_DAT_009eca44 == 0) || (_DAT_009ede84 != 0)) {
    if (_DAT_009eca38 == 0) {
      return;
    }
    if (_DAT_009eca44 != 0) {
      return;
    }
  }
  else {
    FUN_009a4328(&UNK_009f0080);
    _DAT_009eca44 = 0;
    _DAT_009eca40 = 0;
    _DAT_009eca38 = 1;
  }
  if (_DAT_009ecd20 != _DAT_009ecd1c) {
    return;
  }
  if (DAT_009b4a74 != 2) {
    return;
  }
  iVar1 = 0;
  _DAT_009eca38 = 0;
  piVar2 = (int *)&DAT_009ecd34;
  while( true ) {
    if (*piVar2 != 0) {
      (*(code *)&SUB_ffb2a5b0)();
    }
    *piVar2 = 0;
    *(undefined4 *)(&DAT_009ecd2c + iVar1 * 4) = 0;
    if (iVar1 == 1) break;
    iVar1 = 1;
    piVar2 = piVar2 + 1;
  }
  DAT_009b4a78 = 2;
  return;
}


// ===== FUN_0099c0cc @ 0099c0cc

undefined4 FUN_0099c0cc(int param_1)

{
  undefined4 uVar1;
  bool in_ZR;
  bool in_CY;
  
  if ((!in_CY || in_ZR) && ((&DAT_009ec660)[param_1] != -1)) {
    (&DAT_009ec660)[param_1] = (&DAT_009ec660)[param_1] + '\x01';
  }
  uVar1 = FUN_0098af4c(&UNK_009ede50);
  FUN_0099bfc0();
  return uVar1;
}


// ===== FUN_0099c108 @ 0099c108

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0099c108(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int *piVar5;
  undefined4 uVar6;
  
  if ((((_DAT_0000f1d0 == 0) || ((_DAT_0000f1d0 & 3) != 0)) ||
      (uVar3 = *(uint *)(_DAT_0000f1d0 + 4), uVar3 == 0)) || ((uVar3 & 3) != 0)) {
    uVar3 = 0;
    uVar6 = 0;
  }
  else {
    uVar6 = *(undefined4 *)(uVar3 + 0x7c);
  }
  if (_DAT_009eca44 != 0) {
    iVar4 = 0x21;
    uVar2 = _DAT_0000f1d0;
    while (((uVar2 != 0 && ((uVar2 & 3) == 0)) && (iVar4 = iVar4 + -1, iVar4 != 0))) {
      if (_DAT_009eca44 == *(int *)(uVar2 + 4)) {
        uVar1 = 1;
        goto LAB_0099c16c;
      }
      uVar2 = *(uint *)(uVar2 + 8);
    }
  }
  uVar1 = 0;
LAB_0099c16c:
  FUN_0098b11c(&UNK_009ede50,_DAT_00001bc4,_DAT_00001bc8,uVar3,uVar6,uVar1,param_3);
  if ((_DAT_009eca44 == 0) || (_DAT_009ede84 != 0)) {
    if (_DAT_009eca38 == 0) {
      return;
    }
    if (_DAT_009eca44 != 0) {
      return;
    }
  }
  else {
    FUN_009a4328(&UNK_009f0080);
    _DAT_009eca44 = 0;
    _DAT_009eca40 = 0;
    _DAT_009eca38 = 1;
  }
  if (_DAT_009ecd20 != _DAT_009ecd1c) {
    return;
  }
  if (DAT_009b4a74 != 2) {
    return;
  }
  iVar4 = 0;
  _DAT_009eca38 = 0;
  piVar5 = (int *)&DAT_009ecd34;
  while( true ) {
    if (*piVar5 != 0) {
      (*(code *)&SUB_ffb2a5b0)();
    }
    *piVar5 = 0;
    *(undefined4 *)(&DAT_009ecd2c + iVar4 * 4) = 0;
    if (iVar4 == 1) break;
    iVar4 = 1;
    piVar5 = piVar5 + 1;
  }
  DAT_009b4a78 = 2;
  return;
}


// ===== FUN_0099c1d0 @ 0099c1d0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0099c1d0(char param_1)

{
  int iVar1;
  bool bVar2;
  uint uVar3;
  int *piVar4;
  int iVar5;
  undefined4 local_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 local_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 local_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  
  FUN_0099c108();
  iVar1 = _DAT_009ecc70;
  uVar3 = DAT_009b4a74;
  if (((DAT_009b4a74 != 2) && (_DAT_009ecc6c == _DAT_009ecc74)) && (_DAT_009ecc70 != 0)) {
    _DAT_009ecc70 = 0;
    *(int *)(&DAT_009ecd2c + DAT_009b4a74 * 4) = iVar1;
    if ((iVar1 == _DAT_009ecc8c) && (_DAT_009eca44 != 0)) {
      FUN_0099acfc(uVar3);
      FUN_0098bde4(&UNK_009ede50,iVar1,uVar3 == DAT_009b4a78);
    }
  }
  iVar1 = _DAT_009ecc64;
  if ((DAT_009b4a74 != 2) && (_DAT_009ecc78 == _DAT_009ecc74)) {
    DAT_009b4a74 = 2;
    _DAT_009ecc68 = 0;
    if ((_DAT_009ecc64 != 0) &&
       ((_DAT_009ecc64 = 0, iVar1 == _DAT_009ecc8c && (_DAT_009eca44 != 0)))) {
      FUN_0099b53c();
    }
  }
  iVar1 = _DAT_009ecc84;
  if (_DAT_009ecc84 != _DAT_009ecc80) {
    if ((((_DAT_009eca44 == 0) || (_DAT_009ecd34 == 0)) || (_DAT_009ecd38 == 0)) ||
       (DAT_009b4a74 != 2)) {
      uVar3 = 2;
    }
    else {
      uVar3 = (uint)(DAT_009b4a78 == 0);
      if (((_DAT_009ecd20 == _DAT_009ecd1c) || (uVar3 != _DAT_009ecd24)) &&
         (iVar5 = FUN_0099aba0(), 0x5db < iVar5 - _DAT_009ecc60)) {
        _DAT_009ecc74 = iVar1;
        DAT_009b4a74 = uVar3;
        *(undefined4 *)(&DAT_009ecd2c + uVar3 * 4) = 0;
        _DAT_009ecc68 = 0;
        _DAT_009ecc5c = _DAT_009ecc5c + 1;
      }
      else {
        uVar3 = 3;
      }
    }
    _DAT_009ecc80 = iVar1;
    _DAT_009ecc7c = uVar3;
  }
  if (param_1 == '\x01') {
    if (((_DAT_009eca40 != 0) && (iVar1 = FUN_0099ac40(), iVar1 != 0)) && (_DAT_009ecc8c != 0)) {
      FUN_0099b53c(0);
    }
    if (((_DAT_009eca44 == 0) || (_DAT_009eca30 == 0)) ||
       (iVar1 = FUN_0099aba0(), -1 < iVar1 - _DAT_009eca30)) {
      _DAT_009eca30 = 0;
    }
    else if ((DAT_009b4a78 < 2) && (*(int *)(&DAT_009ecd2c + DAT_009b4a78 * 4) != 0)) {
      FUN_0099acfc(DAT_009b4a78);
    }
    FUN_0098be60(&UNK_009ede50);
  }
  if (_DAT_009ec64c != _DAT_009ecd0c) {
    _DAT_009ec64c = _DAT_009ecd0c;
    if (_DAT_009ece34 != 0) {
      FUN_0098aee4(&UNK_009ede50,&DAT_009ece48,_DAT_009ece38);
      FUN_0098b588(&UNK_009ede50,&DAT_009ecdb0,_DAT_009ecdac);
      _DAT_009ece30 = _DAT_009ec64c;
    }
    _DAT_009edea4 = FUN_0099b714(DAT_009b4a7c);
    DAT_009edeac = 0;
    _DAT_009edea8 = _DAT_009edea4;
  }
  if (_DAT_009ec848 != _DAT_009ec854) {
    _DAT_009ec848 = _DAT_009ec854;
    FUN_0098b2d8(&DAT_009b4a64,&UNK_009ec8ad,&UNK_009ec8a9,&DAT_009b1d80,&DAT_009ec858,
                 _DAT_009edea8 & 0xff);
    _DAT_009ec844 = DAT_009b4a68;
    FUN_0098ae94(&UNK_009ede50,&DAT_009b4a64);
    FUN_0098ae84(&UNK_009ede50);
  }
  if (((_DAT_009ec850 != 0) && (_DAT_009eeec4 != 0)) &&
     ((_DAT_009ec84c == 0 && _DAT_009ede84 == 0 && (_DAT_00001bc4 == 0)))) {
    _DAT_009ec84c = 1;
    FUN_0098af4c(&UNK_009ede50,4);
  }
  while (_DAT_009ec65c != _DAT_009ecd68) {
    iVar1 = (_DAT_009ec65c & 7) * 8;
    _DAT_009ec65c = _DAT_009ec65c + 1;
    FUN_0098b374(&UNK_009ede50,*(undefined4 *)(&UNK_009ecd6c + iVar1),
                 *(undefined4 *)(&UNK_009ecd70 + iVar1));
  }
  while (_DAT_009ec658 != _DAT_009ecc9c) {
    uVar3 = _DAT_009ec658 & 7;
    _DAT_009ec658 = _DAT_009ec658 + 1;
    FUN_0098b5cc(&UNK_009ede50,*(undefined4 *)(&UNK_009ecca0 + uVar3 * 4));
  }
  if (_DAT_009ec654 != _DAT_009ecd08) {
    _DAT_009ec654 = _DAT_009ecd08;
    local_44 = _DAT_009ecd3c;
    uStack_40 = _DAT_009ecd40;
    uStack_3c = _DAT_009ecd44;
    uStack_38 = _DAT_009ecd48;
    local_34 = _DAT_009ecd4c;
    uStack_30 = _DAT_009ecd50;
    uStack_2c = _DAT_009ecd54;
    uStack_28 = _DAT_009ecd58;
    local_24 = _DAT_009ecd5c;
    uStack_20 = _DAT_009ecd60;
    uStack_1c = _DAT_009ecd64;
    FUN_0098bd60(&UNK_009ede50,&local_44);
  }
  if ((_DAT_009ec830 != _DAT_009ec834) && (_DAT_009ec830 = _DAT_009ec834, _DAT_009ec838 == 0)) {
    FUN_0098b574(&UNK_009ede50,DAT_009b4a60);
  }
  if (_DAT_009ec824 != _DAT_009ec828) {
    _DAT_009ec824 = _DAT_009ec828;
    if (_DAT_009ec82c == _DAT_009ecd2c) {
      _DAT_009ecd2c = 0;
    }
    if (_DAT_009ec82c == _DAT_009ecd30) {
      _DAT_009ecd30 = 0;
    }
    if (_DAT_009ecc8c == _DAT_009ec82c) {
      _DAT_009ec820 = _DAT_009ec820 + 1;
      FUN_0099b53c(0);
    }
  }
  iVar1 = _DAT_009ecd18;
  if ((_DAT_009ec650 != _DAT_009ecd1c) && (_DAT_009ecd1c == _DAT_009ecd20)) {
    _DAT_009ec650 = _DAT_009ecd1c;
    if ((_DAT_009ecd14 == 0) || (_DAT_009ecd28 != _DAT_009ecd18)) {
      iVar5 = 0;
    }
    else {
      iVar5 = 1;
      *(int *)(&DAT_009ecd2c + _DAT_009ecd24 * 4) = _DAT_009ecd18;
    }
    FUN_0099abc8(4,iVar1,iVar5,_DAT_009ecc8c == iVar1);
    if ((_DAT_009ecc8c == iVar1) && (_DAT_009eca44 != 0)) {
      bVar2 = false;
      if (iVar5 != 0) {
        FUN_0099acfc(_DAT_009ecd24);
        if (DAT_009b4a78 < 2) {
          bVar2 = *(int *)(&DAT_009ecd2c + DAT_009b4a78 * 4) == iVar1;
        }
        else {
          bVar2 = false;
        }
      }
      FUN_0098bde4(&UNK_009ede50,iVar1,bVar2);
      FUN_0099abc8(7,iVar1,iVar5,_DAT_009eeec8 == iVar1);
    }
    else {
      _DAT_009ecc88 = _DAT_009ecc88 + 1;
    }
  }
  iVar1 = _DAT_009ecc98;
  uVar3 = _DAT_009ecc94;
  if (_DAT_009ecc98 != 0) {
    _DAT_009ecc98 = 0;
    if ((iVar1 == _DAT_009ecc8c) && (_DAT_009eca44 != 0)) {
      bVar2 = iVar1 == *(int *)(&DAT_009ecd2c + _DAT_009ecc94 * 4);
    }
    else {
      bVar2 = false;
    }
    FUN_0099abc8(5,iVar1,_DAT_009ecc94,bVar2);
    if (((iVar1 == _DAT_009ecc8c) && (_DAT_009eca44 != 0)) &&
       (iVar1 == *(int *)(&DAT_009ecd2c + uVar3 * 4))) {
      FUN_0099acfc(uVar3);
      _DAT_009ecc90 = _DAT_009ecc90 + 1;
      FUN_0098bde4(&UNK_009ede50,iVar1,DAT_009b4a78 == uVar3);
      FUN_0099abc8(7,iVar1,DAT_009b4a78 == uVar3,_DAT_009eeec8 == iVar1);
    }
  }
  if ((_DAT_009eca44 == 0) || (_DAT_009ede84 != 0)) {
    if (_DAT_009eca38 == 0) {
      return;
    }
    if (_DAT_009eca44 != 0) {
      return;
    }
  }
  else {
    FUN_009a4328(&UNK_009f0080);
    _DAT_009eca44 = 0;
    _DAT_009eca40 = 0;
    _DAT_009eca38 = 1;
  }
  if (_DAT_009ecd20 != _DAT_009ecd1c) {
    return;
  }
  if (DAT_009b4a74 != 2) {
    return;
  }
  iVar1 = 0;
  _DAT_009eca38 = 0;
  piVar4 = (int *)&DAT_009ecd34;
  while( true ) {
    if (*piVar4 != 0) {
      (*(code *)&SUB_ffb2a5b0)();
    }
    *piVar4 = 0;
    *(undefined4 *)(&DAT_009ecd2c + iVar1 * 4) = 0;
    if (iVar1 == 1) break;
    iVar1 = 1;
    piVar4 = piVar4 + 1;
  }
  DAT_009b4a78 = 2;
  return;
}


// ===== FUN_0099caac @ 0099caac

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0099caac(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  code *UNRECOVERED_JUMPTABLE;
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  
  uVar1 = FUN_0098a5f4();
  _DAT_009ec924 = _DAT_009ec924 + 1;
  uVar3 = _DAT_009ec92c & 0x1f;
  _DAT_009ec92c = _DAT_009ec92c + 1;
  *(undefined4 *)(&DAT_009ec910 + (uVar3 + 8) * 4) = param_3;
  *(undefined4 *)(&DAT_009ec910 + (uVar3 + 0x28) * 4) = _DAT_00001bc4;
  UNRECOVERED_JUMPTABLE = _DAT_009eca34;
  iVar2 = FUN_0098b6b4(&UNK_009ede50,param_3);
  FUN_0099bfc0();
  FUN_0098a644(uVar1);
  if (UNRECOVERED_JUMPTABLE == (code *)0x0 || iVar2 == 0) {
    return 0;
  }
  _DAT_009ec928 = _DAT_009ec928 + 1;
                    /* WARNING: Could not recover jumptable at 0x0099cb60. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (*UNRECOVERED_JUMPTABLE)(param_1,param_2,param_3,param_4);
  return uVar1;
}


// ===== FUN_0099cb7c @ 0099cb7c

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0099cb7c(void)

{
  undefined4 *puVar1;
  uint uVar2;
  
  puVar1 = (undefined4 *)&DAT_009e85a8;
  for (uVar2 = 1; uVar2 < _DAT_009e7584; uVar2 = uVar2 + 1) {
    puVar1[1] = puVar1[3];
    *puVar1 = puVar1[2];
    puVar1 = puVar1 + 2;
  }
  _DAT_009e7584 = _DAT_009e7584 - 1;
  if (_DAT_009e7580 != 0) {
    _DAT_009e7580 = _DAT_009e7580 + -1;
  }
  return;
}


// ===== FUN_0099cbd8 @ 0099cbd8

/* WARNING: Removing unreachable block (ram,0x0098a94c) */

uint FUN_0099cbd8(undefined4 param_1,ushort param_2)

{
  uint uVar1;
  undefined1 extraout_r1;
  int iVar2;
  uint uVar3;
  undefined *puVar4;
  uint uVar5;
  uint uVar6;
  undefined8 uVar7;
  byte bVar8;
  byte bVar9;
  undefined2 uVar10;
  undefined4 uVar11;
  
  uVar1 = param_2 >> 4 & 0x3f;
  bVar8 = (byte)((uint)param_1 >> 0x19);
  uVar10 = CONCAT11(((byte)param_2 & 0xf) - 6,bVar8);
  uVar5 = CONCAT22((short)(CONCAT13(5,(uint3)((byte)(param_2 >> 4) & 0xf) << 0x10) >> 0x10),uVar10);
  puVar4 = (undefined *)0x0;
  if (bVar8 < 0x51 && 0xf < uVar1) {
    iVar2 = (uint)bVar8 * 0xc;
    puVar4 = &DAT_009b1ddc + iVar2;
    if (*(ushort *)(&DAT_009b1de0 + iVar2) != 0) {
      uVar5 = 0;
      do {
        if (((int)(uint)*(ushort *)(&DAT_009b1de0 + iVar2) >> (uVar5 & 0xff) & 1U) != 0) break;
        uVar5 = uVar5 + 1;
      } while (uVar5 != 0xd);
      uVar1 = uVar1 - 0x10;
      puVar4 = (undefined *)(uVar5 + uVar1 / 0xc);
      uVar11 = CONCAT13(5,CONCAT12((char)puVar4,uVar10));
      FUN_009a5e2c(uVar1,0xc,uVar1 * -0x55555555);
      uVar5 = CONCAT13(extraout_r1,(int3)uVar11);
    }
  }
  uVar1 = uVar5 & 0xff;
  if (0x50 < uVar1) {
    return 0x5000000;
  }
  iVar2 = uVar1 * 0xc;
  uVar6 = (uint)(char)(uVar5 >> 8);
  bVar8 = (byte)(uVar5 >> 0x10);
  uVar3 = (int)(char)(&DAT_009b1ddc)[iVar2];
  if ((int)(char)(&DAT_009b1ddc)[iVar2] < (int)uVar6) {
    uVar3 = uVar6;
  }
  bVar9 = (byte)(uVar5 >> 0x18);
  if ((int)(char)(&UNK_009b1ddd)[iVar2] <= (int)uVar3) {
    uVar3 = (int)(char)(&UNK_009b1ddd)[iVar2];
  }
  uVar3 = uVar3 & 0xff;
  if ((byte)(&DAT_009b1dde)[iVar2] <= bVar8) {
    bVar8 = (&UNK_009b1ddf)[iVar2];
  }
  uVar7 = FUN_0098a850(&DAT_009b1ddc + iVar2,bVar8,uVar1,uVar3,&DAT_009b1ddc,uVar5,uVar5,puVar4);
  uVar5 = (uint)uVar7 ^ 1;
  if (0xb < bVar9) {
    uVar5 = uVar5 | 1;
  }
  if ((uVar5 & 1) != 0) {
    bVar9 = 5;
  }
  return uVar1 | uVar3 << 8 | (int)((ulonglong)uVar7 >> 0x20) << 0x10 | (uint)bVar9 << 0x18;
}


// ===== FUN_0099ccac @ 0099ccac

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0099ccac(undefined4 param_1)

{
  byte *pbVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  
  _DAT_009ef060 = 0;
  FUN_0099a998("stage",param_1);
  FUN_0099a998("saves_create",_DAT_009ef050);
  FUN_0099a998("saves_open",_DAT_009ef054);
  FUN_0099a998("task_result",_DAT_009fabf0);
  FUN_0099a998("task_priority",0x11);
  FUN_0099a998("outcome",_DAT_009fac04);
  FUN_0099a998("gui_facts",_DAT_009fabf4);
  FUN_0099a998("gui_samples",_DAT_009fabf8);
  FUN_0099a998("display_result",_DAT_009fabfc);
  FUN_0099a998("unavailable_reasons",_DAT_009fabe8);
  FUN_0099a998("preparation_status",_DAT_009fabc8);
  FUN_0099a998("manager_semaphore",_DAT_009fab9c);
  FUN_0099a998("gui_semaphore",_DAT_009fabcc);
  FUN_0099a998("gui_queue",_DAT_009fabd0);
  FUN_0099a998("bitmap_initialized",_DAT_009fabd4);
  FUN_0099a998("power_permission",_DAT_009fabd8);
  FUN_0099a998("lock_permission",_DAT_009fabdc);
  FUN_0099a998("display_type",_DAT_009fabe0);
  FUN_0099a998("y_scale",_DAT_009fabe4);
  FUN_0099a998("interlace",_DAT_009faba0);
  FUN_0099a998("palette",_DAT_009fab90);
  FUN_0099a998("foreground",_DAT_009fab94);
  FUN_0099a998("background",_DAT_009fab98);
  FUN_0099a998("prepared",_DAT_009faba4);
  FUN_0099a998("display_requested",_DAT_009faba8);
  FUN_0099a998("stale_display",_DAT_009fabac);
  FUN_0099a998("paint_native_status",_DAT_009fabb0);
  FUN_0099a998("release_attempts",_DAT_009fabc0);
  FUN_0099a998("window",_DAT_009fab0c);
  FUN_0099a998("window_state",DAT_009fab10);
  FUN_0099a998("window_state_during_page",_DAT_009fac00);
  FUN_0099a998("paints",_DAT_009fab1c);
  FUN_0099a998("paint_errors",_DAT_009fab20);
  FUN_0099a998("paint_status",_DAT_009fab24);
  FUN_0099a998("native_status",_DAT_009fab28);
  FUN_0099a998("owner_acquired",DAT_009fab2c);
  FUN_0099a998("page_unavailable",_DAT_009faae0);
  FUN_0099a998("page_screen_width",_DAT_009faa88);
  FUN_0099a998("page_screen_height",_DAT_009faa8c);
  FUN_0099a998("page_interlace",_DAT_009faa84);
  FUN_0099a998("page_width",_DAT_009faa90);
  FUN_0099a998("page_height",_DAT_009faa94);
  FUN_0099a998("page_vertical_scale",_DAT_009faa98);
  FUN_0099a998("page_palette_changes",_DAT_009faaa4);
  FUN_0099a998("page_ink_failures",_DAT_009faaa8);
  FUN_0099a998("page_col_repeat",_DAT_009faa9c);
  FUN_0099a998("page_raises",_DAT_009faaa0);
  FUN_0099a998("page_window_state",DAT_009f00ac);
  FUN_0099a998("page_window_paints",_DAT_009f00b8);
  FUN_0099a998("page_window_paint_errors",_DAT_009f00bc);
  FUN_0099a998("page_window_native_status",_DAT_009f00c4);
  FUN_0099a998("page_paints",_DAT_009faac0);
  FUN_0099a998("page_paint_calls",_DAT_009faac4);
  FUN_0099a998("page_paint_errors",_DAT_009faac8);
  FUN_0099a998("page_first_paint_status",_DAT_009faad0);
  FUN_0099a998("page_stale",_DAT_009faad4);
  FUN_0099a998("page_release_attempts",_DAT_009faad8);
  FUN_0099a998("page_release_failures",_DAT_009faadc);
  uVar3 = 0;
  uVar2 = 0;
  pbVar1 = &UNK_009faa67;
  do {
    pbVar1 = pbVar1 + 1;
    uVar2 = uVar2 | (*pbVar1 & 0xf) << (uVar3 & 0xff);
    uVar3 = uVar3 + 4;
  } while (uVar3 != 0x2c);
  FUN_0099a998("page_inks_clear_bg_panel_rule_dim_text_accent",uVar2);
  uVar3 = 0;
  uVar2 = 0;
  pbVar1 = &DAT_009faa72;
  do {
    pbVar1 = pbVar1 + 1;
    uVar2 = uVar2 | (*pbVar1 & 0xf) << (uVar3 & 0xff);
    uVar3 = uVar3 + 4;
  } while (uVar3 != 0x2c);
  FUN_0099a998("page_first_inks",uVar2);
  iVar4 = 0;
  pbVar1 = &DAT_009fa9a0;
  do {
    iVar4 = iVar4 + 1;
    FUN_0099a998("palette_aYUV",
                 (uint)pbVar1[1] << 0x10 | (uint)*pbVar1 << 0x18 | (uint)pbVar1[3] |
                 (uint)pbVar1[2] << 8);
    pbVar1 = pbVar1 + 4;
  } while (iVar4 != 0x10);
  FUN_0099a998("mem_F3E0_manager_flag",_DAT_0000f3e0);
  FUN_0099a998("mem_FE30_bitmap",_DAT_0000fe30);
  FUN_0099a998("mem_4AC0_power",DAT_00004ac0);
  iVar4 = FUN_00982c98("A:/LATENT1.LOG",&UNK_009ef080,_DAT_009ef060);
  if (iVar4 == 0) {
    _DAT_009ef050 = _DAT_009ef050 + 1;
  }
  return;
}


// ===== FUN_0099d198 @ 0099d198

void FUN_0099d198(undefined4 param_1,uint param_2,int param_3)

{
  undefined4 uVar1;
  char *pcVar2;
  char *pcVar3;
  
  uVar1 = FUN_0099aab4(param_1,"A:/DCIM/");
  uVar1 = FUN_0099ab58(uVar1,param_2 / 10000,3,param_2 * -0x2e48e8a7);
  uVar1 = FUN_0099aab4(uVar1,"EOS5D/");
  uVar1 = FUN_0099aab4(uVar1,&DAT_009a6fd0);
  pcVar2 = (char *)FUN_0099ab58(uVar1,param_2 % 10000,4);
  pcVar3 = (char *)(param_3 + -1);
  while( true ) {
    pcVar3 = pcVar3 + 1;
    if (*pcVar3 == '\0') break;
    *pcVar2 = *pcVar3;
    pcVar2 = pcVar2 + 1;
  }
  *pcVar2 = '\0';
  return;
}


// ===== FUN_0099d208 @ 0099d208

void FUN_0099d208(undefined4 param_1,uint param_2)

{
  undefined4 uVar1;
  char *pcVar2;
  char *pcVar3;
  
  uVar1 = FUN_0099aab4(param_1,"A:/DCIM/");
  uVar1 = FUN_0099ab58(uVar1,param_2 / 10000,3,param_2 * -0x2e48e8a7);
  uVar1 = FUN_0099aab4(uVar1,"EOS5D/");
  uVar1 = FUN_0099aab4(uVar1,&DAT_009a6fd0);
  pcVar2 = (char *)FUN_0099ab58(uVar1,param_2 % 10000,4);
  pcVar3 = "";
  while( true ) {
    pcVar3 = pcVar3 + 1;
    if (*pcVar3 == '\0') break;
    *pcVar2 = *pcVar3;
    pcVar2 = pcVar2 + 1;
  }
  *pcVar2 = '\0';
  return;
}


// ===== FUN_0099d214 @ 0099d214

undefined4 FUN_0099d214(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 auStack_30 [40];
  
  FUN_0099d208(auStack_30,param_1);
  iVar1 = FUN_00982bd8(auStack_30);
  if (iVar1 == 0) {
    FUN_0099d198(auStack_30,param_1,&LAB_009a6fda);
    uVar2 = FUN_00982bd8(auStack_30);
  }
  else {
    uVar2 = 1;
  }
  return uVar2;
}


// ===== FUN_0099d264 @ 0099d264

void FUN_0099d264(undefined4 param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  char *pcVar2;
  char *pcVar3;
  
  uVar1 = FUN_0099aab4(param_1,"A:/LATENT/");
  pcVar2 = (char *)FUN_0099ab58(uVar1,param_2,7);
  pcVar3 = (char *)(param_3 + -1);
  while( true ) {
    pcVar3 = pcVar3 + 1;
    if (*pcVar3 == '\0') break;
    *pcVar2 = *pcVar3;
    pcVar2 = pcVar2 + 1;
  }
  *pcVar2 = '\0';
  return;
}


// ===== FUN_0099d294 @ 0099d294

/* WARNING: Heritage AFTER dead removal. Example location: r0x009e756c : 0x0099d364 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Restarted to delay deadcode elimination for space: ram */

void FUN_0099d294(int param_1)

{
  short sVar1;
  byte *pbVar2;
  int iVar3;
  char *pcVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  short *psVar9;
  undefined4 *puVar10;
  uint uVar11;
  undefined4 *puVar12;
  int *piVar13;
  uint *puVar14;
  int *piVar15;
  uint *puVar16;
  char cVar17;
  uint local_8c;
  undefined1 auStack_88 [32];
  undefined1 auStack_68 [32];
  uint local_48 [9];
  
  if (param_1 != 0) {
    pcVar4 = "J.LOG";
    if (_DAT_009e756c != 2) {
      pcVar4 = ".LOG";
    }
    FUN_0099d264(auStack_88,param_1,pcVar4);
  }
  FUN_0099ae24(auStack_68,"A:/LATENT/R",_DAT_009ea410,".LOG");
  if (param_1 == 0) {
    _DAT_009e750c = -1;
  }
  else {
    _DAT_009e750c = FUN_009828c0(auStack_88);
  }
  _DAT_009e7510 = FUN_009828c0(auStack_68);
  if ((_DAT_009e7510 < 0) || ((param_1 != 0 && (_DAT_009e750c < 0)))) {
    _DAT_009e7508 = _DAT_009e7508 + 1;
  }
  _DAT_009ef060 = 0;
  _DAT_009ef05c = FUN_0099ba3c;
  FUN_0099a998("frame",param_1);
  iVar3 = 0;
  if (param_1 != 0) {
    iVar3 = _DAT_009e756c;
  }
  uVar11 = 0;
  FUN_0099a998("pass_picture_jpeg",iVar3);
  FUN_0099a998("develop_stage",_DAT_009ea268);
  FUN_0099a998("develop_result",_DAT_009ea26c);
  FUN_0099a998("table_loads",_DAT_009ea270);
  FUN_0099a998("grain_loaded",_DAT_009ea274);
  FUN_0099a998("light_mired_q16",_DAT_009ea3e0);
  FUN_0099a998("light_kelvin_outside",_DAT_009ea3e4 | _DAT_009ea3e8 << 0x1f);
  FUN_0099a998("light_steps",_DAT_009ea3ec);
  FUN_0099a998("camera_white_balance",_DAT_009ea3f0);
  FUN_0099a998("pack_loads_table_decodes",_DAT_009ea3f8 | _DAT_009ea3f4 << 0x10);
  FUN_0099a998("table_ms",_DAT_009ea3fc);
  FUN_0099a998("table_steps_stored",_DAT_009ea400);
  FUN_0099a998("cr2_reads",_DAT_009ea27c);
  FUN_0099a998("cr2_seeks",_DAT_009ea280);
  FUN_0099a998("cr2_read_failures",_DAT_009ea284);
  FUN_0099a998("cr2_reads_ahead",_DAT_009ea28c);
  FUN_0099a998("cr2_read_ms_walk_all",(uint)_DAT_009ea290 | _DAT_009ea294 << 0x10);
  FUN_0099a998("read_buffer_size",_DAT_009ea288);
  uVar7 = _DAT_009ea2ec;
  FUN_0099a998("out_wh",_DAT_009ea2ec | _DAT_009ea2e8 << 0x10);
  if (_DAT_009ea300 != 0) {
    uVar7 = _DAT_009ea2fc;
  }
  iVar3 = _DAT_009ea300;
  if (_DAT_009ea300 != 0) {
    iVar3 = _DAT_009ea300 - uVar7;
  }
  FUN_0099a998("ms_to_walked",iVar3);
  iVar3 = _DAT_009ea304;
  if (_DAT_009ea304 != 0) {
    iVar3 = _DAT_009ea304 - _DAT_009ea2fc;
  }
  FUN_0099a998("ms_to_picture",iVar3);
  iVar3 = _DAT_009ea308;
  if (_DAT_009ea308 != 0) {
    iVar3 = _DAT_009ea308 - _DAT_009ea2fc;
  }
  FUN_0099a998("ms_to_done",iVar3);
  FUN_0099a998("decode_ms",_DAT_009ea310);
  FUN_0099a998("pixels_ms",_DAT_009ea314);
  FUN_0099a998("jpeg_ms",_DAT_009ea318);
  FUN_0099a998("walk_visit_ms_hook_ms",(uint)_DAT_009ea324 | _DAT_009ea320 << 0x10);
  FUN_0099a998("walk_rest_ms",_DAT_009ea328);
  FUN_0099a998("jpeg_bytes",_DAT_009ea2f0);
  FUN_0099a998("stood_aside_for_canon_ms",_DAT_009ea31c);
  FUN_0099a998("walk_skipped",_DAT_009ea32c);
  FUN_0099a998("from_memory",_DAT_009ea3d4);
  FUN_0099a998("jpeg_paused",_DAT_009ea330);
  FUN_0099a998("memory_reused",_DAT_009ea3d8);
  FUN_0099a998("jpeg_gave_way",_DAT_009ea3dc);
  FUN_0099a998("hw_dead",_DAT_009e70b8);
  puVar12 = (undefined4 *)&DAT_009e6f78;
  for (; uVar11 < _DAT_009e6f74; uVar11 = uVar11 + 1) {
    FUN_0099a998("hw_call_posted",*puVar12);
    FUN_0099a998("hw_call_answer_status_ms",
                 puVar12[3] & 0xffff | puVar12[1] << 0x1c | (puVar12[2] & 0xfff) << 0x10);
    FUN_0099a998("hw_call_size",puVar12[4]);
    puVar12 = puVar12 + 5;
  }
  FUN_0099a998("hw_frame_calls_waits",_DAT_009ea338 | _DAT_009ea334 << 0x10);
  FUN_0099a998("hw_frame_encode_convert_ms",_DAT_009ea340 | _DAT_009ea33c << 0x10);
  FUN_0099a998("hw_frame_bytes",_DAT_009ea344);
  FUN_0099a998(&DAT_009a7251,_DAT_009ea404);
  FUN_0099a998("halo_ms",_DAT_009ea408);
  FUN_0099a998("halo_pool_kb",_DAT_009ea40c);
  FUN_0099a998("hw_frame_result_status",(uint)_DAT_009ea348 | _DAT_009ea34c << 0x10);
  if (_DAT_009ea350 != 0 || _DAT_009ea354 != 0) {
    FUN_0099a998("bench_65536px_cached_ms");
    FUN_0099a998("bench_65536px_spread_ms",_DAT_009ea354);
    FUN_0099a998("bench_read_1mb_lines_ms",_DAT_009ea358);
    FUN_0099a998("cp15_control",_DAT_009ea360);
    FUN_0099a998("cp15_dcache_bits",_DAT_009ea364);
    FUN_0099a998("cp15_icache_bits",_DAT_009ea368);
    FUN_0099a998("cp15_write_buffer_bits",_DAT_009ea36c);
    iVar3 = 0;
    puVar12 = (undefined4 *)&DAT_009ea36c;
    do {
      puVar12 = puVar12 + 1;
      iVar3 = iVar3 + 1;
      FUN_0099a998("cp15_region",*puVar12);
    } while (iVar3 != 8);
    FUN_0099a998("cp15_cache_type",_DAT_009ea390);
    FUN_0099a998("loop_20m_4cycle_ms",_DAT_009ea394);
    FUN_0099a998("at_code",_DAT_009ea398);
    FUN_0099a998("at_table",_DAT_009ea39c);
    FUN_0099a998("at_log_lut",_DAT_009ea3a0);
    FUN_0099a998("at_read_buffer",_DAT_009ea3a4);
    FUN_0099a998("at_stack",_DAT_009ea3a8);
  }
  FUN_0099a998("card_waits_in_frame",_DAT_009ea3ac);
  FUN_0099a998("card_waited_ms_in_frame",_DAT_009ea3b0);
  local_8c = 0;
  local_48[0] = 0;
  FUN_00985044(&local_8c,local_48);
  FUN_0099a998("pool_free_kb_start_now",local_8c >> 10 | (_DAT_009ea264 >> 10) << 0x10);
  FUN_0099a998("pool_largest_kb_start_now",local_48[0] >> 10 | (_DAT_009ea260 >> 10) << 0x10);
  FUN_0099a998("pool_free_kb_frame_before_during",
               _DAT_009ea3bc >> 10 | (_DAT_009ea3b4 >> 10) << 0x10);
  FUN_0099a998("pool_free_largest_kb_at_jpeg",_DAT_009ea3d0 >> 10 | (_DAT_009ea3cc >> 10) << 0x10);
  FUN_0099a998("pool_largest_kb_frame_before_during",
               _DAT_009ea3c0 >> 10 | (_DAT_009ea3b8 >> 10) << 0x10);
  FUN_0099a998("pool_free_kb_frame_after",_DAT_009ea3c4 >> 10);
  cVar17 = _DAT_009ecd38 != 0;
  if (_DAT_009ecd34 != 0) {
    cVar17 = cVar17 + '\x01';
  }
  FUN_0099a998("picture_buffers_held",cVar17);
  FUN_0099a998("frames_seen",_DAT_009ea25c);
  FUN_0099a998("remove_proven",_DAT_009e96d4);
  FUN_0099a998("shots_seen_found_ready_lost",
               (uint)DAT_009e98b0 | _DAT_009e98bc << 0x18 | (_DAT_009e98b8 & 0xff) << 0x10 |
               (_DAT_009e98b4 & 0xff) << 8);
  FUN_0099a998("memory_pictures_reused_off",
               _DAT_009e98a4 | _DAT_009e98ac << 0x10 | (_DAT_009e98a8 & 0xff) << 8);
  FUN_0099a998("memory_proven_same_differed",_DAT_009e989c & 0xffff | _DAT_009e98a0 << 0x10);
  FUN_0099a998("memory_shown_from_memory",_DAT_009e994c);
  FUN_0099a998("shot_found_ready_ms",_DAT_009e9864 & 0xffff | _DAT_009e9860 << 0x10);
  FUN_0099a998("shot_picture_ms_frame",_DAT_009e986c & 0xffff | _DAT_009e9868 << 0x10);
  FUN_0099a998("shot_counter_looked_for",_DAT_009e9810);
  puVar12 = (undefined4 *)&DAT_009e9818;
  for (uVar7 = 0; uVar7 < _DAT_009e9814; uVar7 = uVar7 + 1) {
    FUN_0099a998("shot_job_passed_at",*puVar12);
    FUN_0099a998("shot_job_passed_id_frame",puVar12[2] & 0xffff | puVar12[1] << 0x10);
    puVar12 = puVar12 + 3;
  }
  FUN_0099a998("tables_let_go",_DAT_009e9898);
  FUN_0099a998("frame_looks_skipped",(uint)_DAT_009e9720 | _DAT_009e9724 << 0x10);
  FUN_0099a998("shots_found_by_looking",_DAT_009e9714);
  FUN_0099a998("steps_stored_read_refused",
               _DAT_009b5988 & 0x3ff | _DAT_009b5990 << 0x14 | (_DAT_009b598c & 0x3ff) << 10);
  FUN_0099a998("shots_passed_up",_DAT_009e9894);
  FUN_0099a998("shots_needing_card",_DAT_009e9884);
  FUN_0099a998("shot_pool_kb_free_largest_passed_up",_DAT_009e9890);
  FUN_0099a998("last_job_at",_DAT_009e98cc);
  FUN_0099a998("jpeg_resumable_rename",_DAT_009b5824 | _DAT_009b5828 << 8);
  FUN_0099a998("jpegs_unfinished_removed",_DAT_009e96d8);
  FUN_0099a998("deletes_done_failed",(uint)_DAT_009e96cc | _DAT_009e96d0 << 0x10);
  FUN_0099a998("canon_deletes_hidden_removed_back",
               (uint)DAT_009e96c0 | _DAT_009e96c8 << 0x10 | (_DAT_009e96c4 & 0xff) << 8);
  FUN_0099a998("deletes_asked_confirmed",_DAT_009eefc4 & 0xffff | _DAT_009eefc0 << 0x10);
  uVar7 = _DAT_009e972c;
  if (_DAT_009e972c < 8) {
    uVar7 = 8;
  }
  for (uVar7 = uVar7 - 8; uVar7 < _DAT_009e972c; uVar7 = uVar7 + 1) {
    iVar3 = (uVar7 & 7) * 0x14;
    uVar11 = *(uint *)(&UNK_009e9734 + iVar3);
    if (0xfffe < *(uint *)(&UNK_009e9734 + iVar3)) {
      uVar11 = 0xffff;
    }
    FUN_0099a998("frame_seen_after_shot_ms",uVar11 | *(int *)(&UNK_009e9730 + iVar3) << 0x10);
    FUN_0099a998("frame_seen_held_by",
                 *(uint *)(&UNK_009e9738 + iVar3) | *(int *)(&UNK_009e9730 + iVar3) << 0x10);
    FUN_0099a998("frame_seen_job_state_rest",
                 *(uint *)(&UNK_009e9740 + iVar3) & 0xffff | *(int *)(&UNK_009e973c + iVar3) << 0x10
                );
  }
  FUN_0099a998("pictures_made",_DAT_009ea258);
  FUN_0099a998("jpegs_made",_DAT_009ea254);
  FUN_0099a998("halo_level",DAT_009b4a60);
  FUN_0099a998("halos_shown",_DAT_009ec820);
  FUN_0099a998("jpegs_gave_way",_DAT_009ea244);
  FUN_0099a998("session",_DAT_009ea410);
  FUN_0099a998("frames_owed",_DAT_009ea628);
  FUN_0099a998("file_number_at_start",_DAT_009e996c);
  piVar13 = (int *)&DAT_009e9e40;
  FUN_0099a998("canon_number_now_followed",_DAT_009e9958 & 0xffff | _DAT_009e995c << 0x10);
  FUN_0099a998("file_number_reads_failures",_DAT_009e9964 & 0xffff | _DAT_009e9968 << 0x10);
  FUN_0099a998("folder_reads_failures_owed_dropped",_DAT_009ea61c & 0xffff | _DAT_009e9960 << 0x10);
  piVar15 = piVar13;
  for (uVar7 = 0; (uVar7 < _DAT_009e9e30 && (uVar7 != 0x40)); uVar7 = uVar7 + 1) {
    FUN_0099a998("film_span",(uint)*(byte *)((int)piVar15 + 10) | *piVar15 << 0x10);
    piVar15 = piVar15 + 4;
  }
  for (uVar7 = 0; (uVar7 < _DAT_009e9e30 && (uVar7 != 0x40)); uVar7 = uVar7 + 1) {
    FUN_0099a998("span_push_paper_grade_roll",
                 (uint)*(byte *)(piVar13 + 3) << 0x10 | (uint)*(byte *)((int)piVar13 + 0xb) << 0x18
                 | (uint)*(byte *)((int)piVar13 + 0xd) << 0xc | *(ushort *)(piVar13 + 2) & 0xfff);
    piVar13 = piVar13 + 4;
  }
  FUN_0099a998("develop_failures",_DAT_009ea250);
  puVar12 = (undefined4 *)&DAT_009ea418;
  for (uVar7 = 0; (uVar7 < _DAT_009ea414 && (uVar7 != 0x40)); uVar7 = uVar7 + 1) {
    FUN_0099a998("frame_set_aside",*puVar12);
    puVar12 = puVar12 + 1;
  }
  FUN_0099a998("pool_short_waits",_DAT_009ea240);
  FUN_0099a998("picture_loads",_DAT_009ea24c);
  FUN_0099a998("pictures_arrived_after_dial_moved",_DAT_009ecc88);
  FUN_0099a998("pictures_from_memory",_DAT_009ecc90);
  FUN_0099a998("dialog_calls_from_other_tasks",_DAT_009e70c8);
  FUN_0099a998("pool_kb_least_free_largest_while_shooting",
               DAT_009b49e8 >> 10 & 0xffff | (DAT_009b49ec >> 10) << 0x10);
  FUN_0099a998("pool_samples_while_shooting",_DAT_009e9948);
  FUN_0099a998("picture_load_failures",_DAT_009ea248);
  FUN_0099a998("last_frame",_DAT_009ec648);
  FUN_0099a998("roll_count",_DAT_009ece38);
  FUN_0099a998("settings_loaded",DAT_009b4a7c);
  FUN_0099a998("guard_fcs_queue_state",_DAT_009b4a84 & 0xffff | _DAT_009b4a80 << 0x10);
  FUN_0099a998("guard_rest_fcs_job",_DAT_009b4a90 & 0xffff | _DAT_009b4a8c << 0x10);
  FUN_0099a998("guard_job_state",_DAT_009b4a88);
  FUN_0099a998("guard_readable_untrusted",_DAT_009b4ab8 | _DAT_009b4a94 << 8);
  FUN_0099a998("guard_operations",_DAT_009b4ab0);
  FUN_0099a998("guard_waits",_DAT_009b4aa4);
  FUN_0099a998("guard_waited_ms",_DAT_009b4aa8);
  FUN_0099a998("guard_longest_wait_ms",_DAT_009b4aac);
  FUN_0099a998("guard_last_reason",_DAT_009b4ab4);
  FUN_0099a998("guard_shooting_events",_DAT_009b4aa0);
  FUN_0099a998("guard_held_ms_queue",_DAT_009b4ac8);
  FUN_0099a998("guard_held_ms_fcs",_DAT_009b4acc);
  FUN_0099a998("guard_held_ms_job",_DAT_009b4ad0);
  FUN_0099a998("guard_held_ms_quiet",_DAT_009b4ad4);
  uVar7 = 0x170000;
  puVar14 = (uint *)&DAT_009ec6a0;
  puVar16 = (uint *)&DAT_009ec760;
  do {
    if (*puVar16 != 0) {
      FUN_0099a998("event_in_shooting_state",*puVar16 & 0xffff | uVar7);
    }
    if (*puVar14 != 0) {
      FUN_0099a998("event_elsewhere",*puVar14 & 0xffff | uVar7);
    }
    uVar7 = uVar7 + 0x10000;
    puVar14 = puVar14 + 1;
    puVar16 = puVar16 + 1;
  } while (uVar7 != 0x470000);
  FUN_0099a998("gui_state",_DAT_009ef014);
  FUN_0099a998("gui_events",_DAT_009ef018);
  FUN_0099a998("gui_buttons_kept",_DAT_009ef020 | _DAT_009ef01c << 0x10);
  FUN_0099a998("gui_slowest_ms",_DAT_009ef044);
  FUN_0099a998("gui_slowest_event",_DAT_009ef048);
  FUN_0099a998("gui_slow_events_over_200ms",_DAT_009ef04c);
  iVar3 = 0;
  do {
    uVar7 = _DAT_009ef01c + iVar3;
    uVar11 = _DAT_009ef01c + iVar3;
    iVar3 = iVar3 + 1;
    FUN_0099a998("raw_button_kept",
                 CONCAT11((&UNK_009ef024)[uVar7 & 0xf],(&UNK_009ef034)[uVar11 & 0xf]));
  } while (iVar3 != 0x10);
  FUN_0099a998("core_raw_moves",_DAT_009eefbc);
  uVar7 = 0;
  pbVar2 = &DAT_009ec660;
  do {
    if (*pbVar2 != 0) {
      FUN_0099a998("raw_code_count",*pbVar2 | uVar7);
    }
    uVar7 = uVar7 + 0x10000;
    pbVar2 = pbVar2 + 1;
  } while (uVar7 != 0x400000);
  iVar3 = 0;
  psVar9 = (short *)&UNK_009eefe6;
  do {
    sVar1 = psVar9[1];
    if (sVar1 != 0) {
      FUN_0099a998("screen_code_count",CONCAT22(psVar9[-0xf],sVar1));
    }
    iVar3 = iVar3 + 1;
    psVar9 = psVar9 + 1;
  } while (iVar3 != 0x10);
  FUN_0099a998("core_takes_failures",_DAT_009eef88 | _DAT_009eef84 << 0x10);
  FUN_0099a998("core_releases",_DAT_009eef8c);
  FUN_0099a998("core_opens_asked_forgotten",_DAT_009eef94 | _DAT_009eef90 << 0x10);
  FUN_0099a998("core_empty_card_takes",_DAT_009eefa4);
  FUN_0099a998("films_offered",_DAT_009ec844);
  FUN_0099a998("films_look_ms",_DAT_009ec840);
  FUN_0099a998("card_read_at_ms",_DAT_009ec83c);
  FUN_0099a998("pruned_roll_owed_at_start",_DAT_009ea620 | _DAT_009e757c << 0x10);
  FUN_0099a998("core_reviews_skipped_closed",
               _DAT_009eef9c << 10 | _DAT_009eef98 << 0x14 | _DAT_009eefa0);
  FUN_0099a998("core_gallery_plays",_DAT_009eefac | _DAT_009eefa8 << 0x10);
  FUN_0099a998("core_draws",_DAT_009eefb4);
  FUN_0099a998("core_photo_failures",_DAT_009eefb8);
  FUN_0099a998("adapter_takes_failures",_DAT_009ec914 | _DAT_009ec910 << 0x10);
  FUN_0099a998("adapter_displays_failures",_DAT_009ec920 | _DAT_009ec91c << 0x10);
  FUN_0099a998("adapter_handler_delegated",_DAT_009ec928 | _DAT_009ec924 << 0x10);
  FUN_0099a998("adapter_paint_failures",_DAT_009ec918);
  FUN_0099a998("page_paints_errors",_DAT_009faac8 | _DAT_009faac0 << 0x10);
  FUN_0099a998("page_paint_area",_DAT_009faacc);
  FUN_0099a998("empty_boxes_widened",_DAT_009ec904);
  FUN_0099a998("displays_lit",_DAT_009ec900);
  FUN_0099a998("picture_buffers_late",_DAT_009eca3c);
  FUN_0099a998("welcome_asked_opened",_DAT_009ec84c | _DAT_009ec850 << 8);
  FUN_0099a998("empty_box_xy",_DAT_009ec908);
  FUN_0099a998("empty_box_wh",_DAT_009ec90c);
  uVar11 = 0;
  uVar7 = 0;
  pbVar2 = &UNK_009faa67;
  do {
    pbVar2 = pbVar2 + 1;
    uVar7 = uVar7 | (*pbVar2 & 0xf) << (uVar11 & 0xff);
    uVar11 = uVar11 + 4;
  } while (uVar11 != 0x1c);
  uVar11 = (uint)DAT_009faa70;
  uVar8 = (uint)DAT_009faa6f;
  uVar5 = (uint)DAT_009faa71;
  uVar6 = (uint)DAT_009faa72;
  FUN_0099a998("page_inks_clear_bg_panel_rule_dim_text_accent",uVar7);
  FUN_0099a998("page_inks_faint_shade_aa1_aa2",
               uVar8 & 0xf | (uVar11 & 0xf) << 4 | (uVar5 & 0xf) << 8 | (uVar6 & 0xf) << 0xc);
  FUN_0099a998("page_palette_changes_ink_failures",_DAT_009faaa8 | _DAT_009faaa4 << 0x10);
  FUN_0099a998("page_latent_palette_on",DAT_009faa24);
  FUN_0099a998("page_latent_palette_apply_status",_DAT_009faaac);
  FUN_0099a998("page_latent_palette_reapplied_restored_skipped",
               (uint)DAT_009faab8 | _DAT_009faab0 << 0x10 | (_DAT_009faab4 & 0xff) << 8);
  iVar3 = 0;
  pbVar2 = &DAT_009fa9a0;
  do {
    iVar3 = iVar3 + 1;
    FUN_0099a998("page_palette_aYUV",
                 (uint)pbVar2[1] << 0x10 | (uint)*pbVar2 << 0x18 | (uint)pbVar2[3] |
                 (uint)pbVar2[2] << 8);
    pbVar2 = pbVar2 + 4;
  } while (iVar3 != 0x10);
  iVar3 = 0;
  puVar12 = &DAT_009b1d24;
  puVar10 = (undefined4 *)&DAT_009e7514;
  do {
    iVar3 = iVar3 + 1;
    FUN_0099a998(*puVar12,*puVar10);
    puVar12 = puVar12 + 1;
    puVar10 = puVar10 + 1;
  } while (iVar3 != 0x14);
  FUN_0099a998("records_from_roll_owed_films_film",
               (uint)DAT_009b4a1d << 0x10 | (uint)DAT_009b4a39 << 0x18 | (uint)DAT_009b4985 |
               (uint)DAT_009b4a55 << 8);
  FUN_0099a998("records_saves_failures",
               DAT_009b4a40 + DAT_009b4a24 + DAT_009b4a5c + DAT_009b498c & 0xffffU |
               (DAT_009b4a3c + DAT_009b4a20 + DAT_009b4a58 + DAT_009b4988) * 0x10000);
  FUN_0099a998("pictures_not_written",_DAT_009e96ec);
  FUN_0099a998("pictures_lent_busy_gave_room",
               (uint)DAT_009ecc54 | _DAT_009ecc5c << 0x10 | (_DAT_009ecc58 & 0xff) << 8);
  FUN_0099a998("card_folders_made_failed",_DAT_009b4b1c & 0xffff | _DAT_009b4b20 << 0x10);
  FUN_0099a998("log_write_failures",_DAT_009e7508);
  FUN_0099a998("log_lines_lost",_DAT_009ef058);
  FUN_0099a998("log_end",_DAT_009ea410);
  FUN_0099ba3c();
  _DAT_009ef05c = (code *)0x0;
  if (-1 < _DAT_009e750c) {
    FUN_00982a90(_DAT_009e750c,1);
  }
  if (-1 < _DAT_009e7510) {
    FUN_00982a90(_DAT_009e7510,1);
  }
  uVar7 = _DAT_009eca48;
  if ((0xb < _DAT_009eca48) && (_DAT_009e732c != _DAT_009eca48)) {
    _DAT_009e732c = _DAT_009eca48;
    _DAT_009ef060 = 0;
    FUN_0099a998("steps",_DAT_009eca48);
    uVar11 = uVar7;
    if (uVar7 < 0x40) {
      uVar11 = 0x40;
    }
    for (uVar11 = uVar11 - 0x40; uVar11 < uVar7; uVar11 = uVar11 + 1) {
      FUN_0099a998("t",*(undefined4 *)(&UNK_009eca4c + (uVar11 & 0x3f) * 8));
      FUN_0099a998("e",*(undefined4 *)(&UNK_009eca50 + (uVar11 & 0x3f) * 8));
    }
    FUN_0099ae24(local_48,"A:/LATENT/P",_DAT_009ea410,".LOG");
    FUN_00982c98(local_48,&UNK_009ef080,_DAT_009ef060);
  }
  return;
}


// ===== FUN_0099e950 @ 0099e950

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0099e950(void)

{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  undefined1 *puStack_50;
  undefined1 *puStack_4c;
  undefined1 *puStack_48;
  code *pcStack_44;
  code *pcStack_40;
  code *pcStack_3c;
  undefined1 *puStack_38;
  undefined1 *puStack_34;
  undefined1 *puStack_30;
  undefined4 uStack_2c;
  undefined1 *puStack_28;
  code *pcStack_24;
  
  (*(code *)&SUB_ffb23474)(1000);
  uVar6 = 0;
  do {
    if ((uVar6 & 1) == 0) {
      _DAT_c02200f0 = 0x46;
    }
    else {
      _DAT_c02200f0 = 0x44;
    }
    _DAT_009fabf4 = FUN_009a35e0(&puStack_50);
    _DAT_009fabf8 = _DAT_009fabf8 + 1;
    if ((_DAT_009fabf4 & 0x200) != 0) break;
    if ((_DAT_009fabf4 & 0x7e) == 0x7e) {
      bVar1 = true;
      goto LAB_0099e9a8;
    }
    uVar6 = uVar6 + 1;
    (*(code *)&SUB_ffb23474)(100);
  } while (uVar6 != 100);
  bVar1 = false;
LAB_0099e9a8:
  FUN_009824f0();
  FUN_0098288c(&SUB_ffb23474);
  if (bVar1) {
    _DAT_009ede4c = &SUB_ffb23474;
    puStack_50 = &LAB_0099ac30;
    puStack_4c = &LAB_0099ac34;
    puStack_48 = &LAB_0099bd24;
    pcStack_44 = FUN_0099bb90;
    pcStack_40 = FUN_0099ec94;
    pcStack_3c = FUN_0099b53c;
    puStack_38 = &LAB_0099f3a0;
    puStack_34 = &LAB_0099adcc;
    puStack_30 = &LAB_0099adf8;
    uStack_2c = 0;
    puStack_28 = &LAB_0099ada8;
    pcStack_24 = FUN_0099bac0;
    uVar2 = FUN_0099b714(DAT_009b4a7c);
    FUN_0098ae00(&UNK_009ede50,&puStack_50,0x51,&DAT_009b1ddc,&DAT_009b4a64,uVar2);
    _DAT_009eef54 = DAT_009b4a60;
    FUN_0098a56c(&LAB_0099baf4);
    FUN_0098a57c(&LAB_0099c1cc);
    FUN_0098a58c(FUN_0099c1d0);
    iVar3 = FUN_0098a6a8(&UNK_009ef008,&LAB_0099c0c4,&SUB_ffb23474);
    if (iVar3 == 0) {
      (*(code *)&SUB_ffb18b40)("LatentDev",0x1f,0x4000,FUN_009a1714,0);
      (*(code *)&SUB_ffb18b40)("LatentPic",0x1a,0x1000,FUN_0099f768,0);
      iVar3 = 0;
      iVar7 = 0;
      do {
        (*(code *)&SUB_ffb23474)(0xfa);
        if ((((((_DAT_009ede98 != 0 || _DAT_009ede9c != 0) || _DAT_009ede8c != 0) ||
              _DAT_009ede90 != 0) || _DAT_009ede94 != 0) || _DAT_009eca30 != 0) ||
           (_DAT_009eca40 != 0)) {
          FUN_0098a59c(1);
        }
        iVar4 = FUN_0099aba0();
        iVar5 = _DAT_009ef01c + _DAT_009eefb4 + _DAT_009eef84 + _DAT_009eef8c;
        if (iVar5 == iVar7) {
          if ((iVar3 == 0) || ((uint)(iVar4 - iVar3) < 3000)) {
            iVar4 = iVar3;
          }
          else {
            _DAT_009ecd10 = _DAT_009ecd10 + 1;
            iVar4 = 0;
          }
        }
        iVar3 = iVar4;
        iVar7 = iVar5;
      } while( true );
    }
    FUN_0099d294(0);
  }
  (*(code *)&SUB_ffb23474)(5000);
  FUN_0099ccac(1);
  _DAT_009fac04 = 1;
  FUN_0099ccac(4);
  iVar3 = 5;
  do {
    _DAT_c02200f0 = 0x46;
    _DAT_c02200a0 = 0x46;
    (*(code *)&SUB_ffb23474)(300);
    _DAT_c02200f0 = 0x44;
    _DAT_c02200a0 = 0x44;
    (*(code *)&SUB_ffb23474)(300);
    (*(code *)&SUB_ffb23474)(0x5dc);
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  _DAT_c02200f0 = 0x44;
  (*(code *)&SUB_ffb18f00)();
  do {
    (*(code *)&SUB_ffb23474)(1000);
  } while( true );
}


// ===== FUN_0099ec64 @ 0099ec64

/* WARNING: Removing unreachable block (ram,0x0098a94c) */

uint FUN_0099ec64(undefined1 param_1,char param_2,byte param_3,undefined4 param_4)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  undefined8 uVar6;
  uint3 uVar7;
  undefined4 uVar8;
  
  param_2 = param_2 + -6;
  uVar7 = CONCAT12(param_3,CONCAT11(param_2,param_1));
  bVar1 = (byte)param_4;
  uVar8 = CONCAT13(bVar1,uVar7);
  uVar3 = uVar7 & 0xff;
  if (0x50 < uVar3) {
    return 0x5000000;
  }
  iVar4 = uVar3 * 0xc;
  uVar5 = (int)(char)(&DAT_009b1ddc)[iVar4];
  if ((int)(char)(&DAT_009b1ddc)[iVar4] < (int)param_2) {
    uVar5 = (int)param_2;
  }
  if ((int)(char)(&UNK_009b1ddd)[iVar4] <= (int)uVar5) {
    uVar5 = (int)(char)(&UNK_009b1ddd)[iVar4];
  }
  uVar5 = uVar5 & 0xff;
  if ((byte)(&DAT_009b1dde)[iVar4] <= param_3) {
    param_3 = (&UNK_009b1ddf)[iVar4];
  }
  uVar6 = FUN_0098a850(&DAT_009b1ddc + iVar4,param_3,uVar3,uVar5,&DAT_009b1ddc,uVar8,uVar8,param_4);
  uVar2 = (uint)uVar6 ^ 1;
  if (0xb < bVar1) {
    uVar2 = uVar2 | 1;
  }
  if ((uVar2 & 1) != 0) {
    bVar1 = 5;
  }
  return uVar3 | uVar5 << 8 | (int)((ulonglong)uVar6 >> 0x20) << 0x10 | (uint)bVar1 << 0x18;
}


// ===== FUN_0099ec94 @ 0099ec94

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0099ec94(undefined4 param_1,char *param_2)

{
  byte bVar1;
  char cVar2;
  undefined4 uVar3;
  char *pcVar4;
  char *pcVar5;
  int iVar6;
  char extraout_r1;
  char *pcVar7;
  undefined1 *puVar8;
  undefined4 *puVar9;
  uint uVar10;
  uint uVar11;
  char *pcVar12;
  bool bVar13;
  bool bVar14;
  char local_b0 [8];
  undefined4 local_a8;
  undefined4 local_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined *local_98;
  undefined *local_94;
  undefined **local_90;
  undefined4 local_8c;
  uint local_88;
  undefined4 local_84;
  uint local_80;
  uint local_7c;
  int local_78;
  int local_74;
  uint local_70;
  uint local_6c;
  uint local_68;
  uint local_64;
  uint local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  uint local_30;
  undefined4 local_2c;
  
  if (*param_2 == '\x01') {
    uVar10 = 0;
    _DAT_009ecc8c = 0;
    FUN_0098b23c(&local_a8,&DAT_009b4a64,0x51,param_2[1],param_2[5]);
    uVar11 = (uint)(byte)param_2[1];
    puVar9 = &DAT_009b2254 + uVar11 * 3;
    local_9c = (&DAT_009b2254)[uVar11 * 3];
    uVar3 = FUN_0099aab4(&UNK_009e7360,(&PTR_DAT_009b2634)[(byte)(&LAB_009b225e)[uVar11 * 0xc]]);
    uVar3 = FUN_0099aab4(uVar3,&DAT_009a7de8);
    uVar3 = FUN_0099aab4(uVar3,(&PTR_s_colour_negative_009b2620)[*(byte *)((int)puVar9 + 0xb)]);
    pcVar7 = (char *)FUN_0099aab4(uVar3,&DAT_009a7ded);
    uVar11 = (uint)*(ushort *)(puVar9 + 2);
    pcVar4 = local_b0;
    do {
      FUN_009a5ce4(uVar11,10);
      uVar10 = uVar10 + 1;
      bVar14 = 4 < uVar10;
      if (uVar10 != 5) {
        bVar14 = 8 < uVar11;
      }
      bVar13 = uVar11 != 9;
      *pcVar4 = extraout_r1 + '0';
      uVar11 = uVar11 / 10;
      pcVar4 = pcVar4 + 1;
    } while (bVar14 && (uVar10 != 5 && bVar13));
    pcVar12 = local_b0 + uVar10;
    pcVar4 = pcVar7;
    do {
      pcVar12 = pcVar12 + -1;
      pcVar5 = pcVar4 + 1;
      *pcVar4 = *pcVar12;
      pcVar4 = pcVar5;
    } while (pcVar5 != pcVar7 + uVar10);
    *pcVar5 = '\0';
    local_98 = &UNK_009e7360;
    local_80 = (uint)(byte)param_2[1];
    local_94 = &DAT_009b1ddc + local_80 * 0xc;
    local_90 = &PTR_s_Endura_Premier_009b1d90;
    local_8c = local_a8;
    local_88 = local_a4;
    local_84 = local_a0;
    local_7c = (uint)(byte)param_2[5];
    local_78 = (int)param_2[2];
    local_74 = (int)param_2[6];
    local_70 = (uint)(byte)param_2[3];
    local_6c = (uint)(byte)param_2[7];
    local_68 = (uint)(byte)param_2[4];
    local_64 = (uint)(byte)param_2[8];
    local_60 = (uint)(byte)param_2[9];
    local_5c = _DAT_009eeebc;
    local_58 = *(undefined4 *)(param_2 + 0x20);
    local_54 = *(undefined4 *)(param_2 + 0x24);
    local_50 = *(undefined4 *)(param_2 + 0xc);
    local_4c = *(undefined4 *)(param_2 + 0x10);
    local_48 = *(undefined4 *)(param_2 + 0x14);
    local_44 = *(undefined4 *)(param_2 + 0x18);
    local_40 = *(undefined4 *)(param_2 + 0x1c);
    local_3c = *(undefined4 *)(param_2 + 0x30);
    local_38 = *(undefined4 *)(param_2 + 0x34);
    local_34 = *(undefined4 *)(param_2 + 0x58);
    iVar6 = FUN_00994d0c(&DAT_009b2258 + local_80 * 0xc);
    local_30 = (uint)(iVar6 != 0);
    local_2c = *(undefined4 *)(param_2 + 0x5c);
    iVar6 = FUN_009a4b54(&UNK_009f00cc,&local_9c);
  }
  else {
    local_94 = *(undefined **)(param_2 + 0x48);
    local_9c = *(undefined4 *)(param_2 + 0x38);
    if (local_94 == (undefined *)0x0) {
      _DAT_009ecc8c = 0;
      cVar2 = param_2[6];
      bVar1 = param_2[5];
    }
    else {
      cVar2 = param_2[0x41];
      bVar1 = param_2[0x40];
      _DAT_009ecc8c = local_9c;
    }
    uVar11 = (uint)cVar2;
    uVar10 = (uint)bVar1;
    if (0x50 < uVar10) {
      uVar10 = 0;
    }
    local_98 = *(undefined **)(param_2 + 0x44);
    pcVar7 = (char *)((&DAT_009b2254)[uVar10 * 3] + -1);
    pcVar4 = &DAT_009e7330;
    while( true ) {
      pcVar7 = pcVar7 + 1;
      if (*pcVar7 == '\0') break;
      *pcVar4 = *pcVar7;
      pcVar4 = pcVar4 + 1;
    }
    if (uVar11 != 0) {
      if ((int)uVar11 < 1) {
        puVar8 = &UNK_009a7de0;
      }
      else {
        puVar8 = &DAT_009a7dda;
      }
      pcVar7 = puVar8 + -1;
      while( true ) {
        pcVar7 = pcVar7 + 1;
        if (*pcVar7 == '\0') break;
        *pcVar4 = *pcVar7;
        pcVar4 = pcVar4 + 1;
      }
      if ((int)uVar11 < 0) {
        uVar11 = -uVar11;
      }
      pcVar7 = (char *)(*(int *)(&DAT_009b1c7c + (uVar11 & 0xff) * 4) + -1);
      while( true ) {
        pcVar7 = pcVar7 + 1;
        if (*pcVar7 == '\0') break;
        *pcVar4 = *pcVar7;
        pcVar4 = pcVar4 + 1;
      }
    }
    *pcVar4 = '\0';
    local_8c = *(undefined4 *)(param_2 + 0x4c);
    local_90 = (undefined **)&DAT_009e7330;
    local_88 = (uint)(*param_2 == '\x02');
    local_84 = *(undefined4 *)(param_2 + 0x3c);
    if ((*(int *)(param_2 + 0xc) == *(int *)(param_2 + 0x38)) && (*(int *)(param_2 + 0x10) == 2)) {
      local_80 = *(uint *)(param_2 + 0x14);
      if (local_80 == 0) {
        local_80 = 1;
      }
    }
    else {
      local_80 = 0;
    }
    local_7c = *(uint *)(param_2 + 0x50);
    local_78 = *(int *)(param_2 + 0x54);
    local_74 = *(int *)(param_2 + 0x58);
    iVar6 = FUN_009a5774(&UNK_009f00cc,&local_9c);
    FUN_0099abc8(8,*(undefined4 *)(param_2 + 0x38),*(undefined4 *)(param_2 + 0x4c),*param_2);
  }
  if (iVar6 == 0) {
    _DAT_009ec918 = _DAT_009ec918 + 1;
  }
  else if (_DAT_009eca44 != 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  return;
}


// ===== FUN_0099f090 @ 0099f090

void FUN_0099f090(undefined4 param_1,uint param_2,uint param_3,int param_4)

{
  char *pcVar1;
  undefined4 uVar2;
  int iVar3;
  char *pcVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  
  if (0x50 < param_3) {
    param_3 = 0;
  }
  uVar2 = FUN_0099aab4(param_1,"A:/RITUAL/");
  uVar2 = FUN_0099ab58(uVar2,param_2 / 10000,3,param_2 * -0x2e48e8a7);
  uVar2 = FUN_0099aab4(uVar2,"EOS5D/");
  iVar3 = FUN_0099ab58(uVar2,param_2 % 10000,4);
  puVar6 = (undefined1 *)(iVar3 + -1);
  puVar5 = (undefined1 *)((int)&DAT_009b2254 + param_3 * 0xc + 3);
  do {
    puVar5 = puVar5 + 1;
    puVar6 = puVar6 + 1;
    *puVar6 = *puVar5;
  } while (puVar5 != &LAB_009b225a_1 + param_3 * 0xc);
  pcVar4 = (char *)(param_4 + -1);
  pcVar1 = (char *)(iVar3 + 4);
  while( true ) {
    pcVar4 = pcVar4 + 1;
    if (*pcVar4 == '\0') break;
    *pcVar1 = *pcVar4;
    pcVar1 = pcVar1 + 1;
  }
  *pcVar1 = '\0';
  return;
}


// ===== FUN_0099f130 @ 0099f130

void FUN_0099f130(undefined4 param_1,uint param_2)

{
  undefined1 auStack_40 [52];
  
  FUN_0099d264(auStack_40,param_1,&DAT_009a7e01);
  FUN_00982bac(auStack_40);
  if (param_2 < 0x51) {
    FUN_0099f090(auStack_40,param_1,param_2,&LAB_009a6fda);
    FUN_00982bac(auStack_40);
  }
  return;
}


// ===== FUN_0099f18c @ 0099f18c

bool FUN_0099f18c(uint param_1,undefined4 param_2)

{
  int iVar1;
  bool bVar2;
  byte bVar4;
  uint uVar3;
  undefined1 auStack_68 [40];
  undefined1 auStack_40 [52];
  
  bVar4 = (byte)(param_1 >> 0x18);
  if (((param_1 & 0x1000000) == 0) && (bVar4 < 0xa2)) {
    uVar3 = param_1;
    FUN_0099d208(auStack_68,param_1 & 0xffffff);
    FUN_0099f090(auStack_40,param_1 & 0xffffff,bVar4 >> 1,&LAB_009a6fda,uVar3,param_2);
    FUN_00985ddc(auStack_68,auStack_40);
    iVar1 = FUN_00985bbc();
    bVar2 = iVar1 != 0;
  }
  else {
    bVar2 = false;
  }
  return bVar2;
}


// ===== FUN_0099f200 @ 0099f200

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_0099f200(void)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  undefined1 auStack_48 [44];
  
  do {
    uVar2 = _DAT_009ece38;
    uVar4 = 0;
    uVar3 = 0;
    while (uVar2 != uVar4) {
      uVar4 = uVar4 + 1;
      if (((((&DAT_009ece43)[uVar4 * 8] & 1) == 0) &&
          (uVar5 = *(uint *)(&DAT_009ece40 + uVar4 * 8) & 0xffffff, uVar3 < uVar5)) &&
         (iVar1 = FUN_0099b0e4(uVar5), iVar1 != 0)) {
        iVar1 = FUN_0099b098(uVar5);
        if (iVar1 != 0) {
          uVar5 = uVar3;
        }
      }
      else {
        uVar5 = uVar3;
      }
      uVar3 = uVar5;
    }
    if (uVar3 == 0) {
      uVar2 = 0;
      while (uVar4 = _DAT_009ece38, uVar2 < _DAT_009ece38) {
        uVar2 = uVar2 + 1;
        if ((uVar3 < (*(uint *)(&DAT_009ece40 + uVar2 * 8) & 0xffffff)) &&
           (iVar1 = FUN_0099f18c(*(undefined4 *)(&DAT_009ece40 + uVar2 * 8),
                                 *(undefined4 *)(&DAT_009ece44 + uVar2 * 8)), iVar1 != 0)) {
          uVar3 = *(uint *)(&DAT_009ece40 + uVar2 * 8) & 0xffffff;
        }
      }
      if (uVar3 == 0) {
        uVar2 = 0;
      }
      else {
        iVar1 = FUN_0099b098(uVar3);
        if (iVar1 == 0) goto LAB_0099f2e0;
        uVar3 = 0;
        uVar2 = 0;
      }
      while (uVar2 != uVar4) {
        uVar2 = uVar2 + 1;
        if ((((&DAT_009ece43)[uVar2 * 8] & 1) == 0) &&
           (uVar5 = *(uint *)(&DAT_009ece40 + uVar2 * 8) & 0xffffff, uVar3 < uVar5)) {
          iVar1 = FUN_0099b098(uVar5);
          if (iVar1 != 0) {
            uVar5 = uVar3;
          }
        }
        else {
          uVar5 = uVar3;
        }
        uVar3 = uVar5;
      }
      if (uVar3 == 0) {
        return 0;
      }
    }
LAB_0099f2e0:
    FUN_0099d208(auStack_48,uVar3);
    iVar1 = FUN_00982bd8(auStack_48);
    if (iVar1 != 0) {
      return uVar3;
    }
    uVar2 = _DAT_009ea518 & 0x3f;
    _DAT_009ea518 = _DAT_009ea518 + 1;
    *(uint *)(&DAT_009ea51c + uVar2 * 4) = uVar3;
    FUN_0099b960(uVar3);
  } while( true );
}


// ===== FUN_0099f3ec @ 0099f3ec

void FUN_0099f3ec(int param_1,uint param_2,int *param_3,int *param_4)

{
  int extraout_r1;
  uint uVar1;
  
  uVar1 = *(uint *)(param_1 + 4);
  if (param_2 < uVar1) {
    uVar1 = 0;
  }
  else {
    FUN_009a5ce4(uVar1,10000);
    uVar1 = ((param_2 - param_2 / 10000) - extraout_r1) + (uVar1 / 10000) * -9999;
  }
  *param_3 = (uint)*(ushort *)(param_1 + 8) + uVar1 / 0x24;
  *param_4 = uVar1 % 0x24 + 1;
  return;
}


// ===== FUN_0099f490 @ 0099f490

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0099f490(uint param_1,uint param_2)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  uint *puVar4;
  undefined4 *puVar5;
  uint *puVar6;
  uint uVar7;
  undefined1 uStack_3a;
  undefined1 uStack_39;
  char cStack_33;
  short local_30 [2];
  undefined1 auStack_2c [8];
  
  cVar1 = (char)(param_2 >> 8);
  puVar4 = _DAT_009e9e30;
  if (_DAT_009e9e30 != (uint *)0x0) {
    puVar4 = (uint *)((int)_DAT_009e9e30 + -1);
    puVar6 = _DAT_009e9e30;
    if ((*(uint *)(&DAT_009e9e40 + (int)puVar4 * 0x10) != param_1) ||
       (puVar6 = puVar4, puVar4 != (uint *)0x0)) {
      puVar4 = puVar6;
      puVar6 = (uint *)(&DAT_009e9e40 + (int)((int)puVar4 + -1) * 0x10);
      goto LAB_0099f4f4;
    }
  }
  puVar6 = puVar4;
LAB_0099f4f4:
  uStack_3a = (undefined1)(param_2 >> 0x10);
  uStack_39 = (undefined1)(param_2 >> 0x18);
  uVar7 = param_1;
  if (puVar6 == (uint *)0x0) {
    local_30[0] = 1;
  }
  else {
    uVar2 = FUN_0099ec64(*(undefined *)((int)puVar6 + 10),*(undefined *)((int)puVar6 + 0xb),
                         (char)puVar6[3],*(undefined *)((int)puVar6 + 0xd));
    iVar3 = FUN_0098ada0(uVar2,param_2);
    if ((iVar3 != 0) && (_DAT_009e9e30 == puVar4)) {
      return;
    }
    if (((uVar2 & 0xff) == (param_2 & 0xff)) && (cStack_33 = (char)(uVar2 >> 8), cStack_33 == cVar1)
       ) {
      local_30[0] = (short)puVar6[2];
      uVar7 = puVar6[1];
    }
    else {
      uVar2 = param_1;
      if (*puVar6 < param_1) {
        uVar2 = param_1 - 1;
      }
      FUN_0099f3ec(puVar6,uVar2,local_30,auStack_2c);
      local_30[0] = local_30[0] + 1;
    }
  }
  if (puVar4 == (uint *)0x40) {
    iVar3 = 1;
    puVar5 = (undefined4 *)&DAT_009e9e40;
    do {
      iVar3 = iVar3 + 1;
      *puVar5 = puVar5[4];
      puVar5[1] = puVar5[5];
      puVar5[2] = puVar5[6];
      puVar5[3] = puVar5[7];
      puVar5 = puVar5 + 4;
    } while (iVar3 != 0x40);
    puVar4 = (uint *)0x3f;
  }
  *(uint *)(&DAT_009e9e40 + (int)puVar4 * 0x10) = param_1;
  iVar3 = (int)puVar4 * 0x10;
  (&DAT_009e9e4c)[iVar3] = uStack_3a;
  (&DAT_009e9e4d)[iVar3] = uStack_39;
  _DAT_009e9e30 = (uint *)((int)puVar4 + 1);
  *(undefined2 *)(&UNK_009e9e4e + iVar3) = 0;
  *(uint *)(&DAT_009e9e44 + iVar3) = uVar7;
  *(short *)(&DAT_009e9e48 + iVar3) = local_30[0];
  (&DAT_009e9e4a)[iVar3] = (char)param_2;
  (&DAT_009e9e4b)[iVar3] = cVar1 + '\x06';
  _DAT_009e9e2c = _DAT_009e9e2c + 1;
  return;
}


// ===== FUN_0099f638 @ 0099f638

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0099f638(uint param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  uint uVar2;
  uint *puVar3;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30 [3];
  
  do {
    iVar1 = _DAT_009e9e2c;
    local_38 = FUN_0099b714(DAT_009b4a7c);
    puVar3 = (uint *)&DAT_009e9e40;
    local_34 = 0;
    local_30[0] = 0;
    for (uVar2 = 0; (uVar2 < _DAT_009e9e30 && (uVar2 != 0x40)); uVar2 = uVar2 + 1) {
      if (*puVar3 <= param_1) {
        local_38 = FUN_0099ec64(*(undefined *)((int)puVar3 + 10),*(undefined *)((int)puVar3 + 0xb),
                                (char)puVar3[3],*(undefined *)((int)puVar3 + 0xd));
        FUN_0099f3ec(puVar3,param_1,&local_34,local_30);
      }
      puVar3 = puVar3 + 4;
    }
  } while (_DAT_009e9e2c != iVar1);
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = local_34;
  }
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = local_30[0];
  }
  return local_38;
}


// ===== FUN_0099f718 @ 0099f718

/* WARNING: Removing unreachable block (ram,0x0099f69c) */
/* WARNING: Removing unreachable block (ram,0x0099f6a4) */
/* WARNING: Removing unreachable block (ram,0x0098a94c) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_0099f718(uint param_1)

{
  int iVar1;
  int iVar2;
  ushort uVar3;
  undefined1 extraout_r1;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint *puVar8;
  uint uVar9;
  undefined8 uVar10;
  uint uStack_38;
  undefined4 uStack_34;
  undefined4 auStack_30 [3];
  byte bVar11;
  byte bVar12;
  undefined2 uVar13;
  
  iVar4 = _DAT_009ece38;
  do {
    if (iVar4 == 0) {
      do {
        iVar4 = _DAT_009e9e2c;
        uStack_38 = FUN_0099b714(DAT_009b4a7c);
        puVar8 = (uint *)&DAT_009e9e40;
        uStack_34 = 0;
        auStack_30[0] = 0;
        for (uVar7 = 0; (uVar7 < _DAT_009e9e30 && (uVar7 != 0x40)); uVar7 = uVar7 + 1) {
          if (*puVar8 <= param_1) {
            uStack_38 = FUN_0099ec64(*(undefined *)((int)puVar8 + 10),
                                     *(undefined *)((int)puVar8 + 0xb),(char)puVar8[3],
                                     *(undefined *)((int)puVar8 + 0xd));
            FUN_0099f3ec(puVar8,param_1,&uStack_34,auStack_30);
          }
          puVar8 = puVar8 + 4;
        }
      } while (_DAT_009e9e2c != iVar4);
      return uStack_38;
    }
    iVar2 = iVar4 * 8;
    iVar1 = iVar4 * 8;
    iVar4 = iVar4 + -1;
  } while ((*(uint *)(&DAT_009ece40 + iVar2) & 0xffffff) != param_1);
  uVar3 = (ushort)*(undefined4 *)(&DAT_009ece44 + iVar1) >> 4;
  uVar7 = uVar3 & 0x3f;
  bVar11 = (byte)((uint)*(undefined4 *)(&DAT_009ece40 + iVar1) >> 0x19);
  uVar13 = CONCAT11(((byte)*(undefined4 *)(&DAT_009ece44 + iVar1) & 0xf) - 6,bVar11);
  uVar6 = CONCAT22((short)(CONCAT13(5,(uint3)((byte)uVar3 & 0xf) << 0x10) >> 0x10),uVar13);
  if ((bVar11 < 0x51 && 0xf < uVar7) && (*(ushort *)(&DAT_009b1de0 + (uint)bVar11 * 0xc) != 0)) {
    uVar6 = 0;
    do {
      if (((int)(uint)*(ushort *)(&DAT_009b1de0 + (uint)bVar11 * 0xc) >> (uVar6 & 0xff) & 1U) != 0)
      break;
      uVar6 = uVar6 + 1;
    } while (uVar6 != 0xd);
    uVar7 = uVar7 - 0x10;
    FUN_009a5e2c(uVar7,0xc,uVar7 * -0x55555555);
    uVar6 = CONCAT13(extraout_r1,CONCAT12((char)uVar6 + (char)(uVar7 / 0xc),uVar13));
  }
  uVar7 = uVar6 & 0xff;
  if (0x50 < uVar7) {
    return 0x5000000;
  }
  iVar4 = uVar7 * 0xc;
  uVar9 = (uint)(char)(uVar6 >> 8);
  bVar11 = (byte)(uVar6 >> 0x10);
  uVar5 = (int)(char)(&DAT_009b1ddc)[iVar4];
  if ((int)(char)(&DAT_009b1ddc)[iVar4] < (int)uVar9) {
    uVar5 = uVar9;
  }
  bVar12 = (byte)(uVar6 >> 0x18);
  if ((int)(char)(&UNK_009b1ddd)[iVar4] <= (int)uVar5) {
    uVar5 = (int)(char)(&UNK_009b1ddd)[iVar4];
  }
  uVar5 = uVar5 & 0xff;
  if ((byte)(&DAT_009b1dde)[iVar4] <= bVar11) {
    bVar11 = (&UNK_009b1ddf)[iVar4];
  }
  uVar10 = FUN_0098a850(&DAT_009b1ddc + iVar4,bVar11,uVar7,uVar5);
  uVar6 = (uint)uVar10 ^ 1;
  if (0xb < bVar12) {
    uVar6 = uVar6 | 1;
  }
  if ((uVar6 & 1) != 0) {
    bVar12 = 5;
  }
  return uVar7 | uVar5 << 8 | (int)((ulonglong)uVar10 >> 0x20) << 0x10 | (uint)bVar12 << 0x18;
}


// ===== FUN_0099f768 @ 0099f768

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0099f768(void)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  uint uVar6;
  uint extraout_r1;
  uint uVar7;
  int iVar8;
  int iVar9;
  int *piVar10;
  uint uVar11;
  int iVar12;
  uint *puVar13;
  uint *puVar14;
  uint uVar15;
  undefined1 *puVar16;
  uint uVar17;
  uint uVar18;
  int iVar19;
  uint uVar20;
  int iVar21;
  uint unaff_r10;
  undefined1 *puVar22;
  bool bVar23;
  bool bVar24;
  uint local_34;
  uint local_30 [9];
  
  do {
    iVar21 = _DAT_009ecd28;
    iVar9 = _DAT_009ecd20;
    iVar3 = _DAT_009e9954;
    if (_DAT_009ecd20 != _DAT_009ecd1c) {
      if ((_DAT_009ecd24 < 2) && (iVar19 = *(int *)(&DAT_009ecd34 + _DAT_009ecd24 * 4), iVar19 != 0)
         ) {
        if ((_DAT_009e9954 == 0) || (_DAT_009ecd28 != _DAT_009e9950)) {
          FUN_0099d264(local_30,_DAT_009ecd28,&DAT_009a7e01);
          local_34 = 0;
          iVar3 = FUN_00982c00(local_30,iVar19,0x3f480,&local_34);
          if (iVar3 == 0) {
            _DAT_009ecd14 = (uint)(local_34 == 0x3f480);
          }
          else {
            _DAT_009ecd14 = 0;
          }
          _DAT_009ea24c = _DAT_009ea24c + 1;
          if (_DAT_009ecd14 == 0) {
            _DAT_009ea248 = _DAT_009ea248 + 1;
          }
        }
        else {
          iVar12 = 0;
          do {
            *(undefined4 *)(iVar19 + iVar12 * 4) = *(undefined4 *)(iVar3 + iVar12 * 4);
            iVar12 = iVar12 + 1;
          } while (iVar12 != 0xfd20);
          _DAT_009e994c = _DAT_009e994c + 1;
          _DAT_009ecd14 = 1;
        }
      }
      else {
        _DAT_009ecd14 = 0;
      }
      _DAT_009ecd18 = iVar21;
      _DAT_009ecd1c = iVar9;
      FUN_0098a59c(iVar21 << 8 | 5);
    }
    iVar3 = _DAT_009ede48;
    if (_DAT_009e9e28 == 0) {
      if (_DAT_009e9974 != 0) {
        iVar3 = FUN_0099be28(local_30);
        if (iVar3 == 0) {
          _DAT_009e7504 = _DAT_009e7504 + 1;
          if (_DAT_009e7504 < 100) goto LAB_0099f91c;
        }
        else {
          _DAT_009e996c = local_30[0];
          uVar4 = FUN_0099ae48();
          uVar5 = FUN_0099b714(DAT_009b4a7c);
          FUN_0099f490(uVar4,uVar5);
        }
        _DAT_009e9e28 = 1;
      }
    }
    else if ((_DAT_009ede48 != _DAT_009e9970) && (iVar9 = FUN_0099be28(local_30), iVar9 != 0)) {
      _DAT_009e9970 = iVar3;
      uVar4 = FUN_0099ae48(local_30[0]);
      uVar5 = FUN_0099b714(DAT_009b4a7c);
      FUN_0099f490(uVar4,uVar5);
    }
LAB_0099f91c:
    iVar3 = FUN_0099aba0();
    if (499 < (uint)(iVar3 - _DAT_009e7500)) {
      _DAT_009e7500 = iVar3;
      iVar3 = FUN_0099be28(local_30);
      if (iVar3 != 0) {
        _DAT_009e995c = local_30[0];
      }
    }
    uVar15 = _DAT_00004ef4;
    iVar3 = FUN_0099aba0();
    uVar2 = _DAT_009e98dc;
    if (_DAT_009e98d8 == 0) {
      _DAT_009e98dc = uVar15;
      _DAT_009e98d8 = 1;
    }
    else {
      if (uVar15 != _DAT_009e98dc) {
        _DAT_009e98dc = uVar15;
        if ((_DAT_009e991c != 0) && (_DAT_009e992c == 0)) {
          _DAT_009e98b0 = _DAT_009e98b0 + 1;
        }
        iVar9 = 0;
        puVar16 = &DAT_009e9918;
        do {
          iVar9 = iVar9 + 1;
          *puVar16 = 0;
          puVar16 = puVar16 + 1;
        } while (iVar9 != 0x30);
        _DAT_009e9930 = uVar2 + 1;
        _DAT_009e991c = uVar15;
        _DAT_009e9934 = _DAT_009e995c;
        if (_DAT_009e98cc == (undefined1 *)0x0) {
          _DAT_009e98d4 = (undefined1 *)0x6e0000;
        }
        else {
          _DAT_009e98d4 = _DAT_009e98cc;
          if (_DAT_009e98cc < (undefined1 *)0x300000) {
            _DAT_009e98d4 = (undefined1 *)0x300000;
          }
          _DAT_009e98d4 = _DAT_009e98d4 + -0x80000;
        }
        _DAT_009e98d0 = 0x700000;
        _DAT_009e98c0 = 0;
        _DAT_009e98c4 = 0;
        _DAT_009e98bc = _DAT_009e98bc + 1;
        _DAT_009e9924 = iVar3;
      }
      uVar2 = _DAT_009e9934;
      uVar15 = _DAT_009e991c;
      puVar16 = _DAT_009e98d4;
      if (_DAT_009e991c != 0) {
        if (_DAT_009e992c == 0) {
          if (_DAT_009e9918 == (undefined1 *)0x0) {
            FUN_009a5ce4(_DAT_009e9934,10000);
            iVar9 = _DAT_009e9930;
            uVar1 = _DAT_009e98c8;
            iVar19 = (uVar2 / 10000) * 10000;
            uVar11 = uVar15 - _DAT_009e9930;
            iVar12 = _DAT_009e98d0 + -0xc000;
            bVar24 = false;
            bVar23 = false;
            iVar21 = _DAT_009e98d0;
            uVar20 = _DAT_009e9814;
            do {
              if (iVar21 == 0) {
                if (bVar24) {
                  _DAT_009e98d0 = 0;
                }
                if (bVar23) {
                  _DAT_009e9810 = unaff_r10;
                  _DAT_009e9814 = uVar20;
                }
                puVar22 = puVar16;
                if (!bVar24) goto LAB_0099fd28;
                goto LAB_0099fe28;
              }
              if (&LAB_00980000 <= puVar16) {
                puVar16 = (undefined1 *)0x280000;
              }
              puVar22 = puVar16 + 4;
              if (*(int *)((uint)puVar16 & 0xffffffc | 0x10000000) == -0x74d628) {
                puVar13 = (uint *)((uint)puVar22 & 0xffffffc | 0x10000000);
                uVar7 = *puVar13;
                puVar14 = (uint *)((uint)(puVar16 + 0xc) & 0xffffffc | 0x10000000);
                uVar17 = *puVar14;
                if (uVar17 - 1 < 9999) {
                  if (uVar2 == 0) {
                    uVar18 = 0;
                  }
                  else if (uVar17 < extraout_r1 && uVar2 < 0x986f70) {
                    uVar18 = iVar19 + 10000 + uVar17;
                  }
                  else {
                    uVar18 = uVar17 + iVar19;
                  }
                }
                else {
                  uVar18 = 0;
                }
                if ((uVar7 - iVar9 <= uVar11) ||
                   ((uVar18 != 0 &&
                    ((((uVar2 == uVar18 || (uVar6 = FUN_0099ae48(uVar2), uVar18 == uVar6)) ||
                      (uVar6 = FUN_0099ae48(), uVar18 == uVar6)) && (uVar1 < uVar7)))))) {
                  if (bVar24) {
                    _DAT_009e98d0 = iVar21;
                  }
                  if (bVar23) {
                    _DAT_009e9810 = unaff_r10;
                    _DAT_009e9814 = uVar20;
                  }
                  _DAT_009e98b8 = _DAT_009e98b8 + 1;
                  _DAT_009e98c8 = uVar7;
                  _DAT_009e98cc = puVar16;
                  _DAT_009e98d4 = puVar22;
                  _DAT_009e9918 = puVar16;
                  _DAT_009e991c = uVar7;
                  _DAT_009e9928 = iVar3;
                  if (puVar16 == (undefined1 *)0x0) goto LAB_0099fd28;
                  goto LAB_0099fe38;
                }
                if ((uVar17 - 1 < 9999) && (uVar20 < 6)) {
                  bVar23 = true;
                  iVar8 = uVar20 * 0xc;
                  *(undefined1 **)(&DAT_009e9818 + iVar8) = puVar16;
                  uVar20 = uVar20 + 1;
                  *(uint *)(&DAT_009e981c + iVar8) = *puVar13;
                  *(uint *)(&DAT_009e9820 + iVar8) = *puVar14;
                  unaff_r10 = uVar15;
                }
              }
              iVar21 = iVar21 + -4;
              bVar24 = true;
              puVar16 = puVar22;
            } while (iVar21 != iVar12);
            _DAT_009e98d0 = iVar21;
            if (bVar23) {
              _DAT_009e9810 = unaff_r10;
              _DAT_009e9814 = uVar20;
            }
LAB_0099fe28:
            _DAT_009e98d4 = puVar22;
LAB_0099fd28:
            if (_DAT_009e98d0 == 0) goto LAB_0099fd40;
          }
          else {
LAB_0099fe38:
            puVar16 = _DAT_009e9918;
            if (*(int *)((uint)_DAT_009e9918 & 0xffffffc | 0x10000000) == -0x74d628) {
              if (*(uint *)((uint)(_DAT_009e9918 + 4) & 0xffffffc | 0x10000000) != _DAT_009e991c)
              goto LAB_0099fd40;
              uVar5 = *(undefined4 *)((uint)(_DAT_009e9918 + 0x16c) & 0xffffffc | 0x10000000);
              iVar19 = *(int *)((uint)(_DAT_009e9918 + 0x170) & 0xffffffc | 0x10000000);
              uVar4 = *(undefined4 *)((uint)(_DAT_009e9918 + 0x154) & 0xffffffc | 0x10000000);
              iVar21 = *(int *)((uint)(_DAT_009e9918 + 0x158) & 0xffffffc | 0x10000000);
              iVar9 = FUN_0099b260(uVar5,iVar19);
              if ((iVar9 == 0) || (iVar9 = FUN_0099b1f4(uVar4,iVar21), iVar9 == 0)) {
                _DAT_009e98c4 = 0;
                _DAT_009e98c0 = 0;
                goto LAB_0099f964;
              }
              bVar23 = iVar19 == _DAT_009e98c4;
              bVar24 = _DAT_009e98c0 == iVar21;
              _DAT_009e98c0 = iVar21;
              _DAT_009e98c4 = iVar19;
              if (!(bVar23 && bVar24)) goto LAB_0099f964;
              uVar15 = *(uint *)((uint)(puVar16 + 0xc) & 0xffffffc | 0x10000000);
              if ((0x270e < uVar15 - 1) || (_DAT_009e9934 == 0)) goto LAB_0099fd40;
              _DAT_009e98f0 = (_DAT_009e9934 / 10000) * 10000;
              bVar24 = 0x986f6e < _DAT_009e9934;
              if (_DAT_009e9934 < 0x986f70) {
                bVar24 = _DAT_009e9934 % 10000 <= uVar15;
              }
              if (!bVar24) {
                _DAT_009e98f0 = (_DAT_009e9934 / 10000) * 10000 + 10000;
              }
              _DAT_009e98f0 = _DAT_009e98f0 + uVar15;
              _DAT_009e98e8 = _DAT_009e9918;
              _DAT_009e98ec = _DAT_009e991c;
              _DAT_009e98f4 = _DAT_009e9924;
              _DAT_009e98f8 = _DAT_009e9928;
              _DAT_009e9900 = _DAT_009e9930;
              _DAT_009e9904 = _DAT_009e9934;
              _DAT_009e98e4 = _DAT_009e98e4 + 1;
              piVar10 = (int *)&DAT_009e98b4;
              _DAT_009e98fc = iVar3;
              _DAT_009e9908 = uVar5;
              _DAT_009e990c = iVar19;
              _DAT_009e9910 = uVar4;
              _DAT_009e9914 = iVar21;
              _DAT_009e9920 = _DAT_009e98f0;
              _DAT_009e992c = iVar3;
              _DAT_009e9938 = uVar5;
              _DAT_009e993c = iVar19;
              _DAT_009e9940 = uVar4;
              _DAT_009e9944 = iVar21;
            }
            else {
LAB_0099fd40:
              _DAT_009e991c = 0;
              piVar10 = (int *)&DAT_009e98b0;
            }
            *piVar10 = *piVar10 + 1;
          }
        }
      }
    }
LAB_0099f964:
    if ((_DAT_009b4aa0 != 0) && (iVar3 = FUN_0099aba0(), (uint)(iVar3 - _DAT_009b4a98) < 0x1389)) {
      local_34 = 0;
      local_30[0] = 0;
      FUN_00985044(&local_34,local_30);
      if (local_34 < DAT_009b49ec) {
        DAT_009b49ec = local_34;
      }
      if (local_30[0] < DAT_009b49e8) {
        DAT_009b49e8 = local_30[0];
      }
      _DAT_009e9948 = _DAT_009e9948 + 1;
    }
    (*_DAT_009ede4c)(10);
  } while( true );
}


// ===== FUN_009a00b0 @ 009a00b0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_009a00b0(void)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  int extraout_r1;
  uint extraout_r1_00;
  int extraout_r1_01;
  uint *puVar4;
  int iVar5;
  int iVar6;
  uint *puVar7;
  uint uVar8;
  bool bVar9;
  uint local_68 [6];
  int local_50 [11];
  
  iVar1 = FUN_0099aba0();
  iVar6 = _DAT_009e98dc;
  if ((999 < (uint)(iVar1 - _DAT_009e97d8)) || (_DAT_009e97d4 != _DAT_009e98dc)) {
    if (_DAT_009e743c != _DAT_009e98dc) {
      _DAT_009e743c = _DAT_009e98dc;
      _DAT_009e9728 = 0;
    }
    uVar2 = FUN_0098255c();
    if (uVar2 == 0) {
      bVar9 = _DAT_009e97d4 == iVar6;
      _DAT_009e97d4 = iVar6;
      _DAT_009e97d8 = iVar1;
      if (bVar9) {
        if (_DAT_009e971c != 0) {
          if ((uint)(iVar1 - _DAT_009e9718) < 0xea61) goto LAB_009a0164;
          _DAT_009e971c = 0;
        }
        if ((_DAT_009e971c == 0 && _DAT_009e995c != 0) && (_DAT_009ec648 == _DAT_009e995c)) {
          _DAT_009e9720 = _DAT_009e9720 + 1;
LAB_009a03b8:
          uVar2 = _DAT_009e995c;
          iVar6 = FUN_0099ab08(_DAT_009e995c);
          if ((iVar6 != 0) && ((_DAT_009ec648 == 0 || (_DAT_009ec648 + 3 < uVar2)))) {
            FUN_0099d208(local_50,uVar2);
            iVar6 = FUN_00982bd8(local_50);
            if (iVar6 == 0) {
              if (_DAT_009ec648 == 0) {
                _DAT_009ec648 = uVar2;
              }
            }
            else {
              _DAT_009ec648 = uVar2;
              FUN_0099bd2c(uVar2,1);
              _DAT_009ea25c = _DAT_009ea25c + 1;
              _DAT_009e9958 = _DAT_009e9958 + 1;
            }
          }
          if (_DAT_009ea624 != 0) {
            FUN_0099b804();
          }
          if (_DAT_009ea25c != _DAT_009e97d0) {
            _DAT_009e97d0 = _DAT_009ea25c;
            FUN_0099b750();
          }
          iVar6 = FUN_0099b044();
          if (_DAT_009ecd48 != iVar6) {
            _DAT_009ecd48 = iVar6;
            FUN_0099b4a8();
          }
          local_68[0] = 0;
          local_50[0] = 0;
          if (_DAT_009e9e28 != 0) {
            uVar3 = FUN_0099ae48(_DAT_009ec648);
            FUN_0099f638(uVar3,local_68,local_50);
          }
          if ((_DAT_009ecd50 == local_68[0]) && (_DAT_009ecd54 == local_50[0])) {
            return;
          }
          _DAT_009ecd50 = local_68[0];
          _DAT_009ecd54 = local_50[0];
          FUN_0099b4a8();
          return;
        }
      }
      else {
        _DAT_009e971c = 1;
        _DAT_009e9718 = iVar1;
      }
LAB_009a0164:
      _DAT_009e9724 = _DAT_009e9724 + 1;
      do {
        uVar2 = _DAT_009ec648;
        puVar7 = local_68;
        iVar6 = 0;
        puVar4 = puVar7;
        uVar8 = _DAT_009ec648;
        do {
          FUN_009a5ce4(uVar8,10000);
          if (extraout_r1 == 9999) break;
          iVar6 = iVar6 + 1;
          uVar8 = uVar8 + 1;
          *puVar4 = uVar8;
          puVar4 = puVar4 + 1;
        } while (iVar6 != 3);
        FUN_009a5ce4(uVar2,10000);
        if ((((0x270c < extraout_r1_00) || (_DAT_009e971c != 0)) ||
            ((_DAT_009e995c != 0 &&
             ((uVar2 / 10000 < _DAT_009e995c / 10000 || (_DAT_009e995c % 10000 < extraout_r1_00)))))
            ) && (uVar2 < 0x986f70)) {
          FUN_009a5e2c(uVar2,10000);
          iVar5 = uVar2 - extraout_r1_01;
          local_68[iVar6] = iVar5 + 0x2711;
          iVar1 = iVar6 + 2;
          local_68[iVar6 + 1] = iVar5 + 0x2712;
          iVar6 = iVar6 + 3;
          local_68[iVar1] = iVar5 + 0x2713;
        }
        iVar1 = 0;
        while( true ) {
          if (iVar6 == iVar1) goto LAB_009a03b8;
          uVar2 = *puVar7;
          FUN_0099d208(local_50,uVar2);
          iVar5 = FUN_00982bd8(local_50);
          if (iVar5 != 0) break;
          puVar7 = puVar7 + 1;
          iVar1 = iVar1 + 1;
        }
        _DAT_009ec648 = uVar2;
        FUN_0099bd2c(uVar2,1);
        _DAT_009ea25c = _DAT_009ea25c + 1;
        *(uint *)(&UNK_009e9730 + (_DAT_009e972c & 7) * 0x14) = uVar2;
        if (_DAT_009e980c == 0) {
          iVar6 = 0xffff;
        }
        else {
          iVar6 = FUN_0099aba0();
          iVar6 = iVar6 - _DAT_009e980c;
        }
        iVar1 = (_DAT_009e972c & 7) * 0x14;
        *(int *)(&UNK_009e9734 + iVar1) = iVar6;
        *(uint *)(&UNK_009e9738 + iVar1) = _DAT_009e9728;
        uVar3 = _DAT_009b4a90;
        *(undefined4 *)(&UNK_009e973c + iVar1) = _DAT_009b4a88;
        *(undefined4 *)(&UNK_009e9740 + iVar1) = uVar3;
        _DAT_009e972c = _DAT_009e972c + 1;
        _DAT_009e9728 = 0;
        if (_DAT_009e971c != 0) {
          _DAT_009e971c = 0;
          _DAT_009e9714 = _DAT_009e9714 + 1;
        }
      } while( true );
    }
    _DAT_009e9728 = _DAT_009e9728 | uVar2;
  }
                    /* WARNING: Read-only address (ram,0x009b4a88) is written */
                    /* WARNING: Read-only address (ram,0x009e980c) is written */
  return;
}


// ===== FUN_009a056c @ 009a056c

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_009a056c(undefined4 param_1,int param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  
  FUN_009a00b0();
  iVar1 = FUN_0099aba0();
  if (_DAT_009ecd40 == param_2) {
    if (param_3 < _DAT_009ecd44 + 4 && _DAT_009ecd44 <= param_3) {
      return;
    }
    if ((uint)(iVar1 - _DAT_009e7410) < 2000) {
      return;
    }
  }
  _DAT_009ecd08 = _DAT_009ecd08 + 1;
  uVar2 = _DAT_009e70d4 & 0x1f;
  _DAT_009e70d4 = _DAT_009e70d4 + 1;
  _DAT_009e7410 = iVar1;
  _DAT_009ecd40 = param_2;
  _DAT_009ecd44 = param_3;
  *(undefined4 *)(&UNK_009e70d8 + uVar2 * 0x10) = 4;
  iVar1 = uVar2 * 0x10;
  *(undefined4 *)(&UNK_009e70e0 + iVar1) = 0x4c544e4e;
  *(undefined4 *)(&UNK_009e70dc + iVar1) = 4;
  *(undefined4 *)(&UNK_009e70e4 + iVar1) = 0;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_009a05e8 @ 009a05e8

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool FUN_009a05e8(void)

{
  int iVar1;
  
  FUN_009a00b0();
  iVar1 = FUN_0099b044();
  if ((((iVar1 == 0) && (_DAT_009e98e4 == _DAT_009e98e0)) && (iVar1 = FUN_0098255c(), iVar1 == 0))
     && (_DAT_009e9700 == _DAT_009eccc0)) {
    return _DAT_009e9704 != _DAT_009ecce4;
  }
  return true;
}


// ===== FUN_009a0674 @ 009a0674

void FUN_009a0674(uint *param_1,uint param_2,uint param_3,byte param_4)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_3 >> 0x10 & 0xff;
  if ((uVar1 < 0xd) &&
     (((int)(uint)*(ushort *)(&DAT_009b1de0 + (param_3 & 0xff) * 0xc) >> uVar1 & 1U) != 0)) {
    uVar2 = 0;
    do {
      if (((int)(uint)*(ushort *)(&DAT_009b1de0 + (param_3 & 0xff) * 0xc) >> (uVar2 & 0xff) & 1U) !=
          0) break;
      uVar2 = uVar2 + 1;
    } while (uVar2 != 0xd);
    uVar1 = (param_3 >> 0x18) + 0x10 + (uVar1 - uVar2) * 0xc & 0xff;
  }
  *param_1 = param_2 & 0xffffff | *param_1 & 0xff000000;
  *(byte *)((int)param_1 + 3) = param_4 | (byte)((param_3 & 0xff) << 1);
  *(ushort *)(param_1 + 1) =
       (short)(param_3 >> 8) + 6U & 0xf | (ushort)((uVar1 & 0x3f) << 4) |
       (ushort)param_1[1] & 0xfc00;
  return;
}


// ===== FUN_009a0738 @ 009a0738

void FUN_009a0738(undefined4 param_1,uint *param_2,uint param_3,uint param_4)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  undefined8 uVar5;
  undefined4 local_18;
  
  uVar4 = *param_2;
  uVar1 = param_1;
  uVar5 = FUN_0099ab08(uVar4);
  if ((int)uVar5 == 0) {
    uVar4 = 0;
  }
  uVar2 = *(uint *)((int)((ulonglong)uVar5 >> 0x20) + 4);
  local_18 = CONCAT13((char)uVar2,(int3)uVar4);
  uVar3 = param_4 & 0xfc00 | (uVar2 & 0x3ffff) >> 8;
  uVar1 = FUN_0099cbd8(local_18,uVar3,uVar3,uVar4 & 0xffffff | param_3 & 0xff000000,uVar1,param_2);
  FUN_009a0674(param_1,uVar4 & 0xffffff,uVar1,uVar2 & 1);
  return;
}


// ===== FUN_009a07b0 @ 009a07b0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_009a07b0(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 *puVar2;
  uint uVar3;
  uint uVar4;
  undefined4 *puVar5;
  undefined4 local_20;
  undefined4 uStack_1c;
  
  uVar4 = _DAT_009ece38;
  _DAT_009ece40 = 0x3452544c;
  _DAT_009ece44 = _DAT_009ece38;
  _DAT_009ece46 = 0;
  puVar2 = (undefined4 *)&DAT_009ece40;
  local_20 = param_1;
  uStack_1c = param_2;
  for (uVar3 = 0; uVar4 != uVar3; uVar3 = uVar3 + 1) {
    puVar5 = puVar2 + 2;
    FUN_0099aea8(puVar5,*puVar5,puVar2[3]);
    puVar2 = puVar5;
  }
  iVar1 = FUN_00982e28(&PTR_s_A__LATENT_ROLL_A_009b4a28,&DAT_009ece40,(uVar4 + 1) * 8);
  _DAT_009e9a04 = (uint)(iVar1 != 0);
  puVar2 = (undefined4 *)&DAT_009ece40;
  for (uVar4 = 0; uVar4 < _DAT_009ece38; uVar4 = uVar4 + 1) {
    puVar5 = puVar2 + 2;
    FUN_009a0738(&local_20,puVar5);
    *puVar5 = local_20;
    puVar2[3] = uStack_1c;
    puVar2 = puVar5;
  }
  return -(uint)(_DAT_009e9a04 != 0);
}


// ===== FUN_009a087c @ 009a087c

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_009a087c(uint param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined *puVar2;
  uint uVar3;
  uint uVar4;
  
  uVar4 = 0;
  while( true ) {
    if (_DAT_009ece38 == uVar4) {
      return 0;
    }
    uVar3 = uVar4 + 1;
    if ((*(uint *)(&DAT_009ece40 + uVar3 * 8) & 0xffffff) == param_1) break;
    uVar4 = uVar3;
  }
  uVar1 = *(undefined4 *)(&DAT_009ece44 + uVar3 * 8);
  *param_2 = *(undefined4 *)(&DAT_009ece40 + uVar3 * 8);
  param_2[1] = uVar1;
  puVar2 = &DAT_009ece40 + uVar4 * 8;
  for (; uVar3 < _DAT_009ece38; uVar3 = uVar3 + 1) {
    *(undefined4 *)(puVar2 + 8) = *(undefined4 *)(puVar2 + 0x10);
    *(undefined4 *)(puVar2 + 0xc) = *(undefined4 *)(puVar2 + 0x14);
    puVar2 = puVar2 + 8;
  }
  _DAT_009ece38 = _DAT_009ece38 - 1;
  FUN_009a07b0();
  return 1;
}


// ===== FUN_009a0908 @ 009a0908

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_009a0908(uint param_1)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined *puVar5;
  uint uVar6;
  undefined4 uVar7;
  int iVar8;
  int iVar9;
  bool bVar10;
  uint *puVar11;
  undefined4 *puVar12;
  undefined4 local_50;
  undefined4 uStack_4c;
  undefined1 auStack_48 [44];
  
  iVar8 = 0;
  do {
    if (_DAT_009ece38 == iVar8) {
      puVar11 = (uint *)&DAT_009e95b0;
      uVar6 = 0;
      while( true ) {
        if (_DAT_009e95ac == uVar6) {
          return param_1;
        }
        if (*puVar11 == param_1) break;
        puVar11 = puVar11 + 1;
        uVar6 = uVar6 + 1;
      }
      if (_DAT_009e95ac <= uVar6) {
        return param_1;
      }
      puVar12 = (undefined4 *)(&DAT_009e95b0 + uVar6 * 4);
      while (uVar6 = uVar6 + 1, _DAT_009e95ac != uVar6) {
        *puVar12 = puVar12[1];
        puVar12 = puVar12 + 1;
      }
      iVar9 = _DAT_009e95ac - 1;
      iVar8 = 0;
      puVar12 = (undefined4 *)&DAT_009e95b0;
      puVar5 = &DAT_009e95e0;
      _DAT_009e95ac = iVar9;
      if (iVar9 != 0) {
        do {
          uVar7 = *puVar12;
          iVar8 = iVar8 + 1;
          *puVar5 = (char)uVar7;
          puVar5[1] = (char)((uint)uVar7 >> 8);
          puVar5[2] = (char)((uint)uVar7 >> 0x10);
          puVar5[3] = (char)((uint)uVar7 >> 0x18);
          puVar5 = puVar5 + 4;
          puVar12 = puVar12 + 1;
        } while (iVar9 != iVar8);
      }
      iVar9 = iVar9 * 4;
      iVar8 = iRam009b49bc + 1;
      _DAT_009b4b40 = 0x4352544c;
      _DAT_009b4b44 = iVar8;
      _DAT_009b4b48 = iVar9;
      _DAT_009b4b4c = FUN_00982ce4(&DAT_009e95e0,iVar9);
      uVar7 = uRam009b49b4;
      if (bRam009b49c0 == 0) {
        uVar7 = _DAT_009b49b0;
      }
      iVar2 = FUN_009828c0(uVar7);
      if (iVar2 < 0) {
        bVar10 = false;
      }
      else {
        iVar3 = FUN_009829b8(iVar2,&DAT_009b4b40,0x10);
        if (iVar3 == 0) {
          if (iVar9 == 0) {
            bVar10 = true;
          }
          else {
            iVar9 = FUN_009829b8(iVar2,&DAT_009e95e0,iVar9);
            bVar10 = iVar9 == 0;
          }
        }
        else {
          bVar10 = false;
        }
        iVar9 = FUN_00982a90(iVar2,1);
        if (iVar9 != 0) {
          bVar10 = false;
        }
      }
      iRam009b49c4 = iRam009b49c4 + 1;
      if (bVar10) {
        iRam009b49bc = iVar8;
        bRam009b49c0 = bRam009b49c0 ^ 1;
        return 0;
      }
      iRam009b49c8 = iRam009b49c8 + 1;
      return 0xffffffff;
    }
    iVar8 = iVar8 + 1;
    iVar9 = iVar8 * 8;
  } while ((*(uint *)(&DAT_009ece40 + iVar8 * 8) & 0xffffff) != param_1);
  local_50 = *(undefined4 *)(&DAT_009ece40 + iVar9);
  uStack_4c = *(undefined4 *)(&DAT_009ece44 + iVar9);
  if (_DAT_009e96d4 != 0) {
    puVar11 = (uint *)&DAT_009e95b0;
    bVar1 = (&DAT_009ece43)[iVar9];
    for (uVar6 = 0; _DAT_009e95ac != uVar6; uVar6 = uVar6 + 1) {
      if (*puVar11 == param_1) goto LAB_009a098c;
      puVar11 = puVar11 + 1;
    }
    if (_DAT_009e95ac != 8) {
      iVar8 = _DAT_009e95ac * 4;
      _DAT_009e95ac = _DAT_009e95ac + 1;
      *(uint *)(&DAT_009e95b0 + iVar8) = param_1;
    }
LAB_009a098c:
    iVar8 = FUN_0099b860();
    if (iVar8 != 0) goto LAB_009a09a8;
    if (_DAT_009e96d4 != 0) {
      FUN_0099d198(auStack_48,param_1,&LAB_009a6fda);
      FUN_00982bac(auStack_48);
      FUN_0099d208(auStack_48,param_1);
      FUN_00982bac(auStack_48);
      if ((_DAT_009e96d4 != 0) && (iVar8 = FUN_0099d214(param_1), iVar8 == 0)) {
        FUN_0099f130(param_1,bVar1 >> 1);
        FUN_009a087c(param_1,&local_50);
        FUN_0099bd2c(param_1,0);
        FUN_0099b960(param_1,0);
        uVar4 = FUN_0099b508(param_1);
        puVar11 = (uint *)&DAT_009e95b0;
        uVar6 = 0;
        do {
          if (_DAT_009e95ac == uVar6) {
LAB_009a0b24:
            _DAT_009e95a8 = 1;
            _DAT_009e96d0 = _DAT_009e96d0 + 1;
            return uVar4;
          }
          uVar4 = *puVar11;
          if (uVar4 == param_1) {
            if (uVar6 < _DAT_009e95ac) {
              puVar12 = (undefined4 *)(&DAT_009e95b0 + uVar6 * 4);
              while (uVar6 = uVar6 + 1, _DAT_009e95ac != uVar6) {
                *puVar12 = puVar12[1];
                puVar12 = puVar12 + 1;
              }
              _DAT_009e95ac = _DAT_009e95ac - 1;
              uVar4 = FUN_0099b860();
            }
            goto LAB_009a0b24;
          }
          puVar11 = puVar11 + 1;
          uVar6 = uVar6 + 1;
        } while( true );
      }
    }
  }
  _DAT_009e95a8 = 1;
LAB_009a09a8:
  _DAT_009e96cc = _DAT_009e96cc + 1;
  uVar6 = FUN_0099b4c4(local_50,uStack_4c);
  return uVar6;
}


// ===== FUN_009a090c @ 009a090c

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_009a090c(uint param_1,undefined4 param_2,undefined4 param_3,int *param_4)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined *puVar5;
  uint uVar6;
  undefined4 uVar7;
  int iVar8;
  int iVar9;
  bool bVar10;
  uint *puVar11;
  undefined4 *puVar12;
  undefined4 local_50;
  undefined4 uStack_4c;
  undefined1 auStack_48 [44];
  
  iVar8 = 0;
  do {
    if (*param_4 == iVar8) {
      puVar11 = (uint *)&DAT_009e95b0;
      uVar6 = 0;
      while( true ) {
        if (_DAT_009e95ac == uVar6) {
          return param_1;
        }
        if (*puVar11 == param_1) break;
        puVar11 = puVar11 + 1;
        uVar6 = uVar6 + 1;
      }
      if (_DAT_009e95ac <= uVar6) {
        return param_1;
      }
      puVar12 = (undefined4 *)(&DAT_009e95b0 + uVar6 * 4);
      while (uVar6 = uVar6 + 1, _DAT_009e95ac != uVar6) {
        *puVar12 = puVar12[1];
        puVar12 = puVar12 + 1;
      }
      iVar9 = _DAT_009e95ac - 1;
      iVar8 = 0;
      puVar12 = (undefined4 *)&DAT_009e95b0;
      puVar5 = &DAT_009e95e0;
      _DAT_009e95ac = iVar9;
      if (iVar9 != 0) {
        do {
          uVar7 = *puVar12;
          iVar8 = iVar8 + 1;
          *puVar5 = (char)uVar7;
          puVar5[1] = (char)((uint)uVar7 >> 8);
          puVar5[2] = (char)((uint)uVar7 >> 0x10);
          puVar5[3] = (char)((uint)uVar7 >> 0x18);
          puVar5 = puVar5 + 4;
          puVar12 = puVar12 + 1;
        } while (iVar9 != iVar8);
      }
      iVar9 = iVar9 * 4;
      iVar8 = iRam009b49bc + 1;
      _DAT_009b4b40 = 0x4352544c;
      _DAT_009b4b44 = iVar8;
      _DAT_009b4b48 = iVar9;
      _DAT_009b4b4c = FUN_00982ce4(&DAT_009e95e0,iVar9);
      uVar7 = uRam009b49b4;
      if (bRam009b49c0 == 0) {
        uVar7 = _DAT_009b49b0;
      }
      iVar2 = FUN_009828c0(uVar7);
      if (iVar2 < 0) {
        bVar10 = false;
      }
      else {
        iVar3 = FUN_009829b8(iVar2,&DAT_009b4b40,0x10);
        if (iVar3 == 0) {
          if (iVar9 == 0) {
            bVar10 = true;
          }
          else {
            iVar9 = FUN_009829b8(iVar2,&DAT_009e95e0,iVar9);
            bVar10 = iVar9 == 0;
          }
        }
        else {
          bVar10 = false;
        }
        iVar9 = FUN_00982a90(iVar2,1);
        if (iVar9 != 0) {
          bVar10 = false;
        }
      }
      iRam009b49c4 = iRam009b49c4 + 1;
      if (bVar10) {
        iRam009b49bc = iVar8;
        bRam009b49c0 = bRam009b49c0 ^ 1;
        return 0;
      }
      iRam009b49c8 = iRam009b49c8 + 1;
      return 0xffffffff;
    }
    iVar8 = iVar8 + 1;
    iVar9 = iVar8 * 8;
  } while ((*(uint *)(&DAT_009ece40 + iVar8 * 8) & 0xffffff) != param_1);
  local_50 = *(undefined4 *)(&DAT_009ece40 + iVar9);
  uStack_4c = *(undefined4 *)(&DAT_009ece44 + iVar9);
  if (_DAT_009e96d4 != 0) {
    puVar11 = (uint *)&DAT_009e95b0;
    bVar1 = (&DAT_009ece43)[iVar9];
    for (uVar6 = 0; _DAT_009e95ac != uVar6; uVar6 = uVar6 + 1) {
      if (*puVar11 == param_1) goto LAB_009a098c;
      puVar11 = puVar11 + 1;
    }
    if (_DAT_009e95ac != 8) {
      iVar8 = _DAT_009e95ac * 4;
      _DAT_009e95ac = _DAT_009e95ac + 1;
      *(uint *)(&DAT_009e95b0 + iVar8) = param_1;
    }
LAB_009a098c:
    iVar8 = FUN_0099b860();
    if (iVar8 != 0) goto LAB_009a09a8;
    if (_DAT_009e96d4 != 0) {
      FUN_0099d198(auStack_48,param_1,&LAB_009a6fda);
      FUN_00982bac(auStack_48);
      FUN_0099d208(auStack_48,param_1);
      FUN_00982bac(auStack_48);
      if ((_DAT_009e96d4 != 0) && (iVar8 = FUN_0099d214(param_1), iVar8 == 0)) {
        FUN_0099f130(param_1,bVar1 >> 1);
        FUN_009a087c(param_1,&local_50);
        FUN_0099bd2c(param_1,0);
        FUN_0099b960(param_1,0);
        uVar4 = FUN_0099b508(param_1);
        puVar11 = (uint *)&DAT_009e95b0;
        uVar6 = 0;
        do {
          if (_DAT_009e95ac == uVar6) {
LAB_009a0b24:
            _DAT_009e95a8 = 1;
            _DAT_009e96d0 = _DAT_009e96d0 + 1;
            return uVar4;
          }
          uVar4 = *puVar11;
          if (uVar4 == param_1) {
            if (uVar6 < _DAT_009e95ac) {
              puVar12 = (undefined4 *)(&DAT_009e95b0 + uVar6 * 4);
              while (uVar6 = uVar6 + 1, _DAT_009e95ac != uVar6) {
                *puVar12 = puVar12[1];
                puVar12 = puVar12 + 1;
              }
              _DAT_009e95ac = _DAT_009e95ac - 1;
              uVar4 = FUN_0099b860();
            }
            goto LAB_009a0b24;
          }
          puVar11 = puVar11 + 1;
          uVar6 = uVar6 + 1;
        } while( true );
      }
    }
  }
  _DAT_009e95a8 = 1;
LAB_009a09a8:
  _DAT_009e96cc = _DAT_009e96cc + 1;
  uVar6 = FUN_0099b4c4(local_50,uStack_4c);
  return uVar6;
}


// ===== FUN_009a0b98 @ 009a0b98

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_009a0b98(uint param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined *puVar2;
  int iVar3;
  
  iVar3 = 0;
  while (_DAT_009ece38 != iVar3) {
    if (((*(uint *)(&DAT_009ece40 + (iVar3 + 1) * 8) ^ param_1) & 0xffffff) == 0) goto LAB_009a0bd0;
    iVar3 = iVar3 + 1;
  }
  if (_DAT_009ece38 == 0x200) {
    iVar3 = 1;
    puVar2 = &DAT_009ece40;
    do {
      iVar3 = iVar3 + 1;
      *(undefined4 *)(puVar2 + 8) = *(undefined4 *)(puVar2 + 0x10);
      *(undefined4 *)(puVar2 + 0xc) = *(undefined4 *)(puVar2 + 0x14);
      puVar2 = puVar2 + 8;
    } while (iVar3 != 0x200);
    iVar3 = 0x1ff;
  }
  _DAT_009ece38 = iVar3 + 1;
LAB_009a0bd0:
  iVar3 = (iVar3 + 1) * 8;
  *(uint *)(&DAT_009ece40 + iVar3) = param_1;
  *(undefined4 *)(&DAT_009ece44 + iVar3) = param_2;
  uVar1 = FUN_009a07b0();
  iVar3 = (_DAT_009ecd68 & 7) * 8;
  *(uint *)(&UNK_009ecd6c + iVar3) = param_1;
  *(undefined4 *)(&UNK_009ecd70 + iVar3) = param_2;
  _DAT_009ecd68 = _DAT_009ecd68 + 1;
  FUN_0098a59c(3);
  return uVar1;
}


// ===== FUN_009a0b9c @ 009a0b9c

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_009a0b9c(uint param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  undefined4 uVar1;
  undefined *puVar2;
  int iVar3;
  
  while (_DAT_009ece38 != param_4) {
    if (((*(uint *)(&DAT_009ece40 + (param_4 + 1) * 8) ^ param_1) & 0xffffff) == 0)
    goto LAB_009a0bd0;
    param_4 = param_4 + 1;
  }
  if (_DAT_009ece38 == 0x200) {
    iVar3 = 1;
    puVar2 = &DAT_009ece40;
    do {
      iVar3 = iVar3 + 1;
      *(undefined4 *)(puVar2 + 8) = *(undefined4 *)(puVar2 + 0x10);
      *(undefined4 *)(puVar2 + 0xc) = *(undefined4 *)(puVar2 + 0x14);
      puVar2 = puVar2 + 8;
    } while (iVar3 != 0x200);
    param_4 = 0x1ff;
  }
  _DAT_009ece38 = param_4 + 1;
LAB_009a0bd0:
  iVar3 = (param_4 + 1) * 8;
  *(uint *)(&DAT_009ece40 + iVar3) = param_1;
  *(undefined4 *)(&DAT_009ece44 + iVar3) = param_2;
  uVar1 = FUN_009a07b0();
  iVar3 = (_DAT_009ecd68 & 7) * 8;
  *(uint *)(&UNK_009ecd6c + iVar3) = param_1;
  *(undefined4 *)(&UNK_009ecd70 + iVar3) = param_2;
  _DAT_009ecd68 = _DAT_009ecd68 + 1;
  FUN_0098a59c(3);
  return uVar1;
}


// ===== FUN_009a0c78 @ 009a0c78

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_009a0c78(undefined4 param_1,byte *param_2)

{
  byte *pbVar1;
  byte *pbVar2;
  int iVar3;
  uint uVar4;
  bool bVar5;
  undefined4 local_48;
  undefined4 uStack_44;
  undefined1 auStack_40 [32];
  
  uVar4 = _DAT_009e9710;
  if (_DAT_009e96e8 == 0) {
    FUN_009a0674(&local_48,_DAT_009e9710,_DAT_009e96fc,0);
    if (_DAT_009ecc4c == param_2) {
      _DAT_009ecc70 = uVar4;
      iVar3 = 0x15;
      _DAT_009ecc6c = _DAT_009ecc50;
      FUN_0098a59c(4);
      while ((_DAT_009ecc70 != 0 && (iVar3 = iVar3 + -1, iVar3 != 0))) {
        (*_DAT_009ede4c)(10);
      }
      iVar3 = FUN_0099af10(_DAT_009e9710);
      if (iVar3 == 0) {
        FUN_0099b4c4(local_48,uStack_44);
      }
    }
    else {
      _DAT_009e9950 = uVar4;
      _DAT_009e96dc = uVar4;
      _DAT_009e96e0 = 0x811c9dc5;
      pbVar1 = param_2;
      do {
        pbVar2 = pbVar1 + 1;
        _DAT_009e96e0 = (_DAT_009e96e0 ^ *pbVar1) * 0x1000193;
        pbVar1 = pbVar2;
      } while (param_2 + 0x3f480 != pbVar2);
      _DAT_009e9954 = param_2;
      iVar3 = FUN_0099af10(uVar4);
      if (iVar3 == 0) {
        FUN_0099b4c4(local_48,uStack_44);
        uVar4 = 0;
        do {
          if ((_DAT_009ecd1c == _DAT_009ecd20) && (_DAT_009ecd18 == _DAT_009e9710)) break;
          bVar5 = _DAT_009e9710 <= _DAT_009ecd28;
          if (_DAT_009ecd28 != _DAT_009e9710) {
            bVar5 = 0xc6 < uVar4;
          }
          if (bVar5 && (_DAT_009ecd28 != _DAT_009e9710 && uVar4 != 199)) break;
          uVar4 = uVar4 + 10;
          (*_DAT_009ede4c)(10);
        } while (uVar4 != 1000);
      }
    }
    FUN_0099d264(auStack_40,_DAT_009e9710,&DAT_009a7e01);
    iVar3 = FUN_00982c98(auStack_40,param_2,0x3f480);
    _DAT_009e9954 = (byte *)0x0;
    if (iVar3 == 0) {
      _DAT_009ea258 = _DAT_009ea258 + 1;
      iVar3 = FUN_009a0b98(local_48,uStack_44);
      if (iVar3 == 0) {
        FUN_0099bd2c(_DAT_009e9710);
      }
    }
    else {
      _DAT_009e96f0 = 1;
      iVar3 = FUN_0099af10(_DAT_009e9710);
      if (iVar3 == 0) {
        FUN_0099b508(_DAT_009e9710);
      }
    }
  }
  else {
    _DAT_009e96e4 = 0x811c9dc5;
    pbVar1 = param_2;
    do {
      pbVar2 = pbVar1 + 1;
      _DAT_009e96e4 = (_DAT_009e96e4 ^ *pbVar1) * 0x1000193;
      pbVar1 = pbVar2;
    } while (param_2 + 0x3f480 != pbVar2);
  }
  return;
}


// ===== FUN_009a0f18 @ 009a0f18

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_009a0f18(uint param_1,undefined4 param_2,uint param_3,uint param_4)

{
  char cVar1;
  byte bVar2;
  undefined *puVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  undefined1 *puVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  char *pcVar10;
  uint uVar11;
  uint uVar12;
  int iVar13;
  uint uVar14;
  char *pcVar15;
  char *pcVar16;
  undefined4 local_114;
  undefined1 auStack_110 [20];
  undefined1 auStack_fc [40];
  undefined1 auStack_d4 [40];
  undefined1 auStack_ac [40];
  undefined1 auStack_84 [40];
  code *local_5c;
  code *local_58;
  code *local_54;
  undefined4 local_50;
  undefined *local_4c;
  undefined1 *local_48;
  code *local_44;
  int local_40;
  code *local_3c;
  undefined *local_38;
  undefined4 local_34;
  int local_30;
  undefined1 *local_2c;
  
  local_114 = param_2;
  FUN_0099d264(&UNK_009e7414,param_1,&DAT_009a7e27);
  local_114 = FUN_0098a9d8(&DAT_009b1ddc,0x51,local_114);
  uVar12 = local_114 & 0xff;
  _DAT_009e9710 = param_1;
  FUN_009975a8(&DAT_009e96fc,&local_114);
  FUN_0099d208(auStack_fc,param_1);
  FUN_0099f090(auStack_d4,param_1,uVar12,&LAB_009a6fda);
  FUN_0099b3d0(auStack_110,local_114,auStack_ac,auStack_84);
  iVar8 = 0;
  puVar6 = &DAT_009ea268;
  do {
    iVar8 = iVar8 + 1;
    *puVar6 = 0;
    puVar6 = puVar6 + 1;
  } while (iVar8 != 0x1a8);
  _DAT_009ecd40 = 2 - param_3;
  _DAT_009ecd44 = 0;
  _DAT_009ecd3c = param_1;
  FUN_0099b4a8();
  _DAT_009e96f0 = 0;
  iVar8 = FUN_0098533c(&DAT_009ea268,auStack_110);
  if (iVar8 == 0) {
    uVar9 = param_3 & 1;
  }
  else {
    uVar9 = 0;
  }
  if (uVar9 == 0) {
    _DAT_009ecc4c = 0;
    if (iVar8 == 0) goto LAB_009a1064;
  }
  else {
    iVar8 = 0x33;
    iVar13 = _DAT_009ecc50 + 1;
    _DAT_009ecc50 = iVar13;
    _DAT_009ecc84 = iVar13;
    FUN_0098a59c(4);
    while ((iVar13 != _DAT_009ecc80 && (iVar8 = iVar8 + -1, iVar8 != 0))) {
      (*_DAT_009ede4c)(10);
    }
    if (iVar13 == _DAT_009ecc80) {
      if (_DAT_009ecc7c == 3) {
        _DAT_009ecc58 = _DAT_009ecc58 + 1;
        iVar8 = -0x29;
        _DAT_009ecc4c = 0;
        _DAT_009ecc78 = iVar13;
        goto LAB_009a1318;
      }
      if (_DAT_009ecc7c < 2) {
        _DAT_009ecc4c = *(int *)(&DAT_009ecd34 + _DAT_009ecc7c * 4);
        goto LAB_009a1064;
      }
    }
    _DAT_009ecc4c = 0;
    _DAT_009ecc78 = iVar13;
LAB_009a1064:
    local_5c = _DAT_009ede4c;
    uVar9 = (uint)local_114._1_1_;
    local_58 = FUN_009a056c;
    local_54 = FUN_009a0c78;
    if (param_3 == 0) {
      local_54 = (code *)0x0;
    }
    local_50 = 0;
    iVar8 = (&DAT_009b2254)[uVar12 * 3];
    pcVar10 = (char *)(iVar8 + -1);
    uVar7 = local_114 >> 0x10 & 0xff;
    uVar14 = local_114 >> 0x18;
    pcVar16 = (&PTR_DAT_009b2634)[(byte)(&LAB_009b225e)[uVar12 * 0xc]] + -1;
    pcVar15 = pcVar10;
    do {
      pcVar16 = pcVar16 + 1;
      if (*pcVar16 == '\0') goto LAB_009a1108;
      pcVar15 = pcVar15 + 1;
    } while (*pcVar15 == *pcVar16);
    pcVar15 = "Kodachrome";
    do {
      if ((char *)(iVar8 + 9) == pcVar10) goto LAB_009a1108;
      cVar1 = *pcVar15;
      pcVar10 = pcVar10 + 1;
      pcVar15 = pcVar15 + 1;
    } while (*pcVar10 == cVar1);
    if (cVar1 == '\0') {
LAB_009a1108:
      puVar3 = &UNK_009e73a0;
    }
    else {
      uVar4 = FUN_0099aab4(&UNK_009e73a0);
      puVar3 = (undefined *)FUN_0099aab4(uVar4,&DAT_009a7e38);
    }
    uVar4 = FUN_0099aab4(puVar3,iVar8);
    if (uVar9 != 0) {
      if ((int)uVar9 < 1) {
        pcVar15 = ", pulled ";
      }
      else {
        pcVar15 = ", pushed ";
      }
      uVar4 = FUN_0099aab4(uVar4,pcVar15);
      uVar4 = FUN_0099aab4(uVar4,*(undefined4 *)
                                  (&DAT_009b1cc8 +
                                  ((uVar9 ^ (int)uVar9 >> 0x1f) - ((int)uVar9 >> 0x1f) & 0xff) * 4))
      ;
      if (uVar9 == 3 || uVar9 == 0xfffffffd) {
        pcVar15 = " stop";
      }
      else {
        pcVar15 = " stops";
        if (uVar9 != 0xfffffffa && uVar9 != 6) {
          pcVar15 = " stop";
        }
      }
      uVar4 = FUN_0099aab4(uVar4,pcVar15);
    }
    if (uVar7 < 0xd) {
      uVar9 = (uint)*(ushort *)(&DAT_009b1de0 + uVar12 * 0xc);
    }
    else {
      uVar9 = 0;
    }
    if (uVar7 < 0xd) {
      uVar9 = (int)uVar9 >> (uVar7 & 0xff);
    }
    bVar2 = (&DAT_009b1dde)[uVar12 * 0xc];
    if (uVar7 < 0xd) {
      uVar9 = uVar9 & 1;
    }
    uVar11 = uVar9;
    if (1 < bVar2) {
      uVar11 = uVar9 | 1;
    }
    if (uVar11 != 0) {
      uVar4 = FUN_0099aab4(uVar4,&DAT_009a7e37);
      if (bVar2 <= uVar7) {
        uVar7 = 0;
      }
      uVar4 = FUN_0099aab4(uVar4,(&PTR_s_Endura_Premier_009b1d90)
                                 [*(byte *)(*(int *)(&DAT_009b1de4 + uVar12 * 0xc) + uVar7)]);
      if (uVar9 != 0) {
        uVar4 = FUN_0099aab4(uVar4," grade ");
        if (0xb < uVar14) {
          uVar14 = 5;
        }
        FUN_0099aab4(uVar4,*(undefined4 *)(&DAT_009b1c98 + uVar14 * 4));
      }
    }
    local_4c = &UNK_009e73a0;
    local_48 = &LAB_0099bec8;
    local_44 = FUN_0099b9f0;
    local_40 = _DAT_009e7568;
    local_3c = FUN_0099b2cc;
    if (_DAT_009e7568 == 0) {
      local_3c = (code *)0x0;
    }
    local_38 = &UNK_009e7414;
    if (DAT_009b4a60 < 3) {
      uVar12 = DAT_009b4a60;
    }
    else {
      uVar12 = 2;
    }
    local_34 = *(undefined4 *)(&DAT_009b1d74 + uVar12 * 4);
    local_30 = _DAT_009ecc4c;
    local_2c = &LAB_0099b490;
    if (_DAT_009ecc4c == 0) {
      local_2c = (undefined1 *)0x0;
    }
    if (param_4 == 0) {
      puVar6 = (undefined1 *)0x0;
    }
    else {
      puVar6 = auStack_d4;
    }
    _DAT_009e9708 = param_4;
    iVar8 = FUN_009865ac(&DAT_009ea268,&local_5c,auStack_fc,puVar6);
    _DAT_009e9708 = 0;
    if (iVar8 == 0 && _DAT_009e96f0 != 0) {
      iVar8 = -0x28;
      _DAT_009e96ec = _DAT_009e96ec + 1;
    }
  }
LAB_009a1318:
  if (_DAT_009ecc4c != 0) {
    if (iVar8 == -0xe) {
      _DAT_009ecc54 = _DAT_009ecc54 + 1;
    }
    _DAT_009ecc4c = 0;
    _DAT_009ecc78 = _DAT_009ecc50;
    FUN_0098a59c(4);
  }
  if (iVar8 == 0) {
    uVar12 = 0;
  }
  else {
    uVar12 = param_4 & 1;
  }
  if (uVar12 == 0) {
    if (iVar8 != 0) goto LAB_009a13a0;
    if ((_DAT_009ecd5c <= param_1) && (_DAT_009ea3e4 != 0)) {
      _DAT_009ecd60 = _DAT_009ea3e4;
      _DAT_009ecd64 = _DAT_009ea3f0;
      _DAT_009ecd5c = param_1;
    }
    if ((_DAT_009ea404 & 0x80) != 0) {
      _DAT_009ec828 = _DAT_009ec828 + 1;
      _DAT_009ec82c = param_1;
      FUN_0098a59c(4);
    }
    if (param_4 == 0) goto LAB_009a14d8;
    _DAT_009ea254 = _DAT_009ea254 + 1;
    puVar5 = (undefined4 *)FUN_009a0674(&local_5c,param_1,local_114,1);
    FUN_009a0b98(*puVar5,puVar5[1]);
LAB_009a1498:
    _DAT_009e970c = 0;
    goto LAB_009a14a0;
  }
  if (_DAT_009e96d4 != 0) {
    FUN_00982bac(auStack_d4);
    _DAT_009e96d8 = _DAT_009e96d8 + 1;
  }
LAB_009a13a0:
  if (iVar8 == -0x29) {
LAB_009a13a8:
    _DAT_009e96f8 = FUN_0099aba0();
    _DAT_009e96f8 = _DAT_009e96f8 + 700;
LAB_009a13b8:
    _DAT_009e970c = 0;
  }
  else {
LAB_009a14d8:
    if ((param_3 & 1 & (uint)(iVar8 == -0xe)) != 0) goto LAB_009a13a8;
    if (iVar8 == -0xe) {
      _DAT_009ea244 = _DAT_009ea244 + 1;
      goto LAB_009a13b8;
    }
    if (iVar8 < -0xd) {
      if (iVar8 == -0x16) {
        FUN_0099b18c(_DAT_009ea3b4,_DAT_009ea3b8);
      }
      else {
        if (iVar8 != -0x15) goto LAB_009a1510;
        (*_DAT_009ede4c)(500);
      }
      goto LAB_009a13b8;
    }
    if (iVar8 != -7) {
      if (iVar8 == 0) goto LAB_009a1498;
LAB_009a1510:
      _DAT_009ea250 = _DAT_009ea250 + 1;
      _DAT_009ecd4c = param_1;
      if ((param_3 == 0) || (iVar13 = FUN_0099af90(param_1), iVar13 == 0)) {
        puVar3 = &DAT_009ea51c;
        uVar12 = _DAT_009ea518;
        _DAT_009ea518 = _DAT_009ea518 + 1;
      }
      else {
        puVar3 = &DAT_009ea418;
        uVar12 = _DAT_009ea414;
        _DAT_009ea414 = _DAT_009ea414 + 1;
      }
      *(uint *)(puVar3 + (uVar12 & 0x3f) * 4) = param_1;
      goto LAB_009a13b8;
    }
    _DAT_009ea240 = _DAT_009ea240 + 1;
    FUN_009852b0();
    _DAT_009e96f4 = 1;
    _DAT_009e96f8 = FUN_0099aba0();
    _DAT_009e96f8 = _DAT_009e96f8 + (2000 << (_DAT_009e970c & 0xff));
    if (_DAT_009e970c < 2) {
      _DAT_009e970c = _DAT_009e970c + 1;
    }
  }
  if (_DAT_009ecd4c != 0 && _DAT_009ecd4c < param_1) {
    _DAT_009ecd4c = 0;
  }
LAB_009a14a0:
  _DAT_009ecd3c = 0;
  _DAT_009ecd44 = 0;
  FUN_0099b4a8();
  _DAT_009e756c = param_3 | param_4 << 1;
  if (iVar8 != -0x16) {
    FUN_0099d294(param_1);
  }
  return iVar8;
}


// ===== FUN_009a1714 @ 009a1714

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_009a1714(void)

{
  undefined1 uVar1;
  undefined2 uVar2;
  byte bVar3;
  int iVar4;
  char *pcVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  uint *puVar9;
  int extraout_r1;
  char *pcVar10;
  byte *pbVar11;
  undefined1 *puVar12;
  undefined4 uVar13;
  int *piVar14;
  char *pcVar15;
  uint uVar16;
  undefined4 uVar17;
  int iVar18;
  undefined *puVar19;
  uint uVar20;
  uint uVar21;
  undefined4 *puVar22;
  uint uVar23;
  uint uVar24;
  undefined4 *puVar25;
  uint uVar26;
  bool bVar27;
  bool bVar28;
  undefined8 uVar29;
  int local_cc;
  uint local_c8;
  int local_c4;
  uint local_c0;
  uint local_bc;
  uint local_b8;
  undefined4 local_b4;
  undefined4 local_b0;
  undefined4 local_ac;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  uint local_98;
  uint local_94 [5];
  undefined4 local_80;
  undefined4 uStack_7c;
  undefined4 local_58;
  int iStack_54;
  
  (*_DAT_009ede4c)(5000);
  iVar18 = 0;
  puVar25 = (undefined4 *)&DAT_009e7514;
  puVar22 = &DAT_009b1d24;
  do {
    iVar4 = (*(code *)&SUB_ffb5610c)(*puVar22);
    local_58 = 0xffffffff;
    if (1 < iVar4 + 1U) {
      (*(code *)&SUB_ffb57968)(iVar4,&local_58);
    }
    iVar18 = iVar18 + 1;
    *puVar25 = local_58;
    puVar25 = puVar25 + 1;
    puVar22 = puVar22 + 1;
  } while (iVar18 != 0x14);
  FUN_00985044(&DAT_009ea264,&DAT_009ea260);
  local_c0 = 0;
  iVar18 = FUN_00982f20(&PTR_s_A__LATENT_FILM_A_009b4974,&DAT_009e74e0,0x1f,&local_c0);
  bVar27 = local_c0 < 7;
  local_58 = 0;
  iVar4 = FUN_00982f20(&DAT_009b4958,&DAT_009e74c0,0x20,&local_58);
  if (((iVar4 == 0) && (local_58 != 0)) && (DAT_009e74c0 < 3)) {
    _DAT_009ec834 = _DAT_009ec834 + 1;
    DAT_009b4a60 = (uint)DAT_009e74c0;
    FUN_0098a59c(4);
  }
  local_cc = _DAT_009ec838;
  if (3 < local_c0) {
    iVar4 = 0;
    pcVar15 = (char *)((int)&DAT_009b2254 + 3);
    do {
      pcVar10 = &DAT_009e74e0;
      pcVar5 = pcVar15;
      while (pcVar5 = pcVar5 + 1, *pcVar5 == *pcVar10) {
        pcVar10 = pcVar10 + 1;
        if (pcVar5 == pcVar15 + 4) {
          local_58 = FUN_0098a930(&DAT_009b1ddc);
          if (6 < local_c0) {
            local_58 = CONCAT13(DAT_009e74e6,
                                CONCAT12(DAT_009e74e5,
                                         CONCAT11(DAT_009e74e4 + -6,(undefined1)local_58)));
          }
          local_bc = FUN_0098a9d8(&DAT_009b1ddc,0x51,local_58);
          DAT_009b4a7c = local_bc & 0xffff00ff | ((local_bc >> 8) + 6 & 0xff) << 8;
          goto LAB_009a186c;
        }
      }
      iVar4 = iVar4 + 1;
      pcVar15 = pcVar15 + 0xc;
    } while (iVar4 != 0x51);
  }
LAB_009a186c:
  local_80 = 0;
  _DAT_009ece38 = 0;
  iVar4 = FUN_00982f20(&PTR_s_A__LATENT_ROLL_A_009b4a28,&DAT_009ece40,0x1008,&local_80);
  if ((((iVar4 == 0) && (7 < local_80)) &&
      ((DAT_009ece40 == 'L' && ((DAT_009ece41 == 'T' && (DAT_009ece42 == 'R')))))) &&
     (DAT_009ece43 == '4')) {
    uVar16 = (uint)_DAT_009ece44;
    if ((0x200 < uVar16) || (local_80 < (uVar16 + 1) * 8)) {
      uVar16 = (local_80 >> 3) - 1;
    }
    uVar20 = 0;
    if (0x1ff < uVar16) {
      uVar16 = 0x200;
    }
    uVar24 = 0;
    while (uVar16 != uVar20) {
      uVar20 = uVar20 + 1;
      FUN_009a0738(&local_58,&DAT_009ece40 + uVar20 * 8);
      if ((local_58 & 0xffffff) != 0) {
        uVar24 = uVar24 + 1;
        *(uint *)(&DAT_009ece40 + uVar24 * 8) = local_58;
        *(int *)(&DAT_009ece44 + uVar24 * 8) = iStack_54;
      }
    }
    _DAT_009ece38 = uVar24;
  }
  iVar4 = FUN_00982c00("A:/LATENT/SESSION.TXT",&DAT_009e74a0,0xf,&local_c0);
  if (iVar4 == 0) {
    bVar28 = false;
    uVar16 = 0;
    iVar4 = _DAT_009ea410;
    for (pbVar11 = &DAT_009e74a0; (local_c0 != uVar16 && (*pbVar11 - 0x30 < 10));
        pbVar11 = pbVar11 + 1) {
      bVar28 = true;
      iVar4 = iVar4 * 10 + (uint)*pbVar11 + -0x30;
      uVar16 = uVar16 + 1;
    }
    if (bVar28) {
      _DAT_009ea410 = iVar4;
    }
  }
  FUN_009a5ce4(_DAT_009ea410,9999);
  _DAT_009ea410 = extraout_r1 + 1;
  FUN_0099ae24(&DAT_009e74a0,&DAT_009a7e39);
  FUN_00982c98("A:/LATENT/SESSION.TXT",&DAT_009e74a0,4);
  _DAT_009e9e30 = 0;
  local_94[0] = 0;
  iVar4 = FUN_00982f20(&PTR_s_A__LATENT_FILMS_A_009b4a44,&DAT_009e9a20,0x408,local_94);
  if ((iVar4 == 0) && (7 < local_94[0])) {
    if (DAT_009e9a20 == 'L') {
      if (DAT_009e9a21 == 'T') {
        if (DAT_009e9a22 == 'F') {
          if (DAT_009e9a23 == '3') {
            uVar16 = (uint)DAT_009e9a24;
            if (uVar16 < 0x41) {
              if (local_94[0] < uVar16 * 0x10 + 8) {
                uVar16 = 0;
              }
            }
            else {
              uVar16 = 0;
            }
            iVar4 = 0;
            puVar19 = &UNK_009e9a28;
            for (uVar20 = 0; uVar20 != uVar16; uVar20 = uVar20 + 1) {
              uVar7 = FUN_0099af08(puVar19);
              *(undefined4 *)(&DAT_009e9e40 + iVar4 * 0x10) = uVar7;
              uVar13 = FUN_0099af08(puVar19 + 4);
              iVar6 = iVar4 * 0x10;
              *(undefined4 *)(&DAT_009e9e44 + iVar6) = uVar13;
              *(undefined2 *)(&DAT_009e9e48 + iVar6) = *(undefined2 *)(puVar19 + 8);
              uVar29 = FUN_0099ab08(uVar7,uVar13);
              if (((int)uVar29 != 0) &&
                 (iVar8 = FUN_0099ab08((int)((ulonglong)uVar29 >> 0x20)), iVar8 != 0)) {
                iVar4 = iVar4 + 1;
                local_80 = CONCAT13(puVar19[0xd],
                                    CONCAT12(puVar19[0xc],CONCAT11(puVar19[0xb] + -6,puVar19[10])));
                local_58 = FUN_0098a9d8(&DAT_009b1ddc,0x51,local_80);
                (&DAT_009e9e4b)[iVar6] = (char)(local_58 >> 8) + '\x06';
                (&DAT_009e9e4a)[iVar6] = (char)local_58;
                *(short *)(&DAT_009e9e4c + iVar6) = (short)(local_58 >> 0x10);
                *(undefined2 *)(&UNK_009e9e4e + iVar6) = 0;
              }
              puVar19 = puVar19 + 0x10;
            }
            _DAT_009e9e30 = iVar4;
          }
        }
      }
    }
  }
  local_80 = 0;
  _DAT_009e7584 = 0;
  iVar4 = FUN_00982f20(&DAT_009b4994,&DAT_009e75a0,0x1008,&local_80);
  if (((((iVar4 == 0) && (7 < local_80)) && (DAT_009e75a0 == 'L')) &&
      ((DAT_009e75a1 == 'T' && (DAT_009e75a2 == 'G')))) && (DAT_009e75a3 == '4')) {
    uVar20 = FUN_0099af08(&UNK_009e75a4);
    uVar16 = 0;
    while( true ) {
      bVar28 = 0x1ff < uVar16;
      if (uVar16 != 0x200) {
        bVar28 = uVar16 <= uVar20;
      }
      if ((!bVar28 || (uVar16 == 0x200 || uVar20 == uVar16)) || (local_80 < (uVar16 + 2) * 8))
      break;
      FUN_009a0738(&local_58,&UNK_009e7598 + (uVar16 + 2) * 8);
      uVar16 = uVar16 + 1;
      if ((local_58 & 0xffffff) != 0) {
        *(uint *)(&DAT_009e85a8 + _DAT_009e7584 * 8) = local_58;
        *(int *)(&DAT_009e85ac + _DAT_009e7584 * 8) = iStack_54;
        _DAT_009e7584 = _DAT_009e7584 + 1;
      }
    }
  }
  _DAT_009e7580 = _DAT_009e7584;
  local_58 = 0;
  _DAT_009ecdac = 0;
  iVar4 = FUN_00982f20(&DAT_009b49f0,&DAT_009e9980,0x80,&local_58);
  if (iVar4 == 0) {
    bVar28 = false;
    pbVar11 = &DAT_009e9980 + _DAT_009ecdac * 4;
    for (uVar16 = _DAT_009ecdac; (uVar16 < local_58 >> 2 && (uVar16 < 0x20)); uVar16 = uVar16 + 1) {
      *(uint *)(&DAT_009ecdb0 + uVar16 * 4) =
           (uint)pbVar11[2] << 0x10 | (uint)pbVar11[1] << 8 | (uint)*pbVar11 |
           (uint)pbVar11[3] << 0x18;
      bVar28 = true;
      pbVar11 = pbVar11 + 4;
    }
    if (bVar28) {
      _DAT_009ecdac = uVar16;
    }
  }
  iVar4 = FUN_00982c98("A:/LATENT/REMOVE.TST",&DAT_009a7e58,4);
  if ((((iVar4 == 0) && (iVar4 = FUN_00982bd8("A:/LATENT/REMOVE.TST"), iVar4 != 0)) &&
      (iVar4 = FUN_00982bac("A:/LATENT/REMOVE.TST"), iVar4 == 0)) &&
     (uVar16 = FUN_00982bd8("A:/LATENT/REMOVE.TST"), uVar16 == 0)) {
    _DAT_009e96d4 = 1;
    _DAT_009e95ac = 0;
    local_58 = uVar16;
    iVar4 = FUN_00982f20(&DAT_009b49b0,&DAT_009e95e0,0x20,&local_58);
    if (iVar4 == 0) {
      puVar19 = &DAT_009e95e0;
      uVar16 = local_58 >> 2;
      for (; (_DAT_009e95ac < uVar16 && (_DAT_009e95ac < 8)); _DAT_009e95ac = _DAT_009e95ac + 1) {
        uVar29 = FUN_0099af08(puVar19 + _DAT_009e95ac * 4);
        puVar19 = (undefined *)((ulonglong)uVar29 >> 0x20);
        *(int *)(&DAT_009e95b0 + _DAT_009e95ac * 4) = (int)uVar29;
      }
    }
    uVar16 = _DAT_009e95ac;
    while (uVar16 != 0) {
      uVar16 = uVar16 - 1;
      FUN_009a0908(*(undefined4 *)(&DAT_009e95b0 + uVar16 * 4));
    }
  }
  else {
    _DAT_009e96d4 = 0;
  }
  _DAT_009b5824 = 0;
  _DAT_009b5828 = 0;
  if (_DAT_009e96d4 != 0) {
    FUN_00982bac("A:/LATENT/NAMED.TST");
    iVar4 = FUN_00982c98("A:/LATENT/WRITE.TST",&DAT_009a7e5d,4);
    if (iVar4 == 0) {
      iVar4 = FUN_00982af0("A:/LATENT/WRITE.TST");
      if (iVar4 < 0) {
LAB_009a1c04:
        uVar16 = 0;
        local_58 = 0;
      }
      else {
        iVar6 = FUN_00982a34(iVar4,2);
        if (iVar6 == 0) {
          iVar6 = FUN_009829b8(iVar4,&DAT_009a7e62,2);
          bVar28 = iVar6 == 0;
        }
        else {
          bVar28 = false;
        }
        local_58 = FUN_00982a90(iVar4,1);
        if (local_58 != 0) goto LAB_009a1c04;
        uVar16 = 0;
        if (bVar28) {
          iVar4 = FUN_00982c00("A:/LATENT/WRITE.TST",&DAT_009e7460,0x20,&local_58);
          if (iVar4 == 0) {
            uVar16 = 0;
            if (((local_58 == 4) && (DAT_009e7460 == 'L')) &&
               ((DAT_009e7461 == 'T' && (DAT_009e7462 == 'Z')))) {
              uVar16 = (uint)(DAT_009e7463 == 'Z');
            }
          }
          else {
            uVar16 = 0;
          }
        }
      }
      _DAT_009b5828 = uVar16;
      iVar4 = FUN_00982b14("A:/LATENT/WRITE.TST","A:/LATENT/NAMED.TST");
      uVar16 = 0;
      if (iVar4 == 0) {
        iVar4 = FUN_00982bd8("A:/LATENT/NAMED.TST");
        uVar16 = 0;
        if (iVar4 != 0) {
          iVar4 = FUN_00982bd8("A:/LATENT/WRITE.TST");
          uVar16 = (uint)(iVar4 == 0);
        }
      }
      _DAT_009b5824 = uVar16;
      FUN_00982bac("A:/LATENT/WRITE.TST");
      FUN_00982bac("A:/LATENT/NAMED.TST");
    }
  }
  local_58 = 0;
  _DAT_009b582c = 0;
  _DAT_009b588c = 0;
  if (((_DAT_009b5828 != 0) &&
      (iVar4 = FUN_00982f20(&DAT_009b49cc,&UNK_009e9600,0xc0,&local_58), iVar4 == 0)) &&
     (local_58 == 0xc0)) {
    FUN_009975a8(&DAT_009b582c,&UNK_009e9600,0x60);
    FUN_009975a8(&DAT_009b588c,&UNK_009e9660);
  }
  uVar20 = 0;
  uVar16 = 0;
  _DAT_009ecd58 = _DAT_009e96d4;
  piVar14 = (int *)&DAT_009ece40;
  while (uVar20 < _DAT_009ece38) {
    local_58 = piVar14[2];
    iStack_54 = piVar14[3];
    uVar20 = uVar20 + 1;
    iVar4 = FUN_0099d214(piVar14[2] & 0xffffff);
    if (iVar4 == 0) {
      if (_DAT_009e7584 == 0x200) {
        if (_DAT_009e96d4 != 0) {
          FUN_0099f130(_DAT_009e85a8 & 0xffffff,DAT_009e85ab >> 1);
        }
        FUN_0099cb7c();
      }
      iVar4 = _DAT_009e7584 * 8;
      _DAT_009e7584 = _DAT_009e7584 + 1;
      *(uint *)(&DAT_009e85a8 + iVar4) = local_58;
      *(int *)(&DAT_009e85ac + iVar4) = iStack_54;
      _DAT_009e757c = _DAT_009e757c + 1;
    }
    else {
      uVar16 = uVar16 + 1;
      *(uint *)(&DAT_009ece40 + uVar16 * 8) = local_58;
      *(int *)(&DAT_009ece44 + uVar16 * 8) = iStack_54;
    }
    piVar14 = piVar14 + 2;
  }
  if (_DAT_009e757c != 0) {
    _DAT_009ece38 = uVar16;
    FUN_009a07b0();
    FUN_0099b788();
  }
  FUN_0099b4a8();
  iVar6 = 0;
  _DAT_009e9970 = _DAT_009ede48;
  _DAT_009e9974 = 1;
  iVar4 = FUN_0099aba0();
  puVar19 = &DAT_009ec858;
  do {
    uVar7 = FUN_0099aab4(&local_58,"A:/LATENT/");
    uVar7 = FUN_0099aad4(uVar7,iVar6);
    FUN_0099aab4(uVar7,&DAT_009a6c0f);
    iVar8 = FUN_00982bd8(&local_58);
    iVar6 = iVar6 + 1;
    *puVar19 = iVar8 != 0;
    puVar19 = puVar19 + 1;
  } while (iVar6 != 0x51);
  _DAT_009ec840 = FUN_0099aba0();
  _DAT_009ec840 = _DAT_009ec840 - iVar4;
  _DAT_009ec83c = FUN_0099aba0();
  iVar4 = FUN_00982bd8("A:/LATENT/WELCOME.REQ");
  if (iVar4 != 0) {
    _DAT_009ec850 = 1;
    _DAT_009ec84c = 1;
  }
  _DAT_009ec854 = _DAT_009ec854 + 1;
  _DAT_009ece34 = 1;
  _DAT_009ecd0c = _DAT_009ecd0c + 1;
  FUN_0098a59c(2);
  iVar4 = 0x3e9;
  while ((_DAT_009ece30 != _DAT_009ecd0c && (iVar4 = iVar4 + -1, iVar4 != 0))) {
    (*_DAT_009ede4c)(10);
  }
  _DAT_009ece34 = 0;
  local_58 = 0;
  iVar4 = FUN_00982f20(&PTR_s_A__LATENT_OWED_A_009b4a0c,&DAT_009ea640,0x2008,&local_58);
  if (((iVar4 == 0) && (7 < local_58)) && (_DAT_009ea640 == 0x324f544c)) {
    uVar20 = 1;
    uVar16 = _DAT_009ea644;
  }
  else {
    uVar20 = 0;
    uVar16 = uVar20;
  }
  uVar24 = 0;
  uVar21 = 0;
  uVar23 = 0;
  puVar25 = (undefined4 *)&DAT_009ea644;
  _DAT_009ea628 = 0;
  while( true ) {
    if (uVar23 < uVar16) {
      uVar26 = uVar20;
    }
    else {
      uVar26 = 0;
    }
    if (((uVar26 == 0) || (uVar23 == 0x800)) || (local_58 < (uVar23 + 3) * 4)) break;
    puVar25 = puVar25 + 1;
    uVar7 = *puVar25;
    uVar29 = FUN_0099ab08(uVar7);
    uVar24 = (uint)((ulonglong)uVar29 >> 0x20);
    if ((int)uVar29 != 0) {
      *(undefined4 *)(&DAT_009ea640 + (uVar21 + 2) * 4) = uVar7;
      uVar21 = uVar21 + 1;
      uVar24 = uVar26;
    }
    uVar23 = uVar23 + 1;
  }
  if (uVar24 != 0) {
    _DAT_009ea628 = uVar21;
  }
  uVar16 = _DAT_009ea628;
  while (uVar16 != 0) {
    uVar16 = uVar16 - 1;
    uVar7 = *(undefined4 *)(&DAT_009ea648 + uVar16 * 4);
    FUN_0099d208(&local_58,uVar7);
    iVar4 = FUN_00982bd8(&local_58);
    if (iVar4 == 0) {
      FUN_0099bd2c(uVar7);
      _DAT_009ea620 = _DAT_009ea620 + 1;
    }
  }
  iVar4 = FUN_00982c00("A:/LATENT/LAST.TXT",&DAT_009e7480,0xf);
  if (iVar4 == 0) {
    iVar4 = 0;
    uVar16 = 0;
    for (pbVar11 = &DAT_009e7480; ((local_c0 != uVar16 && (uVar16 != 7)) && (*pbVar11 - 0x30 < 10));
        pbVar11 = pbVar11 + 1) {
      iVar4 = iVar4 * 10 + (uint)*pbVar11 + -0x30;
      uVar16 = uVar16 + 1;
    }
    uVar29 = FUN_0099ab08(iVar4);
    if ((int)uVar29 != 0) {
      _DAT_009ec648 = (uint)((ulonglong)uVar29 >> 0x20);
    }
  }
  uVar24 = 0;
  puVar9 = (uint *)&DAT_009ece40;
  uVar16 = 0;
  while (_DAT_009ece38 != uVar24) {
    puVar9 = puVar9 + 2;
    uVar24 = uVar24 + 1;
    if (uVar16 < (*puVar9 & 0xffffff)) {
      uVar16 = *puVar9 & 0xffffff;
    }
  }
  if ((uVar20 == 0) || (_DAT_009ec648 == 0)) {
    if (uVar16 != 0) {
      _DAT_009ec648 = uVar16;
      goto LAB_009a1f68;
    }
    if (_DAT_009ec648 != 0) goto LAB_009a1f68;
    iVar4 = 0x97;
    while ((_DAT_009e995c == 0 && (iVar4 = iVar4 + -1, iVar4 != 0))) {
      (*_DAT_009ede4c)(10);
    }
    uVar29 = FUN_0099ab08(_DAT_009e995c);
    uVar16 = 0;
    if (((int)uVar29 == 0) || (uVar16 = _DAT_009e995c, _DAT_009e995c == 0)) {
      uVar20 = 0xf4241;
      uVar24 = 1009999;
    }
    else {
      if (_DAT_009e9e30 == 0) {
        uVar20 = _DAT_009e995c;
      }
      else {
        uVar20 = _DAT_009e9e40;
        if (_DAT_009e995c < _DAT_009e9e40) {
          uVar20 = _DAT_009e995c;
        }
      }
      uVar24 = _DAT_009e995c;
    }
    while (uVar20 - 1 < uVar24) {
      FUN_0099d208(&local_58,uVar20);
      iVar4 = FUN_00982bd8(&local_58);
      if ((((iVar4 != 0) && (_DAT_009ec648 = uVar20, _DAT_009e9e30 != 0)) &&
          (_DAT_009e9e40 <= uVar20)) && (iVar4 = FUN_0099af10(uVar20), iVar4 == 0)) {
        FUN_0099bd2c(uVar20,1);
        _DAT_009ea25c = _DAT_009ea25c + 1;
      }
      uVar29 = FUN_0099ae48(uVar20);
      uVar20 = (uint)uVar29;
    }
    if (_DAT_009ec648 < uVar16) {
      _DAT_009ec648 = uVar16;
    }
  }
  else {
LAB_009a1f68:
    uVar29 = FUN_0099ae48(_DAT_009ec648);
    uVar16 = (uint)uVar29;
    bVar28 = true;
    while( true ) {
      uVar20 = (uint)uVar29;
      if (uVar16 == 0) {
        bVar28 = false;
      }
      if (!bVar28) break;
      iVar4 = 0;
      bVar28 = false;
      uVar24 = uVar16;
      do {
        uVar29 = CONCAT44(uVar24 * -0x2e48e8a7,uVar20);
        if ((uVar16 / 10000 != uVar24 / 10000) ||
           (uVar29 = CONCAT44(uVar24 * -0x2e48e8a7,uVar20), iVar4 == 0x14)) break;
        FUN_0099d208(&local_58,uVar24);
        iVar6 = FUN_00982bd8(&local_58);
        if (iVar6 == 0) {
          iVar4 = iVar4 + 1;
        }
        else {
          _DAT_009ec648 = uVar24;
          iVar4 = FUN_0099af10(uVar24);
          if (iVar4 == 0) {
            FUN_0099bd2c(uVar24,1);
            _DAT_009ea25c = _DAT_009ea25c + 1;
          }
          iVar4 = 0;
          bVar28 = true;
        }
        uVar29 = FUN_0099ae48(uVar24);
        uVar20 = (uint)uVar29;
        uVar24 = uVar20;
      } while (uVar20 != 0);
      if (uVar16 < 0x986f70) {
        uVar16 = (uVar16 / 10000) * 10000 + 0x2711;
      }
      else {
        uVar16 = 0;
      }
    }
  }
  FUN_0099b804((int)uVar29,(int)((ulonglong)uVar29 >> 0x20));
  FUN_0099b750();
  FUN_0099d294(0);
  uVar16 = _DAT_009ede48;
  if (iVar18 != 0 || bVar27) {
    uVar16 = ~_DAT_009ede48;
  }
  local_c4 = _DAT_009ecd10;
  local_c8 = ~_DAT_009e9e2c;
LAB_009a280c:
  uVar20 = _DAT_009ede48;
  if (_DAT_009ede48 != uVar16) {
    uVar24 = FUN_0099b714(DAT_009b4a7c);
    iVar18 = (uVar24 & 0xff) * 0xc;
    puVar12 = (undefined1 *)((int)&DAT_009b2254 + iVar18 + 3);
    puVar19 = &DAT_009e74e0;
    do {
      puVar12 = puVar12 + 1;
      *puVar19 = *puVar12;
      puVar19 = puVar19 + 1;
    } while (puVar12 != &LAB_009b225a_1 + iVar18);
    local_58._1_1_ = (char)(uVar24 >> 8);
    DAT_009e74e4 = local_58._1_1_ + '\x06';
    local_58._2_1_ = (undefined1)(uVar24 >> 0x10);
    DAT_009e74e5 = local_58._2_1_;
    local_58._3_1_ = (undefined1)(uVar24 >> 0x18);
    DAT_009e74e6 = local_58._3_1_;
    local_58 = uVar24;
    iVar18 = FUN_00982e28(&PTR_s_A__LATENT_FILM_A_009b4974,&DAT_009e74e0,7);
    if (iVar18 == 0) {
      uVar16 = uVar20;
    }
  }
  iVar18 = _DAT_009ec838;
  if (_DAT_009ec838 != local_cc) {
    DAT_009e74c0 = (byte)DAT_009b4a60;
    iVar4 = FUN_00982e28(&DAT_009b4958,&DAT_009e74c0,1);
    if (iVar4 == 0) {
      local_cc = iVar18;
    }
  }
  uVar20 = _DAT_009e9e2c;
  if (_DAT_009e9e2c != local_c8) {
    _DAT_009e9a20 = 0x3346544c;
    DAT_009e9a24 = (byte)_DAT_009e9e30;
    DAT_009e9a25 = 0;
    _DAT_009e9a26 = 0;
    iVar18 = _DAT_009e9e30;
    puVar19 = &UNK_009e9a28;
    puVar25 = (undefined4 *)&DAT_009e9e40;
    for (iVar4 = 0; iVar18 != iVar4; iVar4 = iVar4 + 1) {
      FUN_0099af00(puVar19,*puVar25);
      FUN_0099af00(puVar19 + 4,puVar25[1]);
      uVar2 = *(undefined2 *)(puVar25 + 2);
      puVar19[8] = (char)uVar2;
      puVar19[9] = (char)((ushort)uVar2 >> 8);
      puVar19[10] = *(undefined *)((int)puVar25 + 10);
      puVar19[0xb] = *(undefined *)((int)puVar25 + 0xb);
      puVar19[0xc] = *(undefined1 *)(puVar25 + 3);
      uVar1 = *(undefined *)((int)puVar25 + 0xd);
      puVar19[0xf] = 0;
      puVar19[0xd] = uVar1;
      puVar19[0xe] = 0;
      puVar19 = puVar19 + 0x10;
      puVar25 = puVar25 + 4;
    }
    iVar18 = FUN_00982e28(&PTR_s_A__LATENT_FILMS_A_009b4a44,&DAT_009e9a20,iVar18 * 0x10 + 8);
    if (iVar18 == 0) {
      local_c8 = uVar20;
    }
  }
  if (_DAT_009e9a04 != 0) {
    FUN_009a07b0();
  }
  FUN_009a00b0();
  if (_DAT_009ea624 != 0) {
    FUN_0099b804();
  }
  while (_DAT_009e9704 != _DAT_009ecce4) {
    uVar20 = _DAT_009e9704 & 7;
    _DAT_009e9704 = _DAT_009e9704 + 1;
    FUN_009a0908(*(undefined4 *)(&UNK_009ecce8 + uVar20 * 4));
  }
  while (_DAT_009e9700 != _DAT_009eccc0) {
    uVar20 = _DAT_009e9700 & 7;
    _DAT_009e9700 = _DAT_009e9700 + 1;
    FUN_0099b960(*(undefined4 *)(&UNK_009eccc4 + uVar20 * 4),1);
  }
  if (_DAT_009e9a04 == 0) {
    uVar20 = 0;
LAB_009a2aa8:
    if (uVar20 < _DAT_009ecdac) {
      uVar24 = 0;
      while (_DAT_009ece38 != uVar24) {
        uVar21 = uVar24 + 1;
        if ((*(uint *)(&DAT_009ece40 + uVar21 * 8) & 0xffffff) ==
            *(uint *)(&DAT_009ecdb0 + uVar20 * 4)) {
          if ((uVar24 < _DAT_009ece38) && (((&DAT_009ece43)[uVar21 * 8] & 1U) != 0)) {
            FUN_0099b960(*(uint *)(&DAT_009ece40 + uVar21 * 8) & 0xffffff,0);
            goto LAB_009a2aa8;
          }
          break;
        }
        uVar24 = uVar21;
      }
      uVar20 = uVar20 + 1;
      goto LAB_009a2aa8;
    }
  }
  if (_DAT_009e9a00 != 0) {
    FUN_0099b8e0();
  }
  _DAT_009e7564 = 0;
  iVar18 = FUN_0099aba0();
  if (iVar18 - _DAT_009e96f8 < 0) {
LAB_009a2aec:
    _DAT_009e7564 = 1;
    goto LAB_009a2af4;
  }
  if (_DAT_009e96f4 != 0) {
    local_80 = 0;
    local_58 = 0;
    iVar18 = FUN_0099afc4();
    if (iVar18 == 0) {
      iVar4 = FUN_0099f200();
    }
    else {
      iVar4 = 0;
    }
    if ((_DAT_009eca44 == 0) || (_DAT_009ecd34 == 0)) {
      bVar27 = false;
    }
    else {
      bVar27 = _DAT_009ecd38 != 0;
    }
    if (iVar4 == 0) {
      uVar7 = 0;
      if (iVar18 != 0) goto LAB_009a2bf4;
    }
    else {
      local_98 = FUN_0099f718();
      uVar7 = FUN_0099bac0(0,local_98 & 0xff);
LAB_009a2bf4:
      iVar18 = FUN_00985ef4(iVar18 != 0,bVar27,uVar7,&local_80,&local_58);
      if (iVar18 == 0) {
        _DAT_009e96f8 = FUN_0099aba0();
        _DAT_009e96f8 = _DAT_009e96f8 + 1000;
        goto LAB_009a2aec;
      }
    }
    _DAT_009e96f4 = 0;
  }
  while (((_DAT_009e9a04 == 0 && (iVar18 = FUN_0099afc4(), iVar18 != 0)) &&
         (iVar4 = FUN_0099af10(), iVar4 != 0))) {
    FUN_0099bd2c(iVar18,0);
  }
  if (_DAT_009e98e4 == _DAT_009e98e0) {
    if (_DAT_009e988c != 0) goto LAB_009a2ccc;
  }
  else {
    _DAT_009e98e0 = _DAT_009e98e4;
    _DAT_009e97dc = _DAT_009e98e8;
    _DAT_009e97e0 = _DAT_009e98ec;
    _DAT_009e97e4 = _DAT_009e98f0;
    _DAT_009e97e8 = _DAT_009e98f4;
    _DAT_009e97ec = _DAT_009e98f8;
    _DAT_009e97f0 = _DAT_009e98fc;
    _DAT_009e97f4 = _DAT_009e9900;
    _DAT_009e97f8 = _DAT_009e9904;
    _DAT_009e97fc = _DAT_009e9908;
    _DAT_009e9800 = _DAT_009e990c;
    _DAT_009e9804 = _DAT_009e9910;
    _DAT_009e9808 = _DAT_009e9914;
    _DAT_009e988c = 1;
    _DAT_009e9888 = 0;
LAB_009a2ccc:
    uVar20 = _DAT_009e97e4;
    local_b8 = 0;
    local_b4 = 0;
    local_9c = FUN_0099f638(_DAT_009e97e4,0);
    FUN_0099b3d0(local_94,local_9c,&local_80,&local_58);
    if (((_DAT_009e98a4 == 0) && (iVar18 = FUN_0099af10(uVar20), iVar18 == 0)) &&
       ((_DAT_009ec648 <= uVar20 + 1 && (uVar20 <= _DAT_009ec648 + 0x14)))) {
      iVar18 = FUN_0099b2cc();
      if ((iVar18 == 0) || (iVar18 = FUN_00986414(&local_80), iVar18 == 0)) {
        FUN_00985044(&local_b8,&local_b4);
      }
      else {
        if (_DAT_009e9888 == 0) {
          _DAT_009e9888 = 1;
          iVar18 = FUN_0098644c(local_94,&DAT_009e97fc);
          if (iVar18 != 0) {
            _DAT_009e988c = 0;
            _DAT_009e9884 = _DAT_009e9884 + 1;
            goto LAB_009a2d6c;
          }
        }
        uVar7 = 0;
        if (((_DAT_009eca44 != 0) && (_DAT_009ecd34 != 0)) && (uVar7 = 0, _DAT_009ecd38 != 0)) {
          uVar7 = 1;
        }
        iVar18 = FUN_00985e30(&local_80,uVar7,&local_b8,&local_b4);
        uVar20 = _DAT_009e97e4;
        if (iVar18 != 0) {
          _DAT_009e7568 = &DAT_009e97fc;
          _DAT_009e988c = 0;
          local_a0 = FUN_0099f638(_DAT_009e97e4,0,0);
          iVar18 = FUN_009a0f18(uVar20,local_a0,1,0);
          _DAT_009e7568 = (undefined *)0x0;
          _DAT_009e95a8 = 1;
          if (iVar18 == 0) {
            _DAT_009e98ac = _DAT_009e98ac + 1;
            _DAT_009e9860 = _DAT_009e97ec - _DAT_009e97e8;
            _DAT_009e9864 = _DAT_009e97f0 - _DAT_009e97e8;
            _DAT_009e9868 = FUN_0099aba0();
            _DAT_009e9868 = _DAT_009e9868 - _DAT_009e97e8;
            _DAT_009e986c = _DAT_009e97e4;
            if ((_DAT_009e9870 < 2) && (_DAT_009e97e4 == _DAT_009e96dc)) {
              *(uint *)(&UNK_009e9874 + _DAT_009e9870 * 8) = _DAT_009e97e4;
              iVar18 = _DAT_009e9870 * 8;
              _DAT_009e9870 = _DAT_009e9870 + 1;
              *(undefined4 *)(&UNK_009e9878 + iVar18) = _DAT_009e96e0;
            }
          }
          else if (iVar18 == -0x15) {
            piVar14 = (int *)&DAT_009e98a8;
            iVar18 = _DAT_009e98a8;
LAB_009a2fb8:
            _DAT_009e95a8 = 1;
            *piVar14 = iVar18 + 1;
          }
          goto LAB_009a280c;
        }
        if (local_b8 < 0x96000) {
          FUN_009852b0();
          _DAT_009e9898 = _DAT_009e9898 + 1;
        }
        else {
          iVar18 = FUN_0099aba0();
          if ((uint)(iVar18 - _DAT_009e97f0) < 4000) goto LAB_009a2af4;
        }
      }
      FUN_0099b18c(local_b8,local_b4);
      goto LAB_009a2d6c;
    }
    _DAT_009e988c = 0;
  }
LAB_009a2d6c:
  uVar20 = 0;
  while ((uVar20 != _DAT_009e9870 && (_DAT_009e98a4 == 0))) {
    uVar24 = *(uint *)(&UNK_009e9874 + uVar20 * 8);
    if ((uVar24 != 0) && (uVar24 <= _DAT_009ec648)) {
      *(undefined4 *)(&UNK_009e9874 + uVar20 * 8) = 0;
      _DAT_009e96e8 = 1;
      _DAT_009e96e4 = 0;
      local_a4 = FUN_0099f638(uVar24,0,0);
      iVar18 = FUN_009a0f18(uVar24,local_a4,1,0);
      _DAT_009e96e8 = 0;
      _DAT_009e95a8 = 1;
      if (iVar18 != 0) goto LAB_009a280c;
      if (*(int *)(&UNK_009e9878 + uVar20 * 8) != _DAT_009e96e4) {
        _DAT_009e989c = _DAT_009e989c + 1;
        _DAT_009e98a4 = 1;
        uVar7 = FUN_0099f638(uVar24,0,0);
        local_a8 = uVar7;
        goto LAB_009a307c;
      }
      piVar14 = (int *)&DAT_009e98a0;
      iVar18 = _DAT_009e98a0;
      goto LAB_009a2fb8;
    }
    uVar20 = uVar20 + 1;
  }
  uVar24 = FUN_0099afc4();
  if (uVar24 != 0) {
    uVar7 = FUN_0099f638(uVar24,0);
    local_ac = uVar7;
LAB_009a307c:
    uVar17 = 0;
    uVar13 = 1;
LAB_009a3084:
    FUN_009a0f18(uVar24,uVar7,uVar13,uVar17);
    goto LAB_009a280c;
  }
  if ((_DAT_009eca40 == 0) && (uVar24 = FUN_0099f200(), uVar24 != 0)) {
    uVar7 = FUN_0099f718();
    uVar17 = 1;
    uVar13 = 0;
    local_b0 = uVar7;
    goto LAB_009a3084;
  }
  if (_DAT_009e7564 == 0) {
    local_80 = _DAT_009e7564;
    local_58 = _DAT_009e7564;
    FUN_00985044(&local_80,&local_58);
    if ((local_80 < 0x96000) || (_DAT_009e98a4 != 0)) {
      FUN_009852b0();
      _DAT_009e9898 = _DAT_009e9898 + 1;
    }
    else if ((((0xa5fff < local_80) && (0x9fff < local_58)) &&
             (iVar18 = FUN_0098255c(), iVar18 == 0)) &&
            ((iVar18 = FUN_0099aba0(), 5000 < (uint)(iVar18 - _DAT_009b4a98) &&
             (iVar18 = FUN_00985fb4(FUN_009a05e8,0), iVar18 != 0)))) {
      _DAT_009e95a8 = 1;
      goto LAB_009a280c;
    }
    if ((_DAT_009e7570 == 0) && (iVar18 = FUN_0098255c(), iVar18 == 0)) {
      if (_DAT_009e7580 == 0) {
        if (DAT_009b4990 == 0) {
LAB_009a32d8:
          if (_DAT_009ece38 < _DAT_009e7574) {
            _DAT_009e7574 = _DAT_009ece38;
          }
          if (_DAT_009e7574 == 0) {
            _DAT_009e7570 = 1;
            goto LAB_009a3504;
          }
          uVar24 = _DAT_009e7574 - 1;
          uVar20 = *(uint *)(&DAT_009ece40 + _DAT_009e7574 * 8);
          uStack_7c = *(undefined4 *)(&DAT_009ece44 + _DAT_009e7574 * 8);
          local_80._3_1_ = (byte)(uVar20 >> 0x18);
          uVar21 = *(uint *)(&DAT_009ece40 + _DAT_009e7574 * 8) & 0xffffff;
          _DAT_009e7574 = uVar24;
          if ((((uVar20 & 0x1000000) == 0) && (_DAT_009e96d4 != 0)) &&
             ((local_80._3_1_ < 0xa2 && (_DAT_009e9710 != uVar21)))) {
            local_80 = uVar20;
            FUN_0099f090(&local_58,uVar21);
            iVar18 = FUN_00982bd8(&local_58);
            if ((iVar18 != 0) && (iVar18 = FUN_00982bac(&local_58), iVar18 == 0)) {
              _DAT_009e96d8 = _DAT_009e96d8 + 1;
            }
            local_80 = uVar21 | local_80 & 0xff000000;
            iVar18 = FUN_0099f18c(local_80,uStack_7c);
            uVar20 = local_80;
            if (iVar18 == 0) {
              FUN_0099f090(&local_58,uVar21);
              iVar18 = FUN_00982bd8(&local_58);
              uVar20 = local_80;
              if (iVar18 != 0) {
                iVar18 = FUN_00982bac(&local_58);
                uVar20 = local_80;
                if (iVar18 == 0) {
                  _DAT_009e96d8 = _DAT_009e96d8 + 1;
                }
              }
            }
          }
          local_80 = uVar20;
          iVar18 = FUN_0099d214(uVar21);
          if (iVar18 == 0) {
            if (_DAT_009e7584 == 0x200) {
              if (_DAT_009e96d4 != 0) {
                FUN_0099f130(_DAT_009e85a8 & 0xffffff,DAT_009e85ab >> 1);
              }
              FUN_0099cb7c();
            }
            iVar18 = _DAT_009e7584 * 8;
            local_80 = uVar21 | local_80 & 0xff000000;
            _DAT_009e7584 = _DAT_009e7584 + 1;
            *(uint *)(&DAT_009e85a8 + iVar18) = local_80;
            *(undefined4 *)(&DAT_009e85ac + iVar18) = uStack_7c;
            FUN_0099b788();
            iVar18 = FUN_009a087c(uVar21,&local_58);
            if (iVar18 != 0) {
              FUN_0099b508(uVar21);
            }
            _DAT_009e96c8 = _DAT_009e96c8 + 1;
            _DAT_009e95a8 = 1;
          }
        }
        else {
          bVar27 = false;
          for (uVar20 = DAT_009b4990; _DAT_009ea628 < uVar20; uVar20 = uVar20 - 1) {
            bVar27 = true;
          }
          uVar20 = DAT_009b4990;
          if ((bVar27) && (_DAT_009ea628 <= DAT_009b4990)) {
            uVar20 = _DAT_009ea628;
            DAT_009b4990 = _DAT_009ea628;
          }
          do {
            if (uVar20 == 0) {
              _DAT_009e7574 = _DAT_009ece38;
              goto LAB_009a32d8;
            }
            uVar20 = uVar20 - 1;
            uVar7 = *(undefined4 *)(&DAT_009ea648 + uVar20 * 4);
            DAT_009b4990 = uVar20;
            iVar18 = FUN_0099af10(uVar7);
          } while (iVar18 != 0);
          FUN_0099d208(&local_58,uVar7);
          iVar18 = FUN_00982bd8(&local_58);
          if (iVar18 == 0) {
            FUN_0099bd2c(uVar7);
          }
        }
      }
      else {
        local_58 = _DAT_009e85a8;
        iStack_54 = _DAT_009e85ac;
        uVar20 = _DAT_009e85a8 & 0xffffff;
        bVar3 = DAT_009e85ab;
        iVar18 = FUN_0099d214(uVar20);
        if (iVar18 == 0) {
          if (_DAT_009e96d4 != 0) {
            FUN_0099f130(uVar20,bVar3 >> 1);
            FUN_0099cb7c();
            piVar14 = (int *)&DAT_009e96c4;
            _DAT_009e7578 = _DAT_009e7578 + 1;
            goto LAB_009a3194;
          }
          _DAT_009e7580 = 0;
        }
        else {
          FUN_0099cb7c();
          _DAT_009e7578 = _DAT_009e7578 + 1;
          FUN_009a0b98(local_58,iStack_54);
          piVar14 = (int *)&DAT_009e96c0;
LAB_009a3194:
          *piVar14 = *piVar14 + 1;
          _DAT_009e95a8 = 1;
        }
        if ((_DAT_009e7578 != 0) && ((0xf < _DAT_009e7578 || (_DAT_009e7580 == 0)))) {
          FUN_0099b788();
          _DAT_009e7578 = 0;
        }
      }
      uVar7 = 0x14;
      goto LAB_009a31e4;
    }
LAB_009a3504:
    if ((_DAT_009ec84c == 1) && (iVar18 = FUN_0098255c(), iVar18 == 0)) {
      iVar18 = FUN_00982bac("A:/LATENT/WELCOME.REQ");
      if (iVar18 == 0) {
        _DAT_009ec84c = 2;
      }
      else {
        _DAT_009ec84c = 3;
      }
    }
    if (((_DAT_009ecd10 != local_c4) || (_DAT_009e95a8 != 0)) &&
       (iVar18 = FUN_0098255c(), iVar18 == 0)) {
      local_c4 = _DAT_009ecd10;
      _DAT_009e95a8 = 0;
      FUN_0099d294();
    }
  }
LAB_009a2af4:
  uVar7 = 100;
LAB_009a31e4:
  (*_DAT_009ede4c)(uVar7);
  goto LAB_009a280c;
}


// ===== FUN_009a3580 @ 009a3580

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_009a3580(void)

{
                    /* WARNING: Could not recover jumptable at 0x009a3588. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_DAT_009ede4c)();
  return;
}


// ===== FUN_009a3590 @ 009a3590

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_009a3590(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  _DAT_009fabec = 0x31545241;
  _DAT_009fabf0 = (*(code *)&SUB_ffb18b40)("Latent",0x11,0x2000,FUN_0099e950,0,param_2,param_3);
  return;
}


// ===== FUN_009a35e0 @ 009a35e0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_009a35e0(uint *param_1)

{
  uint uVar1;
  
  if (param_1 == (uint *)0x0) {
    return 1;
  }
  *param_1 = _DAT_00004ab8;
  param_1[1] = _DAT_00004abc;
  param_1[2] = _DAT_0000f3e0;
  param_1[3] = _DAT_0001aaa4;
  param_1[4] = _DAT_0000f3d4;
  param_1[5] = _DAT_00012720;
  param_1[6] = (uint)DAT_00004ac0;
  param_1[7] = (uint)DAT_00004ac1;
  if (param_1 == (uint *)0x0) {
    return 1;
  }
  uVar1 = (uint)(*param_1 == 1) << 1;
  if (param_1[1] == 1) {
    uVar1 = uVar1 | 4;
  }
  if (param_1[2] == 1) {
    uVar1 = uVar1 | 8;
  }
  if ((param_1[3] != 0) && ((param_1[3] & 3) == 0)) {
    uVar1 = uVar1 | 0x10;
  }
  if ((param_1[4] != 0) && ((param_1[4] & 3) == 0)) {
    uVar1 = uVar1 | 0x20;
  }
  if ((param_1[5] != 0) && ((param_1[5] & 3) == 0)) {
    uVar1 = uVar1 | 0x40;
  }
  if (param_1[6] == 1) {
    uVar1 = uVar1 | 0x80;
  }
  if (param_1[7] == 1) {
    uVar1 = uVar1 | 0x100;
  }
  return uVar1 | (uint)(1 < (*param_1 | param_1[1] | param_1[2] | param_1[6] | param_1[7])) << 9;
}


// ===== FUN_009a3654 @ 009a3654

uint FUN_009a3654(int param_1,undefined4 param_2,uint param_3)

{
  uint uVar1;
  
  uVar1 = (uint)(param_3 == 1) << 1;
  if (*(uint *)(param_1 + 4) == 1) {
    uVar1 = uVar1 | 4;
  }
  if (*(uint *)(param_1 + 8) == 1) {
    uVar1 = uVar1 | 8;
  }
  if ((*(uint *)(param_1 + 0xc) != 0) && ((*(uint *)(param_1 + 0xc) & 3) == 0)) {
    uVar1 = uVar1 | 0x10;
  }
  if ((*(uint *)(param_1 + 0x10) != 0) && ((*(uint *)(param_1 + 0x10) & 3) == 0)) {
    uVar1 = uVar1 | 0x20;
  }
  if ((*(uint *)(param_1 + 0x14) != 0) && ((*(uint *)(param_1 + 0x14) & 3) == 0)) {
    uVar1 = uVar1 | 0x40;
  }
  if (*(uint *)(param_1 + 0x18) == 1) {
    uVar1 = uVar1 | 0x80;
  }
  if (*(uint *)(param_1 + 0x1c) == 1) {
    uVar1 = uVar1 | 0x100;
  }
  return uVar1 | (uint)(1 < (param_3 | *(uint *)(param_1 + 4) | *(uint *)(param_1 + 8) |
                             *(uint *)(param_1 + 0x18) | *(uint *)(param_1 + 0x1c))) << 9;
}


// ===== FUN_009a3700 @ 009a3700

bool FUN_009a3700(uint param_1)

{
  if (param_1 == 0) {
    return false;
  }
  return (param_1 & 3) == 0;
}


// ===== FUN_009a3718 @ 009a3718

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool FUN_009a3718(int param_1)

{
  if ((*(int *)(param_1 + 0xaa3c) == 1) && (_DAT_0000f3e0 == 1)) {
    return *(int *)(param_1 + 0xaa00) == _DAT_0000f3d4;
  }
  return false;
}


// ===== FUN_009a3758 @ 009a3758

undefined4 FUN_009a3758(int param_1)

{
  undefined4 uVar1;
  char *pcVar2;
  int iVar3;
  char *pcVar4;
  int *piVar5;
  
  iVar3 = *(int *)(param_1 + 0xaa58);
  *(int *)(param_1 + 0xaa58) = iVar3 + 1;
  if (iVar3 != 0) {
    return 0xffffffff;
  }
  if (*(char *)(param_1 + 0xa9a4) == '\0') goto LAB_009a3834;
  iVar3 = (*(code *)&SUB_ffb0bc28)(&DAT_009fac08);
  if (iVar3 == 0) {
    pcVar2 = &DAT_009fac08;
    pcVar4 = (char *)(param_1 + 0xa95f);
    do {
      pcVar4 = pcVar4 + 1;
      if (*pcVar2 != *pcVar4) goto LAB_009a38b4;
      pcVar2 = pcVar2 + 1;
    } while (pcVar4 != (char *)(param_1 + 0xa99f));
    uVar1 = (*(code *)&SUB_ffa24a90)(param_1 + 0xa920);
    iVar3 = FUN_009a3700();
    if (iVar3 != 0) {
      iVar3 = (*(code *)&SUB_ffa24ed4)(uVar1);
      if (iVar3 == 0) {
        *(int *)(param_1 + 0xaa34) = *(int *)(param_1 + 0xaa34) + 1;
      }
      else {
        *(int *)(param_1 + 0xaa5c) = *(int *)(param_1 + 0xaa5c) + 1;
      }
      iVar3 = (*(code *)&SUB_ffa24b98)(uVar1);
      if (iVar3 == 0 || iVar3 == 0xd) goto LAB_009a382c;
    }
    *(int *)(param_1 + 0xaa5c) = *(int *)(param_1 + 0xaa5c) + 1;
  }
  else {
LAB_009a38b4:
    *(int *)(param_1 + 0xaa38) = *(int *)(param_1 + 0xaa38) + 1;
  }
LAB_009a382c:
  *(undefined1 *)(param_1 + 0xa9a4) = 0;
LAB_009a3834:
  piVar5 = (int *)(param_1 + 0xa9a4);
  do {
    piVar5 = piVar5 + 1;
    if (*piVar5 != 0) {
      iVar3 = (*(code *)&SUB_ffa30538)();
      if (iVar3 != 0 && iVar3 != 0xd) {
        *(int *)(param_1 + 0xaa5c) = *(int *)(param_1 + 0xaa5c) + 1;
      }
      *piVar5 = 0;
    }
  } while ((int *)(param_1 + 0xa9e4) != piVar5);
  if (*(int *)(param_1 + 0xa9a0) != 0) {
    iVar3 = (*(code *)&SUB_ffa24b98)();
    if (iVar3 != 0 && iVar3 != 0xd) {
      *(int *)(param_1 + 0xaa5c) = *(int *)(param_1 + 0xaa5c) + 1;
    }
    *(undefined4 *)(param_1 + 0xa9a0) = 0;
  }
  *(undefined4 *)(param_1 + 0xaa3c) = 0;
  uVar1 = 0;
  if (*(int *)(param_1 + 0xaa5c) != 0) {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}


// ===== FUN_009a38e4 @ 009a38e4

undefined4 FUN_009a38e4(char *param_1,undefined1 *param_2,undefined4 param_3,undefined4 param_4)

{
  undefined1 uVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  byte *pbVar5;
  byte bVar6;
  undefined1 uVar7;
  uint uVar8;
  undefined1 uVar9;
  char *pcVar10;
  int iVar11;
  int iVar12;
  bool bVar13;
  byte local_31;
  undefined4 local_30;
  undefined1 *puStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  
  uStack_24 = param_4;
  uStack_28 = param_3;
  puStack_2c = param_2;
  local_30 = param_1;
  iVar11 = 0;
  uVar4 = 0;
  pcVar10 = param_1;
  do {
    uVar8 = uVar4;
    if (((*pcVar10 == -1) && ((byte)(pcVar10[2] + 0x82U) < 5)) && ((byte)(pcVar10[3] + 0x82U) < 5))
    {
      uVar8 = uVar4 + 1;
      pbVar5 = (byte *)((int)&local_30 + uVar4);
      while ((uVar4 != 0 && ((byte)pcVar10[1] < (byte)param_1[(uint)pbVar5[-1] * 4 + 1]))) {
        uVar4 = uVar4 - 1;
        *pbVar5 = pbVar5[-1];
        pbVar5 = pbVar5 + -1;
      }
      *(char *)((int)&local_30 + uVar4) = (char)iVar11;
    }
    iVar11 = iVar11 + 1;
    pcVar10 = pcVar10 + 4;
    uVar4 = uVar8;
  } while (iVar11 != 0x10);
  if (uVar8 < 2) {
    uVar2 = 0;
  }
  else {
    bVar6 = (&local_31)[uVar8];
    uVar7 = (undefined1)local_30;
    uVar9 = (undefined1)local_30;
    if (uVar8 != 2) {
      uVar7 = local_30._1_1_;
      if (uVar8 == 3) {
        uVar9 = local_30._1_1_;
      }
      else {
        uVar9 = local_30._2_1_;
      }
    }
    uVar1 = *(undefined1 *)((int)&local_30 + (uVar8 >> 1));
    iVar11 = 0x28;
    iVar3 = 0;
    iVar12 = -1;
    pcVar10 = param_1;
    do {
      if (((*pcVar10 == -1) && (0x3f < (byte)pcVar10[1])) &&
         (iVar11 < (int)((uint)(byte)pcVar10[3] - (uint)(byte)pcVar10[2]))) {
        iVar11 = (uint)(byte)pcVar10[3] - (uint)(byte)pcVar10[2];
        iVar12 = iVar3;
      }
      iVar3 = iVar3 + 1;
      pcVar10 = pcVar10 + 4;
    } while (iVar3 != 0x10);
    uVar4 = 0;
    do {
      uVar8 = uVar4;
      if (param_1[uVar4 * 4] != '\0') {
        uVar8 = 0xffffffff;
      }
      bVar13 = uVar4 != 0xf;
      uVar4 = uVar4 + 1;
    } while (uVar8 == 0xffffffff && bVar13);
    if (uVar8 == 0xffffffff) {
      uVar8 = (uint)local_30 & 0xff;
    }
    uVar2 = 1;
    param_2[5] = bVar6;
    if (iVar12 != -1) {
      bVar6 = (byte)iVar12;
    }
    *param_2 = (char)uVar8;
    param_2[1] = (undefined1)local_30;
    param_2[2] = uVar7;
    param_2[3] = uVar9;
    param_2[4] = uVar1;
    param_2[6] = bVar6;
    param_2[7] = uVar1;
    param_2[8] = uVar9;
    param_2[9] = uVar9;
    param_2[10] = uVar1;
  }
  return uVar2;
}


// ===== FUN_009a3a90 @ 009a3a90

undefined4 FUN_009a3a90(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uStack_14;
  undefined4 uStack_10;
  char *local_c;
  
  local_c = &UNK_009fac48 + param_2;
  *local_c = (char)param_2 * '\x11';
  uStack_14 = 2;
  uStack_10 = 1;
  uVar1 = (*(code *)&SUB_ffa303ac)(*(undefined4 *)(param_1 + 0xa9a0),2,1,&uStack_14,param_1);
  iVar2 = FUN_009a3700();
  if (iVar2 == 0) {
    uVar1 = 0;
  }
  return uVar1;
}


// ===== FUN_009a3aec @ 009a3aec

int FUN_009a3aec(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4,int param_5,
                uint param_6)

{
  uint uVar1;
  byte bVar2;
  char cVar3;
  int iVar4;
  uint uVar5;
  undefined *puVar6;
  int iVar7;
  byte *pbVar8;
  ushort *puVar9;
  uint uVar10;
  char *pcVar11;
  ushort *puVar12;
  undefined1 *puVar13;
  uint uVar14;
  int iVar15;
  char *pcVar16;
  byte *pbVar17;
  uint uVar18;
  uint uVar19;
  int iVar20;
  uint uVar21;
  int iVar22;
  undefined *puVar23;
  uint uVar24;
  uint uVar25;
  uint uVar26;
  int iVar27;
  bool bVar28;
  undefined8 uVar29;
  uint local_90;
  byte local_70 [12];
  undefined2 local_64;
  undefined2 local_62;
  undefined4 local_60;
  undefined *local_5c;
  ushort local_58 [12];
  ushort local_40 [14];
  
  *(uint *)(param_2 + 0xaa4c) = param_6 & 0xffff | param_5 << 0x10;
  if (param_6 == 0 || param_5 == 0) {
    return 0;
  }
  uVar29 = FUN_009a3718(param_2);
  iVar7 = (int)((ulonglong)uVar29 >> 0x20);
  if ((int)uVar29 == 0) {
    *(undefined4 *)(param_2 + 0xaa54) = 1;
    return 1;
  }
  iVar4 = (*(code *)&SUB_ffb0bc28)(&DAT_009fac58);
  if (iVar4 == 0) {
    if (*(char *)(param_2 + 0xa9a4) != '\0') {
      pcVar11 = &DAT_009fac58;
      pcVar16 = (char *)(iVar7 + 0xa95f);
      do {
        pcVar16 = pcVar16 + 1;
        if (*pcVar11 != *pcVar16) {
          *(int *)(param_2 + 0xaa30) = *(int *)(param_2 + 0xaa30) + 1;
          iVar4 = (*(code *)&SUB_ffa24ed4)(*(undefined4 *)(param_2 + 0xa9a0));
          if (iVar4 == 0) goto LAB_009a3f44;
          *(undefined1 *)(param_2 + 0xa9a4) = 0;
          goto LAB_009a3dc4;
        }
        pcVar11 = pcVar11 + 1;
      } while (pcVar16 != (char *)(iVar7 + 0xa99f));
      goto LAB_009a3b9c;
    }
  }
  else {
LAB_009a3f44:
    if (*(char *)(param_2 + 0xa9a4) != '\0') goto LAB_009a3b9c;
  }
LAB_009a3dc4:
  iVar4 = (*(code *)&SUB_ffb0bc28)(&DAT_009fac58);
  if (iVar4 == 0) {
    uVar29 = FUN_009a38e4(&DAT_009fac58,local_40);
    if ((int)uVar29 == 0) {
      *(int *)(param_2 + 0xaa28) = *(int *)(param_2 + 0xaa28) + 1;
    }
    else {
      pcVar16 = (char *)(iVar7 + 0xa9e7);
      pcVar11 = (char *)((ulonglong)uVar29 >> 0x20);
      do {
        pcVar16 = pcVar16 + 1;
        cVar3 = *pcVar11;
        if (*pcVar16 != cVar3) {
          *(int *)(param_2 + 0xaa24) = *(int *)(param_2 + 0xaa24) + 1;
        }
        *pcVar16 = cVar3;
        pcVar11 = pcVar11 + 1;
      } while ((char *)(iVar7 + 0xa9f2) != pcVar16);
    }
  }
LAB_009a3b9c:
  *(int *)(param_2 + 0xaa40) = *(int *)(param_2 + 0xaa40) + 1;
  local_90 = *(uint *)(param_2 + 0xaa14);
  if (*(int *)(param_2 + 0xaa18) == 2) {
    local_90 = local_90 >> 1;
  }
  uVar1 = *(int *)(param_2 + 0xaa10) + 7U >> 3;
  pbVar17 = (byte *)(iVar7 + 0xa9e7);
  pbVar8 = local_70;
  do {
    pbVar17 = pbVar17 + 1;
    *pbVar8 = *pbVar17 & 0xf;
    pbVar8 = pbVar8 + 1;
  } while ((byte *)(iVar7 + 0xa9f2) != pbVar17);
  uVar25 = 0;
  do {
    if (local_90 <= uVar25) {
      return 0;
    }
    uVar24 = local_90 - uVar25;
    iVar4 = 0;
    if (7 < uVar24) {
      uVar24 = 8;
    }
    puVar9 = local_58;
    puVar12 = local_40;
    do {
      iVar4 = iVar4 + 1;
      *puVar9 = 0xffff;
      *puVar12 = 0;
      puVar9 = puVar9 + 1;
      puVar12 = puVar12 + 1;
    } while (iVar4 != 0xb);
    puVar13 = &DAT_009faf9a;
    for (uVar18 = 0; uVar18 < uVar1 * 0x58; uVar18 = uVar18 + 1) {
      *puVar13 = 0;
      puVar13 = puVar13 + 1;
    }
    uVar26 = 0;
    uVar18 = uVar25;
    do {
      if (0xef < uVar18) break;
      uVar10 = 0;
      do {
        bVar2 = *(byte *)(uVar18 * 0xb4 + iVar7 + 0x60 + (uVar10 >> 1));
        bVar28 = (uVar10 & 1) != 0;
        if (bVar28) {
          bVar2 = bVar2 >> 4;
        }
        uVar19 = (uint)bVar2;
        if (!bVar28) {
          uVar19 = uVar19 & 0xf;
        }
        if (uVar19 < 0xb) {
          bVar28 = *(int *)(iVar7 + 0xaa1c) == 2;
          if (bVar28) {
            uVar21 = 0xc0;
            uVar14 = (uVar10 & 3) << 1;
          }
          else {
            uVar21 = 0x80;
            uVar14 = uVar10 & 7;
          }
          if (bVar28) {
            uVar5 = uVar10 >> 2;
          }
          else {
            uVar5 = uVar10 >> 3;
          }
          if (uVar5 < uVar1) {
            iVar4 = (uVar26 + uVar19 * 8) * uVar1 + uVar5;
            (&DAT_009faf9a)[iVar4] = (byte)(uVar21 >> uVar14) | (&DAT_009faf9a)[iVar4];
            if (uVar5 < local_58[uVar19]) {
              local_58[uVar19] = (ushort)uVar5;
            }
            if (local_40[uVar19] < uVar5) {
              local_40[uVar19] = (ushort)uVar5;
            }
          }
        }
        uVar10 = uVar10 + 1;
      } while (uVar10 != 0x168);
      uVar26 = uVar26 + 1;
      uVar18 = uVar18 + 1;
    } while (uVar24 != uVar26);
    iVar22 = 0;
    iVar4 = 0;
    do {
      iVar20 = *(int *)(iVar7 + (local_70[iVar4] + 0x2a6a) * 4);
      uVar18 = (uint)local_58[iVar4];
      if (uVar18 <= local_40[iVar4] && iVar20 != 0) {
        uVar10 = (local_40[iVar4] - uVar18) + 1;
        iVar27 = iVar22 + uVar18;
        iVar15 = 0;
        uVar26 = 0;
        do {
          puVar6 = &UNK_009fac98 + iVar15;
          puVar23 = &DAT_009faf9a + iVar27;
          for (uVar19 = 0; uVar19 < uVar10; uVar19 = uVar19 + 1) {
            *puVar6 = *puVar23;
            puVar6 = puVar6 + 1;
            puVar23 = puVar23 + 1;
          }
          uVar26 = uVar26 + 1;
          iVar27 = iVar27 + uVar1;
          iVar15 = iVar15 + uVar10;
        } while (uVar24 != uVar26);
        (&UNK_009fac98)[uVar10 * uVar24] = 0;
        (&UNK_009fac99)[uVar10 * uVar24] = 0;
        local_60 = 0;
        *(int *)(iVar7 + 0xaa44) = *(int *)(iVar7 + 0xaa44) + 1;
        local_64 = (undefined2)(uVar10 * 8);
        local_62 = (undefined2)uVar24;
        local_5c = &UNK_009fac98;
        iVar20 = (*(code *)&SUB_ffa2f9a8)
                           (param_1,uVar18 << 3,uVar25 * *(int *)(iVar7 + 0xaa18),&local_64,
                            uVar10 * 8,uVar24,iVar20,0);
        if (iVar20 != 0) {
          iVar4 = *(int *)(iVar7 + 0xaa48);
          *(int *)(iVar7 + 0xaa48) = iVar4 + 1;
          if (iVar4 == 0) {
            *(int *)(iVar7 + 0xaa50) = iVar20;
            return iVar20;
          }
          return iVar20;
        }
      }
      iVar4 = iVar4 + 1;
      iVar22 = iVar22 + uVar1 * 8;
    } while (iVar4 != 0xb);
    uVar25 = uVar25 + 8;
  } while( true );
}


// ===== FUN_009a3f6c @ 009a3f6c

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_009a3f6c(int param_1)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  char *pcVar4;
  uint uVar5;
  byte *pbVar6;
  code *pcVar7;
  undefined4 uVar8;
  undefined1 *puVar10;
  undefined1 *puVar9;
  int iVar11;
  byte *pbVar12;
  int iVar13;
  int *piVar14;
  undefined *puVar15;
  char *pcVar16;
  undefined8 uVar17;
  byte local_5c [12];
  byte local_50 [12];
  char acStack_44 [12];
  char acStack_38 [20];
  
  *(undefined4 *)(param_1 + 0xaa58) = 0;
  *(undefined1 *)(param_1 + 0xa9a4) = 0;
  *(int *)(param_1 + 0x4c) = param_1 + 0x60;
  *(undefined4 *)(param_1 + 0x50) = 0xa8c0;
  *(undefined4 *)(param_1 + 0x5c) = 0xb4;
  *(undefined4 *)(param_1 + 0x54) = 0x168;
  *(undefined4 *)(param_1 + 0x58) = 0xf0;
  pcVar7 = (code *)&SUB_ffb0bc28;
  *(undefined4 *)(param_1 + 0xaa00) = _DAT_0000f3d4;
  if (_DAT_0000f3e0 == 1) {
    uVar17 = FUN_009a3700();
    if (((int)uVar17 != 0) && (*(int *)((int)((ulonglong)uVar17 >> 0x20) + 0xe30) == 1)) {
      iVar13 = param_1 + 0xa920;
      iVar3 = (*pcVar7)(iVar13);
      if ((iVar3 != 0) || (iVar3 = FUN_009a38e4(iVar13,param_1 + 0xa9e8), iVar3 == 0)) {
        uVar8 = 2;
        goto LAB_009a3ffc;
      }
      uVar8 = (*(code *)&SUB_ffa2855c)();
      *(undefined4 *)(param_1 + 0xaa04) = uVar8;
      iVar3 = (*(code *)&SUB_ffa2f058)(param_1 + 0xaa08,param_1 + 0xaa0c);
      if (iVar3 != 0) {
        uVar8 = 3;
        goto LAB_009a3ffc;
      }
      uVar5 = *(uint *)(param_1 + 0xaa08);
      if (uVar5 < 0x2d0) {
        iVar3 = 1;
      }
      else {
        iVar3 = 2;
      }
      *(int *)(param_1 + 0xaa1c) = iVar3;
      if ((uint)(iVar3 * 0x168) < uVar5) {
        uVar5 = iVar3 * 0x168;
      }
      *(uint *)(param_1 + 0xaa10) = uVar5 & 0xfffffff8;
      if (*(int *)(param_1 + 0xaa04) == 0) {
        iVar3 = 1;
      }
      else {
        iVar3 = 2;
      }
      *(int *)(param_1 + 0xaa18) = iVar3;
      if (*(uint *)(param_1 + 0xaa0c) < (uint)(iVar3 * 0xf0)) {
        *(uint *)(param_1 + 0xaa14) = *(uint *)(param_1 + 0xaa0c);
      }
      else {
        *(int *)(param_1 + 0xaa14) = iVar3 * 0xf0;
      }
      *(undefined4 *)(param_1 + 0xa9a0) = 0;
      *(undefined4 *)(param_1 + 0xaa2c) = 0xffffffff;
      iVar3 = FUN_009a38e4(iVar13,local_50);
      if (iVar3 == 0) {
LAB_009a4244:
        uVar8 = (*(code *)&SUB_ffa24a90)(iVar13);
        *(undefined4 *)(param_1 + 0xa9a0) = uVar8;
      }
      else {
        puVar10 = (undefined1 *)(param_1 + 0xa91f);
        do {
          puVar9 = puVar10 + 1;
          puVar10[0x41] = *puVar9;
          puVar10 = puVar9;
        } while (puVar9 != (undefined1 *)(param_1 + 0xa95f));
        iVar3 = 0;
        pcVar4 = acStack_38;
        do {
          iVar11 = iVar3 * 4;
          iVar3 = iVar3 + 1;
          *pcVar4 = *(char *)(iVar13 + iVar11) != -1;
          pcVar4 = pcVar4 + 1;
        } while (iVar3 != 0x10);
        if (*(char *)(iVar13 + (uint)local_50[0] * 4) == '\0') {
          local_5c[0] = local_50[0];
          FUN_00997590(acStack_44,0,0xb);
          iVar3 = 0;
          pbVar6 = &DAT_009b2678;
          do {
            bVar1 = *pbVar6;
            iVar3 = iVar3 + 1;
            bVar2 = local_50[bVar1];
            if (acStack_38[bVar2] == '\0') {
              acStack_38[bVar2] = '\x01';
              acStack_44[bVar1] = '\x01';
              local_5c[bVar1] = bVar2;
            }
            pbVar6 = pbVar6 + 1;
          } while (iVar3 != 3);
          iVar3 = 1;
          pcVar4 = acStack_44;
          do {
            pcVar4 = pcVar4 + 1;
            if (*pcVar4 == '\0') {
              iVar11 = 1;
              pcVar16 = acStack_38;
              while (pcVar16 = pcVar16 + 1, *pcVar16 != '\0') {
                iVar11 = iVar11 + 1;
                if (iVar11 == 0x10) goto LAB_009a4238;
              }
              acStack_38[iVar11] = '\x01';
              local_5c[iVar3] = (byte)iVar11;
            }
            iVar3 = iVar3 + 1;
          } while (iVar3 != 0xb);
          iVar3 = 1;
          do {
            iVar11 = 0;
            puVar15 = &DAT_009b267b + iVar3 * 4;
            do {
              *(undefined *)(param_1 + 0xa960 + (uint)local_5c[iVar3] * 4 + iVar11) = *puVar15;
              iVar11 = iVar11 + 1;
              puVar15 = puVar15 + 1;
            } while (iVar11 != 4);
            iVar3 = iVar3 + 1;
          } while (iVar3 != 0xb);
          uVar8 = (*(code *)&SUB_ffa24a90)();
          iVar3 = FUN_009a3700();
          if (iVar3 != 0) {
            iVar3 = (*(code *)&SUB_ffa24ed4)(uVar8);
            *(int *)(param_1 + 0xaa2c) = iVar3;
            if (iVar3 == 0) {
              *(undefined4 *)(param_1 + 0xa9a0) = uVar8;
              *(undefined1 *)(param_1 + 0xa9a4) = 1;
              pbVar12 = (byte *)(param_1 + 0xa9e7);
              pbVar6 = local_5c;
              do {
                pbVar12 = pbVar12 + 1;
                *pbVar12 = *pbVar6;
                pbVar6 = pbVar6 + 1;
              } while (pbVar12 != (byte *)(param_1 + 0xa9f2));
            }
            else {
              (*(code *)&SUB_ffa24b98)(uVar8);
            }
          }
        }
LAB_009a4238:
        if (*(int *)(param_1 + 0xa9a0) == 0) goto LAB_009a4244;
      }
      iVar3 = FUN_009a3700();
      if (iVar3 != 0) {
        piVar14 = (int *)(param_1 + 0xa9a4);
        uVar5 = 0;
        do {
          iVar3 = FUN_009a3a90(param_1,uVar5 & 0xff);
          piVar14 = piVar14 + 1;
          *piVar14 = iVar3;
          if (iVar3 == 0) {
            *(undefined4 *)(param_1 + 0xaa3c) = 1;
            *(undefined4 *)(param_1 + 0xaa60) = 6;
            FUN_009a3758(param_1);
            return 0xffffffff;
          }
          uVar5 = uVar5 + 1;
        } while (uVar5 != 0x10);
        *(undefined4 *)(param_1 + 0xaa3c) = 1;
        return 0;
      }
      uVar8 = 5;
      *(undefined4 *)(param_1 + 0xa9a0) = 0;
      goto LAB_009a3ffc;
    }
  }
  uVar8 = 1;
LAB_009a3ffc:
  *(undefined4 *)(param_1 + 0xaa60) = uVar8;
  return 0xffffffff;
}


// ===== FUN_009a3f70 @ 009a3f70

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_009a3f70(int param_1,undefined4 param_2)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  char *pcVar4;
  uint uVar5;
  byte *pbVar6;
  code *pcVar7;
  undefined4 uVar8;
  undefined1 *puVar10;
  undefined1 *puVar9;
  int iVar11;
  byte *pbVar12;
  int iVar13;
  int *piVar14;
  undefined *puVar15;
  char *pcVar16;
  undefined8 uVar17;
  byte local_5c [12];
  byte local_50 [12];
  char acStack_44 [12];
  char acStack_38 [20];
  
  *(undefined4 *)(param_1 + 0xaa58) = param_2;
  *(char *)(param_1 + 0xa9a4) = (char)param_2;
  *(int *)(param_1 + 0x4c) = param_1 + 0x60;
  *(undefined4 *)(param_1 + 0x50) = 0xa8c0;
  *(undefined4 *)(param_1 + 0x5c) = 0xb4;
  *(undefined4 *)(param_1 + 0x54) = 0x168;
  *(undefined4 *)(param_1 + 0x58) = 0xf0;
  pcVar7 = (code *)&SUB_ffb0bc28;
  *(undefined4 *)(param_1 + 0xaa00) = _DAT_0000f3d4;
  if (_DAT_0000f3e0 == 1) {
    uVar17 = FUN_009a3700();
    if (((int)uVar17 != 0) && (*(int *)((int)((ulonglong)uVar17 >> 0x20) + 0xe30) == 1)) {
      iVar13 = param_1 + 0xa920;
      iVar3 = (*pcVar7)(iVar13);
      if ((iVar3 != 0) || (iVar3 = FUN_009a38e4(iVar13,param_1 + 0xa9e8), iVar3 == 0)) {
        uVar8 = 2;
        goto LAB_009a3ffc;
      }
      uVar8 = (*(code *)&SUB_ffa2855c)();
      *(undefined4 *)(param_1 + 0xaa04) = uVar8;
      iVar3 = (*(code *)&SUB_ffa2f058)(param_1 + 0xaa08,param_1 + 0xaa0c);
      if (iVar3 != 0) {
        uVar8 = 3;
        goto LAB_009a3ffc;
      }
      uVar5 = *(uint *)(param_1 + 0xaa08);
      if (uVar5 < 0x2d0) {
        iVar3 = 1;
      }
      else {
        iVar3 = 2;
      }
      *(int *)(param_1 + 0xaa1c) = iVar3;
      if ((uint)(iVar3 * 0x168) < uVar5) {
        uVar5 = iVar3 * 0x168;
      }
      *(uint *)(param_1 + 0xaa10) = uVar5 & 0xfffffff8;
      if (*(int *)(param_1 + 0xaa04) == 0) {
        iVar3 = 1;
      }
      else {
        iVar3 = 2;
      }
      *(int *)(param_1 + 0xaa18) = iVar3;
      if (*(uint *)(param_1 + 0xaa0c) < (uint)(iVar3 * 0xf0)) {
        *(uint *)(param_1 + 0xaa14) = *(uint *)(param_1 + 0xaa0c);
      }
      else {
        *(int *)(param_1 + 0xaa14) = iVar3 * 0xf0;
      }
      *(undefined4 *)(param_1 + 0xa9a0) = 0;
      *(undefined4 *)(param_1 + 0xaa2c) = 0xffffffff;
      iVar3 = FUN_009a38e4(iVar13,local_50);
      if (iVar3 == 0) {
LAB_009a4244:
        uVar8 = (*(code *)&SUB_ffa24a90)(iVar13);
        *(undefined4 *)(param_1 + 0xa9a0) = uVar8;
      }
      else {
        puVar10 = (undefined1 *)(param_1 + 0xa91f);
        do {
          puVar9 = puVar10 + 1;
          puVar10[0x41] = *puVar9;
          puVar10 = puVar9;
        } while (puVar9 != (undefined1 *)(param_1 + 0xa95f));
        iVar3 = 0;
        pcVar4 = acStack_38;
        do {
          iVar11 = iVar3 * 4;
          iVar3 = iVar3 + 1;
          *pcVar4 = *(char *)(iVar13 + iVar11) != -1;
          pcVar4 = pcVar4 + 1;
        } while (iVar3 != 0x10);
        if (*(char *)(iVar13 + (uint)local_50[0] * 4) == '\0') {
          local_5c[0] = local_50[0];
          FUN_00997590(acStack_44,0,0xb);
          iVar3 = 0;
          pbVar6 = &DAT_009b2678;
          do {
            bVar1 = *pbVar6;
            iVar3 = iVar3 + 1;
            bVar2 = local_50[bVar1];
            if (acStack_38[bVar2] == '\0') {
              acStack_38[bVar2] = '\x01';
              acStack_44[bVar1] = '\x01';
              local_5c[bVar1] = bVar2;
            }
            pbVar6 = pbVar6 + 1;
          } while (iVar3 != 3);
          iVar3 = 1;
          pcVar4 = acStack_44;
          do {
            pcVar4 = pcVar4 + 1;
            if (*pcVar4 == '\0') {
              iVar11 = 1;
              pcVar16 = acStack_38;
              while (pcVar16 = pcVar16 + 1, *pcVar16 != '\0') {
                iVar11 = iVar11 + 1;
                if (iVar11 == 0x10) goto LAB_009a4238;
              }
              acStack_38[iVar11] = '\x01';
              local_5c[iVar3] = (byte)iVar11;
            }
            iVar3 = iVar3 + 1;
          } while (iVar3 != 0xb);
          iVar3 = 1;
          do {
            iVar11 = 0;
            puVar15 = &DAT_009b267b + iVar3 * 4;
            do {
              *(undefined *)(param_1 + 0xa960 + (uint)local_5c[iVar3] * 4 + iVar11) = *puVar15;
              iVar11 = iVar11 + 1;
              puVar15 = puVar15 + 1;
            } while (iVar11 != 4);
            iVar3 = iVar3 + 1;
          } while (iVar3 != 0xb);
          uVar8 = (*(code *)&SUB_ffa24a90)();
          iVar3 = FUN_009a3700();
          if (iVar3 != 0) {
            iVar3 = (*(code *)&SUB_ffa24ed4)(uVar8);
            *(int *)(param_1 + 0xaa2c) = iVar3;
            if (iVar3 == 0) {
              *(undefined4 *)(param_1 + 0xa9a0) = uVar8;
              *(undefined1 *)(param_1 + 0xa9a4) = 1;
              pbVar12 = (byte *)(param_1 + 0xa9e7);
              pbVar6 = local_5c;
              do {
                pbVar12 = pbVar12 + 1;
                *pbVar12 = *pbVar6;
                pbVar6 = pbVar6 + 1;
              } while (pbVar12 != (byte *)(param_1 + 0xa9f2));
            }
            else {
              (*(code *)&SUB_ffa24b98)(uVar8);
            }
          }
        }
LAB_009a4238:
        if (*(int *)(param_1 + 0xa9a0) == 0) goto LAB_009a4244;
      }
      iVar3 = FUN_009a3700();
      if (iVar3 != 0) {
        piVar14 = (int *)(param_1 + 0xa9a4);
        uVar5 = 0;
        do {
          iVar3 = FUN_009a3a90(param_1,uVar5 & 0xff);
          piVar14 = piVar14 + 1;
          *piVar14 = iVar3;
          if (iVar3 == 0) {
            *(undefined4 *)(param_1 + 0xaa3c) = 1;
            *(undefined4 *)(param_1 + 0xaa60) = 6;
            FUN_009a3758(param_1);
            return 0xffffffff;
          }
          uVar5 = uVar5 + 1;
        } while (uVar5 != 0x10);
        *(undefined4 *)(param_1 + 0xaa3c) = 1;
        return 0;
      }
      uVar8 = 5;
      *(undefined4 *)(param_1 + 0xa9a0) = 0;
      goto LAB_009a3ffc;
    }
  }
  uVar8 = 1;
LAB_009a3ffc:
  *(undefined4 *)(param_1 + 0xaa60) = uVar8;
  return 0xffffffff;
}


// ===== FUN_009a4328 @ 009a4328

int FUN_009a4328(int param_1)

{
  undefined4 uVar1;
  char *pcVar2;
  int iVar3;
  char *pcVar4;
  int *piVar5;
  
  if (*(int *)(param_1 + 0xaa3c) == 0) {
    return param_1;
  }
  iVar3 = *(int *)(param_1 + 0xaa58);
  *(int *)(param_1 + 0xaa58) = iVar3 + 1;
  if (iVar3 != 0) {
    return -1;
  }
  if (*(char *)(param_1 + 0xa9a4) == '\0') goto LAB_009a3834;
  iVar3 = (*(code *)&SUB_ffb0bc28)(&DAT_009fac08);
  if (iVar3 == 0) {
    pcVar2 = &DAT_009fac08;
    pcVar4 = (char *)(param_1 + 0xa95f);
    do {
      pcVar4 = pcVar4 + 1;
      if (*pcVar2 != *pcVar4) goto LAB_009a38b4;
      pcVar2 = pcVar2 + 1;
    } while (pcVar4 != (char *)(param_1 + 0xa99f));
    uVar1 = (*(code *)&SUB_ffa24a90)(param_1 + 0xa920);
    iVar3 = FUN_009a3700();
    if (iVar3 != 0) {
      iVar3 = (*(code *)&SUB_ffa24ed4)(uVar1);
      if (iVar3 == 0) {
        *(int *)(param_1 + 0xaa34) = *(int *)(param_1 + 0xaa34) + 1;
      }
      else {
        *(int *)(param_1 + 0xaa5c) = *(int *)(param_1 + 0xaa5c) + 1;
      }
      iVar3 = (*(code *)&SUB_ffa24b98)(uVar1);
      if (iVar3 == 0 || iVar3 == 0xd) goto LAB_009a382c;
    }
    *(int *)(param_1 + 0xaa5c) = *(int *)(param_1 + 0xaa5c) + 1;
  }
  else {
LAB_009a38b4:
    *(int *)(param_1 + 0xaa38) = *(int *)(param_1 + 0xaa38) + 1;
  }
LAB_009a382c:
  *(undefined1 *)(param_1 + 0xa9a4) = 0;
LAB_009a3834:
  piVar5 = (int *)(param_1 + 0xa9a4);
  do {
    piVar5 = piVar5 + 1;
    if (*piVar5 != 0) {
      iVar3 = (*(code *)&SUB_ffa30538)();
      if (iVar3 != 0 && iVar3 != 0xd) {
        *(int *)(param_1 + 0xaa5c) = *(int *)(param_1 + 0xaa5c) + 1;
      }
      *piVar5 = 0;
    }
  } while ((int *)(param_1 + 0xa9e4) != piVar5);
  if (*(int *)(param_1 + 0xa9a0) != 0) {
    iVar3 = (*(code *)&SUB_ffa24b98)();
    if (iVar3 != 0 && iVar3 != 0xd) {
      *(int *)(param_1 + 0xaa5c) = *(int *)(param_1 + 0xaa5c) + 1;
    }
    *(undefined4 *)(param_1 + 0xa9a0) = 0;
  }
  *(undefined4 *)(param_1 + 0xaa3c) = 0;
  iVar3 = 0;
  if (*(int *)(param_1 + 0xaa5c) != 0) {
    iVar3 = -1;
  }
  return iVar3;
}


// ===== FUN_009a433c @ 009a433c

bool FUN_009a433c(int *param_1)

{
  if ((((param_1 == (int *)0x0) || (*param_1 == 0)) || (param_1[2] != 0x168)) ||
     ((param_1[3] != 0xf0 || (0xf4c < param_1[4] - 0xb4U)))) {
    return false;
  }
  return (uint)(param_1[4] * 0xf0) <= (uint)param_1[1];
}


// ===== FUN_009a43a0 @ 009a43a0

void FUN_009a43a0(int *param_1,uint param_2,uint param_3,byte param_4)

{
  int iVar1;
  int iVar2;
  
  if ((int)(param_2 | param_3) < 0) {
    return;
  }
  if ((uint)param_1[2] <= param_2) {
    return;
  }
  if ((uint)param_1[3] <= param_3) {
    return;
  }
  iVar1 = param_1[4] * param_3 + (param_2 >> 1);
  iVar2 = *param_1;
  if ((param_2 & 1) == 0) {
    *(byte *)(iVar2 + iVar1) = param_4 | *(byte *)(iVar2 + iVar1) & 0xf0;
  }
  else {
    *(byte *)(iVar2 + iVar1) = *(byte *)(iVar2 + iVar1) & 0xf | param_4 << 4;
  }
  return;
}


// ===== FUN_009a43f8 @ 009a43f8

void FUN_009a43f8(undefined4 param_1,int param_2,int param_3,int param_4,int param_5,
                 undefined1 param_6)

{
  int extraout_r1;
  int iVar1;
  
  param_5 = param_3 + param_5;
  do {
    iVar1 = param_2;
    while (iVar1 < param_2 + param_4) {
      FUN_009a43a0(param_1,iVar1,param_3,param_6);
      iVar1 = extraout_r1 + 1;
    }
    param_3 = param_3 + 1;
  } while (param_3 < param_5);
  return;
}


// ===== FUN_009a444c @ 009a444c

uint FUN_009a444c(undefined4 *param_1)

{
  byte bVar1;
  int iVar2;
  byte *pbVar3;
  uint uVar4;
  
  uVar4 = (uint)*(byte *)*param_1;
  if (uVar4 < 0xf0) {
    if (uVar4 < 0xe0) {
      if (uVar4 < 0xc0) {
        iVar2 = 0;
        goto LAB_009a4484;
      }
      iVar2 = 1;
    }
    else {
      iVar2 = 2;
    }
  }
  else {
    iVar2 = 3;
  }
  uVar4 = uVar4 & 0x3fU >> iVar2;
LAB_009a4484:
  pbVar3 = (byte *)*param_1 + 1;
  if (iVar2 == 0) {
    *param_1 = pbVar3;
    return uVar4;
  }
  do {
    bVar1 = *pbVar3;
    if ((bVar1 & 0xc0) != 0x80) {
      uVar4 = 0xfffd;
      break;
    }
    iVar2 = iVar2 + -1;
    pbVar3 = pbVar3 + 1;
    uVar4 = bVar1 & 0x3f | uVar4 << 6;
  } while (iVar2 != 0);
  *param_1 = pbVar3;
  return uVar4;
}


// ===== FUN_009a44e8 @ 009a44e8

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_009a44e8(int *param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = 0;
  uVar1 = param_1[1];
  while (uVar3 = uVar1, uVar2 < uVar3) {
    uVar1 = uVar2 + uVar3 >> 1;
    if (*(ushort *)(*param_1 + uVar1 * 10) < param_2) {
      uVar2 = uVar1 + 1;
      uVar1 = uVar3;
    }
  }
  if ((uVar2 < (uint)param_1[1]) && (*(ushort *)(*param_1 + uVar2 * 10) == param_2)) {
    return *param_1 + uVar2 * 10;
  }
  _DAT_009fd09c = _DAT_009fd09c + 1;
  return 0;
}


// ===== FUN_009a4568 @ 009a4568

int FUN_009a4568(int param_1,char *param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  char *local_14;
  undefined4 uStack_10;
  
  iVar4 = 0;
  local_14 = param_2;
  uStack_10 = param_3;
  while (*local_14 != '\0') {
    uVar1 = FUN_009a444c(&local_14);
    iVar2 = FUN_009a44e8(param_1,uVar1);
    if (iVar2 != 0) {
      iVar4 = iVar4 + (uint)*(ushort *)(iVar2 + 6);
    }
  }
  uVar3 = (uint)(*(int *)(param_1 + 0xc) == 1);
  if (iVar4 == 0) {
    uVar3 = 0;
  }
  return (iVar4 + 8U >> 4) - uVar3;
}


// ===== FUN_009a45d4 @ 009a45d4

void FUN_009a45d4(char *param_1,uint param_2,undefined4 param_3,int param_4)

{
  char extraout_r1;
  char *pcVar1;
  char *pcVar2;
  
  pcVar2 = param_1 + 4;
  do {
    pcVar1 = pcVar2;
    FUN_009a5ce4(param_2,10,param_3,param_4);
    param_4 = param_2 * -0x33333333;
    pcVar2 = pcVar1 + -1;
    *pcVar2 = extraout_r1 + '0';
    param_2 = param_2 / 10;
  } while (pcVar2 != param_1);
  pcVar1[3] = '\0';
  return;
}


// ===== FUN_009a461c @ 009a461c

int FUN_009a461c(int param_1,uint param_2)

{
  undefined1 *puVar1;
  uint uVar2;
  uint uVar3;
  int *piVar4;
  undefined1 *puVar5;
  bool bVar6;
  bool bVar7;
  int aiStack_20 [3];
  
  aiStack_20[0] = param_1;
  uVar3 = 0;
  piVar4 = aiStack_20;
  do {
    uVar2 = uVar3;
    uVar3 = uVar2 + 1;
    bVar7 = 4 < uVar3;
    if (uVar3 != 5) {
      bVar7 = 8 < param_2;
    }
    bVar6 = param_2 != 9;
    *(char *)piVar4 = (char)param_2 + (char)(param_2 / 10) * -10 + '0';
    param_2 = param_2 / 10;
    piVar4 = (int *)((int)piVar4 + 1);
  } while (bVar7 && (uVar3 != 5 && bVar6));
  puVar5 = (undefined1 *)(param_1 + -1);
  puVar1 = (undefined1 *)((int)aiStack_20 + uVar2);
  do {
    puVar5 = puVar5 + 1;
    *puVar5 = *puVar1;
    puVar1 = puVar1 + -1;
  } while (puVar5 != (undefined1 *)(param_1 + uVar2));
  *(undefined1 *)(param_1 + uVar3) = 0;
  return param_1 + uVar3;
}


// ===== FUN_009a4694 @ 009a4694

void FUN_009a4694(char *param_1,int param_2)

{
  char *pcVar1;
  
  pcVar1 = (char *)(param_2 + -1);
  while( true ) {
    pcVar1 = pcVar1 + 1;
    if (*pcVar1 == '\0') break;
    *param_1 = *pcVar1;
    param_1 = param_1 + 1;
  }
  *param_1 = '\0';
  return;
}


// ===== FUN_009a46b4 @ 009a46b4

void FUN_009a46b4(undefined4 param_1,int param_2,int param_3,int param_4,int param_5,
                 undefined1 param_6)

{
  int extraout_r1;
  int iVar1;
  
  iVar1 = 0x10 - param_2;
  if (param_2 < 0x10) {
    param_2 = 0x10;
    param_4 = param_4 - iVar1;
  }
  if (0x158 < param_2 + param_4) {
    param_4 = 0x158 - param_2;
  }
  if (param_4 < 1) {
    return;
  }
  param_5 = param_3 + param_5;
  do {
    iVar1 = param_2;
    while (iVar1 < param_2 + param_4) {
      FUN_009a43a0(param_1,iVar1,param_3,param_6);
      iVar1 = extraout_r1 + 1;
    }
    param_3 = param_3 + 1;
  } while (param_3 < param_5);
  return;
}


// ===== FUN_009a46c4 @ 009a46c4

void FUN_009a46c4(undefined4 param_1,int param_2,int param_3,int param_4,int param_5,
                 undefined1 param_6)

{
  int extraout_r1;
  int iVar1;
  
  if (0x158 < param_2 + param_4) {
    param_4 = 0x158 - param_2;
  }
  if (param_4 < 1) {
    return;
  }
  param_5 = param_3 + param_5;
  do {
    iVar1 = param_2;
    while (iVar1 < param_2 + param_4) {
      FUN_009a43a0(param_1,iVar1,param_3,param_6);
      iVar1 = extraout_r1 + 1;
    }
    param_3 = param_3 + 1;
  } while (param_3 < param_5);
  return;
}


// ===== FUN_009a46f4 @ 009a46f4

void FUN_009a46f4(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4,uint param_5)

{
  undefined4 uVar1;
  
  uVar1 = param_3;
  FUN_009a43f8();
  if (99 < param_5) {
    param_5 = 100;
  }
  FUN_009a43f8(param_1,param_2,param_3,(int)(param_4 * param_5) / 100,2,6,uVar1);
  return;
}


// ===== FUN_009a4768 @ 009a4768

uint FUN_009a4768(undefined4 param_1,int param_2,int param_3,int param_4,char *param_5,char param_6)

{
  uint uVar1;
  ushort uVar2;
  char cVar3;
  char cVar4;
  char cVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  char cVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  int iVar13;
  
  cVar5 = param_6;
  param_3 = param_3 << 4;
  do {
    do {
      uVar1 = param_3 + 8U >> 4;
      if (*param_5 == '\0') {
        return uVar1;
      }
      uVar6 = FUN_009a444c(&param_5);
      iVar7 = FUN_009a44e8(param_2,uVar6);
    } while (iVar7 == 0);
    cVar3 = *(char *)(iVar7 + 4);
    uVar12 = 0;
    cVar4 = *(char *)(iVar7 + 5);
    iVar8 = *(int *)(param_2 + 8);
    uVar2 = *(ushort *)(iVar7 + 8);
    for (iVar11 = 0; iVar11 < (int)(uint)*(byte *)(iVar7 + 3); iVar11 = iVar11 + 1) {
      for (iVar13 = 0; iVar13 < (int)(uint)*(byte *)(iVar7 + 2); iVar13 = iVar13 + 1) {
        if (*(int *)(param_2 + 0xc) == 2) {
          uVar10 = 3;
        }
        else {
          uVar10 = 1;
        }
        uVar10 = uVar10 & (int)(uint)*(byte *)(iVar8 + (uint)uVar2 + (uVar12 >> 3)) >> (uVar12 & 7);
        if (uVar10 != 0) {
          cVar9 = cVar5;
          if (*(int *)(param_2 + 0xc) == 2 && uVar10 != 3) {
            if (cVar5 == '\x05') {
              if (uVar10 == 2) {
                cVar9 = '\n';
              }
              else {
                cVar9 = '\t';
              }
            }
            else if (cVar5 == '\x04') {
              if (uVar10 == 2) {
                cVar9 = '\a';
              }
              else {
                cVar9 = '\b';
              }
            }
            else {
              if (uVar10 != 2) goto LAB_009a4878;
              cVar9 = '\x06';
            }
          }
          FUN_009a43a0(param_1,iVar13 + (int)cVar3 + uVar1,iVar11 + cVar4 + param_4,cVar9);
        }
LAB_009a4878:
        uVar12 = uVar12 + *(int *)(param_2 + 0xc);
      }
    }
    param_3 = param_3 + (uint)*(ushort *)(iVar7 + 6);
  } while( true );
}


// ===== FUN_009a48d0 @ 009a48d0

void FUN_009a48d0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined1 param_5)

{
  FUN_009a4768(param_1,&DAT_009b4420,param_2,param_3,param_4,param_5,param_3);
  return;
}


// ===== FUN_009a48f8 @ 009a48f8

void FUN_009a48f8(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4,
                 undefined1 param_5)

{
  int iVar1;
  undefined4 in_lr;
  
  iVar1 = FUN_009a4568(&DAT_009b4420,param_4);
  FUN_009a4768(param_1,&DAT_009b4420,param_2 - iVar1,param_3,param_4,param_5,param_3,in_lr);
  return;
}


// ===== FUN_009a493c @ 009a493c

int FUN_009a493c(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                undefined4 param_5)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = param_3;
  iVar1 = FUN_009a48d0();
  iVar1 = FUN_009a48d0(param_1,iVar1 + 3,param_3,param_5,4,param_2,uVar2);
  return iVar1 + 0xe;
}


// ===== FUN_009a4940 @ 009a4940

int FUN_009a4940(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                undefined4 param_5)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = param_3;
  iVar1 = FUN_009a48d0();
  iVar1 = FUN_009a48d0(param_1,iVar1 + 3,param_3,param_5,4,param_2,uVar2);
  return iVar1 + 0xe;
}


// ===== FUN_009a497c @ 009a497c

void FUN_009a497c(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4,int param_5,
                 char param_6,int param_7)

{
  int iVar1;
  undefined4 unaff_r4;
  undefined4 unaff_r5;
  undefined4 unaff_r6;
  char cVar2;
  undefined4 unaff_r7;
  undefined4 unaff_r8;
  undefined4 in_lr;
  
  if (param_5 != 0) {
    FUN_009a43f8(param_1,0xc,param_2 + -4,0x150,0x10,2);
    FUN_009a43f8(param_1,0xc,param_2 + -4,2,0x10,6);
  }
  cVar2 = '\x04';
  FUN_009a48d0(param_1,0x14,param_2,param_3,4);
  if (param_7 == 0) {
    cVar2 = param_6 + '\x05';
  }
  iVar1 = FUN_009a4568(&DAT_009b4420,param_4,param_2,param_4,unaff_r4,unaff_r5,unaff_r6,unaff_r7,
                       unaff_r8,in_lr);
  FUN_009a4768(param_1,&DAT_009b4420,0x154 - iVar1,param_2,param_4,cVar2,param_2,in_lr);
  return;
}


// ===== FUN_009a4a30 @ 009a4a30

void FUN_009a4a30(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined1 param_5)

{
  int iVar1;
  
  iVar1 = FUN_009a4568(param_2,param_4,param_3,param_4,param_1,param_2,param_3);
  FUN_009a4768(param_1,param_2,0xb4 - iVar1 / 2,param_3,param_4,param_5);
  return;
}


// ===== FUN_009a4a80 @ 009a4a80

void FUN_009a4a80(undefined4 param_1)

{
  FUN_009a43f8(param_1,0,0,0x168,0xf0,1);
  FUN_009a4a30(param_1,&DAT_009b2728,0x3a,"Ritual",5);
  FUN_009a4a30(param_1,&DAT_009b4420,100,"by Latent Studios",4);
  FUN_009a43f8(param_1,0xa0,0x7e,0x28,1,3);
  FUN_009a4a30(param_1,&DAT_009b4420,0x8e,"www.latentstudios.art",6);
  FUN_009a4a30(param_1,&DAT_009b4420,0xd8,"Reading the card",4);
  return;
}


// ===== FUN_009a4b54 @ 009a4b54

undefined4 FUN_009a4b54(undefined4 param_1,int *param_2)

{
  short sVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  ushort uVar5;
  bool bVar6;
  uint uVar7;
  undefined4 uVar8;
  int iVar9;
  char **ppcVar10;
  int iVar11;
  int iVar12;
  uint uVar13;
  uint uVar14;
  char *pcVar15;
  int iVar16;
  char **ppcVar17;
  undefined4 uVar18;
  undefined *puVar19;
  char *pcVar20;
  int iVar21;
  int iVar22;
  int iVar23;
  int iVar24;
  int iVar25;
  uint uVar26;
  bool bVar27;
  bool bVar28;
  uint local_bc;
  int local_a8;
  undefined1 auStack_88 [8];
  undefined1 auStack_80 [40];
  char *local_58 [13];
  
  uVar7 = FUN_009a433c();
  uVar7 = (uVar7 ^ 1) & 1;
  if (param_2 == (int *)0x0) {
    uVar7 = 1;
  }
  if ((((uVar7 != 0) || (*param_2 == 0)) || (pcVar15 = (char *)param_2[2], pcVar15 == (char *)0x0))
     || (((param_2[3] == 0 || (param_2[4] == 0)) || ((uint)param_2[4] <= (uint)param_2[5])))) {
    return 0;
  }
  uVar7 = param_2[0xb];
  if (uVar7 < 0xd) {
    local_bc = (int)(uint)*(ushort *)(pcVar15 + 4) >> (uVar7 & 0xff) & 1;
  }
  else {
    local_bc = 0;
  }
  if ((param_2[7] == param_2[8]) && (param_2[9] == param_2[10])) {
    if (uVar7 != param_2[0xc]) {
      bVar6 = false;
      goto LAB_009a4c14;
    }
    bVar27 = param_2[0xd] != param_2[0xe];
    bVar6 = false;
  }
  else {
    bVar6 = true;
LAB_009a4c14:
    bVar27 = true;
  }
  FUN_009a43f8(param_1,0,0,0x168,0xf0,1);
  FUN_009a48d0(param_1,0x10,10,&DAT_009a887e,4);
  if (param_2[0x11] == 0) {
    iVar9 = param_2[0x10];
    if (iVar9 == 0) goto LAB_009a4ce8;
    uVar8 = FUN_009a461c(local_58,iVar9);
    pcVar20 = " photograph";
    if (iVar9 != 1) {
      pcVar20 = " photographs";
    }
    FUN_009a4694(uVar8,pcVar20);
  }
  else {
    uVar8 = FUN_009a4694(local_58,"Roll ");
    uVar8 = FUN_009a461c(uVar8,param_2[0x11]);
    uVar8 = FUN_009a4694(uVar8,&DAT_009a8889);
    uVar8 = FUN_009a461c(uVar8,param_2[0x12]);
    uVar8 = FUN_009a4694(uVar8,&DAT_009a8894);
    FUN_009a461c(uVar8,0x24);
  }
  FUN_009a48f8(param_1,0x158,10,local_58,4);
LAB_009a4ce8:
  FUN_009a43f8(param_1,0x10,0x18,0x148,1,3);
  if (param_2[0x1a] == 0) {
    pcVar20 = (char *)*param_2;
    iVar9 = FUN_009a4568(&DAT_009b2728,pcVar20);
    if (iVar9 < 0x149) {
      FUN_009a4a30(param_1,&DAT_009b2728,0x1e,pcVar20,5);
    }
    else {
      iVar9 = FUN_009a5bf0(0x14800,iVar9);
      iVar16 = 0x100;
      local_58[0] = pcVar20;
      while (*local_58[0] != '\0') {
        uVar8 = FUN_009a444c(local_58);
        iVar23 = FUN_009a44e8(&DAT_009b2728,uVar8);
        if (iVar23 != 0) {
          sVar1 = (short)iVar9;
          iVar25 = (int)(short)*(char *)(iVar23 + 4) * (int)sVar1;
          if (iVar25 < 0) {
            iVar25 = iVar25 + 0xff;
          }
          iVar24 = 1;
          bVar2 = *(byte *)(iVar23 + 2);
          uVar5 = *(ushort *)(iVar23 + 8);
          iVar21 = iVar9 * (0x1a - *(char *)(iVar23 + 5));
          if (iVar21 < 0) {
            iVar21 = iVar21 + 0xff;
          }
          local_a8 = 0x38 - (iVar21 >> 8);
          bVar3 = *(byte *)(iVar23 + 3);
          for (; ((int)sVar1 * (int)(short)(ushort)bVar3 + 0xff >> 8) * 4 + 1 != iVar24;
              iVar24 = iVar24 + 4) {
            for (iVar21 = 0; (int)sVar1 * (int)(short)(ushort)bVar2 + 0xff >> 8 != iVar21;
                iVar21 = iVar21 + 1) {
              iVar22 = 0;
              uVar7 = 0;
              bVar4 = *(byte *)(iVar23 + 2);
              do {
                iVar11 = FUN_009a5bf0((iVar21 * 4 + 1 + (uVar7 & 1) * 2) * 0x40,iVar9);
                if ((iVar11 < (int)(uint)bVar4) &&
                   (iVar12 = FUN_009a5bf0(((uVar7 & 0xfffffffe) + iVar24) * 0x40,iVar9),
                   iVar12 < (int)(uint)*(byte *)(iVar23 + 3))) {
                  uVar14 = iVar12 * (uint)bVar4 + iVar11;
                  iVar22 = iVar22 + ((int)(uint)(byte)(&DAT_009b297a)
                                                      [(uint)uVar5 + ((uVar14 & 0x7fffffff) >> 2)]
                                     >> (uVar14 * 2 & 7) & 3U);
                }
                uVar7 = uVar7 + 1;
              } while (uVar7 != 4);
              if (iVar22 + 2U >> 2 != 0) {
                FUN_009a43a0(param_1,(iVar16 + 8U >> 4) + (iVar25 >> 8) + iVar21,local_a8);
              }
            }
            local_a8 = local_a8 + 1;
          }
          iVar16 = iVar16 + (iVar9 * (uint)*(ushort *)(iVar23 + 6) >> 8);
        }
      }
    }
    if (param_2[1] != 0) {
      FUN_009a4a30(param_1,&DAT_009b4420,0x44,param_2[1],4);
    }
    iVar16 = param_2[4];
    iVar23 = param_2[5];
    iVar25 = param_2[6];
    iVar9 = iVar16 * 0x16;
    if (iVar9 < 0x143) {
      iVar21 = iVar16 * -0x16 + 0x16e >> 1;
    }
    else {
      iVar21 = iVar23 * -0x16 + 0xac;
      if (0x15 < iVar21) {
        iVar21 = 0x16;
      }
      if (iVar9 + iVar21 < 0x158) {
        iVar21 = iVar16 * -0x16 + 0x158;
      }
    }
    FUN_009a46b4(param_1,iVar21 + -6,0x51,iVar9 + 6,1,3);
    FUN_009a46b4(param_1,iVar21 + -6,0x69,iVar9 + 6,1,3);
    uVar7 = iVar21 + 6;
    for (iVar9 = 0; iVar16 != iVar9; iVar9 = iVar9 + 1) {
      if (uVar7 < 0x15f) {
        FUN_009a46b4(param_1,uVar7,0x54,4,2,3);
        if (iVar23 == iVar9) {
          uVar8 = 6;
        }
        else {
          uVar8 = 8;
        }
        FUN_009a46b4(param_1,uVar7 - 6,0x58,0x10,0xb,uVar8);
        if (iVar25 == iVar9) {
          if (iVar23 == iVar25) {
            uVar8 = 6;
          }
          else {
            uVar8 = 5;
          }
          FUN_009a46b4(param_1,uVar7 - 2,0x65,8,2,uVar8);
        }
      }
      uVar7 = uVar7 + 0x16;
    }
    uVar7 = param_2[9];
    if (uVar7 == 0) {
      ppcVar10 = local_58;
      pcVar20 = "Box speed";
    }
    else {
      iVar9 = (uVar7 ^ (int)uVar7 >> 0x1f) - ((int)uVar7 >> 0x1f);
      pcVar20 = "Pushed ";
      if ((int)uVar7 < 1) {
        pcVar20 = "Pulled ";
      }
      uVar8 = FUN_009a4694(local_58,pcVar20);
      iVar16 = iVar9;
      if (5 < iVar9) {
        iVar16 = 6;
      }
      ppcVar10 = (char **)FUN_009a4694(uVar8,*(undefined4 *)(&DAT_009b2700 + iVar16 * 4));
      pcVar20 = " stops";
      if (iVar9 < 4) {
        pcVar20 = " stop";
      }
    }
    FUN_009a4694(ppcVar10,pcVar20);
    if (*pcVar15 == pcVar15[1]) {
      uVar8 = 1;
      ppcVar10 = local_58;
      do {
        ppcVar17 = ppcVar10;
        ppcVar10 = (char **)((int)ppcVar17 + 1);
      } while (*(char *)ppcVar17 != '\0');
      FUN_009a4694(ppcVar17,&DAT_009a88a3);
    }
    else {
      uVar8 = 0;
    }
    if (param_2[9] == param_2[10]) {
      uVar18 = 0;
      if (param_2[7] != param_2[8]) {
        uVar18 = 1;
      }
    }
    else {
      uVar18 = 1;
    }
    FUN_009a497c(param_1,0x72,"Development",local_58,param_2[0xf] == 1,uVar18,uVar8);
    uVar7 = param_2[0xb];
    uVar13 = (uint)(byte)pcVar15[2];
    uVar14 = 0;
    if (uVar7 < uVar13) {
      uVar14 = uVar7;
    }
    uVar26 = local_bc;
    if (1 < uVar13) {
      uVar26 = 1;
    }
    pcVar20 = "Paper";
    if (uVar26 == 0) {
      pcVar20 = "Printed on";
    }
    bVar28 = uVar7 != param_2[0xc];
    if (bVar28) {
      uVar7 = 1;
    }
    if ((!bVar28) && (uVar7 = 0, param_2[7] != param_2[8])) {
      uVar7 = 1;
    }
    FUN_009a497c(param_1,0x82,pcVar20,
                 *(undefined4 *)(param_2[3] + (uint)*(byte *)(*(int *)(pcVar15 + 8) + uVar14) * 4),
                 param_2[0xf] == 2,uVar7,uVar13 < 2);
    if (local_bc == 0) {
      iVar9 = 0x92;
    }
    else {
      uVar14 = param_2[0xd];
      uVar7 = uVar14;
      if (0xb < uVar14) {
        uVar7 = 5;
      }
      if (uVar14 == param_2[0xe]) {
        local_bc = (uint)(param_2[7] != param_2[8]);
      }
      FUN_009a497c(param_1,0x92,"Grade",(&PTR_s_00_009a845a_0xd_009b26d0)[uVar7],param_2[0xf] == 3,
                   local_bc,0);
      iVar9 = 0xa2;
    }
    if (param_2[0x1b] != 0) {
      uVar7 = param_2[0x1c];
      if (1 < uVar7) {
        uVar7 = 2;
      }
      FUN_009a497c(param_1,iVar9,"Halation",*(undefined4 *)(&DAT_009b271c + uVar7 * 4),
                   param_2[0xf] == 4,0,0);
      iVar9 = iVar9 + 0x10;
    }
    iVar16 = param_2[0x18];
    if (iVar16 == 0) {
      pcVar15 = "from each frame\'s raw";
      ppcVar10 = local_58;
    }
    else {
      ppcVar10 = local_58;
      if (((uint)param_2[0x19] < 10) && ((&PTR_DAT_009b26a8)[param_2[0x19]] != (undefined *)0x0)) {
        uVar8 = FUN_009a4694(ppcVar10);
        ppcVar10 = (char **)FUN_009a4694(uVar8,&DAT_009a7de8);
      }
      uVar8 = FUN_009a4694(ppcVar10,"last ");
      ppcVar10 = (char **)FUN_009a461c(uVar8,((iVar16 + 0x32U) / 100) * 100,
                                       (iVar16 + 0x32U) * 0x51eb851f);
      pcVar15 = " K";
    }
    FUN_009a4694(ppcVar10,pcVar15);
    FUN_009a497c(param_1,iVar9,"Light",local_58,0,0,1);
    FUN_009a43f8(param_1,0x10,0xae,0x148,1,3);
    if (bVar27) {
      iVar9 = FUN_009a48d0(param_1,0x10,0xb8,"SET",6);
      pcVar15 = "starts a new roll with these from your next frame";
      if (!bVar6) {
        pcVar15 = "prints the rest of this roll this way";
      }
      FUN_009a48d0(param_1,iVar9 + 5,0xb8,pcVar15,5);
      if (((bVar6) && (param_2[0x11] != 0)) && (1 < (uint)param_2[0x12])) {
        uVar8 = FUN_009a4694(auStack_80,"this roll ends at frame ");
        uVar8 = FUN_009a461c(uVar8,param_2[0x12] + -1);
        FUN_009a4694(uVar8,&DAT_009a7e39);
        FUN_009a48d0(param_1,0x10,0xc6,auStack_80,4);
      }
    }
    else {
      if (param_2[0x13] == 0) {
        if (param_2[0x17] == 0) {
          iVar9 = FUN_009a48d0(param_1,0x10,0xb8,"Loaded",6);
          puVar19 = &DAT_009a8955;
        }
        else {
          FUN_009a45d4(auStack_80);
          iVar9 = FUN_009a48d0(param_1,0x10,0xb8,auStack_80,6);
          puVar19 = &DAT_009a8924;
        }
        FUN_009a48d0(param_1,iVar9 + 4,0xb8,puVar19,4);
      }
      else {
        FUN_009a45d4(auStack_88);
        pcVar15 = "Share size";
        if (param_2[0x14] != 2) {
          pcVar15 = "Developing";
        }
        iVar9 = FUN_009a48d0(param_1,0x10,0xb8,pcVar15,4);
        FUN_009a48d0(param_1,iVar9 + 4,0xb8,auStack_88,5);
        if (param_2[0x16] != 0) {
          uVar8 = FUN_009a461c(auStack_80);
          FUN_009a4694(uVar8," waiting");
          FUN_009a48f8(param_1,0x158,0xb8,auStack_80,4);
        }
        FUN_009a46f4(param_1,0x10,199,0x148,param_2[0x15]);
      }
      if (param_2[0x13] == 0) {
        FUN_009a4a30(param_1,&DAT_009b4420,0xcb,&DAT_009a897e,4);
      }
    }
    uVar8 = FUN_009a493c(param_1,0x10,0xde,&DAT_009a89b0,&DAT_009a89b7);
    if (param_2[0xf] == 0) {
      uVar8 = FUN_009a493c(param_1,uVar8,0xde,&DAT_009a89bb,"film");
      pcVar15 = "shelf";
      puVar19 = &DAT_009a89c0;
    }
    else {
      pcVar15 = "change";
      puVar19 = &DAT_009a89bb;
    }
    uVar8 = FUN_009a493c(param_1,uVar8,0xde,puVar19,pcVar15);
    uVar8 = FUN_009a493c(param_1,uVar8,0xde,"SET",&DAT_009a89d4);
    FUN_009a493c(param_1,uVar8,0xde,&DAT_009a89d9,"photographs");
  }
  else {
    FUN_009a4a80(param_1);
  }
  return 1;
}


// ===== FUN_009a5774 @ 009a5774

undefined4 FUN_009a5774(undefined4 param_1,undefined4 *param_2)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined *puVar4;
  char *pcVar5;
  undefined4 uVar6;
  undefined1 auStack_48 [8];
  undefined1 auStack_40 [16];
  undefined1 auStack_30 [24];
  
  uVar1 = FUN_009a433c();
  uVar1 = (uVar1 ^ 1) & 1;
  if (param_2 == (undefined4 *)0x0) {
    uVar1 = 1;
  }
  if (uVar1 != 0) {
    return 0;
  }
  FUN_009a43f8(param_1,0,0,0x168,0xf0,0);
  FUN_009a43f8(param_1,0,0,0x168,0xd,1);
  FUN_009a43f8(param_1,0,0xe2,0x168,0xe,1);
  if (param_2[10] == 0) {
    if (param_2[2] == 0) {
      FUN_009a43f8(param_1,0,0xd,0x168,0xd5,1);
      FUN_009a4a30(param_1,&DAT_009b2728,0x4e,"No photographs yet",5);
      if (param_2[3] != 0) {
        FUN_009a4a30(param_1,&DAT_009b4420,0x7c,"Each frame you shoot develops on",4);
        FUN_009a4a30(param_1,&DAT_009b4420,0x8a,param_2[3],6);
      }
      FUN_009a493c(param_1,8,0xe5,&DAT_009a89d9,"film");
    }
    else {
      FUN_009a45d4(auStack_48,*param_2);
      iVar2 = FUN_009a48d0(param_1,8,3,auStack_48,5);
      puVar4 = (undefined *)param_2[3];
      if ((undefined *)param_2[3] == (undefined *)0x0) {
        puVar4 = &DAT_009a7e39;
      }
      FUN_009a48d0(param_1,iVar2 + 6,3,puVar4,6);
      uVar3 = FUN_009a461c(auStack_30,param_2[1]);
      uVar3 = FUN_009a4694(uVar3,&DAT_009a8894);
      FUN_009a461c(uVar3,param_2[2]);
      FUN_009a48f8(param_1,0x160,3,auStack_30,4);
      if (param_2[4] == 0) {
        FUN_009a43f8(param_1,0,0xd,0x168,0xd5,1);
        FUN_009a4a30(param_1,&DAT_009b2728,0x66,auStack_48,4);
      }
      if (param_2[8] == 0) {
        if (param_2[5] == 0) {
          uVar3 = FUN_009a493c(param_1,8,0xe5,&DAT_009a89bb,"browse");
          uVar3 = FUN_009a493c(param_1,uVar3,0xe5,&DAT_009a89d9,"film");
          FUN_009a493c(param_1,uVar3,0xe5,&DAT_009a8aa4,"close");
          if (param_2[6] != 0) {
            return 1;
          }
          pcVar5 = "Share size next";
          if (param_2[7] != 0) {
            pcVar5 = "Share size developing";
          }
          iVar2 = FUN_009a4568(&DAT_009b4420,pcVar5);
          FUN_009a48f8(param_1,0x160,0xe5,pcVar5,4);
          if (param_2[7] == 0) {
            return 1;
          }
          FUN_009a46f4(param_1,0x160 - iVar2,0xee,iVar2,param_2[7]);
          return 1;
        }
        uVar6 = 6;
        uVar3 = 8;
        pcVar5 = "Developed";
      }
      else {
        FUN_009a43f8(param_1,0,0x5c,0x168,0x3a,2);
        FUN_009a43f8(param_1,0,0x5c,0x168,1,3);
        FUN_009a43f8(param_1,0,0x95,0x168,1,3);
        uVar3 = FUN_009a4694(auStack_40,"Delete ");
        uVar3 = FUN_009a4694(uVar3,auStack_48);
        FUN_009a4694(uVar3,&DAT_009a8a40);
        FUN_009a4a30(param_1,&DAT_009b2728,0x60,auStack_40,5);
        FUN_009a4a30(param_1,&DAT_009b4420,0x86,
                     "Its raw, Canon\'s JPEG and its print leave the card",4);
        uVar3 = FUN_009a493c(param_1,8,0xe5,"SET","delete");
        pcVar5 = "any other key keeps it";
        uVar6 = 4;
      }
      FUN_009a48d0(param_1,uVar3,0xe5,pcVar5,uVar6);
    }
  }
  else {
    FUN_009a43f8(param_1,0,0xd,0x168,0xd5,1);
    FUN_009a4a80(param_1);
  }
  return 1;
}


// ===== FUN_009a5bf0 @ 009a5bf0

uint FUN_009a5bf0(uint param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  bool bVar4;
  
  if (param_2 - 1 == 0) {
    return param_1;
  }
  if (param_2 == 0) {
    uVar3 = 0;
    if (param_1 != 0) {
      uVar3 = 0xffffffff;
    }
    return uVar3;
  }
  if (param_1 <= param_2) {
    return (uint)(param_1 == param_2);
  }
  if ((param_2 & param_2 - 1) == 0) {
    if (param_2 < 0x10000) {
      iVar2 = 0;
    }
    else {
      param_2 = param_2 >> 0x10;
      iVar2 = 0x10;
    }
    if (0xff < param_2) {
      param_2 = param_2 >> 8;
      iVar2 = iVar2 + 8;
    }
    if (0xf < param_2) {
      param_2 = param_2 >> 4;
      iVar2 = iVar2 + 4;
    }
    if (param_2 < 5) {
      uVar3 = iVar2 + (param_2 >> 1);
    }
    else {
      uVar3 = iVar2 + 3;
    }
    return param_1 >> (uVar3 & 0xff);
  }
  if ((param_2 & 0xe0000000) == 0) {
    param_2 = param_2 << 3;
    uVar3 = 8;
  }
  else {
    uVar3 = 1;
  }
  for (; param_2 < 0x10000000 && param_2 < param_1; param_2 = param_2 << 4) {
    uVar3 = uVar3 << 4;
  }
  for (; param_2 < 0x80000000 && param_2 < param_1; param_2 = param_2 << 1) {
    uVar3 = uVar3 << 1;
  }
  uVar1 = 0;
  while( true ) {
    if (param_2 <= param_1) {
      param_1 = param_1 - param_2;
      uVar1 = uVar1 | uVar3;
    }
    if (param_2 >> 1 <= param_1) {
      param_1 = param_1 - (param_2 >> 1);
      uVar1 = uVar1 | uVar3 >> 1;
    }
    if (param_2 >> 2 <= param_1) {
      param_1 = param_1 - (param_2 >> 2);
      uVar1 = uVar1 | uVar3 >> 2;
    }
    if (param_2 >> 3 <= param_1) {
      param_1 = param_1 - (param_2 >> 3);
      uVar1 = uVar1 | uVar3 >> 3;
    }
    bVar4 = param_1 == 0;
    if (!bVar4) {
      uVar3 = uVar3 >> 4;
      bVar4 = uVar3 == 0;
    }
    if (bVar4) break;
    param_2 = param_2 >> 4;
  }
  return uVar1;
}


// ===== FUN_009a5ce4 @ 009a5ce4

ulonglong FUN_009a5ce4(int param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  
  if (param_2 != 0) {
    iVar2 = FUN_009a5bf0();
    return CONCAT44(param_1 - param_2 * iVar2,iVar2);
  }
  uVar1 = 0;
  if (param_1 != 0) {
    uVar1 = 0xffffffff;
  }
  return (ulonglong)uVar1;
}


// ===== FUN_009a5cec @ 009a5cec

void FUN_009a5cec(void)

{
  FUN_009a5bf0();
  return;
}


// ===== FUN_009a5d0c @ 009a5d0c

uint FUN_009a5d0c(uint param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  bool in_NG;
  bool bVar7;
  
  uVar6 = param_1 ^ param_2;
  uVar4 = param_2;
  if (in_NG) {
    uVar4 = -param_2;
  }
  if (uVar4 - 1 == 0) {
    if ((int)param_2 < 0) {
      param_1 = -param_1;
    }
    return param_1;
  }
  uVar5 = param_1;
  if ((int)param_1 < 0) {
    uVar5 = -param_1;
  }
  if (uVar5 <= uVar4) {
    if (uVar5 < uVar4) {
      param_1 = 0;
    }
    if (uVar5 == uVar4) {
      param_1 = (int)uVar6 >> 0x1f | 1;
    }
    return param_1;
  }
  if ((uVar4 & uVar4 - 1) == 0) {
    if (uVar4 < 0x10000) {
      iVar3 = 0;
    }
    else {
      uVar4 = uVar4 >> 0x10;
      iVar3 = 0x10;
    }
    if (0xff < uVar4) {
      uVar4 = uVar4 >> 8;
      iVar3 = iVar3 + 8;
    }
    if (0xf < uVar4) {
      uVar4 = uVar4 >> 4;
      iVar3 = iVar3 + 4;
    }
    if (uVar4 < 5) {
      uVar4 = iVar3 + (uVar4 >> 1);
    }
    else {
      uVar4 = iVar3 + 3;
    }
    uVar5 = uVar5 >> (uVar4 & 0xff);
    if ((int)uVar6 < 0) {
      uVar5 = -uVar5;
    }
    return uVar5;
  }
  if ((uVar4 & 0xe0000000) == 0) {
    uVar4 = uVar4 << 3;
    uVar2 = 8;
  }
  else {
    uVar2 = 1;
  }
  for (; uVar4 < 0x10000000 && uVar4 < uVar5; uVar4 = uVar4 << 4) {
    uVar2 = uVar2 << 4;
  }
  for (; uVar4 < 0x80000000 && uVar4 < uVar5; uVar4 = uVar4 << 1) {
    uVar2 = uVar2 << 1;
  }
  uVar1 = 0;
  while( true ) {
    if (uVar4 <= uVar5) {
      uVar5 = uVar5 - uVar4;
      uVar1 = uVar1 | uVar2;
    }
    if (uVar4 >> 1 <= uVar5) {
      uVar5 = uVar5 - (uVar4 >> 1);
      uVar1 = uVar1 | uVar2 >> 1;
    }
    if (uVar4 >> 2 <= uVar5) {
      uVar5 = uVar5 - (uVar4 >> 2);
      uVar1 = uVar1 | uVar2 >> 2;
    }
    if (uVar4 >> 3 <= uVar5) {
      uVar5 = uVar5 - (uVar4 >> 3);
      uVar1 = uVar1 | uVar2 >> 3;
    }
    bVar7 = uVar5 == 0;
    if (!bVar7) {
      uVar2 = uVar2 >> 4;
      bVar7 = uVar2 == 0;
    }
    if (bVar7) break;
    uVar4 = uVar4 >> 4;
  }
  if ((int)uVar6 < 0) {
    uVar1 = -uVar1;
  }
  return uVar1;
}


// ===== FUN_009a5e2c @ 009a5e2c

ulonglong FUN_009a5e2c(uint param_1,int param_2)

{
  int iVar1;
  bool bVar2;
  
  if (param_2 != 0) {
    iVar1 = FUN_009a5d0c();
    return CONCAT44(param_1 - param_2 * iVar1,iVar1);
  }
  bVar2 = (int)param_1 < 0;
  if (0 < (int)param_1) {
    param_1 = 0x7fffffff;
  }
  if (bVar2) {
    param_1 = 0x80000000;
  }
  return (ulonglong)param_1;
}


// ===== FUN_009a5e34 @ 009a5e34

void FUN_009a5e34(void)

{
  FUN_009a5d0c();
  return;
}


// ===== FUN_009a5e58 @ 009a5e58

ulonglong FUN_009a5e58(uint param_1,uint param_2,uint param_3,uint param_4)

{
  int iVar1;
  byte bVar2;
  byte bVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  bool bVar14;
  bool bVar15;
  
  uVar6 = param_4 ^ 0x80000000;
  uVar10 = param_2 << 1;
  iVar8 = (int)uVar10 >> 0x15;
  iVar1 = (int)(param_4 << 1) >> 0x15;
  if ((((((param_2 ^ param_4) & 0x7fffffff) == 0 && param_1 == param_3 ||
        uVar10 == 0 && param_1 == 0) || param_4 << 1 == 0 && param_3 == 0) || iVar8 == -1) ||
      iVar1 == -1) {
    if (iVar8 == -1 || iVar1 == -1) {
      uVar10 = param_3;
      uVar5 = uVar6;
      if (iVar8 == -1) {
        uVar10 = param_1;
        uVar5 = param_2;
      }
      if (iVar8 != -1 || iVar1 != -1) {
        param_3 = uVar10;
        uVar6 = uVar5;
      }
      bVar14 = (uVar5 & 0xfffff) == 0;
      bVar15 = uVar10 == 0 && bVar14;
      if (uVar10 == 0 && bVar14) {
        bVar15 = param_3 == 0 && (uVar6 & 0xfffff) == 0;
      }
      if (!bVar15 || uVar5 != uVar6) {
        uVar5 = uVar5 | 0x80000;
      }
      return CONCAT44(uVar5,uVar10);
    }
    if (((param_2 ^ param_4) & 0x7fffffff) != 0 || param_1 != param_3) {
      if (uVar10 == 0 && param_1 == 0) {
        param_1 = param_3;
        param_2 = uVar6;
      }
      return CONCAT44(param_2,param_1);
    }
    if (param_2 != uVar6) {
      return 0;
    }
    if ((param_2 & 0x7fffffff) >> 0x14 == 0) {
      bVar2 = (byte)(param_1 >> 0x1f);
      uVar10 = param_2 * 2 + (uint)bVar2;
      if (CARRY4(param_2,param_2) || CARRY4(param_2 * 2,(uint)bVar2)) {
        uVar10 = uVar10 | 0x80000000;
      }
      return CONCAT44(uVar10,param_1 << 1);
    }
    if (uVar10 < 0xffc00000) {
      return CONCAT44(param_2 + 0x100000,param_1);
    }
    param_2 = param_2 & 0x80000000;
LAB_009a6128:
    return (ulonglong)(param_2 | 0x7ff00000) << 0x20;
  }
  uVar10 = (param_2 & 0x7fffffff) >> 0x14;
  uVar5 = (param_4 & 0x7fffffff) >> 0x14;
  uVar12 = uVar5 - uVar10;
  bVar14 = uVar12 != 0;
  if (uVar5 < uVar10) {
    uVar12 = -uVar12;
  }
  uVar11 = param_1;
  uVar7 = param_2;
  if (bVar14 && uVar10 <= uVar5) {
    uVar10 = uVar10 + uVar12;
    uVar11 = param_3;
    uVar7 = uVar6;
    param_3 = param_1;
    uVar6 = param_2;
  }
  if (0x36 < uVar12) {
    return CONCAT44(uVar7,uVar11);
  }
  uVar5 = uVar7 & 0xfffff | 0x100000;
  if ((uVar7 & 0x80000000) != 0) {
    bVar14 = uVar11 != 0;
    uVar11 = -uVar11;
    uVar5 = -(uVar5 + bVar14);
  }
  uVar7 = uVar6 & 0xfffff | 0x100000;
  if ((uVar6 & 0x80000000) != 0) {
    bVar14 = param_3 != 0;
    param_3 = -param_3;
    uVar7 = -(uVar7 + bVar14);
  }
  if (uVar10 == uVar12) {
    uVar7 = uVar7 ^ 0x100000;
    if (uVar10 == 0) {
      uVar5 = uVar5 ^ 0x100000;
      uVar10 = 1;
    }
    else {
      uVar12 = uVar12 - 1;
    }
  }
  uVar6 = -uVar12 + 0x20;
  if ((int)uVar12 < 0x21) {
    uVar13 = param_3 << (uVar6 & 0xff);
    param_3 = param_3 >> (uVar12 & 0xff);
    uVar4 = uVar11 + param_3;
    uVar9 = uVar7 << (uVar6 & 0xff);
    uVar6 = uVar4 + uVar9;
    uVar5 = uVar5 + CARRY4(uVar11,param_3) + ((int)uVar7 >> (uVar12 & 0xff)) +
            (uint)CARRY4(uVar4,uVar9);
  }
  else {
    uVar13 = uVar7 << (-uVar12 + 0x40 & 0xff);
    if (param_3 != 0) {
      uVar13 = uVar13 | 2;
    }
    uVar12 = (int)uVar7 >> (uVar12 - 0x20 & 0xff);
    uVar6 = uVar11 + uVar12;
    uVar5 = uVar5 + ((int)uVar7 >> 0x1f) + (uint)CARRY4(uVar11,uVar12);
  }
  param_2 = uVar5 & 0x80000000;
  uVar12 = uVar5;
  if ((int)uVar5 < 0) {
    bVar14 = uVar13 == 0;
    uVar13 = -uVar13;
    uVar12 = -uVar6;
    uVar6 = -(uVar6 + !bVar14);
    uVar12 = -(uVar5 + (bVar14 <= uVar12));
  }
  if (0xfffff < uVar12) {
    uVar11 = uVar10 - 1;
    if (0x1fffff < uVar12) {
      bVar2 = (byte)uVar12;
      uVar12 = uVar12 >> 1;
      bVar3 = (byte)uVar6;
      uVar6 = (uint)(bVar2 & 1) << 0x1f | uVar6 >> 1;
      uVar13 = (uint)(bVar3 & 1) << 0x1f | uVar13 >> 1;
      uVar11 = uVar10;
      if (0xffbfffff < uVar10 << 0x15) goto LAB_009a6128;
    }
LAB_009a5f78:
    bVar14 = 0x7fffffff < uVar13;
    if (uVar13 == 0x80000000) {
      bVar14 = (bool)((byte)uVar6 & 1);
    }
    return CONCAT44(uVar12 + uVar11 * 0x100000 + (uint)CARRY4(uVar6,(uint)bVar14) | param_2,
                    uVar6 + bVar14);
  }
  bVar2 = (byte)(uVar13 >> 0x1f);
  uVar13 = uVar13 << 1;
  uVar11 = uVar6 * 2;
  bVar14 = CARRY4(uVar6,uVar6);
  uVar6 = uVar6 * 2 + (uint)bVar2;
  uVar12 = uVar12 * 2 + (uint)(bVar14 || CARRY4(uVar11,(uint)bVar2));
  uVar11 = uVar10 - 2;
  if (uVar10 - 1 != 0 && 0xfffff < uVar12) goto LAB_009a5f78;
  if (uVar12 == 0) {
    iVar8 = 0x34;
    uVar10 = 0;
  }
  else {
    iVar8 = 0x14;
    uVar10 = uVar6;
    uVar6 = uVar12;
  }
  uVar12 = uVar6;
  if (0xffff < uVar6) {
    uVar12 = uVar6 >> 0x10;
    iVar8 = iVar8 + -0x10;
  }
  if (0xff < uVar12) {
    uVar12 = uVar12 >> 8;
    iVar8 = iVar8 + -8;
  }
  if (0xf < uVar12) {
    uVar12 = uVar12 >> 4;
    iVar8 = iVar8 + -4;
  }
  if (uVar12 < 4) {
    iVar8 = iVar8 - (uVar12 >> 1);
  }
  else {
    iVar8 = iVar8 + -2;
  }
  uVar9 = iVar8 - (uVar12 >> 3);
  bVar15 = SBORROW4(uVar9,0x20);
  uVar12 = uVar9 - 0x20;
  bVar14 = uVar12 == 0;
  uVar7 = uVar12;
  if ((int)uVar9 < 0x20) {
    bVar15 = SCARRY4(uVar12,0xc);
    uVar7 = uVar9 - 0x14;
    bVar14 = uVar7 == 0;
    if (!bVar14 && -0xd < (int)uVar12) {
      uVar10 = uVar6 << (uVar9 & 0xff);
      uVar6 = uVar6 >> (0xc - uVar7 & 0xff);
      goto LAB_009a6030;
    }
    uVar12 = uVar9;
  }
  if (bVar14 || (int)uVar7 < 0 != bVar15) {
    uVar13 = 0x20 - uVar12;
  }
  uVar6 = uVar6 << (uVar12 & 0xff);
  if (bVar14 || (int)uVar7 < 0 != bVar15) {
    uVar6 = uVar6 | uVar10 >> (uVar13 & 0xff);
    uVar10 = uVar10 << (uVar12 & 0xff);
  }
LAB_009a6030:
  if ((int)uVar9 <= (int)uVar11) {
    return CONCAT44(uVar6 + (uVar11 - uVar9) * 0x100000 | param_2,uVar10);
  }
  uVar12 = ~(uVar11 - uVar9);
  if (0x1e < (int)uVar12) {
    return CONCAT44(uVar5,uVar6 >> (uVar12 - 0x1f & 0xff)) & 0x80000000ffffffff;
  }
  if (uVar12 - 0x13 == 0 || (int)(uVar12 - 0x1f) < -0xc) {
    uVar12 = uVar12 + 1;
    return CONCAT44(param_2 | uVar6 >> (uVar12 & 0xff),
                    uVar10 >> (uVar12 & 0xff) | uVar6 << (0x20 - uVar12 & 0xff));
  }
  uVar12 = 0xc - (uVar12 - 0x13);
  return CONCAT44(uVar5,uVar10 >> (0x20 - uVar12 & 0xff) | uVar6 << (uVar12 & 0xff)) &
         0x80000000ffffffff;
}


// ===== FUN_009a5e5c @ 009a5e5c

ulonglong FUN_009a5e5c(uint param_1,uint param_2,uint param_3,uint param_4)

{
  int iVar1;
  byte bVar2;
  byte bVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  bool bVar14;
  bool bVar15;
  
  uVar9 = param_2 << 1;
  iVar7 = (int)uVar9 >> 0x15;
  iVar1 = (int)(param_4 << 1) >> 0x15;
  if ((((((param_2 ^ param_4) & 0x7fffffff) == 0 && param_1 == param_3 || uVar9 == 0 && param_1 == 0
        ) || param_4 << 1 == 0 && param_3 == 0) || iVar7 == -1) || iVar1 == -1) {
    if (iVar7 == -1 || iVar1 == -1) {
      uVar9 = param_3;
      uVar5 = param_4;
      if (iVar7 == -1) {
        uVar9 = param_1;
        uVar5 = param_2;
      }
      if (iVar7 != -1 || iVar1 != -1) {
        param_3 = uVar9;
        param_4 = uVar5;
      }
      bVar14 = (uVar5 & 0xfffff) == 0;
      bVar15 = uVar9 == 0 && bVar14;
      if (uVar9 == 0 && bVar14) {
        bVar15 = param_3 == 0 && (param_4 & 0xfffff) == 0;
      }
      if (!bVar15 || uVar5 != param_4) {
        uVar5 = uVar5 | 0x80000;
      }
      return CONCAT44(uVar5,uVar9);
    }
    if (((param_2 ^ param_4) & 0x7fffffff) != 0 || param_1 != param_3) {
      if (uVar9 == 0 && param_1 == 0) {
        param_1 = param_3;
        param_2 = param_4;
      }
      return CONCAT44(param_2,param_1);
    }
    if (param_2 != param_4) {
      return 0;
    }
    if ((param_2 & 0x7fffffff) >> 0x14 == 0) {
      bVar2 = (byte)(param_1 >> 0x1f);
      uVar9 = param_2 * 2 + (uint)bVar2;
      if (CARRY4(param_2,param_2) || CARRY4(param_2 * 2,(uint)bVar2)) {
        uVar9 = uVar9 | 0x80000000;
      }
      return CONCAT44(uVar9,param_1 << 1);
    }
    if (uVar9 < 0xffc00000) {
      return CONCAT44(param_2 + 0x100000,param_1);
    }
    param_2 = param_2 & 0x80000000;
LAB_009a6128:
    return (ulonglong)(param_2 | 0x7ff00000) << 0x20;
  }
  uVar9 = (param_2 & 0x7fffffff) >> 0x14;
  uVar5 = (param_4 & 0x7fffffff) >> 0x14;
  uVar11 = uVar5 - uVar9;
  bVar14 = uVar11 != 0;
  if (uVar5 < uVar9) {
    uVar11 = -uVar11;
  }
  uVar10 = param_1;
  uVar6 = param_2;
  if (bVar14 && uVar9 <= uVar5) {
    uVar9 = uVar9 + uVar11;
    uVar10 = param_3;
    uVar6 = param_4;
    param_3 = param_1;
    param_4 = param_2;
  }
  if (0x36 < uVar11) {
    return CONCAT44(uVar6,uVar10);
  }
  uVar5 = uVar6 & 0xfffff | 0x100000;
  if ((uVar6 & 0x80000000) != 0) {
    bVar14 = uVar10 != 0;
    uVar10 = -uVar10;
    uVar5 = -(uVar5 + bVar14);
  }
  uVar6 = param_4 & 0xfffff | 0x100000;
  if ((param_4 & 0x80000000) != 0) {
    bVar14 = param_3 != 0;
    param_3 = -param_3;
    uVar6 = -(uVar6 + bVar14);
  }
  if (uVar9 == uVar11) {
    uVar6 = uVar6 ^ 0x100000;
    if (uVar9 == 0) {
      uVar5 = uVar5 ^ 0x100000;
      uVar9 = 1;
    }
    else {
      uVar11 = uVar11 - 1;
    }
  }
  uVar13 = -uVar11 + 0x20;
  if ((int)uVar11 < 0x21) {
    uVar12 = param_3 << (uVar13 & 0xff);
    param_3 = param_3 >> (uVar11 & 0xff);
    uVar4 = uVar10 + param_3;
    uVar8 = uVar6 << (uVar13 & 0xff);
    uVar13 = uVar4 + uVar8;
    uVar5 = uVar5 + CARRY4(uVar10,param_3) + ((int)uVar6 >> (uVar11 & 0xff)) +
            (uint)CARRY4(uVar4,uVar8);
  }
  else {
    uVar12 = uVar6 << (-uVar11 + 0x40 & 0xff);
    if (param_3 != 0) {
      uVar12 = uVar12 | 2;
    }
    uVar11 = (int)uVar6 >> (uVar11 - 0x20 & 0xff);
    uVar13 = uVar10 + uVar11;
    uVar5 = uVar5 + ((int)uVar6 >> 0x1f) + (uint)CARRY4(uVar10,uVar11);
  }
  param_2 = uVar5 & 0x80000000;
  uVar11 = uVar5;
  if ((int)uVar5 < 0) {
    bVar14 = uVar12 == 0;
    uVar12 = -uVar12;
    uVar11 = -uVar13;
    uVar13 = -(uVar13 + !bVar14);
    uVar11 = -(uVar5 + (bVar14 <= uVar11));
  }
  if (0xfffff < uVar11) {
    uVar10 = uVar9 - 1;
    if (0x1fffff < uVar11) {
      bVar2 = (byte)uVar11;
      uVar11 = uVar11 >> 1;
      bVar3 = (byte)uVar13;
      uVar13 = (uint)(bVar2 & 1) << 0x1f | uVar13 >> 1;
      uVar12 = (uint)(bVar3 & 1) << 0x1f | uVar12 >> 1;
      uVar10 = uVar9;
      if (0xffbfffff < uVar9 << 0x15) goto LAB_009a6128;
    }
LAB_009a5f78:
    bVar14 = 0x7fffffff < uVar12;
    if (uVar12 == 0x80000000) {
      bVar14 = (bool)((byte)uVar13 & 1);
    }
    return CONCAT44(uVar11 + uVar10 * 0x100000 + (uint)CARRY4(uVar13,(uint)bVar14) | param_2,
                    uVar13 + bVar14);
  }
  bVar2 = (byte)(uVar12 >> 0x1f);
  uVar12 = uVar12 << 1;
  uVar10 = uVar13 * 2;
  bVar14 = CARRY4(uVar13,uVar13);
  uVar13 = uVar13 * 2 + (uint)bVar2;
  uVar11 = uVar11 * 2 + (uint)(bVar14 || CARRY4(uVar10,(uint)bVar2));
  uVar10 = uVar9 - 2;
  if (uVar9 - 1 != 0 && 0xfffff < uVar11) goto LAB_009a5f78;
  if (uVar11 == 0) {
    iVar7 = 0x34;
    uVar9 = 0;
  }
  else {
    iVar7 = 0x14;
    uVar9 = uVar13;
    uVar13 = uVar11;
  }
  uVar11 = uVar13;
  if (0xffff < uVar13) {
    uVar11 = uVar13 >> 0x10;
    iVar7 = iVar7 + -0x10;
  }
  if (0xff < uVar11) {
    uVar11 = uVar11 >> 8;
    iVar7 = iVar7 + -8;
  }
  if (0xf < uVar11) {
    uVar11 = uVar11 >> 4;
    iVar7 = iVar7 + -4;
  }
  if (uVar11 < 4) {
    iVar7 = iVar7 - (uVar11 >> 1);
  }
  else {
    iVar7 = iVar7 + -2;
  }
  uVar8 = iVar7 - (uVar11 >> 3);
  bVar15 = SBORROW4(uVar8,0x20);
  uVar11 = uVar8 - 0x20;
  bVar14 = uVar11 == 0;
  uVar6 = uVar11;
  if ((int)uVar8 < 0x20) {
    bVar15 = SCARRY4(uVar11,0xc);
    uVar6 = uVar8 - 0x14;
    bVar14 = uVar6 == 0;
    if (!bVar14 && -0xd < (int)uVar11) {
      uVar9 = uVar13 << (uVar8 & 0xff);
      uVar13 = uVar13 >> (0xc - uVar6 & 0xff);
      goto LAB_009a6030;
    }
    uVar11 = uVar8;
  }
  if (bVar14 || (int)uVar6 < 0 != bVar15) {
    uVar12 = 0x20 - uVar11;
  }
  uVar13 = uVar13 << (uVar11 & 0xff);
  if (bVar14 || (int)uVar6 < 0 != bVar15) {
    uVar13 = uVar13 | uVar9 >> (uVar12 & 0xff);
    uVar9 = uVar9 << (uVar11 & 0xff);
  }
LAB_009a6030:
  if ((int)uVar8 <= (int)uVar10) {
    return CONCAT44(uVar13 + (uVar10 - uVar8) * 0x100000 | param_2,uVar9);
  }
  uVar11 = ~(uVar10 - uVar8);
  if (0x1e < (int)uVar11) {
    return CONCAT44(uVar5,uVar13 >> (uVar11 - 0x1f & 0xff)) & 0x80000000ffffffff;
  }
  if (uVar11 - 0x13 == 0 || (int)(uVar11 - 0x1f) < -0xc) {
    uVar11 = uVar11 + 1;
    return CONCAT44(param_2 | uVar13 >> (uVar11 & 0xff),
                    uVar9 >> (uVar11 & 0xff) | uVar13 << (0x20 - uVar11 & 0xff));
  }
  uVar11 = 0xc - (uVar11 - 0x13);
  return CONCAT44(uVar5,uVar9 >> (0x20 - uVar11 & 0xff) | uVar13 << (uVar11 & 0xff)) &
         0x80000000ffffffff;
}


// ===== FUN_009a616c @ 009a616c

/* WARNING: Removing unreachable block (ram,0x009a5fb0) */

ulonglong FUN_009a616c(uint param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint in_r12;
  bool bVar6;
  bool bVar7;
  
  if (param_1 == 0) {
    return 0;
  }
  iVar4 = 0x34;
  uVar1 = 0;
  uVar2 = param_1;
  if (0xffff < param_1) {
    uVar2 = param_1 >> 0x10;
    iVar4 = 0x24;
  }
  if (0xff < uVar2) {
    uVar2 = uVar2 >> 8;
    iVar4 = iVar4 + -8;
  }
  if (0xf < uVar2) {
    uVar2 = uVar2 >> 4;
    iVar4 = iVar4 + -4;
  }
  if (uVar2 < 4) {
    iVar4 = iVar4 - (uVar2 >> 1);
  }
  else {
    iVar4 = iVar4 + -2;
  }
  uVar5 = iVar4 - (uVar2 >> 3);
  bVar7 = SBORROW4(uVar5,0x20);
  uVar2 = uVar5 - 0x20;
  bVar6 = uVar2 == 0;
  uVar3 = uVar2;
  if ((int)uVar5 < 0x20) {
    bVar7 = SCARRY4(uVar2,0xc);
    uVar3 = uVar5 - 0x14;
    bVar6 = uVar3 == 0;
    if (!bVar6 && -0xd < (int)uVar2) {
      uVar1 = param_1 << (uVar5 & 0xff);
      param_1 = param_1 >> (0xc - uVar3 & 0xff);
      goto LAB_009a6030;
    }
    uVar2 = uVar5;
  }
  if (bVar6 || (int)uVar3 < 0 != bVar7) {
    in_r12 = 0x20 - uVar2;
  }
  param_1 = param_1 << (uVar2 & 0xff);
  if (bVar6 || (int)uVar3 < 0 != bVar7) {
    param_1 = param_1 | 0U >> (in_r12 & 0xff);
    uVar1 = 0 << (uVar2 & 0xff);
  }
LAB_009a6030:
  if ((int)uVar5 < 0x433) {
    return CONCAT44(param_1 + (0x432 - uVar5) * 0x100000,uVar1);
  }
  uVar2 = ~(0x432 - uVar5);
  if (0x1e < (int)uVar2) {
    return (ulonglong)(param_1 >> (uVar2 - 0x1f & 0xff));
  }
  if (uVar2 - 0x13 == 0 || (int)(uVar2 - 0x1f) < -0xc) {
    uVar2 = uVar2 + 1;
    return CONCAT44(param_1 >> (uVar2 & 0xff),
                    uVar1 >> (uVar2 & 0xff) | param_1 << (0x20 - uVar2 & 0xff));
  }
  uVar2 = 0xc - (uVar2 - 0x13);
  return (ulonglong)(uVar1 >> (0x20 - uVar2 & 0xff) | param_1 << (uVar2 & 0xff));
}


// ===== FUN_009a6178 @ 009a6178

/* WARNING: Removing unreachable block (ram,0x009a5fb0) */

ulonglong FUN_009a6178(uint param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint in_r12;
  bool bVar6;
  bool bVar7;
  
  iVar4 = 0x34;
  uVar1 = 0;
  uVar2 = param_1;
  if (0xffff < param_1) {
    uVar2 = param_1 >> 0x10;
    iVar4 = 0x24;
  }
  if (0xff < uVar2) {
    uVar2 = uVar2 >> 8;
    iVar4 = iVar4 + -8;
  }
  if (0xf < uVar2) {
    uVar2 = uVar2 >> 4;
    iVar4 = iVar4 + -4;
  }
  if (uVar2 < 4) {
    iVar4 = iVar4 - (uVar2 >> 1);
  }
  else {
    iVar4 = iVar4 + -2;
  }
  uVar5 = iVar4 - (uVar2 >> 3);
  bVar7 = SBORROW4(uVar5,0x20);
  uVar2 = uVar5 - 0x20;
  bVar6 = uVar2 == 0;
  uVar3 = uVar2;
  if ((int)uVar5 < 0x20) {
    bVar7 = SCARRY4(uVar2,0xc);
    uVar3 = uVar5 - 0x14;
    bVar6 = uVar3 == 0;
    if (!bVar6 && -0xd < (int)uVar2) {
      uVar1 = param_1 << (uVar5 & 0xff);
      param_1 = param_1 >> (0xc - uVar3 & 0xff);
      goto LAB_009a6030;
    }
    uVar2 = uVar5;
  }
  if (bVar6 || (int)uVar3 < 0 != bVar7) {
    in_r12 = 0x20 - uVar2;
  }
  param_1 = param_1 << (uVar2 & 0xff);
  if (bVar6 || (int)uVar3 < 0 != bVar7) {
    param_1 = param_1 | 0U >> (in_r12 & 0xff);
    uVar1 = 0 << (uVar2 & 0xff);
  }
LAB_009a6030:
  if ((int)uVar5 < 0x433) {
    return CONCAT44(param_1 + (0x432 - uVar5) * 0x100000,uVar1);
  }
  uVar2 = ~(0x432 - uVar5);
  if (0x1e < (int)uVar2) {
    return (ulonglong)(param_1 >> (uVar2 - 0x1f & 0xff));
  }
  if (uVar2 - 0x13 == 0 || (int)(uVar2 - 0x1f) < -0xc) {
    uVar2 = uVar2 + 1;
    return CONCAT44(param_1 >> (uVar2 & 0xff),
                    uVar1 >> (uVar2 & 0xff) | param_1 << (0x20 - uVar2 & 0xff));
  }
  uVar2 = 0xc - (uVar2 - 0x13);
  return (ulonglong)(uVar1 >> (0x20 - uVar2 & 0xff) | param_1 << (uVar2 & 0xff));
}


// ===== FUN_009a6190 @ 009a6190

/* WARNING: Removing unreachable block (ram,0x009a5fb0) */

ulonglong FUN_009a6190(uint param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint in_r12;
  bool bVar8;
  bool bVar9;
  
  if (param_1 == 0) {
    return 0;
  }
  uVar7 = param_1 & 0x80000000;
  uVar2 = param_1;
  if ((int)uVar7 < 0) {
    uVar2 = -param_1;
  }
  iVar5 = 0x34;
  uVar1 = 0;
  uVar3 = uVar2;
  if (0xffff < uVar2) {
    uVar3 = uVar2 >> 0x10;
    iVar5 = 0x24;
  }
  if (0xff < uVar3) {
    uVar3 = uVar3 >> 8;
    iVar5 = iVar5 + -8;
  }
  if (0xf < uVar3) {
    uVar3 = uVar3 >> 4;
    iVar5 = iVar5 + -4;
  }
  if (uVar3 < 4) {
    iVar5 = iVar5 - (uVar3 >> 1);
  }
  else {
    iVar5 = iVar5 + -2;
  }
  uVar6 = iVar5 - (uVar3 >> 3);
  bVar9 = SBORROW4(uVar6,0x20);
  uVar3 = uVar6 - 0x20;
  bVar8 = uVar3 == 0;
  uVar4 = uVar3;
  if ((int)uVar6 < 0x20) {
    bVar9 = SCARRY4(uVar3,0xc);
    uVar4 = uVar6 - 0x14;
    bVar8 = uVar4 == 0;
    if (!bVar8 && -0xd < (int)uVar3) {
      uVar1 = uVar2 << (uVar6 & 0xff);
      uVar2 = uVar2 >> (0xc - uVar4 & 0xff);
      goto LAB_009a6030;
    }
    uVar3 = uVar6;
  }
  if (bVar8 || (int)uVar4 < 0 != bVar9) {
    in_r12 = 0x20 - uVar3;
  }
  uVar2 = uVar2 << (uVar3 & 0xff);
  if (bVar8 || (int)uVar4 < 0 != bVar9) {
    uVar2 = uVar2 | 0U >> (in_r12 & 0xff);
    uVar1 = 0 << (uVar3 & 0xff);
  }
LAB_009a6030:
  if ((int)uVar6 < 0x433) {
    return CONCAT44(uVar2 + (0x432 - uVar6) * 0x100000 | uVar7,uVar1);
  }
  uVar3 = ~(0x432 - uVar6);
  if (0x1e < (int)uVar3) {
    return CONCAT44(param_1,uVar2 >> (uVar3 - 0x1f & 0xff)) & 0x80000000ffffffff;
  }
  if (uVar3 - 0x13 == 0 || (int)(uVar3 - 0x1f) < -0xc) {
    uVar3 = uVar3 + 1;
    return CONCAT44(uVar7 | uVar2 >> (uVar3 & 0xff),
                    uVar1 >> (uVar3 & 0xff) | uVar2 << (0x20 - uVar3 & 0xff));
  }
  uVar7 = 0xc - (uVar3 - 0x13);
  return CONCAT44(param_1,uVar1 >> (0x20 - uVar7 & 0xff) | uVar2 << (uVar7 & 0xff)) &
         0x80000000ffffffff;
}


// ===== FUN_009a619c @ 009a619c

/* WARNING: Removing unreachable block (ram,0x009a5fb0) */

ulonglong FUN_009a619c(uint param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint in_r12;
  bool bVar8;
  bool bVar9;
  
  uVar7 = param_1 & 0x80000000;
  uVar2 = param_1;
  if ((int)uVar7 < 0) {
    uVar2 = -param_1;
  }
  iVar5 = 0x34;
  uVar1 = 0;
  uVar3 = uVar2;
  if (0xffff < uVar2) {
    uVar3 = uVar2 >> 0x10;
    iVar5 = 0x24;
  }
  if (0xff < uVar3) {
    uVar3 = uVar3 >> 8;
    iVar5 = iVar5 + -8;
  }
  if (0xf < uVar3) {
    uVar3 = uVar3 >> 4;
    iVar5 = iVar5 + -4;
  }
  if (uVar3 < 4) {
    iVar5 = iVar5 - (uVar3 >> 1);
  }
  else {
    iVar5 = iVar5 + -2;
  }
  uVar6 = iVar5 - (uVar3 >> 3);
  bVar9 = SBORROW4(uVar6,0x20);
  uVar3 = uVar6 - 0x20;
  bVar8 = uVar3 == 0;
  uVar4 = uVar3;
  if ((int)uVar6 < 0x20) {
    bVar9 = SCARRY4(uVar3,0xc);
    uVar4 = uVar6 - 0x14;
    bVar8 = uVar4 == 0;
    if (!bVar8 && -0xd < (int)uVar3) {
      uVar1 = uVar2 << (uVar6 & 0xff);
      uVar2 = uVar2 >> (0xc - uVar4 & 0xff);
      goto LAB_009a6030;
    }
    uVar3 = uVar6;
  }
  if (bVar8 || (int)uVar4 < 0 != bVar9) {
    in_r12 = 0x20 - uVar3;
  }
  uVar2 = uVar2 << (uVar3 & 0xff);
  if (bVar8 || (int)uVar4 < 0 != bVar9) {
    uVar2 = uVar2 | 0U >> (in_r12 & 0xff);
    uVar1 = 0 << (uVar3 & 0xff);
  }
LAB_009a6030:
  if ((int)uVar6 < 0x433) {
    return CONCAT44(uVar2 + (0x432 - uVar6) * 0x100000 | uVar7,uVar1);
  }
  uVar3 = ~(0x432 - uVar6);
  if (0x1e < (int)uVar3) {
    return CONCAT44(param_1,uVar2 >> (uVar3 - 0x1f & 0xff)) & 0x80000000ffffffff;
  }
  if (uVar3 - 0x13 == 0 || (int)(uVar3 - 0x1f) < -0xc) {
    uVar3 = uVar3 + 1;
    return CONCAT44(uVar7 | uVar2 >> (uVar3 & 0xff),
                    uVar1 >> (uVar3 & 0xff) | uVar2 << (0x20 - uVar3 & 0xff));
  }
  uVar7 = 0xc - (uVar3 - 0x13);
  return CONCAT44(param_1,uVar1 >> (0x20 - uVar7 & 0xff) | uVar2 << (uVar7 & 0xff)) &
         0x80000000ffffffff;
}


// ===== FUN_009a61ec @ 009a61ec

ulonglong FUN_009a61ec(uint param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint in_r12;
  bool bVar6;
  bool bVar7;
  
  if ((param_2 & 0x7fffffff) == 0) {
    iVar4 = 0x34;
    uVar1 = 0;
  }
  else {
    iVar4 = 0x14;
    uVar1 = param_1;
    param_1 = param_2 & 0x7fffffff;
  }
  uVar2 = param_1;
  if (0xffff < param_1) {
    uVar2 = param_1 >> 0x10;
    iVar4 = iVar4 + -0x10;
  }
  if (0xff < uVar2) {
    uVar2 = uVar2 >> 8;
    iVar4 = iVar4 + -8;
  }
  if (0xf < uVar2) {
    uVar2 = uVar2 >> 4;
    iVar4 = iVar4 + -4;
  }
  if (uVar2 < 4) {
    iVar4 = iVar4 - (uVar2 >> 1);
  }
  else {
    iVar4 = iVar4 + -2;
  }
  uVar5 = iVar4 - (uVar2 >> 3);
  bVar7 = SBORROW4(uVar5,0x20);
  uVar2 = uVar5 - 0x20;
  bVar6 = uVar2 == 0;
  uVar3 = uVar2;
  if ((int)uVar5 < 0x20) {
    bVar7 = SCARRY4(uVar2,0xc);
    uVar3 = uVar5 - 0x14;
    bVar6 = uVar3 == 0;
    if (!bVar6 && -0xd < (int)uVar2) {
      uVar1 = param_1 << (uVar5 & 0xff);
      param_1 = param_1 >> (0xc - uVar3 & 0xff);
      goto LAB_009a6030;
    }
    uVar2 = uVar5;
  }
  if (bVar6 || (int)uVar3 < 0 != bVar7) {
    in_r12 = 0x20 - uVar2;
  }
  param_1 = param_1 << (uVar2 & 0xff);
  if (bVar6 || (int)uVar3 < 0 != bVar7) {
    param_1 = param_1 | uVar1 >> (in_r12 & 0xff);
    uVar1 = uVar1 << (uVar2 & 0xff);
  }
LAB_009a6030:
  if ((int)uVar5 < 0x381) {
    return CONCAT44(param_1 + (0x380 - uVar5) * 0x100000 | param_2 & 0x80000000,uVar1);
  }
  uVar2 = ~(0x380 - uVar5);
  if (0x1e < (int)uVar2) {
    return CONCAT44(param_2,param_1 >> (uVar2 - 0x1f & 0xff)) & 0x80000000ffffffff;
  }
  if (uVar2 - 0x13 == 0 || (int)(uVar2 - 0x1f) < -0xc) {
    uVar2 = uVar2 + 1;
    return CONCAT44(param_2 & 0x80000000 | param_1 >> (uVar2 & 0xff),
                    uVar1 >> (uVar2 & 0xff) | param_1 << (0x20 - uVar2 & 0xff));
  }
  uVar2 = 0xc - (uVar2 - 0x13);
  return CONCAT44(param_2,uVar1 >> (0x20 - uVar2 & 0xff) | param_1 << (uVar2 & 0xff)) &
         0x80000000ffffffff;
}


// ===== FUN_009a6208 @ 009a6208

ulonglong FUN_009a6208(uint param_1,uint param_2)

{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  bool bVar10;
  bool bVar11;
  
  iVar9 = 0x432;
  uVar8 = 0;
  if (param_2 >> 0x16 != 0) {
    iVar9 = 3;
    if (param_2 >> 0x19 != 0) {
      iVar9 = 6;
    }
    if (param_2 >> 0x1c != 0) {
      iVar9 = iVar9 + 3;
    }
    iVar9 = iVar9 - ((int)param_2 >> 0x1f);
    uVar8 = param_1 << (0x20U - iVar9 & 0xff);
    param_1 = param_1 >> iVar9 | param_2 << (0x20U - iVar9 & 0xff);
    param_2 = param_2 >> iVar9;
    iVar9 = iVar9 + 0x432;
  }
  if (0xfffff < param_2) {
    if (0x1fffff < param_2) {
      bVar1 = (byte)param_2;
      param_2 = param_2 >> 1;
      bVar2 = (byte)param_1;
      param_1 = (uint)(bVar1 & 1) << 0x1f | param_1 >> 1;
      uVar8 = (uint)(bVar2 & 1) << 0x1f | uVar8 >> 1;
      iVar9 = iVar9 + 1;
      if (0xffbfffff < (uint)(iVar9 * 0x200000)) {
        return 0x7ff0000000000000;
      }
    }
LAB_009a5f78:
    bVar10 = 0x7fffffff < uVar8;
    if (uVar8 == 0x80000000) {
      bVar10 = (bool)((byte)param_1 & 1);
    }
    return CONCAT44(param_2 + iVar9 * 0x100000 + (uint)CARRY4(param_1,(uint)bVar10),param_1 + bVar10
                   );
  }
  bVar1 = (byte)(uVar8 >> 0x1f);
  uVar8 = uVar8 << 1;
  uVar3 = param_1 * 2;
  bVar10 = CARRY4(param_1,param_1);
  param_1 = param_1 * 2 + (uint)bVar1;
  param_2 = param_2 * 2 + (uint)(bVar10 || CARRY4(uVar3,(uint)bVar1));
  bVar10 = iVar9 != 0;
  iVar9 = iVar9 + -1;
  if (bVar10 && 0xfffff < param_2) goto LAB_009a5f78;
  if (param_2 == 0) {
    iVar6 = 0x34;
    uVar3 = 0;
  }
  else {
    iVar6 = 0x14;
    uVar3 = param_1;
    param_1 = param_2;
  }
  uVar4 = param_1;
  if (0xffff < param_1) {
    uVar4 = param_1 >> 0x10;
    iVar6 = iVar6 + -0x10;
  }
  if (0xff < uVar4) {
    uVar4 = uVar4 >> 8;
    iVar6 = iVar6 + -8;
  }
  if (0xf < uVar4) {
    uVar4 = uVar4 >> 4;
    iVar6 = iVar6 + -4;
  }
  if (uVar4 < 4) {
    iVar6 = iVar6 - (uVar4 >> 1);
  }
  else {
    iVar6 = iVar6 + -2;
  }
  uVar7 = iVar6 - (uVar4 >> 3);
  bVar11 = SBORROW4(uVar7,0x20);
  uVar4 = uVar7 - 0x20;
  bVar10 = uVar4 == 0;
  uVar5 = uVar4;
  if ((int)uVar7 < 0x20) {
    bVar11 = SCARRY4(uVar4,0xc);
    uVar5 = uVar7 - 0x14;
    bVar10 = uVar5 == 0;
    if (!bVar10 && -0xd < (int)uVar4) {
      uVar3 = param_1 << (uVar7 & 0xff);
      param_1 = param_1 >> (0xc - uVar5 & 0xff);
      goto LAB_009a6030;
    }
    uVar4 = uVar7;
  }
  if (bVar10 || (int)uVar5 < 0 != bVar11) {
    uVar8 = 0x20 - uVar4;
  }
  param_1 = param_1 << (uVar4 & 0xff);
  if (bVar10 || (int)uVar5 < 0 != bVar11) {
    param_1 = param_1 | uVar3 >> (uVar8 & 0xff);
    uVar3 = uVar3 << (uVar4 & 0xff);
  }
LAB_009a6030:
  if ((int)uVar7 <= iVar9) {
    return CONCAT44(param_1 + (iVar9 - uVar7) * 0x100000,uVar3);
  }
  uVar8 = ~(iVar9 - uVar7);
  if (0x1e < (int)uVar8) {
    return (ulonglong)(param_1 >> (uVar8 - 0x1f & 0xff));
  }
  if (uVar8 - 0x13 == 0 || (int)(uVar8 - 0x1f) < -0xc) {
    uVar8 = uVar8 + 1;
    return CONCAT44(param_1 >> (uVar8 & 0xff),
                    uVar3 >> (uVar8 & 0xff) | param_1 << (0x20 - uVar8 & 0xff));
  }
  uVar8 = 0xc - (uVar8 - 0x13);
  return (ulonglong)(uVar3 >> (0x20 - uVar8 & 0xff) | param_1 << (uVar8 & 0xff));
}


// ===== FUN_009a621c @ 009a621c

ulonglong FUN_009a621c(uint param_1,uint param_2)

{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  bool bVar11;
  bool bVar12;
  
  uVar9 = param_2 & 0x80000000;
  uVar4 = param_2;
  if ((int)uVar9 < 0) {
    bVar11 = param_1 != 0;
    param_1 = -param_1;
    uVar4 = -(param_2 + bVar11);
  }
  iVar8 = 0x432;
  uVar10 = 0;
  if (uVar4 >> 0x16 != 0) {
    iVar8 = 3;
    if (uVar4 >> 0x19 != 0) {
      iVar8 = 6;
    }
    if (uVar4 >> 0x1c != 0) {
      iVar8 = iVar8 + 3;
    }
    iVar8 = iVar8 - ((int)uVar4 >> 0x1f);
    uVar10 = param_1 << (0x20U - iVar8 & 0xff);
    param_1 = param_1 >> iVar8 | uVar4 << (0x20U - iVar8 & 0xff);
    uVar4 = uVar4 >> iVar8;
    iVar8 = iVar8 + 0x432;
  }
  if (0xfffff < uVar4) {
    if (0x1fffff < uVar4) {
      bVar1 = (byte)uVar4;
      uVar4 = uVar4 >> 1;
      bVar2 = (byte)param_1;
      param_1 = (uint)(bVar1 & 1) << 0x1f | param_1 >> 1;
      uVar10 = (uint)(bVar2 & 1) << 0x1f | uVar10 >> 1;
      iVar8 = iVar8 + 1;
      if (0xffbfffff < (uint)(iVar8 * 0x200000)) {
        return (ulonglong)(uVar9 | 0x7ff00000) << 0x20;
      }
    }
LAB_009a5f78:
    bVar11 = 0x7fffffff < uVar10;
    if (uVar10 == 0x80000000) {
      bVar11 = (bool)((byte)param_1 & 1);
    }
    return CONCAT44(uVar4 + iVar8 * 0x100000 + (uint)CARRY4(param_1,(uint)bVar11) | uVar9,
                    param_1 + bVar11);
  }
  bVar1 = (byte)(uVar10 >> 0x1f);
  uVar10 = uVar10 << 1;
  uVar3 = param_1 * 2;
  bVar11 = CARRY4(param_1,param_1);
  param_1 = param_1 * 2 + (uint)bVar1;
  uVar4 = uVar4 * 2 + (uint)(bVar11 || CARRY4(uVar3,(uint)bVar1));
  bVar11 = iVar8 != 0;
  iVar8 = iVar8 + -1;
  if (bVar11 && 0xfffff < uVar4) goto LAB_009a5f78;
  if (uVar4 == 0) {
    iVar6 = 0x34;
    uVar3 = 0;
  }
  else {
    iVar6 = 0x14;
    uVar3 = param_1;
    param_1 = uVar4;
  }
  uVar4 = param_1;
  if (0xffff < param_1) {
    uVar4 = param_1 >> 0x10;
    iVar6 = iVar6 + -0x10;
  }
  if (0xff < uVar4) {
    uVar4 = uVar4 >> 8;
    iVar6 = iVar6 + -8;
  }
  if (0xf < uVar4) {
    uVar4 = uVar4 >> 4;
    iVar6 = iVar6 + -4;
  }
  if (uVar4 < 4) {
    iVar6 = iVar6 - (uVar4 >> 1);
  }
  else {
    iVar6 = iVar6 + -2;
  }
  uVar7 = iVar6 - (uVar4 >> 3);
  bVar12 = SBORROW4(uVar7,0x20);
  uVar4 = uVar7 - 0x20;
  bVar11 = uVar4 == 0;
  uVar5 = uVar4;
  if ((int)uVar7 < 0x20) {
    bVar12 = SCARRY4(uVar4,0xc);
    uVar5 = uVar7 - 0x14;
    bVar11 = uVar5 == 0;
    if (!bVar11 && -0xd < (int)uVar4) {
      uVar3 = param_1 << (uVar7 & 0xff);
      param_1 = param_1 >> (0xc - uVar5 & 0xff);
      goto LAB_009a6030;
    }
    uVar4 = uVar7;
  }
  if (bVar11 || (int)uVar5 < 0 != bVar12) {
    uVar10 = 0x20 - uVar4;
  }
  param_1 = param_1 << (uVar4 & 0xff);
  if (bVar11 || (int)uVar5 < 0 != bVar12) {
    param_1 = param_1 | uVar3 >> (uVar10 & 0xff);
    uVar3 = uVar3 << (uVar4 & 0xff);
  }
LAB_009a6030:
  if ((int)uVar7 <= iVar8) {
    return CONCAT44(param_1 + (iVar8 - uVar7) * 0x100000 | uVar9,uVar3);
  }
  uVar4 = ~(iVar8 - uVar7);
  if (0x1e < (int)uVar4) {
    return CONCAT44(param_2,param_1 >> (uVar4 - 0x1f & 0xff)) & 0x80000000ffffffff;
  }
  if (uVar4 - 0x13 == 0 || (int)(uVar4 - 0x1f) < -0xc) {
    uVar4 = uVar4 + 1;
    return CONCAT44(uVar9 | param_1 >> (uVar4 & 0xff),
                    uVar3 >> (uVar4 & 0xff) | param_1 << (0x20 - uVar4 & 0xff));
  }
  uVar4 = 0xc - (uVar4 - 0x13);
  return CONCAT44(param_2,uVar3 >> (0x20 - uVar4 & 0xff) | param_1 << (uVar4 & 0xff)) &
         0x80000000ffffffff;
}


// ===== FUN_009a6274 @ 009a6274

ulonglong FUN_009a6274(undefined4 param_1,uint param_2,uint param_3,uint param_4)

{
  longlong lVar1;
  ulonglong uVar2;
  byte bVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint unaff_r5;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  bool bVar11;
  bool bVar12;
  bool bVar13;
  ulonglong uVar14;
  
  uVar14 = CONCAT44(param_2,param_1);
  uVar9 = 0x7ff;
  uVar5 = param_2 >> 0x14 & 0x7ff;
  bVar11 = uVar5 == 0;
  if (!bVar11) {
    unaff_r5 = param_4 >> 0x14 & 0x7ff;
    bVar11 = unaff_r5 == 0;
  }
  if (!bVar11) {
    bVar11 = uVar5 == 0x7ff;
  }
  if (!bVar11) {
    bVar11 = unaff_r5 == 0x7ff;
  }
  if (bVar11) {
    uVar14 = FUN_009a646c();
  }
  uVar4 = (uint)(uVar14 >> 0x20);
  uVar8 = (uint)uVar14;
  iVar6 = uVar5 + unaff_r5;
  uVar5 = uVar4 ^ param_4;
  uVar4 = uVar4 & ~(uVar9 << 0x15);
  param_4 = param_4 & ~(uVar9 << 0x15);
  bVar11 = (uVar4 & 0xfffff) == 0;
  bVar12 = uVar8 == 0 && bVar11;
  if (uVar8 != 0 || !bVar11) {
    bVar12 = param_3 == 0 && (param_4 & 0xfffff) == 0;
  }
  uVar4 = uVar4 | 0x100000;
  param_4 = param_4 | 0x100000;
  if (bVar12) {
    uVar8 = uVar8 | param_3;
    param_4 = (uVar5 & 0x80000000 | uVar4) ^ param_4;
    uVar5 = uVar9 >> 1;
    bVar12 = SBORROW4(iVar6,uVar5);
    uVar7 = iVar6 - uVar5;
    bVar11 = uVar7 == 0;
    uVar4 = uVar7;
    if (!bVar11 && (int)uVar5 <= iVar6) {
      bVar12 = SBORROW4(uVar9,uVar7);
      uVar4 = uVar9 - uVar7;
      bVar11 = uVar9 == uVar7;
    }
    if (!bVar11 && (int)uVar4 < 0 == bVar12) {
      return CONCAT44(param_4 | uVar7 * 0x100000,uVar8);
    }
    param_4 = param_4 | 0x100000;
    uVar5 = 0;
    bVar12 = SBORROW4(uVar7,1);
    uVar7 = uVar7 - 1;
    bVar11 = uVar7 == 0;
    uVar9 = uVar7;
  }
  else {
    uVar2 = (ulonglong)param_3 * (uVar14 & 0xffffffff);
    uVar14 = (ulonglong)param_4 * (uVar14 & 0xffffffff) +
             (ulonglong)param_3 * (ulonglong)uVar4 + (uVar2 >> 0x20);
    uVar10 = (uint)uVar14;
    lVar1 = (ulonglong)param_4 * (ulonglong)uVar4 + (uVar14 >> 0x20);
    uVar9 = (uint)lVar1;
    uVar8 = (uint)((ulonglong)lVar1 >> 0x20);
    if ((int)uVar2 != 0) {
      uVar10 = uVar10 | 1;
    }
    uVar7 = (iVar6 + -0xff) - ((uVar8 < 0x200) + 0x300);
    if (uVar8 < 0x200) {
      bVar3 = (byte)(uVar10 >> 0x1f);
      uVar10 = uVar10 << 1;
      lVar1 = CONCAT44(uVar8 * 2 + (uint)(CARRY4(uVar9,uVar9) || CARRY4(uVar9 * 2,(uint)bVar3)),
                       uVar9 * 2 + (uint)bVar3);
    }
    param_4 = uVar5 & 0x80000000 | (int)((ulonglong)lVar1 >> 0x20) << 0xb | (uint)lVar1 >> 0x15;
    uVar8 = (uint)lVar1 << 0xb | uVar10 >> 0x15;
    uVar5 = uVar10 * 0x800;
    bVar13 = 0xfc < uVar7;
    bVar12 = SBORROW4(uVar7,0xfd);
    uVar4 = uVar7 - 0xfd;
    bVar11 = uVar4 == 0;
    uVar9 = uVar4;
    if (bVar13 && !bVar11) {
      bVar13 = 0x6ff < uVar4;
      bVar12 = SBORROW4(uVar4,0x700);
      uVar9 = uVar7 - 0x7fd;
      bVar11 = uVar4 == 0x700;
    }
    if (!bVar13 || bVar11) {
      bVar11 = 0x7fffffff < uVar5;
      if (uVar5 == 0x80000000) {
        bVar11 = (bool)((byte)(uVar10 >> 0x15) & 1);
      }
      return CONCAT44(param_4 + uVar7 * 0x100000 + (uint)CARRY4(uVar8,(uint)bVar11),uVar8 + bVar11);
    }
  }
  if (!bVar11 && (int)uVar9 < 0 == bVar12) {
    return (ulonglong)(param_4 & 0x80000000 | 0x7ff00000) << 0x20;
  }
  if ((int)uVar7 < -0x35) {
    return (ulonglong)(param_4 & 0x80000000) << 0x20;
  }
  uVar9 = -uVar7;
  uVar4 = uVar9 - 0x20;
  if (0x1f < (int)uVar9) {
    uVar7 = uVar8 >> (uVar4 & 0xff) | param_4 << (0x20 - uVar4 & 0xff);
    uVar9 = (param_4 >> (uVar4 & 0xff) & ~((param_4 & 0x80000000) >> (uVar4 & 0xff))) -
            ((int)uVar7 >> 0x1f);
    if ((uVar5 == 0 && uVar8 << (0x20 - uVar4 & 0xff) == 0) && (uVar7 & 0x7fffffff) == 0) {
      uVar9 = uVar9 & ~(uVar7 >> 0x1f);
    }
    return CONCAT44(param_4,uVar9) & 0x80000000ffffffff;
  }
  if (uVar9 - 0x14 == 0 || (int)uVar4 < -0xc) {
    uVar4 = uVar8 << (uVar7 + 0x20 & 0xff);
    uVar8 = uVar8 >> (uVar9 & 0xff) | param_4 << (uVar7 + 0x20 & 0xff);
    uVar7 = uVar8 + -((int)uVar4 >> 0x1f);
    if (uVar5 == 0 && (uVar4 & 0x7fffffff) == 0) {
      uVar7 = uVar7 & ~(uVar4 >> 0x1f);
    }
    return CONCAT44((param_4 & 0x80000000) + ((param_4 & 0x7fffffff) >> (uVar9 & 0xff)) +
                    (uint)CARRY4(uVar8,-((int)uVar4 >> 0x1f)),uVar7);
  }
  uVar4 = 0xc - (uVar9 - 0x14);
  uVar9 = uVar8 << (uVar4 & 0xff);
  uVar8 = uVar8 >> (0x20 - uVar4 & 0xff) | param_4 << (uVar4 & 0xff);
  uVar4 = uVar8 + -((int)uVar9 >> 0x1f);
  if (uVar5 == 0 && (uVar9 & 0x7fffffff) == 0) {
    uVar4 = uVar4 & ~(uVar9 >> 0x1f);
  }
  return CONCAT44((param_4 & 0x80000000) + (uint)CARRY4(uVar8,-((int)uVar9 >> 0x1f)),uVar4);
}


// ===== FUN_009a646c @ 009a646c

ulonglong FUN_009a646c(int param_1,uint param_2,int param_3,uint param_4)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  uint unaff_r4;
  uint uVar4;
  uint uVar5;
  uint in_r12;
  bool bVar6;
  
  uVar4 = in_r12 & param_4 >> 0x14;
  if (unaff_r4 == in_r12 || uVar4 == in_r12) {
    bVar1 = (param_2 & 0x7fffffff) == 0;
    bVar6 = param_1 == 0 && bVar1;
    uVar5 = param_4;
    iVar2 = param_3;
    if (param_1 != 0 || !bVar1) {
      bVar6 = param_3 == 0 && (param_4 & 0x7fffffff) == 0;
      uVar5 = param_2;
      iVar2 = param_1;
    }
    uVar3 = uVar5;
    if (((bVar6) || ((unaff_r4 == in_r12 && (iVar2 != 0 || (uVar5 & 0xfffff) != 0)))) ||
       ((uVar4 == in_r12 &&
        (iVar2 = param_3, uVar3 = param_4, param_3 != 0 || (param_4 & 0xfffff) != 0)))) {
      return CONCAT44(uVar3,iVar2) | 0x7ff8000000000000;
    }
    return (ulonglong)((uVar5 ^ param_4) & 0x80000000 | 0x7ff00000) << 0x20;
  }
  bVar1 = (param_2 & 0x7fffffff) == 0;
  bVar6 = param_1 == 0 && bVar1;
  if (param_1 != 0 || !bVar1) {
    bVar6 = param_3 == 0 && (param_4 & 0x7fffffff) == 0;
  }
  if (bVar6) {
    return (ulonglong)((param_2 ^ param_4) & 0x80000000) << 0x20;
  }
  if (unaff_r4 == 0) {
    uVar5 = param_2 & 0x80000000;
    do {
      iVar2 = param_1 >> 0x1f;
      param_1 = param_1 << 1;
      param_2 = param_2 * 2 - iVar2;
    } while ((param_2 & 0x100000) == 0);
    param_2 = param_2 | uVar5;
    if (uVar4 != 0) {
      return CONCAT44(param_2,param_1);
    }
  }
  do {
    iVar2 = param_3 >> 0x1f;
    param_3 = param_3 << 1;
    param_4 = param_4 * 2 - iVar2;
  } while ((param_4 & 0x100000) == 0);
  return CONCAT44(param_2,param_1);
}


// ===== FUN_009a6504 @ 009a6504

ulonglong FUN_009a6504(undefined4 param_1,uint param_2,uint param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  uint unaff_r5;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  bool bVar13;
  bool bVar14;
  bool bVar15;
  undefined8 uVar16;
  
  uVar16 = CONCAT44(param_2,param_1);
  uVar11 = 0x7ff;
  uVar6 = param_2 >> 0x14 & 0x7ff;
  bVar13 = uVar6 == 0;
  if (!bVar13) {
    unaff_r5 = param_4 >> 0x14 & 0x7ff;
    bVar13 = unaff_r5 == 0;
  }
  if (!bVar13) {
    bVar13 = uVar6 == 0x7ff;
  }
  if (!bVar13) {
    bVar13 = unaff_r5 == 0x7ff;
  }
  if (bVar13) {
    uVar16 = FUN_009a66a0();
  }
  uVar8 = (uint)((ulonglong)uVar16 >> 0x20);
  uVar2 = (uint)uVar16;
  iVar7 = uVar6 - unaff_r5;
  if (param_3 == 0 && (param_4 & 0xfffff) == 0) {
    uVar6 = (uVar8 ^ param_4) & 0x80000000 | uVar8 & 0xfffff;
    bVar14 = SCARRY4(iVar7,uVar11 >> 1);
    uVar8 = iVar7 + (uVar11 >> 1);
    bVar13 = (int)uVar8 < 0;
    bVar15 = uVar8 == 0;
    if (!bVar15 && bVar13 == bVar14) {
      bVar14 = SBORROW4(uVar11,uVar8);
      bVar13 = (int)(uVar11 - uVar8) < 0;
      bVar15 = uVar11 == uVar8;
    }
    if (!bVar15 && bVar13 == bVar14) {
      return CONCAT44(uVar6 | uVar8 * 0x100000,uVar2);
    }
    uVar6 = uVar6 | 0x100000;
    uVar4 = 0;
    bVar15 = SBORROW4(uVar8,1);
    uVar8 = uVar8 - 1;
    bVar13 = uVar8 == 0;
    uVar11 = uVar8;
  }
  else {
    uVar4 = (param_4 & 0xfffff) << 8 | 0x10000000 | param_3 >> 0x18;
    uVar11 = param_3 << 8;
    uVar9 = (uVar8 & 0xfffff) << 8 | 0x10000000 | uVar2 >> 0x18;
    uVar2 = uVar2 * 0x100;
    uVar6 = (uVar8 ^ param_4) & 0x80000000;
    bVar13 = uVar4 <= uVar9;
    if (uVar9 == uVar4) {
      bVar13 = uVar11 <= uVar2;
    }
    iVar7 = iVar7 + (uint)bVar13;
    uVar8 = iVar7 + 0x3fd;
    if (!bVar13) {
      uVar4 = uVar4 >> 1;
      uVar11 = (uint)((byte)(param_3 >> 0x18) & 1) << 0x1f | (param_3 & 0xffffff) << 7;
    }
    uVar10 = uVar2 - uVar11;
    uVar9 = uVar9 - (uVar4 + (uVar2 < uVar11));
    uVar5 = uVar4 >> 1;
    uVar3 = (uint)((byte)uVar4 & 1) << 0x1f | uVar11 >> 1;
    uVar2 = 0x100000;
    uVar11 = 0x80000;
    while( true ) {
      bVar13 = uVar3 <= uVar10;
      if (uVar5 < uVar9 || uVar9 - uVar5 < (uint)bVar13) {
        uVar10 = uVar10 - uVar3;
        uVar2 = uVar2 | uVar11;
        uVar9 = uVar9 - (uVar5 + !bVar13);
      }
      uVar4 = uVar5 >> 1;
      uVar3 = (uint)((byte)uVar5 & 1) << 0x1f | uVar3 >> 1;
      bVar13 = uVar3 <= uVar10;
      if (uVar4 < uVar9 || uVar9 - uVar4 < (uint)bVar13) {
        uVar10 = uVar10 - uVar3;
        uVar2 = uVar2 | uVar11 >> 1;
        uVar9 = uVar9 - (uVar4 + !bVar13);
      }
      uVar12 = uVar5 >> 2;
      uVar1 = (uint)((byte)uVar4 & 1) << 0x1f | uVar3 >> 1;
      bVar13 = uVar1 <= uVar10;
      if (uVar12 < uVar9 || uVar9 - uVar12 < (uint)bVar13) {
        uVar10 = uVar10 - uVar1;
        uVar2 = uVar2 | uVar11 >> 2;
        uVar9 = uVar9 - (uVar12 + !bVar13);
      }
      uVar5 = uVar5 >> 3;
      uVar3 = (uint)((byte)uVar12 & 1) << 0x1f | uVar1 >> 1;
      bVar13 = uVar3 <= uVar10;
      if (uVar5 < uVar9 || uVar9 - uVar5 < (uint)bVar13) {
        uVar10 = uVar10 - uVar3;
        uVar2 = uVar2 | uVar11 >> 3;
        uVar9 = uVar9 - (uVar5 + !bVar13);
      }
      uVar4 = uVar9 | uVar10;
      if (uVar4 == 0) break;
      uVar9 = uVar9 << 4 | uVar10 >> 0x1c;
      uVar10 = uVar10 << 4;
      uVar5 = uVar5 << 3 | uVar3 >> 0x1d;
      uVar3 = (uVar1 >> 1) << 3;
      uVar11 = uVar11 >> 4;
      if (uVar11 == 0) {
        if ((uVar6 & 0x100000) != 0) goto LAB_009a6644;
        uVar6 = uVar6 | uVar2;
        uVar2 = 0;
        uVar11 = 0x80000000;
      }
    }
    if ((uVar6 & 0x100000) == 0) {
      uVar6 = uVar6 | uVar2;
      uVar2 = 0;
    }
LAB_009a6644:
    bVar14 = 0xfc < uVar8;
    bVar15 = SBORROW4(uVar8,0xfd);
    uVar12 = iVar7 + 0x300;
    bVar13 = uVar12 == 0;
    uVar11 = uVar12;
    if (bVar14 && !bVar13) {
      bVar14 = 0x6ff < uVar12;
      bVar15 = SBORROW4(uVar12,0x700);
      uVar11 = iVar7 - 0x400;
      bVar13 = uVar12 == 0x700;
    }
    if (!bVar14 || bVar13) {
      bVar13 = uVar5 <= uVar9;
      if (uVar9 == uVar5) {
        bVar13 = uVar3 <= uVar10;
      }
      if (uVar9 == uVar5 && uVar10 == uVar3) {
        bVar13 = (bool)((byte)uVar2 & 1);
      }
      return CONCAT44(uVar6 + uVar8 * 0x100000 + (uint)CARRY4(uVar2,(uint)bVar13),uVar2 + bVar13);
    }
  }
  if (!bVar13 && (int)uVar11 < 0 == bVar15) {
    return (ulonglong)(uVar6 & 0x80000000 | 0x7ff00000) << 0x20;
  }
  if ((int)uVar8 < -0x35) {
    return (ulonglong)(uVar6 & 0x80000000) << 0x20;
  }
  uVar11 = -uVar8;
  uVar9 = uVar11 - 0x20;
  if (0x1f < (int)uVar11) {
    uVar8 = uVar2 >> (uVar9 & 0xff) | uVar6 << (0x20 - uVar9 & 0xff);
    uVar11 = (uVar6 >> (uVar9 & 0xff) & ~((uVar6 & 0x80000000) >> (uVar9 & 0xff))) -
             ((int)uVar8 >> 0x1f);
    if ((uVar4 == 0 && uVar2 << (0x20 - uVar9 & 0xff) == 0) && (uVar8 & 0x7fffffff) == 0) {
      uVar11 = uVar11 & ~(uVar8 >> 0x1f);
    }
    return CONCAT44(uVar6,uVar11) & 0x80000000ffffffff;
  }
  if (uVar11 - 0x14 == 0 || (int)uVar9 < -0xc) {
    uVar9 = uVar2 << (uVar8 + 0x20 & 0xff);
    uVar2 = uVar2 >> (uVar11 & 0xff) | uVar6 << (uVar8 + 0x20 & 0xff);
    uVar8 = uVar2 + -((int)uVar9 >> 0x1f);
    if (uVar4 == 0 && (uVar9 & 0x7fffffff) == 0) {
      uVar8 = uVar8 & ~(uVar9 >> 0x1f);
    }
    return CONCAT44((uVar6 & 0x80000000) + ((uVar6 & 0x7fffffff) >> (uVar11 & 0xff)) +
                    (uint)CARRY4(uVar2,-((int)uVar9 >> 0x1f)),uVar8);
  }
  uVar8 = 0xc - (uVar11 - 0x14);
  uVar11 = uVar2 << (uVar8 & 0xff);
  uVar2 = uVar2 >> (0x20 - uVar8 & 0xff) | uVar6 << (uVar8 & 0xff);
  uVar8 = uVar2 + -((int)uVar11 >> 0x1f);
  if (uVar4 == 0 && (uVar11 & 0x7fffffff) == 0) {
    uVar8 = uVar8 & ~(uVar11 >> 0x1f);
  }
  return CONCAT44((uVar6 & 0x80000000) + (uint)CARRY4(uVar2,-((int)uVar11 >> 0x1f)),uVar8);
}


// ===== FUN_009a66a0 @ 009a66a0

ulonglong FUN_009a66a0(int param_1,uint param_2,int param_3,uint param_4)

{
  bool bVar1;
  int iVar2;
  uint unaff_r4;
  uint uVar3;
  uint uVar4;
  uint in_r12;
  bool bVar5;
  
  uVar3 = in_r12 & param_4 >> 0x14;
  if (unaff_r4 != in_r12 || uVar3 != in_r12) {
    if (unaff_r4 == in_r12) {
      if (param_1 == 0 && (param_2 & 0xfffff) == 0) {
        if (uVar3 != in_r12) {
LAB_009a64d8:
          return (ulonglong)((param_2 ^ param_4) & 0x80000000 | 0x7ff00000) << 0x20;
        }
        param_1 = param_3;
        param_2 = param_4;
      }
    }
    else if (uVar3 == in_r12) {
      if (param_3 == 0 && (param_4 & 0xfffff) == 0) {
LAB_009a6488:
        return (ulonglong)((param_2 ^ param_4) & 0x80000000) << 0x20;
      }
      param_1 = param_3;
      param_2 = param_4;
    }
    else {
      bVar1 = (param_2 & 0x7fffffff) == 0;
      bVar5 = param_1 == 0 && bVar1;
      if (param_1 != 0 || !bVar1) {
        bVar5 = param_3 == 0 && (param_4 & 0x7fffffff) == 0;
      }
      if (!bVar5) {
        if (unaff_r4 == 0) {
          uVar4 = param_2 & 0x80000000;
          do {
            iVar2 = param_1 >> 0x1f;
            param_1 = param_1 << 1;
            param_2 = param_2 * 2 - iVar2;
          } while ((param_2 & 0x100000) == 0);
          param_2 = param_2 | uVar4;
          if (uVar3 != 0) {
            return CONCAT44(param_2,param_1);
          }
        }
        do {
          iVar2 = param_3 >> 0x1f;
          param_3 = param_3 << 1;
          param_4 = param_4 * 2 - iVar2;
        } while ((param_4 & 0x100000) == 0);
        return CONCAT44(param_2,param_1);
      }
      if (param_1 != 0 || (param_2 & 0x7fffffff) != 0) goto LAB_009a64d8;
      if (param_3 != 0 || (param_4 & 0x7fffffff) != 0) goto LAB_009a6488;
    }
  }
  return CONCAT44(param_2,param_1) | 0x7ff8000000000000;
}


// ===== FUN_009a6720 @ 009a6720

uint FUN_009a6720(uint param_1,uint param_2,uint param_3,uint param_4)

{
  uint uVar1;
  bool bVar2;
  bool bVar3;
  
  if (((int)(param_2 << 1) >> 0x15 == -1 || (int)(param_4 << 1) >> 0x15 == -1) &&
     ((((int)(param_2 << 1) >> 0x15 == -1 && (param_1 != 0 || (param_2 & 0xfffff) != 0)) ||
      (((int)(param_4 << 1) >> 0x15 == -1 && (param_3 != 0 || (param_4 & 0xfffff) != 0)))))) {
    return 1;
  }
  bVar3 = (param_2 & 0x7fffffff) == 0;
  bVar2 = param_1 == 0 && bVar3;
  if (param_1 == 0 && bVar3) {
    bVar2 = param_3 == 0 && (param_4 & 0x7fffffff) == 0;
  }
  if (!bVar2) {
    bVar2 = param_2 == param_4;
  }
  if (bVar2 && param_1 == param_3) {
    return 0;
  }
  uVar1 = param_2 ^ param_4;
  bVar3 = uVar1 == 0;
  if (-1 < (int)uVar1) {
    bVar3 = param_2 == param_4;
  }
  bVar2 = -1 < (int)uVar1 && param_4 <= param_2;
  if (bVar3) {
    bVar2 = param_3 <= param_1;
  }
  param_4 = (int)param_4 >> 0x1f;
  if (!bVar2) {
    param_4 = ~param_4;
  }
  return param_4 | 1;
}


// ===== FUN_009a67a8 @ 009a67a8

undefined4 FUN_009a67a8(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  FUN_009a6720(param_3,param_4,param_1,param_2);
  return param_3;
}


// ===== FUN_009a67c4 @ 009a67c4

undefined4 FUN_009a67c4(undefined4 param_1)

{
  FUN_009a6720();
  return param_1;
}


// ===== FUN_009a67dc @ 009a67dc

undefined1 FUN_009a67dc(void)

{
  undefined1 in_ZR;
  
  FUN_009a67c4();
  return in_ZR;
}


// ===== FUN_009a67f4 @ 009a67f4

bool FUN_009a67f4(void)

{
  undefined1 in_CY;
  
  FUN_009a67c4();
  return !(bool)in_CY;
}


// ===== FUN_009a680c @ 009a680c

bool FUN_009a680c(void)

{
  undefined1 in_ZR;
  undefined1 in_CY;
  
  FUN_009a67c4();
  return !(bool)in_CY || (bool)in_ZR;
}


// ===== FUN_009a6824 @ 009a6824

bool FUN_009a6824(void)

{
  undefined1 in_ZR;
  undefined1 in_CY;
  
  FUN_009a67a8();
  return !(bool)in_CY || (bool)in_ZR;
}


// ===== FUN_009a683c @ 009a683c

bool FUN_009a683c(void)

{
  undefined1 in_CY;
  
  FUN_009a67a8();
  return !(bool)in_CY;
}


// ===== FUN_009a6854 @ 009a6854

uint FUN_009a6854(uint param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = param_2 * 2 + 0x200000;
  if (param_2 * 2 < 0xffe00000) {
    if (-1 < iVar2) {
      return 0;
    }
    uVar1 = iVar2 >> 0x15;
    uVar3 = -uVar1 - 0x3e1;
    if (uVar1 < 0xfffffc20 && uVar3 != 0) {
      uVar1 = (param_2 << 0xb | 0x80000000 | param_1 >> 0x15) >> (uVar3 & 0xff);
      if ((param_2 & 0x80000000) != 0) {
        uVar1 = -uVar1;
      }
      return uVar1;
    }
  }
  else if (param_1 != 0 || (param_2 & 0xfffff) != 0) {
    return 0;
  }
  param_2 = param_2 & 0x80000000;
  if (param_2 == 0) {
    param_2 = 0x7fffffff;
  }
  return param_2;
}


// ===== FUN_009a68b0 @ 009a68b0

uint FUN_009a68b0(uint param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  
  if (SUB41(param_2 >> 0x1f,0)) {
    return 0;
  }
  iVar1 = param_2 * 2 + 0x200000;
  if (param_2 * 2 < 0xffe00000) {
    if (-1 < iVar1) {
      return 0;
    }
    uVar2 = -(iVar1 >> 0x15) - 0x3e1;
    if (-1 < (int)uVar2) {
      return (param_2 << 0xb | 0x80000000 | param_1 >> 0x15) >> (uVar2 & 0xff);
    }
  }
  else if (param_1 != 0 || (param_2 & 0xfffff) != 0) {
    return 0;
  }
  return 0xffffffff;
}


// ===== FUN_009a6904 @ 009a6904

undefined8 FUN_009a6904(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  undefined8 uVar2;
  undefined1 local_8 [8];
  
  if (param_4 == 0 && param_3 == 0) {
    if (param_2 < 0) {
      param_2 = -0x80000000;
      param_1 = 0;
    }
    else if (param_2 != 0 || param_1 != 0) {
      param_2 = 0x7fffffff;
      param_1 = -1;
    }
    return CONCAT44(param_2,param_1);
  }
  if (param_2 < 0) {
    iVar1 = -param_2 - (uint)(param_1 != 0);
    if (param_4 < 0) {
      uVar2 = FUN_009a6a14(-param_1,iVar1,-param_3,-param_4 - (uint)(param_3 != 0),local_8);
      return uVar2;
    }
    uVar2 = FUN_009a6a14(-param_1,iVar1,param_3,param_4,local_8);
    return CONCAT44(-(int)((ulonglong)uVar2 >> 0x20) - (uint)((int)uVar2 != 0),-(int)uVar2);
  }
  if (param_4 < 0) {
    uVar2 = FUN_009a6a14(param_1,param_2,-param_3,-param_4 - (uint)(param_3 != 0),local_8);
    return CONCAT44(-(int)((ulonglong)uVar2 >> 0x20) - (uint)((int)uVar2 != 0),-(int)uVar2);
  }
  uVar2 = FUN_009a6a14();
  return uVar2;
}


// ===== FUN_009a6934 @ 009a6934

int FUN_009a6934(int param_1,int param_2,int param_3,int param_4,undefined1 param_5)

{
  int iVar1;
  undefined1 uStack00000000;
  
  if (param_2 < 0) {
    iVar1 = -param_2 - (uint)(param_1 != 0);
    if (param_4 < 0) {
      iVar1 = FUN_009a6a14(-param_1,iVar1,-param_3,-param_4 - (uint)(param_3 != 0),&param_5);
      return iVar1;
    }
    iVar1 = FUN_009a6a14(-param_1,iVar1,param_3,param_4,&param_5);
    return -iVar1;
  }
  if (param_4 < 0) {
    iVar1 = FUN_009a6a14(param_1,param_2,-param_3,-param_4 - (uint)(param_3 != 0),&param_5);
    return -iVar1;
  }
  iVar1 = FUN_009a6a14();
  return iVar1;
}


// ===== FUN_009a69d8 @ 009a69d8

undefined8 FUN_009a69d8(int param_1,int param_2,int param_3,int param_4)

{
  undefined8 uVar1;
  
  if (param_4 != 0 || param_3 != 0) {
    uVar1 = FUN_009a6a14();
    return uVar1;
  }
  if (param_2 != 0 || param_1 != 0) {
    param_2 = -1;
    param_1 = -1;
  }
  return CONCAT44(param_2,param_1);
}


// ===== FUN_009a69fc @ 009a69fc

void FUN_009a69fc(void)

{
  FUN_009a6a14();
  return;
}


// ===== FUN_009a6a14 @ 009a6a14

undefined8 FUN_009a6a14(uint param_1,uint param_2,uint param_3,uint param_4,uint *param_5)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  bool bVar12;
  
  if (param_4 < param_2 || param_2 - param_4 < (uint)(param_3 <= param_1)) {
    iVar2 = FUN_009a6b54(param_3,param_4);
    iVar3 = FUN_009a6b54(param_1,param_2);
    uVar11 = iVar2 - iVar3;
    uVar9 = uVar11 - 0x20;
    uVar8 = 0x20 - uVar11;
    uVar6 = param_4 << (uVar11 & 0xff) | param_3 << (uVar9 & 0xff) | param_3 >> (uVar8 & 0xff);
    param_3 = param_3 << (uVar11 & 0xff);
    if (uVar6 < param_2 || param_2 - uVar6 < (uint)(param_3 <= param_1)) {
      bVar12 = param_1 < param_3;
      param_1 = param_1 - param_3;
      uVar4 = 1 << (uVar9 & 0xff) | 1U >> (uVar8 & 0xff);
      param_2 = param_2 - (uVar6 + bVar12);
      uVar1 = 1 << (uVar11 & 0xff);
    }
    else {
      uVar1 = 0;
      uVar4 = uVar1;
    }
    if (uVar11 != 0) {
      uVar5 = param_3 >> 1 | uVar6 << 0x1f;
      uVar6 = uVar6 >> 1;
      uVar10 = uVar11;
      do {
        while (uVar6 < param_2 || param_2 - uVar6 < (uint)(uVar5 <= param_1)) {
          bVar12 = param_1 < uVar5;
          uVar7 = param_1 - uVar5;
          param_1 = uVar7 * 2 + 1;
          param_2 = (param_2 - (uVar6 + bVar12)) * 2 + (uint)CARRY4(uVar7,uVar7) +
                    (uint)(0xfffffffe < uVar7 * 2);
          uVar10 = uVar10 - 1;
          if (uVar10 == 0) goto LAB_009a6b0c;
        }
        bVar12 = CARRY4(param_1,param_1);
        param_1 = param_1 * 2;
        param_2 = param_2 * 2 + (uint)bVar12;
        uVar10 = uVar10 - 1;
      } while (uVar10 != 0);
LAB_009a6b0c:
      bVar12 = CARRY4(uVar1,param_1);
      uVar6 = uVar1 + param_1;
      param_1 = param_1 >> (uVar11 & 0xff) | param_2 << (uVar8 & 0xff) | param_2 >> (uVar9 & 0xff);
      iVar2 = uVar4 + param_2;
      param_2 = param_2 >> (uVar11 & 0xff);
      uVar4 = param_1 << (uVar11 & 0xff);
      uVar1 = uVar6 - uVar4;
      uVar4 = (iVar2 + (uint)bVar12) -
              ((param_2 << (uVar11 & 0xff) | param_1 << (uVar9 & 0xff) | param_1 >> (uVar8 & 0xff))
              + (uint)(uVar6 < uVar4));
    }
  }
  else {
    uVar1 = 0;
    uVar4 = uVar1;
  }
  if (param_5 != (uint *)0x0) {
    *param_5 = param_1;
    param_5[1] = param_2;
  }
  return CONCAT44(uVar4,uVar1);
}


// ===== FUN_009a6b54 @ 009a6b54

int FUN_009a6b54(undefined4 param_1,int param_2)

{
  int iVar1;
  
  if (param_2 == 0) {
    iVar1 = FUN_009a6b7c();
    iVar1 = iVar1 + 0x20;
  }
  else {
    iVar1 = FUN_009a6b7c(param_2);
  }
  return iVar1;
}


// ===== FUN_009a6b7c @ 009a6b7c

int FUN_009a6b7c(uint param_1)

{
  int iVar1;
  
  iVar1 = 0x1c;
  if (0xffff < param_1) {
    param_1 = param_1 >> 0x10;
    iVar1 = 0xc;
  }
  if (0xff < param_1) {
    param_1 = param_1 >> 8;
    iVar1 = iVar1 + -8;
  }
  if (0xf < param_1) {
    param_1 = param_1 >> 4;
    iVar1 = iVar1 + -4;
  }
  return (uint)(byte)(&DAT_009a6bb4)[param_1] + iVar1;
}


