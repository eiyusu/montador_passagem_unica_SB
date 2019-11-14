int is_instruction(std::string token);
int is_declared_symbol(std::vector<symbols> symbols_table, std::string symbols_aux);
std::vector<std::string> build(std::string file_name);
std::vector<std::string> file_reader_build(std::string input_file_name);

int is_instruction(std::string token){

	int flag;
	if (token == "ADD" || token ==  "SUB" || token ==  "MULT" || token ==  "DIV" || token ==  "JMP" || token ==  "JMPN" || token ==  "JMPP" || token ==  "JMPZ" || token == "COPY" || token ==  "LOAD" || token == "STORE" || token ==  "INPUT" || token ==  "OUTPUT" || token ==  "STOP"){
		flag = 1;
	}
	else{
		flag = 0;
	};

	return flag;
}

int is_declared_symbol(std::vector<symbols> symbols_table, std::string symbols_aux){
	int flag = 0;
	for (unsigned i = 0; i < symbols_table.size(); i++) {
		if (symbols_table[i].symbol_name == symbols_aux) {
			flag = 1;
		}
	};

	return flag;
}

//Função que gera um vetor do código pre processado
std::vector<std::string> file_reader_build(std::string input_file_name){

	std::ifstream input_file (input_file_name.append(".pre"));
	std::vector<std::string> word;
	char c;
	std::vector<char> word_c;
	char word_aux[50];
	unsigned i, j, k;

	word.push_back(" \n ");
	//Rotina para salvar o código em um vetor de caracteres ignorando os comentátios
	if(input_file.is_open()){
		while (input_file.get(c)){
			if (c == ';'){
				while(c != '\n'){
					input_file.get(c);
				};
				c = '\n';
				word_c.push_back(c);
			}
			else {
				if(c == '\n'){
					word_c.push_back(' ');
					word_c.push_back('\n');
					word_c.push_back(' ');
				}
				else{
					word_c.push_back(toupper(c));
				};
			};
		};
	};

			//Rotina para salvar o código em um vetor de strings ignorando espaços e quebras de linha
			i = 0;
			j = 0;
			k = 0;

			while((word_c[i] != ' ') && (word_c[i] != '\t') && (word_c[i] != '\n') && (i < word_c.size())){
					word_aux[j] = word_c[i];
					//std::cout << word_c[i] << "\n";
					i++;
					j++;
				};

			word_aux[i] = '\0';
			word.push_back(word_aux);
			//std::cout << word_aux << "\n";

			for(i = i; i < word_c.size(); i++){
				j = 0;
				if((word_c[i] != ' ') && (word_c[i] != '\t') && (word_c[i] != '\n')){
					while((word_c[i] != ' ') && (word_c[i] != '\t') && (word_c[i] != '\n') && (i < word_c.size())){
						word_aux[j] = word_c[i];
						i++;
						j++;
					}
					word.push_back(word_aux);
					//std::cout << word_aux << "\n";
				}

				else if (word_c[i] == '\n'){
					word_aux[j] = '\n';
					word.push_back(word_aux);
				};

				for(j=0;j<sizeof(word_aux);j++){
					word_aux[j] = '\0';
				};
				k++;
			};

		return word;
}

std::vector<std::string> build(std::string file_name){

	std::vector<std::string> program = file_reader_build(file_name);
	/*for(unsigned i=0; i<program.size();i++)
		std::cout << program[i] << ' ';*/

	int line = 1;
	int address = 0;
	int stopped = 0;
	std::string current_section;
	std::string aux;

	std::vector<build_structure> building_structure;
	build_structure build_aux;
	std::vector<symbols> symbols_table;
	symbols symbols_aux;

	for (unsigned i = 0; i < program.size(); i++) {
		if (program[i] == "\n") {
			i++;
			line+=1;
		}
		else if (program[i] == "SECTION") {
				i++;
				if(program[i] == "TEXT"){
					current_section = "TEXT";
				}
				else if(program[i] == "DATA") {
					current_section = "DATA";
				};
		}
		else if (program[i] == "ADD") {

		}
		else if (program[i] == "SUB") {

		}
		else if (program[i] == "MULT") {

		}
		else if (program[i] == "DIV") {

		}
		else if (program[i] == "JMP") {

		}
		else if (program[i] == "JMPN") {

		}
		else if (program[i] == "JMPP") {

		}
		else if (program[i] == "JMPZ") {

		}
		else if (program[i] == "COPY") {

		}
		else if (program[i] == "LOAD") {

		}
		else if (program[i] == "STORE") {

		}
		else if (program[i] == "INPUT") {

		}
		else if (program[i] == "OUTPUT") {

		}
		else if (program[i] == "STOP") {

		}
		else if (program[i].back() == ':') {
			if (is_declared_symbol(symbols_table, program[i]) == 0) {

				aux = program[i];
				aux.resize(aux.size()-1);
				symbols_aux.symbol_name = aux;
				symbols_aux.symbol_address = address;
				symbols_aux.symbol_line = line;
				symbols_aux.symbol_label = current_section;

			}

		}
	};


	return program;
}
