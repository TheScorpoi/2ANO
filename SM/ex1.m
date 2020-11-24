clear all

Ta = 0.001;
%%
%a) x(t) = 2sin(4*pi*t)

% Periodo = 1/2 s
% Frequência = 2 Hz
% Máximo = 2

t = 0:Ta:5;

x = 2*sin(4*pi*t);
plot(t,x)
xlabel ('t');
ylabel('amplitude');

%%
%b) y(t) = sin(10*pi*t + pi/2)
% Periodo = 1/5 s
% Frequência = 5 Hz
% Máximo = 2

y = sin(10*pi*t + pi/2);
plot(t,y)
xlabel ('t');
ylabel('amplitude');

%%
%c) z(t) = sin(6*pi*t) + sin(8*pi*t)

% Periodo = 1/12 s
% Frequência = 2 Hz
% Máximo = ??

%mmc de 1/3 e 1/4 = 1/12

z = sin(6*pi*t) + sin(8*pi*t);
plot(t,z)
xlabel ('t');
ylabel('amplitude')

%%
%d) w(t) = sin(6*pi*t) + sin(8*pi*t + 0.1)

% Periodo = 1/12 s
% Frequência = 2 Hz
% Máximo = 2

w = sin(6*pi*t) + sin(8*pi*t + 0.1);
plot(t,w)
xlabel ('t');
ylabel('amplitude')

%%
%e) q(t) = sin(6*pi*t) + sin(7*pi*t) + sin(8*pi*t)

%freq MDC entre 3, 7/2, 4 --> metemos tudo ao msm denominador ficamos com
% 6 , 7, 8 --> 2


%periodo mmc entre 3, 7/2, 4 --> ja ns como puta se faz isto pqp

% Periodo = 1/2 s
% Frequência = 2 Hz
% Máximo = 2

q = sin(6*pi*t) + sin(7*pi*t) + sin(8*pi*t);
Ta = 0.01;
T = 2;

a = ex3(1,Ta, T)

plot(t,q)
xlabel ('t');
ylabel('amplitude')