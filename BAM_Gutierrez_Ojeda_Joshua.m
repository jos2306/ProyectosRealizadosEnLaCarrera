%%%Red BAM
clc;
close all;
clear all;
patronesA=input('Escriba el numero de Patrones de netrada: ');
entradA=input('Escriba el numero de neuronas de entrada: ');
ea=ones(entradA);
ea=ea(1:patronesA,1:entradA);
for i=1:patronesA
    while true
        fprintf('Escriba el vector del patron A%d:',i);%%[1,1,...,n]
        entAux= input('');
        tamA=length(entAux);
        if tamA==entradA
            ea(i,:)=entAux;
            break;
        end
        fprintf('El vector de entrada debe ser una cadena de %d neuronas:',entradA);
    end
end
entradB=input(' Escriba el numero de nueronas de salida de la red: ');
eb=ones(entradB);
eb=eb(1:patronesA,1:entradB);
for i=1:patronesA
    while true
        fprintf('Escriba el vector de salida B%d :',i)
        entBux= input(' ');
        tamb=length(entBux);
        if tamb==entradB
            eb(i,:)=entBux;
            break;
        end
        fprintf('El vector de salida debe ser una cadena de %d neuronas:',entradB)
    end
end
W=zeros(entradA,entradB);
for j=1:entradA
    for i=1:entradB
        for h=1:patronesA
               W(j,i)= ea(h,j) *  eb(h,i) +W(j,i)
        
        end
    end
end
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%if entradA==entradB
%    W=W;
%    else
%    W=W.'
%end
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
ronda=1;
 while ronda==1     
  auxdew=W; 
  fprintf(' Escriba el patron de prueba de entrada: ')   
  prueba=input(''); 
  tamA=length(prueba);
  pruebaaux(1,:)=prueba; 
  if tamA==entradA
      W = ( W.' * pruebaaux.' )  
  else 
      W = ( pruebaaux * W.' ) 
      W = W.'
  end
tamB=length(W);
for i=1:tamB
       if  W(i,1) >= 0
           W(i,1) = 1; 
       else
         W(i,1) = -1;
        end
end
W=W.'
 if entradB == tamB 
      for n=1:entradA
          if W == eb(n,:)
          fprintf(' El vector de entrada asocia con la salida y %d \n',n)  
          break;
          else
               if n == entradA
               fprintf(' El vector de entrada no asocia con ninguna salida y \n')
               end
          end
      end
 else
for e=1:entradA
    if W == ea(e,:)
    fprintf(' El vector de entrada asocia con la salida B%d \n',e)  
    break;
    else
        if e == entradA
            fprintf(' El vector de entrada no asocia con ninguna salida B \n')
        end
    end
end
end
pruebaaux = [];
W=auxdew;
 ronda=input('\n ¿Desea probar un nuevo patron? si= 1, No = 0 : ');
 end