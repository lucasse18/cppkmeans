#include "IteracaoSimples.h"

//TODO verificar erros
bool IteracaoSimples::itera(Dataset *dados, vector<Centro> *centros) {

  float RSS;

  for(unsigned i = 0; i < dados->getNExemplos(); ++i) {
    dados->getExemplos().at(i).setCentro(0);
  }
  centros->at(0).setQtdExemplos(150);

  while(atribui(dados, centros)) {
    RSS = 0;
    for(unsigned i = 0; i < dados->getNExemplos(); ++i) {
      RSS += Distancia::calc(dados->getExemplos().at(i).getAtributos(), centros->at(dados->getExemplos().at(i).getCentro()).getAtributos(), dados->getNAtributos());
    }
    cout << "RSS: " << RSS << "\n";
    recomputa(dados, centros);
  }
  for(unsigned i = 0; i < dados->getK(); ++i) {
    cout << centros->at(i).getQtdExemplos() << " exemplos no centro " << i << '\n';
  }

  return true;
}

unsigned long IteracaoSimples::atribui(Dataset *dados, vector<Centro> *centros) {

  unsigned long melhor, trocas = 0;
  float menorDistancia, atualDistancia;

  for(unsigned i = 0; i < dados->getNExemplos(); ++i) {
    melhor = dados->getExemplos().at(i).getCentro();
    menorDistancia = Distancia::calc(dados->getExemplos().at(i).getAtributos(), centros->at(melhor).getAtributos(), dados->getNAtributos());
    for(unsigned j = 0; j < dados->getK(); ++j) {
      atualDistancia = Distancia::calc(dados->getExemplos().at(i).getAtributos(), centros->at(j).getAtributos(), dados->getNAtributos());
      if(atualDistancia < menorDistancia) {
        centros->at(dados->getExemplos().at(i).getCentro()).setQtdExemplos(centros->at(dados->getExemplos().at(i).getCentro()).getQtdExemplos() - 1);
        dados->getExemplos().at(i).setCentro(j);
        centros->at(j).setQtdExemplos(centros->at(j).getQtdExemplos() + 1);
      }
      /*else if(atualDistancia == menorDistancia)
        cout << "Warning: distancias iguais\n";*/
    }
    if(dados->getExemplos().at(i).getCentro() != melhor)
      trocas++;
  }

  for(unsigned i = 0; i < dados->getK(); ++i) {
    cout << centros->at(i).getQtdExemplos() << " exemplos no grupo " << i << '\n';
  }

  cout << "Trocas: " << trocas << '\n';
  return trocas;
}

void IteracaoSimples::recomputa(Dataset *dados, vector<Centro> *centros) {
  float *acumulador = (float *)malloc(dados->getK() * sizeof(float));
  for(unsigned i = 0; i < dados->getNAtributos(); ++i) {
    for(unsigned j = 0; j < dados->getNExemplos(); ++j) {
      acumulador[dados->getExemplos().at(j).getCentro()] += dados->getExemplos().at(j).getAtributos().at(i);

    }

    for(unsigned j = 0; j < dados->getK(); ++j) {
      if(centros->at(j).getQtdExemplos() > 0) {
        /*cout << "Acumulador: " << acumulador[j];
        cout << ", Qtd exemplos: " << centros->at(j).getQtdExemplos() << '\n';
        cout << "Centro antes: ";
        cout << centros->at(j).getAtributos().at(i) << ',';
        cout << '\n';*/

        centros->at(j).setAtributo((acumulador[j]/centros->at(j).getQtdExemplos()), i);

        /*cout << "Centro depois: ";
        cout << centros->at(j).getAtributos().at(i) << ',';
        cout << '\n';*/
      }
    }
  }
  for(unsigned i = 0; i < dados->getK(); ++i) {
    cout << "Centro: ";
    for(unsigned j = 0; j < dados->getNAtributos(); ++j) {
      cout << centros->at(i).getAtributos().at(j) << ',';
    }
    cout << '\n';
  }
}
