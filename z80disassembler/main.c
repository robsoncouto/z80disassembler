#include<stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
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
void disassemble(uint8_t *buffer){
  //nopasss
}

void hexdump(uint8_t* buffer, uint32_t buffersize){
  for (uint32_t i=0;i<buffersize;i++){
    if(i%8==0) printf("\n");
    printf("%02x ", buffer[i]);
  }
  printf("\n")
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
  hexdump(buffer,filesize);
  //printf("size of buffer %d ", strlen(buffer));
}
