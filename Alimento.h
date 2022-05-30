//Product.h
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