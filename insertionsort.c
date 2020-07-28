void insertion(int n, int array[]){

  int i, j, value;
  for(i = 1; i <n; i++){
    value = array[i];
    j = i - 1;
    /* Move elements of arr[0..i-1], that are
      greater than key, to one position ahead
      of their current position */
    while(value < array[j] && j >=0){
      array[j + 1] = array[j];
      j--;
    }
    array[j+1] = value;
  }
}
