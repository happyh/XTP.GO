ifdef M
LOG=$(M)
else
LOG=modify
endif

prepare:
	./elasticsearch_setup.sh
	./logstash_setup.sh
	./redis_setup.sh
	./kibana_setup.sh

zmq:
	./golang_setup.sh
	source /home/ubuntu/.bashrc

dep: prepare zmq

commit:
	git add --all :/ && git commit -a -m '$(LOG)'
	