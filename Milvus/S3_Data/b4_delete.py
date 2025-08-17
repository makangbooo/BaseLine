from pymilvus import MilvusClient

client = MilvusClient(
    uri="http://localhost:19530",
    token="root:Milvus",
    db_name="xjuspeech_xjrccb"
)

res = client.delete(
    collection_name="bank_qa_knowledge",
    filter="qa_id in ['qa-001', '']"
)

print(res)