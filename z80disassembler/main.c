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
    case 0x06: printf("\tLD B,%02x", buffer[pc+1]); break;
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
    case 0x11: printf("\tLD DE, %02x%02x ",buffer[pc+1],buffer[pc+2]); break;
    case 0x12: printf("\tLD [DE], A"); break;
    case 0x13: printf("\tINC DE"); break;
    case 0x14: printf("\tINC D"); break;
    case 0x15: printf("\tDEC D"); break;
    case 0x16: printf("\tLD D,%02x", buffer[pc+1]); break;
    case 0x17: printf("\tRLA"); break;
    case 0x18: printf("\tJR, %02x", buffer[pc+1]); break;
    case 0x19: printf("\tADD HL, DE"); break;
    case 0x1A: printf("\tLD A, [DE]"); break;
    case 0x1B: printf("\tDEC DE"); break;
    case 0x1C: printf("\tINC E"); break;
    case 0x1D: printf("\tDEC E"); break;
    case 0x1E: printf("\tLD E, %02x",buffer[pc+1]); break;
    case 0x1F: printf("\tRRA"); break;

    case 0x20: printf("\tJR NZ, %02x",buffer[pc+1]); break;
    case 0x21: printf("\tLD HL, %02x%02x ",buffer[pc+1],buffer[pc+2]); break;
    case 0x22: printf("\tLD [%02x%02x], HL",buffer[pc+1],buffer[pc+2]); break;
    case 0x23: printf("\tINC HL"); break;
    case 0x24: printf("\tINC H"); break;
    case 0x25: printf("\tDEC H"); break;
    case 0x26: printf("\tLD H,%02x", buffer[pc+1]); break;
    case 0x27: printf("\tDAA"); break;
    case 0x28: printf("\tJR Z, %02x", buffer[pc+1]); break;
    case 0x29: printf("\tADD HL, HL"); break;
    case 0x2A: printf("\tLD HL, [%02x%02x]",buffer[pc+1],buffer[pc+2]); break;
    case 0x2B: printf("\tDEC HL"); break;
    case 0x2C: printf("\tINC L"); break;
    case 0x2D: printf("\tDEC L"); break;
    case 0x2E: printf("\tLD L, %02x",buffer[pc+1]); break;
    case 0x2F: printf("\tCPL"); break;

    case 0x30: printf("\tJR NC, %02x",buffer[pc+1]); break;
    case 0x31: printf("\tLD SP, %02x%02x ",buffer[pc+1],buffer[pc+2]); break;
    case 0x32: printf("\tLD [%02x%02x], A",buffer[pc+1],buffer[pc+2]); break;
    case 0x33: printf("\tINC SP"); break;
    case 0x34: printf("\tINC [HL]"); break;
    case 0x35: printf("\tDEC [HL]"); break;
    case 0x36: printf("\tLD [HL],%02x", buffer[pc+1]); break;
    case 0x37: printf("\tSCF"); break;
    case 0x38: printf("\tJR C, %02x", buffer[pc+1]); break;
    case 0x39: printf("\tADD HL, SP"); break;
    case 0x3A: printf("\tLD A, [%02x%02x]",buffer[pc+1],buffer[pc+2]); break;
    case 0x3B: printf("\tDEC SP"); break;
    case 0x3C: printf("\tINC A"); break;
    case 0x3D: printf("\tDEC A"); break;
    case 0x3E: printf("\tLD L, %02x",buffer[pc+1]); break;
    case 0x3F: printf("\tCPF"); break;

    case 0x40: printf("\tLD B, B"); break;
    case 0x41: printf("\tLD B, C"); break;
    case 0x42: printf("\tLD B, D"); break;
    case 0x43: printf("\tLD B, E"); break;
    case 0x44: printf("\tLD B, H"); break;
    case 0x45: printf("\tLD B, L"); break;
    case 0x46: printf("\tLD B, [HL]"); break;
    case 0x47: printf("\tLD B, A"); break;
    case 0x48: printf("\tLD C, B"); break;
    case 0x49: printf("\tLD C, C"); break;
    case 0x4A: printf("\tLD C, D"); break;
    case 0x4B: printf("\tLD C, E"); break;
    case 0x4C: printf("\tLD C, H"); break;
    case 0x4D: printf("\tLD C, L"); break;
    case 0x4E: printf("\tLD C, [HL]"); break;
    case 0x4F: printf("\tLD C, A"); break;

    case 0x50: printf("\tLD D, B"); break;
    case 0x51: printf("\tLD D, C"); break;
    case 0x52: printf("\tLD D, D"); break;
    case 0x53: printf("\tLD D, E"); break;
    case 0x54: printf("\tLD D, H"); break;
    case 0x55: printf("\tLD D, L"); break;
    case 0x56: printf("\tLD D, [HL]"); break;
    case 0x57: printf("\tLD D, A"); break;
    case 0x58: printf("\tLD E, B"); break;
    case 0x59: printf("\tLD E, C"); break;
    case 0x5A: printf("\tLD E, D"); break;
    case 0x5B: printf("\tLD E, E"); break;
    case 0x5C: printf("\tLD E, H"); break;
    case 0x5D: printf("\tLD E, L"); break;
    case 0x5E: printf("\tLD E, [HL]"); break;
    case 0x5F: printf("\tLD E, A"); break;

    case 0x60: printf("\tLD H, B"); break;
    case 0x61: printf("\tLD H, C"); break;
    case 0x62: printf("\tLD H, D"); break;
    case 0x63: printf("\tLD H, E"); break;
    case 0x64: printf("\tLD H, H"); break;
    case 0x65: printf("\tLD H, L"); break;
    case 0x66: printf("\tLD H, [HL]"); break;
    case 0x67: printf("\tLD H, A"); break;
    case 0x68: printf("\tLD L, B"); break;
    case 0x69: printf("\tLD L, C"); break;
    case 0x6A: printf("\tLD L, D"); break;
    case 0x6B: printf("\tLD L, E"); break;
    case 0x6C: printf("\tLD L, H"); break;
    case 0x6D: printf("\tLD L, L"); break;
    case 0x6E: printf("\tLD L, [HL]"); break;
    case 0x6F: printf("\tLD L, A"); break;

    case 0x70: printf("\tLD [HL], B"); break;
    case 0x71: printf("\tLD [HL], C"); break;
    case 0x72: printf("\tLD [HL], D"); break;
    case 0x73: printf("\tLD [HL], E"); break;
    case 0x74: printf("\tLD [HL], H"); break;
    case 0x75: printf("\tLD [HL], L"); break;
    case 0x76: printf("\tLD HALT"); break;
    case 0x77: printf("\tLD [HL], A"); break;
    case 0x78: printf("\tLD A, B"); break;
    case 0x79: printf("\tLD A, C"); break;
    case 0x7A: printf("\tLD A, D"); break;
    case 0x7B: printf("\tLD A, E"); break;
    case 0x7C: printf("\tLD A, H"); break;
    case 0x7D: printf("\tLD A, L"); break;
    case 0x7E: printf("\tLD A, [HL]"); break;
    case 0x7F: printf("\tLD A, A"); break;

    case 0x80: printf("\tADD A, B"); break;
    case 0x81: printf("\tADD A, C"); break;
    case 0x82: printf("\tADD A, D"); break;
    case 0x83: printf("\tADD A, E"); break;
    case 0x84: printf("\tADD A, H"); break;
    case 0x85: printf("\tADD A, L"); break;
    case 0x86: printf("\tADD A, [HL]"); break;
    case 0x87: printf("\tADD A, A"); break;
    case 0x88: printf("\tADC A, B"); break;
    case 0x89: printf("\tADC A, C"); break;
    case 0x8A: printf("\tADC A, D"); break;
    case 0x8B: printf("\tADC A, E"); break;
    case 0x8C: printf("\tADC A, H"); break;
    case 0x8D: printf("\tADC A, L"); break;
    case 0x8E: printf("\tADC A, [HL]"); break;
    case 0x8F: printf("\tADC A, A"); break;

    case 0x90: printf("\tSUB B"); break;
    case 0x91: printf("\tSUB C"); break;
    case 0x92: printf("\tSUB D"); break;
    case 0x93: printf("\tSUB E"); break;
    case 0x94: printf("\tSUB H"); break;
    case 0x95: printf("\tSUB L"); break;
    case 0x96: printf("\tSUB [HL]"); break;
    case 0x97: printf("\tSUB A"); break;
    case 0x98: printf("\tSBC A, B"); break;
    case 0x99: printf("\tSBC A, C"); break;
    case 0x9A: printf("\tSBC A, D"); break;
    case 0x9B: printf("\tSBC A, E"); break;
    case 0x9C: printf("\tSBC A, H"); break;
    case 0x9D: printf("\tSBC A, L"); break;
    case 0x9E: printf("\tSBC A, [HL]"); break;
    case 0x9F: printf("\tSBC A, A"); break;

    case 0xA0: printf("\tAND B"); break;
    case 0xA1: printf("\tAND C"); break;
    case 0xA2: printf("\tAND D"); break;
    case 0xA3: printf("\tAND E"); break;
    case 0xA4: printf("\tAND H"); break;
    case 0xA5: printf("\tAND L"); break;
    case 0xA6: printf("\tAND [HL]"); break;
    case 0xA7: printf("\tAND A"); break;
    case 0xA8: printf("\tXOR B"); break;
    case 0xA9: printf("\tXOR C"); break;
    case 0xAA: printf("\tXOR D"); break;
    case 0xAB: printf("\tXOR E"); break;
    case 0xAC: printf("\tXOR H"); break;
    case 0xAD: printf("\tXOR L"); break;
    case 0xAE: printf("\tXOR [HL]"); break;
    case 0xAF: printf("\tXOR A"); break;

    case 0xB0: printf("\tOR B"); break;
    case 0xB1: printf("\tOR C"); break;
    case 0xB2: printf("\tOR D"); break;
    case 0xB3: printf("\tOR E"); break;
    case 0xB4: printf("\tOR H"); break;
    case 0xB5: printf("\tOR L"); break;
    case 0xB6: printf("\tOR [HL]"); break;
    case 0xB7: printf("\tOR A"); break;
    case 0xB8: printf("\tCP B"); break;
    case 0xB9: printf("\tCP C"); break;
    case 0xBA: printf("\tCP D"); break;
    case 0xBB: printf("\tCP E"); break;
    case 0xBC: printf("\tCP H"); break;
    case 0xBD: printf("\tCP L"); break;
    case 0xBE: printf("\tCP [HL]"); break;
    case 0xBF: printf("\tCP A"); break;

    case 0xc0: printf("\tRET NZ"); break;
    case 0xc1: printf("\tPOP BC"); break;
    case 0xc2: printf("\tJP NZ %02x%02x",buffer[pc+1],buffer[pc+2]); break;
    case 0xc3: printf("\tJP %02x%02x",buffer[pc+1],buffer[pc+2]); break;
    case 0xC4: printf("\tCALL NZ %02x%02x",buffer[pc+1],buffer[pc+2]); break;
    case 0xC5: printf("\tPUSH BC"); break;
    case 0xC6: printf("\tADD A, %02x",buffer[pc+1]); break;
    case 0xC7: printf("\tRST 00h"); break;
    case 0xC8: printf("\tRET Z"); break;
    case 0xC9: printf("\tRET"); break;
    case 0xCA: printf("\tJP Z, %02x%02x",buffer[pc+1],buffer[pc+2]); break;
    case 0xCB: printf("\t-BIT INSTRUCTION-"); break;//FIXME BITS GO HERE
    case 0xCC: printf("\tCALL Z,%02x%02x",buffer[pc+1],buffer[pc+2]); break;
    case 0xCD: printf("\tCALL %02x%02x",buffer[pc+1],buffer[pc+2]); break;
    case 0xCE: printf("\tADC A, %02x",buffer[pc+1]); break;
    case 0xCF: printf("\tRST 08h"); break;

    case 0xD0: printf("\tRET NC"); break;
    case 0xD1: printf("\tPOP DE"); break;
    case 0xD2: printf("\tJP NC %02x%02x",buffer[pc+1],buffer[pc+2]); break;
    case 0xD3: printf("\tOUT [%02x], A ",buffer[pc+1]); break;
    case 0xD4: printf("\tCALL NC %02x%02x",buffer[pc+1],buffer[pc+2]); break;
    case 0xD5: printf("\tPUSH DE"); break;
    case 0xD6: printf("\tSUB %02x",buffer[pc+1]); break;
    case 0xD7: printf("\tRST 10h"); break;
    case 0xD8: printf("\tRET C"); break;
    case 0xD9: printf("\tEXX"); break;
    case 0xDA: printf("\tJP C, [%02x%02x]",buffer[pc+1],buffer[pc+2]); break;
    case 0xDB: printf("\tIN A, [%02x]",buffer[pc+1]); break;//FIXME BITS GO HERE
    case 0xDC: printf("\tCALL C,[%02x%02x]",buffer[pc+1],buffer[pc+2]); break;
    case 0xDD: printf("\t-IX INSTRUCTION-"); break;
    case 0xDE: printf("\tSBC A, %02x",buffer[pc+1]); break;
    case 0xDF: printf("\tRST 18h"); break;

    case 0xE0: printf("\tRET PO"); break;
    case 0xE1: printf("\tPOP HL"); break;
    case 0xE2: printf("\tJP PO %02x%02x",buffer[pc+1],buffer[pc+2]); break;
    case 0xE3: printf("\tEX [SP], HL "); break;
    case 0xE4: printf("\tCALL PO %02x%02x",buffer[pc+1],buffer[pc+2]); break;
    case 0xE5: printf("\tPUSH HL"); break;
    case 0xE6: printf("\tAND %02x",buffer[pc+1]); break;
    case 0xE7: printf("\tRST 20h"); break;
    case 0xE8: printf("\tRET PE"); break;
    case 0xE9: printf("\tJP [HL]"); break;
    case 0xEA: printf("\tJP PE, %02x%02x",buffer[pc+1],buffer[pc+2]); break;
    case 0xEB: printf("\tEX DE, HL"); break;//FIXME BITS GO HERE
    case 0xEC: printf("\tCALL PE, %02x%02x",buffer[pc+1],buffer[pc+2]); break;
    case 0xED: printf("\t-EXTD INSTRUCTION-"); break;
    case 0xEE: printf("\tXOR %02x",buffer[pc+1]); break;
    case 0xEF: printf("\tRST 28h"); break;

    case 0xF0: printf("\tRET P"); break;
    case 0xF1: printf("\tPOP AF"); break;
    case 0xF2: printf("\tJP P %02x%02x",buffer[pc+1],buffer[pc+2]); break;
    case 0xF3: printf("\tDI"); break;
    case 0xF4: printf("\tCALL P %02x%02x",buffer[pc+1],buffer[pc+2]); break;
    case 0xF5: printf("\tPUSH AF"); break;
    case 0xF6: printf("\tOR %02x",buffer[pc+1]); break;
    case 0xF7: printf("\tRST 30h"); break;
    case 0xF8: printf("\tRET M"); break;
    case 0xF9: printf("\tLD SP, HL"); break;
    case 0xFA: printf("\tJP M, %02x%02x",buffer[pc+1],buffer[pc+2]); break;
    case 0xFB: printf("\tEI"); break;//FIXME BITS GO HERE
    case 0xFC: printf("\tCALL M, %02x%02x",buffer[pc+1],buffer[pc+2]); break;
    case 0xFD: printf("\t-IY INSTRUCTION-"); break;
    case 0xFE: printf("\tCP %02x",buffer[pc+1]); break;
    case 0xFF: printf("\tRST 38h"); break;

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
