#include<stdio.h>
#include<math.h>
void main()
{
	double
		Ma0, h, k, R, kg, B, Cp, Cpg, Rg, Ci, Mlpc, Mmpc, Mhpc, Mmp, Nb, Cb, Hu, Z1, Z2, Z3, L,Nhpt, Nmpt, Nlpt, Nhpm , Nmpm, Nlpm, Cto, Cm, Cmm, Plpc, Pmpc, Phpc, Tem40, Ce;
	double
		f, Temo, Preo, a0, c0, Preo0, Temo0, Pre20, Tem20, Pre220, Tem220, Wlpc=0, Pre240, Tem240, Wmpc, Pre30, Tem30, Whpc, Pre40, WB1, Pre4a0, Tem4a0, WB2, Tem420, Uhpt, Pre420, WB3, Pre4b0, Tem4b0, WB4, Tem430, Umpt, Pre430, WB5, Tem4c0, Pre4c0, WB6, Tem50, Ulpt, Pre50, Bm, Cp6, Prem, WB7, Tem60, Pre60, Pre80, Tem80, Ma8, Tem8, Pre8, a8, C8, Fs, sfc;
	Ma0 = 0.5, h =10.67, k = 1.40, R = 287.30, kg = 1.200, B = 4.35, Cp = 1.005, Cpg = 1.80, Rg = 308.66, Ci = 0.94, Mlpc = 0.89, Mmpc = 0.90, Mhpc = 0.90, Mmp = 0.99, Nb = 0.95, Cb = 0.99, Hu = 42000, Z1 = 0.05, Z2 = 0.05, Z3 = 0.05, L= 0.02, Nhpt = 0.89, Nmpt = 0.89, Nlpt = 0.89, Nhpm = 0.96, Nmpm = 0.97, Nlpm = 0.99, Cto = 3, Cm = 0.97, Cmm = 0.97, Plpc = 1.6, Pmpc = 3.8, Phpc = 4.03, Tem40 = 1100, Ce = 0.95;
	Temo = 288.15 - 6.5 * h;
	Preo = 101325 * (pow((1 - h / 44.308), 5.2553));
	a0 = sqrt(k * R * Temo);
	c0 = a0 * Ma0;
	Preo0 = Preo * pow((1 + ((k - 1) / 2) * Ma0 * Ma0), ((k) / (k - 1)));
	Temo0 = Temo * (1 + (k - 1) / 2 * Ma0 * Ma0);
	Pre20 = Preo0 * Ci;
	Tem20 = Temo0;
	Pre220 = Plpc * Pre20;
	Tem220 = Tem20 * (1 + (pow(Plpc, ((k - 1) / (k))) - 1) / (Mlpc));
		Wlpc = Cp * (Tem220 - Tem20);
	Pre240 = Pre220 * Pmpc;
	Tem240 = Tem220 * (1 + (pow(Pmpc, ((k - 1) / (k))) - 1) / (Mmpc));
	Wmpc = Cp * (Tem240 - Tem220);
	Pre30 = Pre240 * Phpc;
	Tem30 = Tem240 * (1 + (pow(Phpc, ((k - 1) / (k))) - 1) / (Mhpc));
	Whpc = Cp * (Tem30 - Tem240);
	Pre40 = Pre30 * Cb;
	f = (Cpg * Tem40 - Cp * Tem30) / (Hu * Nb - Cpg * Tem40);
	WB1 = ((1 - Z1 - Z2 - Z3 - L) * (1 + f) + (Cp * Z1 * Tem30) / (Cpg * Tem40)) / ((1 - Z1 - Z2 - Z3 - L) * (1 + f) + Z1);
	Pre4a0 = Pre40;
	Tem4a0 = Tem40 * WB1;
	WB2 = 1 - Cp * (Tem30 - Tem240) / (Cpg * ((1 - Z1 - Z2 - Z3 - L) * (1 + f) + Z1) * Nhpm * Tem4a0);
	Tem420 = Tem4a0 * WB2;
	Uhpt = pow((1 - (1 - (Tem420) / (Tem4a0)) / (Nhpt)), ((-kg) / (kg - 1)));
	Pre420 = Pre4a0 / Uhpt;
	WB3 = ((1 - Z1 - Z2 - Z3 - L) * (1 + f) + Z1 + (Cp * Z1 * Tem30 * Z2) / (Cpg * Tem420)) / ((1 - Z1 - Z2 - Z3 -L) * (1 + f) + Z1 + Z2);
	Tem4b0 = Tem420 * WB3;
	Pre4b0 = Pre420;
	WB4 = 1 - Cp * (Tem240 - Tem220) / (Nmpm * Tem4b0 * Cpg * ((1 - Z1 - Z2 - Z3 - L) * (1 + f) + Z1 + Z2));
	Tem430 = Tem4b0 * WB4;
	Umpt = pow((1 - (1 - Tem430 / Tem4b0) / (Nmpt)), ((-kg) / (kg - 1)));
	Pre430 = Pre4b0 / Umpt;
	WB5 = ((1 - Z1 - Z2 - Z3 - L) * (1 + f) + Z1 + Z2 + (Cp * Tem30 * Z3) / (Cpg * Tem430)) / ((1 - Z1 - Z2 - Z3 -L) * (1 + f) + Z1 + Z2 + Z3);
	Tem4c0 = Tem4b0 * WB5;
	Pre4c0 = Pre430;
	WB6 = 1 - (Cp * (Tem220 - Tem20) + Cto / Mmp) * (1 + B) / (Nlpm * Tem4c0 * Cpg * (1 - Z1 - Z2 - Z3 -L) * (1 + f) + Z1 + Z2 + Z3);
	Tem50 = Tem4c0 * WB6;
	Ulpt = pow((1 - (1 - Tem50 / Tem4c0) / (Nlpt)), ((-kg) / (kg - 1)));
	Pre50 = Pre4c0 / Ulpt;
	Bm = B / ((1 - Z1 - Z2 - Z3 - L) * (1 + f) + Z1 + Z2 + Z3);
	Cp6 = (Cpg + Bm * Cp) / (1 + Bm);
	Prem = (Pre50 + Bm * Cmm * Pre220) / (1 + Bm);
	WB7 = Cpg * (1 + (Bm * Cp * Tem220) / (Cpg * Tem50)) / (Cp6 * (1 + Bm));
	Tem60 = Tem50 * WB7;
	Pre60 = Prem * Cm;
	Pre80 = Pre60 * Ce;
	Tem80 = Tem60;
	Pre8 = Preo;
	Ma8 = sqrt(2 / (kg - 1) * (pow(Pre80 / Pre8, (kg - 1) / kg) - 1));
	Tem8 = Tem80 / (1 + (kg - 1) / 2 * Ma8 * Ma8);
	a8 = sqrt(kg * R * Tem8);
	C8 = a8 * Ma8;
	Fs = (1 + f * (1 - Z1 - Z2 - Z3 - L) / (1 + B) - L / (1 + B)) * C8;
	sfc = 3600 * f * (1 - Z1 - Z2 - Z3 - L) / (Fs * (1 + B));
	printf("\n\n 热力计算结果：\n\n ");
	printf("\n\n 计算点大气压力和大气温度:\n\n Preo=%.2f,Temo=%.2f\n", Preo, Temo);
	printf("\n\n 计算点高度的声速:\n\n a0=%.2f\n", a0);
	printf("\n\n 进气道进口气流速度:\n\n c0=%.2f\n", c0);
	printf("\n\n 进气道进口总压总温:\n\n Preo0=%.2f,Temo0=%.2f\n", Preo0, Temo0);
	printf("\n\n 进气道出口总压总温:\n\n Pre20=%.2f,Tem20=%.2f\n", Pre20, Tem20);
	printf("\n\n 低压压气机出口总压总温:\n\n Pre220=%.2f,Tem220=%.2f",Pre220,Tem220);
		printf("\n\n 低压压气机单位质量耗功:\n\n Wlpc=%.2f\n", Wlpc);
	printf("\n\n 中压压气机出口总压总温:\n\n Pre240=%.2f,Tem240=%.2f", Pre240,Tem240);
		printf("\n\n 中压压气机单位质量耗功:\n\n Wmpc=%.2f\n", Wmpc);
	printf("\n\n 高压压气机出口总压总温:\n\n Pre30=%.2f,Tem30=%.2f\n", Pre30, Tem30);
	printf("\n\n 高压压气机单位质量耗功:\n\n Whpc=%.2f\n", Whpc);
	printf("\n\n 燃烧室出口总压:\n\n Pre40=%.2f\n", Pre40);
	printf("\n\n 燃烧室油气比:\n\n f=%.3f\n", f);
	printf("\n\n 高压涡轮冷却混合过程前后温比:\n\n WB1=%.2f\n", WB1);
	printf("\n\n 高压涡轮混合模型出口总压总温:\n\n Pre4a0=%.2f,Tem4a0=%.2f",Pre4a0,Tem4a0);
		printf("\n\n 高压涡轮出口与混合模型出口温比:\n\n WB2=%.2f\n", WB2);
	printf("\n\n 高压涡轮出口总压总温:\n\n Pre420=%.2f,Tem420=%.2f\n", Pre420, Tem420);
	printf("\n\n 高压涡轮膨胀比:\n\n Uhpt=%.2f\n", Uhpt);
	printf("\n\n 中压涡轮混合模型前后温比:\n\n WB3=%.2f\n", WB3);
	printf("\n\n 中压涡轮混合模型出口总压总温:\n\n Pre4b0=%.2f,Tem4b0=%.2f",Pre4b0,Tem4b0);
		printf("\n\n 中压涡轮出口与混合模型出口温比:\n\n WB4=%.2f\n", WB4);
	printf("\n\n 中压涡轮出口总压总温:\n\n Pre430=%.2f,Tem430=%.2f\n", Pre430, Tem430);
	printf("\n\n 中压涡轮膨胀比:\n\n Umpt=%.2f\n", Umpt);
	printf("\n\n 低压涡轮混合模型前后温比:\n\n WB5=%.2f\n", WB5);
	printf("\n\n 低压涡轮混合模型出口总压总温:\n\n Pre4c0=%.2f,Tem4c0=%.2f",Pre4c0,Tem4c0);
		printf("\n\n 低压涡轮出口与混合模型前后温比:\n\n WB6=%.2f\n", WB6);
	printf("\n\n 低压涡轮出口总压总温:\n\n Pre50=%.2f,Tem50=%.2f\n", Pre50, Tem50);
	printf("\n\n 低压涡轮膨胀比:\n\n Ulpt=%.2f\n", Ulpt);
	printf("\n\n 混合过程进气道涵道比:\n\n Bm=%.2f\n", Bm);
	printf("\n\n 混合过程气体定压比热容:\n\n Cp6=%.2f\n", Cp6);
	printf("\n\n 混合过程进口气流质量平均总压:\n\n Prem=%.2f\n", Prem);
	printf("\n\n 混合过程前后温比:\n\n WB7=%.2f\n", WB7);
	printf("\n\n 混合过程出口总压总温:\n\n Pre60=%.2f,Tem60=%.2f\n", Pre60, Tem60);
	printf("\n\n 尾喷管出口总压总温:\n\n Pre80=%.2f,Tem80=%.2f\n", Pre80, Tem80);
	printf("\n\n 尾喷管出口静压静温:\n\n Pre8=%.2f,Tem8=%.2f\n", Pre8, Tem8);
	printf("\n\n 尾喷管出口速度:\n\n C8=%.2f\n", C8);
	printf("\n\n 总性能:\n\n 单位推力 Fs=%.2fN/(kg/s),耗油率 sfc=%.3fkg/(N*h)", Fs, sfc);
}