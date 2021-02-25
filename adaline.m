clear all
close all
clc


%Patrones de entrenamiento
Patron=[[2 1];
        [0 -1];
        [-2 1];
        [0 2];
       ];

%Matriz de salida
salida=[1; 1; -1; -1];


%Matriz de pesos aleatoria
W=randn(3,1)
%W=[0.5 -0.7 0.2]';


%ALfa variable
alfa=input('Valor de alfa:');


for i=1:200 %iteraciones a realizar
    for j=1:4%Iteraciones para los 4 patrones
        X=[1,Patron(j,:)]; %Patrones de entrada
        U=X*W;  
        %Y=hardlim(U); %funcion de transferencia
        e=salida(j,:)-U;%error
            
    %if e~=0 % error diferente a cero se adapta el nuevo vector
         W=W+alfa*X'*e;
    %end

    error(j)=(e*e');    %suma de errores al cuadrado 
    end
    errort(i)=(sum(error))/4; % error cuadrado
     
    if errort(i)< 0.25 %deberia ser alfa %error menor a epsilon  
        break %para cuando error es menor a epsilon
    end
end            
fprintf('N˙mero de iteración=%d\n',i);
%%Termino de entrenamiento

plot(errort)
%Prueba
count=0;
for j=1:4  
    u=[1,Patron(j,:)]*W; %matriz optima para cada patron
    y=hardlims(u);   %funcion de transferencia
    fprintf('Patron %d  --> %d %d %d %d %d %d %d %d %d %d\n',j,y);
     if salida(j,:)==y %salida igual a funcion de transferencia
        count=count+1; 
    end 
end
 
fprintf('reconocimiento=%f',(count*100)/4); 