#include<stdio.h>
#include <inttypes.h>
#include <stdlib.h>

uint32_t check_file_size(FILE *fp){
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

int main(void){
  FILE *romptr;
  romptr=fopen("pacman.bin", "rb");
  uint32_t filesize=0;
  printf("z80 disassembler\nRobson Couto 2017\n");
  filesize=check_file_size(romptr);
  if(!filesize){
    printf("File not found");
    return 0;
  }
  printf("File size:%d\n",filesize );
  uint8_t buffer = (uint8_t *) malloc(filesize);

  return 0;
}
