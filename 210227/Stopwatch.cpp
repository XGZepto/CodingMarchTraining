#include <cstdio>
#include <string>

using namespace std;

int hh, mm, ss;

int main(){
    int opt = 1, flag = 0;
    while(opt != 2){
        char buff[10];
        scanf("%d", &opt);
        scanf("%s", buff);
        int nhh = (buff[0] - '0') * 10 + (buff[1] - '0');
        int nmm = (buff[3] - '0') * 10 + (buff[4] - '0');
        int nss = (buff[6] - '0') * 10 + (buff[7] - '0');
        int css = nss - ss, cmm = nmm - mm, chh = nhh - hh;
        if (css < 0) css += 60, cmm--;
        if (cmm < 0) cmm += 60, chh--;
        if (flag) printf("%02d:%02d:%02d\n", chh, cmm, css);
        flag = 1;
        hh = nhh * opt, mm = nmm * opt, ss = nss * opt;
    }
    return 0;
}