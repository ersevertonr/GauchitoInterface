carregar:
	@echo SALVANDO REMOTAMENTE NO GIT
	@echo ------------------------------
	git push
	@echo ------------------------------
	@echo ALTERACOES SALVAS COM SUCESSO

salvar:
	@echo SALVANDO REMOTAMENTE NO GIT
	@echo ------------------------------
	git commit
	git pull origin master
	@echo ------------------------------
	@echo ALTERACOES SALVAS COM SUCESSO
