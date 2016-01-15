carregar:
	@echo CARREGANDO DADOS DO REPOSITORIO
	@echo ------------------------------
	git push
	@echo ------------------------------
	@echo REPOSITÓRIO CARREGADO

salvar:
	@echo SALVANDO REMOTAMENTE NO GIT
	@echo ------------------------------
	git commit -m "Desenvolvimento"
	git pull
	@echo ------------------------------
	@echo ALTERACOES SALVAS COM SUCESSO
