	code[0] = buff[0];
            	code[1] = buff[1];
            	code[2] = buff[2];

	if(strcmp(code,"354") == 0)
            {
                printf("\nReady to send header data!\n\n");
            }
            else{
                printf("\nError occured!\n\n");
            }

            	//creating a mail header
            	char sub[150];
            	char content[450];
            	printf("\nEnter Subject : ");
            	scanf("%[^\n]",sub);
            	printf("\nEnter content : (Press Tab and Enter Key to end)\n");
            	scanf("%[^\t]",content);

            	bzero(buff,10240);
            	//Mail_header function declared above
            	strcpy(buff, Mail_Header(mail_from,mail_to,sub,content));
		//assigning header to buffer
            	n = write(socket_id,buff,strlen(buff));
            if(n < 0)
            {
                printf("\nError occured while writing to socket!\n");
            }
            	printf("\nCLIENT : ====| Mail header & content |====\n%s\n",buff);
		//header content
            	bzero(buff,10240);
            	strcpy(buff,".\r\n");
            	n = write(socket_id,buff,strlen(buff));
            if(n < 0)
            {
                printf("\nError occured while writing to socket!\n");
            }
            bzero(buff,10240);
            n = read(socket_id,buff,10239);
            if(n < 0)
            {
                printf("\nError occured while reading from socket!\n");
            }
            	printf("SERVER : %s\n",buff);     //250 OK

            	//checking error
            	code[0] = buff[0];
            	code[1] = buff[1];
            	code[2] = buff[2];
            	code[3] = '\0';
		code[3] = '\0';
