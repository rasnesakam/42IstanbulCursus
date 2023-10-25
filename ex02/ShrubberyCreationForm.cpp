#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>
#include <iostream>

ShrubberyCreationForm::ShrubberyCreationForm(){
	this->target = "default";
}
ShrubberyCreationForm::~ShrubberyCreationForm(){}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& oth){
	*this = oth;
}
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& oth) {
	this->target = oth.target;
	return *this;
}
ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target): AForm("ShrubberyCreationForm",25,5){
	this->target = target;
}

const std::string ShrubberyCreationForm::getTarget() const {
	return this->target;
}

void ShrubberyCreationForm::execute(const Bureaucrat& bureaucrat) const{
	if (this->isSigned()){
		if (this->getGradeToExecute() >= bureaucrat.getGrade()){
			std::ofstream target_file((this->getTarget()+"_shrubbery").c_str());
            if (!target_file)
            {
                std::cout << "Failed to create file" << std::endl;
                return;
            }
			target_file << " ###########################  V##'############################" << std::endl;
			target_file << " ###########################'`################################" << std::endl;
			target_file << " #########################V'  `V  ############################" << std::endl;
			target_file << " ########################V'      ,############################" << std::endl;
			target_file << " #########`#############V      ,A###########################V" << std::endl;
			target_file << " ########' `###########V      ,###########################V',#" << std::endl;
			target_file << " ######V'   ###########l      ,####################V~~~~'',###" << std::endl;
			target_file << " #####V'    ###########l      ##P' ###########V~~'   ,A#######" << std::endl;
			target_file << " #####l      d#########l      V'  ,#######V~'       A#########" << std::endl;
			target_file << " #####l      ##########l         ,####V''         ,###########" << std::endl;
			target_file << " #####l        `V######l        ,###V'   .....;A##############" << std::endl;
			target_file << " #####A,         `######A,     ,##V' ,A#######################" << std::endl;
			target_file << " #######A,        `######A,    #V'  A########'''''##########''" << std::endl;
			target_file << " ##########,,,       `####A,           `#''           '''  ,,," << std::endl;
			target_file << " #############A,                               ,,,     ,######" << std::endl;
			target_file << " ######################oooo,                 ;####, ,#########" << std::endl;
			target_file << " ##################P'                   A,   ;#####V##########" << std::endl;
			target_file << " #####P'    ''''       ,###             `#,     `V############" << std::endl;
			target_file << " ##P'                ,d###;              ##,       `V#########" << std::endl;
			target_file << " ##########A,,   #########A              )##,    ##A,..,ooA###" << std::endl;
			target_file << " #############A, Y#########A,            )####, ,#############" << std::endl;
			target_file << " ###############A ############A,        ,###### ##############" << std::endl;
			target_file << " ###############################       ,#######V##############" << std::endl;
			target_file << " ###############################      ,#######################" << std::endl;
			target_file << " ##############################P    ,d########################" << std::endl;
			target_file << " ##############################'    d#########################" << std::endl;
			target_file << " ##############################     ##########################" << std::endl;
			target_file << " ##############################     ##########################" << std::endl;
			target_file << " #############################P     ##########################" << std::endl;
			target_file << " #############################'     ##########################" << std::endl;
			target_file << " ############################P      ##########################" << std::endl;
			target_file << " ###########################P'     ;##########################" << std::endl;
			target_file << " ###########################'     ,###########################" << std::endl;
			target_file << " ##########################       ############################" << std::endl;
			target_file << " #########################       ,############################" << std::endl;
			target_file << " ########################        d###########P'    `Y#########" << std::endl;
			target_file << " #######################        ,############        #########" << std::endl;
			target_file << " ######################        ,#############        #########" << std::endl;
			target_file << " #####################        ,##############b.    ,d#########" << std::endl;
			target_file << " ####################        ,################################" << std::endl;
			target_file << " ###################         #################################" << std::endl;
			target_file << " ##################          #######################P'  `V##P'" << std::endl;
			target_file << " #######P'     `V#           ###################P'" << std::endl;
			target_file << " #####P'                    ,#################P'" << std::endl;
			target_file << " ###P'                      d##############P''" << std::endl;
			target_file << " ##P'                       V##############'" << std::endl;
			target_file << " #P'                         `V###########'" << std::endl;
			target_file << " #'                             `V##P'" << std::endl;
		}

		else throw GradeTooHighException("grade is too high");
	}
	else
		throw AForm::FormNotSignedException("Form not signed");
}