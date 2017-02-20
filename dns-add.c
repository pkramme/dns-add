#include<stdio.h>
#include<string.h>

#define CONFIG_PATH "/etc/dnsmasq.d/50-dns-add.conf"
#define COPY_CONFIG_PATH "CONFIG_PATH.temp"

int main(int argc, char *argv[])
{
	if(argc <= 2)
	{
		printf("USAGE");
	}

	if(argc >= 4)
	{
		if(strcmp(argv[1], "add") == 0)
		{
			FILE *config = fopen(CONFIG_PATH, "a+");
			fprintf(config, "address=/%s/%s\n", argv[2], argv[3]);
			fclose(config);
		}
	}
	else if(argc >= 3)
	{
		if(strcmp(argv[1], "rm") == 0)
		{
			FILE *config = fopen(CONFIG_PATH, "r");
			FILE *copyconfig = fopen(COPY_CONFIG_PATH, "w");
			char buffer[256];
			while(fgets(buffer, sizeof(buffer), config) != NULL)
			{
				if(strstr(buffer, argv[2]))
				{
					/*DO NOTHING*/
				}
				else
				{
					fprintf(copyconfig, "%s", buffer);
				}
			}
			fclose(config);
			fclose(copyconfig);
			rename(COPY_CONFIG_PATH, CONFIG_PATH);
		}
	}
	return 0;
}

