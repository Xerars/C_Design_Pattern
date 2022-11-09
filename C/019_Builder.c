// Builder

typedef struct _AssemblePersonalComputer
{
  void (*assemble_cpu)(void);
  void (*assemble_memory)(void);
  void (*assemble_harddisk)(void);
} AssemblePersonalComputer;

void assemble_intel_cpu(void)
{
  printf("Intel CPU\n");
}

void assemble_samsung_memory(void)
{
  printf("Samsung Memory\n");
}

void assemble_hitachi_harddisk(void)
{
  printf("Hitichi Harddisk\n");
}

void assemble_amd_cpu(void)
{
  printf("AMD CPU\n");
}

void assemble_kingston_memory(void)
{
  printf("Kingston Memory\n");
}

void assemble_western_digit_harddisk(void)
{
  printf("Western Digital Harddisk\n");
}

