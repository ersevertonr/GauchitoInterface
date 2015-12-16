install:
	@echo GAUCHITO API - INSTALLER
	@echo =============================================
	@echo
	@read -p "Arduino sketchbook library folder : " lib_folder;  \
	if test -d $$lib_folder; then 	                             \
           echo "[INSTALLING] on: $$lib_folder";           	     \
	   cp -r ./GauchitoAPI/* $$lib_folder;                       \
	else							     \
		echo "[ERROR] \"$$lib_folder \"directory not found"; \
	fi

update:
	@echo UPDATING
	@echo ==============================================
	git pull origin master
