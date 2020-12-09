# Projeto sistemas operacionais embarcados

O seguinte projeto propõe um sistema para fermentação culinária, uma estufa para massas, constituído pelo aquecimento do meio e que também coleta de dados dos processos. O projeto foi desenvolvido na displina de sistemas operacionais embarcados, no semestre de 2020/1 na Universidade de Brasília(UNB), campus do Gama(FGA).

## Dependências

- [OpenCV](https://opencv.org/)
- [Compilador de C++ e C](https://gcc.gnu.org/)
- [CMake](https://cmake.org/)
- [Sitema Operacional Linux](https://ubuntu.com/)

## Inicialização

Clone o repositório
```
git clone https://github.com/jschneiderm98/projetoEmbarcados
```
Edite o diretório do sensor, para o seu sensor no arquivo tempMeasure.c
```
fp=fopen("/sys/bus/w1/devices/28-3c01a81664b5/w1_slave","r")
```
Adicione o diretório do OpenCV na sua Raspberry Pi, no arquivo CMakeLists.txt

![CMakeLists print screen](https://raw.githubusercontent.com/jschneiderm98/projetoEmbarcados/main/assets/cmakelists.png)

Crie uma pasta build e vá para ela
```
mkdir build && cd build
```
Inicie o CMake
```
cmake ..
```
Compile o código utilizando o Make
```
make
```
Execute o arquivo
```
./breadMake
```
