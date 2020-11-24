%%Guião 2 
%
%Ex1  (A parte de juntar os graficos todos fui ver ao DS)

clear all
figure(1);

%% a)

T = 1/2; % Periodo
Ta = 5 * T/1000;
t = 0:Ta:(5*T-Ta);

subplot(3,2,1);

x = 2*sin(4*pi*t);

plot(t,x)
maxX = max(x(:))

title ('Alinea A)');
xlabel ('t');
ylabel('Amplitude');



%% b)

T = 1/5;
Ta = 5 *T/1000;
t = 0:Ta:(5*T-Ta);

subplot(3,2,2);

y = sin(10*pi*t + pi/2);

maxY = max(y(:))   %para saber o máximo da função

plot(t,y)

title ('Alinea B)');
xlabel ('t');
ylabel('Amplitude');

%% c)
subplot(3,2,3);

z = sin(6*pi*t) + sin(8*pi*t);

plot(t,z);

maxZ = max(z(:))

xlabel('t');
ylabel('amplitude');
title('Aliena C)');



%% d)

subplot(3,2,4);

w = sin(6*pi*t) + sin(8*pi*t + 0.1);

plot(t,w);

maxW = max(w(:))

xlabel('t');
ylabel('Amplitude');
title('Alinea C'); 

%% e)

subplot(3,2,[5,6])

q = sin(6*pi*t) + sin(7*pi*t) + sin(8*pi*t);

plot(t,q);

maxQ = max(q(:))

xlabel('t');
ylabel('Amplitude');
title('Alinea E');

