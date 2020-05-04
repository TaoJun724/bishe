#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARINGS
#include<stdio.h>
#include<winsock2.h>
#include<WS2tcpip.h>
#include<iostream>
#include <string.h>
#include"Comm.hpp"
#include "amgraph.h"
#include"parkingMember.hpp"
#include"parkingOperator.hpp"
#include"CMysqlOperator.hpp"
#include "CMysqlOperator.hpp"
using namespace std;
using namespace itlab;
#pragma comment(lib,"ws2_32.lib")
#define MaxClient 10
#define MaxBufSize 1024
#define BOUNDS_CHECK
const int PORT = 8000;
Manage m;
map<string, string> plsql;
CMysqlOperatoe sql;



//停车场A图结构顶点
Road R0, R1, R2, R3, R4, R5, R6, R7, R8, R11, R12, R13, R14, R15, R16, R17, R18, R19, R20;
Road R21, R22, R23, R24, R25, R26, R27, R28, R29, R30, R31, R32, R33, R34, R35, R36, R37, R38, R39, R40, R41;
Road C0, C1, C2, C3, C4, C5, C6, C7, C8, C9, C10, C11, C12, C13, C14, C15, C16, C17, C18, C19, C20;
Road C21, C22, C23, C24, C25, C26, C27, C28, C29, C30, C31, C32, C33, C34, C35, C36, C37, C38, C39, C40;
Road C41, C42, C43, C44, C45, C46, C47, C48, C49, C50, C51, C52, C53, C54, C55, C56, C57, C58, C59, C60;
Road C61, C62, C63, C64, C65, C66, C67, C68, C69, C70;
Road T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11;
Road E0, E1, E2, E3;

//停车场A添加顶点
void InitParkingAPoint(AMGraph<char, int>& parkingA)
{
	//添加线路点
	R0.index = "R0"; parkingA.insertVertex(R0);
	R1.index = "R1"; parkingA.insertVertex(R1);
	R2.index = "R2"; parkingA.insertVertex(R2);
	R3.index = "R3"; parkingA.insertVertex(R3);
	R4.index = "R4"; parkingA.insertVertex(R4);
	R5.index = "R5"; parkingA.insertVertex(R5);
	R6.index = "R6"; parkingA.insertVertex(R6);
	R7.index = "R7"; parkingA.insertVertex(R7);
	R8.index = "R8"; parkingA.insertVertex(R8);
	R11.index = "R11"; parkingA.insertVertex(R11);
	R12.index = "R12"; parkingA.insertVertex(R12);
	R13.index = "R13"; parkingA.insertVertex(R13);
	R14.index = "R14"; parkingA.insertVertex(R14);
	R15.index = "R15"; parkingA.insertVertex(R15);
	R16.index = "R16"; parkingA.insertVertex(R16);
	R17.index = "R17"; parkingA.insertVertex(R17);
	R18.index = "R18"; parkingA.insertVertex(R18);
	R19.index = "R19"; parkingA.insertVertex(R19);
	R20.index = "R20"; parkingA.insertVertex(R20);
	R21.index = "R21"; parkingA.insertVertex(R21);
	R22.index = "R22"; parkingA.insertVertex(R22);
	R23.index = "R23"; parkingA.insertVertex(R23);
	R24.index = "R24"; parkingA.insertVertex(R24);
	R25.index = "R25"; parkingA.insertVertex(R25);
	R26.index = "R26"; parkingA.insertVertex(R26);
	R27.index = "R27"; parkingA.insertVertex(R27);
	R28.index = "R28"; parkingA.insertVertex(R28);
	R29.index = "R29"; parkingA.insertVertex(R29);
	R30.index = "R30"; parkingA.insertVertex(R30);
	R31.index = "R31"; parkingA.insertVertex(R31);
	R32.index = "R32"; parkingA.insertVertex(R32);
	R33.index = "R33"; parkingA.insertVertex(R33);
	R34.index = "R34"; parkingA.insertVertex(R34);
	R35.index = "R35"; parkingA.insertVertex(R35);
	R36.index = "R36"; parkingA.insertVertex(R36);
	R37.index = "R37"; parkingA.insertVertex(R37);
	R38.index = "R38"; parkingA.insertVertex(R38);
	R39.index = "R39"; parkingA.insertVertex(R39);
	R40.index = "R40"; parkingA.insertVertex(R40);
	R41.index = "R41"; parkingA.insertVertex(R41);
	//添加车位点
	C0.index = "C0"; parkingA.insertVertex(C0);
	C1.index = "C1"; parkingA.insertVertex(C1);
	C2.index = "C2"; parkingA.insertVertex(C2);
	C3.index = "C3"; parkingA.insertVertex(C3);
	C4.index = "C4"; parkingA.insertVertex(C4);
	C5.index = "C5"; parkingA.insertVertex(C5);
	C6.index = "C6"; parkingA.insertVertex(C6);
	C7.index = "C7"; parkingA.insertVertex(C7);
	C8.index = "C8"; parkingA.insertVertex(C8);
	C9.index = "C9"; parkingA.insertVertex(C9);
	C10.index = "C10"; parkingA.insertVertex(C10);
	C11.index = "C11"; parkingA.insertVertex(C11);
	C12.index = "C12"; parkingA.insertVertex(C12);
	C13.index = "C13"; parkingA.insertVertex(C13);
	C14.index = "C14"; parkingA.insertVertex(C14);
	C15.index = "C15"; parkingA.insertVertex(C15);
	C16.index = "C16"; parkingA.insertVertex(C16);
	C17.index = "C17"; parkingA.insertVertex(C17);
	C18.index = "C18"; parkingA.insertVertex(C18);
	C19.index = "C19"; parkingA.insertVertex(C19);
	C20.index = "C20"; parkingA.insertVertex(C20);
	C21.index = "C21"; parkingA.insertVertex(C21);
	C22.index = "C22"; parkingA.insertVertex(C22);
	C23.index = "C23"; parkingA.insertVertex(C23);
	C24.index = "C24"; parkingA.insertVertex(C24);
	C25.index = "C25"; parkingA.insertVertex(C25);
	C26.index = "C26"; parkingA.insertVertex(C26);
	C27.index = "C27"; parkingA.insertVertex(C27);
	C28.index = "C28"; parkingA.insertVertex(C28);
	C29.index = "C29"; parkingA.insertVertex(C29);
	C30.index = "C30"; parkingA.insertVertex(C30);
	C31.index = "C31"; parkingA.insertVertex(C31);
	C32.index = "C32"; parkingA.insertVertex(C32);
	C33.index = "C33"; parkingA.insertVertex(C33);
	C34.index = "C34"; parkingA.insertVertex(C34);
	C35.index = "C35"; parkingA.insertVertex(C35);
	C36.index = "C36"; parkingA.insertVertex(C36);
	C37.index = "C37"; parkingA.insertVertex(C37);
	C38.index = "C38"; parkingA.insertVertex(C38);
	C39.index = "C39"; parkingA.insertVertex(C39);
	C40.index = "C40"; parkingA.insertVertex(C40);
	C41.index = "C41"; parkingA.insertVertex(C41);
	C42.index = "C42"; parkingA.insertVertex(C42);
	C43.index = "C43"; parkingA.insertVertex(C43);
	C44.index = "C44"; parkingA.insertVertex(C44);
	C45.index = "C45"; parkingA.insertVertex(C45);
	C46.index = "C46"; parkingA.insertVertex(C46);
	C47.index = "C47"; parkingA.insertVertex(C47);
	C48.index = "C48"; parkingA.insertVertex(C48);
	C49.index = "C49"; parkingA.insertVertex(C49);
	C50.index = "C50"; parkingA.insertVertex(C50);
	C51.index = "C51"; parkingA.insertVertex(C51);
	C52.index = "C52"; parkingA.insertVertex(C52);
	C53.index = "C53"; parkingA.insertVertex(C53);
	C54.index = "C54"; parkingA.insertVertex(C54);
	C55.index = "C55"; parkingA.insertVertex(C55);
	C56.index = "C56"; parkingA.insertVertex(C56);
	C57.index = "C57"; parkingA.insertVertex(C57);
	C58.index = "C58"; parkingA.insertVertex(C58);
	C59.index = "C59"; parkingA.insertVertex(C59);
	C60.index = "C60"; parkingA.insertVertex(C60);
	C61.index = "C61"; parkingA.insertVertex(C61);
	C62.index = "C62"; parkingA.insertVertex(C62);
	C63.index = "C63"; parkingA.insertVertex(C63);
	C64.index = "C64"; parkingA.insertVertex(C64);
	C65.index = "C65"; parkingA.insertVertex(C65);
	C66.index = "C66"; parkingA.insertVertex(C66);
	C67.index = "C67"; parkingA.insertVertex(C67);
	C68.index = "C68"; parkingA.insertVertex(C68);
	C69.index = "C69"; parkingA.insertVertex(C69);
	C70.index = "C70"; parkingA.insertVertex(C70);
	//添加停靠点与充点电
	T0.index = "T0"; parkingA.insertVertex(T0);
	T1.index = "T1"; parkingA.insertVertex(T1);
	T2.index = "T2"; parkingA.insertVertex(T2);
	T3.index = "T3"; parkingA.insertVertex(T3);
	T4.index = "T4"; parkingA.insertVertex(T4);
	T5.index = "T5"; parkingA.insertVertex(T5);
	T6.index = "T6"; parkingA.insertVertex(T6);
	T7.index = "T7"; parkingA.insertVertex(T7);
	T8.index = "T8"; parkingA.insertVertex(T8);
	T9.index = "T9"; parkingA.insertVertex(T9);
	T10.index = "T10"; parkingA.insertVertex(T10);
	T11.index = "T11"; parkingA.insertVertex(T11);
	E0.index = "E0"; parkingA.insertVertex(E0);
	E1.index = "E1"; parkingA.insertVertex(E1);
	E2.index = "E2"; parkingA.insertVertex(E2);
	E3.index = "E3"; parkingA.insertVertex(E3);
}
//停车场A添加线路
void InitParkingAEdge(AMGraph<char, int>& parkingA)
{
	parkingA.insertEdge(R0, R2, 1);	parkingA.insertEdge(R2, R4, 5);
	parkingA.insertEdge(R4, C0, 2);	parkingA.insertEdge(R4, C1, 2);
	parkingA.insertEdge(C0, R4, 2);	parkingA.insertEdge(C1, R4, 2);
	parkingA.insertEdge(R3, R1, 6);	parkingA.insertEdge(R4, R3, 3);
	parkingA.insertEdge(R3, R4, 3);	parkingA.insertEdge(R4, R6, 3);
	parkingA.insertEdge(R6, C2, 2);	parkingA.insertEdge(R6, C3, 3);	
	parkingA.insertEdge(C2, R6, 2); parkingA.insertEdge(C3, R6, 3);
	parkingA.insertEdge(R6, R5, 2);	parkingA.insertEdge(R5, R6, 2);
	parkingA.insertEdge(R5, R3, 5);	parkingA.insertEdge(R6, R3, 7);
	parkingA.insertEdge(R6, R8, 5);	parkingA.insertEdge(R8, C4, 4);
	parkingA.insertEdge(R8, C5, 5); parkingA.insertEdge(C4, R8, 4);
	parkingA.insertEdge(C5, R8, 5);
	parkingA.insertEdge(R8, R5, 7);
	parkingA.insertEdge(R8, R7, 3);
	parkingA.insertEdge(R8, R12, 5);
	parkingA.insertEdge(R7, R8, 3);
	parkingA.insertEdge(R7, R5, 5);
	parkingA.insertEdge(R36, R7, 3);
	parkingA.insertEdge(R11, R7, 3);
	parkingA.insertEdge(R8, R12, 4);
	parkingA.insertEdge(R12, R14, 5);
	parkingA.insertEdge(R14, C6, 3);
	parkingA.insertEdge(R14, C7, 4);
	parkingA.insertEdge(R14, C8, 3);
	parkingA.insertEdge(R14, C9, 4);
	parkingA.insertEdge(C6, R14, 3);
	parkingA.insertEdge(C7, R14, 4);
	parkingA.insertEdge(C8, R14, 3);
	parkingA.insertEdge(C9, R14, 4);
	parkingA.insertEdge(R33, C50, 2);
	parkingA.insertEdge(R33, C51, 2);
	parkingA.insertEdge(R33, C52, 2);
	parkingA.insertEdge(C50, R33, 2);
	parkingA.insertEdge(C51, R33, 2);
	parkingA.insertEdge(C52, R33, 2);
	parkingA.insertEdge(R33, R28, 5);
	parkingA.insertEdge(R28, R29, 5);
	parkingA.insertEdge(R29, R13, 5);
	parkingA.insertEdge(R33, R34, 7);
	parkingA.insertEdge(R34, R35, 5);
	parkingA.insertEdge(R35, R37, 3);
	parkingA.insertEdge(R35, R13, 5);
	parkingA.insertEdge(R14, R13, 3);
	parkingA.insertEdge(R13, R14, 3);
	parkingA.insertEdge(R13, R11, 5);
	parkingA.insertEdge(R11, R13, 5);
	parkingA.insertEdge(R41, R40, 3);
	parkingA.insertEdge(R40, R41, 3);
	parkingA.insertEdge(R41, R39, 5);
	parkingA.insertEdge(R39, R41, 5);
	parkingA.insertEdge(R40, E2, 5);
	parkingA.insertEdge(R40, E3, 4);
	parkingA.insertEdge(E2, R40, 5);
	parkingA.insertEdge(E3, R40, 4);
	parkingA.insertEdge(R40, R38, 5);
	parkingA.insertEdge(R38, R40, 5);
	parkingA.insertEdge(R38, T10, 5);
	parkingA.insertEdge(R38, T11, 4);
	parkingA.insertEdge(R38, E0, 5);
	parkingA.insertEdge(R38, E1, 4);
	parkingA.insertEdge(T10, R38, 5);
	parkingA.insertEdge(T11, R38, 4);
	parkingA.insertEdge(E0, R38, 5);
	parkingA.insertEdge(E1, R38, 4);
	parkingA.insertEdge(R38, R39, 3);
	parkingA.insertEdge(R39, R38, 3);
	parkingA.insertEdge(R38, R36, 5);
	parkingA.insertEdge(R36, R38, 5);
	parkingA.insertEdge(R36, T6, 5);
	parkingA.insertEdge(R36, T8, 5);
	parkingA.insertEdge(R36, T7, 4);
	parkingA.insertEdge(R36, T9, 4);
	parkingA.insertEdge(T6, R36, 5);
	parkingA.insertEdge(T8, R36, 5);
	parkingA.insertEdge(T7, R36, 4);
	parkingA.insertEdge(T9, R36, 4);
	parkingA.insertEdge(R39, R37, 5);
	parkingA.insertEdge(R37, R39, 5);
	parkingA.insertEdge(R37, R36, 3);
	parkingA.insertEdge(R36, R11, 4);
	parkingA.insertEdge(R36, R7, 4);
	parkingA.insertEdge(R12, R11, 3);
	parkingA.insertEdge(R11, R12, 3);
	parkingA.insertEdge(R11, R37, 3);
	parkingA.insertEdge(R37, R11, 3);
	parkingA.insertEdge(R14, R16, 5);
	parkingA.insertEdge(R16, C10, 2);
	parkingA.insertEdge(C10, R16, 2);
	parkingA.insertEdge(R16, C11, 2);
	parkingA.insertEdge(C11, R16, 2);
	parkingA.insertEdge(R16, C12, 3);
	parkingA.insertEdge(C12, R16, 3);
	parkingA.insertEdge(R16, C13, 3);
	parkingA.insertEdge(C13, R16, 3);
	parkingA.insertEdge(R16, C14, 2);
	parkingA.insertEdge(C14, R16, 2);
	parkingA.insertEdge(R16, C15, 2);
	parkingA.insertEdge(C15, R16, 2);
	parkingA.insertEdge(R16, C16, 3);
	parkingA.insertEdge(C16, R16, 3);
	parkingA.insertEdge(R16, C17, 3);
	parkingA.insertEdge(C17, R16, 3);
	parkingA.insertEdge(R16, R15, 2);
	parkingA.insertEdge(R15, R16, 2);
	parkingA.insertEdge(R16, R18, 5);
	parkingA.insertEdge(R18, C18, 2);
	parkingA.insertEdge(R18, C19, 2);
	parkingA.insertEdge(R18, C20, 3);
	parkingA.insertEdge(R18, C21, 3);
	parkingA.insertEdge(C18, R18, 2);
	parkingA.insertEdge(C19, R18, 2);
	parkingA.insertEdge(C20, R18, 3);
	parkingA.insertEdge(C21, R18, 3);
	parkingA.insertEdge(R18, R17, 2);
	parkingA.insertEdge(R17, R18, 2);
	parkingA.insertEdge(R18, R20, 5);
	parkingA.insertEdge(R20, C22, 2);	parkingA.insertEdge(C22, R20, 2);
	parkingA.insertEdge(R20, C23, 2);	parkingA.insertEdge(C23, R20, 2);
	parkingA.insertEdge(R20, C24, 3);	parkingA.insertEdge(C24, R20, 3);
	parkingA.insertEdge(R20, C25, 3);	parkingA.insertEdge(C25, R20, 3);
	parkingA.insertEdge(R20, R23, 5);
	parkingA.insertEdge(R20, R19, 2);
	parkingA.insertEdge(R19, R20, 2);
	parkingA.insertEdge(R15, R13, 2);
	parkingA.insertEdge(R13, R15, 2);
	parkingA.insertEdge(R15, C53, 2);
	parkingA.insertEdge(C53, R15, 2);
	parkingA.insertEdge(R15, C54, 2);
	parkingA.insertEdge(C54, R15, 2);
	parkingA.insertEdge(R15, C55, 2);
	parkingA.insertEdge(C55, R15, 2);
	parkingA.insertEdge(R15, C56, 2);
	parkingA.insertEdge(C56, R15, 2);
	parkingA.insertEdge(R15, R17, 5);
	parkingA.insertEdge(R17, R15, 5);
	parkingA.insertEdge(R17, C57, 2);
	parkingA.insertEdge(C57, R17, 2);
	parkingA.insertEdge(R17, C58, 2);
	parkingA.insertEdge(C58, R17, 2);
	parkingA.insertEdge(R17, C59, 2);
	parkingA.insertEdge(C59, R17, 2);
	parkingA.insertEdge(R17, C60, 2);
	parkingA.insertEdge(C60, R17, 2);
	parkingA.insertEdge(R17, R19, 5);
	parkingA.insertEdge(R19, R17, 5);
	parkingA.insertEdge(R19, C61, 2);
	parkingA.insertEdge(C61, R19, 2);
	parkingA.insertEdge(R19, T0, 2);
	parkingA.insertEdge(T0, R19, 2);
	parkingA.insertEdge(R19, T1, 2);
	parkingA.insertEdge(T1, R19, 2);
	parkingA.insertEdge(R19, T2, 2);
	parkingA.insertEdge(T2, R19, 2);
	parkingA.insertEdge(R19, R23, 5);
	parkingA.insertEdge(R23, R19, 5);
	parkingA.insertEdge(R19, R22, 5);
	parkingA.insertEdge(R22, R19, 5);
	parkingA.insertEdge(R22, R21, 4);
	parkingA.insertEdge(R21, R25, 4);
	parkingA.insertEdge(R25, R21, 4);
	parkingA.insertEdge(R21, R24, 5);
	parkingA.insertEdge(R24, R21, 5);
	parkingA.insertEdge(R25, T3, 2);
	parkingA.insertEdge(T3, R25, 2);
	parkingA.insertEdge(R25, T4, 2);
	parkingA.insertEdge(T4, R25, 2);
	parkingA.insertEdge(R25, T5, 2);
	parkingA.insertEdge(T5, R25, 2);
	parkingA.insertEdge(R25, C62, 2);
	parkingA.insertEdge(C62, R25, 2);
	parkingA.insertEdge(R25, R26, 5);
	parkingA.insertEdge(R26, R27, 5);
	parkingA.insertEdge(R27, R28, 5);
	parkingA.insertEdge(R25, R30, 7);
	parkingA.insertEdge(R25, R31, 7);
	parkingA.insertEdge(R32, R33, 5);
	parkingA.insertEdge(R31, R32, 5);
	parkingA.insertEdge(R30, R31, 5);
	parkingA.insertEdge(R24, R30, 6);
	parkingA.insertEdge(R23, R24, 5);
	parkingA.insertEdge(R26, C66, 2);
	parkingA.insertEdge(R26, C65, 2);
	parkingA.insertEdge(R26, C64, 2);
	parkingA.insertEdge(R26, C63, 2);
	parkingA.insertEdge(C66, R26, 2);
	parkingA.insertEdge(C65, R26, 2);
	parkingA.insertEdge(C64, R26, 2);
	parkingA.insertEdge(C63, R26, 2);
	parkingA.insertEdge(C70, R27, 2);
	parkingA.insertEdge(C69, R27, 2);
	parkingA.insertEdge(C68, R27, 2);
	parkingA.insertEdge(C67, R27, 2);
	parkingA.insertEdge(R27, C70, 2);
	parkingA.insertEdge(R27, C69, 2);
	parkingA.insertEdge(R27, C68, 2);
	parkingA.insertEdge(R27, C67, 2);
	parkingA.insertEdge(R23, C26, 2);
	parkingA.insertEdge(R23, C27, 2);
	parkingA.insertEdge(R23, C28, 2);
	parkingA.insertEdge(R23, C29, 2);
	parkingA.insertEdge(R23, C30, 2);
	parkingA.insertEdge(R23, C31, 2);
	parkingA.insertEdge(R23, C32, 2);
	parkingA.insertEdge(C26, R23, 2);
	parkingA.insertEdge(C27, R23, 2);
	parkingA.insertEdge(C28, R23, 2);
	parkingA.insertEdge(C29, R23, 2);
	parkingA.insertEdge(C30, R23, 2);
	parkingA.insertEdge(C31, R23, 2);
	parkingA.insertEdge(C32, R23, 2);
	parkingA.insertEdge(C33, R24, 2);
	parkingA.insertEdge(C34, R24, 2);
	parkingA.insertEdge(C35, R24, 2);
	parkingA.insertEdge(C36, R24, 2);
	parkingA.insertEdge(C37, R24, 2);
	parkingA.insertEdge(R24, C33, 2);
	parkingA.insertEdge(R24, C34, 2);
	parkingA.insertEdge(R24, C35, 2);
	parkingA.insertEdge(R24, C36, 2);
	parkingA.insertEdge(R24, C37, 2);
	parkingA.insertEdge(R30, C38, 2);
	parkingA.insertEdge(R30, C39, 2);
	parkingA.insertEdge(R30, C40, 2);
	parkingA.insertEdge(C38, R30, 2);
	parkingA.insertEdge(C39, R30, 2);
	parkingA.insertEdge(C40, R30, 2);
	parkingA.insertEdge(R31, C41, 2);
	parkingA.insertEdge(R31, C42, 2);
	parkingA.insertEdge(R31, C43, 2);
	parkingA.insertEdge(R31, C44, 2);
	parkingA.insertEdge(R31, C45, 2);
	parkingA.insertEdge(C41, R31, 2);
	parkingA.insertEdge(C42, R31, 2);
	parkingA.insertEdge(C43, R31, 2);
	parkingA.insertEdge(C44, R31, 2);
	parkingA.insertEdge(C45, R31, 2);
	parkingA.insertEdge(C46, R32, 2);
	parkingA.insertEdge(C47, R32, 2);
	parkingA.insertEdge(C48, R32, 2);
	parkingA.insertEdge(C49, R32, 2);
	parkingA.insertEdge(R32, C46, 2);
	parkingA.insertEdge(R32, C47, 2);
	parkingA.insertEdge(R32, C48, 2);
	parkingA.insertEdge(R32, C49, 2);
}

//停车场B图结构顶掉
Road R42, R43, R44, R45, R46, R47, R48, R49, R50, R51, R52, R53, R54, R55, R56, R57;
Road T12, T13, T14, T15, T16, T17;
Road E4, E5, E6, E7;
Road C71, C72, C73, C74, C75, C76, C77, C78, C79, C80, C81, C82, C83, C84;
//B添加顶点
void InitParkingBPoint(AMGraph<char, int>& parkingB)
{
	//添加点
	R42.index = "R42"; parkingB.insertVertex(R42);
	R43.index = "R43"; parkingB.insertVertex(R43);
	R44.index = "R44"; parkingB.insertVertex(R44);
	R45.index = "R45"; parkingB.insertVertex(R45);
	R46.index = "R46"; parkingB.insertVertex(R46);
	R47.index = "R47"; parkingB.insertVertex(R47);
	R48.index = "R48"; parkingB.insertVertex(R48);
	R49.index = "R49"; parkingB.insertVertex(R49);
	R50.index = "R50"; parkingB.insertVertex(R50);
	R51.index = "R51"; parkingB.insertVertex(R51);
	R52.index = "R52"; parkingB.insertVertex(R52);
	R53.index = "R53"; parkingB.insertVertex(R53);
	R54.index = "R54"; parkingB.insertVertex(R54);
	R55.index = "R55"; parkingB.insertVertex(R55);
	R56.index = "R56"; parkingB.insertVertex(R56);
	R57.index = "R57"; parkingB.insertVertex(R57);
	//停靠区
	T12.index = "T12"; parkingB.insertVertex(T12);
	T13.index = "T13"; parkingB.insertVertex(T13);
	T14.index = "T14"; parkingB.insertVertex(T14);
	T15.index = "T15"; parkingB.insertVertex(T15);
	T16.index = "T16"; parkingB.insertVertex(T16);
	T17.index = "T17"; parkingB.insertVertex(T17);
	//充电点
	E4.index = "E4"; parkingB.insertVertex(E4); 	E5.index = "E5"; parkingB.insertVertex(E5);
	E6.index = "E6"; parkingB.insertVertex(E6);  	E7.index = "E7"; parkingB.insertVertex(E7);
	//车位
	C71.index = "C71"; parkingB.insertVertex(C71);
	C72.index = "C72"; parkingB.insertVertex(C72);
	C73.index = "C73"; parkingB.insertVertex(C73);
	C74.index = "C74"; parkingB.insertVertex(C74);
	C75.index = "C75"; parkingB.insertVertex(C75);
	C76.index = "C76"; parkingB.insertVertex(C76);
	C77.index = "C77"; parkingB.insertVertex(C77);
	C78.index = "C78"; parkingB.insertVertex(C78);
	C79.index = "C79"; parkingB.insertVertex(C79);
	C80.index = "C80"; parkingB.insertVertex(C80);
	C81.index = "C81"; parkingB.insertVertex(C81);
	C82.index = "C82"; parkingB.insertVertex(C82);
	C83.index = "C83"; parkingB.insertVertex(C83);
	C84.index = "C84"; parkingB.insertVertex(C84);
	C37.index = "C37"; parkingB.insertVertex(C37);
	C38.index = "C38"; parkingB.insertVertex(C38);
	C39.index = "C39"; parkingB.insertVertex(C39);
	C40.index = "C40"; parkingB.insertVertex(C40);
	C41.index = "C41"; parkingB.insertVertex(C41);
	C42.index = "C42"; parkingB.insertVertex(C42);
	C43.index = "C43"; parkingB.insertVertex(C43);
	C44.index = "C44"; parkingB.insertVertex(C44);
	C45.index = "C45"; parkingB.insertVertex(C45);
	C46.index = "C46"; parkingB.insertVertex(C46);
	C47.index = "C47"; parkingB.insertVertex(C47);
	C48.index = "C48"; parkingB.insertVertex(C48);
	C49.index = "C49"; parkingB.insertVertex(C49);
	C50.index = "C50"; parkingB.insertVertex(C50);
	C51.index = "C51"; parkingB.insertVertex(C51);
	C52.index = "C52"; parkingB.insertVertex(C52);
}
//B添加线路
void InitParkingBEdge(AMGraph<char, int>& parkingB)
{
	parkingB.insertEdge(R57, R42, 2);
	parkingB.insertEdge(R42, R43, 2);
	parkingB.insertEdge(R43, R55, 4);
	parkingB.insertEdge(R43, R44, 2);
	parkingB.insertEdge(R44, R54, 3);
	parkingB.insertEdge(R44, R45, 2);
	parkingB.insertEdge(R45, R53, 3);
	parkingB.insertEdge(R45, R46, 2);
	parkingB.insertEdge(R46, R47, 2);
	parkingB.insertEdge(R47, R48, 2);
	parkingB.insertEdge(R47, R52, 3);
	parkingB.insertEdge(R48, R49, 1);
	parkingB.insertEdge(R49, R50, 2);
	parkingB.insertEdge(R50, R51, 2);
	parkingB.insertEdge(R51, R52, 2);
	parkingB.insertEdge(R52, R51, 2);
	parkingB.insertEdge(R52, R53, 2);
	parkingB.insertEdge(R53, R54, 2);
	parkingB.insertEdge(R54, R55, 3);
	parkingB.insertEdge(R55, R56, 2);
	parkingB.insertEdge(R56, R57, 2);

	parkingB.insertEdge(R44, T12, 2); parkingB.insertEdge(T12, R44, 2);
	parkingB.insertEdge(R44, T13, 3); parkingB.insertEdge(T13, R44, 3);
	parkingB.insertEdge(R44, T15, 4); parkingB.insertEdge(T15, R44, 4);
	parkingB.insertEdge(R44, T16, 5); parkingB.insertEdge(T16, R44, 5);

	parkingB.insertEdge(R45, T14, 2); parkingB.insertEdge(T14, R45, 2);
	parkingB.insertEdge(R45, T17, 3); parkingB.insertEdge(T17, R45, 3);
	parkingB.insertEdge(R45, E4, 4); parkingB.insertEdge(E4, R45, 4);
	parkingB.insertEdge(R45, E6, 5); parkingB.insertEdge(E6, R45, 5);

	parkingB.insertEdge(R46, E5, 2); parkingB.insertEdge(E5, R46, 2);
	parkingB.insertEdge(R46, E7, 3); parkingB.insertEdge(E7, R46, 3);
	parkingB.insertEdge(R46, C71, 4); parkingB.insertEdge(C71, R46, 4);
	parkingB.insertEdge(R46, C75, 5); parkingB.insertEdge(C75, R46, 5);

	parkingB.insertEdge(R47, C72, 2); parkingB.insertEdge(C72, R47, 2);
	parkingB.insertEdge(R47, C73, 3); parkingB.insertEdge(C73, R47, 3);
	parkingB.insertEdge(R47, C74, 4); parkingB.insertEdge(C74, R47, 4);
	parkingB.insertEdge(R47, C76, 5); parkingB.insertEdge(C76, R47, 5);
	parkingB.insertEdge(R47, C77, 6); parkingB.insertEdge(C77, R47, 6);
	parkingB.insertEdge(R47, C78, 7); parkingB.insertEdge(C78, R47, 7);

	parkingB.insertEdge(R48, C79, 2); parkingB.insertEdge(C79, R48, 2);
	parkingB.insertEdge(R48, C80, 3); parkingB.insertEdge(C80, R48, 3);
	parkingB.insertEdge(R48, C81, 4); parkingB.insertEdge(C81, R48, 4);

	parkingB.insertEdge(R49, C82, 2); parkingB.insertEdge(C82, R49, 2);
	parkingB.insertEdge(R49, C83, 3); parkingB.insertEdge(C83, R49, 3);
	parkingB.insertEdge(R49, C84, 4); parkingB.insertEdge(C84, R49, 4);

	parkingB.insertEdge(R55, C50, 2); parkingB.insertEdge(C50, R55, 2);
	parkingB.insertEdge(R55, C51, 3); parkingB.insertEdge(C51, R55, 3);
	parkingB.insertEdge(R55, C52, 4); parkingB.insertEdge(C52, R55, 4);


	parkingB.insertEdge(R53, C49, 2); parkingB.insertEdge(C49, R53, 2);
	parkingB.insertEdge(R53, C41, 3); parkingB.insertEdge(C41, R53, 3);
	parkingB.insertEdge(R53, C42, 4); parkingB.insertEdge(C42, R53, 4);

	parkingB.insertEdge(R52, C43, 2); parkingB.insertEdge(C43, R52, 2);
	parkingB.insertEdge(R52, C44, 3); parkingB.insertEdge(C44, R52, 3);
	parkingB.insertEdge(R52, C45, 4); parkingB.insertEdge(C45, R52, 4);

	parkingB.insertEdge(R54, C46, 2); parkingB.insertEdge(C46, R54, 2);
	parkingB.insertEdge(R54, C47, 3); parkingB.insertEdge(C47, R54, 3);
	parkingB.insertEdge(R54, C48, 4); parkingB.insertEdge(C48, R54, 4);


	parkingB.insertEdge(R51, C40, 2); parkingB.insertEdge(C40, R51, 2);
	parkingB.insertEdge(R51, C39, 3); parkingB.insertEdge(C39, R51, 3);
	parkingB.insertEdge(R51, C38, 4); parkingB.insertEdge(C38, R51, 4);
	parkingB.insertEdge(R51, C37, 5); parkingB.insertEdge(C37, R51, 5);
}



//服务线程
DWORD WINAPI ServerThread(LPVOID lpParameter){
	//bool flag;
	bool flag0;
	bool flag1;
	bool flag2;
	bool flag3;
	string licensestr;
//	m.initParking();
	mysql_query(&mysql, "set names gbk");
	sql.ConnectDatabase();
	sprintf(query, "SELECT licensePlate, userName, passwd from userInfo"); //执行查询语句，这里是查询所有，user是表名，不用加引号，用strcpy也可以
	mysql_query(&mysql, "set names gbk"); //设置编码格式（SET NAMES GBK也行），否则cmd下中文乱码
	//返回0 查询成功，返回1查询失败
	mysql_query(&mysql, query);      //执行SQL语句
	//获取结果集
	if (!(res = mysql_store_result(&mysql)))    //获得sql语句结束后返回的结果集
	{
		//	printf("Couldn't get result from %s\n", mysql_error(&mysql));
		//	return false;
	}
	//获取字段的信息
	char *str_field[32];  //定义一个字符串数组存储字段信息
	for (int i = 0; i<3; i++)   //在已知字段数量的情况下获取字段名
	{
		str_field[i] = mysql_fetch_field(res)->name;
	}
	//打印获取的数据
	while (column = mysql_fetch_row(res))   //在已知字段数量情况下，获取并打印下一行
	{
		//printf("%10s\t%10s\t%10s\t\n", column[0], column[1], column[2]);  //column是列数组
		plsql.insert(make_pair(column[0], column[2]));
	}

	SOCKET *ClientSocket = (SOCKET*)lpParameter;
	int receByt = 0;
	char revData[MaxBufSize];
//	char sendData[MaxBufSize];
	while (1){
		receByt = recv(*ClientSocket, revData, sizeof(revData), 0);
		if (receByt>0){
			cout << "接收到的消息是：" << revData << "            来自客户端:" << *ClientSocket << endl;
		}
		else
		{
			cout << "接收消息结束！" << endl;
			break;
		}

		//事件流处理		
		string str(revData);
		string str1;
		str1 = str.substr(0, 20);
		const char* str2;
		str2 = str1.c_str();

		string str6;
		str6 = str.substr(0, 13);
		const char* str7;
		str7 = str6.c_str();
		//发送数据给客户端
		char sendData[1024];

		/************请进行管理员功能选择***************\n
		******1.查询数据库**********2.删除数据库******\n
		******3.查询车位状态********4.查询便道状态****\n
		******5.查询小车状态********6.展示停车场******\n
		     ********6.退出登录******\n\n*/
		if (strcmp(revData, "管理员") == 0)
		{
			flag2 = true;
			send(*ClientSocket, "请输入管理员密码\n", sizeof(sendData), 0);
		}
		else if (flag2 == true)
		{
			if (strcmp(revData, "admin") == 0)
			{
				flag2 = false;
				send(*ClientSocket, "管理员登录成功\n\n************请进行管理员功能选择***************\n ******1.查询数据库**********2.删除数据库******\n******3.查询车位状态********4.查询便道状态****\n******5.查询小车状态********6.展示停车场******\n        ********6.退出登录******\n\n", sizeof(sendData), 0);
			}
			else{
				send(*ClientSocket, "密码错误，请重新输入管理员密码\n", sizeof(sendData), 0);
			}

		}
		else if ((strcmp(revData, "查询数据库") == 0))
		{
			sql.QueryDatabase1();
			send(*ClientSocket, "\n数据库已展示\n\n************请进行管理员功能选择***************\n ******1.查询数据库**********2.删除数据库******\n******3.查询车位状态********4.查询便道状态****\n******5.查询小车状态********6.展示停车场******\n        ********6.退出登录******\n\n", sizeof(sendData), 0);
		}
		else if ((strcmp(revData, "查询小车状态") == 0))
		{
			int noWork = m.findAgvCarStatus();
			if (noWork < AgvCarNum){
				//工作小车返回坐标 //待完成
			}
			send(*ClientSocket, "\n小车状态已展示\n\n************请进行管理员功能选择***************\n ******1.查询数据库**********2.删除数据库******\n******3.查询车位状态********4.查询便道状态****\n******5.查询小车状态********6.展示停车场******\n        ********6.退出登录******\n\n", sizeof(sendData), 0);
		}
		else if (strcmp(revData, "删除数据库") == 0)
		{
			flag3 = true;
			send(*ClientSocket, "请输入删除的车牌号\n", sizeof(sendData), 0);
		}
		else if (flag3 == true)
		{
			string str4("delete from userInfo where licensePlate = '");
			str4 += str;
			string str5("'");
			str4 += str5;
			const char* SQL = str4.c_str();
			sql.DeleteData(SQL);
			sql.QueryDatabase1();
			flag3 = false;
			send(*ClientSocket, "\n数据库删除操作完成\n\n************请进行管理员功能选择***************\n ******1.查询数据库**********2.删除数据库******\n******3.查询车位状态********4.查询便道状态****\n******5.查询小车状态********6.展示停车场******\n        ********6.退出登录******\n\n", sizeof(sendData), 0);
		}
		else if (strcmp(revData, "用户") == 0)
		{
			send(*ClientSocket, "\n**************************************************\n**********1.用户注册**********2.用户登录**********\n**************************************************\n", sizeof(sendData), 0);
		}
		else if (strcmp(revData, "用户登录") == 0)
		{
			flag0 = true;
			send(*ClientSocket, "请输入你的车牌号\n", sizeof(sendData), 0);
		}
		else if (strcmp(revData, "用户注册") == 0)
		{
			flag1 = true;
			send(*ClientSocket, "请输入你的车牌号，姓名，登录密码\n", sizeof(sendData), 0);
		}
		else if (flag1 == true)
		{
			char *temp;
			char *output = revData;
			string licenseplate;
			string name;
			string passed;
			int index = 1;
			while ((temp = strchr(output, ',')) != NULL) {
				*temp = '\0';
				if (index == 1){
					licenseplate = output;
					index++;
				}
				else if (index == 2){
					name = output;
				}
				output = temp + 1;
			}
			passed = output;
			plsql.insert(make_pair(licenseplate, passed));
			string SQL("Insert into userInfo(licensePlate, userName, passwd) values('");
			SQL += licenseplate;
			string fuhao("','");
			string fuhao1("');");
			SQL += fuhao;
			SQL += name;
			SQL += fuhao;
			SQL += passed;
			SQL += fuhao1;
			const char* sq = SQL.c_str();
			sql.InsertDate(sq);
			flag1 = false;
			send(*ClientSocket, "注册成功\n\n**************************************************\n**********1.用户注册**********2.用户登录**********\n**************************************************\n", sizeof(sendData), 0);
		}
		else if (licensestr.size() == 0 && flag0 == true)
		{
			licensestr += str;
			send(*ClientSocket, "请输入你的密码\n", sizeof(sendData), 0);
		}
		else if (flag0 == true && licensestr.size() != 0)
		{
			string password = plsql[licensestr];
			const char *licenseindex = password.c_str();
			if (strcmp(licenseindex, revData) == 0)
			{
				flag0 = false;
				licensestr.clear();
				send(*ClientSocket, "用户登陆成功\n\*******请进行用户功能选择*********\n******1.停车**********2.取车******\n      ******3.退出登录********\n\n", sizeof(sendData), 0);
			}
			else{
				//flag = false;
				licensestr.clear();
				send(*ClientSocket, "车牌或者密码错误，请重新输入车牌号\n", sizeof(sendData), 0);
			}

		}
		else if ((strcmp(revData, "查询车位状态") == 0))
		{
			m.findParkingSpaceStatus();
			send(*ClientSocket, "\n车位状态已展示\n\n************请进行管理员功能选择***************\n ******1.查询数据库**********2.删除数据库******\n******3.查询车位状态********4.查询便道状态****\n******5.查询小车状态********6.展示停车场******\n        ********6.退出登录******\n\n", sizeof(sendData), 0);
		}
		else if ((strcmp(revData, "查询便道状态") == 0))
		{
			m.findRoadStatus();
			send(*ClientSocket, "\n便道状态已展示\n\n************请进行管理员功能选择***************\n ******1.查询数据库**********2.删除数据库******\n******3.查询车位状态********4.查询便道状态****\n******5.查询小车状态********6.展示停车场******\n        ********6.退出登录******\n\n", sizeof(sendData), 0);
		}
		else if ((strcmp(revData, "展示停车场") == 0))
		{
			m.show();
			send(*ClientSocket, "停车场已展示\n\n************请进行管理员功能选择***************\n ******1.查询数据库**********2.删除数据库******\n******3.查询车位状态********4.查询便道状态****\n******5.查询小车状态********6.展示停车场******\n        ********6.退出登录******\n\n", sizeof(sendData), 0);
		}
		else if ((strcmp(revData, "退出登录") == 0))
		{
			send(*ClientSocket, "退出成功\n\n************请选择你的身份:******************\n*************1.管理员********2.用户**********\n*********************************************\n\n", sizeof(sendData), 0);
		}
		else if (strcmp(revData, "取车") == 0)
		{
			send(*ClientSocket, "取车功能待实现\n\n*******请进行用户功能选择*********\n******1.停车**********2.取车******\n******3.退出登录********\n\n", sizeof(sendData), 0);
		}
		else if (strcmp(revData, "停车") == 0)
		{
			send(*ClientSocket, "停车功能待实现\n\n*******请进行用户功能选择*********\n******1.停车**********2.取车******\n******3.退出登录********\n\n", sizeof(sendData), 0);
		}
		else
		{
			send(*ClientSocket, "无效操作\n", sizeof(sendData), 0);
		}
	}
	closesocket(*ClientSocket);
	free(ClientSocket);
	return 0;
}



int main(){
	m.initParking();
	WSAData wsd;
	WSAStartup(MAKEWORD(2, 2), &wsd);
	SOCKET ListenSocket = socket(AF_INET, SOCK_STREAM, 0);
	SOCKADDR_IN ListenAddr;
	ListenAddr.sin_family = AF_INET;
	ListenAddr.sin_addr.S_un.S_addr = INADDR_ANY;//表示填入本机ip
	ListenAddr.sin_port = htons(PORT);
	int n;
	n = bind(ListenSocket, (LPSOCKADDR)&ListenAddr, sizeof(ListenAddr));
	if (n == SOCKET_ERROR){
		cout << "端口绑定失败！" << endl;
		return -1;
	}
	else{
		cout << "端口绑定成功：" << PORT << endl;
	}
	int l = listen(ListenSocket, 20);
	cout << "服务端准备就绪，等待连接请求" << endl;

	while (1){
		//循环接收客户端连接请求并创建服务线程
		SOCKET *ClientSocket = new SOCKET;
		ClientSocket = (SOCKET*)malloc(sizeof(SOCKET));
		//接收客户端连接请求
		int SockAddrlen = sizeof(sockaddr);
		*ClientSocket = accept(ListenSocket, 0, 0);
		cout << "一个客户端已连接到服务器，socket是：" << *ClientSocket << endl;
		CreateThread(NULL, 0, &ServerThread, ClientSocket, 0, NULL);
	}//while
	closesocket(ListenSocket);
	WSACleanup();
	system("pause");
	return(0);
}//main

