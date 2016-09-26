---
title: 插入排序容易犯错的地方 
---

```
void insertSort(int array[],int count){
    int j,i,key;
    for(j=1;j<count;j++){
        i=j-1;
        key = array[j];
        while(i>=0&&array[i]>=key){ // 这里的key，容易写成array[j]，这是我特别容易犯的错误
            array[i+1] = array[i];//另外一个 地方，我容易在i+1这里写成j，这也是一个要注意的地方
            i--;
        }
        array[i+1] = key;
    }
}
```
