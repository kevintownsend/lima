#include "lima_cpu_lib.h"

#include <iostream>
#include <cmath>
#include <cinttypes>

std::string N_STRING = "474809754727201286617503413061677388505126074492005644486710"
    "619636071042455814765425270760494101231177589201256757906462"
    "053687463338505591900116762157771031136607205702942170513568"
    "430393481139013793780209643316395921689235118482669118001605"
    "519886679653623008552320068354906699567215583904228295559156"
    "849460306111329203904475384384648480711222838920423958171293"
    "110891982025021858635204389730623887202537819314111150742631"
    "144461349873631561421830476173554162699783903651772800068839"
    "401561061817976886834207039510014762029561669583444089424114"
    "790556556780829814902466852704523965014586209290411941287400"
    "776304104231428760477287686129441766402083279620913558718182"
    "645823558000382582372423580085016028485080973720098370355217"
    "935469186387604444337782243983407931357802908565807857573129"
    "024477859561522947241132683150266742576852000637175296327429"
    "629450606318225806436204878833839252826635151130492184785475"
    "0642192694541125065873977";

boost::multiprecision::cpp_int N(N_STRING);

uint64_t T = 72057594037927936ULL; // 2**56

std::string Z_STRING = "281925200789646054484626895242259073034267440683167652674260"
    "444591975889902849810168128895728145609121926279767832267892"
    "542066973188291684718744670094846726572899884983417621775255"
    "327210450830507578704233244224354792555227248423668532198826"
    "815434660322678303055198560726336871038927854530931214528139"
    "373062870256369865359829985298135548898569521934607434544000"
    "441455075616167756392020564099520298066717731321210733579077"
    "301206361429295031940789176281366976549232723977044834008951"
    "835696482863894992874097176920270620602720510686448265399942"
    "665576829947343992975331586905362399981263293987821422331239"
    "630446286999665633015654768670005653277971729589550900484148"
    "746877649612226774676201443379399666029879354208782911706544"
    "158175417730799622034258201586627351071911874884702195535013"
    "165691782737205797563610954623717953897626420548504301835206"
    "050378592457192577621469438707103550461448491697592874506496"
    "0514158355537463493917412";

boost::multiprecision::cpp_int Z(Z_STRING);


// TODO: include main.
int main(int argc, char** argv) {
  std::cerr << "hello world" << std::endl;
  convert(N, 26);
  // TODO: loop
  // TODO: square value
  // TODO: modulo math.
}