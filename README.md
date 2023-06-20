# Boost
Aprendendo sobre a biblioteca Boost C++

### Instalação no Windows: Visual Studio 2022

	Unzip to a path of your choice for eg E:\boost
	Open Developer Command Prompt For VS 2022 and cd into extracted boost directory
	Issue the command bootstrap vc143 hit Enter and wait
	Next issue the command .\b2 hit Enter and grab tea or coffee.

	Next, on Project -> Settings:
	C/C++ -> Geral -> Diretórios de Inclusão Adicionais: E:\boost
	Vinculador -> Geral -> Diretórios de Biblioteca Adicionais: E:\boost\stage\lib
