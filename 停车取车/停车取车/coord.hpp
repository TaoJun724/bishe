#ifndef COORD_HPP
#define COORD_HPP

#include"Comm.hpp"
#include<vector>
#include"Road.h"
#include"amgraph.h"
#define BOUNDS_CHECK
using namespace itlab;
//停车场A
Road R0, R1, R2, R3, R4, R5, R6, R7, R8,R9,R10, R11, R12, R13, R14, R15, R16, R17, R18, R19, R20;
Road R21, R22, R23, R24, R25, R26, R27, R28, R29, R30, R31, R32, R33, R34, R35, R36, R37, R38, R39, R40, R41;
Road C0, C1, C2, C3, C4, C5, C6, C7, C8, C9, C10, C11, C12, C13, C14, C15, C16, C17, C18, C19, C20;
Road C21, C22, C23, C24, C25, C26, C27, C28, C29, C30, C31, C32, C33, C34, C35, C36, C37, C38, C39, C40;
Road C41, C42, C43, C44, C45, C46, C47, C48, C49, C50, C51, C52, C53, C54, C55, C56, C57, C58, C59, C60;
Road C61, C62, C63, C64, C65, C66, C67, C68, C69, C70;
Road T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11;
Road E0, E1, E2, E3;


//停车场B
Road R42, R43, R44, R45, R46, R47, R48, R49, R50, R51, R52, R53, R54, R55, R56, R57;
Road T12, T13, T14, T15, T16, T17;
Road E4, E5, E6, E7;
Road C71, C72, C73, C74, C75, C76, C77, C78, C79, C80, C81, C82, C83, C84;


//四种属性点的坐标存储数组
vector<Road> lineVect;
vector<Road> eleVect;
vector<Road> berVect;
vector<Road> spaceVect;

//记录各车位状态
vector<Road> spaceA;
vector<Road> spaceB;
vector<Road> spaceC;

vector<Road> bLine;

class Coord
{
public:

	//初始化A
	void InitParkingAPoint(AMGraph<char, int>& parkingA)
	{
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

	void InitParkingAEdge(AMGraph<char, int>& parkingA)
	{
		parkingA.insertEdge(R0, R2, 1);	parkingA.insertEdge(R2, R4, 5);
		parkingA.insertEdge(R4, C0, 2);	parkingA.insertEdge(R4, C1, 2);
		parkingA.insertEdge(C0, R4, 2);	parkingA.insertEdge(C1, R4, 2);
		parkingA.insertEdge(R3, R1, 6);	parkingA.insertEdge(R4, R3, 3);
		parkingA.insertEdge(R3, R4, 3);		parkingA.insertEdge(R4, R6, 3);
		parkingA.insertEdge(R6, C2, 2);
		parkingA.insertEdge(R6, C3, 3);	parkingA.insertEdge(C2, R6, 2);
		parkingA.insertEdge(C3, R6, 3);	parkingA.insertEdge(R6, R3, 7);
		parkingA.insertEdge(R6, R5, 2);	parkingA.insertEdge(R5, R6, 2);
		parkingA.insertEdge(R5, R3, 5);
		parkingA.insertEdge(R6, R8, 5);
		parkingA.insertEdge(R8, C4, 4);
		parkingA.insertEdge(R8, C5, 5);
		parkingA.insertEdge(C4, R8, 4);
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
	//初始化B
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

	//路顶点信息获取
	//线路点
	void Line(vector<Road> &v)
	{
		v.push_back(R1); v.push_back(R2); v.push_back(R3); v.push_back(R4); v.push_back(R5); v.push_back(R6); v.push_back(R7); v.push_back(R8); v.push_back(R9);
		v.push_back(R10); v.push_back(R11); v.push_back(R12); v.push_back(R13); v.push_back(R14); v.push_back(R15); v.push_back(R16); v.push_back(R17);
		v.push_back(R18); v.push_back(R19); v.push_back(R20); v.push_back(R21); v.push_back(R22); v.push_back(R23); v.push_back(R24); v.push_back(R25);
		v.push_back(R26); v.push_back(R27); v.push_back(R28); v.push_back(R29); v.push_back(R30); v.push_back(R31); v.push_back(R32); v.push_back(R33);
		v.push_back(R34); v.push_back(R35); v.push_back(R36); v.push_back(R37); v.push_back(R38); v.push_back(R39); v.push_back(R40); v.push_back(R41);
		v.push_back(R42); v.push_back(R43); v.push_back(R44); v.push_back(R45); v.push_back(R46); v.push_back(R47); v.push_back(R48); v.push_back(R49);
		v.push_back(R50); v.push_back(R51); v.push_back(R52); v.push_back(R53); v.push_back(R54); v.push_back(R55); v.push_back(R56);
		int i = 0;
		int size = 0;
		FILE* fp1;
		fp1 = fopen("便道.txt", "r");
		while (1)
		{
			if (size == v.size())
				break;
			fscanf(fp1, "%d", &(v[i].x));
			fscanf(fp1, "%d", &(v[i].y));
			if (v[i].x < 0)
				break;
			//cout << "请输入局部区域的长度与宽度" << endl;
			//int wide, length;
			fscanf(fp1, "%d", &(v[i].length));
			fscanf(fp1, "%d", &(v[i].wide));
			i++;
			size++;
		}
		fclose(fp1);
	}
	//初始化B停车场的便道
	void LineB(vector<Road> &v)
	{		
		char buf[1024]; 
		FILE *fp;                   
		fp = fopen("B线路.txt", "r");
		while (1)
		{
			Road ret;
			fgets(buf, 1024, fp);
			ret.index1 += buf[0];
			ret.index1 += buf[1];
			ret.index1 += buf[2];
			v.push_back(ret);
			if (v.size() == 15)
				break;
		}
		fclose(fp);

		int size = 0;
		int i = 0;
		FILE* fp1;
		fp1 = fopen("B线路坐标.txt", "r");
		while (1)
		{
			if (size == v.size())
				break;
			fscanf(fp1, "%d", &(v[i].x));
			fscanf(fp1, "%d", &(v[i].y));
			if (v[i].x < 0)
				break;
			//cout << "请输入局部区域的长度与宽度" << endl;
			//int wide, length;
			fscanf(fp1, "%d", &(v[i].length));
			fscanf(fp1, "%d", &(v[i].wide));
			i++;
			size++;
		}
		fclose(fp1);

	}
	//充电点
	void Ele(vector<Road> &v)
	{
		v.push_back(E0); v.push_back(E1); v.push_back(E2); v.push_back(E3); v.push_back(E4); v.push_back(E5); v.push_back(E6);
		v.push_back(E7);
		int i = 0;
		int size = 0;
		FILE* fp1;
		fp1 = fopen("充电区.txt", "r");
		while (1)
		{
			if (size == v.size())
				break;
			fscanf(fp1, "%d", &(v[i].x));
			fscanf(fp1, "%d", &(v[i].y));
			if (v[i].x < 0)
				break;
			//cout << "请输入局部区域的长度与宽度" << endl;
			//int wide, length;
			fscanf(fp1, "%d", &(v[i].length));
			fscanf(fp1, "%d", &(v[i].wide));
			i++;
			size++;
		}
		fclose(fp1);
	}
	//停靠点
	void Berth(vector<Road> &v)
	{
		v.push_back(T0); v.push_back(T1); v.push_back(T2); v.push_back(T3); v.push_back(T4); v.push_back(T5);
		v.push_back(T6); v.push_back(T7); v.push_back(T8); v.push_back(T9); v.push_back(T10); v.push_back(T11);
		v.push_back(T12); v.push_back(T13); v.push_back(T14); v.push_back(T15); v.push_back(T16); v.push_back(T17);
		int i = 0;
		int size = 0;
		FILE* fp1;
		fp1 = fopen("小车停靠区.txt", "r");
		while (1)
		{
			if (size == v.size())
				break;
			fscanf(fp1, "%d", &(v[i].x));
			fscanf(fp1, "%d", &(v[i].y));
			if (v[i].x < 0)
				break;
			//cout << "请输入局部区域的长度与宽度" << endl;
			//int wide, length;
			fscanf(fp1, "%d", &(v[i].length));
			fscanf(fp1, "%d", &(v[i].wide));
			i++;
			size++;
		}
		fclose(fp1);
	}
	//车位
	void Space(vector<Road> &v)
	{
		v.push_back(C0); v.push_back(C1); v.push_back(C2); v.push_back(C3); v.push_back(C4); v.push_back(C5); v.push_back(C6); v.push_back(C7); v.push_back(C8);
		v.push_back(C9); v.push_back(C10); v.push_back(C11); v.push_back(C12); v.push_back(C13); v.push_back(C14); v.push_back(C15); v.push_back(C16);
		v.push_back(C17); v.push_back(C18); v.push_back(C19); v.push_back(C20); v.push_back(C21); v.push_back(C22); v.push_back(C23); v.push_back(C24);
		v.push_back(C25); v.push_back(C26); v.push_back(C27); v.push_back(C28); v.push_back(C29); v.push_back(C30); v.push_back(C31); v.push_back(C32);
		v.push_back(C33); v.push_back(C34); v.push_back(C35); v.push_back(C36); v.push_back(C37); v.push_back(C38); v.push_back(C39); v.push_back(C40);
		v.push_back(C41); v.push_back(C42); v.push_back(C43); v.push_back(C44); v.push_back(C45); v.push_back(C46); v.push_back(C47); v.push_back(C48);
		v.push_back(C49); v.push_back(C50); v.push_back(C51); v.push_back(C52); v.push_back(C53); v.push_back(C54); v.push_back(C55); v.push_back(C56);
		v.push_back(C57); v.push_back(C58); v.push_back(C59); v.push_back(C60); v.push_back(C61); v.push_back(C62); v.push_back(C63); v.push_back(C64);
		v.push_back(C65); v.push_back(C66); v.push_back(C67); v.push_back(C68); v.push_back(C69); v.push_back(C70); v.push_back(C71); v.push_back(C72);
		v.push_back(C73); v.push_back(C74); v.push_back(C75); v.push_back(C76); v.push_back(C77); v.push_back(C78); v.push_back(C79); v.push_back(C80);
		v.push_back(C81); v.push_back(C82); v.push_back(C83); v.push_back(C84); 
		int i = 0;
		int size = 0;
		FILE* fp1;
		fp1 = fopen("车位.txt", "r");
		while (1)
		{
			if (size == v.size())
				break;
			fscanf(fp1, "%d", &(v[i].x));
			fscanf(fp1, "%d", &(v[i].y));
			if (v[i].x < 0)
				break;
			//cout << "请输入局部区域的长度与宽度" << endl;
			//int wide, length;
			fscanf(fp1, "%d", &(v[i].length));
			fscanf(fp1, "%d", &(v[i].wide));
			i++;
			size++;
		}
		fclose(fp1);
	}

	void SpaceA(vector<Road> &v)
	{
		v.push_back(C0); v.push_back(C1); v.push_back(C2); v.push_back(C3); v.push_back(C4); v.push_back(C5); v.push_back(C6); v.push_back(C7); v.push_back(C8);
		v.push_back(C9); v.push_back(C10); v.push_back(C11); v.push_back(C12); v.push_back(C13); v.push_back(C14); v.push_back(C15); v.push_back(C16);
		v.push_back(C17); v.push_back(C18); v.push_back(C19); v.push_back(C20); v.push_back(C21); v.push_back(C22); v.push_back(C23); v.push_back(C24);
		v.push_back(C25); v.push_back(C26); v.push_back(C27); v.push_back(C28); v.push_back(C29); v.push_back(C30); v.push_back(C31); v.push_back(C32);
		v.push_back(C33); v.push_back(C34); v.push_back(C35); v.push_back(C36);  v.push_back(C53); v.push_back(C54); v.push_back(C55); v.push_back(C56);
		v.push_back(C57); v.push_back(C58); v.push_back(C59); v.push_back(C60); v.push_back(C61); v.push_back(C62); v.push_back(C63); v.push_back(C64);
		v.push_back(C65); v.push_back(C66); v.push_back(C67); v.push_back(C68); v.push_back(C69); v.push_back(C70);
		int i = 0;
		int size = 0;
		FILE* fp1;
		fp1 = fopen("功能A车位.txt", "r");
		while (1)
		{
			if (size == v.size())
				break;
			fscanf(fp1, "%d", &(v[i].x));
			fscanf(fp1, "%d", &(v[i].y));
			if (v[i].x < 0)
				break;
			//cout << "请输入局部区域的长度与宽度" << endl;
			//int wide, length;
			fscanf(fp1, "%d", &(v[i].length));
			fscanf(fp1, "%d", &(v[i].wide));
			i++;
			size++;
		}
		fclose(fp1);
	}

	void SpaceB(vector<Road> &v)
	{
	    v.push_back(C71); v.push_back(C72);
		v.push_back(C73); v.push_back(C74); v.push_back(C75); v.push_back(C76); v.push_back(C77); v.push_back(C78); v.push_back(C79); v.push_back(C80);
		v.push_back(C81); v.push_back(C82); v.push_back(C83); v.push_back(C84);
		int i = 0;
		int size = 0;
		FILE* fp1;
		fp1 = fopen("功能B车位.txt", "r");
		while (1)
		{
			if (size == v.size())
				break;
			fscanf(fp1, "%d", &(v[i].x));
			fscanf(fp1, "%d", &(v[i].y));
			if (v[i].x < 0)
				break;
			//cout << "请输入局部区域的长度与宽度" << endl;
			//int wide, length;
			fscanf(fp1, "%d", &(v[i].length));
			fscanf(fp1, "%d", &(v[i].wide));
			i++;
			size++;
		}
		fclose(fp1);
	}

	void SpaceC(vector<Road> &v)
	{
		 v.push_back(C37); v.push_back(C38); v.push_back(C39); v.push_back(C40);
		v.push_back(C41); v.push_back(C42); v.push_back(C43); v.push_back(C44); v.push_back(C45); v.push_back(C46); v.push_back(C47); v.push_back(C48);
		v.push_back(C49); v.push_back(C50); v.push_back(C51); v.push_back(C52);
		int i = 0;
		int size = 0;
		FILE* fp1;
		fp1 = fopen("功能共用车位.txt", "r");
		while (1)
		{
			if (size == v.size())
				break;
			fscanf(fp1, "%d", &(v[i].x));
			fscanf(fp1, "%d", &(v[i].y));
			if (v[i].x < 0)
				break;
			//cout << "请输入局部区域的长度与宽度" << endl;
			//int wide, length;
			fscanf(fp1, "%d", &(v[i].length));
			fscanf(fp1, "%d", &(v[i].wide));
			i++;
			size++;
		}
		fclose(fp1);
	}
};


#endif
