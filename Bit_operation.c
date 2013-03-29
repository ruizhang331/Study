/************
Bit Manipulation and low level stuff
**************/
/*
Swap odd and even bit
*/
int SwapOddEvenbits(int x){
  return ((x&0xaaaaaaaa)>>1) | (x&0x55555555)<<1))
}

/*
Detect whether a number is 2's power
*/
bool Istwopower(int n)
{
	if((n&(n-1)) == 0)
		return true;
	else
		return false
}

return (num != 0) && ((num & (num - 1)) == 0);

/*
Detect how many "1" in one int
*/
//method 1, shift and &
int Numofone(int x){
	int count = 0;
	for(i=0;i<sizeof(int)*8;i++){
		if(x&0x00000001) count++;
		x = x>>1;
	}
	
	return count;
}

//method 2, using a array or hash table to search

//method 3
int Numofone(int x){
	x = (x & 0x55555555) + ((x>>1) & 0x55555555);
	x = (x & 0x33333333) + ((x>>2) & 0x33333333);
	x = (x & 0x0f0f0f0f) + ((x>>4) & 0x0f0f0f0f);
	x += (x>>8);
	x += (x>>16);
	return (x & 0x00ff);
}

//method 4:
int Numofone(int x){
	int count = 0;
	if(x == 0) count = 0;

	do{
		count++;
	}while(x&=(x-1));
	
	return count;
}

int Numofone(int x){

    int counter =0;
    for(;x!=0;x&=(x-1)){
        count++;
    }
    
    return counter;

}
