#include<cstdio>
#include<cmath>
using namespace std;

#define PI 3.14159265358979323846
#define eps 1e-10

double getArc(double chord, double theta){
    theta = theta * (PI/180);
    double r = chord/(2 * sin(theta/2));
    double ans = r  * theta;
    return ans;
}

double newL(int l, int n, double c){
    double ans = (1 + n * c) * l;
    return ans;
}

double sagitta(double r, double chord){
    double l = chord/2;
    double ans = r - sqrt(pow(r, 2) - pow(l,2));
    return ans;
}

double bisection(double low, double hi, double chord, double arc){
    double ans, wans, mid, tmp;
    if(low < hi){
        while(abs(hi - low) > eps){
            mid = (low + ((hi - low)) / 2);
            tmp = getArc(chord, mid);
            if (tmp > arc){
                hi = mid;
            }else{
                low = mid;
            }
        }
    }
    ans = tmp;
    wans = low * (PI/180) / 2;
    return wans;
}

int main(){
    int l, n;
    double c, r, angle, arc;
    scanf("%d %d %lf", &l, &n, &c);
    while (l >= 0 && n >= 0 && c >= 0){
        arc = newL(l, n, c);
        if(arc == l){
            printf("0.000\n");
        }else{
            angle = bisection(-181, 181, l, arc);
            r = l / (2 * sin(angle));
            printf("%.3f\n", sagitta(r, l));
        }
        scanf("%d %d %lf", &l, &n, &c);
    }
    return 0;
}
