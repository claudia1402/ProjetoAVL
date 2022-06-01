// ---------- Projeto II AVL - EDII ------------
// --------- Grupo cavalo_sentado.png ----------
// 	Claudia Fiorentino Andrade 		- 42005302
// 	João Victor Ferreira Pimenta 	- 42005876
// 	Joyce Cui 						- 42017157
//	Ryan Marco Andrade dos Santos 	- 42080223
// 	Victor Prado Chaves 			- 32070772

//Alimento.h
#ifndef __ALIMENTO_H__
#define __ALIMENTO_H__

#include <string>
#include <list>

class Alimento {
public:
	Alimento();
	Alimento(std::string dados[]);
	// food & serving: nome
	// array nutrientes:
	// Calorias: float (g)
	// total gordura: float (g)
	// sodio: float (g)
	// potassio: float (g)
	// total carboidrato: float (g)
	// fibra dietética: float (g)
	// acucares: float (g)
	// proteina: float (g)
	// gordura saturada: float (mg)
	// colesterol: float (mg)
	std::string GetNome() const;
	void SetNome(std::string novoNome);
	std::list<float> GetNutrientes();
	void SetNutrientes();

private:
	std::string m_nome;
	std::list<float> m_nutrientes;
};

#endif