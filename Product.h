//Product.h
#ifndef __PRODUCT_H__
#define __PRODUCT_H__

#include <string>

class Product {
public:
	Product();
	Product(int cod, const std::string &nome, int qtde, float valorUnitario);
	

	int GetCod() const;
	void SetCod(int novoCod);
	std::string GetNome() const;
	void SetNome(std::string novoNome);
	int GetQtde() const;
	void SetQtde(int novaQtde);
	float GetValorUnitario() const;
	void SetValorUnitario(float novoValor);

private:
	int m_cod;
	std::string m_nome;
	int m_qtde;
	float m_valorUnitario;
};

#endif