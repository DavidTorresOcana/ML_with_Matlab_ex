function [J,grad] = nnCostFunction(nn_params, ...
                                   input_layer_size, ...
                                   hidden_layer_size, ...
                                   num_labels, ...
                                   X, y, lambda)
%NNCOSTFUNCTION Implements the neural network cost function for a two layer
%neural network which performs classification
%   [J grad] = NNCOSTFUNCTON(nn_params, hidden_layer_size, num_labels, ...
%   X, y, lambda) computes the cost and gradient of the neural network. The
%   parameters for the neural network are "unrolled" into the vector
%   nn_params and need to be converted back into the weight matrices. 
% 
%   The returned parameter grad should be a "unrolled" vector of the
%   partial derivatives of the neural network.
%

% Reshape nn_params back into the parameters Theta1 and Theta2, the weight matrices
% for our 2 layer neural network
Theta1 = reshape(nn_params(1:hidden_layer_size * (input_layer_size + 1)), ...
                 hidden_layer_size, (input_layer_size + 1));

Theta2 = reshape(nn_params((1 + (hidden_layer_size * (input_layer_size + 1))):( (hidden_layer_size * (input_layer_size + 1))) + hidden_layer_size*(hidden_layer_size+1)  ), ...
                 hidden_layer_size, (hidden_layer_size + 1));

Theta3 = reshape(nn_params(( 1 + (hidden_layer_size * (input_layer_size + 1)))+hidden_layer_size*(hidden_layer_size+1):end  ), ...
                 num_labels, (hidden_layer_size + 1));
             

% Setup some useful variables
m = size(X, 1);
         
% You need to return the following variables correctly 

    X=[ones(m,1),X];
    for c=1:num_labels
        y2(:,c)=(y==c);
    end
    y=y2;
    Delta1=zeros(size(Theta1));
    Delta2=zeros(size(Theta2));
    Delta3=zeros(size(Theta3));

    for i=1:m
        % Forward
        a1=X(i,:)';
        z2=Theta1*a1;
        a2=[1 ;  sigmoid(z2)];
        z3=Theta2*a2;
        a3=[1 ;  sigmoid(z3)];
        z4=Theta3*a3;
        a4(:,i)=sigmoid(z4);
       
       % Backward
        delta4=a4(:,i) - y(i,:)';
        delta3=Theta3'*delta4.*(a3.*(ones(size(a3))-a3));
        delta2=Theta2'*delta3(2:end).*(a2.*(ones(size(a2))-a2)); % No tiene sentido la primera diferencia pues es la diferencia con 1
        Delta1=Delta1+delta2(2:end)*a1'; % No tiene sentido la primera diferencia pues es la diferencia con 1
        Delta2=Delta2+delta3(2:end)*a2'; % No tiene sentido la primera diferencia pues es la diferencia con 1
        Delta3=Delta3+delta4*a3';

    end 

    J = -1/m*( sum( sum(y.*log( a4' )) )  + sum( sum(( ones(size(y))-y ).*log(ones(size(a4'))-a4') ) )   )   + lambda/(2*m)*( sum(sum(Theta1(:,2:end).^2 )) + sum(sum(Theta2(:,2:end).^2 ))+sum(sum(Theta3(:,2:end).^2 ))   );

    
    Theta1_grad=zeros(size(Theta1));
    Theta2_grad=zeros(size(Theta2));
    Theta3_grad=zeros(size(Theta3));
    Theta1_grad =  1/m*Delta1 ;
    Theta1_grad(:,2:end) = Theta1_grad(:,2:end)+ lambda/m*Theta1(:,2:end);
    Theta2_grad =  1/m*Delta2 ;
    Theta2_grad(:,2:end) = Theta2_grad(:,2:end)+ lambda/m*Theta2(:,2:end);
    Theta3_grad =  1/m*Delta3 ;
    Theta3_grad(:,2:end) = Theta3_grad(:,2:end)+ lambda/m*Theta3(:,2:end);
%     Theta1_grad(:,2:end) =  1/m*Delta1(:,2:end) + lambda/m*Theta1(:,2:end) ;
%     Theta1_grad(:,1) =  1/m*Delta1(:,1);
%     Theta2_grad(:,2:end) =  1/m*Delta2(:,2:end) + lambda/m*Theta2(:,2:end);
%     Theta2_grad(:,1) =  1/m*Delta2(:,1);
    

    % Unroll gradients
    grad = [Theta1_grad(:) ; Theta2_grad(:);Theta3_grad(:)];
    
    
% %     J=-1/m*sum(sum(  y.*log( sigmoid([ones(m,1) ,sigmoid(X*Theta1')]*Theta2') ) +(ones(size(y))-y).*log( ones(size(sigmoid([ones(m,1) ,sigmoid(X*Theta1')]*Theta2'))) -sigmoid([ones(m,1) ,sigmoid(X*Theta1')]*Theta2'))  ))+...
% %         lambda/(2*m)*( sum(sum(Theta1(:,2:end).^2 )) + sum(sum(Theta2(:,2:end).^2 ))   );

% % % % %     sum=0;
% % % % %     for i=1:m
% % % % %         for k=1:num_labels
% % % % %             sum=sum  + y(i,k)*log( a3(k) )  +( 1-y(i,k) )*log(1-a3(k));       
% % % % %             
% % % % %             
% % % % %         end
% % % % %     end
% % % % %     J = -1/m*sum + lambda/(2*m)*( sum(sum(Theta1(:,2:end).^2 )) + sum(sum(Theta2(:,2:end).^2 ))   );


  

% ====================== YOUR CODE HERE ======================
% Instructions: You should complete the code by working through the
%               following parts.
%
% Part 1: Feedforward the neural network and return the cost in the
%         variable J. After implementing Part 1, you can verify that your
%         cost function computation is correct by verifying the cost
%         computed in ex4.m
%
% Part 2: Implement the backpropagation algorithm to compute the gradients
%         Theta1_grad and Theta2_grad. You should return the partial derivatives of
%         the cost function with respect to Theta1 and Theta2 in Theta1_grad and
%         Theta2_grad, respectively. After implementing Part 2, you can check
%         that your implementation is correct by running checkNNGradients
%
%         Note: The vector y passed into the function is a vector of labels
%               containing values from 1..K. You need to map this vector into a 
%               binary vector of 1's and 0's to be used with the neural network
%               cost function.
%
%         Hint: We recommend implementing backpropagation using a for-loop
%               over the training examples if you are implementing it for the 
%               first time.
%
% Part 3: Implement regularization with the cost function and gradients.
%
%         Hint: You can implement this around the code for
%               backpropagation. That is, you can compute the gradients for
%               the regularization separately and then add them to Theta1_grad
%               and Theta2_grad from Part 2.
%


% -------------------------------------------------------------

% =========================================================================




end
