build:
	docker buildx build \
    	--platform linux/amd64,linux/arm64 \
    	-t tymosh83/mikrobudzik \
    	.
buildnpush:
	docker buildx build \
		--platform linux/amd64,linux/arm64 \
		-t tymosh83/mikrobudzik \
		--push .
c:
	g++ ./src/*.cpp -std=c++17 -o a -lcurl