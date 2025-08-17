# 数据库基本操作


from pymilvus import MilvusClient

client = MilvusClient(
    uri="http://localhost:19530",
    token="root:Milvus"
)

# # 1. 数据库创建
client.create_database(
    db_name="xjuspeech_xjrccb"
)

# 2. 查看数据库
client.list_databases()

client.describe_database(
    db_name="xjuspeech_xjrccb"
)

# # 3. 删除数据库
# client.drop_database(
#     db_name="my_database_1"
# )