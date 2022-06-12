#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int num, sayac, i, j, k, k1, k2;
float a, b, c, d, e, g, ep, x1, x2, h1, h2, top1, top2, m, A[20][20], B[20][20];
float f(float x) {
    return a*x*x*x*x*x+b*x*x*x*x+c*x*x*x+d*x*x+e*x+g;
}
float h(float x){
    return 5*a*x*x*x*x+ 4*b*x*x*x+3*c*x*x+2*d*x+e;  
}

int main(int argc, char **argv)
{
    printf("_______________________NUMERIK ANALIZ MAKINESI_______________________\n");
    printf("1- GRAFIK YONTEMI\n");
    printf("2- BISECTION YONTEMI \n");
    printf("3- REGULA FALSE YONTEMI \n");
    printf("4- NEWTON RAPSON YONTEMI \n");
    printf("5- MATRIS INVERSI ALINMASI\n");
    printf("6- GAUSS- JORDAN ELEMINASYON\n");
    printf("7- TRAPEZ YONTEMI \n");
    printf("8- SIMPSON YONTEMI\n");
    printf("9- NUMERIK TUREV ALMA\n");
    printf("Kullanmak istediginiz yontemin numarasini giriniz: \n");
    scanf("%d", &num);
    if ((num==1) || (num==2) ||(num==3)||(num==4)){
        printf("Fonksiyonunuzun katsayilarini 5.den baslamak uzere bosluk birakarak giriniz: \n");
        printf("Uyari: Fonksiyon maksimum 5. dereceden secilebilir.\n");
        scanf("%f %f %f %f %f %f", &a, &b, &c, &d, &e, &g);
        printf("Epsilon degerini giriniz: \n");
        scanf("%f", &ep);
    }
     if ((num==3) || (num==2)){
        printf("x1 degerini giriniz: \n");
        scanf("%f", &x1);
        printf("x2 degerini giriniz: \n");
        scanf("%f", &x2);
     }
      if ((num==7) || (num==8)){
        printf("Fonksiyonunuzun katsayilarini 5.den baslamak uzere bosluk birakarak giriniz: \n");
        printf("Uyari: Fonksiyon maksimum 5. dereceden secilebilir.\n");
        scanf("%f %f %f %f %f %f", &a, &b, &c, &d, &e, &g);
        printf("Integralin sinirlarini once alt sinir olmak uzere bosluk birakarak giriniz: \n");
        scanf("%f %f", &x1, &x2);
        printf("n degerini giriniz: \n");
        scanf("%f", &ep);
        if (x1*x2 >=0){
        h1= (x2-x1)/ep;
        k1= ((x2-x1)/h1) -1;
        } else {
            h1= (0-x1)/ep;
            k1= ((0-x1)/h1)-1;
            h2= (x2-0)/ep;
            k2= ((x2-0)/h2)-1;
        }
      }
     
     if(num==1){ //grafik yontemi//
        printf("X icin baslangic degerini giriniz: \n");
        scanf("%f", &x1);
        printf("X icin degisim miktarini giriniz: \n");
        scanf("%f", &x2);
        x2 *=2;
        sayac=0;
    do {
        sayac++;
        x2 /=2;
        printf("\n");
        printf("%d. iterasyon: \n", sayac);
        printf("x= %f f(x)= %f\n", x1, f(x1));
        while( f(x1)<0 && f(x1+x2)<0){
        x1 +=x2;
        printf("x= %f f(x)= %f\n", x1, f(x1));
        }
    } while(x2>ep);
    printf("Not: fonksiyonunun pozitif degerleri yazdirilmadi\n");
    printf("Aranan kok bulundu= %.4f\n", x1+x2 );
    printf("Iterasyon sayisi= %d\n", sayac);
     } 
     else if (num==2) { //bisection//
     sayac=0;
    while( fabs(f((x1+x2)/2))>ep) {
        sayac++;
        printf("\n");
        printf("%d. iterasyon: \n", sayac);
        printf("a= %f f(a)= %f b= %f f(b)= %f c= %f f(c)= %f\n", x1, f(x1), x2, f(x2), (x1+x2)/2, f((x1+x2)/2) );
        if (f(x1)*f((x1+x2)/2)<0) {
            x2=(x1+x2)/2;
        } else {
            x1=(x1+x2)/2;
        }
    }
    sayac++;
    printf("\n");
    printf("%d. iterasyon: \n", sayac);
    printf("a= %f f(a)= %f b= %f f(b)= %f c= %f f(c)= %f\n", x1, f(x1), x2, f(x2), (x1+x2)/2, f((x1+x2)/2) );
    printf("Aranan kok bulundu= %.4f\n", (x1+x2)/2);
    printf("Iterasyon sayisi= %d\n", sayac);
     }
     else if(num==3){ //regula falsi//
       sayac=0;
    while( fabs(f((x2*f(x1)-x1*f(x2))/(f(x1)-f(x2))))>ep) {
        sayac++;
        printf("%d. iterasyon: \n", sayac);
        printf("\n");
        printf("a= %f f(a)= %f b= %f f(b)= %f c= %f f(c)= %f\n", x1, f(x1), x2, f(x2), (x2*f(x1)-x1*f(x2))/(f(x1)-f(x2)), f((x2*f(x1)-x1*f(x2))/(f(x1)-f(x2))));
        if (f(x1)*f((x2*f(x1)-x1*f(x2))/(f(x1)-f(x2)))<=0) {
            x2=(x2*f(x1)-x1*f(x2))/(f(x1)-f(x2));
        } else {
            x1=(x2*f(x1)-x1*f(x2))/(f(x1)-f(x2));
        }}
  sayac++;
  printf("\n");
  printf("%d. iterasyon: \n", sayac);
  printf("a= %f f(a)= %f b= %f f(b)= %f c= %f f(c)= %f\n", x1, f(x1), x2, f(x2), (x2*f(x1)-x1*f(x2))/(f(x1)-f(x2)), f((x2*f(x1)-x1*f(x2))/(f(x1)-f(x2)) ));
  printf("Aranan kok bulundu= %.4f\n", (x2*f(x1)-x1*f(x2))/(f(x1)-f(x2)));
  printf("Iterasyon sayisi= %d\n", sayac);
}
else if(num==4){ //newton raphson//
    printf("x1 degerini giriniz: \n");
    scanf("%f", &x1);
     sayac=0;
    while( fabs(f(x1)/h(x1))>ep) {
        sayac++;
        printf("\n");
        printf("Iterasyon sayisi= %d\n", sayac);
        printf("xk= %f xk+1= %f xk+1-xk= %f\n", x1,x1-f(x1)/h(x1) ,f(x1)/h(x1) );
        x1=x1-(f(x1)/h(x1));
    }
    sayac++;
    printf("\n");
    printf("Iterasyon sayisi= %d\n", sayac);
    printf("xk= %.5f xk+1= %.5f xk+1-xk= %.5f\n", x1, x1-f(x1)/h(x1), f(x1)/h(x1) );
    printf("Aranan kok bulundu = %.5f\n", x1-(f(x1)/h(x1)) );
    printf("Iterasyon sayisi= %d\n", sayac);
    }
    else if(num==5){ //matris inversi//
    printf("Matrisinizin boyutunu giriniz: \n");
    scanf("%d", &k1);
     for(i=0; i<k1; i++) {
        for(j=0; j<k1; j++){
        printf("Matrisinizin %d. satir ve %d. sutun elemaninini giriniz: \n", i+1, j+1);
         scanf("%f", &A[i][j]);
     }}
     for(i=0; i<k1; i++) { //birim matris//
        for(j=0; j<k1; j++){
            if (i==j) {
             B[i][j]=1;
         } else {
             B[i][j]=0;
             }}}
       for(i=0; i<k1; i++) {
    h1= A[i][i];
     for(j=0; j<k1; j++){
        A[i][j]= A[i][j] / h1;
         B[i][j] = B[i][j] / h1;
     }
     for(j=0; j<k1; j++) {
         if (j != i) {
             h2=A[j][i];
             for (k=0; k<k1; k++) {
                 A[j][k] =A[j][k]-(A[i][k]*h2);
                 B[j][k] =  B[j][k]-(B[i][k]*h2);
             }}}}
     for(i=0; i<k1; i++)  {
        for(j=0; j<k1; j++) {
         printf( "%.4f ", B[i][j]);
     }
     printf("\n");
 }} else if(num==6){ //gauss- jordan//
  printf("Matrisinizin boyutunu giriniz: \n");
  scanf("%d", &k1);
  printf("Katsayilar matrisini giriniz: \n");
  for(i=0; i<k1; i++) {
        for(j=0; j<k1; j++){
         scanf("%f", &A[i][j]);
     }}
  printf("Sonuc matrisini giriniz: \n");
    for(i=0; i<k1; i++) {
        scanf("%f", &B[i][1]);
    }
   for(i=0; i<k1; i++) {
        for(j=i; j<k1; j++){
         m= A[j][i];
         B[j][1]=B[j][1]/m;
         for(k=0; k<k1; k++){ //satir elemanlara bolunuyor//
            A[j][k]=A[j][k]/m;
         }
        if( (j!=i) && ((j!=k1) && (i!=k1)) ){ //satir cikarmasi yapilacaksa yapiliyor//
         B[j][1]=B[j][1]-B[i][1];
         for(k=0; k<k1; k++){
         A[j][k]=A[j][k]-A[i][k];  }  
     }}}
        for(i=k1-1; i>0; i--){
         m=A[i][i];
         for(j=0 ; j<i; j++){ //gauss jordan yontemi uygulamalari//
            h1=A[j][i]; 
            B[j][1]=B[j][1]-B[i][1]*h1;
            A[j][i]=A[j][i]-A[j][i]*m; 
         }
     }
    for(i=0; i<k1; i++){
         printf("X%d = %.5f\n", i+1, B[i][1]);
     }    
 }
    else if(num==7){ //TRAPEZ//
        if (x1*x2>=0){
            top2=0;
            m=x1;
             if(f(x1)>=0){
                    printf("x= %f f(x)= %f\n", x1, f(x1));
            } else {
                    printf("x= %f f(x)= %f\n", x1, -f(x1));  
            }
            for(i=0;i<k1;i++){
                m=m+h1;
             if(top1*f(m)>=0){
                    top1= top1+ f(m);
             }
             else {
                    top1= top1- f(m);    
             }
             if(f(m)>=0){
                    printf("x= %f f(x)= %f\n", m, f(m));
            } else {
                    printf("x= %f f(x)= %f\n", m, -f(m));  
            }
            }
             if(f(x2)>=0){
                    printf("x= %f f(x)= %f\n" ,x2, f(x2));
            } else {
                    printf("x= %f f(x)= %f\n", x2, -f(x2));  
            }
          if(top1*f(x1)>=0){
                    top1= top1+ f(x1)/2;
             }
             else {
                    top1= top1- f(x1)/2;    
             }
              if(top1*f(x2)>=0){
                    top1= top1+ f(x2)/2;
             }
             else {
                    top1= top1- f(x2)/2;    
             }
                    top1=top1*h1;
            if(top1<0){
                    top1=top1*-1;
            }
            } else{ //araligin negatif ve pozitif deger icerdigi durum//
            m=x1; //negatif bolge//
             if(f(x1)>=0){
                    printf("x= %f f(x)= %f\n", x1, f(x1));
            } else {
                    printf("x= %f f(x)= %f\n", x1, -f(x1));  
            }
             for(i=0; i<k1;i++){
             m=m+h1;
             if(top1*f(m)>=0){
                    top1= top1+ f(m);
             }
             else {
                    top1= top1- f(m);    
             }
              if(f(m)>=0){
                    printf("x= %f f(x)= %f\n", m, f(m));
            } else {
                    printf("x= %f f(x)= %f\n", m, -f(m));  
            }
            }
              if(f(0)>=0){
                    printf("x= 0 f(x)= %f\n", f(0));
            } else {
                    printf("x= 0 f(x)= %f\n", -f(0));  
            }
              if(top1*f(x1)>=0){
                    top1= top1+ f(x1)/2;
             }
             else {
                    top1= top1- f(x1)/2;    
             }
              if(top1*f(0)>=0){
                    top1= top1+ f(0)/2;
             }
             else {
                    top1= top1- f(0)/2;    
             }
             top1=top1*h1;
            if(top1<0){
                    top1=top1*-1;
            }
             m=0; //pozitif bolge//
             printf("\n");
              if(f(0)>=0){
                    printf("x= 0 f(x)= %f\n", f(0));
            } else {
                    printf("x= 0 f(x)= %f\n", -f(0));  
            }
             for(i=0;i<k2 ;i++){
                    m=m+h2;
              if(top2*f(m)>=0){
                    top2= top2+ f(m);
             }
             else {
                    top2= top2- f(m);    
             }
              if(f(m)>=0){
                    printf("x= %f f(x)= %f\n", m, f(m));
            } else {
                    printf("x= %f f(x)= %f\n", m, -f(m));  
            }
            }
             if(f(x2)>=0){
                    printf("x= %f f(x)= %f\n", x2, f(x2));
            } else {
                    printf("x= %f f(x)= %f\n", x2, -f(x2));  
            }
             if(top2*f(x2)>=0){
                    top2= top2+ f(x2)/2;
             }
             else {
                    top2= top2- f(x2)/2;    
             }
              if(top2*f(0)>=0){
                    top2= top2+ f(0)/2;
             }
             else {
                    top2= top2- f(0)/2;    
             }
             top2=top2*h2;
            if(top2<0){
                    top2=top2*-1;
            }
             }
             printf("Toplam alan= %.4f\n", top1+top2);
    }
    else if (num==8) {                              //SIMPSON//
        if(x1*x2>=0){
            top2=0;
            m=x1;
             if(f(x1)>=0){
                    printf("x= %f f(x)= %f\n", x1, f(x1));
            } else {
                    printf("x= %f f(x)= %f\n", x1, -f(x1));  
            }
            for(i=0; i<k1; i++){
                m=m+h1;
             if(top1*f(m)>=0){  
                if ((i+1)%2==0) {
                    top1= top1+2*f(m);
                } else {
                    top1= top1+ 4*f(m);
            }} else {
              if ((i+1)%2==0) {
                    top1= top1 -2*f(m);
                } else {
                    top1= top1- 4*f(m);  
                }
            }
            if(f(m)>=0){
                    printf("x= %f f(x)= %f\n", m, f(m));
            } else {
                    printf("x= %f f(x)= %f\n", m, -f(m));  
            }
            }
             if(f(x2)>=0){
                    printf("x= %f f(x)= %f\n", x2, f(x2));
            } else {
                    printf("x= %f f(x)= %f\n", x2, -f(x2));  
            }
            if(top1*f(x1)>=0){
                    top1= top1+ f(x1);
             }
             else {
                    top1= top1- f(x1);    
             }
              if(top1*f(x2)>=0){
                    top1= top1+ f(x2);
             }
             else {
                    top1= top1- f(x2);    
             }
                if(top1<0){
                    top1=top1*-1*h1/3;
                } else {
                    top1= top1* h1/3;
                }
        } else { //egrinin bir kismi x ekseninin negatif bolgesinde bir kismi pozitif bolgesinde//
            m=x1;
             if(f(x1)>=0){
                    printf("x= %f f(x)= %f\n", x1, f(x1));
            } else {
                    printf("x= %f f(x)= %f\n", x1, -f(x1));  
            }
            
            for(i=0; i<k1; i++){
                m=m+h1;
                if(top1*f(m)>=0){  
                if ((i+1)%2==0) {
                    top1= top1+2*f(m);
                } else {
                    top1= top1+ 4*f(m);
            }} else {
              if ((i+1)%2==0) {
                    top1= top1 -2*f(m);
                } else {
                    top1= top1- 4*f(m);  
            }
            }
            if(f(m)>=0){
                    printf("x= %f f(x)= %f\n", m, f(m));
            } else {
                    printf("x= %f f(x)= %f\n", m, -f(m));  
            }
            }
              if(f(0)>=0){
                    printf("x= 0 f(x)= %f\n", f(0));
            } else {
                    printf("x= 0 f(x)= %f\n", -f(0));  
            }
            
           if(top1*f(x1)>=0){
                    top1= top1+ f(x1);
             }
             else {
                    top1= top1- f(x1);    
             }
              if(top1*f(0)>=0){
                    top1= top1+ f(0);
             }
             else {
                    top1= top1- f(0);    
             }
                if(top1<0){
                    top1=top1*-1*h1/3;
                } else {
                    top1= top1* h1/3;
                }
            m=0; //x in pozitif degerleri//
            printf("\n");
             if(f(0)>=0){
                    printf("x= 0 f(x)= %f\n", f(0));
            } else {
                    printf("x= 0 f(x)= %f\n", -f(0));  
            }
            for(i=0; i<k2; i++){
            m=m+h2;
             if(top2*f(m)>=0){  
                if ((i+1)%2==0) {
                    top2= top2+2*f(m);
                } else {
                    top2= top2+ 4*f(m);
            }} else {
              if ((i+1)%2==0) {
                    top2= top2 -2*f(m);
                } else {
                    top2= top2- 4*f(m);  
            }
            }
            if(f(m)>=0){
                    printf("x= %f f(x)= %f\n", m, f(m));
            } else {
                    printf("x= %f f(x)= %f\n", m, -f(m));  
            }
           }
            if(f(x2)>=0){
                    printf("x= %f f(x)= %f\n", x2, f(x2));
            } else {
                    printf("x= %f f(x)= %f\n", x2, -f(x2));  
            }
            if(top2*f(x2)>=0){
                    top2= top2+ f(x2);
             }
             else {
                    top2= top2- f(x2);    
             }
              if(top2*f(0)>=0){
                    top2= top2+ f(0);
             }
             else {
                    top2= top2- f(0);    
             }
                if(top2<0){
                    top2=top2*-1*h1/3;
                } else {
                    top2= top2* h1/3;
            }
        }
        printf("Egrinin altinda kalan alan= %.4f\n", top1+top2);
    }
     if (num==9){
        printf("Fonksiyonunuzun katsayilarini 5.den baslamak uzere bosluk birakarak giriniz: \n");
        printf("Uyari: Fonksiyon maksimum 5. dereceden secilebilir.\n");
        scanf("%f %f %f %f %f %f", &a, &b, &c, &d, &e, &g);
        printf("Degisim miktarini (delta x) giriniz: \n");
        scanf("%f", &x1);
        printf("x in baslangic degerini giriniz: \n");
        scanf("%f", &x2);
        h1= (f(x2+x1)-f(x2))/x1;
        h2= (f(x2)-f(x2-x1))/x1;
        printf("Ileri fark turev= %.4f\n", h1);
        printf("Geri fark turev= %.4f\n", h2);
        printf("Merkezi fark turev= %.4f\n", (h1+h2)/2);
        }
   system("PAUSE");
    return 0;
}


