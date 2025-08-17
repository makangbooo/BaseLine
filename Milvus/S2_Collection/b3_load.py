from pymilvus import MilvusClient, DataType

client = MilvusClient(
    uri="http://localhost:19530",
    token="root:Milvus",
    db_name="xjuspeech_xjrccb"
)

# 确保 collection 加载
client.load_collection(collection_name="bank_qa_knowledge")