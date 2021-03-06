#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//EN ESTA SECCI�N DE CONSTRUYE LA CLASE
class Matriz{
      private:
              float *pA,*pB,*pC;
              int Nfilas1,Ncol1,Nfilas2,Ncol2;
      public:
             Matriz(float &_pA,float &_pB,float &_pC,int _Nfilas1,int _Ncol1,int _Nfilas2,int _Ncol2);
             void suma(float &_pA,float &_pB,float &_pC,int _Nfilas1,int _Ncol1);
             void transpuesta(float &_pA,float &_pC,int _Nfilas1,int _Ncol1);
             void producto(float &_pA,float &_pB,float &_pC,int _Nfilas1,int _Ncol1,int _Nfilas2,int _Ncol2);
             
             };
//EN ESTE PASO SE INICIALIZA LA CLASE             
Matriz::Matriz(float &_pA,float &_pB,float &_pC, int _Nfilas1,int _Ncol1,int _Nfilas2,int _Ncol2){
	
                       pA=&_pA;
                       pB=&_pB;
                       pC=&_pC;
                       Nfilas1=_Nfilas1;
                       Ncol1=_Ncol1;
                      Nfilas2=_Nfilas2;
                       Ncol2=_Ncol2;
                       };
                       
//SE PROCEDE A DEFINIR LOS M�TODOS INCLUIDOS EN LA CLASE MATRIZ

//METODO SUMA

void Matriz::suma(float &_pA,float &_pB, float &_pC,int _Nfilas1,int _Ncol1){
	
    int i,j;
    
	
	for (i=0;i<_Nfilas1;i++){
		
		for (j=0;j<_Ncol1;j++){	
			
			*(&_pC+i*_Ncol1+j)=*(&_pA+i*_Ncol1+j)+*(&_pB+i*_Ncol1+j); //Ac� se est� llenando las direcciones de memoria de la matriz C con la suma del
			//contenido de las matrices A y B.
		}
	}
    
	}
     
//METODO TRANSPUESTA

 void Matriz::transpuesta(float &_pA,float &_pC,int _Nfilas1,int _Ncol1){
     
	int i,j;
	
	for (i=0;i<_Ncol1;i++){
		
		for (j=0;j<_Nfilas1;j++){	
			
			*(&_pC+i*_Nfilas1+j)=*(&_pA+j*_Ncol1+i); //Ac� se est� llenando las direcciones de memoria de la matriz C con la suma del
			//contenido de las matrices A y B.
		}
	}
    
	}
     
//METODO PRODUCTO

 void Matriz::producto(float &_pA,float &_pB,float &_pC,int _Nfilas1,int _Ncol1,int _Nfilas2,int _Ncol2){
     int i,j,k;
	
	for (i=0;i<_Nfilas1;i++){
		for (j=0;j<_Ncol2;j++){
			
			*(&_pC+i*_Ncol2+j)=0;
			
			for (k=0;k<_Nfilas2;k++){
				
				*(&_pC+i*_Ncol2+j)=*(&_pC+i*_Ncol2+j)+*(&_pA+i*_Ncol1+k)*(*(&_pB+k*_Ncol2+j));
				
			}
		}
	}
    
	}
	
	
	
//PROGRAMA PRINCIPAL	
     
    int main(){
     	
    int i,j,_Nfilas1,_Ncol1,_Nfilas2,_Ncol2,Operacion;
    float *_pA, *_pB, *_pC;
	
	         
         //SE CREA EL OBJETO R DE CLASE "MATRIZ"
         
         
         Matriz R=Matriz(*_pA,*_pB,*_pC,_Nfilas1,_Ncol1,_Nfilas2,_Ncol2);
         
         //Y LUEGO SE PROCEDE A APLICAR LOS M�TODOS SOBRE EL OBJETO R
         
         printf("Seleccione la operacion a ejecutar: 1. A+B, 2. A*B, 3. AT \n");
         
         scanf("%i", &Operacion);
         
         
         switch(Operacion){
		 
         	
         	case 1:{
				
         		printf("ingrese el numero de filas y columnas de la matriz a sumar:\n");
				scanf("%i %i",&_Nfilas1,&_Ncol1);
				float A[_Nfilas1][_Ncol1],B[_Nfilas1][_Ncol1],C[_Nfilas1][_Ncol1];
				
				for (i=0;i<_Nfilas1;i++){
					for (j=0;j<_Ncol1;j++){
			
					printf("Ingrese A(%i,%i):\n",i+1,j+1);
					scanf("%f",&A[i][j]);
					}
				}
	
				for (i=0;i<_Nfilas1;i++){
					for (j=0;j<_Ncol1;j++){
			
					printf("Ingrese B(%i,%i):\n",i+1,j+1);
					scanf("%f",&B[i][j]);
					}
				}
				
				_pA=&A[0][0];
				_pB=&B[0][0];
				_pC=&C[0][0];
								
         		R.suma(*_pA,*_pB,*_pC,_Nfilas1,_Ncol1);
         		
         		for (i=0;i<_Nfilas1;i++){
				 for (j=0;j<_Ncol1;j++){
			
	 				printf("C(%i,%i)=%f \n",i+1,j+1,C[i][j]);
	 			}
	 		}
	 		
			 break;
		}
	 		
	 		
	 		case 2:{
				
	 			printf("ingrese el numero de filas y columnas de la matriz A:\n");
				scanf("%i %i",&_Nfilas1,&_Ncol1);
				printf("ingrese el numero de filas y columnas de la matriz B:\n");
				scanf("%i %i",&_Nfilas2,&_Ncol2);
				
	 			float A[_Nfilas1][_Ncol1],B[_Nfilas2][_Ncol2],C[_Nfilas1][_Ncol2];
	 			
	 			for (i=0;i<_Nfilas1;i++){
					for (j=0;j<_Ncol1;j++){
			
					printf("Ingrese A(%i,%i):\n",i+1,j+1);
					scanf("%f",&A[i][j]);
					}
				}
	
				for (i=0;i<_Nfilas2;i++){
					for (j=0;j<_Ncol2;j++){
			
					printf("Ingrese B(%i,%i):\n",i+1,j+1);
					scanf("%f",&B[i][j]);
					}
				}
				
				_pA=&A[0][0];
				_pB=&B[0][0];
				_pC=&C[0][0];
				
	 			R.producto(*_pA,*_pB,*_pC,_Nfilas1,_Ncol1,_Nfilas2,_Ncol2);
         		
         		for (i=0;i<_Nfilas1;i++){
				 for (j=0;j<_Ncol2;j++){
			
	 				printf("C(%i,%i)=%f \n",i+1,j+1,C[i][j]);
	 			}
	 		}
	 		
	 		break;
	 	}
	 
	 	 				
	 		case 3:{
	 			
				printf("ingrese el numero de filas y columnas de la matriz A:\n");
				scanf("%i %i",&_Nfilas1,&_Ncol1);
								
	 			float A[_Nfilas1][_Ncol1],C[_Ncol1][_Nfilas1];
	 			
	 			for (i=0;i<_Nfilas1;i++){
					for (j=0;j<_Ncol1;j++){
			
					printf("Ingrese A(%i,%i):\n",i+1,j+1);
					scanf("%f",&A[i][j]);
					}
				}
	 			
	 			_pA=&A[0][0];
				_pC=&C[0][0];
	 			
	 			R.transpuesta(*_pA,*_pC,_Nfilas1,_Ncol1);
         		
         		for (i=0;i<_Ncol1;i++){
				 for (j=0;j<_Nfilas1;j++){
			
	 				printf("C(%i,%i)=%f \n",i+1,j+1,C[i][j]);
	 			}
	 		}
	 		
	 		break;
	 	}
	 	
	 }
	 			
        system("pause");
			
	}
         
         
         
        
         
             
