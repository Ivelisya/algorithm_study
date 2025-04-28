/*

小蓝要为一条街的住户制作门牌号。
这条街一共有 2020 位住户，门牌号从 1到 2020 编号。
小蓝制作门牌的方法是先制作0到9这几个数字字符，最后根据需要将字符粘贴到门牌上，例如门牌 1017 需要依次粘贴字符 1、0、1、7,即需要 1 个字符 0，2 个字符 1，1 个字符 7。
请问要制作所有的 1 到 2020 号门牌，总共需要多少个字符 2?
*/

#include <iostream>
using namespace std;
int two = 0;
int main(){
    for(int i =1;i <= 2020; ++i){
        int temp = i;
        while(temp){
            if(temp % 10 == 2){
                two++;
            }
            temp /= 10;
        }   
    }
    cout << two << endl;
    return 0;
}