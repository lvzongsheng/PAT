//
//  main.cpp
//  PAT1049
//  http://pat.zju.edu.cn/contests/pat-a-practise/1049
//  Solutions:
//  此题运行时间只有10ms，不能采用遍历的方法，但是纵观该题，可以找到规律。通过计算每一位上出现的1的个数来求得。
//  Created by 吕 宗胜 on 7/10/13.
//  Copyright (c) 2013 吕 宗胜. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char * argv[])
{

    int n;
    scanf("%d",&n);
    int temp = n;
    int index = 1;
    int result = 0;
    while(temp>0){
        int r = temp/10;
        int p = temp%10;
        result = result+r*index;
        if(p>1){
            result = result+index;
        }else if(p==1){
            result = result + n%index+1;
        }
        index = index*10;
        temp = temp/10;
        
    }
    printf("%d",result);
    return 0;
}

