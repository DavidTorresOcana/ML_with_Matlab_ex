%  This script modify the data of the ex6data2.mat to convert it to a
%  multiclass data

%% Initialization
clear ; close all; clc
load('ex6data2.mat');
for i=1:size(X,1)
    if X(i,1)>0.5 && y(i)==0
        y(i)=2;
    end
    if X(i,1)>0.9
        y(i)=1;
    end
    
end


y=[y;ones(200,1)];
X=[X;[randi([0*1000000,1000000],[200,1])/1000000,randi([0.3*1000000,0.4*1000000],[200,1])/1000000]];



