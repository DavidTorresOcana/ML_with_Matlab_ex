function p = predict(Theta1, Theta2, X)
%PREDICT Predict the label of an input given a trained neural network
%   p = PREDICT(Theta1, Theta2, X) outputs the predicted label of X given the
%   trained weights of a neural network (Theta1, Theta2)

% Useful values
m = size(X, 1);
num_labels = size(Theta2, 1);
num_layers=3;
% You need to return the following variables correctly 
p = zeros(size(X, 1), 1);

% ====================== YOUR CODE HERE ======================
% Instructions: Complete the following code to make predictions using
%               your learned neural network. You should set p to a 
%               vector containing labels between 1 to num_labels.
%
% Hint: The max function might come in useful. In particular, the max
%       function can also return the index of the max element, for more
%       information see 'help max'. If your examples are in rows, then, you
%       can use max(A, [], 2) to obtain the max for each row.
%
X = [ones(m, 1),X];

for i=1:m
    a2=[1 ;  sigmoid(Theta1*X(i,:)')];
    a3=sigmoid(Theta2*a2);
    [c(i),p(i)]=max(a3);

end




% % % % % % % Theta(:,:,1)=Theta1;
% % % % % % % Theta(:,:,2)=zeros(size(Theta(:,:,1)));
% % % % % % % Theta(1:size(Theta2,1),1:size(Theta2,2),2)=Theta2;
% % % % % % % 
% % % % % % %     for i=1:m   % Evaluate each data of the set
% % % % % % %         
% % % % % % %         for layer=1:num_layers-1  %Propoagacion hacia delante
% % % % % % %             if layer==1
% % % % % % % 
% % % % % % %                 a(layer+1)=[1 ;  sigmoid(Theta(:,:,layer)*X(i,:)')];
% % % % % % %             end
% % % % % % %             
% % % % % % %             if layer>=num_layers-1
% % % % % % %                 a(layer+1)=sigmoid(Theta(:,:,layer)*a(layer));
% % % % % % %             else
% % % % % % %                 a(layer+1)=[1 ;  sigmoid(Theta(:,:,layer)*a(layer))];
% % % % % % %             end
% % % % % % %         end
% % % % % % %         
% % % % % % %         [c(i),p(i)]=max( a(num_layers) );
% % % % % % %         
% % % % % % %     end







% =========================================================================


end
