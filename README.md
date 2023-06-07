# Exam_Trifonova_221-332

## Docker

https://hub.docker.com/repository/docker/trifonovada/trifonova_221-332/general

docker login
docker build -t trifonovada/trifonova_221-332 .
docker push trifonovada/trifonova_221-332
docker run  --name exam -p 33333:33333 -t -i trifonovada/trifonova_221-332

![image](https://github.com/DaryaTrifonova/Exam_Trifonova_221-332/assets/113592931/6f9497b1-3ed6-4fa1-840a-9c2a8f844206)
![image](https://github.com/DaryaTrifonova/Exam_Trifonova_221-332/assets/113592931/53e0e403-1782-4ac2-9b3c-60a2c2ec61f8)


### Git

git clone https://github.com/DaryaTrifonova/Exam_Trifonova_221-332
git add *
git commit -am "exam" 
git checkout -b exam
git push https://github.com/DaryaTrifonova/Exam_Trifonova_221-332 exam
git checkout main
git merge exam
