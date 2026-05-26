#  Sistema de Monitoramento Orbital — Global Solution 2026.1

Este projeto consiste num sistema em linguagem C desenvolvido para monitorizar informações críticas de uma missão espacial experimental. O software analisa telemetrias reais/simuladas obtidas através dos sensores da nave e emite alertas automáticos dependendo do status operacional dos sistemas.

---

**Funcionalidades Principais**
- **Registo de Telemetria:** Entrada de dados via teclado de temperatura, nível de energia e status de comunicação.
- **Validação Ativa de Dados (Fail-Safe):** Bloqueio de dados corrompidos ou fora dos limiares aceitáveis (como energia fora do intervalo 0-100% ou comunicação diferente de 0 e 1).
- **Análise Histórica Completa:** Varredura em tempo real de todo o histórico guardado na memória através de laços de repetição, avaliando as regras de segurança críticas:
  - Temperatura > 80°C: Alerta de Superaquecimento.
  - Energia < 20%: Modo de Economia de Energia.
  - Comunicação == 0: Alerta de Falha de Comunicação.
- **Histórico de Leituras:** Armazenamento estático dos dados inseridos utilizando vetores (arrays) globais com capacidade de até 100 registos.
- **Interface Estilizada (Terminal ANSI):** Alertas críticos exibidos em vermelho (`RED`) e avisos de atenção em amarelo (`YELLOW`) utilizando códigos de escape ANSI diretamente no terminal.

---

**Estrutura e Lógica do Código** 
O software foi desenhado seguindo as melhores práticas da programação estruturada:
- **Modularização:** Divisão limpa de responsabilidades em funções dedicadas (`inserirDados`, `visualizarStatus`, `analisarCondicoes`), mantendo a função `main` focada apenas no controlo do fluxo principal.
- **Menu Interativo Dinâmico:** Estrutura de repetição `do-while` integrada a um seletor `switch()`, permitindo navegação contínua até o encerramento explícito da missão.
- **Verificação Condicional Independente:** Uso de condicionais `if` independentes na análise de falhas, o que permite disparar múltiplos alertas simultâneos caso mais de um sistema falhe ao mesmo tempo.

---

**Como Compilar e Executar**

1. Certifique-se de que tem um compilador C (como o GCC) instalado no seu ambiente de desenvolvimento.
2. Clone ou descarregue os ficheiros do repositório.
3. Abra o terminal na raiz do projeto e compile o código-fonte:
   ```bash
   gcc main.c -o monitoramento
