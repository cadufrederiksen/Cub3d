# 🎮 Cub3D - Motor Gráfico 3D com Raycasting

![C](https://img.shields.io/badge/Language-C-blue) ![MiniLibX](https://img.shields.io/badge/Library-MiniLibX-orange) ![Makefile](https://img.shields.io/badge/Build-Makefile-yellow) ![Graphics](https://img.shields.io/badge/Feature-Graphics-green)

**Cub3D** é um projeto que introduz os alunos ao desenvolvimento gráfico utilizando técnicas de **raycasting**. Inspirado no clássico **Wolfenstein 3D**, o objetivo é criar um motor de renderização 3D básico que permita navegar por um labirinto interativo. Este projeto combina habilidades de programação, conceitos matemáticos e fundamentos de gráficos computacionais para criar uma experiência imersiva em 2.5D.

---

## 📋 Objetivo do Projeto

Desenvolver um jogo de labirinto 3D utilizando:
- **Raycasting** para simular a projeção 3D em um ambiente 2D.  
- Técnicas de **mapeamento de texturas**, **detecção de colisões** e **transformações geométricas**.  
- Simulação de um ambiente tridimensional com iluminação e sombreamento básicos.  

O jogo permitirá que o jogador explore o labirinto, interaja com objetos e navegue por diferentes desafios.

---

## 📚 Conceitos Fundamentais

- **Raycasting**: técnica para projetar raios em um ambiente 2D e determinar a posição e a distância de objetos para simular profundidade.  
- **Mapeamento de Texturas**: aplicação de imagens em superfícies para criar realismo no ambiente.  
- **Colisões**: detecção e resposta a interações físicas entre o jogador e o cenário.  
- **Transformações Geométricas**: manipulação de coordenadas para simular movimento e perspectiva.  
- **MiniLibX**: biblioteca gráfica simplificada para renderização 2D e 3D.  

---

## ✨ Funcionalidades Implementadas

### 🎨 Gráficos e Renderização
- **Raycasting**: renderização eficiente para simular profundidade em um espaço 3D.  
- **Mapeamento de Texturas**:
  - Texturas aplicadas às paredes e ao chão do labirinto.  
- **Iluminação Básica**:
  - Simulação de sombreamento com base na distância dos objetos.  

### 🚪 Gameplay
- **Movimento do Jogador**:
  - Navegação suave pelo labirinto com controles de teclado.  
- **Colisões**:
  - Sistema para evitar que o jogador atravesse paredes ou objetos sólidos.  
- **Interatividade**:
  - Interação com objetos e possíveis elementos móveis.  

### ⚙️ Configuração do Ambiente
- **Arquivos de Configuração**:
  - Arquivo `.cub` para definir o layout do labirinto, as texturas e os parâmetros de renderização.  
- **Renderização Dinâmica**:
  - Atualização em tempo real com base nos movimentos do jogador.  

---

## 🛠️ Ferramentas e Padrões

| Ferramenta/Padrão       | Descrição                                              |
|--------------------------|------------------------------------------------------|
| **MiniLibX**            | Biblioteca gráfica simplificada usada para renderização. |
| **Raycasting**          | Técnica para projetar raios e calcular a profundidade. |
| **C**                   | Linguagem de programação principal do projeto.        |
| **Makefile**            | Automação da compilação e geração do executável.      |
| **Norminette**          | Conformidade com os padrões de estilo da 42.          |

---

