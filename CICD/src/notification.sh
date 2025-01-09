TELEGRAM_BOT_TOKEN=7531604445:AAG8jvoL8gSMYZRRq0AiNAPSz82FloU-2VY
TELEGRAM_USER_ID=6720514317
TIME=10

URL="https://api.telegram.org/bot$TELEGRAM_BOT_TOKEN/sendMessage"
TEXT="Deploy status:$CI_JOB_NAME%0A$CI_JOB_STATUS%0A%0AProject:+$CI_PROJECT_NAME%0AURL:+$CI_PROJECT_URL/pipelines/$CI_PIPELINE_ID/%0ABranch:+$CI_COMMIT_REF_SLUG"

curl -s --max-time $TIME -d "chat_id=$TELEGRAM_USER_ID&disable_web_page_preview=1&text=$TEXT" $URL > /dev/null