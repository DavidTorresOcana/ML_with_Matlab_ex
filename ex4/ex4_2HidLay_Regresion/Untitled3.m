p = [0 1 2 3 4 5 6 7 8];
t = [0 0.84 0.91 0.14 -0.77 -0.96 -0.28 0.66 0.99];
plot(p,t,'o')
pause
net = feedforwardnet(20);
net = configure(net,p,t);
y1 = net(p)
plot(p,t,'o',p,y1,'x')

net = train(net,p,t);
y2 = net(p)
plot(p,t,'o',p,y1,'x',p,y2,'*')