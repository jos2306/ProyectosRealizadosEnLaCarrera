clear all
close all
clc

%Patrones de entrenamiento
E1 = imread('patron2.png');
E(:,:,1) = [E1];



v1=1;
v2=1;
ax=0;
figure(1) 
imshow(E)
for i=1:10
    for a=1:35
        for b=1:35
        r(v1,v2)=E((a+ax),b,1);
        v2=v2+1;                      
        end 
    end
    v2=1;
    v1=v1+1;
    ax=ax+35;
end

for i=1:10
    for a=1:1225
if r(i,a) == 0
    Patron(i,a) = -1; 
else
    Patron(i,a) = 1;
end
    end
end

Patron=imnoise(Patron,'salt & pepper',0.6);

for i=1:10
ima=Patron(i,:);
ima2=reshape(ima,35,35);
ima2=ima2.';
meanI = mean(ima2(:));
ima2 = ima2 > meanI;
figure
imshow(ima2);
end

%Matriz de salida
salida=[1 1 1 1 1 1 1 1 1 1; 
        1 1 1 1 1 1 1 1 1 -1; 
        1 1 1 1 1 1 1 1 -1 1; 
        1 1 1 1 1 1 1 -1 1 1; 
        1 1 1 1 1 1 -1 1 1 1; 
        1 1 1 1 1 -1 1 1 1 1;
        1 1 1 1 -1 1 1 1 1 1;
        1 1 1 -1 1 1 1 1 1 1;
        1 1 -1 1 1 1 1 1 1 1;
        1 -1 1 1 1 1 1 1 1 1;];
    

        
%Matriz de pesos aleatoria
W=randn(1226,10);

%ALfa variable
alfa=input('Valor de alfa:');
for i=1:1000 %iteraciones a realizar
    for j=1:10%Iteraciones para los 4 patrones
        X=[1,Patron(j,:)]; %Patrones de entrada
        U=X*W;  
        Y=hardlims(U); %funcion de transferencia
       
        e=salida(j,:)-Y;%error            
    if e~= salida(j,:)
         W=W+alfa*X'*e;
    end
    error(j)=(e*e');    %suma de errores al cuadrado
    end
    errort(i)=(sum(error))/10;
    if errort(i)< 0.005 %deberia ser alfa %error menor a epsilon  
        break %para cuando error es menor a epsilon
    end
end    



fprintf('N˙mero de iteración=%d\n',i);
%%Termino de entrenamiento
figure(15)
plot(errort)
%Prueba
count=0;
for j=1:10
    u=[1,Patron(j,:)]*W; %matriz optima para cada patron
    y=hardlims(u);   %funcion de transferencia
    fprintf('Patron %d  --> %d %d %d %d %d %d %d %d %d %d\n',j,y);
     if salida(j,:)==y %salida igual a funcion de transferencia
        count=count+1; 
    end 
end
fprintf('reconocimiento=%f',(count*100)/10);  