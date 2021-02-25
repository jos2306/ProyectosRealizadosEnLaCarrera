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

%Patron=imnoise(Patron,'salt & pepper',0.8);

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
salida=[0;
        1; 
        2; 
        3; 
        4;  
        5;
        6;
        7;
        8;
        9;]
%  salida=[1 1 1 1 1 1 1 1 1 1; 
%        1 1 1 1 1 1 1 1 1 -1; 
%        1 1 1 1 1 1 1 1 -1 1; 
%        1 1 1 1 1 1 1 -1 1 1; 
%        1 1 1 1 1 1 -1 1 1 1; 
%        1 1 1 1 1 -1 1 1 1 1;
%        1 1 1 1 -1 1 1 1 1 1;
%       1 1 1 -1 1 1 1 1 1 1;
%        1 1 -1 1 1 1 1 1 1 1;
%        1 -1 1 1 1 1 1 1 1 1;];

        
%Matriz de pesos aleatoria
W=randn(1226,1);

%ALfa variable
alfa=input('Valor de alfa:');
for i=1:2000 %iteraciones a realizar
    for j=1:10%Iteraciones para los 4 patrones
        X=[1,Patron(j,:)]; %Patrones de entrada
        U=X*W;  
        %Y=hardlims(U); %funcion de transferencia
       
        e=salida(j,:)-U;%error            
    %if e~= salida(j,:)
         W=W+alfa*X'*e;
    %end
    error(j)=(e*e');    %suma de errores al cuadrado
    end
    errort(i)=(sum(error))/10;
    errort(i);
    if errort(i)< 0.09; %deberia ser alfa %error menor a epsilon  
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
    y=u ;  %funcion de transferencia
    %y=hardlims(u);
        if y <0.5
        y=0;
        else
        if y <1.5
        y=1;
        else
        if y <2.5
        y=2;
        else
        if y <3.5
        y=3;
        else
        if y <4.5
        y=4;
        else
        if y <5.5
        y=5;
        else
        if y <6.5
        y=6;
        else
        if y <7.5
        y=7;
        else
        if y <8.5
        y=8;
        else
        if y <9.5
        y=9;
        else
        end
        end
        end
        end
        end
        end
        end
        end
        end
        end
         
    fprintf('Patron %d  --> %d \n %d \n %d \n %d \n %d \n %d \n %d \n %d \n %d %d \n',j,y);
     if salida(j,:)==y %salida igual a funcion de transferencia
        count=count+1; 
    end 
end
fprintf('reconocimiento=%f',(count*100)/10);