#include "lima_cpu_lib.h"

#include <iostream>

std::string n_string = "474809754727201286617503413061677388505126074492005644486710"
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

// TODO: include main.
int main(int argc, char** argv) {
  std::cerr << "hello world" << std::endl;
  convert(boost::multiprecision::cpp_int(n_string));
  // TODO: Get constants.
}
