#include<stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

//http://clrhome.org/table/
int32_t check_file_size(FILE *fp){
  uint8_t data;
  uint32_t filesize=0;
  if(fp){//if file opened sucessfully
    fseek(fp, filesize, SEEK_SET);
    while (fread(&data, 1, 1, fp)==1) {
      filesize++;
    }
    return filesize;
  }
}
uint8_t disassemble(uint8_t *buffer, uint32_t pc){
  uint8_t instruction=buffer[pc];
  int inst_bytes=1;
  printf("%04x ", pc);
  printf("%02x", buffer[pc]);
  switch (instruction) {
    case 0x00: printf("\tNOP"); break;
    case 0x01: printf("\tLD BC, %02x%02x ",buffer[pc+1],buffer[pc+2]); break;
    case 0x02: printf("\tLD [BC], A"); break;
    case 0x03: printf("\tINC BC"); break;
    case 0x04: printf("\tINC B"); break;
    case 0x05: printf("\tDEC B"); break;
    case 0x06: printf("\tLD B,%02x", buffer[pc+i]); break;
    case 0x07: printf("\tRLCA"); break;
    case 0x08: printf("\tEX AF, AF'"); break;
    case 0x09: printf("\tADD HL, BC"); break;
    case 0x0A: printf("\tLD A, [BC]"); break;
    case 0x0B: printf("\tDEC BC"); break;
    case 0x0C: printf("\tINC C"); break;
    case 0x0D: printf("\tDEC C"); break;
    case 0x0E: printf("\tLD C, %02x",buffer[pc+1]); break;
    case 0x0F: printf("\tRRCA"); break;

    case 0x10: printf("\tDJNZ, %02x",buffer[pc+1]); break;
    case 0x01: printf("\tLD DE, %02x%02x ",buffer[pc+1],buffer[pc+2]); break;
    case 0x02: printf("\tLD [DE], A"); break;
    case 0x03: printf("\tINC DE"); break;
    case 0x04: printf("\tINC D"); break;
    case 0x05: printf("\tDEC D"); break;
    case 0x06: printf("\tLD D,%02x", buffer[pc+i]); break;
    case 0x07: printf("\tRLA"); break;
    case 0x08: printf("\tJR, %02x", buffer[pc+1]); break;
    case 0x09: printf("\tADD HL, DE"); break;
    case 0x0A: printf("\tLD A, [DE]"); break;
    case 0x0B: printf("\tDEC DE"); break;
    case 0x0C: printf("\tINC E"); break;
    case 0x0D: printf("\tDEC E"); break;
    case 0x0E: printf("\tLD E, %02x",buffer[pc+1]); break;
    case 0x0F: printf("\tRRA"); break;

    case 0x10: printf("\tJR NZ, %02x",buffer[pc+1]); break;
    case 0x01: printf("\tLD HL, %02x%02x ",buffer[pc+1],buffer[pc+2]); break;
    case 0x02: printf("\tLD [%02x%02x], HL",buffer[pc+1],buffer[pc+2]]); break;
    case 0x03: printf("\tINC HL"); break;
    case 0x04: printf("\tINC H"); break;
    case 0x05: printf("\tDEC H"); break;
    case 0x06: printf("\tLD H,%02x", buffer[pc+i]); break;
    case 0x07: printf("\tDAA"); break;
    case 0x08: printf("\tJR Z, %02x", buffer[pc+1]); break;
    case 0x09: printf("\tADD HL, HL"); break;
    case 0x0A: printf("\tLD HL, [%02x%02x]",buffer[pc+1],buffer[pc+2]); break;
    case 0x0B: printf("\tDEC HL"); break;
    case 0x0C: printf("\tINC L"); break;
    case 0x0D: printf("\tDEC L"); break;
    case 0x0E: printf("\tLD L, %02x",buffer[pc+1]); break;
    case 0x0F: printf("\tCPL"); break;






    default: printf("\tinimplemented instruction"); break;
  }
  printf("\n");
  return inst_bytes;

}

void hexdump(uint8_t* buffer, uint32_t buffersize){
  for (uint32_t i=0;i<buffersize;i++){
    if(i%8==0) printf("\n");
    printf("%02x ", buffer[i]);
  }
  printf("\n");
}

int main(void){
  FILE *romptr;
  romptr=fopen("pacman.bin", "rb");
  uint32_t filesize=0;
  printf("z80 disassembler\nRobson Couto 2017\n");
  filesize=check_file_size(romptr);
  if(filesize==0){
    printf("File not found");
    return 0;
  }
  printf("File size:%d\n",filesize );
  uint8_t *buffer = (uint8_t *) malloc(filesize);
  fseek(romptr, 0, SEEK_SET);
  if (fread(buffer, 1, filesize, romptr)==filesize){
    printf("Moved file to buffer:%d\n",filesize );
  }
  //hexdump(buffer,filesize);
  //printf("size of buffer %d ", strlen(buffer));
  uint32_t pc=0;
  while (pc<=filesize) {
    pc+= disassemble(buffer,pc);
  }

}
