# 🎶 Projeto: Música de Páscoa com LCD e Buzzer (Arduino)

Este projeto exibe a música **"Coelhinho da Páscoa"** em um display **LCD 16x2**, enquanto um **buzzer passivo** toca a melodia no ritmo suave da canção tradicional.

✨ Ideal para apresentações escolares, decoração de Páscoa ou projetos didáticos de Arduino!

---

## 📋 Materiais Utilizados

- Arduino Uno
- Display LCD 16x2 (com comunicação paralela)
- Buzzer passivo
- Jumpers (cabos)
- Protoboard
- Resistores (opcional, para proteção do circuito)

---

## 🎵 Funcionalidades

- Mensagem de boas-vindas **"Feliz Páscoa!"** com animação de rolagem.
- Exibição da letra da música em duas linhas por vez no LCD.
- Reprodução da melodia de "Coelhinho da Páscoa" no buzzer, com ritmo suave e melodioso.
- Ciclo contínuo da música e da letra.

---

## 🛠️ Montagem do Circuito

- **LCD:**
  - RS ➔ pino 12
  - EN ➔ pino 11
  - D4 ➔ pino 5
  - D5 ➔ pino 4
  - D6 ➔ pino 3
  - D7 ➔ pino 2
- **Buzzer Passivo:**
  - Sinal ➔ pino 8
  - GND ➔ GND do Arduino

> **Obs.:** Ajuste o contraste do LCD utilizando um potenciômetro, se necessário.

---

## 📜 Código-Fonte

O código organiza a letra da música em blocos, sincroniza a exibição no LCD com o som do buzzer e cria uma experiência suave e alegre.

> 💡 **Destaques do código:** uso de arrays para organizar a letra e a melodia, controle de ritmo usando `tone()` e `delay()`, e rolagem animada da mensagem inicial.

---

## 🎥 Demonstração (Opcional)

(*Aqui você pode adicionar um gif ou link para o vídeo mostrando o projeto funcionando!*)

---

## 📖 Licença

Este projeto está disponível sob a licença MIT. Sinta-se livre para usar, modificar e compartilhar! 🎉

---

# 🐰 Feliz Páscoa e boas criações!
